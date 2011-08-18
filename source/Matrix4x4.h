


#ifndef MATHLIB__MATRIX4X4_H
#define MATHLIB__MATRIX4X4_H

#include "constants.h"

#include "Vector4.h"
#include <cstring>
#include <cmath>
namespace MathLib
{
class __declspec(dllexport) Matrix4x4
{
public:

	/* Constructors */
	Matrix4x4()
	{}

	Matrix4x4(float *data)
	{
		this->_11 = data[0];
		this->_12 = data[1];
		this->_13 = data[2];
		this->_14 = data[3];

		this->_21 = data[4];
		this->_22 = data[5];
		this->_23 = data[6];
		this->_24 = data[7];

		this->_31 = data[8];
		this->_32 = data[9];
		this->_33 = data[10];
		this->_34 = data[11];

		this->_41 = data[12];
		this->_42 = data[13];
		this->_43 = data[14];
		this->_44 = data[15];
	}


	  Matrix4x4(float _11,float _12, float _13, float _14,
			  float _21,float _22, float _23, float _24,
			  float _31,float _32, float _33, float _34,
			  float _41,float _42, float _43, float _44) :

			 _11(_11), _12(_12), _13(_13), _14(_14),
			 _21(_21), _22(_22), _23(_23), _24(_24),
			 _31(_31), _32(_32), _33(_33), _34(_34),
			 _41(_41), _42(_42), _43(_43), _44(_44)
	{
	}


	void setData(float _11,float _12, float _13, float _14,
			  float _21,float _22, float _23, float _24,
			  float _31,float _32, float _33, float _34,
			  float _41,float _42, float _43, float _44)
	{
		this->_11 = _11;
		this->_12 = _12;
		this->_13 = _13;
		this->_14 = _14;

		this->_21 = _21;
		this->_22 = _22;
		this->_23 = _23;
		this->_24 = _24;

		this->_31 = _31;
		this->_32 = _32;
		this->_33 = _33;
		this->_34 = _34;

		this->_41 = _41;
		this->_42 = _42;
		this->_43 = _43;
		this->_44 = _44;

	}


	// Identity and Zero Matrix operations

	static Matrix4x4 getIdentityMatrix()
	{
		return Matrix4x4(1,0,0,0,
						 0,1,0,0,
						 0,0,1,0,
						 0,0,0,1);


	}

	void setIdentityMatrix()
	{
		this->_11 = this->_22 = this->_33 = this->_44 = 1.0f;
		this->_12 = this->_13 = this->_14 = 0;
		this->_21 = this->_23 = this->_24 = 0;
		this->_31 = this->_32 = this->_34 = 0;
		this->_41 = this->_42 = this->_43 = 0;

	}


	Matrix4x4 getZeroMatrix()
	{
		return Matrix4x4(0,0,0,0,
						 0,0,0,0,
						 0,0,0,0,
						 0,0,0,0);
	}


	void setZeroMatrix()
	{
		this->_11 = this->_12 = this->_13 = this->_14 = 0;
		this->_21 = this->_22 = this->_23 = this->_24 = 0;
		this->_31 = this->_32 = this->_33 = this->_34 = 0;
		this->_41 = this->_42 = this->_43 = this->_44 = 0;
	}


	/* Addition */
	  static Matrix4x4 add(Matrix4x4 left, const Matrix4x4 &right);
	  Matrix4x4 operator+(const Matrix4x4 &right);
	  Matrix4x4& operator+=(const Matrix4x4 &right);


	/* subtraction */

	  static Matrix4x4 subtract(Matrix4x4 left, const Matrix4x4 &right);
	  Matrix4x4 operator-(const Matrix4x4 &right);
	  Matrix4x4& operator-=(const Matrix4x4 &right);

	/*multiplication */

	  static Matrix4x4 multiply(const Matrix4x4 &left, const Matrix4x4 &right);
	  Matrix4x4 operator*(const Matrix4x4 &right);
	  Matrix4x4& operator*=(const Matrix4x4 &right);
	


	/* scaling */

	void multiply(float scalar)
	{

		this->_11 *= scalar;
		this->_12 *= scalar;
		this->_13 *= scalar;
		this->_14 *= scalar;

		this->_21 *= scalar;
		this->_22 *= scalar;
		this->_23 *= scalar;
		this->_24 *= scalar;

		this->_31 *= scalar;
		this->_32 *= scalar;
		this->_33 *= scalar;
		this->_34 *= scalar;

		this->_41 *= scalar;
		this->_42 *= scalar;
		this->_43 *= scalar;
		this->_44 *= scalar;

	}

