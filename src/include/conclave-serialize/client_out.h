/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_H
#define CONCLAVE_SERIALIZE_H

#include <conclave-serialize/commands.h>
#include <conclave-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int clvSerializeClientOutLogin(struct FldOutStream* stream, const char* name);
int clvSerializeClientOutRoomCreate(struct FldOutStream* stream, uint32_t userSessionId,
                                    const ClvSerializeRoomCreateOptions* options);
int clvSerializeClientOutRoomJoin(struct FldOutStream* stream, uint32_t userSessionId,
                                  const ClvSerializeRoomJoinOptions* players);
int clvSerializeClientOutRoomReJoin(struct FldOutStream* stream, const ClvSerializeRoomReJoinOptions* options);
int clvSerializeClientOutGameJoin(struct FldOutStream* stream, uint32_t roomId, uint8_t roomConnectionIndex);
int clvSerializeClientOutRoomAndConnectionIndex(struct FldOutStream* stream, uint32_t roomId,
                                                uint8_t roomConnectionIndex);

#endif
