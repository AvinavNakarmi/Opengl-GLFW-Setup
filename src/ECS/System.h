#pragma once

#include "Scene.h"
class ISystem
{
public:
    virtual void Start(Scene &state);
    virtual void Update(Scene &state);
    virtual void Destroy(Scene &state);
};