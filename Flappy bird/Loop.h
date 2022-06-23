#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include <string>
#include"Player.h"
#include"Background.h"
#include <SDL_ttf.h>
#include <Windows.h>
#include "Collision.h"
#include <SDL_mixer.h>
#include "MainMenu.h"
class GameLoop
{
private:
	Player p;
	Background b;
	Background c; 
	Background Above1;
	Background Below1;
	Background Above2;
	Background Below2;
	Background Above3;
	Background Below3;
	MainMenu menu;
	const int HEIGHT = 640;
	const int WIDTH = 800;
	bool GameState;
	bool Dead;
	SDL_Window* window;
	SDL_Event event1;
	SDL_Renderer* renderer;
	Mix_Chunk* Wing;
	SDL_Color color;
	
public:
	GameLoop();
	bool getGameState();
	bool getDead();
	void MainMenu();
	void Update();
	void CollisionDetect();
	void Intialize();
	void Event();
	void Render();
	void Clear();
};