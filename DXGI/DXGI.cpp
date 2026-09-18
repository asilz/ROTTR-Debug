#include <d3d11.h>
#include "Gui.h"
#include "imgui.h"
#include "Types.h"

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

static const uintptr_t DebugDrawPersistentGetInstance_offset = 0x553b20;
static const uintptr_t AddCube_offset = 0xc8aa50;
static const uintptr_t DrawWireframeBox_offset = 0x369870;
static const uintptr_t DebugRenderPtr_offset = 0x62a9e0;

static const uintptr_t LightManager_offset = 0x5d9c1b0;


struct DebugDrawPersistent;
struct DP_Cube;
struct DebugRender;
typedef DebugDrawPersistent* (__cdecl* DebugDrawPersistentGetInstance_t)(void);
typedef DP_Cube* (__thiscall* AddCube_t)(DebugDrawPersistent* this_, Vector3* param_1, float param_2, Color* param_3, float param_4, char* param_5, bool *param_6);
typedef void(__thiscall* DrawWireframeBox_t)(DebugRender* this_, Box* param_1, Color* param_2);
typedef DebugRender* (__cdecl* DebugRenderPtr_t)(void);

HRESULT __fastcall hkPresent(IDXGISwapChain* pThis, UINT SyncInterval, UINT Flags) // 000002DC26616710
{
    HMODULE module_handle = GetModuleHandle(NULL);

    DebugDrawPersistentGetInstance_t DebugDrawPersistentGetInstance_ptr = (DebugDrawPersistentGetInstance_t)(DebugDrawPersistentGetInstance_offset + (uintptr_t)module_handle);
    AddCube_t AddCube_ptr = (AddCube_t)(AddCube_offset + (uintptr_t)module_handle);
    DrawWireframeBox_t DrawWireframeBox_ptr = (DrawWireframeBox_t)(DrawWireframeBox_offset + (uintptr_t)module_handle);
    DebugRenderPtr_t DebugRenderPtr_ptr = (DebugRenderPtr_t)(DebugRenderPtr_offset + (uintptr_t)module_handle);

    Vector3 *playerPos = (Vector3 *)(0x2f6c210 + (uintptr_t)module_handle);
    LightManager* lightManager = *((LightManager**)(LightManager_offset + (uintptr_t)module_handle));
    
    
    GUI::StartFrame();
    ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
    ImGui::Begin("Asil's Debug Menu");
    ImGui::Text("Hello, Lara Croft!");

    static Color color = { .m_rgba = {.x = 0.5f, .y = 0.5f, .z = 0.5f, .w = 0.5f} };
    ImGui::DragFloat4("Color", (float*)&color.m_rgba);

    ImGui::InputFloat3("player pos", (float*)playerPos, "%.3f", ImGuiInputTextFlags_ReadOnly);
    float BOX_LENGTH = 10.0f;
    ImGui::InputFloat("box size", &BOX_LENGTH);

    static bool box_enable = false;
    ImGui::Checkbox("enable box", &box_enable);
    if (box_enable) {
        for (unsigned int i = 0; i < lightManager->m_lights.size; ++i) {
            LightInstance *instance = lightManager->m_lights.data[i].m_pInstance;
            if (instance == nullptr) {
                continue;
            }
            Box box = {
                .m_min = {
                    .x = instance->m_transform.col[3].x - BOX_LENGTH,
                    .y = instance->m_transform.col[3].y - BOX_LENGTH,
                    .z = instance->m_transform.col[3].z - BOX_LENGTH,
                },
                .m_max = {
                    .x = instance->m_transform.col[3].x + BOX_LENGTH,
                    .y = instance->m_transform.col[3].y + BOX_LENGTH,
                    .z = instance->m_transform.col[3].z + BOX_LENGTH,
                }
            };
            DrawWireframeBox_ptr(DebugRenderPtr_ptr(), &box, &color);
        }
    }
    ImGui::End();
    GUI::EndFrame();
    return oPresent(pThis, SyncInterval, Flags);
}

static HRESULT CreateSwapChain(IDXGIFactory* pThis,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain
) {
    return oCreateSwapChain(pThis, pDevice, pDesc, ppSwapChain);
    HRESULT result = oCreateSwapChain(pThis, pDevice, pDesc, ppSwapChain);

    void** vtable = *(void***)(*ppSwapChain);

    oPresent = (tPresent)vtable[8];

    DWORD old_protection;
    VirtualProtect(&vtable[8], 8, PAGE_READWRITE, &old_protection);
    vtable[8] = (void*)hkPresent;
    VirtualProtect(&vtable[8], 8, old_protection, &old_protection);

    GUI::Init(*ppSwapChain);
    
    return result;
}

static int count = 0;

static HRESULT CreateSwapChain1(IDXGIFactory* pThis,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain
) {
    
    HRESULT result = oCreateSwapChain1(pThis, pDevice, pDesc, ppSwapChain);
    if (count < 1) {
        count++;
        return result;;
    }
    void** vtable = *(void***)(*ppSwapChain);

    oPresent = (tPresent)vtable[8];

    DWORD old_protection;
    VirtualProtect(&vtable[8], 8, PAGE_READWRITE, &old_protection);
    vtable[8] = (void*)hkPresent;
    VirtualProtect(&vtable[8], 8, old_protection, &old_protection);

    GUI::Init(*ppSwapChain);

    return result;
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

    return result;
   
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

    return result;
}
