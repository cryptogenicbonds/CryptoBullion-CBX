// Copyright (c) 2011-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The CBX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "splashscreen.h"

#include "clientversion.h"
#include "init.h"
#include "ui_interface.h"
#include "util.h"
#ifdef ENABLE_WALLET
#include "wallet.h"
#endif

#include <QApplication>
#include <QPainter>
#include <QFontDatabase>

SplashScreen::SplashScreen(const QPixmap &pixmap, bool isTestNet) :
    QSplashScreen(pixmap)
{
    setAutoFillBackground(true);

    // set reference point, paddings
    int paddingLeft             = 14;
    int paddingTop              = 460;
    int titleVersionVSpace      = 17;
    int titleCopyrightVSpace    = 32;
    float fontFactor            = 1.0;

    // define text to place
    QString titleText       = tr("CBX VAULT");
    QString versionText     = QString(tr("Version %1")).arg(QString::fromStdString(FormatFullVersion()));
    QString copyrightTextBtc   = QChar(0xA9)+QString(" 2009-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The Bitcoin Core developers"));
    QString copyrightTextCbx   = QChar(0xA9)+QString(" 2013-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("Team CBX"));
    QString testnetAddText  = QString(tr("[testnet]")); // define text to place as single text object

    QString splashName = ":/images/splash2";

    if (mapArgs.count("-testnet"))
    {
        //splashName = ":/images/splash2";
    }else{
        //splashName = ":/images/splashTestnet";
    }


    // load the bitmap for writing some text over it
    QPixmap newPixmap = QPixmap(splashName);

    QPainter pixPaint(&newPixmap);
    pixPaint.setPen(QColor(224, 224, 224));

    int id = QFontDatabase::addApplicationFont(":/fonts/font_consolas_bold");
    QString cbxFontFamily = QFontDatabase::applicationFontFamilies(id).at(0);
    //QString font            = "Arial";

    // check font size and drawing with
    pixPaint.setFont(QFont(cbxFontFamily, 18*fontFactor));
    QFontMetrics fm = pixPaint.fontMetrics();
    int titleTextWidth  = fm.width(titleText);
    if(titleTextWidth > 160) {
        // strange font rendering, Arial probably not found
        fontFactor = 0.75;
    }

    pixPaint.setFont(QFont(cbxFontFamily, 18*fontFactor));
    fm = pixPaint.fontMetrics();
    titleTextWidth  = fm.width(titleText);
    pixPaint.drawText((newPixmap.width() - titleTextWidth) / 2,paddingTop-6, titleText);

    pixPaint.setFont(QFont(cbxFontFamily, 12*fontFactor));
    fm = pixPaint.fontMetrics();
    int versionTextWidth  = fm.width(versionText);
    pixPaint.drawText((newPixmap.width() - versionTextWidth) / 2,paddingTop+titleVersionVSpace, versionText);

    // draw copyright stuff
    pixPaint.setFont(QFont(cbxFontFamily, 11*fontFactor));
    fm = pixPaint.fontMetrics();
    int cpTextBtc  = fm.width(copyrightTextBtc);
    int cpTextCbx = fm.width(copyrightTextCbx);
    pixPaint.drawText((newPixmap.width() - cpTextBtc) / 2,paddingTop+titleCopyrightVSpace+3,copyrightTextBtc);
    pixPaint.drawText((newPixmap.width() - cpTextCbx) / 2,paddingTop+titleCopyrightVSpace+21,copyrightTextCbx);

    // draw testnet string if testnet is on
    if(isTestNet) {
        QFont boldFont = QFont(cbxFontFamily, 10*fontFactor);
        boldFont.setWeight(QFont::Bold);
        pixPaint.setFont(boldFont);
        fm = pixPaint.fontMetrics();
        int testnetAddTextWidth  = fm.width(testnetAddText);
        pixPaint.drawText((newPixmap.width()-testnetAddTextWidth)/2,newPixmap.height()-25,testnetAddText);
    }

    pixPaint.end();

    this->setPixmap(newPixmap);

    subscribeToCoreSignals();
}

void SplashScreen::mousePressEvent(QMouseEvent *)
{
    //hide();
}

SplashScreen::~SplashScreen()
{
    unsubscribeFromCoreSignals();
}

void SplashScreen::slotFinish(QWidget *mainWin)
{
    finish(mainWin);
}

static void InitMessage(SplashScreen *splash, const std::string &message)
{
    QMetaObject::invokeMethod(splash, "showMessage",
        Qt::QueuedConnection,
        Q_ARG(QString, QString::fromStdString(message)),
        Q_ARG(int, Qt::AlignBottom|Qt::AlignHCenter),
        Q_ARG(QColor, QColor(255,230,200)));
}

static void ShowProgress(SplashScreen *splash, const std::string &title, int nProgress)
{
    InitMessage(splash, title + strprintf("%d", nProgress) + "%");
}

#ifdef ENABLE_WALLET
static void ConnectWallet(SplashScreen *splash, CWallet* wallet)
{
    wallet->ShowProgress.connect(boost::bind(ShowProgress, splash, _1, _2));
}
#endif

void SplashScreen::subscribeToCoreSignals()
{
    // Connect signals to client
    uiInterface.InitMessage.connect(boost::bind(InitMessage, this, _1));
#ifdef ENABLE_WALLET
    uiInterface.LoadWallet.connect(boost::bind(ConnectWallet, this, _1));
#endif
}

void SplashScreen::unsubscribeFromCoreSignals()
{
    // Disconnect signals from client
    uiInterface.InitMessage.disconnect(boost::bind(InitMessage, this, _1));
#ifdef ENABLE_WALLET
    if(pwalletMain)
        pwalletMain->ShowProgress.disconnect(boost::bind(ShowProgress, this, _1, _2));
#endif
}
