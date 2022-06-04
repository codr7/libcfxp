#ifndef LIBCFXP_FIX64_H
#define LIBCFXP_FIX64_H

#include <stdint.h>

typedef uint64_t cfxp_fix64_t;

cfxp_fix64_t cfxp_fix64_new(uint64_t val, uint8_t exp);
cfxp_fix64_t cfxp_fix64_add(cfxp_fix64_t x, cfxp_fix64_t y);

#endif
