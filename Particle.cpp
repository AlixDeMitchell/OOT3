#include "Particle.h"

Particle::Particle( double _x, double _y )
{
	m_position.x = _x;
	m_position.y = _y;
	rect.w = 5;
	rect.h = 5;

	do
	{
		m_velocity.x = rand() % 10 - 5;
	} while ( m_velocity.x == 0 );

	do
	{
		m_velocity.y = rand() % 10 - 5;
	} while ( m_velocity.y == 0 );

	
}

std::weak_ptr<Bucket> Particle::GetOwner()
{
	return m_owner;
}

void Particle::SetOwner( std::weak_ptr<Bucket> _currentBucket )
{
	m_owner = _currentBucket;
}

SDL_Rect & Particle::GetRect()
{
	return rect;
}


void Particle::Update()
{
	m_position += m_velocity;
	rect.x = m_position.x;
	rect.y = m_position.y;

	if ( rect.x < 0 || rect.x > 1900 ) m_velocity.x *= -1;
	if ( rect.y < 0 || rect.y > 1000 ) m_velocity.y *= -1;
}

std::list<std::shared_ptr<Particle>>::iterator Particle::GetIter()
{
	return m_iter;
}

void Particle::SetIter( std::vector<std::shared_ptr<Bucket>>& _buckets )
{

}

glm::vec2 Particle::GetPosition()
{
	return m_position;
}

SDL_Rect & Particle::GetRect()
{
	return rect;
}




Particle::~Particle()
{
}
