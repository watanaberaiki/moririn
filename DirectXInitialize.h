#pragma once
#include<d3d12.h>
#include<dxgi1_6.h>
#include<cassert>
#include<vector>
#include<string>
#include <wrl.h>
#include "WindowsApp.h"

#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib,"d3d12.lib")

using namespace std;
using namespace Microsoft::WRL;

class DirectXInitialize
{
public:
	HRESULT result;
	/*ID3D12Device* device = nullptr;
	IDXGIFactory7* dxgiFactory = nullptr;
	IDXGISwapChain4* swapChain = nullptr;
	ID3D12CommandAllocator* commandAllocator = nullptr;
	ID3D12GraphicsCommandList* commandList = nullptr;
	ID3D12CommandQueue* commandQueue = nullptr;
	ID3D12DescriptorHeap* rtvHeap = nullptr;*/

	ComPtr <ID3D12Device> device;
	ComPtr <IDXGIFactory6> dxgiFactory;
	ComPtr <IDXGISwapChain4> swapChain;
	ComPtr <ID3D12CommandAllocator> commandAllocator;
	ComPtr <ID3D12GraphicsCommandList> commandList;
	ComPtr <ID3D12CommandQueue> commandQueue;
	ComPtr <ID3D12DescriptorHeap> rtvHeap;

	//コマンドキューの設定
	D3D12_COMMAND_QUEUE_DESC commandQueueDesc{};

	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};

	// レンダーターゲットビューの設定
	D3D12_RENDER_TARGET_VIEW_DESC rtvDesc{};

	// バックバッファ
	std::vector<ID3D12Resource*> backBuffers;

	// フェンスの生成
	ID3D12Fence* fence = nullptr;
	UINT64 fenceVal = 0;

	void createDX(HWND hwnd);

};