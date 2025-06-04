//
//Redcar.cpp
//

#include"Black.h"

using namespace HE;



void Black::Load()
{
	sprite_ = Sprite("same.png");
	RenderingPath->AddSprite(&sprite_, -50);

}

void Black::Initialize(Math::Vector2 initial)
{
	sprite_.params.siz = Math::Vector2(100.0f, 46.0f);
	sprite_.params.pos = initial;
	//sprite_.params.enableDrawRect(Rectf(
	//	0, 0, sprite_.params.siz.x, sprite_.params.siz.y
	//));

}

void Black::Update()
{
	sprite_.params.pos.y += 200.0f * Time.deltaTime;
	if (sprite_.params.pos.y >= 720.0f)
		sprite_.params.pos.y =  -88.0f;
	sprite_.params.enableMirror();
}
//“–‚½‚è”»’è
Math::Rectangle Black::GetCollision()
{
	Math::Rectangle collision;
	collision.x = (long)sprite_.params.pos.x;
	collision.y = (long)sprite_.params.pos.y;
	collision.width = (long)sprite_.params.siz.x;
	collision.height = (long)sprite_.params.siz.y;

	return collision;
}
void Black::OnCollision()
{


}