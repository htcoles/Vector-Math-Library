

#ifndef MATHLIB__VECTOR4_H
#define MATHLIB__VECTOR4_H


#include <cmath>
#include <iostream>


#include "constants.h"
#include "Vector3.h"

namespace MathLib
{

class __declspec(dllexport) Vector4
{
public:

	
	  Vector4() 
	{
		//std::cout << "New Vec4 Object Made\n";
	}
/*
	  Vector4(const Vector4 &copy)
	{
		std::cout << "New Vec4 Copy Made\n";
	}
	*/
	  Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
	{}

	  Vector4(const Vector3 &vector, float w)
	{
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
		this->w = w;
	}

	  void setValues(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}


	/*Addition operations */
	  static Vector4 add(Vector4 left, const Vector4 &right)
	{
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;
		left.w += right.w;

		return left;
	}


	  Vector4 operator+(Vector4 right)
	{
		right.x += this->x;
		right.y += this->y;
		right.z += this->z;
		right.w += this->w;
		return right;
	}



	/*Accumulation operations */
	  void addTo(const Vector4 &right)
	{
		*this += right;
	}

	  Vector4& operator+=(const Vector4 &right)
	{
		this->x += right.x;
		this->y += right.y;
		this->z += right.z;
		this->w += right.w;

		return *this;
	}


	/*Subtraction operations */
	  static Vector4 subtract(Vector4 left, const Vector4 &right)
	{
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;
		left.w -= right.w;

		return left;
	}


	  Vector4 operator-(Vector4 right)
	{
		right.x -= this->x;
		right.y -= this->y;
		right.z -= this->z;
		right.w -= this->w;
		return right;
	}



	  void subtractFrom(const Vector4 &right)
	{
		*this += right;
	}

	  Vector4& operator-=(const Vector4 &right)
	{
		this->x -= right.x;
		this->y -= right.y;
		this->z -= right.z;
		this->w -= right.w;

		return *this;
	}


	  static Vector4 negate(const Vector4 &vector)
	{
		return Vector4(-vector.x, -vector.y, -vector.z, -vector.w);
	}

	/* Negation operations */
	  void negate()
	{
		this->x = -this->x;
		this->y = -this->y;
		this->z = -this->z;
		this->w = -this->w;
	}

	  Vector4 operator-()
	{
		return Vector4(-this->x,-this->y,-this->z, -this->w);
	}

	/* Vector Scaling */
	  static Vector4 scale(Vector4 vector, float scalar)
	{
		vector.x *= scalar;
		vector.y *= scalar;
		vector.z *= scalar;


		return vector;
	}

	  Vector4 operator* (float scalar)
	{
		return Vector4(this->x * scalar, this->y * scalar, this->z * scalar,this->w);
	}

	  friend Vector4 operator*(float scalar, Vector4 right)
	{
		return Vector4(scalar * right.x, scalar * right.y, scalar * right.z,scalar * right.w);
	}

	  void scale(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
	}

	  Vector4& operator*= (float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;

		return *this;
	}


	/*Dot Product */

	  static float dotProduct(const Vector4 &left, const Vector4 &right)
	{
		return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
	}

	  float dotProduct(const Vector4 &vector)
	{
		return (this->x * vector.x) + (this->y * vector.y) + (this->z + vector.z);
	}

	/*Cross Product*/

	  static Vector4 CrossPoduct(Vector4 left, const Vector4 &right)
	{
		left.x = (left.y * right.z) - (right.y * left.z);
		left.y = (left.z * right.x) - (left.x * right.z);
		left.z = (left.x * right.y) - (left.y * right.x);
		left.w = 0;

		return left;
	}


	float x,y,z,w;



};



}


#endif