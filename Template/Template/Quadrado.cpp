#include "Quadrado.h"


Quadrado::Quadrado()
{
}


Quadrado::~Quadrado()
{
}

void Quadrado::IndicadorFome(int tempo)
{
	if (tempo % 20 == 0)
	{
		fome++;
	}

}

void Quadrado::IndicadorDiversão(int tempo)
{
	if (tempo % 20 == 0)
	{
		diversão--;
	}
}

void Quadrado::IndicadorSujeira(int tempo)
{
	if (tempo % 20 == 0)
	{
		sujeira++;
	}
}

void Quadrado::IndicadorVida(int tempo)
{
	if (tempo % 400 == 0)
	{
		vida--;
	}
	if (diversão < 0)
	{
		vida--;
	}
	if (fome <= 0 || fome >= 100)
	{
		vida--;
	}
	if (sujeira > 100)
	{
		vida--;
	}
}

void Quadrado::DrawExpressão(SDL_Renderer* r)
{
	if (vida <= 0)
	{
		SDL_Rect morto = { 0, 0, 250, 224 };
		SDL_Rect morto2 = { x, y, 200, 200 };
		SDL_RenderCopy(r, textureMorto, &morto, &morto2);
	}
	else
	{
		if (sujeira > 70)
		{
			SDL_Rect sujo = { 0, 0, 599, 598 };
			SDL_Rect sujo2 = { x, y, 200, 200 };
			SDL_RenderCopy(r, texturePetSujo, &sujo, &sujo2);
		}
		else
		{
			if (diversão >= 50)
			{
				SDL_Rect feliz = { 0, 0, 599, 598 };
				SDL_Rect feliz2 = { x, y, 200, 200 };
				SDL_RenderCopy(r, texturePetFeliz, &feliz, &feliz2);
			}
			if (diversão < 50)
			{
				SDL_Rect triste = { 0, 0, 599, 598 };
				SDL_Rect triste2 = { x, y, 200, 200 };
				SDL_RenderCopy(r, texturePetTriste, &triste, &triste2);
			}
			if (diversão < 20)
			{
				SDL_Rect raiva = { 0, 0, 599, 598 };
				SDL_Rect raiva2 = { x, y, 200, 200 };
				SDL_RenderCopy(r, texturePetRaiva, &raiva, &raiva2);
			}
		}
		if (fome <= 40)
		{
			if (sujeira > 50)
			{
				SDL_Rect sujo = { 0, 0, 599, 598 };
				SDL_Rect sujo2 = { x - 20, y, 230, 230 };
				SDL_RenderCopy(r, texturePetSujo, &sujo, &sujo2);
			}
			else
			{
				if (diversão >= 50)
				{
					SDL_Rect feliz = { 0, 0, 599, 598 };
					SDL_Rect feliz2 = { x - 20, y, 230, 230 };
					SDL_RenderCopy(r, texturePetFeliz, &feliz, &feliz2);
				}
				if (diversão < 50)
				{
					SDL_Rect triste = { 0, 0, 599, 598 };
					SDL_Rect triste2 = { x - 20, y, 230, 230 };
					SDL_RenderCopy(r, texturePetTriste, &triste, &triste2);
				}
				if (diversão < 20)
				{
					SDL_Rect raiva = { 0, 0, 599, 598 };
					SDL_Rect raiva2 = { x - 20, y, 230, 230 };
					SDL_RenderCopy(r, texturePetRaiva, &raiva, &raiva2);
				}
			}
		}
		if (fome <= 30)
		{
			if (sujeira > 50)
			{
				SDL_Rect sujo = { 0, 0, 599, 598 };
				SDL_Rect sujo2 = { x - 40, y, 250, 250 };
				SDL_RenderCopy(r, texturePetSujo, &sujo, &sujo2);
			}
			else
			{
				if (diversão >= 50)
				{
					SDL_Rect feliz = { 0, 0, 599, 598 };
					SDL_Rect feliz2 = { x - 40, y, 250, 250 };
					SDL_RenderCopy(r, texturePetFeliz, &feliz, &feliz2);
				}
				if (diversão < 50)
				{
					SDL_Rect triste = { 0, 0, 599, 598 };
					SDL_Rect triste2 = { x - 40, y, 250, 250 };
					SDL_RenderCopy(r, texturePetTriste, &triste, &triste2);
				}
				if (diversão < 20)
				{
					SDL_Rect raiva = { 0, 0, 599, 598 };
					SDL_Rect raiva2 = { x - 40, y, 250, 250 };
					SDL_RenderCopy(r, texturePetRaiva, &raiva, &raiva2);
				}
			}
		}
		if (fome <= 20)
		{
			if (sujeira > 50)
			{
				SDL_Rect sujo = { 0, 0, 599, 598 };
				SDL_Rect sujo2 = { x-40, y, 280, 280 };
				SDL_RenderCopy(r, texturePetSujo, &sujo, &sujo2);
			}
			else
			{
				if (diversão >= 50)
				{
					SDL_Rect feliz = { 0, 0, 599, 598 };
					SDL_Rect feliz2 = { x - 40, y, 280, 280 };
					SDL_RenderCopy(r, texturePetFeliz, &feliz, &feliz2);
				}
				if (diversão < 50)
				{
					SDL_Rect triste = { 0, 0, 599, 598 };
					SDL_Rect triste2 = { x - 40, y, 280, 280 };
					SDL_RenderCopy(r, texturePetTriste, &triste, &triste2);
				}
				if (diversão < 20)
				{
					SDL_Rect raiva = { 0, 0, 599, 598 };
					SDL_Rect raiva2 = { x - 40, y, 280, 280 };
					SDL_RenderCopy(r, texturePetRaiva, &raiva, &raiva2);
				}
			}
		}
		if (fome <= 0)
		{
			if (sujeira > 50)
			{
				SDL_Rect sujo = { 0, 0, 599, 598 };
				SDL_Rect sujo2 = { x-80, 5, 330, 330 };
				SDL_RenderCopy(r, texturePetSujo, &sujo, &sujo2);
			}
			else
			{
				if (diversão >= 50)
				{
					SDL_Rect feliz = { 0, 0, 599, 598 };
					SDL_Rect feliz2 = { x - 80, 5, 330, 330 };
					SDL_RenderCopy(r, texturePetFeliz, &feliz, &feliz2);
				}
				if (diversão < 50)
				{
					SDL_Rect triste = { 0, 0, 599, 598 };
					SDL_Rect triste2 = { x - 80, 5, 330, 330 };
					SDL_RenderCopy(r, texturePetTriste, &triste, &triste2);
				}
				if (diversão < 20)
				{
					SDL_Rect raiva = { 0, 0, 599, 598 };
					SDL_Rect raiva2 = { x - 80, 5, 330, 330 };
					SDL_RenderCopy(r, texturePetRaiva, &raiva, &raiva2);
				}
			}
		}
	}
}

void Quadrado::DrawIcones(SDL_Renderer* r)
{
	SDL_Rect fome = { 0, 0, 600, 600 };
	SDL_Rect fome2 = { 50, 330, 200, 200 };
	SDL_RenderCopy(r, textureComida, &fome, &fome2);

	SDL_Rect banho = { 0, 0, 360, 360 };
	SDL_Rect banho2 = { 300, 315, 230, 230 };
	SDL_RenderCopy(r, textureBanho, &banho, &banho2);

	SDL_Rect brinquedo = { 0, 0, 1969, 1969 };
	SDL_Rect brinquedo2 = { 550, 330, 200, 200 };
	SDL_RenderCopy(r, textureBrinquedo, &brinquedo, &brinquedo2);
}

void Quadrado::ProcessInput(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEMOTION)
	{
		if (e.button.button == (SDL_BUTTON_LEFT))
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);
			if ((x > 50 && x < 250) && (y > 330 && y < 530))
			{
				fome--;
				vida++;
			}
			if ((x > 300 && x < 530) && (y > 315 && y < 545))
			{
				sujeira-= 5;
			}
			if ((x > 550 && x < 750) && (y > 330 && y < 530))
			{
				diversão++;
				sujeira++;
			}
		}
	}
}