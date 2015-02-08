Crypto Bullion Cryptographic Commodity

Proof of Work/Proof of Stake Hybrid

Scrypt

Linear Difficulty Retarget (2 block retarget)

Transactions require 6 confirmations

Block reward halves after every ~50000 blocks until baseline reward of 0.01 CBX reached on July 13, 2014

Blocks 1-55000 = 10 CBX per;
Blocks 55001-95000 = 5 CBX per;
Blocks 95001-145000 = 2.5 CBX per;
Blocks 145001-195000 = 1.25 CBX per
etc

First year coin mint of < 1000000

<<<<<<< HEAD
Crypto Bullion (CBX) is a digital asset with all of the qualities of money. It is a descendant of Bitcoin, but employs an 
advanced security model which is more efficient and more secure than Bitcoin. The problems of today’s debt based fiat 
currencies find solutions in cutting-edge decentralized cryptographic currencies like Crypto Bullion. Designed to function as a
store of wealth, Crypto Bullion’s fundamentals emulate the properties and supply of gold.
=======
Aiming to be PoS-only blockchain once PoW block subsidy reaches baseline reward of 0.01.
Much research will go into maintaining security of the blockchain if/when CBX goes PoS only.  Many possible schemes and solutions are being analyzed for potential implementation, including but not limited to:
>>>>>>> raizor/master

While Crypto Bullion shares many traits with Bitcoin such as fast global payments, decentralization, pseudo-anonymity, and 
non-reversible transactions, there are many improvements which allow Crypto Bullion to more reliably store wealth. A critical 
requirement for storing wealth is a low inflation rate. Crypto Bullion is a very rare exception in that it has completed its 
volatile inflationary stage and settled into its maximum yearly inflation rate of 2%. It also allows prudent savers of Crypto 
Bullion to earn up to 1.5% annual interest on funds left unspent in their wallets for at least 30 days.

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

<<<<<<< HEAD
If using Linux, the data directory is located at /home/User/.CryptoBullion 
where User is your login username for your system.

If using Windows, the data directory is located at C:\Users\USERNAME\AppData\Roaming\CryptoBullion where USERNAME is replaced 
with your Windows Username.
=======
If using Linux, the data directory is located at /home/User/.CryptoBullion
where User is your login username for your system.

If using Windows, the data directory is located at C:\Users\USERNAME\AppData\Roaming\CryptoBullion where USERNAME is replaced with your Windows Username.
>>>>>>> raizor/master

