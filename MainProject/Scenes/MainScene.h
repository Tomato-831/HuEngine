#pragma once

#include "../HuEngine.h"
#include "../Classes/BG.h"
#include "../Classes/Player.h"
#include "../Classes/Same.h"
#include "../Classes/PlayerDate.h"
#include "../Classes/PlayerLife.h"
#include "../Classes/Black.h"


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
	//Player_R  player_R;
	//Player_L  player_L;
	Same      same_;
	Same      same1_;
	Same      same2_;
	Same      same3_;


	Black     black_;
	Black     black2_;
	Black     black3_;
	Black     black4_;
	Black     black5_;
	Black     black6_;
	Black     black7_;
	Black     black8_;
	Black     black9_;
	Black     black10_;
	Black     black11_;
	Black     black12_;
	Black     black13_;
		        





	HE::Sprite sprite_;

	PlayerData player_data_;
	PlayerLife player_life_;


};