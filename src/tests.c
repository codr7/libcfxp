#include <assert.h>
#include "cfxp/fix64.h"

int main() {
  assert(cfxp_fix64_add(cfxp_fix64_new(25, 2), cfxp_fix64_new(75, 2)) == cfxp_fix64_new(1, 0));
}
