cmake_minimum_required(VERSION 3.21)
project(ImGUI_Example)

find_package(glfw3 REQUIRED)

if ("${IMGUI_DIR}" STREQUAL "")
    message(SEND_ERROR "define IMGUI_DIR")
    return()
endif()

if ("${GLAD_DIR}" STREQUAL "")
    message(SEND_ERROR "define GLAD_DIR")
    return()
endif()

message("IMGUI_DIR ${IMGUI_DIR}")

set(SOURCES "${IMGUI_DIR}/imgui.cpp;${IMGUI_DIR}/imgui_demo.cpp;${IMGUI_DIR}/imgui_draw.cpp;${IMGUI_DIR}/imgui_tables.cpp;${IMGUI_DIR}/imgui_widgets.cpp;${IMGUI_DIR}/backends/imgui_impl_glfw.cpp;${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp")
set(SOURCES "${SOURCES};${GLAD_DIR}/src/glad.c")

add_executable(${PROJECT_NAME} main.cpp UseImGui.cpp ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "${IMGUI_DIR};${IMGUI_DIR}/backends")
target_include_directories(${PROJECT_NAME} PUBLIC "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} glfw GL)
install(TARGETS ${PROJECT_NAME})
