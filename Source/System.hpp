#ifndef SES_SYSTEM_HPP
#define SES_SYSTEM_HPP

#include <memory>
#include <vector>

#include "ComponentFilter.hpp"
#include "Packet.hpp"
#include "TypeToString.hpp"

namespace ses
{

class EntityManager;

class System
{
    public:
        System(std::shared_ptr<EntityManager> entityManager);
        virtual ~System();

        typedef std::unique_ptr<System> Ptr;

        virtual void handlePacket(sf::Packet& packet);
        virtual void entityUpdate(sf::Int32 const& entityId);

    protected:
        std::shared_ptr<EntityManager> mEntityManager;
};

typedef std::vector<sf::Int32> EntityVector;

} // namespace ses

#endif // SES_SYSTEM_HPP
