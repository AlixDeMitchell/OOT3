#include "Application.h"

Application::Application()
{
	m_running = true;
	m_particleCount = m_allParticles.size();
	GenerateBuckets();
	GenerateParticles();

	m_particleCount = 2000;
}

void Application::GenerateBuckets()
{
	int numBuckets = ( m_SDLmanager.SCREEN_W / 100 ) * ( m_SDLmanager.SCREEN_H / 100 );
	for ( int i = 0; i < numBuckets; i++ )
	{
		m_buckets.push_back( std::make_shared<Bucket>(i) );

	}
}

void Application::GenerateParticles()
{
	for ( int i = 0; i < MAX_PARTICLES; i++ )
	{
		//randomly roll starting x and y position coords
		int x = rand() % m_SDLmanager.SCREEN_W;
		int y = rand() % m_SDLmanager.SCREEN_H;

		int bucketX = x / BUCKET_SIZE;
		int bucketY = y / BUCKET_SIZE;

		std::shared_ptr<Particle> newParticle = std::make_shared<Particle>( x, y );

		// particles spawn and go in the right bucket, based on their coords and bucket coords
		m_buckets.at( ( bucketY * 19 ) + bucketX )->AddParticle( newParticle );

		//also add the new particles to the vector for drawing
		m_allParticles.push_back( newParticle );

		newParticle->SetOwner(m_buckets.at((bucketY * 19) + bucketX));
	}
}

int Application::GetParticleCount()
{
	return m_particleCount;
}

void Application::UpdateOwner( std::shared_ptr<Particle> _particle )
{
	//check if owner exists
	std::shared_ptr<Bucket> currentOwner = _particle->GetOwner().lock();

	if ( currentOwner == nullptr )
	{
		return;
	}

	_particle->Rehash(m_buckets);

	std::shared_ptr<Bucket> newOwner = _particle->GetOwner().lock;

	if ( currentOwner == newOwner )
	{
		return;
	}

	else
	{
		if ( _particle->GetIter() != currentOwner->GetList().end )
		{
			currentOwner->GetList.erase( _particle->GetIter() );
			newOwner->GetList.push_back( _particle );
		}
	}



	//std::shared_ptr<Bucket> incoming_bucket = _currentBucket.lock();
	//std::shared_ptr<Bucket> existing_bucket = m_owner.lock();

	//if ( !existing_bucket )
	//{

	//	m_owner = _currentBucket;

	//	std::shared_ptr<Particle> thisShared = shared_from_this();
	//	incoming_bucket->GetList().push_back( thisShared );

	//		m_iter = std::find(
	//			incoming_bucket->GetList().begin(),
	//			incoming_bucket->GetList().end(),
	//			shared_from_this() );

	//		return;
	//}

	//else if ( incoming_bucket/*->GetIndex()*/ == existing_bucket/*->GetIndex()*/ )
	//{
	//	return;
	//}

	//else if ( incoming_bucket != existing_bucket )
	//{
	//	//erase this particle from current owner particle list
	//   // add this particle to new owner particle list
	//  //	m_owner = _owner;
	//	if ( m_iter != existing_bucket->GetList().end() )
	//	{
	//		existing_bucket->GetList().erase( m_iter );

	//		incoming_bucket->GetList().push_back( shared_from_this() );

	//		m_iter = std::find(
	//			incoming_bucket->GetList().begin(),
	//			incoming_bucket->GetList().end(),
	//			shared_from_this() );
	//	}
	//}

}
//bool Application::HasParticleCollided( std::shared_ptr<Bucket> _owner, std::list<std::shared_ptr<Particle>> _otherParticles )
//{
//	return false;
//}

void Application::Draw()
{
	for ( int i = 0; i < m_particleCount; i++ )
	{
		SDL_SetRenderDrawColor( m_SDLmanager.GetRenderer(), rand() % 255, rand() % 255, rand() % 255, rand() % 255 );
		SDL_RenderDrawRect( m_SDLmanager.GetRenderer(), &m_allParticles.at( i )->GetRect() );
	}
}

//void Application::EmptyBuckets( std::vector<std::shared_ptr<Bucket>> &_buckets )
//{
//	//clear list
//	//for_each( _buckets.begin(), _buckets.end(), _buckets->ClearList() );
//
//	for ( size_t i = 0; i < _buckets.size(); i++ )
//	{
//		_buckets.at( i )->ClearList();
//	}
//}

//void Application::RefillBuckets()
//{
//	//refill list
//}

void Application::Run()
{
	

	SDL_Event e;
	bool quit = false;

	while ( !m_SDLmanager.GetKeyboard()[ SDL_SCANCODE_ESCAPE ] && !quit)
	{
		fps.Update();

		quit = m_SDLmanager.HandleEvents();

		if ( m_SDLmanager.GetKeyboard()[ SDL_SCANCODE_UP ] )
		{
			m_particleCount += 50;
			if ( m_particleCount > MAX_PARTICLES )
			{
				m_particleCount = MAX_PARTICLES;
			}

			std::cout << "Particles: " << m_particleCount << "\n";
		}

		if ( m_SDLmanager.GetKeyboard()[ SDL_SCANCODE_DOWN ] )
		{
			m_particleCount -= 50;
			if ( m_particleCount < 0 )
			{
				m_particleCount = 0;
			}

			std::cout << "Particles: " << m_particleCount << "\n";
		}

		// set color, clear screen
		SDL_SetRenderDrawColor( m_SDLmanager.GetRenderer(), 194, 171, 252, 255 );
		SDL_RenderClear( m_SDLmanager.GetRenderer() );

		SDL_SetRenderDrawColor( m_SDLmanager.GetRenderer(), 0, 0, 0, 255 );

		for ( int i = 0; i < m_particleCount; i++ )
		{
			m_allParticles.at( i )->Update();
		}

		Draw();

		SDL_RenderPresent( m_SDLmanager.GetRenderer() );
	}
}



Application::~Application()
{
}
