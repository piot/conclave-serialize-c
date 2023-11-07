/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_DEBUG_H
#define CONCLAVE_SERIALIZE_DEBUG_H

#include <stdint.h>
#include <stdlib.h>

// void clvSerializeDebugHex(const char* debug, const uint8_t* data, size_t length);
const char* clvSerializeCmdToString(uint8_t t);

#endif
