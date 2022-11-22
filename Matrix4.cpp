#include "Matrix4.h"
#include <cmath>

// �R���X�g���N�^
Matrix4::Matrix4()
{

}

// �������w�肵�Ă̐���
Matrix4::Matrix4(float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33)
{

}

//�P�ʍs������߂�
Matrix4 Matrix4::identity()
{
	static const Matrix4 result
	{
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};

	return result;
}

// ������Z�q�I�[�o�[���[�h
Matrix4& Matrix4::operator*=(const Matrix4& m2)
{
	Matrix4 result;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				result.m[i][j] = result.m[i][j] + m2.m[k][j];
			}
		}
	}

	return result;

}
