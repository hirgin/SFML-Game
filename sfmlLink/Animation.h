#pragma once
#include "stdafx.h"
class Animation
{

public:
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	~Animation();

	void update(int row, float deltaTime, bool faceRight, float switchTime, Vector2u imageCount, Texture* texture);

public: 
	IntRect uvRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;
	float totalTime;
	float switchTime;
	std::string prevAnimation;
};

