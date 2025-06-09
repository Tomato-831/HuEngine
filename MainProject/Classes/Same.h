#pragma once

#include "../HuEngine.h"
#include <winnt.h>

class Same {
public:
	void Load();
	void Initialize(HE::Math::Vector2 initial);
	void Update();
	void OnCollision();
	HE::Math::Rectangle GetCollision();

	

private:

	HE::Sprite sprite_;
	HE::Sprite collision_sprite;

};