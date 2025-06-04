#pragma once

#include "../HuEngine.h"

class Title : public HE::Scene
{
public:
	Title();
	virtual ~Title() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:

	HE::Sprite sprite_title_;

};
