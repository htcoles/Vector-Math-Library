

#ifndef MATHLIB__FRUSTUM_H
#define MATHLIB__FRUSTUM_H


#pragma once

#include "MathLib.h"
#include <cmath>

namespace MathLib
{

struct __declspec(dllexport) Frustum
{

	void set(Vector3 position, Vector3 lookAt, Vector3 up, float nearDistance, float farDistance, float fov, float aspectRatio)
	{
		//determine size of front and back 
		float temp = 2 * tan(fov/2.0f);

		float nearHeight = temp * nearDistance;
		float nearWidth = nearDistance * aspectRatio;

		float farHeight = temp * farDistance;
		float farWidth = farDistance * aspectRatio;

		//determine 3 points on each plane
		Vector3 rtl, rtr, fbl, fbr; //, ftl, ftr;
		Vector3 frontCenter, rearCenter;

		Vector3 lookVector = lookAt - position;
		lookVector.normalize();
		Vector3 rightVector = Vector3::CrossPoduct(lookVector,up);

		frontCenter = position + (lookVector * nearDistance);
		rearCenter = position + (lookVector * farDistance);

		rtl = rearCenter + (up * (farHeight/2.0f)) - (rightVector * (farWidth/2.0f));
		rtr = rearCenter + (up * (farHeight/2.0f)) + (rightVector * (farWidth/2.0f));

		fbl = rearCenter - (up * (nearHeight/2.0f)) - (rightVector * (nearWidth/2.0f));
		fbr = rearCenter + (up * (nearHeight/2.0f)) + (rightVector * (nearWidth/2.0f));

		//front and back planes
		this->frontPlane.set(frontCenter, fbl,fbr);
		this->rearPlane.set(rtl,rtr,rearCenter);

		//top and bottom planes
		this->topPlane.set(position, rtr,rtl);
		this->bottomPlane.set(position, fbl,fbr);

		//left and right
		this->leftPlane.set(position,rtl,fbl);
		this->rightPlane.set(position,rtr,fbr);



		
	}


	bool isInside(Vector3 point)
	{
		if( (this->bottomPlane.distanceFrom(point) >= 0) &&
			(this->topPlane.distanceFrom(point) >= 0) &&
			(this->leftPlane.distanceFrom(point) >= 0) &&
			(this->rightPlane.distanceFrom(point) >= 0) &&
			(this->frontPlane.distanceFrom(point) >= 0) &&
			(this->rearPlane.distanceFrom(point) >= 0))
			return true;

		return false;

	}

	bool checkCollision(BoundingSphere sphere)
	{
		if( (this->bottomPlane.distanceFrom(sphere.position) <= sphere.radius) &&
			(this->topPlane.distanceFrom(sphere.position) <= sphere.radius) &&
			(this->leftPlane.distanceFrom(sphere.position) <= sphere.radius) &&
			(this->rightPlane.distanceFrom(sphere.position) <= sphere.radius) &&
			(this->frontPlane.distanceFrom(sphere.position) <= sphere.radius) &&
			(this->rearPlane.distanceFrom(sphere.position) <= sphere.radius))
			return true;

		return false;

	}


	Plane frontPlane, rearPlane, leftPlane, rightPlane, topPlane, bottomPlane;


};



}


#endif