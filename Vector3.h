#pragma once

/// <summary>
/// 3�����x�N�g��
/// </summary>
class Vector3 {
public:
	float x; // x����
	float y; // y����
	float z; // z����

public:

	// �R���X�g���N�^
	Vector3();                          // ��x�N�g���Ƃ���
	Vector3(float x, float y, float z); // x����, y����, z���� ���w�肵�Ă̐���

	// �P�����Z�q�I�[�o�[���[�h
	Vector3 operator+() const;
	Vector3 operator-() const;

	// ������Z�q�I�[�o�[���[�h
	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator*=(float s);
	Vector3& operator/=(float s);
};

// 2�����Z�q�I�[�o�[���[�h
//  �������Ȉ����̃p�^�[���ɑΉ�(�����̏���)���邽��,�ȉ��̂悤�ɏ������Ă���
const Vector3 operator+(const Vector3& v1, const Vector3& v2);
const Vector3 operator-(const Vector3& v1, const Vector3& v2);
const Vector3 operator*(const Vector3& v, float s);
const Vector3 operator*(float s, const Vector3& v);
const Vector3 operator/(const Vector3& v, float s);