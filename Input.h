#pragma once
#include <windows.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <wrl.h>

//����
class Input
{
public: //�����o�ϐ�

	//������
	void Initialize(HRESULT result, WNDCLASSEX w);

	//�X�V
	void Update(HRESULT result);

	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

private:
	IDirectInput8* directInput = nullptr;

	IDirectInputDevice8* keyboard = nullptr;

	//�S�L�[�̓��͏�Ԃ��擾����
	BYTE key[256] = {};

	//�O��̑S�L�[�̓��͏�Ԃ��擾����
	BYTE keyPre[256] = {};

};
