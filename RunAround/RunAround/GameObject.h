#pragma once

#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SDL.h>

class GameObject {
private:
	SDL_Rect rect;
	SDL_Texture *texture;

public:
	GameObject();
	GameObject(int position_x, int position_y, int width, int height, SDL_Renderer *main_renderer, const char *file);
	~GameObject();
	/*
	// Getter
	int GetPosX() const;
	int GetPosY() const;
	int GetWidth() const;
	int GetHeight() const;

	// Setter
	void SetPosX(int position_x);
	void SetPosy(int position_x);
	void SetWidth(int widht);
	void SetHeight(int height);

	// Functions
	virtual void update();
	virtual void render();
	*/
};

#endif // !_GAMEOBJECT_H
