#include "Player.h"

Player::Player(Texture* texture, float speed)
{
	this->speed = speed; //setting the private variable to speed

	body.setSize(Vector2f(100.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f); //centers the guy so it's PERFECTLY centered when we update the view
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
}

Player::~Player()
{}

void Player::Update(float deltaTime)
{
	Vector2f movement(0.0f, 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::A))
		movement.x -= speed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::D))
		movement.x += speed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::S))
		movement.y += speed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::W))
		movement.y -= speed * deltaTime;

	body.move(movement);
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);

}

Vector2f Player::GetPosition() { return body.getPosition(); }
Collider Player::GetCollider() { return Collider(body); }

