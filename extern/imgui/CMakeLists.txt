# Dear ImGui
set(IMGUI_DIR remote)

file(GLOB sources ${IMGUI_DIR}/*.cpp)

add_library(imgui_lib ${sources} backend/imgui_impl_dx11.cpp backend/imgui_impl_win32.cpp ${IMGUI_DIR}/imgui.cpp ${IMGUI_DIR}/imgui_draw.cpp ${IMGUI_DIR}/imgui_demo.cpp ${IMGUI_DIR}/imgui_tables.cpp ${IMGUI_DIR}/imgui_widgets.cpp)
target_include_directories(imgui_lib PUBLIC ${IMGUI_DIR})
target_include_directories(imgui_lib PUBLIC backend)