/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_SERVER_IN_H
#define CONCLAVE_SERIALIZE_SERVER_IN_H

#include <conclave-serialize/commands.h>
#include <conclave-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldInStream;

int clvSerializeServerInListRooms(struct FldInStream* stream,
                                 ClvSerializeListRoomsOptions* options);

#endif
