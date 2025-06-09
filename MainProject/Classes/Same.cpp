//
//Redcar.cpp
//

#include"Same.h"
#include <wiBacklog.cpp>

using namespace HE;



void Same::Load()
{
	sprite_ = Sprite("sameL.png");
	RenderingPath->AddSprite(&sprite_, -50);

}

void Same::Initialize(Math::Vector2 initial)
{
	sprite_.params.siz = Math::Vector2(100.0f, 46.0f);
	sprite_.params.pos = initial;
	//sprite_.params.enableDrawRect(Rectf(
	//	0, 0, sprite_.params.siz.x, sprite_.params.siz.y
	//));


}

void Same::Update()
{
	

	sprite_.params.pos.x += 400.0f * Time.deltaTime;
	if (sprite_.params.pos.x >= 1280.0f)
		sprite_.params.pos.x = -88.0f;
	sprite_.params.enableMirror();

}
//“–‚½‚è”»’è
Math::Rectangle Same::GetCollision()
{
	Math::Rectangle collision;
	collision.x =      (long)sprite_.params.pos.x;
	collision.y =      (long)sprite_.params.pos.y;
	collision.width =  (long)sprite_.params.siz.x;
	collision.height = (long)sprite_.params.siz.y;

	return collision;
}
void Same::OnCollision()
{

	
}