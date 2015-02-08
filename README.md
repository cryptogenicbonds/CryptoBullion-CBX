Crypto Bullion Cryptographic Commodity

Proof of Work/Proof of Stake Hybrid

Scrypt

Linear Difficulty Retarget (2 block retarget)

Transactions require 6 confirmations

Block reward halves after every ~50000 blocks until baseline of 0.01 CBX (reached on July 13, 2014)

Blocks 1-55000 = 10 CBX per;
Blocks 55001-95000 = 5 CBX per;
Blocks 95001-145000 = 2.5 CBX per;
Blocks 145001-195000 = 1.25 CBX per
etc

Coin mint of < 1000000

Default P2P Port: 7695

Default RPC Port: 8395

---

Sample config file:

create a file and name it CryptoBullion.conf

And copy/paste the following contents:

rpcuser=username

rpcpassword=password

rpcallowip=127.0.0.1

rpcconnect=127.0.0.1

DNSSEED=1

daemon=1

server=1

gen=0

testnet=0

listen=0

maxconnections=100

addnode=seed.cryptobullion.io

addnode=blockexplorer.cryptobullion.io

addnode=173.230.133.205

addnode=72.78.100.7

addnode=70.98.114.237

addnode=192.81.209.17

addnode=192.241.222.16

addnode=88.198.184.231

addnode=109.169.220.58

addnode=80.255.6.123

addnode=66.58.170.165

addnode=37.187.9.53

addnode=216.158.85.123

addnode=119.9.15.177



Replace username and password with your own username and password.  Do not use the same username/password that is the same as 
something sensitive, like a website.  

Place the file in your data directory. (you need to run the Qt or daemon once before you do this)

If using Linux, the data directory is located at /home/User/.CryptoBullion
where User is your login username for your system.

If using Windows, the data directory is located at C:\Users\USERNAME\AppData\Roaming\CryptoBullion where USERNAME is replaced with your Windows Username.
