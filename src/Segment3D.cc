#include "Segment3D.h"

Segment3D::Segment3D() : start(Vector3D()), end(Vector3D()) {}

Segment3D::Segment3D(Vector3D start_, Vector3D end_) {
  start = start_;
  end = end_;
}

bool Segment3D::Intersect(const Segment3D& B, Vector3D& result) {
  bool ans = false;
  Vector3D vec1 = end - start;      // Вектор отрезка A
  Vector3D vec2 = B.end - B.start;  // Вектор отрезка B
  Vector3D vec3 = B.start - start;  // Вектор между началами отрезков

  // Вычисление объема параллелепипеда для проверки плоскости
  double volume = vec1.dot(vec2.cross(vec3));

  if (fabs(volume) < epsilon) {
    Vector3D crossVec = vec1.cross(vec2);
    double denom = crossVec.dot(crossVec);
    if (fabs(denom) < epsilon) {
      // Проверка на коллинеарность отрезков
      Vector3D collinearityCheck = vec1.cross(vec3);
      if (collinearityCheck.dot(collinearityCheck) < epsilon) {
        // Проверка на пересечение проекций коллинеарных отрезков
        Vector3D vec4 = B.end - start;
        double t1 = vec3.dot(vec1) / vec1.dot(vec1);
        double t2 = vec4.dot(vec1) / vec1.dot(vec1);

        double tmin = std::max(0.0, std::min(t1, t2));
        double tmax = std::min(1.0, std::max(t1, t2));

        // Проверяем, совпадают ли отрезки
        if (tmin == 0.0 && tmax == 1.0) {
          result = start;  // В качестве точки пересечения выбрано начало
          ans = true;
        } else if (tmin <= tmax + epsilon) {
          result = start + vec1 * tmin;
          ans = true;  // Коллинеарные отрезки пересекаются на промежутке либо в
                       // одной точке
        }
      }
    } else {
      double t1 = vec3.cross(vec2).dot(crossVec) / denom;
      double t2 = vec3.cross(vec1).dot(crossVec) / denom;

      if ((t1 >= 0) && (t1 <= 1.0) && (t2 >= 0) && (t2 <= 1.0)) {
        result = start + vec1 * t1;
        ans = true;
      }
    }
  }
  return ans;
}
