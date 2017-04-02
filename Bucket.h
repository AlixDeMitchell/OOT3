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

	//screen coordinates of the bucket
	//m::vec2 m_bucketPos;

	//list containing a ptr to all particles within a given bucket
	std::list<std::shared_ptr<Particle>> m_particles;

	//position of each bucket within the vector of buckets, created in application GenerateBuckets routine
	int m_index;

public:

	
	Bucket(int _index);
	~Bucket();

	//getter for particle list
	std::list<std::shared_ptr<Particle>> GetList ();

	//get/set index of bucket
	int GetIndex();
	void SetIndex( int _index );

	//add particle to bucket
	void AddParticle( std::shared_ptr<Particle> _particle );

	//remove particle from bucket
	void RemoveParticle( std::list<std::shared_ptr<Particle>>::iterator _iter );

	

};

#endif
