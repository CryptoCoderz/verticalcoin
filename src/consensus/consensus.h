// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Copyright (c) 2016-2018 The Verticalcoin developers
// Copyright (c) 2018	   The CryptoCoderz Team

// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CONSENSUS_CONSENSUS_H
#define BITCOIN_CONSENSUS_CONSENSUS_H

#include <stdint.h>

// HF constants

static const int HF_LBK3_HEIGHT 					= 1; // TODO: Set official fork after testing (OFF: 999999)
static const int HF_VNODE_HEIGHT 					= 999999; // TODO: Set official fork after testing (OFF: 999999) | [No default text available]
static const int HF_VNODE_PAYMENT_START   			= 999999; // TODO: Set back to official after testing (OFF: 999999) | After ~1 day we start with Masternodes
static const int HF_VNODE_PAYMENT_ENFORCE 			= 999999; // TODO: Set back to official after testing (OFF: 999999) |  then blocks will go invalid without vnode payment.
static const int HF_ZEROSPEND_FIX 					= 1;


static const int HF_LBK3_HEIGHT_TESTNET 			= HF_LBK3_HEIGHT; // TODO: Modify for engagement height
static const int HF_VNODE_HEIGHT_TESTNET 			= HF_VNODE_PAYMENT_START;


/** The maximum allowed size for a serialized block, in bytes (only for buffer size limits) */
static const unsigned int MAX_BLOCK_SERIALIZED_SIZE = 2000000;
/** The maximum allowed weight for a block, see BIP 141 (network rule) */
static const unsigned int MAX_BLOCK_WEIGHT 			= 2000000;
/** The maximum allowed size for a block excluding witness data, in bytes (network rule) */
static const unsigned int MAX_BLOCK_BASE_SIZE 		= 2000000;
/** The maximum allowed number of signature check operations in a block (network rule) */
static int64_t MAX_BLOCK_SIGOPS_COST 				= 400000;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int COINBASE_MATURITY 					= 50;

/** Flags for nSequence and nLockTime locks */
enum {
    /* Interpret sequence numbers as relative lock-time constraints. */
    LOCKTIME_VERIFY_SEQUENCE 						= (1 << 0),

    /* Use GetMedianTimePast() instead of nTime for end point timestamp. */
    LOCKTIME_MEDIAN_TIME_PAST 						= (1 << 1),
};

#endif // BITCOIN_CONSENSUS_CONSENSUS_H
