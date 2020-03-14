#include "ProductFilter.h"

ProductFilter::Products ProductFilter::by_color(ProductFilter::Products products, Color color)
{
    Products filtered;

    for(auto product: products)
    {
        if(nullptr == product)
            continue;

        if(color == product->color){
            filtered.push_back(product);
        }
    }

    return filtered;
}

ProductFilter::Products ProductFilter::by_size(ProductFilter::Products products, Product::Size size)
{
    Products filtered;

    for(auto product: products)
    {
        if(nullptr == product)
            continue;

        if(size == product->size){
            filtered.push_back(product);
        }
    }

    return filtered;
}

ProductFilter::Products ProductFilter::by_color_size(Products products, Color color, Product::Size size)
{
    Products filtered;

    for(auto product: products)
    {
        if(nullptr == product)
            continue;

        if(size == product->size && color == product->color){
            filtered.push_back(product);
        }
    }

    return filtered;
}