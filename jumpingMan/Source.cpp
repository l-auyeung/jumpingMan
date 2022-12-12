#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Platform.h"


using namespace sf;
static const float VIEW_HEIGHT = 512.0f;

int main()
{
	RenderWindow window(VideoMode(512, 512), "10: Player class", Style::Default);

	//here is customized bit 
	Texture playerTexture;
	playerTexture.loadFromFile("pinky.png");
	View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	//defining a player named player
	Player player(&playerTexture, 100.0f); //(Texture* texture, float switchTime, float speed)


	//creating platforms
	Platform platform1(nullptr, Vector2f(400.0f, 200.0f), Vector2f(500.0f, 200.0f)); //nullptr is to make it a solid white color, replace it with a texture 
	Platform platform2(nullptr, Vector2f(400.0f, 200.0f), Vector2f(500.0f, 0.0f));
	//time?
	float deltaTime = 0.0f;
	Clock clock;



	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			//polling, we're checking for inputs here
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();

			//INPUTS


		}

		//update stuff here
		player.Update(deltaTime);

		Collider pCol = player.GetCollider();

		//check collision
		platform1.GetCollider().CheckCollision(pCol, 0.8f); //CheckCollision recieves collider& and float
		platform2.GetCollider().CheckCollision(pCol, 1.0f);

		view.setCenter(player.GetPosition()); //after updating player so player moves, then the view moves


		//whatever function, give it deltaTime
		window.clear(Color(120, 20, 90));
		window.setView(view);

		//draw stuff
		player.Draw(window);
		platform1.Draw(window);
		platform2.Draw(window);
		window.display();
	}
	return 0;
}