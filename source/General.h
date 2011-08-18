

#ifndef MATHLIB__GENERAL_H
#define MATHLIB__GENERAL_H

namespace MathLib
{
#include "MathLib.h"

__declspec(dllexport) MATHLIB_INLINE float lerp(float x, float y, float delta)
{
	return x + ((y - x) * delta);
}



}


#endif
