#ifndef SBL_SBL_H_

#include "sbl/array<%=n%>.h"

P get_array<%=n%>(P t, int i) {
  int n = <%= n / 2 %>;
  while (n > 0) {
    if (i < n) {
      t = fst(t);
    } else {
      t = snd(t);
      i -= n;
    }
    n = n / 2;
  }
  return t;
}

#endif  // SBL_SBL_H_