

#ifndef MATHLIB__VECTOR3_H
#define MATHLIB__VECTOR3_H


namespace MathLib
{

#include <cmath>
#include <iostream>
#include <intrin.h>

class __declspec(dllexport) Vector3
{
public:

	Vector3(void)
	{}
	
	Vector3(float x, float y, float z) : x(x), y(y), z(z) 
	{}

	void set(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	/* Addition Operations */
	static Vector3 add(Vector3 left, const Vector3 &right)
	{
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;
		return left;
	}

	  Vector3 operator+ (Vector3 right) const
	{
		right.x += this->x;
		right.y += this->y;
		right.z += this->z;
		return right;
	}


	/* Accumulation Operations */

	void addTo(const Vector3 &vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
	}

	  Vector3& operator+= (const Vector3 &right)
	{
		this->x += right.x;
		this->y += right.y;
		this->z += right.z;
		return *this;
	}


	/*subtraction operations */
	  static Vector3 subtract(Vector3 left, const Vector3 &right)
	{
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;

		return left;
	}


	  Vector3 operator- (Vector3 right) const
	{
		//return Vector3(this->x - right.x, this->y - right.y, this->z - right.z);
		right.x = this->x - right.x;
		right.y = this->y - right.y;
		right.z = this->z - right.z;

		return right;
		
	}


	  void subtractFrom(const Vector3 &vector)
	{
		*this -= vector;
	}

	  Vector3& operator-= (const Vector3 &right)
	{
		this->x -= right.x;
		this->y -= right.y;
		this->z -= right.z;
		return *this;
	}



	static   Vector3 negate(const Vector3 &vector)
	{
		return Vector3(-vector.x, -vector.y, -vector.z);
	}

	  Vector3 operator-()
	{
		return Vector3(-this->x, -this->y, -this->z);
	}

	  void negate()
	{
		this->x = -this->x;
		this->y = -this->y;
		this->z = -this->z;
	}


	/* Vector Scaling */
	  static Vector3 scale(Vector3 vector, float scalar)
	{
		vector.x *= scalar;
		vector.y *= scalar;
		vector.z *= scalar;

		return vector;
	}


	  Vector3 operator* (float scalar)
	{
		return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
	}

	  friend Vector3 operator*(float scalar, Vector3 right)
	{
		return Vector3(scalar * right.x, scalar * right.y, scalar * right.z);
	}

	  void scale(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
	}

	  Vector3& operator*= (float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;

		return *this;
	}


	/*Dot Product */

	  static float dotProduct(const Vector3 &left, const Vector3 &right)
	{
		return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
	}

	  float dotProduct(const Vector3 &vector)
	{
		return (this->x * vector.x) + (this->y * vector.y) + (this->z + vector.z);
	}

	/*Cross Product*/


	  static Vector3 CrossPoduct(Vector3 left, const Vector3 &right)
	{
		left.x = (left.y * right.z) - (right.y * left.z);
		left.y = (left.z * right.x) - (left.x * right.z);
		left.z = (left.x * right.y) - (left.y * right.x);

		return left;
	}


	  static float magnitude(const Vector3 &vector)
	{
		return sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	}

	  float magnitude() const
	{
		return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
	}

	  static Vector3 normalize(Vector3 vector)
	{
		float magnitude =vector.magnitude();

		vector.x /= magnitude;
		vector.y /= magnitude;
		vector.z /= magnitude;

		return vector;
	}

	  void normalize()
	{
		float magnitude = this->magnitude();

		this->x /= magnitude;
		this->y /= magnitude;
		this->z /= magnitude;
	}


		float x,y,z;
};


}

#endif

