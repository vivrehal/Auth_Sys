
#ifndef SHA256_H
#define SHA256_H

#include <stdint.h>


void vcrypt(const uint8_t *message, size_t len, char hashResult[65]);

#endif 
