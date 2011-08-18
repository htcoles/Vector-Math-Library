

#ifndef MATHLIB__BOUNDINGSPHERE_H
#define MATHLIB__BOUNDINGSPHERE_H


#pragma once

#include "MathLib.h"

namespace MathLib
{

struct __declspec(dllexport) BoundingSphere
{

	Vector3 position;
	float radius;

};


}


#endif