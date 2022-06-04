#ifndef LIBCFXP_FIX64_H
#define LIBCFXP_FIX64_H

#include <stdint.h>

#define CFXP_FIX64_EXP_BITS 4

typedef uint64_t cfxp_fix64_t;

cfxp_fix64_t cfxp_fix64_new(uint8_t exp, uint64_t val);
uint8_t cfxp_fix64_exp(cfxp_fix64_t x);
uint64_t cfxp_fix64_val(cfxp_fix64_t x);
cfxp_fix64_t cfxp_fix64_add(cfxp_fix64_t x, cfxp_fix64_t y);
cfxp_fix64_t cfxp_fix64_sub(cfxp_fix64_t x, cfxp_fix64_t y);
cfxp_fix64_t cfxp_fix64_mul(cfxp_fix64_t x, cfxp_fix64_t y);
cfxp_fix64_t cfxp_fix64_div(cfxp_fix64_t x, cfxp_fix64_t y);
uint64_t cfxp_fix64_trunc(cfxp_fix64_t x);
uint64_t cfxp_fix64_frac(cfxp_fix64_t x);

#endif
