#ifndef LBK3_HASH_H
#define LBK3_HASH_H

#include "uint256.h"
#include "common/sph_bmw.h"
#include "common/sph_blake.h"
#include "common/sph_keccak.h"

#ifndef QT_NO_DEBUG
#include <string>
#endif

#ifdef GLOBALDEFINED
#define GLOBAL
#else
#define GLOBAL extern
#endif

GLOBAL sph_bmw512_context       z_bmw;
GLOBAL sph_blake512_context     z_blake;
GLOBAL sph_keccak512_context    z_keccak;

#define fillz() do { \
    sph_bmw512_init(&z_bmw); \
    sph_blake512_init(&z_blake); \
    sph_keccak512_init(&z_keccak); \
} while (0) 

#define ZBMW (memcpy(&ctx_bmw, &z_bmw, sizeof(z_bmw)))
#define ZBLAKE (memcpy(&ctx_blake, &z_blake, sizeof(z_blake)))
#define ZKECCAK (memcpy(&ctx_keccak, &z_keccak, sizeof(z_keccak)))

template<typename T1>
inline uint256 Lbk3_hash(const T1 pbegin, const T1 pend)

{
    sph_bmw512_context       ctx_bmw;
    sph_blake512_context     ctx_blake;
    sph_keccak512_context    ctx_keccak;

    static unsigned char pblank[1];

#ifndef QT_NO_DEBUG
    //std::string strhash;
    //strhash = "";
#endif
    // ------------------ Initial integration of Lbk3 Algorithm --------------------
    // ------------------ Written for Verticalcoin by the****** --------------------
    // ------------------ CryptoCoderz team June 20th 2018***** --------------------
    // ------------------ It utilizes elements of Lyra2Z,****** --------------------
    // ------------------ BlueMidnighWish, and Keccak together* --------------------
    // ------------------ in a semi-random shuffle.************ --------------------

    // -- Semi-random multi-algo hashing round (randomized custom x3 implementation)
    uint512 mask = 8;
    uint512 zero = 0;
    uint512 hash[2];

    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
    sph_bmw512_close(&ctx_bmw, static_cast<void*>(&hash[0]));

    if ((hash[0] & mask) != zero)
    {
        sph_blake512_init(&ctx_blake);
        sph_blake512 (&ctx_blake, static_cast<const void*>(&hash[0]), 64);
        sph_blake512_close(&ctx_blake, static_cast<void*>(&hash[1]));
    }
    else
    {
        sph_keccak512_init(&ctx_keccak);
        sph_keccak512 (&ctx_keccak, static_cast<const void*>(&hash[0]), 64);
        sph_keccak512_close(&ctx_keccak, static_cast<void*>(&hash[1]));
    }

    return hash[1].trim256();
}






#endif // LBK3_HASH_H