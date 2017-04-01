#ifndef _APPLICATION_
#define _APPLICATION_

#include "Bucket.h"
#include "Particle.h"
#include "SDLManager.h"
#include "FPS.h"
#include <algorithm>

class Application
{
private:
	//SDL 
	SDLManager m_SDLmanager;

	//is the demo running?
	bool m_running;

	//"grid": a vector of shared pointers to bucket objects, 100x100 sections of screen
	std::vector<std::shared_ptr<Bucket>> m_buckets;

	// all particles, used for drawing
	std::vector<std::shared_ptr<Particle>> m_allParticles;

	//bucket size
	const int BUCKET_SIZE = 100;

	//max particles 
	const double MAX_PARTICLES = 1000000;

	//current particle count
	int m_particleCount;

	FPS fps;

public:
	//generate "grid"
	void GenerateBuckets();

	//generate starting particles
	void GenerateParticles();

	//get particle count
	int GetParticleCount();

	//detect collisions
	/*bool HasParticleCollided( std::shared_ptr<Bucket> _owner, std::list<std::shared_ptr<Particle>> _otherParticles );*/

	//draw
	void Draw();

	void UpdateOwner( std::shared_ptr<Particle> _particle );
	
	//Empty Buckets
	//void EmptyBuckets( std::vector<std::shared_ptr<Bucket>> &_buckets );

	////Repopulate buckets with current particles
	//void RefillBuckets();

	//run application 
	void Run();

	Application();
	~Application();
};

#endif;
