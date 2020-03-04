#pragma once
#include<math.h>

// class vec3 a simple 3D vector class
template<class DType> class vec3 { // DType: Data Type 

public:
	// Public representation: Not many options here.
	DType x, y, z;
	bool isRowVector = 1;

	/* Constructors */

	// Default constructor
	vec3() :x(0), y(0), z(0) {}
	// Copy constructor
	vec3(const vec3& a) : x(a.x), y(a.y), z(a.z) {}
	// Construct given three values
	vec3(DType nx, DType ny, DType nz) : x(nx), y(ny), z(nz) {}

	// Standard object maintenance
	// return reference to the lvalue
	vec3& operator =(const vec3& a) {
		x = a.x; y = a.y; z = a.z;
		return *this;
	}

	/* Boolian Operations */

	bool operator ==(const vec3& a) const
	{
		return x == a.x && y == a.y && z == a.z;
	}
	bool operator !=(const vec3& a) const
	{
		return x != a.x || y != a.y || z != a.z;
	}

	/* Vector operations */

	// Set the vector to zero
	void zero() { x = y = z = 0.0f; }
	// Unary minus returns the negative of the vector
	vec3 operator -() const { return vec3(-x, -y, -z); }

	// Binary + and - add and subtract vectors
	vec3 operator +(const vec3& a) const {
		return vec3(x + a.x, y + a.y, z + a.z);
	}
	vec3 operator -(const vec3& a) const {
		return vec3(x - a.x, y - a.y, z - a.z);
	}
	// Multiplication and division by scalar
	vec3 operator *(DType a) const {
		return vec3(x * a, y * a, z * a);
	}
	vec3 operator /(DType a) const {
		DType oneOverA = 1.0f / a; // NOTE: no check for divide by zero here ADD TRY CATCH
		return vec3(x * oneOverA, y * oneOverA, z * oneOverA);
	}

	/* Assignment operations */

	vec3& operator +=(const vec3& a) {
		x += a.x; y += a.y; z += a.z;
		return *this;
	}
	vec3& operator -= (const vec3& a) {
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}
	vec3& operator *=(DType a) {
		x *= a; y *= a; z *= a;
		return *this;
	}
	vec3& operator /=(DType a) {
		DType oneOverA = 1.0f / a; // NOTE: no check for divide by zero here ADD TRY CATCH
		x *= oneOverA; y *= oneOverA; z *= oneOverA;
		return *this;
	}

	/* Normalize the vector */

	void normalize() {
		DType magSq = x * x + y * y + z * z;
		if (magSq > 0.0f) { // check for divide-by-zero
			DType oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag; y *= oneOverMag; z *= oneOverMag;
		}
	}

	/* Vector dot product */
	DType operator *(const vec3& a) const { // overload
		return x * a.x + y * a.y + z * a.z;
	}
};


/*
 * Nonmember functions
 */

 // Compute the magnitude of a vector vectorMag
template<class DType> DType norm(const vec3<DType>& a) {
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
// Compute the cross product of two vectors
template<class DType> vec3<DType> cross(const vec3<DType>& a, const vec3<DType>& b) {
	return vec3<DType>(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
		);
}
// Scalar on the left multiplication, for symmetry
template<class DType> vec3<DType> operator *(DType k, const vec3<DType>& v) {
	return vec3<DType>(k * v.x, k * v.y, k * v.z);
}
// Compute the distance between two points
template<class DType> vec3<DType> dist(const vec3<DType>& a, const vec3<DType>& b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

/*
 *Global variables
 */

 // We provide a global zero vector constant
template<class DType> const vec3<DType> kZeroVector;
