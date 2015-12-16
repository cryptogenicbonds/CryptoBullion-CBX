#!/bin/bash
##
# This script is for building Crypto Bullion Qt wallet for windows using MXE on a Linux environement.
# Please read doc/build-windows.md
##
MXE_PATH=/home/alexandre/sandbox/mxe

echo "######################"
echo "#  Building leveldb  #"
echo "######################"
cd src/leveldb
chmod 755 build_detect_platform
TARGET_OS=NATIVE_WINDOWS make libleveldb.a libmemenv.a CC=$MXE_PATH/usr/bin/i686-w64-mingw32.static-gcc CXX=$MXE_PATH/usr/bin/i686-w64-mingw32.static-g++
cd ..

echo "######################"
echo "# Building miniupnpc #"
echo "######################"
cd miniupnpc
CC=$MXE_PATH/usr/bin/i686-w64-mingw32.static-gcc \
AR=$MXE_PATH/usr/bin/i686-w64-mingw32.static-ar \
CFLAGS="-DSTATICLIB -I$MXE_PATH/usr/i686-w64-mingw32.static/include" \
LDFLAGS="-L$MXE_PATH/usr/i686-w64-mingw32.static/lib" \
make libminiupnpc.a
cd ../..

export PATH=$MXE_PATH/usr/bin:$PATH

MXE_INCLUDE_PATH=$MXE_PATH/usr/i686-w64-mingw32.static/include
MXE_LIB_PATH=$MXE_PATH/usr/i686-w64-mingw32.static/lib

i686-w64-mingw32.static-qmake-qt5 \
	BOOST_LIB_SUFFIX=-mt \
	BOOST_THREAD_LIB_SUFFIX=_win32-mt \
	BOOST_INCLUDE_PATH=$MXE_INCLUDE_PATH/boost \
	BOOST_LIB_PATH=$MXE_LIB_PATH \
	OPENSSL_INCLUDE_PATH=$MXE_INCLUDE_PATH/openssl \
	OPENSSL_LIB_PATH=$MXE_LIB_PATH \
	BDB_INCLUDE_PATH=$MXE_INCLUDE_PATH \
	BDB_LIB_PATH=$MXE_LIB_PATH \
	MINIUPNPC_INCLUDE_PATH=src/miniupnpc \
	MINIUPNPC_LIB_PATH=src/miniupnpc \
 	USE_UPNP=1 \
	USE_LEVELDB=1 \
	USE_BDB=0 \
	RELEASE=1 \
	QMAKE_LRELEASE=$MXE_PATH/usr/i686-w64-mingw32.static/qt5/bin/lrelease cryptobullion-qt.pro
make -f Makefile.Release
