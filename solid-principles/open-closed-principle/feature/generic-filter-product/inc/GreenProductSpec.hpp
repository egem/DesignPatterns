#pragma once

#include "ISpecification.hpp"
#include "models/Product.hpp"

class GreenProductSpec: public ISpecification<Product>
{
    public:
        bool is_satisfied(Product* product) const
        {
            return Color::Green == product->color;
        }
};
