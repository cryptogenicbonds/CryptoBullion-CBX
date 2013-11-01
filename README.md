Cryptogenic Bullion Cryptographic Commodity

Proof of Work/Proof of Stake Hybrid

Scrypt

Linear Difficulty Retarget (2 block retarget)

Transactions require 6 confirmations

Block reward halves after every ~50000 blocks:

Blocks 1-55000 = 10 CGB per; 
Blocks 55001-95000 = 5 CGB per;
Blocks 95001-145000 = 2.5 CGB per;
Blocks 145001-195000 = 1.25 CGB per
etc

First year coin mint of ~1000000

Aiming to be PoS-only blockchain once PoW block subsidy reaches baseline reward of 0.01.
Much research will go into maintaining security of the blockchain if/when CGB goes PoS only.  Many possible schemes and solutions are being analyzed for potential implementation, including but not limited to:

-CoinJoin revision for additional PoS overlay scheme

-Increasing PoS rewards to slightly accelerate coin cap growth, to make it more difficult for 51% stake attack.

-Revision to current PoS trust score algorithm

-Additional randomized trust score scheme to increase scrutiny for randomly selected new PoS blocks

Default P2P Port: 7695

Default RPC Port: 8395

---

Sample config file:

create a file and name it CryptogenicBullion.conf

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



replace username and password with your own username and password.  Do not use the same username/password that is the same as something sensitive, like a website.  

Place the file in your data directory. (you need to run the Qt or daemon once before you do this)

If using Linux, the data directory is located at /home/User/.CryptogenicBullion 
where User is your login username for your system.

If using Windows, the data directory is located at C:\Users\USERNAME\AppData\Roaming\CryptogenicBullion where USERNAME is replaced with your Windows Username.

