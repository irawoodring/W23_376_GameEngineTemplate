#include "player.h"
#include "LEAGUE/engine.h"

Player::Player(){
	x = 320;
	y = 240;
	x_vel = 0;
	y_vel = 0;
	loadImage("/Users/woodriir/Repos/leaguePlusPlus/assets/cat.png");
}

Player::~Player(){

}

void Player::update(double delta){
	auto events = Engine::getEvents();
	for(auto& event : events){
		if(event.type == SDL_KEYDOWN){
			switch(event.key.keysym.sym){
				case SDLK_w:
					y_vel -= 1;
					break;
				case SDLK_s:
					y_vel = y_vel + 1;
					break;
				case SDLK_a:
					x_vel = x_vel - 1;
					break;
				case SDLK_d:
					x_vel = x_vel + 1;
			}
			if(x_vel > 5){
				x_vel = 5;
			}
			if(y_vel > 5){
				y_vel = 5;
			}
			if(y_vel < -5){
				y_vel = -5;
			}
			if(x_vel < -5){
				x_vel = -5;
			}
		}
	}
	x = x + (x_vel * 100) * delta;
	y = y + (y_vel * 100) * delta; 
}

void Player::draw(SDL_Renderer* renderer){
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = rect.w;
	dest.h = rect.h;
	int result = SDL_RenderCopy(renderer, texture, NULL, &dest);
	if(result != 0){
		std::cout << SDL_GetError() << std::endl;
	}
}
