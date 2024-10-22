#ifndef Segment3D_H
#define Segment3D_H

#include "Vector3D.h"

#define epsilon 1e-7

class Segment3D {
 public:
  Segment3D();
  Segment3D(Vector3D start_, Vector3D end_);
  ~Segment3D() = default;

  bool Intersect(const Segment3D& B, Vector3D& result);

 private:
  Vector3D start;
  Vector3D end;
};

#endif