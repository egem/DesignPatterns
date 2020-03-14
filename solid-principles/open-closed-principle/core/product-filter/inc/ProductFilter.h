#pragma once

#include <vector>

#include "models/Product.hpp"
#include "models/Color.hpp"

class [[deprecated("This implemention is against OCP. It is open for modification")]] ProductFilter
{
    public:
        using Products = std::vector<Product*>;
        static Products by_color(Products products, Color color);
        static Products by_size(Products products, Product::Size size);
        static Products by_color_size(Products products, Color color, Product::Size size);
};
