struct ID3D11Device;
struct IDXGISwapChain;
struct ID3D11DeviceContext;

namespace GUI {
	int Init(IDXGISwapChain* swapchain);
	bool StartFrame(void);
	void EndFrame(void);
	void Destroy(void);
};