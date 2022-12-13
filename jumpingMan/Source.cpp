#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include <vector>

static const string PLAYER_TEXTURE = "pinky.png";
static const string GAME_NAME = "jumpingGame";
static const float VIEW_HEIGHT = 512.0f; //it's a square... cus im lazy
static const float PLAYER_SPEED = 100.0f;
static const float PLAYER_JUMP_HEIGHT = 200.0f;
static const string PLATFORM_TEXTURE = nullptr;
static const string GROUND_TEXTURE = nullptr;

using namespace sf;


int main()
{
	RenderWindow window(VideoMode(512, 512), "jumpingGame", Style::Default);

	//here is customized bit 
	Texture playerTexture;
	playerTexture.loadFromFile(PLAYER_TEXTURE);
	View view(Vector2f(0.0f, 0.0f), Vector2f(512.0f, 512.0f));
	//defining a player named player
	Player player(&playerTexture, 100.0f, 200.0f); //(Texture* texture,  float speed, float jumpHeight)


	//create vector to hold platforms
	vector<Platform> platforms; //need to make this pointers
	//push same for all the platforms in the vector (works well for us... platforms are the same, for broken platforms need seperate vector)
	//creating platforms (texture, dimentions, position_
	
	//replace nullptr with PLATFROM_TEXTURE when we put a texture in
	Platform platform1(nullptr, Vector2f(400.0f, 200.0f), Vector2f(500.0f, 200.0f)); //nullptr is to make it a solid white color, replace it with a texture 
	Platform platform2(nullptr, Vector2f(400.0f, 200.0f), Vector2f(500.0f, 0.0f));
	//ground, replace nullptr with GROUND_TEXTURE
	Platform ground(nullptr, Vector2f(1000.0f, 200.0f), Vector2f(500.0f, 500.0f));

	platforms.push_back(platform1);
	platforms.push_back(platform2);
	platforms.push_back(ground);

	//time
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

		Vector2f direction;

		
		for (Platform& platform : platforms) //for entire vector of platforms, we're checking collision with player and what direction they are
		{
			if (platform.GetCollider().CheckCollision(pCol, direction, 1.0f)) //1.0f means the platforms are solid
			{
				player.OnCollision(direction);
			}
		}

		

		//check collision
		//platform pointers turn this into a vector parse through, check for collision with player
	

		view.setCenter(player.GetPosition()); //after updating player so player moves, then the view moves


		//whatever function, give it deltaTime
		window.clear(Color(120, 20, 90));
		window.setView(view);

		//draw stuff
		player.Draw(window); //draw the player
		
		for (Platform& platform : platforms)
			platform.Draw(window); //draw the platforms

		window.display();
	}
	return 0;
}