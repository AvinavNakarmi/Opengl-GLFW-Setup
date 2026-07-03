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
#include "Scene.h"

Entity Scene::CreateEntity()
{
    Entity NewEntity;
    NewEntity.id = nextEntityID++;
    this->entity.push_back(NewEntity);
    return NewEntity;
}
template <typename T>
ComponentStore<T> &Scene::GetStore()
{
    std::type_index type = typeid(T);

    auto it = this->componentStores.find(type);

    if (it == this->componentStores.end())
    {
        componentStores[type] =
            std::make_unique<ComponentStore<T>>();
    }

    return *static_cast<componentStore<T> *>(this->componentStores[type].get());
}
template <typename T>
bool Scene::HasComponent(Entity entity)
{
    auto &store = GetStore<T>();
    if (store == nullptr)
    {
        return false;
    }
    return true;
}
template <typename T>
T &Scene::GetComponent(Entity entity)
{
    auto &store = GetStore<T>();
    return store[entity.id];
};
template <typename T>
void Scene::AddComponent(Entity entity, const T &component)
{
    auto &store = GetStore<T>();
    if (store == nullptr)
    {
        std::type_index type = typeid(T);
        this->componentStores[type] = std::make_unique<componentStore<T>>();
        this->componentStores[type].component[entity.id] = component;
    }
    else
    {

        store.component[entity.id] = component;
    }
}
