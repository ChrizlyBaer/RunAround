// RunAround.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "RunAround.h"

#include <SDL.h>

int main( int argc, char **argv) {

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;


	Map *testmap;
	SDL_Rect map_rect;

	map_rect.x = map_rect.y = 0;
	map_rect.h = 400;
	map_rect.w = 600;

	bool running = true;

	SDL_Init(SDL_INIT_EVERYTHING);


	window = SDL_CreateWindow("RunArround", 100, 100, 800, 600, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0,0);
	testmap = new Map(0, 0, renderer);
	
	while (running) {
		SDL_RenderClear(renderer);
		/* Render */
		//SDL_RenderCopy(renderer, texture, &rect1, &rect2);
		testmap->render(renderer, &map_rect);
		
		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_RIGHT) 
				{
					testmap->AddPosX(1);
				}
				else if (event.key.keysym.sym == SDLK_LEFT)
				{
					testmap->AddPosX(-1);
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					testmap->AddPosY(-1);
				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					testmap->AddPosY(1);
				}
				break;
			}
			
		}
	}

	delete testmap;

	return 0;
}