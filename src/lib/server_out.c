/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <conclave-serialize/commands.h>
#include <conclave-serialize/debug.h>
#include <conclave-serialize/server_out.h>
#include <flood/out_stream.h>

static int writeConnectionIndexAndParticipantIds(FldOutStream* outStream, uint8_t roomConnectionIndex,
                                                 const ClvSerializeMember* members, size_t memberCount)
{
    fldOutStreamWriteUInt8(outStream, roomConnectionIndex);
    fldOutStreamWriteUInt8(outStream, memberCount);

    for (size_t i = 0; i < memberCount; ++i) {
        const ClvSerializeMember* member = &members[i];
        fldOutStreamWriteUInt8(outStream, member->localIndex);
        fldOutStreamWriteUInt8(outStream, member->id);
    }

    return 0;
}

#define DEBUG_PREFIX "ServerOut"

int clvSerializeServerOutRoomCreate(FldOutStream* outStream, ClvSerializeRoomId roomId,
                                    ClvSerializeMemberConnectionIndex roomConnectionIndex,
                                    const ClvSerializeMember* members, size_t memberCount)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdRoomCreateResponse, DEBUG_PREFIX);
    clvSerializeWriteRoomId(outStream, roomId);

    int errorCode = writeConnectionIndexAndParticipantIds(outStream, roomConnectionIndex, members, memberCount);
    if (errorCode < 0) {
        return errorCode;
    }
    return errorCode;
}

int clvSerializeServerOutLogin(FldOutStream* outStream, ClvSerializeSessionId userSessionId)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdLoginResponse, DEBUG_PREFIX);
    fldOutStreamWriteUInt32(outStream, userSessionId);

    return 0;
}

int clvSerializeServerOutPacketHeader(FldOutStream* outStream, uint32_t lastReceivedStepIdFromClient,
                                      size_t connectionSpecificBufferCount, int8_t deltaAgainstAuthoritativeBuffer)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdPacketResponse, DEBUG_PREFIX);
    fldOutStreamWriteUInt8(outStream, connectionSpecificBufferCount);
    fldOutStreamWriteInt8(outStream, deltaAgainstAuthoritativeBuffer);
    fldOutStreamWriteUInt32(outStream, lastReceivedStepIdFromClient);

    return 0;
}

int clvSerializeServerOutRoomJoin(FldOutStream* outStream, ClvSerializeRoomId roomId,
                                  ClvSerializeMemberConnectionIndex roomConnectionIndex,
                                  const ClvSerializeMember* members, size_t memberCount)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdRoomJoinResponse, DEBUG_PREFIX);
    clvSerializeWriteRoomId(outStream, roomId);

    int errorCode = writeConnectionIndexAndParticipantIds(outStream, roomConnectionIndex, members, memberCount);
    if (errorCode < 0) {
        return errorCode;
    }

    return 0;
}
