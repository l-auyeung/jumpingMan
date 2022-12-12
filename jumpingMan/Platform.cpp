#include "Platform.h"

Platform::Platform(Texture* texture, Vector2f size, Vector2f position)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(size / 2.0f);
}

Platform::~Platform() {}

void Platform::Draw(RenderWindow& window)
{
	window.draw(body);
}

Collider Platform::GetCollider()
{
	return Collider(body);
}