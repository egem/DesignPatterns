#pragma once

#include <iostream>
#include "models/Color.hpp"

struct Product
{
    enum class Size
    {
        Small,
        Medium,
        Large
    };

    std::string name;
    Color color;
    Size size;
};