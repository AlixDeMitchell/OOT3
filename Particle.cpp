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

void Particle::SetOwner( std::weak_ptr<Bucket> _owner )
{
	/*
	std::shared_ptr<Bucket> incoming_bucket = _owner.lock();
	std::shared_ptr<Bucket> existing_bucket = m_owner.lock();

	if ( !existing_bucket )
	{
		std::shared_ptr<Particle> thisShared = shared_from_this();
		incoming_bucket->GetList().push_back( thisShared );

		m_iter = std::find(
			incoming_bucket->GetList().begin(),
			incoming_bucket->GetList().end(),
			shared_from_this() );

		return;
	}

	if ( incoming_bucket->GetIndex() == existing_bucket->GetIndex() )
	{
		return;
	}
	else
	{
		//  erase this particle from current owner particle list
		//  add this particle to new owner particle list
		//	m_owner = _owner;
		if (m_iter != existing_bucket->GetList().end() )
			existing_bucket->GetList().erase( m_iter );

		incoming_bucket->GetList().push_back( shared_from_this() );

		m_iter = std::find( 
			incoming_bucket->GetList().begin(),
			incoming_bucket->GetList().end(),
			shared_from_this());

	}
	*/
	m_owner = _owner;
	
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

void Particle::Rehash( std::vector<std::shared_ptr<Bucket>> &_buckets )
{
	/*m_position
		Using this->position work out which bucket I am in
		setOwner to be the bucket found in above

		int xindex = (4 * owner->bucketWidth) / position.x
		int yindex = (4 * owner->bucketHeight) / position.y

		int i = yindex * 4 + xindex

		setOwner(buckets.at(i));*/
	
	m_position = this->m_position;

	int xIndex = ( 190 / m_position.x );
	int yIndex = ( 100 / m_position.y );
	int i = yIndex * 10 + xIndex;
	SetOwner( _buckets.at( i ) );
}




Particle::~Particle()
{
}
