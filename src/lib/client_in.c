/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <conclave-serialize/client_in.h>
#include <conclave-serialize/serialize.h>
#include <flood/in_stream.h>
#include <guise-serialize/serialize.h>
#include <imprint/allocator.h>
#include <tiny-libc/tiny_libc.h>

int clvSerializeClientInListRoomsResponse(
    FldInStream* stream, ImprintAllocator* allocator, ClvSerializeListRoomsResponseOptions* options)
{
    uint8_t roomInfoCount;
    fldInStreamReadUInt8(stream, &roomInfoCount);
    options->roomInfoCount = roomInfoCount;

    size_t roomInfoCountToRead = roomInfoCount > 16 ? 16 : roomInfoCount;
    for (size_t i = 0; i < roomInfoCountToRead; ++i) {
        ClvSerializeRoomInfo* roomInfo = &options->roomInfos[i];
        clvSerializeReadRoomId(stream, &roomInfo->roomId);
        fldInStreamReadUInt64(stream, &roomInfo->applicationId);
        char tempStr[32];
        clvSerializeReadString(stream, tempStr, 32);
        roomInfo->roomName = tc_str_dup(tempStr);
        guiseSerializeReadUserId(stream, &roomInfo->ownerUserId);

        fldInStreamReadUInt8(stream, &roomInfo->memberCount);
        fldInStreamReadUInt8(stream, &roomInfo->maxMemberCount);
        fldInStreamReadUInt16(stream, &roomInfo->externalStateOctetCount);

        roomInfo->externalStateOctets
            = IMPRINT_ALLOC(allocator, roomInfo->externalStateOctetCount, "external state octets");
        fldInStreamReadOctets(
            stream, roomInfo->externalStateOctets, roomInfo->externalStateOctetCount);
    }

    return 0;
}

int clvSerializeClientInPingResponse(FldInStream* stream, ClvSerializePingResponseOptions* options)
{
    uint8_t memberCount;
    fldInStreamReadUInt8(stream, &memberCount);
    options->roomInfo.memberCount = memberCount;

    for (size_t i = 0; i < memberCount; ++i) {
        GuiseSerializeUserId* userId = &options->roomInfo.members[i];

        guiseSerializeReadUserId(stream, userId);
    }

    fldInStreamReadUInt8(stream, &options->roomInfo.indexOfOwner);

    return 0;
}

int clvSerializeClientInLogin(struct FldInStream* inStream, ClvSerializeClientNonce* clientNonce,
    ClvSerializeUserSessionId* userSessionId)
{
    clvSerializeReadClientNonce(inStream, clientNonce);

    return clvSerializeReadUserSessionId(inStream, userSessionId);
}
