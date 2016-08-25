BUILD ON UNIX
=============
Copyright (c) 2013-2016 CryptoBullion Developers
Distributed under the MIT/X11 software license, see the accompanying file
license.txt or http://www.opensource.org/licenses/mit-license.php.  This
product includes software developed by the OpenSSL Project for use in the
OpenSSL Toolkit (http://www.openssl.org/).  This product includes cryptographic
software written by Eric Young (eay@cryptsoft.com) and UPnP software written by
Thomas Bernard.

If you want to build Qt, please see readme-qt.md.
Every user that wants to use Vault on Linux should build it from source.

Here is how to do it on Debian/Ubuntu-like Linux distribution:

0. Install Git and clone repo
```
sudo apt-get install git
git clone https://github.com/cryptogenicbonds/CryptoBullion-CBX
cd CryptoBullion-CBX
```
1. First add bitcoin repository in order to be able to get libdb4.8:
```
sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt-get update
```
2. Install all dependances:
```
sudo apt-get install build-essential libtool autotools-dev autoconf pkg-config libssl-dev libevent-dev libboost-all-dev libdb4.8-dev libdb4.8++-dev
```
3. Build leveldb:
```
cd src/leveldb/ && make libleveldb.a libmemenv.a && cd ..
```
4. Build miniupnpc (option, if you don't build it just use make "USE_UPNP=-" in the next step)
```
cd src/miniupnpc && make && cd ..
```
5. Build CrytpoBullion daemon:
```
make -f makefile.unix
```
