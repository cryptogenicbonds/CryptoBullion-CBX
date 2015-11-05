CryptoBullion-qt: Qt5 GUI for CryptoBullion
===========================================

Build instructions
===================

Debian, Ubuntu, Linux Mint and other varients
---------------------------------------------

First, make sure that the required packages for Qt4 development of your
distribution are installed, for Debian and Ubuntu these are:

	sudo apt-get install build-essential libtool autotools-dev autoconf pkg-config libssl-dev libevent-dev libboost-all-dev

If you are on Ubuntu you have to add a new repository in order to instad BDB 4.8, if you are on an other distribution you should compile it from source or get it through an old packet.
You can try to build it with latest BDB version, but at your own risk !

	sudo add-apt-repository ppa:bitcoin/bitcoin
	sudo apt-get update
	sudo apt-get install libdb4.8-dev libdb4.8++-dev

Now you have to install Qt depedencies:
	sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler qt5-default

Once it's done, you are ready for compiling, use the following command to compile:
	git clone https://github.com/cryptogenicbonds/CryptoBullion-CBX

	cd CryptoBullion-CBX

	cd src/leveldb/ && chmod 755 build_detect_platform && make libleveldb.a libmemenv.a && cd ../.. &&
	cd src/miniupnpc && make && cd ../.. && qmake && make

An executable named `cryptobillion-qt` will be built.


Windows
--------

We highly recommend to build Windows on a Linux envrinoment using a cross-compiler explained in 'build-windows_onunix.md'.

Windows build instructions:

- Download the Qt Windows SDK with MinGW32 and install it.

Download and build dependencies:
	- OpenSSL      1.0.1b
	- Berkeley DB  4.8.30.NC
	- Boost        1.47.0

Build dependencies in sub src/ folder:
	- src/leveldb (libleveldb.a and libmemenv.a)
	- src/miniupnpc

Use the following command in MSYS terminal:
	qmake \
		BOOST_LIB_SUFFIX=-mt \
		BOOST_THREAD_LIB_SUFFIX=_win32-mt \
		BOOST_INCLUDE_PATH=PATH_TO_YOUR_DEPS/boost \
		BOOST_LIB_PATH=$MXE_LIB_PATH \
		OPENSSL_INCLUDE_PATH=PATH_TO_YOUR_DEPS/openssl \
		OPENSSL_LIB_PATH=$MXE_LIB_PATH \
		BDB_INCLUDE_PATH=PATH_TO_YOUR_DEPS \
		BDB_LIB_PATH=$MXE_LIB_PATH \
		MINIUPNPC_INCLUDE_PATH=src/miniupnpc \
		MINIUPNPC_LIB_PATH=src/miniupnpc \
		USE_LEVELDB=1 \
		USE_BDB=0 \
		RELEASE=1 \
		QMAKE_LRELEASE=PATH_TO_QMAKE cryptobullion-qt.pro


Mac OS X
--------

- Download and install XCode, run it atleast the first time before continuing

- Download and install the `Qt Mac OS X SDK`_.

- Download and install `Home Brew`_.

- Execute the following commands in a terminal to get the dependencies:

::
	brew install boost berkeley-db4 miniupnpc openssl

- Open the terminal and go in cd src/leveldb

- Type the following command:
	chmod 755 build_detect_platform
	make -f makefile.osx

- Open the .pro file in Qt Creator and build as normal (cmd-B)


Build configuration options
============================

UPNnP port forwarding
---------------------

To use UPnP for port forwarding behind a NAT router (recommended, as more connections overall allow for a faster and more stable cryptobullion experience), pass the following argument to qmake:

::

    qmake "USE_UPNP=1"

(in **Qt Creator**, you can find the setting for additional qmake arguments under "Projects" -> "Build Settings" -> "Build Steps", then click "Details" next to **qmake**)

This requires miniupnpc for UPnP port mapping.  It can be downloaded from
http://miniupnp.tuxfamily.org/files/.  UPnP support is not compiled in by default.

Set USE_UPNP to a different value to control this:

+------------+--------------------------------------------------------------------------+
| USE_UPNP=- | no UPnP support, miniupnpc not required;                                 |
+------------+--------------------------------------------------------------------------+
| USE_UPNP=0 | (the default) built with UPnP, support turned off by default at runtime; |
+------------+--------------------------------------------------------------------------+
| USE_UPNP=1 | build with UPnP support turned on by default at runtime.                 |
+------------+--------------------------------------------------------------------------+

Notification support for recent (k)ubuntu versions
---------------------------------------------------

To see desktop notifications on (k)ubuntu versions starting from 10.04, enable usage of the
FreeDesktop notification interface through DBUS using the following qmake option:

::

    qmake "USE_DBUS=1"

Generation of QR codes
-----------------------

libqrencode may be used to generate QRCode images for payment requests. 
It can be downloaded from http://fukuchi.org/works/qrencode/index.html.en, or installed via your package manager. Pass the USE_QRCODE 
flag to qmake to control this:

+--------------+--------------------------------------------------------------------------+
| USE_QRCODE=0 | (the default) No QRCode support - libarcode not required                 |
+--------------+--------------------------------------------------------------------------+
| USE_QRCODE=1 | QRCode support enabled                                                   |
+--------------+--------------------------------------------------------------------------+


Berkely DB version warning
==========================

A warning for people using the *static binary* version of Cryptobullion on a Linux/UNIX-ish system (tl;dr: **Berkely DB databases are not forward compatible**).

The static binary version of Cryptobullion is linked against libdb4.8 (see also `this Debian issue`_).

Now the nasty thing is that databases from 5.X are not compatible with 4.X.

If the globally installed development package of Berkely DB installed on your system is 5.X, any source you
build yourself will be linked against that. The first time you run with a 5.X version the database will be upgraded,
and 4.X cannot open the new format. This means that you cannot go back to the old statically linked version without
significant hassle!

.. _`this Debian issue`: http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=621425

Ubuntu 11.10 warning
====================

Ubuntu 11.10 has a package called 'qt-at-spi' installed by default.  At the time of writing, having that package
installed causes cryptobullion-qt to crash intermittently.  The issue has been reported as `launchpad bug 857790`_, but
isn't yet fixed.

Until the bug is fixed, you can remove the qt-at-spi package to work around the problem, though this will presumably
disable screen reader functionality for Qt apps:

::

    sudo apt-get remove qt-at-spi

.. _`launchpad bug 857790`: https://bugs.launchpad.net/ubuntu/+source/qt-at-spi/+bug/857790
