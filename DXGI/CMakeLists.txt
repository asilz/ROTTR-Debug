# CMakeList.txt : CMake project for RiseMemoryHack, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library (dxgi SHARED "DXGI.cpp" "Gui.cpp" "Gui.h")

target_link_libraries(dxgi PRIVATE imgui_lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET dxgi PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
