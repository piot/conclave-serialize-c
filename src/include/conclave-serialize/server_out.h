/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_SERVER_OUT_H
#define CONCLAVE_SERIALIZE_SERVER_OUT_H

#include <conclave-serialize/serialize.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int clvSerializeServerOutChallenge(struct FldOutStream* outStream, ClvSerializeClientNonce forClient,
                                   ClvSerializeServerChallenge challenge);
int clvSerializeServerOutLogin(struct FldOutStream* outStream, ClvSerializeClientNonce forClient,
                               ClvSerializeUserSessionId userSession);
int clvSerializeServerOutRoomCreate(struct FldOutStream* outStream, ClvSerializeRoomId roomId,
                                    ClvSerializeRoomConnectionIndex connectionIndex);
int clvSerializeServerOutRoomJoin(struct FldOutStream* outStream, ClvSerializeRoomId roomId,
                                  ClvSerializeRoomConnectionIndex connectionIndex);

int clvSerializeServerOutPacketHeader(struct FldOutStream* outStream);
int clvSerializeServerOutListRooms(struct FldOutStream* outStream, ClvSerializeListRoomsResponseOptions* options);

#endif
