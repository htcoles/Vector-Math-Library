


#include "Matrix4x4.h"



namespace MathLib
{


	/*Addition */

	Matrix4x4 Matrix4x4::add(Matrix4x4 left, const Matrix4x4 &right)
	{

		/* First Row */
		left._11 += right._11;
		left._12 += right._12;
		left._13 += right._13;
		left._14 += right._14;

		
		/* Second Row */
		left._21 += right._21;
		left._22 += right._22;
		left._23 += right._23;
		left._24 += right._24;

		/* Third Row */
		left._31 += right._31;
		left._32 += right._32;
		left._33 += right._33;
		left._34 += right._34;

		/* Fourth Row */
		left._41 += right._41;
		left._42 += right._42;
		left._43 += right._43;
		left._44 += right._44;

		return left;
	}


	Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &right)
	{

		Matrix4x4 returnValue;

		returnValue._11 = this->_11 + right._11;
		returnValue._12 = this->_12 + right._12;
		returnValue._13 = this->_13 + right._13;
		returnValue._14 = this->_14 + right._14;

		returnValue._21 = this->_21 + right._21;
		returnValue._22 = this->_22 + right._22;
		returnValue._23 = this->_23 + right._23;
		returnValue._24 = this->_24 + right._24;

		returnValue._31 = this->_31 + right._31;
		returnValue._32 = this->_32 + right._32;
		returnValue._33 = this->_33 + right._33;
		returnValue._34 = this->_34 + right._34;

		returnValue._41 = this->_41 + right._41;
		returnValue._42 = this->_42 + right._42;
		returnValue._43 = this->_43 + right._43;
		returnValue._44 = this->_44 + right._44;

		return returnValue;

	}


	Matrix4x4& Matrix4x4::operator+=(const Matrix4x4 &right)
	{

		this->_11 += right._11;
		this->_12 += right._12;
		this->_13 += right._13;
		this->_14 += right._14;

		this->_21 += right._21;
		this->_22 += right._22;
		this->_23 += right._23;
		this->_24 += right._24;


		this->_31 += right._31;
		this->_32 += right._32;
		this->_33 += right._33;
		this->_34 += right._34;

		this->_41 += right._41;
		this->_42 += right._42;
		this->_43 += right._43;
		this->_44 += right._44;

		return *this;
	}


		/*subtraction */

	Matrix4x4 Matrix4x4::subtract(Matrix4x4 left, const Matrix4x4 &right)
	{

		/* First Row */
		left._11 -= right._11;
		left._12 -= right._12;
		left._13 -= right._13;
		left._14 -= right._14;

		
		/* Second Row */
		left._21 -= right._21;
		left._22 -= right._22;
		left._23 -= right._23;
		left._24 -= right._24;

		/* Third Row */
		left._31 -= right._31;
		left._32 -= right._32;
		left._33 -= right._33;
		left._34 -= right._34;

		/* Fourth Row */
		left._41 -= right._41;
		left._42 -= right._42;
		left._43 -= right._43;
		left._44 -= right._44;

		return left;
	}


	Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &right)
	{

		Matrix4x4 returnValue;

		returnValue._11 = this->_11 - right._11;
		returnValue._12 = this->_12 - right._12;
		returnValue._13 = this->_13 - right._13;
		returnValue._14 = this->_14 - right._14;

		returnValue._21 = this->_21 - right._21;
		returnValue._22 = this->_22 - right._22;
		returnValue._23 = this->_23 - right._23;
		returnValue._24 = this->_24 - right._24;

		returnValue._31 = this->_31 - right._31;
		returnValue._32 = this->_32 - right._32;
		returnValue._33 = this->_33 - right._33;
		returnValue._34 = this->_34 - right._34;

		returnValue._41 = this->_41 - right._41;
		returnValue._42 = this->_42 - right._42;
		returnValue._43 = this->_43 - right._43;
		returnValue._44 = this->_44 - right._44;

		return returnValue;

	}

	Matrix4x4& Matrix4x4::operator-=(const Matrix4x4 &right)
	{

		this->_11 -= right._11;
		this->_12 -= right._12;
		this->_13 -= right._13;
		this->_14 -= right._14;

		this->_21 -= right._21;
		this->_22 -= right._22;
		this->_23 -= right._23;
		this->_24 -= right._24;


		this->_31 -= right._31;
		this->_32 -= right._32;
		this->_33 -= right._33;
		this->_34 -= right._34;

		this->_41 -= right._41;
		this->_42 -= right._42;
		this->_43 -= right._43;
		this->_44 -= right._44;

		return *this;
	}




	Matrix4x4 Matrix4x4::multiply(const Matrix4x4 &left, const Matrix4x4 &right)
	{


		Matrix4x4 returnValue;
		
		returnValue._11 = (left._11 * right._11) + (left._12 * right._21) + (left._13 * right._31) + (left._14 * right._41); 
		returnValue._12 = (left._11 * right._12) + (left._12 * right._22) + (left._13 * right._32) + (left._14 * right._42);
		returnValue._13 = (left._11 * right._13) + (left._12 * right._23) + (left._13 * right._33) + (left._14 * right._43);
		returnValue._14 = (left._11 * right._14) + (left._12 * right._24) + (left._13 * right._34) + (left._14 * right._44);
		
		returnValue._21 = (left._21 * right._11) + (left._22 * right._21) + (left._23 * right._31) + (left._24 * right._41); 
		returnValue._22 = (left._21 * right._12) + (left._22 * right._22) + (left._23 * right._32) + (left._24 * right._42);
		returnValue._23 = (left._21 * right._13) + (left._22 * right._23) + (left._23 * right._33) + (left._24 * right._43);
		returnValue._24 = (left._21 * right._14) + (left._22 * right._24) + (left._23 * right._34) + (left._24 * right._44);
		
		returnValue._31 = (left._31 * right._11) + (left._32 * right._21) + (left._33 * right._31) + (left._34 * right._41); 
		returnValue._32 = (left._31 * right._12) + (left._32 * right._22) + (left._33 * right._32) + (left._34 * right._42);
		returnValue._33 = (left._31 * right._13) + (left._32 * right._23) + (left._33 * right._33) + (left._34 * right._43);
		returnValue._34 = (left._31 * right._14) + (left._32 * right._24) + (left._33 * right._34) + (left._34 * right._44);
		
		returnValue._21 = (left._41 * right._11) + (left._42 * right._21) + (left._43 * right._31) + (left._44 * right._41); 
		returnValue._22 = (left._41 * right._12) + (left._42 * right._22) + (left._43 * right._32) + (left._44 * right._42);
		returnValue._23 = (left._41 * right._13) + (left._42 * right._23) + (left._43 * right._33) + (left._44 * right._43);
		returnValue._24 = (left._41 * right._14) + (left._42 * right._24) + (left._43 * right._34) + (left._44 * right._44);
		
		return returnValue;
	} 


	Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &right)
	{
		Matrix4x4 returnValue;

		returnValue._11 = this->_11 * right._11;
		returnValue._12 = this->_12 * right._12;
		returnValue._13 = this->_13 * right._13;
		returnValue._14 = this->_14 * right._14;

		returnValue._21 = this->_21 * right._21;
		returnValue._22 = this->_22 * right._22;
		returnValue._23 = this->_23 * right._23;
		returnValue._24 = this->_24 * right._24;

		returnValue._31 = this->_31 * right._31;
		returnValue._32 = this->_32 * right._32;
		returnValue._33 = this->_33 * right._33;
		returnValue._34 = this->_34 * right._34;

		returnValue._41 = this->_41 * right._41;
		returnValue._42 = this->_42 * right._42;
		returnValue._43 = this->_43 * right._43;
		returnValue._44 = this->_44 * right._44;

		return returnValue;


	}


/*
	Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &right)
	{
		
		this->_11 *= right._11;
		this->_12 *= right._12;
		this->_13 *= right._13;
		this->_14 *= right._14;

		this->_21 *= right._21;
		this->_22 *= right._22;
		this->_23 *= right._23;
		this->_24 *= right._24;


		this->_31 *= right._31;
		this->_32 *= right._32;
		this->_33 *= right._33;
		this->_34 *= right._34;

		this->_41 *= right._41;
		this->_42 *= right._42;
		this->_43 *= right._43;
		this->_44 *= right._44;

		return *this;
	}*/


	


	




}