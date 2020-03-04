#pragma once
#include <math.h>
// Declare a global constant for pi and a few multiples.
const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;
// "Wrap" an angle in range –pi...pi by adding the correct multiple
// of 2 pi
extern float wrapPi(float theta);
// "Safe" inverse trig functions
extern float safeAcos(float x);
// Compute the sin and cosine of an angle. On some platforms, if we know
// that we need both values, it can be computed faster than computing
// the two values seperately.
inline void sinCos(float* returnSin, float* returnCos, float theta) {
	// For simplicity, we'll just use the normal trig functions.
	// Note that on some platforms we may be able to do better
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}
