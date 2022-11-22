#pragma once
#include <windows.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <wrl.h>

//入力
class Input
{
public: //メンバ変数

	//初期化
	void Initialize(HRESULT result, WNDCLASSEX w);

	//更新
	void Update(HRESULT result);

	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

private:
	IDirectInput8* directInput = nullptr;

	IDirectInputDevice8* keyboard = nullptr;

	//全キーの入力状態を取得する
	BYTE key[256] = {};

	//前回の全キーの入力状態を取得する
	BYTE keyPre[256] = {};

};
