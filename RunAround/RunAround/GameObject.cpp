#include "GameObject.h"

GameObject::GameObject() {
	rect.x = rect.w = rect.h = rect.w = 0;
	texture = NULL;
}

GameObject::GameObject(int position_x, int position_y, int width, int height, SDL_Renderer *main_renderer, const char *file) {
	SDL_Surface *temp_surface = SDL_LoadBMP(file);
	texture = SDL_CreateTextureFromSurface(main_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	rect.x = position_x;
	rect.y = position_y;
	rect.w = width;
	rect.h = height;
}

GameObject::~GameObject() {
	SDL_DestroyTexture(texture);
}
/*
// Getter
int GameObject::GetPosX() const;
int GameObject::GetPosY() const;
int GameObject::GetWidth() const;
int GameObject::GetHeight() const;

// Setter
void GameObject::SetPosX(int position_x);
void GameObject::SetPosy(int position_x);
void GameObject::SetWidth(int widht);
void GameObject::SetHeight(int height);

// Functions
// virtual void update();	override
// virtual void render();	override
*/
