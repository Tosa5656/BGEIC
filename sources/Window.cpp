#include <Window.h>

//////////////////////////////////////////
/// \brief Constructor with title, width and height.
/// \param Title Title of the window.
/// \param Width Width of the window.
/// \param Height Height of the window.
/////////////////////////////////////////
Window::Window(std::string Title, int Width, int Height)
{
    title = Title;
    size = VideoMode(Width, Height);
    position = Vector2(0, 0);

    Create();
}

//////////////////////////////////////////
/// \brief Constructor with title, width, height, X and Y position.
/// \param Title Title of the window.
/// \param Width Width of the window.
/// \param Height Height of the window.
/// \param PosX X position of the window.
/// \param PosY Y position of the window.
/////////////////////////////////////////
Window::Window(std::string Title, int Width, int Height, int PosX, int PosY)
{
    title = Title;
    size = VideoMode(Width, Height);
    position = Vector2(PosX, PosY);

    Create();
}

//////////////////////////////////////////
/// \brief Constructor with title and VideoMode.
/// \param Title Title of the window.
/// \param Size VideoMode of the window.
/////////////////////////////////////////
Window::Window(std::string Title, VideoMode Size)
{
    title = Title;
    size = Size;
    position = Vector2(0, 0);

    Create();
}

//////////////////////////////////////////
/// \brief Constructor with title, VideoMode and Vector2 position.
/// \param Title Title of the window.
/// \param Size VideoMode of the window.
/// \param Pos Position of the window.
/////////////////////////////////////////
Window::Window(std::string Title, VideoMode Size, Vector2 Pos)
{
    title = Title;
    size = Size;
    position = Pos;

    Create();
}

//////////////////////////////////////////
/// \brief Gets the GLFW window pointer.
/// \return GLFW window pointer.
/////////////////////////////////////////
GLFWwindow* Window::GetGLWindow()
{
    return window;
}

//////////////////////////////////////////
/// \brief Gets the title of the window.
/// \return Title of the window.
/////////////////////////////////////////
std::string Window::GetTitle()
{
    return title;
}

//////////////////////////////////////////
/// \brief Gets the size of the window.
/// \return Size of the window.
/////////////////////////////////////////
VideoMode Window::GetSize()
{
    return size;
}

//////////////////////////////////////////
/// \brief Gets the position of the window.
/// \return Position of the window.
/////////////////////////////////////////
Vector2 Window::GetPosition()
{
    return position;
}

//////////////////////////////////////////
/// \brief Creates the window.
/////////////////////////////////////////
void Window::Create()
{
    GLFWwindow* window;

    if (!glfwInit())
        return;
    
    window = glfwCreateWindow(size.width, size.height, title.c_str(), NULL, NULL);
    
    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGL())
        return;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return;
}