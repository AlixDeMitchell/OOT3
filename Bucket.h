#ifndef _BUCKET_
#define _BUCKET_

#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <glm.hpp>

class Particle;

class Bucket
{
private:

	//coords of the upper left corner?
	glm::vec2 m_bucketPos;

	//list containing a ptr to all particles within a given bucket
	std::list<std::shared_ptr<Particle>> m_particles;

	int m_index;

public:

	
	Bucket(int _index);
	~Bucket();

	//clear the list of particles so that it can be updated
	//void ClearList();

	////update list with currently in-bucket particles
	//void SetList( std::list<std::shared_ptr<Particle>> &_updatedList );

	//getter for particle list
	std::list<std::shared_ptr<Particle>> GetList ();

	//get/set index of bucket
	int GetIndex();
	void SetIndex( int _index );

	void AddParticle( std::shared_ptr<Particle> _particle );
};

#endif