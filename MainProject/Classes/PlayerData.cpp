//
//PlayerData.cpp
//

#include "PlayerDate.h"

using namespace HE;

void PlayerData::Load()
{
	score_headline_.params.style = Font::AddFontStyle("Fonts/HGRPP1002.ttf");
score_text_    .params.style = Font::AddFontStyle("Fonts/HGRPP1002.ttf");

	RenderingPath->AddFont(&score_headline_, 1000);
	RenderingPath->AddFont(&score_text_, 1000);
}

void PlayerData::Initialize()
{

	score_ = 0;

	//スコア見出し
	score_headline_.SetText(L"1-UP");
	score_headline_.params.posX = 256.0f;
	score_headline_.params.posY = 0.0f;
	score_headline_.params.size = 32;
	score_headline_.params.color = Color(255, 255, 255);

	//スコア数値
	score_text_.SetText(std::to_string(score_));
	score_text_.params.posX = 304.0f;
	score_text_.params.posY = 32.0f;	score_text_.params.size = 32;



}