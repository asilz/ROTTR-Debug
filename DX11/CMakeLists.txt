# CMakeList.txt : CMake project for RiseMemoryHack, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library (d3d11 SHARED "D3D11.cpp" "Gui.cpp" "Gui.h")

target_link_libraries(d3d11 PRIVATE imgui_lib d3d11_hook)
target_include_directories(d3d11 PRIVATE ../DX11Hook)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET d3d11 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
