#ifndef		__H__PLAYER__
#define		__H__PLAYER__

#include "LEAGUE/common_data_structures.h"

class Player : public Drawable, public Updateable {
	public:
		Player();
		~Player();
		void draw(SDL_Renderer* renderer) override;
		void update(double delta) override;

	private:
		int x_vel;
		int y_vel;
};



#endif
