#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "UseImGui.h"

using namespace std;

static void glfw_error_callback ( int error, const char *description )
{
    fprintf ( stderr, "Glfw Error %d: %s\n", error, description );
}

class CustomImGui: public UseImGui
{
public:
    void Update() override
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin ( "Hello, world!" );                       // Create a window called "Hello, world!" and append into it.

        ImGui::Text ( "This is some useful text." );            // Display some text (you can use a format strings too)

        ImGui::SliderFloat ( "float", &f, 0.0f, 1.0f );         // Edit 1 float using a slider from 0.0f to 1.0f

        static float clear_color[3];
        ImGui::ColorEdit3 ( "clear color", ( float* ) &clear_color ); // Edit 3 floats representing a color

        if ( ImGui::Button ( "Button" ) )                       // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text ( "counter = %d", counter );

        ImGui::Text ( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate );
        ImGui::End();
    }
};

int main()
{
    // Setup window
    glfwSetErrorCallback ( glfw_error_callback );
    if ( !glfwInit() )
        return 1;

    // GL 3.0 + GLSL 130
    const char *glsl_version = "#version 130";
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 0 );

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow ( 1280, 720, "ImGui Example", NULL, NULL );
    if ( window == NULL )
        return 1;
    glfwMakeContextCurrent ( window );
    glfwSwapInterval ( 1 ); // Enable vsync

    if ( !gladLoadGLLoader ( ( GLADloadproc ) glfwGetProcAddress ) )
        throw ( "Unable to context to OpenGL" );

    int screen_width, screen_height;
    glfwGetFramebufferSize ( window, &screen_width, &screen_height );
    glViewport ( 0, 0, screen_width, screen_height );

    CustomImGui myimgui;
    myimgui.Init ( window, glsl_version );

    while ( !glfwWindowShouldClose ( window ) )
    {
        glfwPollEvents();

        glClearColor ( 0.45f, 0.55f, 0.60f, 1.00f );
        glClear ( GL_COLOR_BUFFER_BIT );

        myimgui.NewFrame();
        myimgui.Update();
        myimgui.Render();

        int display_w, display_h;
        glfwGetFramebufferSize ( window, &display_w, &display_h );
        glViewport ( 0, 0, display_w, display_h );
        glfwSwapBuffers ( window );
    }

    myimgui.Shutdown();

    return 0;
}
