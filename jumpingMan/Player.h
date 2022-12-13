#pragma once
#include <SFML\Graphics.hpp> 
#include "Collider.h"
using namespace sf;
class Player
{
public:
	Player(Texture* texture, float speed, float jumpHeight);
	~Player();
	void Update(float deltaTime); //no dt im spelling everything out bc im dumb 
	void Draw(RenderWindow& window); //so we don't need to call the body, but calling the body fine too

	Vector2f GetPosition();
	Collider GetCollider();
	void OnCollision(Vector2f direction);

private:
	RectangleShape body;
	float speed;
	
	Vector2f velocity;
	bool canJump;
	float jumpHeight;

};

