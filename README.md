# ImGUI example

Tutorial "Why and How To Use ImGui For Your Coding Projects | Tutorial & Case Study"  
Part 1: https://www.youtube.com/watch?v=U1BnzWX194Q  
Part 2: https://www.youtube.com/watch?v=19XcuaYF3kM  

- Clone the repo
    - `git clone https://github.com/ocornut/imgui`
- Install glfw3
    - `sudo apt install libglfw3-dev`
- Add to include path
    - `path/to/imgui`
    - `path/to/imgui/backends`
- Check glfw3 flags
    - `pkg-config --static --libs glfw3`
    - `pkg-config --cflags glfw3`
- Compile all these sources
    - main.cpp
    - $(IMGUI_DIR)/imgui.cpp
    - $(IMGUI_DIR)/imgui_demo.cpp
    - $(IMGUI_DIR)/imgui_draw.cpp
    - $(IMGUI_DIR)/imgui_tables.cpp
    - $(IMGUI_DIR)/imgui_widgets.cpp
    - $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp
    - $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
