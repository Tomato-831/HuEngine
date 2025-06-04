#pragma once

#include "../HuEngine.h"
#include "../Classes/BG.h"
#include "../Classes/Player.h"
#include "../Classes/Player_R.h"
#include "../Classes/Player_L.h"
#include "../Classes/Redcar.h"
#include "../Classes/PlayerDate.h"
#include "../Classes/PlayerLife.h"


class MainScene : public HE::Scene
{
public:
	MainScene();
	virtual ~MainScene() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:
	BG        bg_;
	Player    player_;
	Player_R  player_R;
	Player_L  player_L;
	Redcar    redcar_;

	HE::Sprite sprite_;

	PlayerData player_data_;
	PlayerLife player_life_;


};