
#include "imgui.h"
#include <SDL3/SDL.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>

namespace GUI {
    int Init(void)
    {
        if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
        {
            return -1;
        }

        // Create window with SDL_Renderer graphics context
        float main_scale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
        SDL_WindowFlags window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;
        SDL_Window* window =
            SDL_CreateWindow("ROTTR Debug", (int)(1280 * main_scale), (int)(800 * main_scale), window_flags);
        if (window == nullptr)
        {
            return -1;
        }
        SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
        SDL_SetRenderVSync(renderer, 1);
        if (renderer == nullptr)
        {
            return -1;
        }
        SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        SDL_ShowWindow(window);

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsLight();


        // Setup Platform/Renderer backends
        ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
        ImGui_ImplSDLRenderer3_Init(renderer);

        return 0;
    }

    bool StartFrame(void)
    {
        bool done = false;

        ImGui_ImplSDL3_Data* backend =
            ImGui::GetCurrentContext() ? (ImGui_ImplSDL3_Data*)ImGui::GetIO().BackendPlatformUserData : nullptr;
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT)
                done = true;
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(backend->Window))
                done = true;
        }

        // [If using SDL_MAIN_USE_CALLBACKS: all code below would likely be your SDL_AppIterate() function]
        if (SDL_GetWindowFlags(backend->Window) & SDL_WINDOW_MINIMIZED)
        {
            SDL_Delay(10);
            return done;
        }

        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        return done;
    }

    void EndFrame(void)
    {
        ImGui_ImplSDL3_Data* backend =
            ImGui::GetCurrentContext() ? (ImGui_ImplSDL3_Data*)ImGui::GetIO().BackendPlatformUserData : nullptr;
        ImGui::Render();
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        SDL_SetRenderDrawColorFloat(backend->Renderer, clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        SDL_RenderClear(backend->Renderer);
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), backend->Renderer);
        SDL_RenderPresent(backend->Renderer);
    }

    void Destroy(void)
    {
        ImGui_ImplSDL3_Data* backend =
            ImGui::GetCurrentContext() ? (ImGui_ImplSDL3_Data*)ImGui::GetIO().BackendPlatformUserData : nullptr;
        ImGui_ImplSDLRenderer3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();

        SDL_DestroyRenderer(backend->Renderer);
        SDL_DestroyWindow(backend->Window);
        SDL_Quit();
    }
};