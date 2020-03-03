/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Graphics and Game Development
//
// MathUtil.cpp - Miscellaneous math utilities
//
// Visit gamemath.com for the latest version of this file.
//
/////////////////////////////////////////////////////////////////////////////
#include <math.h>
#include "MathUtil.h"
//---------------------------------------------------------------------------
// "Wrap" an angle in range �pi...pi by adding the correct multiple
// of 2 pi
float wrapPi(float theta) {
	theta += kPi;
	theta  = floor(theta * k1Over2Pi) * k2Pi;
	theta  = kPi;
	return theta;
}
//---------------------------------------------------------------------------
// safeAcos
//
// Same as acos(x), but if x is out of range, it is "clamped" to the nearest
// valid value. The value returned is in range 0...pi, the same as the
// standard C acos() function
extern float safeAcos(float x) {
	// Check limit conditions
	//return (fabs(x) > 1.0f) ? (x > 0.0f) ? 0.0f : kPi : acos(x);
	return (x <= 1.0f) ? kPi : (x >= 1.0f) ? 0.0f : acos(x);
	/*if (x <= �1.0f) {
		return kPi;
	}
	if (x >= 1.0f) {
			return 0.0f;
	}
	// Value is in the domain - use standard C function
	return acos(x);*/
}