#!/bin/bash
QT_INC_DIR=/d/_coinDev/Qt/5.3.2/include
QT_LIB_DIR=/d/_coinDev/Qt/5.3.2/lib
QT_BIN_DIR=/d/_coinDev/Qt/5.3.2/bin
QT_PLUGIN_DIR=/d/_coinDev/Qt/5.3.2/plugins

export PATH=$QT_BIN_DIR:$PATH

echo =============================================
echo == BUILDING WIN32 X86 LEVELDB
echo =============================================
 
cd src/leveldb
TARGET_OS=NATIVE_WINDOWS make libleveldb.a libmemenv.a 
 
echo =============================================
echo == BUILDING WIN32 X86 DAEMON
echo =============================================
 
cd ..
make -f makefile.mingw

#strip src/bitcoin-cli.exe
strip cryptogenicbulliond.exe
#strip src/qt/bitcoin-qt.exe
 
echo =============================================
echo == BUILDING WIN32 X86 QT WALLET
echo =============================================

cd ..
qmake USE_LEVELDB=1 && make