cmake_minimum_required(VERSION 3.21)
project(ImGUI_Example)

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

if(WIN32)
if ("${GLFW_DIR}" STREQUAL "")
message(SEND_ERROR "define GLFW_DIR")
return()
endif()
message("GLFW_DIR ${GLFW_DIR}")

target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_DIR}/include)
target_link_directories(${PROJECT_NAME} PUBLIC ${GLFW_DIR}/lib-vc2022)
target_link_libraries(${PROJECT_NAME} glfw3 opengl32)
target_link_options(${PROJECT_NAME} PUBLIC /NODEFAULTLIB:msvcrt)

else()

find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw GL)

endif()

target_include_directories(${PROJECT_NAME} PUBLIC "${IMGUI_DIR};${IMGUI_DIR}/backends")
target_include_directories(${PROJECT_NAME} PUBLIC "${GLAD_DIR}/include")
install(TARGETS ${PROJECT_NAME})
