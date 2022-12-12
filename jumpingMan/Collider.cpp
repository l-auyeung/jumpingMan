#include "Collider.h"
//I'm planning on changing this and editting to be jump so it's just for the Y
Collider::Collider(RectangleShape& body) : body(body) {}
Collider::~Collider() {}
bool Collider::CheckCollision(Collider& other, float push) //we give it something of the same class and a "push" aka how hard it is to move the opbject
{//it's kinda neat... but it also accounts for x collision and we don't need that, ill edit it
	Vector2f otherPosition = other.GetPosition();
	Vector2f otherHalfSize = other.GetHalfSize();
	Vector2f thisPosition = GetPosition(); //applies to our body that we declared in the collider
	Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//COME BACK THIS IF STATEMENT NEEDS TO BE MODIFIED, WE CAN RENAME THIS TO JUMP
	if (intersectX < 0.0f && intersectY < 0.0f)//we can change this to just Y
	{
		push = min(max(push, 0.0f), 1.0f); // I think push 1.0 is unmovable whereas 0 is very movable
		//don't need this for Y
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f); //this makes the other one go in the opposite direction
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push); //this makes the other one go in the opposite direction
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}
		return true;
	}
	return false;
}
