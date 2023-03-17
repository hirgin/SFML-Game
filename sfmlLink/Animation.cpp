#include "stdafx.h"
#include "Animation.h"

Animation::Animation(Texture* texture, Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{

}


void Animation::update(int row, float deltaTime, bool faceRight, float switchTime, Vector2u imageCount, Texture* texture )
{
	this->currentImage.y = row;
	totalTime += deltaTime;
	this->switchTime = switchTime;
	this->imageCount = imageCount;

	if (currentImage.x >= imageCount.x)	// make sure sprite size matches current sprite
	{
		currentImage.x = 0;
	}

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);

	if (totalTime >= switchTime)	// go to next img
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)		// make sure sprite size matches current sprite
		{
			currentImage.x = 0;	// set image to first frame of animation
		}
	}
	
	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)	// sets whether character is facing left or right
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

}
