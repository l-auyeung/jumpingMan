#include "Player.h"

Player::Player(Texture* texture, float speed, float jumpHeight)
{
	this->speed = speed; //setting the private variable to speed
	this->jumpHeight = jumpHeight; //set jumpHeight 
	body.setSize(Vector2f(100.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f); //centers the guy so it's PERFECTLY centered when we update the view
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
}

Player::~Player()
{}

void Player::Update(float deltaTime)
{
	velocity.x = 0.0f; //this resets the velocity every frame so we aren't just accelerating super fast
	//we can change this a bit but 0.0 is safe


	if (Keyboard::isKeyPressed(Keyboard::A))
		velocity.x -= speed;
	if (Keyboard::isKeyPressed(Keyboard::D))
		velocity.x += speed;
	//change this, it's input for jumping
	if ((Keyboard::isKeyPressed(Keyboard::Space) && canJump ==true) || (Keyboard::isKeyPressed(Keyboard::W) && canJump))
	{
		canJump = false;
		//sqrt(2.0f * gravity * jumpHeight)
		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight); //negative means jump up
	}
	velocity.y += 981.0f * deltaTime; //effect of gravity

	body.move(velocity * deltaTime);
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);

}

Vector2f Player::GetPosition() { return body.getPosition(); } //returns the top left corner of the player rectangle
Collider Player::GetCollider() { return Collider(body); } //returns a collider with the players rectangle as it's param 

void Player::OnCollision(Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//collision on left side
		velocity.x = 0.0f; 
		//since colliding, stop movement
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
		//collision on right
	}
	if (direction.y > 0.0f) //IMPORTANT hitting the bottom, resetting jump!
	{
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
		//collision on top WE CAN'T HAVE THIS
	}
}