#include "cfxp/fix64.h"

uint64_t cfxp_scale(uint8_t exp) {
  uint64_t s = 1;
  while (exp--) { s *= 10; }
  return s;
}


cfxp_fix64_t cfxp_fix64_new(uint8_t exp, uint64_t val) {
  return (cfxp_fix64_t)((exp & ((1 << CFXP_FIX64_EXP_BITS) - 1)) + (val << CFXP_FIX64_EXP_BITS));
}


uint8_t cfxp_fix64_exp(cfxp_fix64_t x) { return x & ((1 << CFXP_FIX64_EXP_BITS) - 1); }

uint64_t cfxp_fix64_val(cfxp_fix64_t x) { return x >> CFXP_FIX64_EXP_BITS; }


cfxp_fix64_t cfxp_fix64_add(cfxp_fix64_t x, cfxp_fix64_t y) {
  uint8_t xe = cfxp_fix64_exp(x);
  return cfxp_fix64_new(xe, cfxp_fix64_val(x) + cfxp_fix64_val(y) * cfxp_scale(xe) / cfxp_scale(cfxp_fix64_exp(y)));
}

cfxp_fix64_t cfxp_fix64_sub(cfxp_fix64_t x, cfxp_fix64_t y) {
  uint8_t xe = cfxp_fix64_exp(x);
  return cfxp_fix64_new(xe, cfxp_fix64_val(x) - cfxp_fix64_val(y) * cfxp_scale(xe) / cfxp_scale(cfxp_fix64_exp(y)));
}

cfxp_fix64_t cfxp_fix64_mul(cfxp_fix64_t x, cfxp_fix64_t y) {
  return cfxp_fix64_new(cfxp_fix64_exp(x), cfxp_fix64_val(x) * cfxp_fix64_val(y) / cfxp_scale(cfxp_fix64_exp(y)));
}

cfxp_fix64_t cfxp_fix64_div(cfxp_fix64_t x, cfxp_fix64_t y) {
  return cfxp_fix64_new(cfxp_fix64_exp(x), cfxp_fix64_val(x) / (cfxp_fix64_val(y) / cfxp_scale(cfxp_fix64_exp(y))));
}


uint64_t cfxp_fix64_trunc(cfxp_fix64_t x) { return cfxp_fix64_val(x) / cfxp_scale(cfxp_fix64_exp(x)); }

uint64_t cfxp_fix64_frac(cfxp_fix64_t x) {
  uint64_t xv = cfxp_fix64_val(x), xs = cfxp_scale(cfxp_fix64_exp(x));
  return xv - (xv / xs) * xs;
}
