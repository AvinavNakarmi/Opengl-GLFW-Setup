#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>
#include "Entity.h"
#include "ComponentStore.h"
#include "System.h"

class Scene
{
private:
    uint32_t nextEntityID = 0;

public:
    std::vector<Entity> entity;
    std::vector<std::unique_ptr<IComponentStore>> componentStores;
    Entity CreateEntity();
    template <typename T>
    ComponentStore<T> &GetStore();
    template <typename T>
    bool HasComponent(Entity entity);
    template <typename T>
    T &GetComponent(Entity entity);
    template <typename T>
    void AddComponent(Entity entity, const T &component);
};
