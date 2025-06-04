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


	//�ŏ��̃R�}�ƂP�R�}�̑傫����ݒ�
	//sprite_.params.enableDrawRect(Math::Vector4(256, 0, 64, 64));

	//�A�j���[�V�����̐ݒ�
	//sprite_.anim = Sprite::Anim();                        //�A�j���[�V�����@�\�̎擾
	//sprite_.anim.repeatable = true;                       //���[�v���邩���Ȃ���
	//sprite_.anim.drawRectAnim.frameRate  = 4;             //�A�j���[�V�����̑��x
	//sprite_.anim.drawRectAnim.frameCount = 4;             //�摜�ɃA�j���[�V���������R�}���邩
	//sprite_.anim.drawRectAnim.horizontalFrameCount = 4;   //���ɕ���ł�R�}��

	//�Փ˔͈͂̕\���ݒ�
	collision_sprite_.params.color = Color(255, 0, 0);    //�F
	collision_sprite_.params.opacity = 0.5f;              //�����x
}

void Player::Update()
{
	auto prev_pos = sprite_.params.pos;

	//�Q�[���p�b�h�̏��擾(�P��ځj 
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

	//���E
	if (InputSystem.Keyboard.isPressed.Right)
		sprite_.params.pos.x += MOVEMENT;
	if (InputSystem.Keyboard.isPressed.Left)
		sprite_.params.pos.x -= MOVEMENT;

	//�͈͓������ׂ�
	if (sprite_.params.pos.x < 0.0f)
		sprite_.params.pos.x = 0.0f;
	else if (sprite_.params.pos.x > RIGHT_LIMIT)
		sprite_.params.pos.x = RIGHT_LIMIT;

	//�㉺
	if (InputSystem.Keyboard.isPressed.Down)
		sprite_.params.pos.y += MOVEMENT;
	if (InputSystem.Keyboard.isPressed.Up)
		sprite_.params.pos.y -= MOVEMENT;

	//�͈͊O�����ׂ�

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

	////���̒������P�ɂ���
	  {
		direction.Normalize();
		sprite_.params.pos += direction * 400.0f * Time.deltaTime;
	  }
	////�\������̈��y���W�̂ݕύX
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

	////�\������̈�̂����W�̂ݕύX 
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


	//// �A�j���[�V�����؂�ւ�
	//if (sprite_.params.pos.y < prev_pos.y) {
	//	// ������̉摜�ɐ؂�ւ���
	//	sprite_.params.drawRect.y = 128;
	//	// �����Ă���摜�ɐ؂�ւ���
	//	if (sprite_.params.drawRect.x < 256.0f) {
	//		sprite_.params.drawRect.x += 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 10;
	//	}
	//}
	//else if (sprite_.params.pos.y > prev_pos.y) {
	//	// �������̉摜�ɐ؂�ւ���
	//	sprite_.params.drawRect.y = 0;
	//	if (sprite_.params.drawRect.x < 256.0f) {
	//		sprite_.params.drawRect.x += 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 10;
	//	}
	//}
	//else if (sprite_.params.pos.x > prev_pos.x) {
	//	// �E�����̉摜�ɐ؂�ւ���
	//	sprite_.params.drawRect.y = 192;
	//	if (sprite_.params.drawRect.x < 256.0f) {
	//		sprite_.params.drawRect.x += 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 10;
	//	}
	//}
	//else if (sprite_.params.pos.x < prev_pos.x) {
	//	// �������̉摜�ɐ؂�ւ���
	//	sprite_.params.drawRect.y = 64;
	//	if (sprite_.params.drawRect.x < 256.0f) {
	//		sprite_.params.drawRect.x += 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 10;
	//	}
	//}
	//else {
	//	// �ړ����Ă��Ȃ��Ƃ�
	//	if (sprite_.params.drawRect.x >= 256.0f) {
	//		sprite_.params.drawRect.x -= 256.0f;
	//		sprite_.anim.drawRectAnim.frameRate = 2;
	//	}
	//}
	////�ҋ@���[�V�����ɐ؂�ւ�
	////���ׂẴ{�^����������ĂȂ��Ƃ��͑ҋ@�Ɉڍs
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
//�����蔻��
Math::Rectangle Player::GetCollision()
{
	Math::Rectangle collision;
	collision.x =      (long)sprite_.params.pos.x; 
	collision.y =      (long)sprite_.params.pos.y;
	collision.width =  (long)sprite_.params.siz.x;
	collision.height = (long)sprite_.params.siz.y;

	////�Փ˔͈͕\���ݒ�
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