	static Matrix4x4 multiply(const Matrix4x4 &matrix, float scalar)
	{
		return Matrix4x4(matrix._11 * scalar, matrix._12 * scalar, matrix._13 * scalar, matrix._14 * scalar,
			      matrix._21 * scalar, matrix._22 * scalar, matrix._23 * scalar, matrix._24 * scalar,
				  matrix._31 * scalar, matrix._32 * scalar, matrix._33 * scalar, matrix._34 * scalar,
				  matrix._41 * scalar, matrix._42 * scalar, matrix._43 * scalar, matrix._44 * scalar);

	}

    friend Matrix4x4 operator*(float scalar, const Matrix4x4 &matrix)
	{
		return Matrix4x4(matrix._11 * scalar, matrix._12 * scalar, matrix._13 * scalar, matrix._14 * scalar,
			      matrix._21 * scalar, matrix._22 * scalar, matrix._23 * scalar, matrix._24 * scalar,
				  matrix._31 * scalar, matrix._32 * scalar, matrix._33 * scalar, matrix._34 * scalar,
				  matrix._41 * scalar, matrix._42 * scalar, matrix._43 * scalar, matrix._44 * scalar);
	}
	

	/*Tansformations*/

	static Vector4 transform(const Matrix4x4 &matrix,Vector4 vector)
	{
		Vector4 returnValue;
		returnValue.x = vector.x * matrix._11 + vector.y * matrix._21 + vector.z * matrix._31 + vector.w * matrix._41;
		returnValue.y = vector.x * matrix._12 + vector.y * matrix._22 + vector.z * matrix._32 + vector.w * matrix._42;
		returnValue.z = vector.x * matrix._13 + vector.y * matrix._23 + vector.z * matrix._33 + vector.w * matrix._43;
		returnValue.w = vector.x * matrix._14 + vector.y * matrix._24 + vector.z * matrix._34 + vector.w * matrix._44;

		return returnValue;
	}
		
		
		
	  Vector4 operator*(Vector4 vector)
	{
		Vector4 returnValue;
		returnValue.x = vector.x * this->_11 + vector.y * this->_21 + vector.z * this->_31 + vector.w * this->_41;
		returnValue.y = vector.x * this->_12 + vector.y * this->_22 + vector.z * this->_32 + vector.w * this->_42;
		returnValue.z = vector.x * this->_13 + vector.y * this->_23 + vector.z * this->_33 + vector.w * this->_43;
		returnValue.w = vector.x *this->_14 + vector.y * this->_24 + vector.z * this->_34 + vector.w * this->_44;

		return returnValue;


	}

	  friend Vector4 operator*(Vector4 vector, const Matrix4x4 &matrix)
	{
		Vector4 returnValue;
		returnValue.x = vector.x * matrix._11 + vector.y * matrix._21 + vector.z * matrix._31 + vector.w * matrix._41;
		returnValue.y = vector.x * matrix._12 + vector.y * matrix._22 + vector.z * matrix._32 + vector.w * matrix._42;
		returnValue.z = vector.x * matrix._13 + vector.y * matrix._23 + vector.z * matrix._33 + vector.w * matrix._43;
		returnValue.w = vector.x * matrix._14 + vector.y * matrix._24 + vector.z * matrix._34 + vector.w * matrix._44;

		return returnValue;


	}

	/* Scaling matrices */

	  static Matrix4x4 getScaleMatrix(float xScale, float yScale, float zScale)
	{
		return Matrix4x4(xScale,0,0,0,
						 0, yScale, 0,0,
						0,0, zScale, 0,
						0,0,0,1);
	}

	  void toScaleMatrix(float xScale, float yScale, float zScale)
	{
		this->setData(xScale,0,0,0,
						 0, yScale, 0,0,
						0,0, zScale, 0,
						0,0,0,1);
	}


	/*transformation matrices*/

	  static Matrix4x4 getTanslationMatrix(float xCoord, float yCoord, float zCoord)
	{
		return Matrix4x4(1,0,0,0,
						 0,1,0,0,
						 0,0,1,0,
						 xCoord,yCoord,zCoord,1);
	}

	  void toTranslationMatrix(float xCoord, float yCoord, float zCoord)
	{
			this->setData(1,0,0,0,
						  0,1,0,0,
						  0,0,1,0,
						  xCoord,yCoord,zCoord,1);
	}

	/*rotation matrices*/


	/* X */

