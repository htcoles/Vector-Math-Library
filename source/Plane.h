

#ifndef MATHLIB__PLANE_H
#define MATHLIB__PLANE_H


#pragma once


#include "MathLib.h"
namespace MathLib
{

struct __declspec(dllexport) Plane
{


	void set(const Vector3 &p0, const Vector3 &p1, const Vector3 &p2)
	{
		Vector3 v0 = p1 - p0;
		Vector3 v1 = p2 - p0;

		this->normalVector = Vector3::CrossPoduct(v0,v1);
		this->normalVector.normalize();

		Vector3 negativeNormal = Vector3::negate(this->normalVector);

		this->d = (negativeNormal).dotProduct(p0);

	}

	float distanceFrom(Vector3 point)
	{
		return point.dotProduct(this->normalVector) + this->d;
	}

	Vector3 normalVector;
	float d;

};

}


#endif