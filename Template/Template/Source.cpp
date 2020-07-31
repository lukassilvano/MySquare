#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "SDLGame.h"

using namespace std;

int main(int argc, char** argv)
{

	SDLGame game;

	if (game.CreateGame() != 0)
	{
		cout << "Erro ao criar jogo" << endl;
	}
	else
	{
		srand(time(0));
		game.Run();
	}
	game.Destroy();

	return 0;
}
