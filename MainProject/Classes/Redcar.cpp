//
//Redcar.cpp
//

#include"Redcar.h"

using namespace HE;



void Redcar::Load()
{
	sprite_ = Sprite("same.png");
	RenderingPath->AddSprite(&sprite_, -50);

}

void Redcar::Initialize(Math::Vector2 initial)
{
	sprite_.params.siz = Math::Vector2(100.0f, 46.0f);
	sprite_.params.pos = initial;
	//sprite_.params.enableDrawRect(Rectf(
	//	0, 0, sprite_.params.siz.x, sprite_.params.siz.y
	//));

}

void Redcar::Update()
{
	sprite_.params.pos.x += 400.0f * Time.deltaTime;
	if (sprite_.params.pos.x >= 1280.0f)
		sprite_.params.pos.x = -88.0f;
	sprite_.params.enableMirror();
}
//�����蔻��
Math::Rectangle Redcar::GetCollision()
{
	Math::Rectangle collision;
	collision.x =      (long)sprite_.params.pos.x;
	collision.y =      (long)sprite_.params.pos.y;
	collision.width =  (long)sprite_.params.siz.x;
	collision.height = (long)sprite_.params.siz.y;

	return collision;
}
void Redcar::OnCollision()
{

	
}