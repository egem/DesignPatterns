#include <iostream>
#include "models/Product.hpp"
#include "ProductFilter.hpp"

#include "Filter.hpp"
#include "GreenProductSpec.hpp"
#include "SmallProductSpec.hpp"

using Products = std::vector<Product*>;


Products deprecatedFilter(Products products)
{
    return ProductFilter::by_color_size(products, Color::Green, Product::Size::Small);
}

Products genericFilter(Products products)
{
    GreenProductSpec greenProductSpec;
    SmallProductSpec smallProductSpec;

    Filter<Product> greenSmallFilter;
    return greenSmallFilter(products, {&greenProductSpec, &smallProductSpec});
}

int main()
{
    Product tshirt{"T-Shirt", Color::Green, Product::Size::Small};
    Product house{"House", Color::Blue, Product::Size::Large};
    Product car{"Car", Color::Blue, Product::Size::Medium};

    Products all{&tshirt, &house, &car};

    std::cout << "Filtered by deprecated filter" << std::endl;

    Products greenSmallProducts = deprecatedFilter(all);

    for(auto greenProduct: greenSmallProducts)
    {
        std::cout << greenProduct->name << " is green and small" << std::endl;
    }

    std::cout << "Filtered by generic filter" << std::endl;

    greenSmallProducts = genericFilter(all);

    for(auto greenProduct: greenSmallProducts)
    {
        std::cout << greenProduct->name << " is green and small" << std::endl;
    }

}