#include <Windows.h>
#include <d3d11.h>
#include <iostream>

typedef HRESULT(WINAPI* CreateDeviceAndSwapChain_t)(
    IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE                    Software,
    UINT                       Flags,
    const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT                       FeatureLevels,
    UINT                       SDKVersion,
    const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    IDXGISwapChain** ppSwapChain,
    ID3D11Device** ppDevice,
    D3D_FEATURE_LEVEL* pFeatureLevel,
    ID3D11DeviceContext** ppImmediateContext
    );

HRESULT D3D11CreateDeviceAndSwapChain_Hook(
    IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE                    Software,
    UINT                       Flags,
    const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT                       FeatureLevels,
    UINT                       SDKVersion,
    const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    IDXGISwapChain** ppSwapChain,
    ID3D11Device** ppDevice,
    D3D_FEATURE_LEVEL* pFeatureLevel,
    ID3D11DeviceContext** ppImmediateContext
) {
    HMODULE d3d11_lib = LoadLibraryA("C:\\Windows\\System32\\d3d11.dll");

    CreateDeviceAndSwapChain_t function = (CreateDeviceAndSwapChain_t)GetProcAddress(d3d11_lib, "D3D11CreateDeviceAndSwapChain");

    return function(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext);
}