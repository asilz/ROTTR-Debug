struct ID3D11Device;
struct IDXGISwapChain;
struct ID3D11DeviceContext;

namespace GUI {
	int Init(ID3D11Device* device, IDXGISwapChain* swapchain, ID3D11DeviceContext* ctx, HWND hwnd);
	bool StartFrame(void);
	void EndFrame(void);
	void Destroy(void);
};