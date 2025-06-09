//
// GameOver.cpp
//

#include "GameOver.h"
#include "../InputSystem.h"

using namespace HE;

// initialize member variables.
GameOver::GameOver()
{

}

// rearrange UI to fit the size.
void GameOver::ResizeLayout()
{
    Scene::ResizeLayout();



}

// load resources.
void GameOver::Load()
{

    sprite_gameover_ = Sprite("End2.PNG");
    RenderingPath->AddSprite(&sprite_gameover_, -100);

    Scene::Load();
}

// initialize a variables.
void GameOver::Initialize()
{
    sprite_gameover_.params.siz = sprite_gameover_.GetTextureSize();
    sprite_gameover_.params.siz.x = RenderingPath->GetLogicalWidth();
    sprite_gameover_.params.pos = Math::Vector2(0.0f, 0.0f);
}

// releasing resources required for termination.
void GameOver::Terminate()
{

}

// updates the scene.
void GameOver::Update(float deltaTime)
{
    if (InputSystem.Keyboard.isPressed.Enter)
        SceneManager.SetNextScene(NextScene::Title);


    Scene::Update(deltaTime);
}
