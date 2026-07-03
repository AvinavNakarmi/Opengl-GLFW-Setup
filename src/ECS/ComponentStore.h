#pragma once
#include <unordered_map>
#include <cstdint>

class IComponentStore
{
public:
    virtual ~IComponentStore() = default;
};

template <typename T>
class ComponentStore : public IComponentStore
{
public:
    std::unordered_map<uint32_t, T> components;
};
