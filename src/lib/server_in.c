/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <conclave-serialize/serialize.h>
#include <conclave-serialize/server_in.h>
#include <flood/in_stream.h>

int clvSerializeServerInListRooms(FldInStream* stream, ClvSerializeListRoomsOptions* options)
{
    fldInStreamReadUInt64(stream, &options->applicationId);
    return fldInStreamReadUInt8(stream, &options->maximumCount);
}

int clvSerializeServerInPing(struct FldInStream* stream, uint64_t* knowledge,
    ClvSerializeTerm* term, ClvSerializeConnectedToOwnerState* connectedToOwner)
{
    clvSerializeReadTerm(stream, term);
    uint8_t flags;
    fldInStreamReadUInt8(stream, &flags);
    *connectedToOwner = (ClvSerializeConnectedToOwnerState)flags;
    return fldInStreamReadUInt64(stream, knowledge);
}

int clvSerializeServerInCreateRoom(FldInStream* stream, ClvSerializeRoomCreateOptions* options)
{
    fldInStreamReadUInt64(stream, &options->applicationId);
    clvSerializeReadVersion(stream, &options->applicationVersion);
    clvSerializeReadString(stream, options->name, 64);
    fldInStreamReadUInt8(stream, &options->maxNumberOfPlayers);
    return fldInStreamReadUInt8(stream, &options->flags);
}
