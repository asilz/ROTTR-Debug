#include <Windows.h>
#include <d3d11.h>
#include <D3D11.hpp>
#include <iostream>
#include "Gui.h"
#include "imgui.h"

#pragma comment(linker, "/export:D3D11CoreRegisterLayers=C:\\Windows\\System32\\d3d11.D3D11CoreRegisterLayers")
#pragma comment(linker, "/export:D3D11CoreGetLayeredDeviceSize=C:\\Windows\\System32\\d3d11.D3D11CoreGetLayeredDeviceSize")
#pragma comment(linker, "/export:D3D11CoreCreateLayeredDevice=C:\\Windows\\System32\\d3d11.D3D11CoreCreateLayeredDevice")
#pragma comment(linker, "/export:EnableFeatureLevelUpgrade=C:\\Windows\\System32\\d3d11.EnableFeatureLevelUpgrade")
#pragma comment(linker, "/export:D3D11CoreCreateDevice=C:\\Windows\\System32\\d3d11.D3D11CoreCreateDevice")
#pragma comment(linker, "/export:D3D11CreateDevice=C:\\Windows\\System32\\d3d11.D3D11CreateDevice")
#pragma comment(linker, "/export:D3D11CreateDeviceAndSwapChain=D3D11CreateDeviceAndSwapChain")
#pragma comment(linker, "/export:D3DKMTCloseAdapter=C:\\Windows\\System32\\d3d11.D3DKMTCloseAdapter")
#pragma comment(linker, "/export:D3DKMTDestroyAllocation=C:\\Windows\\System32\\d3d11.D3DKMTDestroyAllocation")
#pragma comment(linker, "/export:D3DKMTDestroyContext=C:\\Windows\\System32\\d3d11.D3DKMTDestroyContext")
#pragma comment(linker, "/export:D3DKMTDestroyDevice=C:\\Windows\\System32\\d3d11.D3DKMTDestroyDevice")
#pragma comment(linker, "/export:D3DKMTDestroySynchronizationObject=C:\\Windows\\System32\\d3d11.D3DKMTDestroySynchronizationObject")
#pragma comment(linker, "/export:D3DKMTPresent=C:\\Windows\\System32\\d3d11.D3DKMTPresent")
#pragma comment(linker, "/export:D3DKMTRender=C:\\Windows\\System32\\d3d11.D3DKMTRender")
#pragma comment(linker, "/export:D3DKMTSetDisplayPrivateDriverFormat=C:\\Windows\\System32\\d3d11.D3DKMTSetDisplayPrivateDriverFormat")
#pragma comment(linker, "/export:D3DKMTSignalSynchronizationObject=C:\\Windows\\System32\\d3d11.D3DKMTSignalSynchronizationObject")
#pragma comment(linker, "/export:D3DKMTUnlock=C:\\Windows\\System32\\d3d11.D3DKMTUnlock")
#pragma comment(linker, "/export:D3DKMTWaitForSynchronizationObject=C:\\Windows\\System32\\d3d11.D3DKMTWaitForSynchronizationObject")
#pragma comment(linker, "/export:D3DKMTSetAllocationPriority=C:\\Windows\\System32\\d3d11.D3DKMTSetAllocationPriority")
#pragma comment(linker, "/export:D3DKMTSetContextSchedulingPriority=C:\\Windows\\System32\\d3d11.D3DKMTSetContextSchedulingPriority")
#pragma comment(linker, "/export:D3DKMTSetDisplayMode=C:\\Windows\\System32\\d3d11.D3DKMTSetDisplayMode")
#pragma comment(linker, "/export:D3DKMTSetGammaRamp=C:\\Windows\\System32\\d3d11.D3DKMTSetGammaRamp")
#pragma comment(linker, "/export:D3DKMTSetVidPnSourceOwner=C:\\Windows\\System32\\d3d11.D3DKMTSetVidPnSourceOwner")
#pragma comment(linker, "/export:D3DKMTWaitForVerticalBlankEvent=C:\\Windows\\System32\\d3d11.D3DKMTWaitForVerticalBlankEvent")
#pragma comment(linker, "/export:D3DKMTCreateAllocation=C:\\Windows\\System32\\d3d11.D3DKMTCreateAllocation")
#pragma comment(linker, "/export:D3DKMTCreateContext=C:\\Windows\\System32\\d3d11.D3DKMTCreateContext")
#pragma comment(linker, "/export:D3DKMTCreateDevice=C:\\Windows\\System32\\d3d11.D3DKMTCreateDevice")
#pragma comment(linker, "/export:D3DKMTCreateSynchronizationObject=C:\\Windows\\System32\\d3d11.D3DKMTCreateSynchronizationObject")
#pragma comment(linker, "/export:D3DKMTGetContextSchedulingPriority=C:\\Windows\\System32\\d3d11.D3DKMTGetContextSchedulingPriority")
#pragma comment(linker, "/export:D3DKMTGetDisplayModeList=C:\\Windows\\System32\\d3d11.D3DKMTGetDisplayModeList")
#pragma comment(linker, "/export:D3DKMTGetMultisampleMethodList=C:\\Windows\\System32\\d3d11.D3DKMTGetMultisampleMethodList")
#pragma comment(linker, "/export:D3DKMTGetRuntimeData=C:\\Windows\\System32\\d3d11.D3DKMTGetRuntimeData")
#pragma comment(linker, "/export:D3DKMTGetSharedPrimaryHandle=C:\\Windows\\System32\\d3d11.D3DKMTGetSharedPrimaryHandle")
#pragma comment(linker, "/export:D3DKMTLock=C:\\Windows\\System32\\d3d11.D3DKMTLock")
#pragma comment(linker, "/export:D3DKMTQueryAllocationResidency=C:\\Windows\\System32\\d3d11.D3DKMTQueryAllocationResidency")
#pragma comment(linker, "/export:D3D11CreateDeviceForD3D12=C:\\Windows\\System32\\d3d11.D3D11CreateDeviceForD3D12")
#pragma comment(linker, "/export:D3D11On12CreateDevice=C:\\Windows\\System32\\d3d11.D3D11On12CreateDevice")
#pragma comment(linker, "/export:D3DPerformance_BeginEvent=C:\\Windows\\System32\\d3d11.D3DPerformance_BeginEvent")
#pragma comment(linker, "/export:D3DPerformance_EndEvent=C:\\Windows\\System32\\d3d11.D3DPerformance_EndEvent")
#pragma comment(linker, "/export:D3DPerformance_GetStatus=C:\\Windows\\System32\\d3d11.D3DPerformance_GetStatus")
#pragma comment(linker, "/export:D3DPerformance_SetMarker=C:\\Windows\\System32\\d3d11.D3DPerformance_SetMarker")
#pragma comment(linker, "/export:D3DKMTQueryAdapterInfo=C:\\Windows\\System32\\d3d11.D3DKMTQueryAdapterInfo")
#pragma comment(linker, "/export:OpenAdapter10=C:\\Windows\\System32\\d3d11.OpenAdapter10")
#pragma comment(linker, "/export:OpenAdapter10_2=C:\\Windows\\System32\\d3d11.OpenAdapter10_2")
#pragma comment(linker, "/export:D3DKMTEscape=C:\\Windows\\System32\\d3d11.D3DKMTEscape")
#pragma comment(linker, "/export:D3DKMTGetDeviceState=C:\\Windows\\System32\\d3d11.D3DKMTGetDeviceState")
#pragma comment(linker, "/export:D3DKMTOpenAdapterFromHdc=C:\\Windows\\System32\\d3d11.D3DKMTOpenAdapterFromHdc")
#pragma comment(linker, "/export:D3DKMTOpenResource=C:\\Windows\\System32\\d3d11.D3DKMTOpenResource")
#pragma comment(linker, "/export:D3DKMTQueryResourceInfo=C:\\Windows\\System32\\d3d11.D3DKMTQueryResourceInfo")
#pragma comment(linker, "/export:CreateDirect3D11DeviceFromDXGIDevice=C:\\Windows\\System32\\d3d11.CreateDirect3D11DeviceFromDXGIDevice")
#pragma comment(linker, "/export:CreateDirect3D11SurfaceFromDXGISurface=C:\\Windows\\System32\\d3d11.CreateDirect3D11SurfaceFromDXGISurface")

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

HRESULT WINAPI D3D11CreateDeviceAndSwapChain(
    _In_opt_ IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    _In_reads_opt_(FeatureLevels) CONST D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    UINT SDKVersion,
    _In_opt_ CONST DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    _COM_Outptr_opt_ IDXGISwapChain** ppSwapChain,
    _COM_Outptr_opt_ ID3D11Device** ppDevice,
    _Out_opt_ D3D_FEATURE_LEVEL* pFeatureLevel,
    _COM_Outptr_opt_ ID3D11DeviceContext** ppImmediateContext)
{
    HRESULT result =  D3D11CreateDeviceAndSwapChain_Hook(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext);
    
 
    void** vtable = *(void ***)(*ppSwapChain);

    oPresent = (tPresent)vtable[8];

    DWORD old_protection;
    VirtualProtect(&vtable[8], 8, PAGE_READWRITE, &old_protection);
    vtable[8] = (void *)hkPresent;
    VirtualProtect(&vtable[8], 8, old_protection, &old_protection);

    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    (*ppSwapChain)->GetDesc(&swapChainDesc);

    GUI::Init(*ppDevice, *ppSwapChain, *ppImmediateContext, swapChainDesc.OutputWindow);


    

    return result;
}

