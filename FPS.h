#ifndef _FPS_
#define _FPS_

#include <SDL.h>

class FPS
{
private:

	Uint32 m_timeNow;
	Uint32 m_timePrev;
	Uint32 m_timeDiff;

	float m_deltaTime;
	float m_timer;

	int m_frameCount;

public:
	FPS();
	~FPS();

	void Update();


};

#endif