#pragma once

#include "ISpecification.hpp"
#include "models/Product.hpp"

class SmallProductSpec: public ISpecification<Product>
{
    public:
        bool is_satisfied(Product* product) const
        {
            return Product::Size::Small == product->size;
        }
};