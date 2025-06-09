//
// Title.cpp
//

#include "Title.h"
#include "../InputSystem.h"

using namespace HE;

// initialize member variables.
Title::Title()
{

}

// rearrange UI to fit the size.
void Title::ResizeLayout()
{
    Scene::ResizeLayout();



}

// load resources.
void Title::Load()
{

    sprite_title_ = Sprite("title2.png");
    RenderingPath->AddSprite(&sprite_title_, -50);

    Scene::Load();
}

// initialize a variables.
void Title::Initialize()
{
    sprite_title_.params.siz = sprite_title_.GetTextureSize();
    sprite_title_.params.siz.x = RenderingPath->GetLogicalWidth();
    sprite_title_.params.pos = Math::Vector2(0.0f, 0.0f);
    
}

// releasing resources required for termination.
void Title::Terminate()
{

}

// updates the scene.
void Title::Update(float deltaTime)
{
    if (InputSystem.Keyboard.isPressed.Space)
        SceneManager.SetNextScene(NextScene::MainScene, 1.0f, Color(100, 100, 255));


    Scene::Update(deltaTime);
}
