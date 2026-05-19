/*! \file CIsoscelesTriangle.h
    \brief Declaration of the class IsoscelesTriangle
    \author Angelo De Benedetti
*/

#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "CShape.h"

/// @class IsoscelesTriangle
/// @brief to manage an object with the shape of an Isosceles Triangle
class IsoscelesTriangle : public Shape
{
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    IsoscelesTriangle();
    IsoscelesTriangle(float px, float py, float w, float h);
    IsoscelesTriangle(const IsoscelesTriangle &r);

    ~IsoscelesTriangle();
    /// @}

    /// @name OPERATORS
    /// @{
    IsoscelesTriangle& operator=(const IsoscelesTriangle &r);
    bool operator==(const IsoscelesTriangle &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const IsoscelesTriangle &r);
    void Reset();
    /// @}

    /// @name GETTERS
    /// @{
    float GetArea();
    float GetPerimeter();
    float GetBase();
    float GetSide();
    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    void Dump(); 
    void Info();
    /// @}
};

#endif