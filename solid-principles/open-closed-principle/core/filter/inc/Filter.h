#pragma once

#include <vector>

#include "ISpecification.h"

template <typename Item>
class Filter
{
    public:
        virtual ~Filter() = default;
        using Items = std::vector<Item*>;
        Items operator()(Items items, const ISpecification<Item>& spec)
        {
            Items result;

            for(auto item: items)
            {
                if(spec.is_satisfied(item))
                {
                    result.push_back(item);
                }
            }

            return result;
        }
};