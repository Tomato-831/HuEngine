//
//PlayerLife.cpp
//

#include "PlayerLife.h"

using namespace HE;

void PlayerLife::Load()
{
	score_headline_.params.style = Font::AddFontStyle("Fonts/HGRPP1001.ttf");
	score_text_.params.style = Font::AddFontStyle("Fonts/HGRPP1001.ttf");

	RenderingPath->AddFont(&score_headline_, 1000);
	RenderingPath->AddFont(&score_text_, 1000);
}

void PlayerLife::Initialize()
{

	score_ = 2;



	//スコア見出し
	score_headline_.SetText(L"REST");
	score_headline_.params.posX = 1034.0f;
	score_headline_.params.posY = 34.0f;
	score_headline_.params.size = 50;
	score_headline_.params.color = Color(255, 0, 0);

	//スコア数値
	score_text_.SetText(std::to_string(score_));
	score_text_.params.posX = 1150.0f;
	score_text_.params.posY = 30.0f;	
	score_text_.params.size = 50;

}