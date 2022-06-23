#pragma once
#include "Object.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include<iostream>
class Background :public Object
{
private:
	int pipeDistance1 = 400;
	int pipeDistance2 = 700;
	int pipeDistance3 = 1000;
	int yPipe=400;
	int yPipe2 = 700;
	int yPipe3= 1000;
	int score1 = 0;
	int score2= 0;
	int score3 = 0;
	int score4 = 0;
	int score5 = 0;
	int score6 = 0;
	int total;
	
public:
	void Render(SDL_Renderer* ren);
	void PipeRender(SDL_Renderer* ren);
	void Pipelogic1();
	void Pipelogic2();
	void Pipelogic3();
	void Pipelogic4();
	void Pipelogic5();
	void Pipelogic6();
	void Total();
};
