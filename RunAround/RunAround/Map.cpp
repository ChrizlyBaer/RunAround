#include "Map.h"

Map::Map() {
	Map::position_x = 0;
	Map::position_y = 0;
	Map::map_texture = NULL;
}


Map::Map(int position_x, int position_y, SDL_Renderer *main_renderer) {
	// for testing
	SDL_Surface *temp_surface = SDL_LoadBMP("Assets\\testmap.bmp");
	Map::map_texture = SDL_CreateTextureFromSurface(main_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	Map::position_x = position_x;
	Map::position_y = position_y;
}


Map::~Map() {
	SDL_DestroyTexture(map_texture);
}

// Getter
int Map::GetPosX() const {
	return Map::position_x;
}

int Map::GetPosY() const {
	return Map::position_y;
}

// Setter
void Map::SetPosX(int position_x) {
	Map::position_x = position_x;
}

void Map::SetPosY(int position_y) {
	Map::position_y = position_y;
}

void Map::AddPosX(int add_x) {
	Map::position_x += (Map::position_x + add_x >= 0) ? add_x : 0;
}

void Map::AddPosY(int add_y) {
	Map::position_y += (Map::position_y + add_y >= 0) ? add_y : 0;
}

// functions
void Map::update() {

}

void Map::render( SDL_Renderer *main_renderer, SDL_Rect *rect) {
	SDL_Rect r;
	r.x = position_x;
	r.y = position_y;
	// to be defined or add a scale?
	r.h = 64*2;
	r.w = 64*2;
	SDL_RenderCopy(main_renderer, map_texture, &r, rect);
}