Cryptogenic Bullion Cryptographic Commodity

Proof of Work/Proof of Stake Hybrid

Scrypt

Linear Difficulty Retarget (2 block retarget)

Transactions require 5 confirmations

Block reward halves after every ~50000 blocks:

Blocks 1-55000 = 10 CGB per; 
Blocks 55001-95000 = 5 CGB per;
Blocks 95001-145000 = 2.5 CGB per;
Blocks 145001-195000 = 1.25 CGB per
etc

First year coin mint of ~1000000

Released in late June 2013, CGB was designed primarily for the purpose of storing wealth. Cryptogenic Bullion is a second generation crypto-currency designed to emulate the properties and supply of gold. It’s the first crypto-currency to display all of the properties of money, while providing the bearer with interest for holding it.
Unlike most other crypto-currencies, Cryptogenic Bullion has already completed its volatile monetary base expansion stage and is settling in to its maximum target of 2% expansion per year.

To qualify for interest, an investor must keep their funds unspent in their wallets for a minimum of 30 days (for 1.2% interest), and up to a maximum of 90 days (1.5% interest).

With the baseline mining reward expected to be reached within 1 year of release, and the annual inflation target of 2% fast approaching, there is no better time for the serious investor to get involved and claim a stake in this unique digital asset.

New feature developments currently being assembled for client 2.0 release include but are not limited to:

- Balance POS/POW block creation - POS time changes, POW time changes

- Add stake visualization

- Add unlock button to easily unlock wallet for staking

- Client styling

- Fully implement multisig, and make sure getrawtransaction PRC call is available - to support distributed exchange

- Add coin control

- Improve client start up time

- Merged mining

- Stealth addresses

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



Replace username and password with your own username and password.  Do not use the same username/password that is the same as something sensitive, like a website.  

Place the file in your data directory. (you need to run the Qt or daemon once before you do this)

If using Linux, the data directory is located at /home/User/.CryptogenicBullion 
where User is your login username for your system.

If using Windows, the data directory is located at C:\Users\USERNAME\AppData\Roaming\CryptogenicBullion where USERNAME is replaced with your Windows Username.

