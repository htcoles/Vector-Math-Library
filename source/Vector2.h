


#ifndef MATHLIB__VECTOR2_H
#define MATHLIB__VECTOR2_H

#include <cmath>
#include <iostream>

#include "constants.h"



namespace MathLib
{

class __declspec(dllexport) Vector2
{
public:

	
	Vector2(void)
	{

	}

	Vector2(float x, float y) : x(x), y(y)
	{}

	void set(float x, float y)
	{
		this->x = x;
		this->y = y;
	}


	/* Addition Operations */

	 static Vector2 add(Vector2 left, const Vector2 &right)
	{
		left.x += right.x;
		left.y += right.y;
		return left;
	}


	 Vector2 operator +(Vector2 right) const
	{
		right.x += this->x;
		right.y += this->y;
		return right;
	}

	/* Accumulation Operations */

	  void addTo(const Vector2 &other)
	{
		this->x += other.x;
		this->y += other.y;
	}

	  Vector2& operator+=(const Vector2 &right)
	{
		this->x += right.x;
		this->y += right.y;

		return *this;
	}

	/*Subtraction Operations */

	  static Vector2 Subtract(Vector2 left, const Vector2 &right)
	{
		left.x -= right.x;
		left.y -= right.y;
		return left;
	}

	Vector2 operator-(Vector2 right) const
	{
		right.x = this->x - right.x;
		right.y = this->y - right.y;
		return right;
	}

	void subtract(const Vector2 &right)
	{
		this->x -= right.x;
		this->y -= right.y;
	}

	Vector2& operator-=(const Vector2 &right)
	{
		this->x -= right.x;
		this->y -= right.y;
		return *this;
	}


	/* Scaling */

	static Vector2 scale(Vector2 vector, float scalar)
	{
		vector.x *= scalar;
		vector.y *= scalar;
		return vector;
	}

	Vector2 operator*(float scalar) const
	{
		return Vector2(this->x * scalar, this->y * scalar);
	}

	void scale(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
	}


	Vector2& operator*=(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		return *this;
	}


	static float length(const Vector2 &vector)
	{
		return sqrt( (vector.x * vector.x) + (vector.y * vector.y) );
	}


	float length() const
	{
		return sqrt( this->lengthSquared() );
	}

	static float lengthSquared(const Vector2 &vector)
	{
		return (vector.x * vector.x) + (vector.y * vector.y);
	}

	float lengthSquared() const
	{
		return (this->x * this->x) + (this->y * this->y);
	}

	static void normalize(Vector2 &vector)
	{
		float magnitude = vector.length();
		vector.x /= magnitude;
		vector.y /= magnitude;
	}

	void normalize()
	{
		float magnitude = this->length();

		if(magnitude > MATHLIB_EPSILON)
		{
			this->x /= magnitude;
			this->y /= magnitude;
		}
	}



	static bool isNormal(const Vector2 &vector)
	{
		float mag = vector.lengthSquared();

		return ( (mag + MATHLIB_EPSILON + MATHLIB_EPSILON) < 1.0f) && ( (mag - MATHLIB_EPSILON - MATHLIB_EPSILON) > 1.0f) ;

	}

	bool isNormal() const
	{
		float mag = this->lengthSquared();

		return ( (mag + MATHLIB_EPSILON + MATHLIB_EPSILON) < 1.0f) && ( (mag - MATHLIB_EPSILON - MATHLIB_EPSILON) > 1.0f) ;
	}


	static float angle(const Vector2 &vector)
	{
		float angle = degreesToRadians(vector.y/vector.x);
		return radiansToDegrees(atan(angle));
	}


	float angle() const
	{
		float angle = degreesToRadians(this->y/this->x);
		return radiansToDegrees(atan(angle));

	}


	float x, y;
};

}

#endif