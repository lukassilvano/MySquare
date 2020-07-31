#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Quadrado
{
public:
	// x= 280 y = 50
	int x = 320, y = 50;
	int fome = 50, diversão = 100, sujeira, vida = 500;

	SDL_Texture* texturePetFeliz;
	SDL_Texture* texturePetTriste;
	SDL_Texture* texturePetRaiva;
	SDL_Texture* texturePetSujo;
	SDL_Texture* textureBanho;
	SDL_Texture* textureBrinquedo;
	SDL_Texture* textureComida;
	SDL_Texture* textureMorto;

	void IndicadorFome(int tempo);
	void IndicadorDiversão(int tempo);
	void IndicadorSujeira(int tempo);
	void IndicadorVida(int tempo);
	void DrawExpressão(SDL_Renderer* r);
	void DrawIcones(SDL_Renderer* r);
	void ProcessInput(SDL_Event);

	Quadrado();
	~Quadrado();
};

