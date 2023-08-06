#pragma once

#include <cstdlib>
#include <random>
#include <cmath>
#include <ctime>
#include <climits>

#include <library/vec2.h>

namespace ExtMath {

constexpr long double PI = 3.14159265359;

double ToRadian(double a)
{
	return (a * PI / 180);
}

double ToDegrees(double a)
{
	return (a * 180 / PI);
}

float WeightedAverage(float a1, float p1, float a2, float p2)
{
	return (a1 * p1 + a2 * p2) / (p1 + p2);
}

float Hypot(float a1, float a2)
{
	return(sqrt(a1 * a1 + a2 * a2));
}

float Hypot(float x1, float y1, float x2, float y2)
{
	return(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

float Hypot(Vec2<float> p1, Vec2<float> p2) {
	return(sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}

double Sigmoid(float x, float a)
{
	return 1 / (1 + exp(-x * a));
}

int Sign(double a)
{
	if (a == 0)	return 0;
	if (a > 0) return 1;
	return -1;
}

} // namespace ExtMath
