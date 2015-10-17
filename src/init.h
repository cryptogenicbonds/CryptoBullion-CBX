// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef CRYPTOBULLION_INIT_H
#define CRYPTOBULLION_INIT_H

#include "wallet.h"

/* The help message mode determines what help message to show */
enum HelpMessageMode
{
    HMM_CRYPTOBULLIOND,
    HMM_CRYPTOBULLION_QT
};

extern CWallet* pwalletMain;

void StartShutdown();
void Shutdown(void* parg);
bool AppInit2(boost::thread_group& threadGroup);
std::string HelpMessage(HelpMessageMode hmm);

#endif
