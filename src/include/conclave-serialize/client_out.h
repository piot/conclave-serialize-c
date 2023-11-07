/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_H
#define CONCLAVE_SERIALIZE_H

#include <conclave-serialize/commands.h>
#include <conclave-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int clvSerializeClientOutChallenge(struct FldOutStream* stream, ClvSerializeClientNonce clientNonce);
int clvSerializeClientOutLogin(struct FldOutStream* stream, ClvSerializeClientNonce clientNonce,
                               ClvSerializeServerChallenge challenge, const char* name);
int clvSerializeClientOutRoomCreate(struct FldOutStream* stream, ClvSerializeUserSessionId userSessionId,
                                    const ClvSerializeRoomCreateOptions* options);
int clvSerializeClientOutRoomJoin(struct FldOutStream* stream, ClvSerializeUserSessionId userSessionId,
                                  const ClvSerializeRoomJoinOptions* players);
int clvSerializeClientOutRoomReJoin(struct FldOutStream* stream, const ClvSerializeRoomReJoinOptions* options);
int clvSerializeClientOutGameJoin(struct FldOutStream* stream, ClvSerializeRoomId roomId, uint8_t roomConnectionIndex);
int clvSerializeClientOutRoomAndConnectionIndex(struct FldOutStream* stream, ClvSerializeRoomId roomId,
                                                uint8_t roomConnectionIndex);

int clvSerializeClientOutListRooms(struct FldOutStream* stream, ClvSerializeUserSessionId userSessionId,
                                   const ClvSerializeListRoomsOptions* options);

#endif
