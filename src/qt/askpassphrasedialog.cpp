#include "askpassphrasedialog.h"
#include "ui_askpassphrasedialog.h"

#include "guiconstants.h"
#include "walletmodel.h"
#include "guiutil.h"

#include <QMessageBox>
#include <QPushButton>
#include <QKeyEvent>

extern bool fWalletUnlockMintOnly;

AskPassphraseDialog::AskPassphraseDialog(Mode mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AskPassphraseDialog),
    mode(mode),
    model(0),
    fCapsLock(false)
{
    ui->setupUi(this);
    ui->passEdit1->setMaxLength(MAX_PASSPHRASE_SIZE);
    ui->passEdit2->setMaxLength(MAX_PASSPHRASE_SIZE);
    ui->passEdit3->setMaxLength(MAX_PASSPHRASE_SIZE);

    // Setup Caps Lock detection.
    ui->passEdit1->installEventFilter(this);
    ui->passEdit2->installEventFilter(this);
    ui->passEdit3->installEventFilter(this);

    bool addUnlockButton = false;
    bool addUnlockStakingOnlyButton = false;
    bool addCancelButton = true;
    bool addOkButton = false;

    switch(mode)
    {
        case Encrypt: // Ask passphrase x2
            addOkButton = true;
            ui->passLabel1->hide();
            ui->passEdit1->hide();
            ui->warningLabel->setText(tr("Enter the new passphrase to the vault.<br/>Please use a passphrase of <b>10 or more random characters</b>, or <b>eight or more words</b>."));
            setWindowTitle(tr("Encrypt Vault"));
            break;
        case UnlockFullOnly:
            addUnlockButton = true;
            addUnlockStakingOnlyButton = false;
            ui->warningLabel->setText(tr("This operation needs your vault passphrase to unlock the vault."));
            ui->passLabel2->hide();
            ui->passEdit2->hide();
            ui->passLabel3->hide();
            ui->passEdit3->hide();
            setWindowTitle(tr("Unlock vault"));
            break;
        case Unlock: // Ask passphrase
            addUnlockButton = true;
            addUnlockStakingOnlyButton = true;
            ui->warningLabel->setText(tr("This operation needs your vault passphrase to unlock the vault."));
            ui->passLabel2->hide();
            ui->passEdit2->hide();
            ui->passLabel3->hide();
            ui->passEdit3->hide();
            setWindowTitle(tr("Unlock vault"));
            break;
        case Decrypt:   // Ask passphrase
            ui->warningLabel->setText(tr("This operation needs your vault passphrase to decrypt the vault."));
            ui->passLabel2->hide();
            ui->passEdit2->hide();
            ui->passLabel3->hide();
            ui->passEdit3->hide();
            setWindowTitle(tr("Decrypt Vault"));
            break;
        case ChangePass: // Ask old passphrase + new passphrase x2
            setWindowTitle(tr("Change passphrase"));
            ui->warningLabel->setText(tr("Enter the old and new passphrase to the vault."));
            break;
    }

    if (addUnlockButton){
        buttonUnlock = new QPushButton(tr("&Unlock"));
        buttonUnlock->setDefault(true);
        ui->buttonBox->addButton(buttonUnlock, QDialogButtonBox::ActionRole);
        connect(buttonUnlock, SIGNAL(clicked()), this, SLOT(unlockWallet()));
        GUIUtil::SetupPushButton(buttonUnlock);
    }

    if (addUnlockStakingOnlyButton && !fWalletUnlockMintOnly){
        buttonUnlockStakingOnly = new QPushButton(tr("U&nlock for Staking only"));
        buttonUnlockStakingOnly->setDefault(true);
        ui->buttonBox->addButton(buttonUnlockStakingOnly, QDialogButtonBox::ActionRole);
        connect(buttonUnlockStakingOnly, SIGNAL(clicked()), this, SLOT(unlockWalletForStakingOnly()));
        GUIUtil::SetupPushButton(buttonUnlockStakingOnly);
    }

    if (addOkButton){
        buttonOk = new QPushButton(tr("&Ok"));
        buttonOk->setDefault(false);
        ui->buttonBox->addButton(buttonOk, QDialogButtonBox::ActionRole);
        connect(buttonOk, SIGNAL(clicked()), this, SLOT(encryptWallet()));
        GUIUtil::SetupPushButton(buttonOk);
    }

    if (addCancelButton){
        buttonCancel = new QPushButton(tr("&Cancel"));
        buttonCancel->setDefault(true);
        ui->buttonBox->addButton(buttonCancel, QDialogButtonBox::ActionRole);
        connect(buttonCancel, SIGNAL(clicked()), this, SLOT(closeForm()));
        GUIUtil::SetupPushButton(buttonCancel);
    }

    textChanged();
    connect(ui->passEdit1, SIGNAL(textChanged(QString)), this, SLOT(textChanged()));
    connect(ui->passEdit2, SIGNAL(textChanged(QString)), this, SLOT(textChanged()));
    connect(ui->passEdit3, SIGNAL(textChanged(QString)), this, SLOT(textChanged()));
}

