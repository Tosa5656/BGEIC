#pragma once

#include <iostream>
#include <Logging.h>

////////////////////////////////////////////////////
/// \author Tosa
/// \version 1.0
/// \brief Represents a 2D vector with integer coordinates.
////////////////////////////////////////////////////
class Vector2
{
public:
    ///////////////////////////////////////////////////////
    /// \brief Default constructor.
    /// 
    /// Initializes the vector with zero coordinate values.
    ///////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////
    /// \brief Parameterized constructor.
    /// 
    /// Initializes the vector with the given coordinate values.
    /// \param X The value of the x coordinate.
    /// \param Y The value of the y coordinate.
    ////////////////////////////////////////////////////////////
    Vector2(int X, int Y)
    {
    x = X;
    y = Y;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Overloading the addition operator.
    ///
    /// Returns a new vector that is the sum of the current vector and the one passed as an argument.
    /// \param vector The vector to add to the current one.
    /// \return A new vector that is the sum of the two vectors.
    /////////////////////////////////////////////////////////////////////////////////////////////////
    Vector2 operator +(const Vector2 vector) const { return Vector2(x + vector.x, y + vector.y); }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Overloading the subtraction operator.
    ///
    /// Returns a new vector that is the difference between the current vector and the one passed as an argument.
    /// \param vector The vector to subtract from the current one.
    /// \return A new vector that is the difference between the two vectors.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Vector2 operator -(const Vector2 vector) const { return Vector2(x - vector.x, y - vector.y); }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Overloading the multiplication operator.
    ///
    /// Returns a new vector that is the product of the current vector and the one passed as an argument.
    /// \param vector The vector to multiply with the current one.
    /// \return A new vector that is the product of the two vectors.
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    Vector2 operator *(const Vector2 vector) const { return Vector2(x * vector.x, y * vector.y); }

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Overloading the division operator.
    /// 
    /// Returns a new vector that is the quotient of the current vector and the one passed as an argument.
    /// \param vector The vector to divide the current one by.
    /// \return A new vector that is the quotient of the two vectors.
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    Vector2 operator /(const Vector2 vector) const { return Vector2(x / vector.x, y / vector.y); }

    //////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Overloading the addition assignment operator.
    ///
    /// Adds the passed number to the current vector and assigns the result to the current vector.
    /// \param number The number to add to the current vector.
    /// \return A reference to the current vector.
    //////////////////////////////////////////////////////////////////////////////////////////////
    Vector2 operator +=(const int number) { this->SetXY(x += number, y += number); return *this; }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Overloading the subtraction assignment operator.
    /// 
    /// Subtracts the passed number from the current vector and assigns the result to the current vector.
    /// \param number The number to subtract from the current vector.
    /// \return A reference to the current vector.
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    Vector2 operator -=(const int number) { this->SetXY(x -= number, y -= number); return *this; }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Overloading the multiplication assignment operator.
    ///
    /// Multiplies the current vector by the passed number and assigns the result to the current vector.
    /// \param number The number to multiply the current vector by.
    /// \return A reference to the current vector.
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    Vector2 operator *=(const int number) { this->SetXY(x *= number, y *= number); return *this; }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Overloading the division assignment operator.
    /// 
    /// Divides the current vector by the passed number and assigns the result to the current vector.
    /// \param number The number to divide the current vector by.
    /// \return A reference to the current vector.
    /////////////////////////////////////////////////////////////////////////////////////////////////
    Vector2 operator /=(const int number)
    {
        if(number == 0)
        {
            Logger::Error("Error! You cannot divide by zero (the vector is zeroed)");
            this->Reset();
        }

        this->SetXY(x /= number, y /= number);

        return *this;
    }

    //////////////////////////////////////////
    /// \brief Overloads the unary - operator for negation.
    /// \return The negated vector.
    /////////////////////////////////////////
    Vector2 operator - () const { return Vector2(-x, -y); }

    //////////////////////////////////////////
    /// \brief Overloads the << operator for outputting a Vector2 to an ostream.
    /// \param os The ostream to output to.
    /// \param vector The Vector2 to output.
    /// \return The ostream.
    /////////////////////////////////////////
    friend std::ostream& operator <<(std::ostream& os, const Vector2& vector)
    {
        os << "(" << vector.x << ", " << vector.y << ")";
        return os;
    }
    
    int x = 0, y = 0;
private:
    //////////////////////////////////////////////////////
    /// \brief Sets the x and y coordinates of the vector.
    /// \param X The value of the x coordinate.
    /// \param Y The value of the y coordinate.
    //////////////////////////////////////////////////////
    void SetXY(int X, int Y)
    {
        x = X;
        y = Y;
    }

    /////////////////////////////////////
    /// \brief Resets the vector to zero.
    /////////////////////////////////////
    void Reset()
    {
        x = 0;
        y = 0;
    }
};

//////////////////////////////////////////
/// \author Tosa
/// \version 0.1
/// \brief Represents a 3D vector with integer coordinates.
/////////////////////////////////////////
class Vector3
{
public:
    //////////////////////////////////////////
    /// \brief Default constructor.
    /// \details Initializes all coordinates to 0.
    /////////////////////////////////////////
    Vector3()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    //////////////////////////////////////////
    /// \brief Constructor with initial values.
    /// \param X The x-coordinate.
    /// \param Y The y-coordinate.
    /// \param Z The z-coordinate.
    /////////////////////////////////////////
    Vector3(int X, int Y, int Z)
    {
        x = X;
        y = Y;
        z = Z;
    }

