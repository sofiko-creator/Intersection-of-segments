#include "Vector3D.h"

Vector3D::Vector3D() : X(0.0), Y(0.0), Z(0.0) {}

Vector3D::Vector3D(double X_, double Y_, double Z_) : X(X_), Y(Y_), Z(Z_) {}

// Операция присваивания
Vector3D& Vector3D::operator=(const Vector3D& other_vector) {
  X = other_vector.X;
  Y = other_vector.Y;
  Z = other_vector.Z;

  return *this;
}

// Скалярное произведение
double Vector3D::dot(const Vector3D& other) const {
  return X * other.X + Y * other.Y + Z * other.Z;
}

// Векторное произведение
Vector3D Vector3D::cross(const Vector3D& other) const {
  return Vector3D(Y * other.Z - Z * other.Y, Z * other.X - X * other.Z,
                  X * other.Y - Y * other.X);
}

// Операция вычитания
Vector3D Vector3D::operator-(const Vector3D& other) const {
  return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
}

// Операция сложения
Vector3D Vector3D::operator+(const Vector3D& other) const {
  return Vector3D(X + other.X, Y + other.Y, Z + other.Z);
}

// Операция умножения на скаляр
Vector3D Vector3D::operator*(double scalar) const {
  return Vector3D(X * scalar, Y * scalar, Z * scalar);
}

// Операция сравнения
bool Vector3D::operator==(const Vector3D other_vector) const {
  if ((X == other_vector.X) && (Y == other_vector.Y) && (Z == other_vector.Z)) {
    return true;
  }
  return false;
}
