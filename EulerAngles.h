#pragma once
#include"MathUtil.h"
#include"rMat.h"

//---------------------------------------------------------------------------
// class EulerAngles
//
// This class represents a heading-pitch-bank Euler angle triple.
template<class DType> class EulerAngles {
public:
	// Public data
	// Straightforward representation. Store the three angles, in
	// radians
	DType heading;
	DType pitch;
	DType bank;
	// Public operations
	// Default constructor does nothing
	EulerAngles() {}
	// Construct from three values
	EulerAngles(DType h, DType p, DType b) :
		heading(h), pitch(p), bank(b) {}
	// Set to identity triple (all zeros)
	void identity() { pitch = bank = heading = 0.0f; }
	
	
	// Determine "canonical" Euler angle triple
	void EulerAngles::canonize() {
		// First, wrap pitch in range -pi ... pi
		pitch = wrapPi(pitch);
		// Now, check for "the back side" of the matrix pitch outside
		// the canonical range of -pi/2 ... pi/2
		/*if (abs(pitch) > kPiOver2)
		{
			pitch=pitch>0?
		}*/
		if (pitch < -kPiOver2) {
			pitch = -kPi - pitch;
			heading += kPi;
			bank += kPi;
		}
		else if (pitch > kPiOver2) {
			pitch = kPi - pitch;
			heading += kPi;
			bank += kPi;
		}
		// Now check for the gimbel lock case (within a slight tolerance)
		if (fabs(pitch) > kPiOver2 - 1e-4) {
			// We are in gimbel lock. Assign all rotation
			// about the vertical axis to heading
			heading += bank;
			bank = 0.0f;
		}
		else {
			// Not in gimbel lock. Wrap the bank angle in
			// canonical range
			bank = wrapPi(bank);
		}
		// Wrap heading in canonical range
		heading = wrapPi(heading);
	}
	
	
	
	// Convert a rotation matrix to Euler Angle form.
	void fromRotationMatrix(const rMat<DType>& m) {
		// Extract sin(pitch) from m23.
		DType sp = -m.m23;
		// Check for Gimbel lock
		if (fabs(sp) > 0.9999f) {
			// Looking straight up or down
			pitch = kPiOver2 * sp;
			// Compute heading, slam bank to zero
			heading = atan2(-m.m31, m.m11);
			bank = 0.0f;
		}
		else {
			// Compute angles. We don't have to use the "safe" asin
			// function because we already checked for range errors when
			// checking for Gimbel lock
			heading = atan2(m.m13, m.m33);
			pitch = asin(sp);
			bank = atan2(m.m21, m.m22);
		}
	}
};
// A global "identity" Euler angle constant
template<class DType> const EulerAngles<DType> kEulerAnglesIdentity;
