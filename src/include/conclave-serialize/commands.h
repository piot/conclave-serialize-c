/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_COMMANDS_H
#define CONCLAVE_SERIALIZE_COMMANDS_H

#include <stdint.h>

// TODO: change to extern.

// Requests
#define clvSerializeCmdNop (0x00)

#define clvSerializeCmdRoomCreate (0x01)
#define clvSerializeCmdLogin (0x02)
#define clvSerializeCmdRoomJoin (0x04)
#define clvSerializeCmdPacket (0x05)
#define clvSerializeCmdRoomReJoin (0x08)
#define clvSerializeCmdListRooms (0x09)

// Responses
#define clvSerializeCmdRoomCreateResponse (0x21)
#define clvSerializeCmdLoginResponse (0x22)
#define clvSerializeCmdPacketToClient (0x24)
#define clvSerializeCmdRoomJoinResponse (0x25)
#define clvSerializeCmdRoomReJoinResponse (0x28)
#define clvSerializeCmdListRoomsResponse (0x29)

#endif