AskPassphraseDialog::~AskPassphraseDialog()
{
    // Attempt to overwrite text so that they do not linger around in memory
    ui->passEdit1->setText(QString(" ").repeated(ui->passEdit1->text().size()));
    ui->passEdit2->setText(QString(" ").repeated(ui->passEdit2->text().size()));
    ui->passEdit3->setText(QString(" ").repeated(ui->passEdit3->text().size()));
    delete ui;
}

void AskPassphraseDialog::setModel(WalletModel *model)
{
    this->model = model;
}

void AskPassphraseDialog::accept(bool stakingOnly)
{
    SecureString oldpass, newpass1, newpass2;
    if(!model)
        return;

    oldpass.reserve(MAX_PASSPHRASE_SIZE);
    newpass1.reserve(MAX_PASSPHRASE_SIZE);
    newpass2.reserve(MAX_PASSPHRASE_SIZE);
    // TODO: get rid of this .c_str() by implementing SecureString::operator=(std::string)
    // Alternately, find a way to make this input mlock()'d to begin with.
    oldpass.assign(ui->passEdit1->text().toStdString().c_str());
    newpass1.assign(ui->passEdit2->text().toStdString().c_str());
    newpass2.assign(ui->passEdit3->text().toStdString().c_str());

    switch(mode)
    {
    case Encrypt: {
        if(newpass1.empty() || newpass2.empty())
        {
            // Cannot encrypt with empty passphrase
            break;
        }
        QMessageBox::StandardButton retval = QMessageBox::question(this, tr("Confirm vault encryption"),
                 tr("Warning: If you encrypt your vault and lose your passphrase, you will <b>LOSE ALL OF YOUR COINS</b>!") + "<br><br>" + tr("Are you sure you wish to encrypt your vault?"),
                 QMessageBox::Yes|QMessageBox::Cancel,
                 QMessageBox::Cancel);
        if(retval == QMessageBox::Yes)
        {
            if(newpass1 == newpass2)
            {
                if(model->setWalletEncrypted(true, newpass1))
                {
                    QMessageBox::warning(this, tr("Vault encrypted"),
                                         "<qt>" +
                                         tr("CryptoBullion will close now to finish the encryption process. "
                                         "Remember that encrypting your vault cannot fully protect "
                                         "your coins from being stolen by malware infecting your computer.") +
                                         "<br><br><b>" +
                                         tr("IMPORTANT: Any previous backups you have made of your vault file "
                                         "should be replaced with the newly generated, encrypted vault file. "
                                         "For security reasons, previous backups of the unencrypted vault file "
                                         "will become useless as soon as you start using the new, encrypted vault.") +
                                         "</b></qt>");
                    QApplication::quit();
                }
                else
                {
                    QMessageBox::critical(this, tr("Vault encryption failed"),
                                         tr("Vault encryption failed due to an internal error. Your vault was not encrypted."));
                }
                QDialog::accept(); // Success
            }
            else
            {
                QMessageBox::critical(this, tr("Vault encryption failed"),
                                     tr("The supplied passphrases do not match."));
            }
        }
        else
        {
            QDialog::reject(); // Cancelled
        }
        } break;
    case UnlockFullOnly:
    case Unlock:
        if(!model->setWalletLocked(false, oldpass))
        {
            QMessageBox::critical(this, tr("Vault unlock failed"),
                                  tr("The passphrase entered for the vault decryption was incorrect."));
        }
        else
        {
            fWalletUnlockMintOnly = stakingOnly;
            QDialog::accept(); // Success
        }
        break;
    case Decrypt:
        if(!model->setWalletEncrypted(false, oldpass))
        {
            QMessageBox::critical(this, tr("Vault decryption failed"),
                                  tr("The passphrase entered for the vault decryption was incorrect."));
        }
        else
        {
            QDialog::accept(); // Success
        }
        break;
    case ChangePass:
        if(newpass1 == newpass2)
        {
            if(model->changePassphrase(oldpass, newpass1))
            {
                QMessageBox::information(this, tr("Vault encrypted"),
                                     tr("Vault passphrase was successfully changed."));
                QDialog::accept(); // Success
            }
            else
            {
                QMessageBox::critical(this, tr("Vault encryption failed"),
                                     tr("The passphrase entered for the vault decryption was incorrect."));
            }
        }
        else
        {
            QMessageBox::critical(this, tr("Vault encryption failed"),
                                 tr("The supplied passphrases do not match."));
        }
        break;
    }
}

