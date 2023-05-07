/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <conclave-serialize/server_in.h>
#include <flood/in_stream.h>

int clvSerializeServerInListRooms(FldInStream* stream, ClvSerializeListRoomsOptions* options)
{
    fldInStreamReadUInt64(stream, &options->applicationId);
    return fldInStreamReadUInt8(stream, &options->maximumCount);
}
