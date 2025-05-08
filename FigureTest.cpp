#include "gtest/gtest.h"
#include "../Kszta³tyLib/Figure.h"

class FigureTest : public ::testing::Test {
protected:
    Rectangle v1{ 2, 3 };
    Triangle v2{ 3, 5, 4 };
    Circle v3{ 7 };
};

TEST_F(FigureTest, RectangleArea) {
	EXPECT_DOUBLE_EQ(v1.area(), 6);
}

TEST_F(FigureTest, RectanglePerimeter) {
	EXPECT_DOUBLE_EQ(v1.perimeter(), 10);
}

TEST_F(FigureTest, TriangleArea) {
	EXPECT_DOUBLE_EQ(v2.area(), 6);
}

TEST_F(FigureTest, TrianglePerimeter) {
	EXPECT_DOUBLE_EQ(v2.perimeter(), 12);
}

TEST_F(FigureTest, CircleArea) {
	EXPECT_DOUBLE_EQ(v3.area(), 153.86);
}

TEST_F(FigureTest, CirclePerimeter) {
	EXPECT_DOUBLE_EQ(v3.perimeter(), 43.96);
}

TEST_F(FigureTest, CircleEquality) {
	Circle c2{ 7 };
	EXPECT_TRUE(v3 == c2);
}

TEST_F(FigureTest, CircleInequality) {
	Circle c2{ 8 };
	EXPECT_FALSE(v3 == c2);
}

TEST_F(FigureTest, TriangleEquality) {
	Triangle t2{ 3, 4, 5 };
	EXPECT_TRUE(v2 == t2);
}

TEST_F(FigureTest, TriangleInequality) {
	Triangle t2{ 3, 4, 6 };
	EXPECT_FALSE(v2 == t2);
}

TEST_F(FigureTest, RectangleEquality) {
	Rectangle r2{ 3, 2 };
	EXPECT_TRUE(v1 == r2);
}

TEST_F(FigureTest, RectangleInequality) {
	Rectangle r2{ 3, 3 };
	EXPECT_FALSE(v1 == r2);
}

TEST_F(FigureTest, InvalidRectangle) {
	EXPECT_THROW(Rectangle(-1, 2), std::invalid_argument);
	EXPECT_THROW(Rectangle(1, -2), std::invalid_argument);
	EXPECT_THROW(Rectangle(0, 2), std::invalid_argument);
	EXPECT_THROW(Rectangle(1, 0), std::invalid_argument);
}

TEST_F(FigureTest, InvalidCircle) {
	EXPECT_THROW(Circle(-1), std::invalid_argument);
	EXPECT_THROW(Circle(0), std::invalid_argument);
}

TEST_F(FigureTest, InvalidTriangle) {
	EXPECT_THROW(Triangle(1, 2, 3), std::invalid_argument);
}

TEST_F(FigureTest, FigureEquality) {
	EXPECT_TRUE(v1 == v2);
	EXPECT_FALSE(v1 == v3);
}


