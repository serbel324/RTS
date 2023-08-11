#pragma once

#include <cstdlib>
#include <random>
#include <cmath>
#include <ctime>
#include <climits>

#include <library/vec2.h>

namespace ExtMath {

extern const long double PI;

double ToRadian(double a);

double ToDegrees(double a);

float WeightedAverage(float a1, float p1, float a2, float p2);

float Hypot(float a1, float a2);

float Hypot(float x1, float y1, float x2, float y2);

float Hypot(Vec2<float> p1, Vec2<float> p2);

double Sigmoid(float x, float a);

int Sign(double a);

double RandomDouble(double a, double b);

int RandomInt(int a, int b);

} // namespace ExtMath
