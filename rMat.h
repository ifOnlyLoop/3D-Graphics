#ifndef __ROTATIONMATRIX_H_INCLUDED__
#define __ROTATIONMATRIX_H_INCLUDED__
//class vec3;
class EulerAngles;
class Quaternion;
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
	void setup(const EulerAngles& orientation);
	
	// Setup the matrix from a quaternion, assuming the quaternion 
	// performs the rotation in the specified direction of transformation
	void fromInertialToObjectQuaternion(const Quaternion& q);
	void fromObjectToInertialQuaternion(const Quaternion& q);
	
	// Perform vector/point rotations
	vec3<DType> inertialToObject(const vec3<DType>& v) const;
	vec3<DType> objectToInertial(const vec3<DType>& v) const;
};
#endif // #ifndef __ROTATIONMATRIX_H_INCLUDED__