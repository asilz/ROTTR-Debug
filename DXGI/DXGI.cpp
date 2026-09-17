#include <d3d11.h>
#include "Gui.h"
#include "imgui.h"

#pragma comment(linker, "/export:ApplyCompatResolutionQuirking=C:\\Windows\\System32\\dxgi.ApplyCompatResolutionQuirking")
#pragma comment(linker, "/export:CompatString=C:\\Windows\\System32\\dxgi.CompatString")
#pragma comment(linker, "/export:CompatValue=C:\\Windows\\System32\\dxgi.CompatValue")
#pragma comment(linker, "/export:CreateDXGIFactory=CreateDXGIFactory")
#pragma comment(linker, "/export:CreateDXGIFactory1=CreateDXGIFactory1")
#pragma comment(linker, "/export:CreateDXGIFactory2=C:\\Windows\\System32\\dxgi.CreateDXGIFactory2")
#pragma comment(linker, "/export:DXGID3D10CreateDevice=C:\\Windows\\System32\\dxgi.DXGID3D10CreateDevice")
#pragma comment(linker, "/export:DXGID3D10CreateLayeredDevice=C:\\Windows\\System32\\dxgi.DXGID3D10CreateLayeredDevice")
#pragma comment(linker, "/export:DXGID3D10GetLayeredDeviceSize=C:\\Windows\\System32\\dxgi.DXGID3D10GetLayeredDeviceSize")
#pragma comment(linker, "/export:DXGID3D10RegisterLayers=C:\\Windows\\System32\\dxgi.DXGID3D10RegisterLayers")
#pragma comment(linker, "/export:DXGIDeclareAdapterRemovalSupport=C:\\Windows\\System32\\dxgi.DXGIDeclareAdapterRemovalSupport")
#pragma comment(linker, "/export:DXGIDumpJournal=C:\\Windows\\System32\\dxgi.DXGIDumpJournal")
#pragma comment(linker, "/export:DXGIGetDebugInterface1=C:\\Windows\\System32\\dxgi.DXGIGetDebugInterface1")
#pragma comment(linker, "/export:DXGIReportAdapterConfiguration=C:\\Windows\\System32\\dxgi.DXGIReportAdapterConfiguration")
#pragma comment(linker, "/export:PIXBeginCapture=C:\\Windows\\System32\\dxgi.PIXBeginCapture")
#pragma comment(linker, "/export:PIXEndCapture=C:\\Windows\\System32\\dxgi.PIXEndCapture")
#pragma comment(linker, "/export:SetAppCompatStringPointer=C:\\Windows\\System32\\dxgi.SetAppCompatStringPointer")
#pragma comment(linker, "/export:UpdateHMDEmulationStatus=C:\\Windows\\System32\\dxgi.UpdateHMDEmulationStatus")

typedef HRESULT(WINAPI* CreateDXGIFactory_t)(REFIID riid, _COM_Outptr_ void** ppFactory);
typedef HRESULT(__fastcall* CreateSwapChain_t)(IDXGIFactory* pThis,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain
    );

static CreateSwapChain_t oCreateSwapChain = nullptr;
static CreateSwapChain_t oCreateSwapChain1 = nullptr;

typedef HRESULT(__fastcall* tPresent)(IDXGISwapChain* pThis, UINT SyncInterval, UINT Flags);
static tPresent oPresent;

HRESULT __fastcall hkPresent(IDXGISwapChain* pThis, UINT SyncInterval, UINT Flags) // 000002DC26616710
{
    GUI::StartFrame();
    ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
    ImGui::Begin("Asil's Debug Menu");
    ImGui::Text("Hello, Lara Croft!");
    ImGui::End();
    GUI::EndFrame();
    return oPresent(pThis, SyncInterval, Flags);;
}

static HRESULT CreateSwapChain(IDXGIFactory* pThis,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain
) {
    HRESULT result = oCreateSwapChain(pThis, pDevice, pDesc, ppSwapChain);

    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    (*ppSwapChain)->GetDesc(&swapChainDesc);

    ID3D11Device* device;
    (*ppSwapChain)->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void **>(&device));

    ID3D11DeviceContext* context;
    device->GetImmediateContext(&context);

    void** vtable = *(void***)(*ppSwapChain);

    oPresent = (tPresent)vtable[8];

    DWORD old_protection;
    VirtualProtect(&vtable[8], 8, PAGE_READWRITE, &old_protection);
    vtable[8] = (void*)hkPresent;
    VirtualProtect(&vtable[8], 8, old_protection, &old_protection);

    GUI::Init(device, *ppSwapChain, context, swapChainDesc.OutputWindow);
    
    return result;
}

static HRESULT CreateSwapChain1(IDXGIFactory* pThis,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain
) {
    return oCreateSwapChain1(pThis, pDevice, pDesc, ppSwapChain);
}

HRESULT WINAPI CreateDXGIFactory(REFIID riid, _COM_Outptr_ void** ppFactory) {
    HMODULE dxgi_lib = LoadLibraryA("C:\\Windows\\System32\\dxgi.dll");
    CreateDXGIFactory_t function = (CreateDXGIFactory_t)GetProcAddress(dxgi_lib, "CreateDXGIFactory");
    HRESULT result = function(riid, ppFactory);
    IDXGIFactory** factory = reinterpret_cast<IDXGIFactory **>(ppFactory);

    void** vtable = *(void***)(*factory);

    if (oCreateSwapChain == nullptr) {
        oCreateSwapChain = (CreateSwapChain_t)vtable[10];
    }

    DWORD old_protection;
    VirtualProtect(&vtable[10], 8, PAGE_READWRITE, &old_protection);
    vtable[10] = (void*)CreateSwapChain;
    VirtualProtect(&vtable[10], 8, old_protection, &old_protection);

    return function(riid, ppFactory);
   
}
HRESULT WINAPI CreateDXGIFactory1(REFIID riid, _COM_Outptr_ void** ppFactory) {
    HMODULE dxgi_lib = LoadLibraryA("C:\\Windows\\System32\\dxgi.dll");
    CreateDXGIFactory_t function = (CreateDXGIFactory_t)GetProcAddress(dxgi_lib, "CreateDXGIFactory1");
    HRESULT result = function(riid, ppFactory);
    IDXGIFactory1** factory = reinterpret_cast<IDXGIFactory1**>(ppFactory);

    void** vtable = *(void***)(*factory);

    if (oCreateSwapChain1 == nullptr) {
        oCreateSwapChain1 = (CreateSwapChain_t)vtable[10];
    }

    DWORD old_protection;
    VirtualProtect(&vtable[10], 8, PAGE_READWRITE, &old_protection);
    vtable[10] = (void*)CreateSwapChain1;
    VirtualProtect(&vtable[10], 8, old_protection, &old_protection);

    return function(riid, ppFactory);
}
