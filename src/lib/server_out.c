/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <conclave-serialize/commands.h>
#include <conclave-serialize/server_out.h>
#include <flood/out_stream.h>

static int writeRoomConnectionIndex(FldOutStream* outStream, uint8_t roomConnectionIndex)
{
    fldOutStreamWriteUInt8(outStream, roomConnectionIndex);

    return 0;
}

#define DEBUG_PREFIX "ServerOut"

int clvSerializeServerOutRoomCreate(FldOutStream* outStream, ClvSerializeRoomId roomId,
                                    ClvSerializeRoomConnectionIndex roomConnectionIndex)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdRoomCreateResponse, DEBUG_PREFIX);
    clvSerializeWriteRoomId(outStream, roomId);

    int errorCode = writeRoomConnectionIndex(outStream, roomConnectionIndex);
    if (errorCode < 0) {
        return errorCode;
    }
    return errorCode;
}

int clvSerializeServerOutChallenge(FldOutStream* outStream, ClvSerializeClientNonce forClient,
                                   ClvSerializeServerChallenge challenge)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdChallengeResponse, DEBUG_PREFIX);
    clvSerializeWriteClientNonce(outStream, forClient);
    clvSerializeWriteServerChallenge(outStream, challenge);

    return 0;
}

int clvSerializeServerOutLogin(FldOutStream* outStream, ClvSerializeClientNonce forClient,
                               ClvSerializeUserSessionId userSessionId)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdLoginResponse, DEBUG_PREFIX);
    clvSerializeWriteClientNonce(outStream, forClient);
    clvSerializeWriteUserSessionId(outStream, userSessionId);

    return 0;
}


int clvSerializeServerOutRoomJoin(FldOutStream* outStream, ClvSerializeRoomId roomId,
                                  ClvSerializeRoomConnectionIndex roomConnectionIndex)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdRoomJoinResponse, DEBUG_PREFIX);
    clvSerializeWriteRoomId(outStream, roomId);
    int errorCode = writeRoomConnectionIndex(outStream, roomConnectionIndex);
    if (errorCode < 0) {
        return errorCode;
    }

    return 0;
}

int clvSerializeServerOutListRooms(FldOutStream* outStream, ClvSerializeListRoomsResponseOptions* options)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdListRoomsResponse, DEBUG_PREFIX);
    size_t roomInfoCountToWrite = options->roomInfoCount > 16 ? 16 : options->roomInfoCount;
    fldOutStreamWriteUInt8(outStream, (uint8_t)roomInfoCountToWrite);
    for (size_t i = 0; i < roomInfoCountToWrite; ++i) {
        const ClvSerializeRoomInfo* roomInfo = &options->roomInfos[i];
        clvSerializeWriteRoomId(outStream, roomInfo->roomId);
        fldOutStreamWriteUInt64(outStream, roomInfo->applicationId);
        clvSerializeWriteString(outStream, roomInfo->roomName);
        clvSerializeWriteString(outStream, roomInfo->hostUserName);
    }

    return 0;
}
