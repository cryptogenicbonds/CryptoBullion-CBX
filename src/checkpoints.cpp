// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "txdb.h"
#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, std::pair<uint256, unsigned int> > MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        ( 0,     std::make_pair(hashGenesisBlockOfficial, 1360105017) )
        ( 95002,  std::make_pair(uint256("0x000000002005b8fcc4e971b14ef655535fde9285c913c52f3c7064d889cd6226"), 1372351925) )
        ( 128580, std::make_pair(uint256("0x0000000005bbf12779485036c7aa23d0c017182dabdbb58e86b66384e929fd2c"), 1380061639) )
        ( 150002, std::make_pair(uint256("0x00000000023d5687abb2208b1df44974a50c519f3a6f11c29b891dbe8cc84ebf"), 1381364118) )
        ( 183993, std::make_pair(uint256("0x000000001da3185b0b68ac3499084fd96e95487f62700f5ffd040bd8b4d58398"), 1383425111) )
        ( 190000, std::make_pair(uint256("0x000000000e226034b27a0fef11039fee830ff8027e0f17b926bb83c01bf3b688"), 1383788516) )
        ( 230000, std::make_pair(uint256("0x00000000469a52e1ecddf74ebd18d034ae42122729687ecbf5e233562fdfd39f"), 1386214418) )
        ( 260000, std::make_pair(uint256("0x0000000070030143c51d204917e5aaac6cf37d4b1803d72c08dafd12edc8ea72"), 1388032785) )
        ( 290000, std::make_pair(uint256("0x00000000af91b16f01a659894a24c879ee62133e34f9efabdc9fa08d281a4b11"), 1389847220) )
        ( 320000, std::make_pair(uint256("0x00000001d4ee504e892fd7597c0342079f8ec14a6bd7f0e38d77be78baa4442f"), 1391663029) )
        ( 350000, std::make_pair(uint256("0x000000026ff936a9f4d77ef8b3f43fb7c2202219c4246ac56c413ec37672f0e4"), 1393476493) )
        ( 380000, std::make_pair(uint256("0x0000000125a6f752588db314e8577e5c0126dc416929073ea50a21479d6deb69"), 1395288765) )
        ( 402000, std::make_pair(uint256("0x00000002c544f0f8c83671bb5dd48b6ced70dc3db5f6588643b910c079689ce0"), 1396618025) )
        ( 430000, std::make_pair(uint256("0x00000006ba35bae2e2af99bf37243488afc8d6efd0d7cf77bd96bf94e07b80e1"), 1398316272) )
        ( 460000, std::make_pair(uint256("0x109a874f7d794025858987cc72bac7f2baeff792a01d31afa9984a125da22fbd"), 1400147033) )
        ( 510000, std::make_pair(uint256("0x00000000114e79134fa556d603c1e5230e122bd0a78f6192888362bd5091bd18"), 1403183947) )
        ( 530000, std::make_pair(uint256("0x00000000a0540d980018d3b1992bbd10906bb9872b0fc953542d6fb4cddc7ff8"), 1404385612) )
        ( 560000, std::make_pair(uint256("0x00000004d61b326efed561b7fbf5b4d61b64fe6945f9f126f8b3153190fe1cdd"), 1406221401) )
        ( 590000, std::make_pair(uint256("0x000000004d64aa9e1c77b55c4db47dcdec8f878269f87737ef7decbb69f9f9e8"), 1408027941) )
        ( 610000, std::make_pair(uint256("0x0000000677b1841abad721ec3167b3c7b0463d53a22d78fbcd85c2eb53af56f2"), 1409242463) )
        ( 640000, std::make_pair(uint256("0x00000000d5da601476027f06518128b32a7d5bcddb9098e34aab7570830c6e84"), 1411048458) )
        ( 690000, std::make_pair(uint256("0xd60ffff3c297dc6b0b6020d733cd912ca5506bed2fe7472d3fda459c52a8a43e"), 1414054379) )
        ( 730000, std::make_pair(uint256("0xfde685b6116963359b221fc5235a6736f00d24c093bc4de5f3e0b0394a51c56a"), 1416498679) )
        ( 780000, std::make_pair(uint256("0x000000000280ad0eacaf25174b49cb9f965d192f25d3e47d2e4a6b053fb6f990"), 1419520424) )
        ( 820000, std::make_pair(uint256("0x0000000090a8d91fd306e83390eca58d65c576203a8a1a053c1b099190147cb9"), 1421939687) )            
        ( 850000, std::make_pair(uint256("0x000000008b4658c03a8f13866ddb046227de8a96b3ee21078a828aa54d37e90d"), 1423767293) )
        ( 870000, std::make_pair(uint256("0x000000030107f0e16cb4dbbb14a548d91a56527534d34cadd9ac475adec719da"), 1424981318) )
        ( 890000, std::make_pair(uint256("0x000000012fa9230d9f3f15d203a787db0b9e92889eca232cc59f763368896935"), 1426194182) )
        ( 910000, std::make_pair(uint256("0x000000006251188a93289e904eb674dbfa15722e163d4ec90a9673b84d6ac767"), 1427415383) )
        ( 920000, std::make_pair(uint256("0x000000016365ab52244f095a0a2e47c95c9b448b97cd5542d2cdf4dce380ea63"), 1428027541) )
        ( 930000, std::make_pair(uint256("0x000000010d42105d7fb5fd8b37c1e089587831b215c2ffa0d910331bb622cf7b"), 1428621116) )
        ( 940000, std::make_pair(uint256("0x00000000effedf62c11f4915af520ff9760fe95079274272644db33fafcc144a"), 1429238187) )
        ( 950000, std::make_pair(uint256("0x000000013d1baea87356546d2a145ab914ce3e150a1a815255c94467926b8afa"), 1429997830) )
        ( 960000, std::make_pair(uint256("0x00000005ae8130555185ada554519439bdc71c390f95bd5e55530c240db3db54"), 1430623240) )
        ( 970000, std::make_pair(uint256("0x0000000056cf659b939456d76a883cf2147c49047c950ef7415c5700e0b5b4db"), 1431227343) )
        ( 980000, std::make_pair(uint256("0x00000002933a54248502f0091078d3c33269e6d0293358e9259f8581aa91359c"), 1431895647) )
        ( 990000, std::make_pair(uint256("0x00000000758136b0e554e639ad6fa11b7eb5f514120240960f36a33710cfe253"), 1432502809) )
        ( 1000000, std::make_pair(uint256("0x00000002c6f432ca95d5ea89b84d2bfd701e3253d8edef06d18fed7ec09de30c"), 1433111376) )
        ( 1100000, std::make_pair(uint256("0x000000015ac05d2bd89aba131cc9d57cdd7edda818320516cf2f346a2515b9be"), 1439171273) )
        ( 1200000, std::make_pair(uint256("0x000000007a41df6df9174de6483a00c6a70bfa1c2a383d723def0776b6e3601f"), 1445225088) )
        ( 1302573, std::make_pair(uint256("0x51050155f2159ecbaf3470725c50db7f34bb2a8590f1bb638474c6519e99e6ac"), 1451570400) ) // First PoSP block
        ( 1309160, std::make_pair(uint256("0x97ba36ecbcd66d6894b2766aec2b74c128afb5070ed4ba2243ae36f996fbfca8"), 1452014385) )
        ( 1310272, std::make_pair(uint256("0x720b51ded661eb7fd9ba0b4e47743dd80aeeba9adbc22dd4dad8ca58198390df"), 1452091921) )
        ( 1310670, std::make_pair(uint256("0x0abd54495d29078ea17efaae129c97224f6db03292bde04a905ca72bf1bd4547"), 1452268352) )
    ;

    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 0, std::make_pair(hashGenesisBlockTestNet, 1372351925) )
        ;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second.first;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        return checkpoints.rbegin()->first;
    }

    int GetLastCheckpointTime()
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        return checkpoints.rbegin()->second.second;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second.first;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // ppcoin: synchronized checkpoint (centrally broadcasted)
    uint256 hashSyncCheckpoint = 0;
    uint256 hashPendingCheckpoint = 0;
    CSyncCheckpoint checkpointMessage;
    CSyncCheckpoint checkpointMessagePending;
    uint256 hashInvalidCheckpoint = 0;
    CCriticalSection cs_hashSyncCheckpoint;

    // ppcoin: get last synchronized checkpoint
    CBlockIndex* GetLastSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            error("GetSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        else
            return mapBlockIndex[hashSyncCheckpoint];
        return NULL;
    }

    // ppcoin: only descendant of current sync-checkpoint is allowed
    bool ValidateSyncCheckpoint(uint256 hashCheckpoint)
    {
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        if (!mapBlockIndex.count(hashCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for received sync-checkpoint %s", hashCheckpoint.ToString().c_str());

        CBlockIndex* pindexSyncCheckpoint = mapBlockIndex[hashSyncCheckpoint];
        CBlockIndex* pindexCheckpointRecv = mapBlockIndex[hashCheckpoint];

        if (pindexCheckpointRecv->nHeight <= pindexSyncCheckpoint->nHeight)
        {
            // Received an older checkpoint, trace back from current checkpoint
            // to the same height of the received checkpoint to verify
            // that current checkpoint should be a descendant block
            CBlockIndex* pindex = pindexSyncCheckpoint;
            while (pindex->nHeight > pindexCheckpointRecv->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("ValidateSyncCheckpoint: pprev1 null - block index structure failure");
            if (pindex->GetBlockHash() != hashCheckpoint)
            {
                hashInvalidCheckpoint = hashCheckpoint;
                return error("ValidateSyncCheckpoint: new sync-checkpoint %s is conflicting with current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
            }
            return false; // ignore older checkpoint
        }

        // Received checkpoint should be a descendant block of the current
        // checkpoint. Trace back to the same height of current checkpoint
        // to verify.
        CBlockIndex* pindex = pindexCheckpointRecv;
        while (pindex->nHeight > pindexSyncCheckpoint->nHeight)
            if (!(pindex = pindex->pprev))
                return error("ValidateSyncCheckpoint: pprev2 null - block index structure failure");
        if (pindex->GetBlockHash() != hashSyncCheckpoint)
        {
            hashInvalidCheckpoint = hashCheckpoint;
            return error("ValidateSyncCheckpoint: new sync-checkpoint %s is not a descendant of current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
        }
        return true;
    }

    bool WriteSyncCheckpoint(const uint256& hashCheckpoint)
    {
        CTxDB txdb;
        txdb.TxnBegin();
        if (!txdb.WriteSyncCheckpoint(hashCheckpoint))
        {
            txdb.TxnAbort();
            return error("WriteSyncCheckpoint(): failed to write to db sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
        if (!txdb.TxnCommit())
            return error("WriteSyncCheckpoint(): failed to commit to db sync checkpoint %s", hashCheckpoint.ToString().c_str());
#ifndef USE_LEVELDB
        txdb.Close();
#endif

        Checkpoints::hashSyncCheckpoint = hashCheckpoint;
        return true;
    }

    bool AcceptPendingSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint != 0 && mapBlockIndex.count(hashPendingCheckpoint))
        {
            if (!ValidateSyncCheckpoint(hashPendingCheckpoint))
            {
                hashPendingCheckpoint = 0;
                checkpointMessagePending.SetNull();
                return false;
            }

            CTxDB txdb;
            CBlockIndex* pindexCheckpoint = mapBlockIndex[hashPendingCheckpoint];
            if (!pindexCheckpoint->IsInMainChain())
            {
                CBlock block;
                if (!block.ReadFromDisk(pindexCheckpoint))
                    return error("AcceptPendingSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                if (!block.SetBestChain(txdb, pindexCheckpoint))
                {
                    hashInvalidCheckpoint = hashPendingCheckpoint;
                    return error("AcceptPendingSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                }
            }
#ifndef USE_LEVELDB
            txdb.Close();
#endif

            if (!WriteSyncCheckpoint(hashPendingCheckpoint))
                return error("AcceptPendingSyncCheckpoint(): failed to write sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
            hashPendingCheckpoint = 0;
            checkpointMessage = checkpointMessagePending;
            checkpointMessagePending.SetNull();
            printf("AcceptPendingSyncCheckpoint : sync-checkpoint at %s\n", hashSyncCheckpoint.ToString().c_str());
            // relay the checkpoint
            if (!checkpointMessage.IsNull())
            {
                BOOST_FOREACH(CNode* pnode, vNodes)
                    checkpointMessage.RelayTo(pnode);
            }
            return true;
        }
        return false;
    }

    // Automatically select a suitable sync-checkpoint
    uint256 AutoSelectSyncCheckpoint()
    {
        // Proof-of-work blocks are immediately checkpointed
        // to defend against 51% attack which rejects other miners block

        // Select the last proof-of-work block
        const CBlockIndex *pindex = GetLastBlockIndex(pindexBest, false);
        // Search forward for a block within max span and maturity window
        while (pindex->pnext && (pindex->GetBlockTime() + CHECKPOINT_MAX_SPAN <= pindexBest->GetBlockTime() || pindex->nHeight + std::min(6, nCoinbaseMaturity - 20) <= pindexBest->nHeight))
            pindex = pindex->pnext;
        return pindex->GetBlockHash();
    }

    // Check against synchronized checkpoint
    bool CheckSync(const uint256& hashBlock, const CBlockIndex* pindexPrev)
    {
        if (fTestNet) return true; // Testnet has no checkpoints
        int nHeight = pindexPrev->nHeight + 1;

        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];

        if (nHeight > pindexSync->nHeight)
        {
            // trace back to same height as sync-checkpoint
            const CBlockIndex* pindex = pindexPrev;
            while (pindex->nHeight > pindexSync->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("CheckSync: pprev null - block index structure failure");
            if (pindex->nHeight < pindexSync->nHeight || pindex->GetBlockHash() != hashSyncCheckpoint)
                return false; // only descendant of sync-checkpoint can pass check
        }
        if (nHeight == pindexSync->nHeight && hashBlock != hashSyncCheckpoint)
            return false; // same height with sync-checkpoint
        if (nHeight < pindexSync->nHeight && !mapBlockIndex.count(hashBlock))
            return false; // lower height than sync-checkpoint
        return true;
    }

    bool WantedByPendingSyncCheckpoint(uint256 hashBlock)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint == 0)
            return false;
        if (hashBlock == hashPendingCheckpoint)
            return true;
        if (mapOrphanBlocks.count(hashPendingCheckpoint)
            && hashBlock == WantedByOrphan(mapOrphanBlocks[hashPendingCheckpoint]))
            return true;
        return false;
    }

    // ppcoin: reset synchronized checkpoint to last hardened checkpoint
    bool ResetSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        const uint256& hash = mapCheckpoints.rbegin()->second.first;
        if (mapBlockIndex.count(hash) && !mapBlockIndex[hash]->IsInMainChain())
        {
            // checkpoint block accepted but not yet in main chain
            printf("ResetSyncCheckpoint: SetBestChain to hardened checkpoint %s\n", hash.ToString().c_str());
            CTxDB txdb;
            CBlock block;
            if (!block.ReadFromDisk(mapBlockIndex[hash]))
                return error("ResetSyncCheckpoint: ReadFromDisk failed for hardened checkpoint %s", hash.ToString().c_str());
            if (!block.SetBestChain(txdb, mapBlockIndex[hash]))
            {
                return error("ResetSyncCheckpoint: SetBestChain failed for hardened checkpoint %s", hash.ToString().c_str());
            }
#ifndef USE_LEVELDB
            txdb.Close();
#endif
        }
        else if(!mapBlockIndex.count(hash))
        {
            // checkpoint block not yet accepted
            hashPendingCheckpoint = hash;
            checkpointMessagePending.SetNull();
            printf("ResetSyncCheckpoint: pending for sync-checkpoint %s\n", hashPendingCheckpoint.ToString().c_str());
        }

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second.first;
            if (mapBlockIndex.count(hash) && mapBlockIndex[hash]->IsInMainChain())
            {
                if (!WriteSyncCheckpoint(hash))
                    return error("ResetSyncCheckpoint: failed to write sync checkpoint %s", hash.ToString().c_str());
                printf("ResetSyncCheckpoint: sync-checkpoint reset to %s\n", hashSyncCheckpoint.ToString().c_str());
                return true;
            }
        }

        return false;
    }

    void AskForPendingSyncCheckpoint(CNode* pfrom)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (pfrom && hashPendingCheckpoint != 0 && (!mapBlockIndex.count(hashPendingCheckpoint)) && (!mapOrphanBlocks.count(hashPendingCheckpoint)))
            pfrom->AskFor(CInv(MSG_BLOCK, hashPendingCheckpoint));
    }

    bool SetCheckpointPrivKey(std::string strPrivKey)
    {
        // Test signing a sync-checkpoint with genesis block
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = hashGenesisBlock;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        std::vector<unsigned char> vchPrivKey = ParseHex(strPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return false;

        // Test signing successful, proceed
        CSyncCheckpoint::strMasterPrivKey = strPrivKey;
        return true;
    }

    bool SendSyncCheckpoint(uint256 hashCheckpoint)
    {
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = hashCheckpoint;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        if (CSyncCheckpoint::strMasterPrivKey.empty())
            return error("SendSyncCheckpoint: Checkpoint master key unavailable.");
        std::vector<unsigned char> vchPrivKey = ParseHex(CSyncCheckpoint::strMasterPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return error("SendSyncCheckpoint: Unable to sign checkpoint, check private key?");

        if(!checkpoint.ProcessSyncCheckpoint(NULL))
        {
            printf("WARNING: SendSyncCheckpoint: Failed to process checkpoint.\n");
            return false;
        }

        // Relay checkpoint
        {
            LOCK(cs_vNodes);
            BOOST_FOREACH(CNode* pnode, vNodes)
                checkpoint.RelayTo(pnode);
        }
        return true;
    }

    // Is the sync-checkpoint outside maturity window?
    bool IsMatureSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];
        return (nBestHeight >= pindexSync->nHeight + nCoinbaseMaturity ||
                pindexSync->GetBlockTime() + GetStakeMinAge(pindexSync->GetBlockTime()) < GetAdjustedTime());
    }

    // Is the sync-checkpoint too old?
    bool IsSyncCheckpointTooOld(unsigned int nSeconds)
    {
        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];
        return (pindexSync->GetBlockTime() + nSeconds < GetAdjustedTime());
    }
}

// ppcoin: sync-checkpoint master key
const std::string CSyncCheckpoint::strMasterPubKey = "04c20f50f15c626cc037aa55f03daa42d4d4fcc998c5e7da6ef983dfca447966c903a16499ef8bfc9163a951c11a72c357634871d390af606e1bddc3df31feb629";

std::string CSyncCheckpoint::strMasterPrivKey = "";

// ppcoin: verify signature of sync-checkpoint message
bool CSyncCheckpoint::CheckSignature()
{
    CKey key;
    if (!key.SetPubKey(ParseHex(CSyncCheckpoint::strMasterPubKey)))
        return error("CSyncCheckpoint::CheckSignature() : SetPubKey failed");
    if (!key.Verify(Hash(vchMsg.begin(), vchMsg.end()), vchSig))
        return error("CSyncCheckpoint::CheckSignature() : verify signature failed");

    // Now unserialize the data
    CDataStream sMsg(vchMsg, SER_NETWORK, PROTOCOL_VERSION);
    sMsg >> *(CUnsignedSyncCheckpoint*)this;
    return true;
}

// ppcoin: process synchronized checkpoint
bool CSyncCheckpoint::ProcessSyncCheckpoint(CNode* pfrom)
{
    if (!CheckSignature())
        return false;

    LOCK(Checkpoints::cs_hashSyncCheckpoint);
    if (!mapBlockIndex.count(hashCheckpoint))
    {
        // We haven't received the checkpoint chain, keep the checkpoint as pending
        Checkpoints::hashPendingCheckpoint = hashCheckpoint;
        Checkpoints::checkpointMessagePending = *this;
        printf("ProcessSyncCheckpoint: pending for sync-checkpoint %s\n", hashCheckpoint.ToString().c_str());
        // Ask this guy to fill in what we're missing
        if (pfrom)
        {
            pfrom->PushGetBlocks(pindexBest, hashCheckpoint);
            // ask directly as well in case rejected earlier by duplicate
            // proof-of-stake because getblocks may not get it this time
            pfrom->AskFor(CInv(MSG_BLOCK, mapOrphanBlocks.count(hashCheckpoint)? WantedByOrphan(mapOrphanBlocks[hashCheckpoint]) : hashCheckpoint));
        }
        return false;
    }

    if (!Checkpoints::ValidateSyncCheckpoint(hashCheckpoint))
        return false;

    CTxDB txdb;
    CBlockIndex* pindexCheckpoint = mapBlockIndex[hashCheckpoint];
    if (!pindexCheckpoint->IsInMainChain())
    {
        // checkpoint chain received but not yet main chain
        CBlock block;
        if (!block.ReadFromDisk(pindexCheckpoint))
            return error("ProcessSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        if (!block.SetBestChain(txdb, pindexCheckpoint))
        {
            Checkpoints::hashInvalidCheckpoint = hashCheckpoint;
            return error("ProcessSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
    }
#ifndef USE_LEVELDB
    txdb.Close();
#endif

    if (!Checkpoints::WriteSyncCheckpoint(hashCheckpoint))
        return error("ProcessSyncCheckpoint(): failed to write sync checkpoint %s", hashCheckpoint.ToString().c_str());
    Checkpoints::checkpointMessage = *this;
    Checkpoints::hashPendingCheckpoint = 0;
    Checkpoints::checkpointMessagePending.SetNull();
    printf("ProcessSyncCheckpoint: sync-checkpoint at %s\n", hashCheckpoint.ToString().c_str());
    return true;
}
