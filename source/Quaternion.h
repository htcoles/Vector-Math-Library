

#ifndef MATHLIB__QUATERNION_H
#define MATHLIB__QUATERNION_H

namespace MathLib
{

#include "MathLib.h"

class Matrix4x4;

class __declspec(dllexport) Quaternion
{

	Quaternion()
	{}

	Quaternion(Matrix4x4 matrix)
	{}

	Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
	{}


	void setData(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}



	Matrix4x4 toMatrix()
	{
		float xx = this->x * this->x,
			  yy = this->y * this->y,
			  zz = this->z * this->z,
			  xy = this->x * this->y,
			  xz = this->x * this->z,
			  xw = this->x * this->w,
			  yz = this->y * this->z,
			  yw = this->y * this->w,
			  zw = this->z * this->w;

		return Matrix4x4(1.0f - (2.0f *(yy + zz)),2.0f * (xy + zw), 2.0f * (xz - yw), 0,
			             2.0f * (xy - zw), 1.0f - (2.0f *(xx + zz)), 2.0f * (yz + xw), 0,
						 2.0f * (xz + yw),2.0f * (yz - xw), 1.0f - (2.0f * ( xx + yy)), 0,
						 0,0,0,1);
			  
	}


	static Quaternion getConjugate(Quaternion q)
	{
		q.x = -q.x;
		q.y = -q.y;
		q.z = -q.z;
		q.w = -q.w;

		return q;
	}


	void conjugate()
	{
		this->x = -this->x;
		this->y = -this->y;
		this->z = -this->z;
	}


	//static Quaternion normalize(Quaternion q)
	//{
		
	//}

	void normalize()
	{


	}


	float x,y,z,w;

};



}

#endif




