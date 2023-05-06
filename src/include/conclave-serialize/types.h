/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_TYPES_H
#define CONCLAVE_SERIALIZE_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef uint32_t ClvSerializeRoomId;
typedef uint32_t ClvSerializeSessionId;
typedef uint8_t ClvSerializeRoomConnectionIndex;

struct BlobStreamOutEntry;

typedef struct ClvSerializeRoomCreatePlayerOptions {
    uint8_t localUserDeviceIndex;
    const char* name;
} ClvSerializeRoomCreatePlayerOptions;

#define MAX_LOCAL_PLAYERS (4)

typedef struct ClvSerializeRoomCreateOptions {
    size_t maxNumberOfPlayers;
    int flags;
    const char* name;
} ClvSerializeRoomCreateOptions;

typedef struct ClvSerializeRoomJoinOptions {
    const char* name;
} ClvSerializeRoomJoinOptions;

typedef struct ClvSerializeRoomReJoinOptions {
    uint64_t roomId;
    uint8_t roomConnectionIndex;
} ClvSerializeRoomReJoinOptions;

#endif
