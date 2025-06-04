#pragma once
#pragma once

#include "../HuEngine.h"

class PlayerLife {
public:
	void Load();
	void Initialize();

private:
	int score_;
	HE::SpriteFont score_headline_;
	HE::SpriteFont score_text_;
};
