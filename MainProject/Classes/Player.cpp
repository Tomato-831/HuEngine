//
// Player.cpp
//

#include "Player.h"
#include "../InputSystem.h"

using namespace HE;

void Player::Load()
{
	sprite_ = Sprite("hito.png");
	RenderingPath->AddSprite(&sprite_, 0);
	RenderingPath->AddSprite(&collision_sprite_, 1);
}

void Player::Initialize()
{
	sprite_.params.pos.x = 300.0f - 64.0f;
	sprite_.params.pos.y = 700.0f - 64.0f;
	sprite_.params.siz.x = 64.0f;
	sprite_.params.siz.y = 64.0f;


	//最初のコマと１コマの大きさを設定
	//sprite_.params.enableDrawRect(Math::Vector4(256, 0, 64, 64));

	//アニメーションの設定
	//sprite_.anim = Sprite::Anim();                        //アニメーション機能の取得
	//sprite_.anim.repeatable = true;                       //ループするかしないか
	//sprite_.anim.drawRectAnim.frameRate  = 4;             //アニメーションの速度
	//sprite_.anim.drawRectAnim.frameCount = 4;             //画像にアニメーションが何コマあるか
	//sprite_.anim.drawRectAnim.horizontalFrameCount = 4;   //横に並んでるコマ数

	//衝突範囲の表示設定
	collision_sprite_.params.color = Color(255, 0, 0);    //色
	collision_sprite_.params.opacity = 0.5f;              //透明度
}

