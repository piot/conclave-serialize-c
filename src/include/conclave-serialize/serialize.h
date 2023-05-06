/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_SERIALIZE_H
#define CONCLAVE_SERIALIZE_SERIALIZE_H

#include <stdint.h>
#include <stdlib.h>

#include <conclave-serialize/types.h>

struct FldOutStream;
struct FldInStream;

void clvSerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix);
void clvSerializeWriteRoomId(struct FldOutStream* outStream, uint32_t roomId);

int clvSerializeReadRoomId(struct FldInStream* stream, uint32_t* roomId);
int clvSerializeReadRoomConnectionIndex(struct FldInStream* stream, uint8_t* roomConnectionIndex);

#endif
