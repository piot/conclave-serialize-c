/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_SERVER_OUT_H
#define CONCLAVE_SERIALIZE_SERVER_OUT_H

#include <conclave-serialize/serialize.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

typedef struct ClvSerializeMember {
    size_t localIndex;
    size_t id;
} ClvSerializeMember;

typedef struct ClvSerializeGameState {
    uint32_t stepId;
    const uint8_t* gameState;
    size_t gameStateOctetCount;
} ClvSerializeGameState;

int clvSerializeServerOutLogin(struct FldOutStream* outStream, ClvSerializeSessionId userSession);
int clvSerializeServerOutRoomCreate(struct FldOutStream* outStream, ClvSerializeRoomId roomId,
                                    ClvSerializeMemberConnectionIndex connectionIndex,
                                    const ClvSerializeMember* members, size_t memberCount);
int clvSerializeServerOutRoomJoin(struct FldOutStream* outStream, ClvSerializeRoomId roomId,
                                  ClvSerializeMemberConnectionIndex connectionIndex, const ClvSerializeMember* members,
                                  size_t memberCount);

int clvSerializeServerOutPacketHeader(struct FldOutStream* outStream, uint32_t lastReceivedStepIdFromClient,
                                      size_t connectionSpecificBufferCount, int8_t deltaAgainstAuthoritativeBuffer);

#endif
