#include "FPS.h"
#include <iostream>

FPS::FPS()
{
	m_timeNow = SDL_GetTicks();
	m_timePrev = 0;
	m_timeDiff = 0;

	m_deltaTime = 0.f;
	m_timer = 0.f;

	m_frameCount = 0;
}


FPS::~FPS()
{
}

void FPS::Update()
{
	m_timePrev = m_timeNow;
	m_timeNow = SDL_GetTicks();
	m_timeDiff = m_timeNow - m_timePrev;

	m_deltaTime = m_timeDiff / 1000.f;

	m_frameCount++;
	m_timer += m_deltaTime;

	if ( m_timer > 1.0f )
	{
		m_timer -= 1.0f;

		std::cout << "FPS: " << m_frameCount << "\n";

		m_frameCount = 0;
	}
}