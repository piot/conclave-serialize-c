/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <conclave-serialize/commands.h>
#include <conclave-serialize/debug.h>
#include <stdio.h>

const char* clvSerializeCmdToString(uint8_t t)
{
    switch (t) {
        case clvSerializeCmdRoomJoin:
            return "RoomJoin";
        case clvSerializeCmdRoomReJoin:
            return "RoomReJoin";
        case clvSerializeCmdLogin:
            return "Login";
        case clvSerializeCmdRoomCreate:
            return "RoomCreate";
        case clvSerializeCmdPing:
            return "Ping";
        case clvSerializeCmdRoomCreateResponse:
            return "RoomCreateResponse";
        case clvSerializeCmdLoginResponse:
            return "LoginResponse";
        case clvSerializeCmdRoomJoinResponse:
            return "RoomJoinResponse";
        case clvSerializeCmdRoomReJoinResponse:
            return "RoomReJoinResponse";
        case clvSerializeCmdListRooms:
            return "ListRooms";
        case clvSerializeCmdListRoomsResponse:
            return "ListRoomsResponse";
        case clvSerializeCmdPingResponse:
            return "PingResponse";
        default: {
            static char buf[128];
            tc_snprintf(buf, 128, "no idea %02X", t);
            return buf;
        }
    }
}
