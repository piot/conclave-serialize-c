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
void clvSerializeWriteRoomId(struct FldOutStream* outStream, ClvSerializeRoomId roomId);
void clvSerializeWriteUserSessionId(struct FldOutStream* outStream, ClvSerializeUserSessionId userSessionId);

int clvSerializeReadUserSessionId(struct FldInStream* stream, ClvSerializeUserSessionId* userSessionId);
int clvSerializeReadRoomId(struct FldInStream* stream, ClvSerializeRoomId* roomId);
int clvSerializeReadRoomConnectionIndex(struct FldInStream* stream, ClvSerializeRoomConnectionIndex* roomConnectionIndex);
int clvSerializeWriteRoomConnectionIndex(struct FldOutStream* stream, ClvSerializeRoomConnectionIndex roomConnectionIndex);
int clvSerializeWriteString(struct FldOutStream* stream, const char* s);
int clvSerializeReadString(struct FldInStream* stream, char* buf, size_t maxLength);

#endif
