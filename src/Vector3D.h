#ifndef Vector3D_H
#define Vector3D_H

#include <cmath>

class Vector3D {
 public:
  Vector3D();
  Vector3D(double X_, double Y_, double Z_);
  Vector3D(const Vector3D& other) = default;
  ~Vector3D() = default;

  double dot(const Vector3D& other) const;
  Vector3D cross(const Vector3D& other) const;
  Vector3D& operator=(const Vector3D& other_vector);
  Vector3D operator-(const Vector3D& other) const;
  Vector3D operator+(const Vector3D& other) const;
  Vector3D operator*(double scalar) const;
  bool operator==(const Vector3D other_vector) const;
  double X;
  double Y;
  double Z;
};

#endif