	  static Matrix4x4 getXRotationMatrix(float theta)
	{
		float cosTheta = radiansToDegrees(cos(degreesToRadians(theta)));
		float sinTheta = radiansToDegrees(sin(degreesToRadians(theta)));
		return Matrix4x4(1,0,0,0,
						 0, cosTheta,-sinTheta,0,
						 0,sinTheta,cosTheta,0,
						 0,0,0,1);
	}

	  void toXRotationMatrix(float theta)
	{
		float cosTheta = radiansToDegrees(cos(degreesToRadians(theta)));
		float sinTheta = radiansToDegrees(sin(degreesToRadians(theta)));
		this->setData(1,0,0,0,
						 0, cosTheta,-sinTheta,0,
						 0,sinTheta,cosTheta,0,
						 0,0,0,1);
	}

	/* Y */

	  static Matrix4x4 getYRotationMatrix(float theta)
	{
		float cosTheta = radiansToDegrees(cos(degreesToRadians(theta)));
		float sinTheta = radiansToDegrees(sin(degreesToRadians(theta)));
		return Matrix4x4(cosTheta,0,0,sinTheta,
						 0, 1,-sinTheta,0,
						 -sinTheta,0,cosTheta,0,
						 0,0,0,1);
	}
	  void toYRotationMatrix(float theta)
	{
		float cosTheta = radiansToDegrees(cos(degreesToRadians(theta)));
		float sinTheta = radiansToDegrees(sin(degreesToRadians(theta)));
		this->setData(cosTheta,0,0,sinTheta,
						 0, 1,-sinTheta,0,
						 -sinTheta,0,cosTheta,0,
						 0,0,0,1);

	}


	/* Z */

	  static Matrix4x4 getZRotationMatrix(float theta)
	{
		float cosTheta = radiansToDegrees(cos(degreesToRadians(theta)));
		float sinTheta = radiansToDegrees(sin(degreesToRadians(theta)));
		return Matrix4x4(cosTheta,-sinTheta,0,0,
						 sinTheta, cosTheta,0,0,
						 0,0,1,0,
						 0,0,0,1);
	}

	  void toZRotationMatrix(float theta)
	{
		float cosTheta = radiansToDegrees(cos(degreesToRadians(theta)));
		float sinTheta = radiansToDegrees(sin(degreesToRadians(theta)));
		this->setData(cosTheta,-sinTheta,0,0,
						 sinTheta, cosTheta,0,0,
						 0,0,1,0,
						 0,0,0,1);
	}


	/* transpose */


	static Matrix4x4 transpose(const Matrix4x4 &matrix)
	{
		return Matrix4x4(matrix._11, matrix._21, matrix._31, matrix._41,
			             matrix._12, matrix._22, matrix._32, matrix._42,
						 matrix._13, matrix._23, matrix._33, matrix._43,
						 matrix._14, matrix._24, matrix._34, matrix._44);

	}


	void transpose()
	{
		this->setData(this->_11, this->_21, this->_31, this->_41,
			          this->_12, this->_22, this->_32, this->_42,
					  this->_13, this->_23, this->_33, this->_43,
					  this->_14, this->_24, this->_34, this->_44);
	}

	/* determinant */

	//static float determinant(const Matrix4x4 &matrix);
	
	float determinant()
	{
		float x1 = this->_11 * this->determinant3x3(_22,_23,_44,
												    _32,_33,_34,
													_42,_43,_44);

		float x2 = this->_21 * this->determinant3x3(_12,_13,_14,
												    _32,_33,_34,
													_42,_43,_44);

		float x3 = this->_31 * this->determinant3x3(_12,_13,_14,
												    _22,_23,_24,
													_42,_43,_44);


		float x4 = this->_41 * this->determinant3x3(_12,_13,_14,
												    _22,_23,_24,
													_32,_33,_34);

		return x1 -x2 + x3 - x4;
	}

	/*inverse */