    //////////////////////////////////////////
    /// \brief Overloads the + operator for vector addition.
    /// \param vector The vector to add to this vector.
    /// \return The resulting vector.
    /////////////////////////////////////////
    Vector3 operator +(const Vector3 vector) const { return Vector3(x + vector.x, y + vector.y, z + vector.z); }

    //////////////////////////////////////////
    /// \brief Overloads the * operator for element-wise vector multiplication.
    /// \param vector The vector to multiply with this vector.
    /// \return The resulting vector.
    /////////////////////////////////////////
    Vector3 operator *(const Vector3 vector) const { return Vector3(x * vector.x, y * vector.y, z * vector.z); }

    //////////////////////////////////////////
    /// \brief Overloads the / operator for element-wise vector division.
    /// \param vector The vector to divide by.
    /// \return The resulting vector.
    /////////////////////////////////////////
    Vector3 operator /(const Vector3 vector) const { return Vector3(x / vector.x, y / vector.y, z / vector.z); }

    //////////////////////////////////////////
    /// \brief Overloads the += operator for addition assignment.
    /// \param number The value to add to each coordinate.
    /// \return A reference to this vector.
    /////////////////////////////////////////
    Vector3 operator +=(const int number) { this->SetXY(x += number, y += number, z += number); return *this; }

    //////////////////////////////////////////
    /// \brief Overloads the -= operator for subtraction assignment.
    /// \param number The value to subtract from each coordinate.
    /// \return A reference to this vector.
    /////////////////////////////////////////
    Vector3 operator -=(const int number) { this->SetXY(x -= number, y -= number, z -= number); return *this; }

    //////////////////////////////////////////
    /// \brief Overloads the *= operator for multiplication assignment.
    /// \param number The value to multiply each coordinate by.
    /// \return A reference to this vector.
    /////////////////////////////////////////
    Vector3 operator *=(const int number) { this->SetXY(x *= number, y *= number, z *= number); return *this; }

    //////////////////////////////////////////
    /// \brief Overloads the /= operator for division assignment.
    /// \param number The value to divide each coordinate by.
    /// \return A reference to this vector.
    /////////////////////////////////////////
    Vector3 operator /=(const int number)
    {
        if(number == 0)
        {
            Logger::Error("Error! You cannot divide by zero (the vector is zeroed)");
            this->Reset();
        }

        this->SetXY(x /= number, y /= number, z /= number);
        
        return *this;
    }

    //////////////////////////////////////////
    /// \brief Overloads the unary - operator for negation.
    /// \return The negated vector.
    /////////////////////////////////////////
    Vector3 operator - () const { return Vector3(-x, -y, -z); }

    //////////////////////////////////////////
    /// \brief Overloads the << operator for outputting a Vector3 to an ostream.
    /// \param os The ostream to output to.
    /// \param vector The Vector3 to output.
    /// \return The ostream.
    /////////////////////////////////////////
    friend std::ostream& operator <<(std::ostream& os, const Vector3& vector)
    {
        os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
        return os;
    }

    //////////////////////////////////////////
    /// \brief The x-coordinate of the vector.
    /////////////////////////////////////////
    int x = 0;

    //////////////////////////////////////////
    /// \brief The y-coordinate of the vector.
    /////////////////////////////////////////
    int y = 0;

    //////////////////////////////////////////
    /// \brief The z-coordinate of the vector.
    /////////////////////////////////////////
    int z = 0;
private:
    //////////////////////////////////////////
    /// \brief Sets all coordinates of the vector.
    /// \param X The new x-coordinate.
    /// \param Y The new y-coordinate.
    /// \param Z The new z-coordinate.
    /////////////////////////////////////////
    void SetXY(int X, int Y, int Z)
    {
        x = X;
        y = Y;
        z = Z;
    }

    //////////////////////////////////////////
    /// \brief Resets all coordinates to 0.
    /////////////////////////////////////////
    void Reset()
    {
        x = 0;
        y = 0;
        z = 0;
    }
};

//////////////////////////////////////////
/// \author Tosa
/// \version 0.1
/// \brief Represents a 4D vector with integer coordinates.
/////////////////////////////////////////
class Vector4
{
public:
    //////////////////////////////////////////
    /// \brief Default constructor.
    /// \details Initializes all coordinates to 0.
    /////////////////////////////////////////
    Vector4()
    {
        x = 0;
        y = 0;
        z = 0;
        w = 0;
    }

