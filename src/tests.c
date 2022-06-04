#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include "cfxp/fix64.h"

static void test_init() {
  cfxp_fix64_t x = cfxp_fix64_new(2, 25);
  assert(cfxp_fix64_exp(x) == 2);
  assert(cfxp_fix64_val(x) == 25);
}

static void test_arith() {
  assert(cfxp_fix64_add(cfxp_fix64_new(2, 75), cfxp_fix64_new(2, 25)) == cfxp_fix64_new(2, 100));
  assert(cfxp_fix64_sub(cfxp_fix64_new(2, 75), cfxp_fix64_new(2, 25)) == cfxp_fix64_new(2, 50));
  assert(cfxp_fix64_mul(cfxp_fix64_new(2, 25), cfxp_fix64_new(2, 200)) == cfxp_fix64_new(2, 50));
  assert(cfxp_fix64_div(cfxp_fix64_new(2, 50), cfxp_fix64_new(2, 200)) == cfxp_fix64_new(2, 25));
}

static void test_trunc_frac() {
  cfxp_fix64_t x = cfxp_fix64_new(2, 725);
  assert(cfxp_fix64_trunc(x) == 7);
  assert(cfxp_fix64_frac(x) == 25);
}

int main() {
  test_init();
  test_arith();
  test_trunc_frac();
}
