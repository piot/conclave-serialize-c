/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_H
#define CONCLAVE_SERIALIZE_H

#include <conclave-serialize/commands.h>
#include <conclave-serialize/types.h>
#include <guise-serialize/types.h>

#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int clvSerializeClientOutLogin(struct FldOutStream* stream, ClvSerializeClientNonce clientNonce,
    GuiseSerializeUserSessionId userSessionId);
int clvSerializeClientOutRoomCreate(struct FldOutStream* stream,
    ClvSerializeUserSessionId userSessionId, const ClvSerializeRoomCreateOptions* options);
int clvSerializeClientOutRoomJoin(struct FldOutStream* stream,
    ClvSerializeUserSessionId userSessionId, const ClvSerializeRoomJoinOptions* players);
int clvSerializeClientOutRoomReJoin(
    struct FldOutStream* stream, const ClvSerializeRoomReJoinOptions* options);
int clvSerializeClientOutGameJoin(
    struct FldOutStream* stream, ClvSerializeRoomId roomId, uint8_t roomConnectionIndex);
int clvSerializeClientOutRoomAndConnectionIndex(
    struct FldOutStream* stream, ClvSerializeRoomId roomId, uint8_t roomConnectionIndex);

int clvSerializeClientOutListRooms(struct FldOutStream* stream,
    ClvSerializeUserSessionId userSessionId, const ClvSerializeListRoomsOptions* options);

int clvSerializeClientOutPing(
    struct FldOutStream* stream, ClvSerializeUserSessionId userSessionId, uint64_t knowledge);

#endif
