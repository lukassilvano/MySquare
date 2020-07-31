#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include "Quadrado.h"

#define MENU 0
#define GAMEPLAY 1
using namespace std;

class SDLGame
{
public:
	SDLGame();
	~SDLGame();
		
	int CreateGame();
	void Destroy();
	void Run();
	
private:
	SDL_Surface* surface;
	SDL_Texture* textureFeliz;
	SDL_Texture* textureTriste;
	SDL_Texture* textureRaiva;
	SDL_Texture* textureSujo;
	SDL_Texture* textureFundo;
	SDL_Texture* textureStart;
	SDL_Texture* textureQuit;
	SDL_Texture* textureLogo1;
	SDL_Texture* textureLogo2;

	double deltaTime;
	const int windows_width = 860;
	const int windows_height = 600;
	bool quit;
	int estadoJogo, contador;
	void Update();
	void ProcessInput();
	void DesenhaFundo();
	void Frames();
	void DrawMenu();
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Event e;
	Quadrado Quad;
};

int SDLGame::CreateGame()
{
	//Inicializa a tela do jogo e todas suas imagens apenas uma vez
	win = SDL_CreateWindow("Nome da janela", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windows_width, windows_height, 0);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

	surface = IMG_Load("../../ASSET/HappySquare.png");
	Quad.texturePetFeliz = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/SadSquare.png");
	Quad.texturePetTriste = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/AngrySquare.png");
	Quad.texturePetRaiva = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/DirtySquare.png");
	Quad.texturePetSujo = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/fundo.jpg");
	textureFundo = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/Start.png");
	textureStart = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/quit.png");
	textureQuit = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/Logo1.png");
	textureLogo1 = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/toy.png");
	Quad.textureBrinquedo = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/food.png");
	Quad.textureComida = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/bath.png");
	Quad.textureBanho = SDL_CreateTextureFromSurface(ren, surface);

	surface = IMG_Load("../../ASSET/tumulo.png");
	Quad.textureMorto = SDL_CreateTextureFromSurface(ren, surface);

	estadoJogo = MENU;
	return 0;
}

void SDLGame::DrawMenu()
{
	SDL_Rect start = {0, 0, 333, 107};
	SDL_Rect start2 = { 310, 350, 200, 55 };
	SDL_RenderCopy(ren, textureStart, &start, &start2);

	SDL_Rect quit = { 0, 0, 289, 107 };
	SDL_Rect quit2 = { 335, 450, 148.5, 55 };
	SDL_RenderCopy(ren, textureQuit, &quit, &quit2);

	SDL_Rect logoI = { 0, 0, 382, 382 };
	SDL_Rect logo1 = { 280, 50, 270, 270 };
	SDL_RenderCopy(ren, textureLogo1, &logoI, &logo1);
	
}

void SDLGame::Frames()
{
	int fps = 60;
	int fpsMill = 1000 / fps;
	int currentFrameTime;
	double startTime = SDL_GetTicks();
	currentFrameTime = SDL_GetTicks();
	int pastTime = SDL_GetTicks() - currentFrameTime;
	if (fpsMill > pastTime)
		SDL_Delay(fpsMill - pastTime);
	double endTime = SDL_GetTicks();
	deltaTime = (endTime - startTime) / 1000;
}

void SDLGame::DesenhaFundo()
{
	SDL_Rect fnd1 = { 0, 0, 4757, 2676};
	SDL_RenderCopy(ren, textureFundo, &fnd1, 0);

}

void SDLGame::Update()
{
	contador++;
	cout << contador << endl;
}

void SDLGame::ProcessInput()
{
	//Pegando inputs
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)//Se evento de sair (clicou x)
		{
			quit = true;
		}
		if (estadoJogo == MENU)
		{
			if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEMOTION )
			{
				if (e.button.button == (SDL_BUTTON_LEFT))
				{
					//Get mouse position
					int x, y;
					SDL_GetMouseState(&x, &y);
					if ((x > 310 && x < 510) && (y > 350 && y < 405))
					{
						estadoJogo = GAMEPLAY;
					}
					if ((x > 335 && x < 483.5) && (y > 450 && y < 505))
					{
						quit = true;
					}
				}
			}
		}
	}
}

void SDLGame::Run()
{
	while (!quit)
	{
		if (estadoJogo == MENU)
			{
				DesenhaFundo();
				DrawMenu();
				ProcessInput();
				SDL_RenderPresent(ren);
				
			}
		else if (estadoJogo == GAMEPLAY)
			{
				Update();
				Frames();
				ProcessInput();
				Quad.ProcessInput(e);
				DesenhaFundo();
				Quad.DrawExpressão(ren);
				Quad.DrawIcones(ren);
				Quad.IndicadorDiversão(contador);
				Quad.IndicadorFome(contador);
				Quad.IndicadorSujeira(contador);
				Quad.IndicadorVida(contador);
				SDL_RenderPresent(ren);
			}
	}
}

void SDLGame::Destroy()
{
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
}

SDLGame::SDLGame(){}

SDLGame::~SDLGame()
{
}