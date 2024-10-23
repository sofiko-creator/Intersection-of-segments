#include <gtest/gtest.h>

#include <iostream>

#include "../Segment3D.h"
#include "../Vector3D.h"

TEST(Segments_intersect, Test_1) {
  Vector3D dot1(0, 0, 0), dot2(1, 1, 1);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(1, 0, 0), dot4(0, 1, 1);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(0.5, 0.5, 0.5);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_2) {
  Vector3D dot1(0, 0, 0), dot2(2, 2, 2);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(1, 1, 1), dot4(3, 3, 3);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(1, 1, 1);  // начальная точка сегмента пересечения
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_3) {
  Vector3D dot1(0, 0, 0), dot2(1, 1, 1);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(1, 1, 1), dot4(3, 3, 3);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(1, 1, 1);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_4) {
  Vector3D dot1(0, 4, 0), dot2(-3, 2, 4);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(-3, 0, 0), dot4(-3, 2, 4);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(-3, 2, 4);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_5) {
  Vector3D dot2(0, 4, 0), dot1(-3, 2, 4);
  Segment3D seg1(dot1, dot2);

  Vector3D dot4(-3, 0, 0), dot3(-3, 2, 4);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(-3, 2, 4);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_6) {
  Vector3D dot1(0, 4, 0), dot2(-3, 2, 4);
  Segment3D seg1(dot1, dot2);

  Vector3D dot4(-3, 0, 0), dot3(-3, 2, 4);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(-3, 2, 4);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_7) {
  Vector3D dot2(0, 4, 0), dot1(-3, 2, 4);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(-3, 0, 0), dot4(-3, 2, 4);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(-3, 2, 4);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_8) {
  Vector3D dot1(0, 0, 0), dot2(1, 0, 0);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(0.5, -0.5, 0), dot4(0.5, 0.5, 0);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(0.5, 0, 0);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_9) {
  Vector3D dot1(0, 0, 0), dot2(3, 3, 3);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(1, 1, 1), dot4(4, 4, 4);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(1, 1, 1);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_10) {
  Vector3D dot1(1, 1, 1), dot2(4, 4, 4);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(1, 4, 1), dot4(4, 1, 4);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(2.5, 2.5, 2.5);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_11) {
  Vector3D dot1(0, 0, 0), dot2(0.4, 0.4, 0.4);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(0.6, 0, 0), dot4(0, 0.6, 0.6);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(0.3, 0.3, 0.3);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_12) {
  Vector3D dot1(1000, 2000, 3000), dot2(4000, 5000, 6000);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(4000, 2000, 3000), dot4(1000, 5000, 6000);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(2500, 3500, 4500);
  EXPECT_EQ(dot_intersection, ans);
}

TEST(Segments_intersect, Test_13) {
  Vector3D dot1(1000, 2000, 3000), dot2(4000, 5000, 6000);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(1000, 2000, 3000), dot4(4000, 5000, 6000);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(1000, 2000, 3000);  // отрезки полностью совпадают (в качестве
                                   // точки пересечения выбрано начало)
  EXPECT_EQ(dot_intersection, ans);
}

TEST(The_segments_do_not_intersect, Test_1) {
  Vector3D dot1(0, 0, 0), dot2(1, 1, 1);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(0, 1, 1), dot4(1, 2, 2);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, false);
}

TEST(The_segments_do_not_intersect, Test_2) {
  Vector3D dot1(0, 0, 0), dot2(1, 1, 1);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(2, 2, 2), dot4(3, 3, 3);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, false);
}

TEST(The_segments_do_not_intersect, Test_3) {
  Vector3D dot1(0, 0, 0), dot2(1, 0, 0);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(0, 1, 0), dot4(1, 1, 1);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, false);
}

TEST(The_segments_do_not_intersect, Test_4) {
  Vector3D dot1(0, 0, 0), dot2(1, 1, 1);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(0, 1, 1), dot4(1, 2, 2);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, false);
}

TEST(The_segments_do_not_intersect, Test_5) {
  Vector3D dot1(0, 0, 0), dot2(1, 1, 1);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(5, 5, 5), dot4(6, 6, 6);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, false);
}

// Точки пересечения находятся за пределами отрезков
TEST(The_segments_do_not_intersect, Test_6) {
  Vector3D dot1(0, 0, 0), dot2(0.4, 0.4, 0.4);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(1, 0, 0), dot4(0, 1, 1);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, false);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// Скрещивающиеся отрезки
TEST(The_segments_do_not_intersect, Test_7) {
  Vector3D dot1(0, 0, 0), dot2(1, 0, 0);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(0, 0, 1), dot4(0, 1, 1);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);

  EXPECT_EQ(result, false);
}

// Скрещивающиеся отрезки
TEST(The_segments_do_not_intersect, Test_8) {
  Vector3D dot1(10000, 0, 0), dot2(20000, 0, 0);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(15000, -10000, 10000), dot4(15000, 20000, 10000);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);

  EXPECT_EQ(result, false);
}

// Прямые пересекаются, но отрезки не пересекаются
// в пределах их длин.
TEST(The_segments_do_not_intersect, Test_10) {
  Vector3D dot1(100, 100, 100), dot2(150, 150, 150);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(150, 150, 50), dot4(250, 250, 0);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);

  EXPECT_EQ(result, false);
}

// Тест для проверки, что прямые, содержащие отрезки в тесте
// "The_segments_do_not_intersect", Test_10, пересекаются
TEST(Segments_intersect, Test_14) {
  Vector3D dot1(100, 100, 100), dot2(0, 0, 0);
  Segment3D seg1(dot1, dot2);

  Vector3D dot3(150, 150, 50), dot4(0, 0, 125);
  Segment3D seg2(dot3, dot4);

  Vector3D dot_intersection;
  bool result = seg1.Intersect(seg2, dot_intersection);
  EXPECT_EQ(result, true);
  Vector3D ans(83.33, 83.33, 83.33);

  EXPECT_EQ(std::round(dot_intersection.X * 100.0) / 100.0, ans.X);
  EXPECT_EQ(std::round(dot_intersection.Y * 100.0) / 100.0, ans.Y);
  EXPECT_EQ(std::round(dot_intersection.Y * 100.0) / 100.0, ans.Y);
}