#ifndef LMAN_LMAN_H_
#define LMAN_LMAN_H_

#include <stdint.h>
#include <vector>
#include <glog/logging.h>

#include "base/string-printf.h"
#include "sim/sim.h"
#include "util/coordinate.h"
#include "translator/lib.h"

class LambdaManImpl : public LambdaMan {
public:
  void Main() override;
  int Step() override;
  
private:
  static P MakeList(const vector<P>& t);
  P EncodeWorld() const;
  P EncodeGhost(int ghost_index) const;
  
  P state_;
};

#endif  // LMAN_LMAN_H_
