#include "WindowsApp.h"

//�E�B���h�E�v���V�[�W��
LRESULT WindowsApp::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//���b�Z�[�W�ɉ����ăQ�[���ŗL�̏������s��
	switch (msg)
	{
		//�E�B���h�E���j�󂳂ꂽ
	case WM_DESTROY:

		//os�ɑ΂��āA�A�v���̏I����`����
		PostQuitMessage(0);
		return 0;
	}

	//�W���̃��b�Z�[�W�������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

//Widows�A�v���ł̃G���g���[�|�C���g(main�֐�)
void WindowsApp::createWin()
{
	//�E�B���h�E�N���X�̐ݒ�
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowsApp::WindowProc; //�E�B���h�E�v���V�[�W����ݒ�
	w.lpszClassName = L"DirectXGame";	//�E�B���h�E�N���X��
	w.hInstance = GetModuleHandle(nullptr);//�E�B���h�E�n���h��
	w.hCursor = LoadCursor(NULL, IDC_ARROW);//�J�[�\���w��

	//�E�B���h�E�N���X��os�ɓo�^����
	RegisterClassEx(&w);

	//�E�B���h�E�T�C�Y{x���W,y���W,����,�c��}
	RECT wrc = { 0,0,window_width,window_height };

	//�����ŃT�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//�E�B���h�E�I�u�W�F�N�g�̐���
	hwnd = CreateWindow(w.lpszClassName,//�N���X��
		L"DirectXGame",//�^�C�g���o�[�̕���
		WS_OVERLAPPEDWINDOW,//�W���I�ȃE�B���h�E�X�^�C��
		CW_USEDEFAULT,//�\��x���W(os�ɔC����)
		CW_USEDEFAULT,//�\��y���W(os�ɔC����)
		wrc.right - wrc.left,//�E�B���h�E����
		wrc.bottom - wrc.top,//�E�B���h�E�c��
		nullptr,//�e�E�B���h�E�n���h��
		nullptr,//���j���[�n���h��
		w.hInstance,//�Ăяo���A�v���P�[�V�����n���h��
		nullptr);//�I�v�V����

	//�E�B���h�E��\����Ԃɂ���
	ShowWindow(hwnd, SW_SHOW);
}

void WindowsApp::createSubWin()
{
	//�E�B���h�E�N���X�̐ݒ�
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowsApp::WindowProc; //�E�B���h�E�v���V�[�W����ݒ�
	w.lpszClassName = L"DirectXGame";	//�E�B���h�E�N���X��
	w.hInstance = GetModuleHandle(nullptr);//�E�B���h�E�n���h��
	w.hCursor = LoadCursor(NULL, IDC_ARROW);//�J�[�\���w��

	//�E�B���h�E�N���X��os�ɓo�^����
	RegisterClassEx(&w);

	//�E�B���h�E�T�C�Y{x���W,y���W,����,�c��}
	RECT wrc = { 0,0,subWindow_width,subWindow_height };

	//�����ŃT�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//�E�B���h�E�I�u�W�F�N�g�̐���
	hwndSub = CreateWindow(w.lpszClassName,//�N���X��
		L"DirectXGame",//�^�C�g���o�[�̕���
		WS_OVERLAPPEDWINDOW,//�W���I�ȃE�B���h�E�X�^�C��
		CW_USEDEFAULT,//�\��x���W(os�ɔC����)
		CW_USEDEFAULT,//�\��y���W(os�ɔC����)
		wrc.right - wrc.left,//�E�B���h�E����
		wrc.bottom - wrc.top,//�E�B���h�E�c��
		nullptr,//�e�E�B���h�E�n���h��
		nullptr,//���j���[�n���h��
		w.hInstance,//�Ăяo���A�v���P�[�V�����n���h��
		nullptr);//�I�v�V����

	//�E�B���h�E��\����Ԃɂ���
	ShowWindow(hwndSub, SW_SHOW);
}