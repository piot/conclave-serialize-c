/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
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

int clvSerializeServerOutLogin(FldOutStream* outStream, ClvSerializeSessionId userSessionId)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdLoginResponse, DEBUG_PREFIX);
    fldOutStreamWriteUInt32(outStream, userSessionId);

    return 0;
}

int clvSerializeServerOutPacketHeader(FldOutStream* outStream)
{
    clvSerializeWriteCommand(outStream, clvSerializeCmdPacketResponse, DEBUG_PREFIX);


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
