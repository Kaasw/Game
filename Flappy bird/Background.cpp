#include "Background.h"

void Background::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::PipeRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}



void Background::Pipelogic1()
{
	yPipe--;
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		int Num1;
		Num1 = (rand() % 51)* -1- 200;
		setDest(yPipe, Num1, 400, 52);
		
	}
	
	if (yPipe == -50)
	{
		score1 += 1;
		yPipe = 1000;
		Pipelogic1();
	}
	
	
}

void Background::Pipelogic2()
{
	yPipe--;
	srand(time(NULL));
	for (int i = 0; i < 124; i++)
	{
		int Num2;
		Num2 = (rand() % 51)  + 350;
		setDest(yPipe, Num2, 400, 52);
		
	}
	if (yPipe == -50)
	{
		yPipe = 1000;
		Pipelogic2();
	}
}


void Background::Pipelogic3()
{
	yPipe2--;
	srand(time(NULL));
	for (int i = 0; i < 95; i++)
	{
		int Num1;
		Num1 = (rand() % 51) * -1 - 200;
		setDest(yPipe2, Num1, 400, 52);
		
	}
	if (yPipe2 == -50)
	{
		score3+=1;
		yPipe2 = 1000;
		Pipelogic3();
	}




}

void Background::Pipelogic4()
{
	yPipe2--;
	srand(time(NULL));
	for (int i = 0; i < 87; i++)
	{
		int Num2;
		Num2 = (rand() % 51) + 350;
		setDest(yPipe2, Num2, 400, 52);
		
	}
	if (yPipe2 == -50)
	{
		yPipe2 = 1000;
		Pipelogic4();
	}
}


void Background::Pipelogic5()
{
	yPipe3--;
	srand(time(NULL));
	for (int i = 0; i < 110; i++)
	{
		int Num1;
		Num1 = (rand() % 51) * -1 - 200;
		setDest(yPipe3, Num1, 400, 52);
		
	}
	if (yPipe3 == -50)
	{
		score5+=1;
		yPipe3 = 1000;
		Pipelogic5();
	}




}

void Background::Pipelogic6()
{
	yPipe3--;
	srand(time(NULL));
	for (int i = 0; i < 125; i++)
	{
		int Num2;
		Num2 = (rand() % 51) + 300;
		setDest(yPipe3, Num2, 400, 52);
		
	}
	if (yPipe3 == -50)
	{
		yPipe3 = 1000;
		Pipelogic6();
	}

	
}

