#pragma once
#include "stdafx.h"
#include "animation.h"
class player
{
public:
	player(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~player();
	bool movementTrue();
	void update(float deltaTime);
	void draw(RenderWindow& window);

private:
	RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	bool newImage = false;
	float switchUpdate;
	
	Vector2u imageCount;
	Texture pCurrentTexture;

	Texture playerIdleTexture;
	Texture playerWalkTexture;
	Texture playerRunTexture;
	Texture playerJumpTexture;
	Texture playerRunAttackTexture;

};

