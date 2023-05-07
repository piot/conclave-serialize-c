/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <conclave-serialize/client_in.h>
#include <conclave-serialize/serialize.h>
#include <flood/in_stream.h>
#include <tiny-libc/tiny_libc.h>

int clvSerializeClientInListRoomsResponse(FldInStream* stream, ClvSerializeListRoomsResponseOptions* options)
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
        clvSerializeReadString(stream, tempStr, 32);
        roomInfo->hostUserName = tc_str_dup(tempStr);
    }

    return 0;
}
