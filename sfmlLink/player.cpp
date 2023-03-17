#include "stdafx.h"
#include "player.h"
#include "Animation.h"

player::player(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 1;
	this->imageCount = imageCount;
	faceRight = true;
	this->switchUpdate = switchTime;
	body.setSize(Vector2f(400.0f, 200.0f));
	body.setPosition(550.0f, 650.0f);
	body.setTexture(texture);
	body.setOutlineColor(Color::Cyan);
	playerIdleTexture.loadFromFile("playerTexture/Idle.png");
	playerWalkTexture.loadFromFile("playerTexture/Walk.png");
	playerRunTexture.loadFromFile("playerTexture/Run.png");
	playerJumpTexture.loadFromFile("playerTexture/Jump.png");
	playerRunAttackTexture.loadFromFile("playerTexture/Run+Attack.png");
}

player::~player()
{
}

bool player::movementTrue()

/*
* Function that checks keyboard movement to see if user is inputting movement commands. 
*If they are moving or inputting more than one movement command than their movement is invalid and false
*/

{
	if ((!(Keyboard::isKeyPressed(Keyboard::W))) && (!(Keyboard::isKeyPressed(Keyboard::A))) && (!(Keyboard::isKeyPressed(Keyboard::S))) && (!(Keyboard::isKeyPressed(Keyboard::D))) && (!(Keyboard::isKeyPressed(Keyboard::Space))) ||
		(Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::A)))
	{
		return false;
	}
	else
	{
		return true;
	}
}



void player::update(float deltaTime)
{
	Vector2f movement(0.0f, 0.0f);	
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		faceRight = false;
		if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::LShift)) // sprint
		{
			this->imageCount = Vector2u(6, 2);
			pCurrentTexture = playerRunTexture;
			switchUpdate = .095f;
			movement.x -= speed * deltaTime * 1.8f;
		}
		else // walk
		{
			this->imageCount = Vector2u(8, 2);
			pCurrentTexture = playerWalkTexture;
			movement.x -= speed * deltaTime;
			switchUpdate = .09f;
			
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		faceRight = true;
		if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift)) // sprint
		{
			this->imageCount = Vector2u(6, 2);
			pCurrentTexture = playerRunTexture;
			switchUpdate = .095f;
			movement.x += speed * deltaTime * 1.8f;
		
		}
		else // walk
		{
			this->imageCount = Vector2u(8, 2);
			pCurrentTexture = playerWalkTexture;
			switchUpdate = .09f;
			movement.x += speed * deltaTime;
			
		}
	}

	if (!(movementTrue())) // Idle Animation 
	{
		this->imageCount = Vector2u(6, 2);
		pCurrentTexture = playerIdleTexture;
		switchUpdate = .4f;
		
	}


	// Section to update player animation, location, and texture
	body.setTexture(&pCurrentTexture);
	animation.update(row, deltaTime, faceRight, switchUpdate, this->imageCount, &pCurrentTexture );
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

void player::draw(RenderWindow& window)
{
	window.draw(body);
}
