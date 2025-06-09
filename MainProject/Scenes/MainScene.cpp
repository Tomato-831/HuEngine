//
// MainScene.cpp
//

#include "MainScene.h"
#include "../InputSystem.h"

using namespace HE;

// initialize member variables.
MainScene::MainScene()
{

}

// rearrange UI to fit the size.
void MainScene::ResizeLayout()
{
	Scene::ResizeLayout();



}

// load resources.
void MainScene::Load()
{
	bg_.      Load();
	player_.  Load();

	same_.    Load();
	same1_.   Load();
	same2_.   Load();
	same3_.   Load();

	black_.   Load();
	black2_.  Load();
	black3_.  Load();
	black4_.  Load();
	black5_.  Load();
	black6_.  Load();
	black7_.  Load();
	black8_.  Load();
	black9_.  Load();
	black10_. Load();
	black11_. Load();
	black12_. Load();
	black13_. Load();






	player_data_.Load();
	player_life_.Load();

	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	bg_.       Initialize();
	player_.   Initialize();

	same_.     Initialize(Math::Vector2(-88.0f * 1.0f, 100.0f));
	same1_.    Initialize(Math::Vector2(-88.0f * 1.0f, 200.0f));
    same2_.    Initialize(Math::Vector2(-88.0f * 1.0f, 400.0f));
	same3_.    Initialize(Math::Vector2(-88.0f * 1.0f, 660.0f));

	black_.    Initialize(Math::Vector2(320.0f,  0.0f ));
	black2_.   Initialize(Math::Vector2(320.0f, 202.0f));
	black3_.   Initialize(Math::Vector2(320.0f, 404.0f));
	black4_.   Initialize(Math::Vector2(320.0f, 606.0f));
	black5_.   Initialize(Math::Vector2(640.0f, 240.0f));
	black6_.   Initialize(Math::Vector2(640.0f, 480.0f));
	black7_.   Initialize(Math::Vector2(960.0f,   0.0f));
	black8_.   Initialize(Math::Vector2(960.0f, 202.0f));
	black9_.   Initialize(Math::Vector2(960.0f, 404.0f));
	black10_.  Initialize(Math::Vector2(960.0f, 606.0f));

	black11_.  Initialize(Math::Vector2(  0.0f, 600.0f));

	black12_.  Initialize(Math::Vector2(  0.0f, 360.0f));
	black13_.  Initialize(Math::Vector2(  0.0f,  80.0f));

	



	player_data_.Initialize();
	player_life_.Initialize();


	
}

// releasing resources required for termination.
void MainScene::Terminate()
{

}

// updates the scene.
void MainScene::Update(float deltaTime)
{
	bg_.       Update();
	player_.   Update();

	same_.     Update();
	same1_.    Update();
	same2_.    Update();
	same3_.    Update();

	black_.    Update();
	black2_.   Update();
	black3_.   Update();
	black4_.   Update();

	//black5_.   Update();
    //black6_.   Update();
	black7_.   Update();
	black8_.   Update();
	black9_.   Update();
	black10_.  Update();
	//black11_.  Update();
	//black12_.  Update();
	//black13_.  Update();



	//Math::Vector3 Player_position = player_.GetPosition();
	//if (player_position.y <= 0.0f) {


	//Õ“Ë”»’è
	Math::Rectangle player_collision = player_.GetCollision();
	Math::Rectangle same_collision = same_.GetCollision();
	Math::Rectangle black_collision = black_.GetCollision();
	if (player_collision.Intersects(same_collision)) {

		same_.OnCollision();
		black11_.OnCollision();
	}


	if (InputSystem.Keyboard.isPressed.E)
		SceneManager.SetNextScene(NextScene::GameOver, 2.0f, Color(255, 0, 0));


	if (InputSystem.Keyboard.isPressed.Right) {
		sprite_.params.pos.x += 4.0f;
		sprite_.params.drawRect.y = 192;  
		{
			if (InputSystem.Keyboard.isPressed.Left)
				sprite_.params.drawRect.y = 64;
			    sprite_.params.pos.x -= 4.0f;
		}

		if (InputSystem.Keyboard.isPressed.Down)
		{
			sprite_.params.drawRect.y = 0;
			sprite_.params.pos.y -= 4.0f;
		}

		if (InputSystem.Keyboard.isPressed.Up) {
			sprite_.params.drawRect.y = 128;
			sprite_.params.pos.y -= 4.0f;
		}
		Scene::Update(deltaTime);
	}
}