void AskPassphraseDialog::textChanged()
{
    // Validate input, set Ok button to enabled when acceptable
    bool acceptable = false;
    switch(mode)
    {
    case Encrypt: // New passphrase x2
        acceptable = !ui->passEdit2->text().isEmpty() && !ui->passEdit3->text().isEmpty();
        break;
    case Unlock: // Old passphrase x1
    case Decrypt:
        acceptable = !ui->passEdit1->text().isEmpty();
        break;
    case ChangePass: // Old passphrase x1, new passphrase x2
        acceptable = !ui->passEdit1->text().isEmpty() && !ui->passEdit2->text().isEmpty() && !ui->passEdit3->text().isEmpty();
        break;
    }
    //ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(acceptable);
}

bool AskPassphraseDialog::event(QEvent *event)
{
    // Detect Caps Lock key press.
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        if (ke->key() == Qt::Key_CapsLock) {
            fCapsLock = !fCapsLock;
        }
        if (fCapsLock) {
            ui->capsLabel->setText(tr("Warning: The Caps Lock key is on!"));
        } else {
            ui->capsLabel->clear();
        }
    }
    return QWidget::event(event);
}

bool AskPassphraseDialog::eventFilter(QObject *object, QEvent *event)
{
    /* Detect Caps Lock.
     * There is no good OS-independent way to check a key state in Qt, but we
     * can detect Caps Lock by checking for the following condition:
     * Shift key is down and the result is a lower case character, or
     * Shift key is not down and the result is an upper case character.
     */
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        QString str = ke->text();
        if (str.length() != 0) {
            const QChar *psz = str.unicode();
            bool fShift = (ke->modifiers() & Qt::ShiftModifier) != 0;
            if ((fShift && psz->isLower()) || (!fShift && psz->isUpper())) {
                fCapsLock = true;
                ui->capsLabel->setText(tr("Warning: The Caps Lock key is on!"));
            } else if (psz->isLetter()) {
                fCapsLock = false;
                ui->capsLabel->clear();
            }
        }
    }
    return QDialog::eventFilter(object, event);
}

void AskPassphraseDialog::closeForm()
{
    close();
}

void AskPassphraseDialog::unlockWallet()
{
    accept(false); // Success
}

void AskPassphraseDialog::unlockWalletForStakingOnly()
{
    accept(true);
}

void AskPassphraseDialog::encryptWallet()
{
    accept(false);
}
