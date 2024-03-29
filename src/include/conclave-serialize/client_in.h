/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_CLIENT_IN_H
#define CONCLAVE_SERIALIZE_CLIENT_IN_H

#include <conclave-serialize/commands.h>
#include <conclave-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldInStream;
struct ImprintAllocator;

int clvSerializeClientInListRoomsResponse(struct FldInStream* stream,
    struct ImprintAllocator* allocator, ClvSerializeListRoomsResponseOptions* options);
int clvSerializeClientInLogin(struct FldInStream* inStream, ClvSerializeClientNonce* clientNonce,
    ClvSerializeUserSessionId* userSessionId);
int clvSerializeClientInPingResponse(
    struct FldInStream* stream, ClvSerializePingResponseOptions* options);

#endif
