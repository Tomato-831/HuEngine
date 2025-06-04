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
	player_R. Load();
	player_L. Load();
	redcar_.  Load();


	player_data_.Load();
	player_life_.Load();

	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	bg_.      Initialize();
	player_.  Initialize();
	player_R. Initialize();
	player_L. Initialize();
	redcar_.  Initialize(Math::Vector2(-88.0f *  1.0f, 145.0f));


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
	bg_.      Update();
	player_.  Update();
	player_R. Update();
	player_L. Update();
	redcar_.  Update();


	//Math::Vector3 Player_position = player_.GetPosition();
	//if (player_position.y <= 0.0f) {


	//Õ“Ë”»’è
	Math::Rectangle player_collision = player_.GetCollision();
	Math::Rectangle player_R_collision = player_R.GetCollision();
	Math::Rectangle player_L_collision = player_L.GetCollision();
	Math::Rectangle redcar_collision = redcar_.GetCollision();
	if (player_collision.Intersects(redcar_collision)) {
		player_.OnCollision();
		player_R.OnCollision();
		player_L.OnCollision();
		redcar_.OnCollision();
	}

	if (player_R_collision.Intersects(redcar_collision)) {
		player_.OnCollision();
		player_R.OnCollision();
		player_L.OnCollision();
		redcar_.OnCollision();
	}

	if (player_L_collision.Intersects(redcar_collision)) {
		player_.OnCollision();
		player_R.OnCollision();
		player_L.OnCollision();
		redcar_.OnCollision();
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
