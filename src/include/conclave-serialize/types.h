/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_TYPES_H
#define CONCLAVE_SERIALIZE_TYPES_H

#include <stddef.h>
#include <stdint.h>

#include <conclave-serialize/version.h>
#include <guise-serialize/types.h>

typedef uint16_t ClvSerializeRoomId;
typedef uint64_t ClvSerializeUserSessionId;
typedef uint8_t ClvSerializeRoomConnectionIndex;
typedef uint64_t ClvSerializeApplicationId;
typedef uint64_t ClvSerializeClientNonce;
typedef uint64_t ClvSerializeTerm;
typedef uint64_t ClvSerializeKnowledge;

typedef enum ClvSerializeConnectedToOwnerState {
    ClvSerializeConnectedToOwnerStateUndefined,
    ClvSerializeConnectedToOwnerStateConnected,
    ClvSerializeConnectedToOwnerStateDisconnected
} ClvSerializeConnectedToOwnerState;

struct BlobStreamOutEntry;

typedef struct ClvSerializeRoomCreateOptions {
    ClvSerializeApplicationId applicationId;
    ClvSerializeApplicationVersion applicationVersion;
    uint8_t maxNumberOfPlayers;
    uint8_t flags;
    char name[64];
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
    ClvSerializeApplicationVersion applicationVersion;
    const char* roomName;
    GuiseSerializeUserId ownerUserId;
    uint8_t memberCount;
    uint8_t maxMemberCount;
    uint8_t* externalStateOctets;
    uint16_t externalStateOctetCount;
} ClvSerializeRoomInfo;

#define CLV_MAX_ROOM_COUNT_QUERY_RESPONSE (16)

typedef struct ClvSerializeListRoomsResponseOptions {
    size_t roomInfoCount;
    ClvSerializeRoomInfo roomInfos[CLV_MAX_ROOM_COUNT_QUERY_RESPONSE];
} ClvSerializeListRoomsResponseOptions;

#define CLV_MAX_MEMBERS_IN_ROOM (16)

typedef struct ClvSerializeRoomWithMembersInfo {
    GuiseSerializeUserId members[CLV_MAX_MEMBERS_IN_ROOM];
    size_t memberCount;
    uint8_t indexOfOwner;
} ClvSerializeRoomWithMembersInfo;

typedef struct ClvSerializePingResponseOptions {
    uint64_t version;
    ClvSerializeTerm term;
    ClvSerializeRoomWithMembersInfo roomInfo;
} ClvSerializePingResponseOptions;

#endif
