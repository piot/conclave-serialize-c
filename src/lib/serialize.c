/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <conclave-serialize/debug.h>
#include <conclave-serialize/serialize.h>
#include <flood/in_stream.h>
#include <flood/out_stream.h>

void clvSerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix)
{
    // CLOG_VERBOSE("%s: cmd: %s", prefix, clvSerializeCmdToString(cmd));
    fldOutStreamWriteUInt8(outStream, cmd);
}

void clvSerializeWriteRoomId(struct FldOutStream* stream, ClvSerializeRoomId roomId)
{
    if (roomId == 0) {
        CLOG_ERROR("roomId zero is reserved");
    }
    fldOutStreamWriteMarker(stream, 0x85);
    fldOutStreamWriteUInt16(stream, roomId);
}

void clvSerializeWriteUserSessionId(struct FldOutStream* stream, ClvSerializeUserSessionId userSessionId)
{
    if (userSessionId == 0) {
        CLOG_ERROR("userSessionId zero is reserved");
    }
    fldOutStreamWriteMarker(stream, 0x86);
    fldOutStreamWriteUInt64(stream, userSessionId);
}

int clvSerializeReadRoomId(struct FldInStream* stream, ClvSerializeRoomId* roomId)
{
    fldInStreamCheckMarker(stream, 0x85);
    return fldInStreamReadUInt16(stream, roomId);
}

int clvSerializeReadUserSessionId(struct FldInStream* stream, ClvSerializeUserSessionId* userSessionId)
{
    fldInStreamCheckMarker(stream, 0x86);
    return fldInStreamReadUInt64(stream, userSessionId);
}

int clvSerializeWriteRoomConnectionIndex(struct FldOutStream* stream,
                                         ClvSerializeRoomConnectionIndex roomConnectionIndex)
{
    return fldOutStreamWriteUInt8(stream, roomConnectionIndex);
}

int clvSerializeReadRoomConnectionIndex(struct FldInStream* stream,
                                        ClvSerializeRoomConnectionIndex* roomConnectionIndex)
{
    return fldInStreamReadUInt8(stream, roomConnectionIndex);
}

int clvSerializeWriteString(FldOutStream* stream, const char* s)
{
    size_t len = tc_strlen(s);
    fldOutStreamWriteUInt8(stream, len);
    return fldOutStreamWriteOctets(stream, (const uint8_t*) s, len);
}

int clvSerializeReadString(struct FldInStream* stream, char* buf, size_t maxLength)
{
    uint8_t stringLength;
    fldInStreamReadUInt8(stream, &stringLength);
    if (stringLength + 1 > maxLength) {
        return -1;
    }
    int errorCode = fldInStreamReadOctets(stream, (uint8_t*) buf, stringLength);
    if (errorCode < 0) {
        return errorCode;
    }
    buf[stringLength] = 0;
    return stringLength;
}
