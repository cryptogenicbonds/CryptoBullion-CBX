#ifndef ASKPASSPHRASEDIALOG_H
#define ASKPASSPHRASEDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QPushButton>

namespace Ui {
    class AskPassphraseDialog;
}

class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class AskPassphraseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,    /**< Ask passphrase twice and encrypt */
        Unlock,     /**< Ask passphrase and unlock */
        ChangePass, /**< Ask old passphrase + new passphrase twice */
        Decrypt,     /**< Ask passphrase and decrypt wallet */
        UnlockFullOnly /**< Ask passphrase and unlock for staking/mining only */
    };

    explicit AskPassphraseDialog(Mode mode, QWidget *parent = 0);
    ~AskPassphraseDialog();

    void accept(bool stakingOnly);

    void setModel(WalletModel *model);

private:
    Ui::AskPassphraseDialog *ui;
    Mode mode;
    WalletModel *model;
    bool fCapsLock;
    QPushButton* buttonCancel;
    QPushButton* buttonOk;
    QPushButton* buttonUnlock;
    QPushButton* buttonUnlockStakingOnly;

private slots:
    void textChanged();
    bool event(QEvent *event);
    bool eventFilter(QObject *, QEvent *event);

    void closeForm();
    void unlockWallet();
    void unlockWalletForStakingOnly();
    void encryptWallet();
};

#endif // ASKPASSPHRASEDIALOG_H
