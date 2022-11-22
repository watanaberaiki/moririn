#pragma once
#include<Windows.h>

class WindowsApp {
public:

	//�E�B���h�E�T�C�Y
	static const int window_width = 1280;	//����
	static const int window_height = 720;	//�c��

	//�T�u�E�B���h�E�T�C�Y
	static const int subWindow_width = 640;	 //����
	static const int subWindow_height = 720; //�c��

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};

	//���b�Z�[�W
	MSG msg{};

	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	HWND hwnd;

	HWND hwndSub;

	void createWin();

	void createSubWin();
};
