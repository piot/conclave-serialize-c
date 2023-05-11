/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <conclave-serialize/serialize.h>
#include <conclave-serialize/server_in.h>
#include <flood/in_stream.h>

int clvSerializeServerInListRooms(FldInStream* stream, ClvSerializeListRoomsOptions* options)
{
    fldInStreamReadUInt64(stream, &options->applicationId);
    return fldInStreamReadUInt8(stream, &options->maximumCount);
}

int clvSerializeServerInLogin(FldInStream* inStream, ClvSerializeClientNonce* clientNonce,
                              ClvSerializeServerChallenge* serverChallenge, char* target, size_t maxTarget)
{
    clvSerializeReadClientNonce(inStream, clientNonce);
    clvSerializeReadServerChallenge(inStream, serverChallenge);
    clvSerializeReadString(inStream, target, maxTarget);

    return 0;
}

int clvSerializeServerInChallenge(FldInStream* inStream, ClvSerializeClientNonce* clientNonce)
{
    return clvSerializeReadClientNonce(inStream, clientNonce);
}
