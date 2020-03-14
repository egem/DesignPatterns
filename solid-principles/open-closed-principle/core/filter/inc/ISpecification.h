#pragma once

template <typename T>
class ISpecification
{
    public:
        virtual ~ISpecification() = default;
        virtual bool is_satisfied(T* item) const = 0;
};