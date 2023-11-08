/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_TYPES_H
#define CONCLAVE_SERIALIZE_TYPES_H

#include <stddef.h>
#include <stdint.h>

#include <guise-serialize/types.h>

typedef uint16_t ClvSerializeRoomId;
typedef uint64_t ClvSerializeUserSessionId;
typedef uint8_t ClvSerializeRoomConnectionIndex;
typedef uint64_t ClvSerializeApplicationId;
typedef uint64_t ClvSerializeClientNonce;

struct BlobStreamOutEntry;

typedef struct ClvSerializeRoomCreateOptions {
    ClvSerializeApplicationId applicationId;
    size_t maxNumberOfPlayers;
    int flags;
    const char* name;
} ClvSerializeRoomCreateOptions;

typedef struct ClvSerializeRoomJoinOptions {
    ClvSerializeRoomId roomIdToJoin;
} ClvSerializeRoomJoinOptions;

typedef struct ClvSerializeRoomReJoinOptions {
    ClvSerializeRoomId roomId;
    ClvSerializeRoomConnectionIndex roomConnectionIndex;
} ClvSerializeRoomReJoinOptions;

typedef struct ClvSerializeListRoomsOptions {
    ClvSerializeApplicationId applicationId;
    uint8_t maximumCount;
} ClvSerializeListRoomsOptions;

typedef struct ClvSerializeRoomInfo {
    ClvSerializeRoomId roomId;
    ClvSerializeApplicationId applicationId;
    const char* roomName;
    GuiseSerializeUserId ownerUserId;
} ClvSerializeRoomInfo;

#define CLV_MAX_ROOM_COUNT_QUERY_RESPONSE (16)

typedef struct ClvSerializeListRoomsResponseOptions {
    size_t roomInfoCount;
    ClvSerializeRoomInfo roomInfos[CLV_MAX_ROOM_COUNT_QUERY_RESPONSE];
} ClvSerializeListRoomsResponseOptions;

#endif
