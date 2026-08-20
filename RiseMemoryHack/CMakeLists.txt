# CMakeList.txt : CMake project for RiseMemoryHack, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library (RiseMemoryHack SHARED "RiseMemoryHack.cpp" "RiseMemoryHack.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RiseMemoryHack PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
