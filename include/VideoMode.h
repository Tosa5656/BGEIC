#pragma once

#include <iostream>
#include <Logging.h>

//////////////////////////////////////////
/// \author Tosa
/// \version 0.1
/// \brief Represents a video mode with width and height.
/////////////////////////////////////////
class VideoMode
{
public:
    //////////////////////////////////////////
    /// \brief Default constructor.
    /// \details Initializes width and height to 0.
    /////////////////////////////////////////
    VideoMode()
    {
        width = 0;
        height = 0;
    }

    //////////////////////////////////////////
    /// \brief Constructor with initial width and height.
    /// \param Width The width of the video mode.
    /// \param Height The height of the video mode.
    /////////////////////////////////////////
    VideoMode(int Width, int Height)
    {
        width = Width;
        height = Height;
    }

    //////////////////////////////////////////
    /// \brief Overloads the + operator for addition.
    /// \param videoMode The video mode to add to this video mode.
    /// \return The resulting video mode.
    /////////////////////////////////////////
    VideoMode operator +(const VideoMode videoMode) const { return VideoMode(width + videoMode.width, height + videoMode.height); }

    //////////////////////////////////////////
    /// \brief Overloads the - operator for subtraction.
    /// \param videoMode The video mode to subtract from this video mode.
    /// \return The resulting video mode.
    /////////////////////////////////////////
    VideoMode operator -(const VideoMode videoMode) const { return VideoMode(width - videoMode.width, height - videoMode.height); }

    //////////////////////////////////////////
    /// \brief Overloads the * operator for multiplication.
    /// \param videoMode The video mode to multiply with this video mode.
    /// \return The resulting video mode.
    /////////////////////////////////////////
    VideoMode operator *(const VideoMode videoMode) const { return VideoMode(width * videoMode.width, height * videoMode.height); }

    //////////////////////////////////////////
    /// \brief Overloads the / operator for division.
    /// \param videoMode The video mode to divide by.
    /// \return The resulting video mode.
    /////////////////////////////////////////
    VideoMode operator /(const VideoMode videoMode) const { return VideoMode(width / videoMode.width, height / videoMode.height); }

    //////////////////////////////////////////
    /// \brief Overloads the += operator for addition assignment.
    /// \param number The value to add to both width and height.
    /// \return A reference to this video mode.
    /////////////////////////////////////////
    VideoMode operator +=(const int number) { this->SetWH(width += number, height += number); return *this; }

    //////////////////////////////////////////
    /// \brief Overloads the -= operator for subtraction assignment.
    /// \param number The value to subtract from both width and height.
    /// \return A reference to this video mode.
    /////////////////////////////////////////
    VideoMode operator -=(const int number) { this->SetWH(width -= number, height -= number); return *this; }

    //////////////////////////////////////////
    /// \brief Overloads the *= operator for multiplication assignment.
    /// \param number The value to multiply both width and height by.
    /// \return A reference to this video mode.
    /////////////////////////////////////////
    VideoMode operator *=(const int number) { this->SetWH(width *= number, height *= number); return *this; }

    //////////////////////////////////////////
    /// \brief Overloads the /= operator for division assignment.
    /// \param number The value to divide both width and height by.
    /// \return A reference to this video mode.
    /////////////////////////////////////////
    VideoMode operator /=(const int number)
    {
        if(number == 0)
        {
            Logger::Error("Error! You cannot divide by zero (the video mode is zeroed)");
            this->Reset();
        }

        this->SetWH(width /= number, height /= number);

        return *this;
    }

    //////////////////////////////////////////
    /// \brief Overloads the unary - operator for negation.
    /// \return The negated videoMode.
    /////////////////////////////////////////
    VideoMode operator - () const { return VideoMode(-width, -height); }

    //////////////////////////////////////////
    /// \brief Overloads the << operator for outputting a VideoMode to an ostream.
    /// \param os The ostream to output to.
    /// \param videoMode The VideoMode to output.
    /// \return The ostream.
    /////////////////////////////////////////
    friend std::ostream& operator<<(std::ostream& os, const VideoMode& videoMode)
    {
        return os << "(" << videoMode.width << ", " << videoMode.height << ")";
    }

    //////////////////////////////////////////
    /// \brief The width of the video mode.
    /////////////////////////////////////////
    int width = 0;

    //////////////////////////////////////////
    /// \brief The height of the video mode.
    /////////////////////////////////////////
    int height = 0;

private:
    //////////////////////////////////////////
    /// \brief Sets both width and height of the video mode.
    /// \param Width The new width.
    /// \param Height The new height.
    /////////////////////////////////////////
    void SetWH(int Width, int Height)
    {
        width = Width;
        height = Height;
    }

    //////////////////////////////////////////
    /// \brief Resets both width and height to 0.
    /////////////////////////////////////////
    void Reset()
    {
        width = 0;
        height = 0;
    }
};