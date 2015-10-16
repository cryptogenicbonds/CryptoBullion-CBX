Copyright (c) 2013-2015 Crypto Bullion Developers
Distributed under the MIT/X11 software license, see the accompanying
file license.txt or http://www.opensource.org/licenses/mit-license.php.

WINDOWS BUILD NOTES ON LINUX (using cross compiler)
===================================================

Introduction
------------
The most easy way to build the Windows Qt Wallet of Crypto Bullion is to using MXE on Linux distribution.

Set up softwares
----------------
We will install cross-compiler environement.

First, download all dependancies of MXE:
	sudo apt-get install p7zip-full autoconf automake autopoint bash bison bzip2 cmake flex gettext git g++ gperf intltool libffi-dev libtool libltdl-dev libssl-dev libxml-parser-perl make openssl patch perl pkg-config python ruby scons sed unzip wget xz-utils g++-multilib libc6-dev-i386

Secondly you have to download MXE and put it where you want your cross-compiler environment.
I put it in a folder that I named "sandbox" in my personal directory, if you want to install it for all user you can install it in /opt/ or in /mnt/ or whatever you like.
	mkdir /home/alexandre/sandbox
	git clone https://github.com/mxe/mxe.git

Prepare the building dependencies
---------------------------------
Now we have to build/install all dependencies (librairies) needed by Crypto Bullion.
Thanks to MXE this step is pretty easy to do because MXE build it automatically for you.

Here is how to proceed:
	cd /home/alexandre/sandbox/mxe

Compiling Qt5:
	make MXE_TARGETS="i686-w64-mingw32.static" qttools

Compiling Boost:
	make MXE_TARGETS="i686-w64-mingw32.static" boost

Compiling Berkley DB:
	make MXE_TARGETS="i686-w64-mingw32.static" db

Compile Crypto Bullion Wallet
-----------------------------
Now you are ready to compile the Windows Qt Wallet of Crypto Bullion !
In order to do it, edit the mxeBuild.sh file in root folder and replace:
	MXE_PATH=/home/alex4j/sandbox/mxe
By your own MXE path.
Then simply give permission to the file (chmod 755 mxeBuild.sh) and excute it:
	./mxeBuild.sh

The compilation can take a while, so it's a good time to take a coffee :)
Once the compilation is finished, the exe file should be in release/cryptobullion-qt.exe, you just have to get this file and launch it on your Windows computer.