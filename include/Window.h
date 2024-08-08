#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <Logging.h>
#include <Vectors.h>
#include <VideoMode.h>

#define SetTitle(Window, Title) title = Title; glfwSetWindowTitle(Window, Title);

#define SetSize(Window, Width, Height) size = VideoMode(Width, Height); glfwSetWindowSize(Window, Width, Height);
#define SetSizeVM(Window, Size) size = Size; glfwSetWindowSize(Window, Size.width, Size.height);

//////////////////////////////////////////
/// \brief Represents a window for rendering.
/////////////////////////////////////////
class Window
{
public:
    //////////////////////////////////////////
    /// \brief Constructor with title, width and height.
    /// \param Title Title of the window.
    /// \param Width Width of the window.
    /// \param Height Height of the window.
    /////////////////////////////////////////
    Window(std::string Title, int Width, int Height);

    //////////////////////////////////////////
    /// \brief Constructor with title, width, height, X and Y position.
    /// \param Title Title of the window.
    /// \param Width Width of the window.
    /// \param Height Height of the window.
    /// \param PosX X position of the window.
    /// \param PosY Y position of the window.
    /////////////////////////////////////////
    Window(std::string Title, int Width, int Height, int PosX, int PosY);

    //////////////////////////////////////////
    /// \brief Constructor with title and VideoMode.
    /// \param Title Title of the window.
    /// \param Size VideoMode of the window.
    /////////////////////////////////////////
    Window(std::string Title, VideoMode Size);

    //////////////////////////////////////////
    /// \brief Constructor with title, VideoMode and Vector2 position.
    /// \param Title Title of the window.
    /// \param Size VideoMode of the window.
    /// \param Pos Position of the window.
    /////////////////////////////////////////
    Window(std::string Title, VideoMode Size, Vector2 Pos);

    //////////////////////////////////////////
    /// \brief Gets the GLFW window pointer.
    /// \return GLFW window pointer.
    /////////////////////////////////////////
    GLFWwindow* GetGLWindow();

    //////////////////////////////////////////
    /// \brief Gets the title of the window.
    /// \return Title of the window.
    /////////////////////////////////////////
    std::string GetTitle();

    //////////////////////////////////////////
    /// \brief Gets the size of the window.
    /// \return Size of the window.
    /////////////////////////////////////////
    VideoMode GetSize();

    //////////////////////////////////////////
    /// \brief Gets the position of the window.
    /// \return Position of the window.
    /////////////////////////////////////////
    Vector2 GetPosition();

private:
    //////////////////////////////////////////
    /// \brief Creates the window.
    /////////////////////////////////////////
    void Create();

    GLFWwindow* window;
    std::string title;
    VideoMode size;
    Vector2 position;
};