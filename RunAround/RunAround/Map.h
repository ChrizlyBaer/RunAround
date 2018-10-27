#pragma once

#ifndef _MAP_H
#define _MAP_H

#include <SDL.h>

class Map {
	private:
		int position_x;
		int position_y;
		
		SDL_Texture *map_texture;

	public:
		Map();
		Map( int position_x, int position_y, SDL_Renderer *main_renderer );
		~Map();

		// Getter
		int GetPosX() const;
		int GetPosY() const;

		// Setter
		void SetPosX(int position_x);
		void SetPosY(int position_y);
		void AddPosX(int add_x);
		void AddPosY(int add_y);

		// Functions
		void update();
		void render( SDL_Renderer *main_renderer, SDL_Rect *rect);
};

#endif // !_MAP_H