	void invert()
	{
		float determinant = this->determinant();

		//set this matrix as the cofactor matrix

		//first row

		float t11 = this->_11 * this->determinant3x3(this->_22,this->_23,this->_24,
													 this->_32,this->_33,this->_34,
													 this->_42,this->_43,this->_44);

		float t12 = -this->_12 * this->determinant3x3(this->_21,this->_23,this->_24,
													 this->_31,this->_33,this->_34,
													 this->_41,this->_43,this->_44);


		float t13 = this->_13 * this->determinant3x3(this->_21,this->_22,this->_24,
													 this->_31,this->_32,this->_34,
													 this->_41,this->_42,this->_44);



		float t14 = -this->_14 * this->determinant3x3(this->_21,this->_22,this->_23,
													 this->_31,this->_32,this->_33,
													 this->_41,this->_42,this->_43);


		//row 2

		float t21 = -this->_21 * this->determinant3x3(this->_12,this->_13,this->_14,
													 this->_32,this->_33,this->_34,
													 this->_42,this->_43,this->_44);

		float t22 = this->_22 * this->determinant3x3(this->_11,this->_13,this->_14,
													 this->_31,this->_33,this->_34,
													 this->_41,this->_43,this->_44);


		float t23 = -this->_23 * this->determinant3x3(this->_11,this->_12,this->_24,
													 this->_31,this->_32,this->_34,
													 this->_41,this->_42,this->_44);



		float t24 = this->_24 * this->determinant3x3(this->_11,this->_12,this->_13,
													 this->_31,this->_32,this->_33,
													 this->_41,this->_42,this->_43);



		//row 3

		float t31 = this->_31 * this->determinant3x3(this->_12,this->_13,this->_14,
													 this->_22,this->_23,this->_24,
													 this->_42,this->_43,this->_44);

		float t32 = -this->_32 * this->determinant3x3(this->_12,this->_13,this->_14,
													 this->_22,this->_23,this->_24,
													 this->_42,this->_43,this->_44);


		float t33 = this->_33 * this->determinant3x3(this->_11,this->_12,this->_24,
													 this->_21,this->_22,this->_34,
													 this->_41,this->_42,this->_44);



		float t34 = -this->_34 * this->determinant3x3(this->_11,this->_12,this->_13,
													 this->_21,this->_22,this->_23,
													 this->_41,this->_42,this->_43);


		//row 4

		float t41 = -this->_41 * this->determinant3x3(this->_12,this->_13,this->_14,
													 this->_22,this->_23,this->_24,
													 this->_32,this->_33,this->_34);

		float t42 = this->_42 * this->determinant3x3(this->_11,this->_13,this->_14,
													 this->_21,this->_23,this->_24,
													 this->_31,this->_33,this->_34);


		float t43 = -this->_43 * this->determinant3x3(this->_11,this->_12,this->_24,
													 this->_21,this->_22,this->_24,
													 this->_31,this->_32,this->_34);



		float t44 = this->_44 * this->determinant3x3(this->_11,this->_12,this->_13,
													 this->_21,this->_22,this->_23,
													 this->_31,this->_32,this->_33);


		

		//transpose to make this matrix the adjoint
		this->setData(t11,t21,t31,t41,
			          t12,t22,t32,t42,
					  t13,t23,t33,t43,
					  t14,t24,t34,t44);


		//divide by determinant to get inverse
		float factor = 1.0f/determinant;
		this->multiply(factor);

		//this matrix has now been inverted

	}
	


	


	/* Projection Matrices */


	  static Matrix4x4 getPerspectiveProjectionMatrix()
	{
		return Matrix4x4();


	}

	  void setPerspectiveProjectionMatrix()
	{



	}


	  static Matrix4x4 getOrthogonalProjectionMatrix()
	{
		return Matrix4x4();


	}

	  void setOrthogonalProjectionMatrix()
	{



	}


	/* View */

	  static Matrix4x4 getViewMatrix(const Vector3 &position, const Vector3 &look, const Vector3 &up)
	{
		Vector3 right = Vector3::CrossPoduct(look, up);
		return Matrix4x4(right.x,right.y,right.z,0,
							 up.x, up.y, up.z, 0,
							 look.x, look.y, look.z, 0,
							 position.x, position.y, position.z, 1);


	}

	  void setViewMatrix(const Vector3 &position, const Vector3 &look, const Vector3 &up)
	{
		Vector3 right = Vector3::CrossPoduct(look, up);
		this->setData(right.x,right.y,right.z,0,
							 up.x, up.y, up.z, 0,
							 look.x, look.y, look.z, 0,
							 position.x, position.y, position.z, 1);
	}



	//Vector4 row1, row2, row3, row4;
	float _11,_12,_13,_14;
	float _21,_22,_23,_24;
	float _31,_32,_33,_34;
	float _41,_42,_43,_44;


	float determinant2x2(float _11, float _12, float _21, float _22)
	{
		return (_11 * _22) - (_12 * _21);
	}


	float determinant3x3(float _11, float _12, float _13,
						 float _21, float _22, float _23,
						 float _31, float _32, float _33)
	{
		float x1 = _11 * this->determinant2x2(_22,_23,_32,_33);
		float x2 = _21 * this->determinant2x2(_12,_13,_32,_33);
		float x3 = _31 * this->determinant2x2(_12,_33,_22,_23);

		return x1 - x2 + x3;

	}


};


}




#endif