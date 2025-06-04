#pragma once


#include "../HuEngine.h"
#include "../Classes/BG.h"

class Player {
public:
	void Load();
	void Initialize();
	void Update();
	void OnCollision();
	HE::Math::Rectangle GetCollision();
	void SetInitialPosition();

private:
	HE::Sprite sprite_;

	HE::Sprite collision_sprite_;
	HE::Sprite sprite_params;
};