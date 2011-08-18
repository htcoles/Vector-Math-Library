


#ifndef MATHLIB__CONSTANTS_H
#define MATHLIB__CONSTANTS_H


#define MATHLIB_INLINE __forceinline

namespace MathLib
{

const float MATHLIB_EPSILON = 0.05f;

const float MATHLIB_PI = 3.14159265358979323846264338327950288f;
const float MATHLIB_2PI = 2.0f * MATHLIB_PI;

__declspec(dllexport) inline float degreesToRadians(float angleInDegrees)
{
	return (MATHLIB_2PI * angleInDegrees)/180.0f;
}


__declspec(dllexport) inline float radiansToDegrees(float angleInRadians)
{
	return (180.0f * angleInRadians) / MATHLIB_2PI;
}


}

#endif

