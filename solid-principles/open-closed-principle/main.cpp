#include <iostream>
#include "models/Product.hpp"
#include "ProductFilter.h"

#include "Filter.h"
#include "ISpecification.h"

using Products = std::vector<Product*>;

class GreenProductSpec: public ISpecification<Product>
{
    public:
        bool is_satisfied(Product* product) const
        {
            return Color::Green == product->color;
        }
};

class SmallProductSpec: public ISpecification<Product>
{
    public:
        bool is_satisfied(Product* product) const
        {
            return Product::Size::Small == product->size;
        }
};

class MultiProductSpec: public ISpecification<Product>
{
    private:
        std::vector<ISpecification<Product>*> m_specs;

    public:
        MultiProductSpec(std::vector<ISpecification<Product>*> specs)
        :m_specs(specs)
        {}

        bool is_satisfied(Product* product) const
        {
            for(auto spec: m_specs)
            {
                if(!spec->is_satisfied(product))
                    return false;
            }

            return true;
        }
};

Products deprecatedFilter(Products products)
{
    return ProductFilter::by_color_size(products, Color::Green, Product::Size::Small);
}

Products genericFilter(Products products)
{
    GreenProductSpec greenProductSpec;
    SmallProductSpec smallProductSpec;
    MultiProductSpec greenSmallProductSpec({&greenProductSpec, &smallProductSpec});

    Filter<Product> greenSmallFilter;
    return greenSmallFilter(products, greenSmallProductSpec);
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