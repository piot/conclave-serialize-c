/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <conclave-serialize/client_out.h>
#include <conclave-serialize/serialize.h>
#include <flood/out_stream.h>
#include <tiny-libc/tiny_libc.h>

int clvSerializeClientOutRoomCreate(FldOutStream* stream, ClvSerializeUserSessionId userSessionId,
                                    const ClvSerializeRoomCreateOptions* options)
{
    fldOutStreamWriteUInt8(stream, clvSerializeCmdRoomCreate);
    clvSerializeWriteUserSessionId(stream, userSessionId);
    clvSerializeWriteString(stream, options->name);
    fldOutStreamWriteUInt8(stream, options->maxNumberOfPlayers);
    fldOutStreamWriteUInt8(stream, options->flags);

    return 0;
}

int clvSerializeClientOutRoomAndConnectionIndex(FldOutStream* stream, ClvSerializeRoomId roomId, uint8_t roomConnectionIndex)
{
    clvSerializeWriteRoomId(stream, roomId);

    return fldOutStreamWriteUInt8(stream, roomConnectionIndex);
}

#define COMMAND_DEBUG "ClientOut"

int clvSerializeClientOutLogin(FldOutStream* stream, const char* name)
{
    clvSerializeWriteCommand(stream, clvSerializeCmdLogin, COMMAND_DEBUG);
    clvSerializeWriteString(stream, name);

    return 0;
}

int clvSerializeClientOutRoomJoin(FldOutStream* stream, ClvSerializeUserSessionId userSessionId,
                                  const ClvSerializeRoomJoinOptions* options)
{
    clvSerializeWriteCommand(stream, clvSerializeCmdRoomJoin, COMMAND_DEBUG);
    clvSerializeWriteUserSessionId(stream, userSessionId);
    clvSerializeWriteRoomId(stream, options->roomIdToJoin);

    return 0;
}

int clvSerializeClientOutRoomReJoin(FldOutStream* stream, const ClvSerializeRoomReJoinOptions* options)
{
    clvSerializeWriteCommand(stream, clvSerializeCmdRoomReJoin, COMMAND_DEBUG);
    clvSerializeClientOutRoomAndConnectionIndex(stream, options->roomId, options->roomConnectionIndex);

    return 0;
}

int clvSerializeClientOutListRooms(FldOutStream* stream, ClvSerializeUserSessionId userSessionId,
                                   const ClvSerializeListRoomsOptions* options)
{
    clvSerializeWriteCommand(stream, clvSerializeCmdListRooms, COMMAND_DEBUG);
    clvSerializeWriteUserSessionId(stream, userSessionId);
    fldOutStreamWriteUInt64(stream, options->applicationId);
    fldOutStreamWriteUInt8(stream, options->maximumCount);

    return 0;
}
