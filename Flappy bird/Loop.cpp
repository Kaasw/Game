#include"Loop.h"

GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	Wing = NULL;
	GameState = false;
	Dead = true;
	color = { 255,255,255,1 };
	p.setSrc(0, 0, 30, 40);
	p.setDest(10, 10, 30, 40);
	Above1.setSrc(0, 0, 320, 52);
	Above1.setDest(400, -200, 400, 52);
	Below1.setSrc(0, 0, 320, 52);
	Below1.setDest(400, 350, 400, 52);
	Above2.setSrc(0, 0, 320, 52);
	Above2.setDest(700, -200, 400, 52);
	Below2.setSrc(0, 0, 320, 52);
	Below2.setDest(700, 350, 400, 52);
	Above3.setSrc(0, 0, 320, 52);
	Above3.setDest(1000, -200, 400, 52);
	Below3.setSrc(0, 0, 320, 52);
	Below3.setDest(1000, 350, 400, 52);
}


bool GameLoop::getGameState()
{
	return GameState;
}

bool GameLoop::getDead()
{
	return Dead;
}

void GameLoop::Intialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Flappy bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				
			}
			std::cout << "Succeeded!" << std::endl;
			GameState = true;
			p.CreateTexture("Images/Chim/Bird1.png", renderer);
			p.CreateTexture1("Images/Chim/Bird2.png", renderer);
			p.CreateTexture2("Images/Chim/Bird3.png", renderer);
			b.CreateTexture("Images/Background/Background.png", renderer);
			c.CreateTexture("Images/Background/Over.png", renderer);
			Above1.CreateTexture("Images/Pipes/Above.png", renderer);
			Below1.CreateTexture("Images/Pipes/Below.png", renderer);
			Above2.CreateTexture("Images/Pipes/Above.png", renderer);
			Below2.CreateTexture("Images/Pipes/Below.png", renderer);
			Above3.CreateTexture("Images/Pipes/Above.png", renderer);
			Below3.CreateTexture("Images/Pipes/Below.png", renderer);
			Wing = Mix_LoadWAV("Sounds/wing.wav");
			

			
			
		}
		else
		{
			std::cout << "Not created!" << std::endl;
		}
	}
	else
	{
		std::cout << "window not created!" << std::endl;
	}
}



void GameLoop::Event()
{
	p.GetJumpTime();
	SDL_PollEvent(&event1);
	if (event1.type == SDL_QUIT)
	{
		GameState = false;
	}
	if (event1.type == SDL_KEYDOWN)
	{
		if (event1.key.keysym.sym == SDLK_UP)
		{
			
			Mix_PlayChannel(-1,Wing, 0);

			if (!p.JumpState())
			{
				p.Jump();
			}
			else
			{
				p.Gravity();
			}
		}
	}
	else
	{
		p.Gravity();
	}
}


void GameLoop::Update()
{
	Above1.Pipelogic1();
	Below1.Pipelogic2();
	Above2.Pipelogic3();
	Below2.Pipelogic4();
	Above3.Pipelogic5();
	Below3.Pipelogic6();
	
}

void GameLoop::CollisionDetect()
{
	if (CollisionManager::CheckCollision(&p.getDest(), &Above1.getDest()) || CollisionManager::CheckCollision(&p.getDest(), &Below1.getDest()) ||
		CollisionManager::CheckCollision(&p.getDest(), &Above2.getDest()) || CollisionManager::CheckCollision(&p.getDest(), &Below2.getDest()) ||
		CollisionManager::CheckCollision(&p.getDest(), &Above3.getDest()) || CollisionManager::CheckCollision(&p.getDest(), &Below3.getDest()))
	{
		Dead = false;
	}



}



void GameLoop::MainMenu()
{
	menu.Initialize(renderer);
	while (!menu.getClicked())
	{
		if (menu.EventHandling(event1) == -1)
		{
			GameState = false;
			break;
		}
		SDL_RenderClear(renderer);
		menu.Render(renderer);
		SDL_RenderPresent(renderer);
	}
}

void GameLoop::Render()
{
	if (Dead == true)
	{
		SDL_RenderClear(renderer);
		b.Render(renderer);
		p.Render(renderer);
		Above1.PipeRender(renderer);
		Below1.PipeRender(renderer);
		Above2.PipeRender(renderer);
		Below2.PipeRender(renderer);
		Above3.PipeRender(renderer);
		Below3.PipeRender(renderer);
		SDL_RenderPresent(renderer);
	}
	else
	{
		
		SDL_Delay(100);
		c.Render(renderer);
		SDL_RenderPresent(renderer);
		
	}
	
}

void GameLoop::Clear()
{
	Mix_FreeChunk(Wing);
	Wing = NULL;
	Mix_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}