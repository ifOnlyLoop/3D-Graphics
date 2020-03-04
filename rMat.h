#pragma once
#include"EulerAngles.h"
#include"vec3.h"
//---------------------------------------------------------------------------
// class RotationMatrix
//
// matrix is assumed to be orthogonal. The direction of transformation
// is specified at the time of transformation.
template<class DType> class rMat {
public:
	DType m11, m12, m13,
		m21, m22, m23,
		m31, m32, m33;
	
	/* Public operations */
	
	// Set to identity
	void identity();
	
	// Setup the matrix with a specified orientation
	void rMat<DType>::setup(const EulerAngles<DType>& orientation) {
		// Fetch sine and cosine of angles
		float sh, ch, sp, cp, sb, cb;
		sinCos(&sh, &ch, orientation.heading);
		sinCos(&sp, &cp, orientation.pitch);
		sinCos(&sb, &cb, orientation.bank);
		// Fill in the matrix elements
		m11 = ch * cb + sh * sp * sb;
		m12 = -ch * sb + sh * sp * cb;
		m13 = sh * cp;
		m21 = sb * cp;
		m22 = cb * cp;
		m23 = -sp;
		m31 = -sh * cb + ch * sp * sb;
		m32 = sb * sh + ch * sp * cb;
		m33 = ch * cp;
	}
	
	// Perform vector/point rotations
	// rMat::inertialToObject
//
// Rotate a vector from inertial to object space
	vec3<DType> rMat<DType>::inertialToObject(const vec3<DType>& v) const {
		// Perform the matrix multiplication in the "standard" way.
		return vec3<DType>(
			m11 * v.x + m21 * v.y + m31 * v.z,
			m12 * v.x + m22 * v.y + m32 * v.z,
			m13 * v.x + m23 * v.y + m33 * v.z
			);
	}
	//---------------------------------------------------------------------------
	// rMat::objectToInertial
	//
	// Rotate a vector from object to inertial space
	vec3<DType> rMat<DType>::objectToInertial(const vec3<DType>& v) const {
		// Multiply by the transpose
		return vec3<DType>(
			m11 * v.x + m12 * v.y + m13 * v.z,
			m21 * v.x + m22 * v.y + m23 * v.z,
			m31 * v.x + m32 * v.y + m33 * v.z
			);
	}
};
