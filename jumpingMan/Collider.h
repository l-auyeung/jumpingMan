#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;
class Collider
{
public:
	Collider(RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); };

	bool CheckCollision(Collider& other, float push); //push decides how much each object needs to be pushed away 1 means other one movs
	Vector2f GetPosition() { return body.getPosition(); }
	Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
private:
	RectangleShape& body; //we're referecing the SAME body... we could probs use some kind of polymorphism here


};

