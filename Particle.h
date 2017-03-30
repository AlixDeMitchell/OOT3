#ifndef _PARTICLE_
#define _PARTICLE_

#include <SDL.h>
#include <glm.hpp>
#include "Bucket.h"

class Particle : std::enable_shared_from_this<Particle>
{
private:
	//position
	glm::vec2 m_position;

	//velocity
	glm::vec2 m_velocity;

	//which bucket owns this particle?
	std::weak_ptr<Bucket> m_owner;

	//visible particle
	SDL_Rect rect;

	std::list<std::shared_ptr<Particle>>::iterator m_iter;

public:
	//get and set which bucket the particle belongs to
	std::weak_ptr<Bucket> GetOwner();
	void SetOwner( std::weak_ptr<Bucket> _owner );

	SDL_Rect& GetRect();

	//update
	void Update();

	//hash positions to indices
	void Rehash( std::vector<std::shared_ptr<Bucket>> &_buckets );

	Particle(double _x, double _y);
	~Particle();
};

#endif;
