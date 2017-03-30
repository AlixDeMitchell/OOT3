#include "Bucket.h"



Bucket::Bucket(int _index)
{
	m_index = _index;
}


Bucket::~Bucket()
{
}

//void Bucket::ClearList()
//{
//	m_particles.clear();
//}
//
//void Bucket::SetList( std::list<std::shared_ptr<Particle>> &_updatedList )
//{
//	m_particles = _updatedList;
//}

std::list<std::shared_ptr<Particle>> Bucket::GetList()
{
	return std::list<std::shared_ptr<Particle>>();
}

int Bucket::GetIndex()
{
	return m_index;
}

void Bucket::SetIndex( int _index )
{
	m_index = _index;
}


void Bucket::AddParticle( std::shared_ptr<Particle> _particle )
{
	m_particles.push_back( _particle );
}
