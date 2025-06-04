#pragma once

#include "../HuEngine.h"

class GameOver : public HE::Scene
{
public:
	GameOver();
	virtual ~GameOver() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:
	HE::Sprite sprite_gameover_;


};
