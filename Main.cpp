#include <iostream>
#include <SDL.h>
#include <time.h>
#include "Application.h"



int main( int argc, char* argv[] )
{
	srand( time( 0 ) );
	
	Application app;

	app.Run();
	
	system("PAUSE");
	return 0;
}



