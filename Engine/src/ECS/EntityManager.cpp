#include "precomp.h"
#include "EntityManager.h"
#include "ECS/Entity.h"
#include "Render/Texture.h"
#include <algorithm>

namespace Engine
{
    bool EntityManager::Init()
    {
        return true;
    }

    void EntityManager::Update(float dt)
    {
        // Post-physics update
    }

    void EntityManager::AddEntity(Entity* e)
    {
        m_Entities.emplace_back(e);
    }
    void EntityManager::AddEntity(std::unique_ptr<Entity>&& e)
    {
        m_Entities.push_back(std::move(e));
    }

    void EntityManager::RemoveEntityById(unsigned id) {

        m_Entities.erase(std::remove_if(
            m_Entities.begin(),
            m_Entities.end(),
            [id](auto const& e) { return e->GetId() == id; }),
            m_Entities.end());
    }
}