void Player::Update()
{
	auto prev_pos = sprite_.params.pos;

	//ゲームパッドの情報取得(１台目） 
	Gamepad gamepad = InputSystem.Gamepad.ElementAtOrDefault(0);Math::Vector2 stick(gamepad.leftStick.x, -gamepad.leftStick.y);
	float scale = std::max(std::abs(stick.x), std::abs(stick.y));
	stick.Normalize();
	sprite_.params.pos += stick * scale * 576.0f * Time.deltaTime;

	//if (gamepad.leftStick.x > 0)
	   //sprite_.params.pos.x += 2.0f;
	//if (gamepad.leftStick.x < 0)
	   // sprite_.params.pos.x -= 2.0f;
	//if (gamepad.leftStick.y > 0)
	   // sprite_.params.pos.y -= 2.0f;
	//if (gamepad.leftStick.y < 0)
		//sprite_.params.pos.y += 2.0f;

	Math::Vector2 direction;
	const float MOVEMENT = 200.0f * Time.deltaTime;
	const float RIGHT_LIMIT  = RenderingPath->GetLogicalWidth()  - sprite_.params.siz.x;
	const float BOTTOM_LIMIT = RenderingPath->GetLogicalHeight() - sprite_.params.siz.y;

	//左右
	if (InputSystem.Keyboard.isPressed.Right)
		sprite_.params.pos.x += MOVEMENT;
	if (InputSystem.Keyboard.isPressed.Left)
		sprite_.params.pos.x -= MOVEMENT;

	//範囲内か調べる
	if (sprite_.params.pos.x < 0.0f)
		sprite_.params.pos.x = 0.0f;
	else if (sprite_.params.pos.x > RIGHT_LIMIT)
		sprite_.params.pos.x = RIGHT_LIMIT;

	//上下
	if (InputSystem.Keyboard.isPressed.Down)
		sprite_.params.pos.y += MOVEMENT;
	if (InputSystem.Keyboard.isPressed.Up)
		sprite_.params.pos.y -= MOVEMENT;

	//範囲外か調べる

	if (sprite_.params.pos.y < 0.0f)
		sprite_.params.pos.y = 0.0f;

	else if (sprite_.params.pos.y > BOTTOM_LIMIT)
		sprite_.params.pos.y = BOTTOM_LIMIT;

	if (InputSystem.Keyboard.isPressed.Right)

		direction += Math::Vector2(1, 0);

	if (InputSystem.Keyboard.isPressed.Left)

		direction += Math::Vector2(-1, 0);

	if (InputSystem.Keyboard.isPressed.Up)

		direction += Math::Vector2(0, -1);

	if (InputSystem.Keyboard.isPressed.Down)

		direction += Math::Vector2(0,  1);

	if (sprite_.params.pos.x >= RenderingPath->GetLogicalWidth() + RenderingPath->GetLogicalWidth()) {
		sprite_.params.pos.x = -RenderingPath->GetLogicalWidth();
	}
	if (sprite_.params.pos.x <= -RenderingPath->GetLogicalWidth() + -RenderingPath->GetLogicalWidth()) {
		sprite_.params.pos.x = RenderingPath->GetLogicalWidth();
	}

	////矢印の長さを１にする
	  {
		direction.Normalize();
		sprite_.params.pos += direction * 400.0f * Time.deltaTime;
	  }
	////表示する領域のy座標のみ変更
	//{
	//	if (sprite_.params.drawRect.x < 256) {
	//		sprite_.params.drawRect.x += 256;
	//		sprite_.anim.drawRectAnim.frameRate = 4;
	//	}
	//}
	//{
	//	if (InputSystem.Keyboard.isPressed.Left)
	//		sprite_.params.drawRect.y = 64;
	//}

	////表示する領域のｙ座標のみ変更 
	//if (sprite_.params.drawRect.x < 256) {
	//	sprite_.params.drawRect.x += 256;
	//	sprite_.anim.drawRectAnim.frameRate = 4;
	//}
	//if (InputSystem.Keyboard.isPressed.Down) {
	//	sprite_.params.drawRect.y = 128;
	//	 //sprite_.params.pos.y -= 4.0f;
	//	if (sprite_.params.drawRect.x < 256) {
	//		sprite_.params.drawRect.x += 256;
	//		sprite_.anim.drawRectAnim.frameRate = 4;
	//	}
	//}


	//// アニメーション切り替え
	//if (sprite_.params.pos.y < prev_pos.y) {
	//	// 上向きの画像に切り替える
	//	sprite_.params.drawRect.y = 128;
	//	// 走っている画像に切り替える
	//	if (sprite_.params.drawRect.x < 256.0f) {
	//		sprite_.params.drawRect.x += 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 10;
	//	}
	//}
	//else if (sprite_.params.pos.y > prev_pos.y) {
	//	// 下向きの画像に切り替える
	//	sprite_.params.drawRect.y = 0;
	//	if (sprite_.params.drawRect.x < 256.0f) {
	//		sprite_.params.drawRect.x += 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 10;
	//	}
	//}
	//else if (sprite_.params.pos.x > prev_pos.x) {
	//	// 右向きの画像に切り替える
	//	sprite_.params.drawRect.y = 192;
	//	if (sprite_.params.drawRect.x < 256.0f) {
	//		sprite_.params.drawRect.x += 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 10;
	//	}
	//}
	//else if (sprite_.params.pos.x < prev_pos.x) {
	//	// 左向きの画像に切り替える
	//	sprite_.params.drawRect.y = 64;
	//	if (sprite_.params.drawRect.x < 256.0f) {
	//		sprite_.params.drawRect.x += 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 10;
	//	}
	//}
	//else {
	//	// 移動していないとき
	//	if (sprite_.params.drawRect.x >= 256.0f) {
	//		sprite_.params.drawRect.x -= 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 2;
	//	}
	//}
	////待機モーションに切り替え
	////すべてのボタンが押されてないときは待機に移行
	//{
	//	if (InputSystem.Keyboard.isPressed.Right == false &&
	//		InputSystem.Keyboard.isPressed.Left  == false &&
	//		InputSystem.Keyboard.isPressed.Down  == false &&
	//		InputSystem.Keyboard.isPressed.Up    == false)
	//	{
	//		if (sprite_.params.drawRect.x >= 256)
	//		{
	//			sprite_.params.drawRect.x -= 256;
	//			sprite_.anim.drawRectAnim.frameRate = 1;
	//		}
	//	}
	//}
}
//当たり判定
Math::Rectangle Player::GetCollision()
{
	Math::Rectangle collision;
	collision.x =      (long)sprite_.params.pos.x; 
	collision.y =      (long)sprite_.params.pos.y;
	collision.width =  (long)sprite_.params.siz.x;
	collision.height = (long)sprite_.params.siz.y;

	////衝突範囲表示設定
	//collision_sprite_.params.pos.x = (float)collision.x;
	//collision_sprite_.params.pos.y = (float)collision.y;
	//collision_sprite_.params.siz.x = (float)collision.width;
	//collision_sprite_.params.siz.y = (float)collision.height;


	return collision;
}
void Player::OnCollision()
{
	SetInitialPosition();
}
void Player::SetInitialPosition()
{
	sprite_.params.pos = Math::Vector2(
		(RenderingPath->GetLogicalWidth() - sprite_.params.siz.x) / 2.0f,
		RenderingPath->GetLogicalHeight() - sprite_.params.siz.y
	);
}