    //////////////////////////////////////////
    /// \brief Constructor with initial values.
    /// \param X The x-coordinate.
    /// \param Y The y-coordinate.
    /// \param Z The z-coordinate.
    /// \param W The w-coordinate.
    /////////////////////////////////////////
    Vector4(int X, int Y, int Z, int W)
    {
        x = X;
        y = Y;
        z = Z;
        w = W;
    }

    //////////////////////////////////////////
    /// \brief Overloads the + operator for vector addition.
    /// \param vector The vector to add to this vector.
    /// \return The resulting vector.
    /////////////////////////////////////////
    Vector4 operator +(const Vector4 vector) const { return Vector4(x + vector.x, y + vector.y, z + vector.z, w + vector.w); }

    //////////////////////////////////////////
    /// \brief Overloads the - operator for vector subtraction.
    /// \param vector The vector to subtract from this vector.
    /// \return The resulting vector.
    /////////////////////////////////////////
    Vector4 operator -(const Vector4 vector) const { return Vector4(x - vector.x, y - vector.y, z - vector.z, w - vector.w); }

    //////////////////////////////////////////
    /// \brief Overloads the * operator for element-wise vector multiplication.
    /// \param vector The vector to multiply with this vector.
    /// \return The resulting vector.
    /////////////////////////////////////////
    Vector4 operator *(const Vector4 vector) const { return Vector4(x * vector.x, y * vector.y, z * vector.z, w * vector.w); }

    //////////////////////////////////////////
    /// \brief Overloads the / operator for element-wise vector division.
    /// \param vector The vector to divide by.
    /// \return The resulting vector.
    /////////////////////////////////////////
    Vector4 operator /(const Vector4 vector) const { return Vector4(x / vector.x, y / vector.y, z / vector.z, w / vector.w); }

    //////////////////////////////////////////
    /// \brief Overloads the += operator for addition assignment.
    /// \param number The value to add to each coordinate.
    /// \return A reference to this vector.
    /////////////////////////////////////////
    Vector4 operator +=(const int number) { this->SetXY(x += number, y += number, z += number, w += number);  return *this; }

    //////////////////////////////////////////
    /// \brief Overloads the -= operator for subtraction assignment.
    /// \param number The value to subtract from each coordinate.
    /// \return A reference to this vector.
    /////////////////////////////////////////
    Vector4 operator -=(const int number) { this->SetXY(x -= number, y -= number, z -= number, w -= number);  return *this; }

    //////////////////////////////////////////
    /// \brief Overloads the *= operator for multiplication assignment.
    /// \param number The value to multiply each coordinate by.
    /// \return A reference to this vector.
    /////////////////////////////////////////
    Vector4 operator *=(const int number) { this->SetXY(x *= number, y *= number, z *= number, w *= number);  return *this; }

    //////////////////////////////////////////
    /// \brief Overloads the /= operator for division assignment.
    /// \param number The value to divide each coordinate by.
    /// \return A reference to this vector.
    /////////////////////////////////////////
    Vector4 operator /=(const int number)
    {
        if(number == 0)
        {
            Logger::Error("Error! You cannot divide by zero (the vector is zeroed)");
            this->Reset();
        }

        this->SetXY(x /= number, y /= number, z /= number, w /= number);

        return *this;
    }

    //////////////////////////////////////////
    /// \brief Overloads the unary - operator for negation.
    /// \return The negated vector.
    /////////////////////////////////////////
    Vector4 operator - () const { return Vector4(-x, -y, -z, -w); }

    //////////////////////////////////////////
    /// \brief Overloads the << operator for outputting a Vector4 to an ostream.
    /// \param os The ostream to output to.
    /// \param vector The Vector4 to output.
    /// \return The ostream.
    /////////////////////////////////////////
    friend std::ostream& operator <<(std::ostream& os, const Vector4& vector)
    {
        os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
        return os;
    }

    //////////////////////////////////////////
    /// \brief The x-coordinate of the vector.
    /////////////////////////////////////////
    int x = 0;

    //////////////////////////////////////////
    /// \brief The y-coordinate of the vector.
    /////////////////////////////////////////
    int y = 0;

    //////////////////////////////////////////
    /// \brief The z-coordinate of the vector.
    /////////////////////////////////////////
    int z = 0;

    //////////////////////////////////////////
    /// \brief The w-coordinate of the vector.
    /////////////////////////////////////////
    int w = 0;

private:
    //////////////////////////////////////////
    /// \brief Sets all coordinates of the vector.
    /// \param X The new x-coordinate.
    /// \param Y The new y-coordinate.
    /// \param Z The new z-coordinate.
    /// \param W The new w-coordinate.
    /////////////////////////////////////////
    void SetXY(int X, int Y, int Z, int W)
    {
        x = X;
        y = Y;
        z = Z;
        w = W;
    }
    
    //////////////////////////////////////////
    /// \brief Resets all coordinates to 0.
    /////////////////////////////////////////
    void Reset()
    {
        x = 0;
        y = 0;
        z = 0;
        w = 0;
    }
};