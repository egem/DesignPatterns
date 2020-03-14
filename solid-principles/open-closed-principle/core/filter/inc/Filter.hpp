#pragma once

#include <vector>
#include <functional>

#include "ISpecification.hpp"

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

        Items operator()(Items items, const std::vector<ISpecification<Item>*>& multiSpec)
        {
            Items result;

            std::function<bool(Item*)> is_satisfied = [&multiSpec](Item* item) -> bool
            {
                for(auto spec: multiSpec)
                {
                    if(nullptr == spec)
                        continue;

                    if(!spec->is_satisfied(item))
                        return false;
                }

                return true;
            };

            for(auto item: items)
            {
                if(is_satisfied(item))
                {
                    result.push_back(item);
                }
            }

            return result;
        }
};