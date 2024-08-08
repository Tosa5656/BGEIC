#pragma once

#include <iostream>

//////////////////////////////////////////
/// \author Tosa
/// \version 0.1
/// \brief This class provides static methods for logging messages.
///
/// It offers three logging levels: Error, Warning, and Info.
/// Each method takes a string message as input and prints it
/// with the corresponding level prefix.
/////////////////////////////////////////
class Logger
{
public:
    //////////////////////////////////////////
    /// \brief Default constructor.
    /////////////////////////////////////////
    Logger() {}

    //////////////////////////////////////////
    /// \brief Logs an error message.
    /// 
    /// \param message The error message to be logged.
    /////////////////////////////////////////
    static void Error(std::string message)
    {
        std::cout << "Error: " << message << std::endl; 
    }

    //////////////////////////////////////////
    /// \brief Logs a warning message.
    /// 
    /// \param message The warning message to be logged.
    /////////////////////////////////////////
    static void Warning(std::string message)
    {
        std::cout << "Warning: " << message << std::endl; 
    }

    //////////////////////////////////////////
    /// \brief Logs an info message.
    /// 
    /// \param message The info message to be logged.
    /////////////////////////////////////////
    static void Info(std::string message)
    {
        std::cout << message << std::endl; 
    }
};