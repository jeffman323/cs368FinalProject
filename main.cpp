
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <String>
#include "Player.h"
#include "Terrain.h"

using namespace std;

void createBackground(vector<Terrain> &background) {
	Terrain piece1(0, -435, "ground.png" );
	Terrain piece2(60, -435, "ground.png" );
	Terrain piece3(120, -435, "ground.png" );
	Terrain piece4(180, -435, "ground.png" );
	Terrain piece5(240, -435, "ground.png" );
	background.push_back(piece1);
	background.push_back(piece2);
	background.push_back(piece3);
	background.push_back(piece4);
	background.push_back(piece5);
	//background.insert(background.end(), { piece1, piece2, piece3, piece4, piece5 });
}

int main()
{
	//create a window
	sf::RenderWindow window(sf::VideoMode(1000, 500), "FML it works!");
	/*
	//vector for sprite names
	vector<string> playerSprite = { "p1_walk01.png","p1_walk02.png","p1_walk03.png","p1_walk04.png","p1_walk05.png","p1_walk06.png","p1_walk07.png","p1_walk08.png","p1_walk09.png",
		"p1_walk10.png", "p1_walk11.png" };
	
	//index of sprite vector
	int i = 0;
	//int for delaying time
	int delay = 0;
	//max position onscreen
	int MAX = 2000;
	//min position on screen
	int MIN = 0;
	//position of the sprite
	double xpos = 50;
	double ypos = 450;
	//base position/floor
	int basepos = 450;
	//delays time
	int time = 0;
	//jumping speed 
	double speed = 6;
	//is the sprite facing right or left
	bool isRight = true;
	//is the sprite jumping
	bool isJump = false;
	*/
	Player play(window, 100, 396, 8);
	vector<Terrain> background;
	vector<Terrain> badGuyz;
	vector<Terrain> Healthbar;
	//createBackground(background);
	Terrain piece1(0, -435, "ground.png");
	Terrain piece2(-70, -435, "ground.png" );
	Terrain piece3(-140, -435, "ground.png" );
	Terrain piece4(-210, -435, "ground.png" );
	Terrain piece5(-280, -435, "ground.png" );
	Terrain piece6(-350, -435, "ground.png" );
	Terrain piece7(-420, -435, "ground.png" );
	Terrain piece8(-490, -435, "ground.png" );
	Terrain piece9(-560, -435, "ground.png" );
	Terrain piece10(-630, -435, "ground.png" );
	Terrain piece11(-700, -435, "ground.png" );
	Terrain piece12(-770, -435, "ground.png" );
	Terrain piece13(-840, -435, "ground.png" );
	Terrain piece14(-910, -435, "ground.png" );
	Terrain piece15(-980, -435, "ground.png" );
	Terrain piece16(-1050, -435, "ground.png" );
	Terrain piece17(-1120, -435, "ground.png" );
	Terrain piece18(-560, -300, "ground.png" );
	Terrain piece19(-630, -300, "ground.png" );
	Terrain piece20(-700, -300, "ground.png" );
	Terrain piece21(-770, -300, "ground.png" );
	Terrain piece22(-840, -300, "ground.png" );
	Terrain piece23(-910, -300, "ground.png" );
	Terrain piece24(-980, -300, "ground.png" );
	Terrain piece25(-1050, -300, "ground.png" );
	Terrain piece26(-1120, -300, "ground.png" );
	Terrain piece27(-400, -100, "ground.png" );
	Terrain piece28(-330, -100, "ground.png" );
	Terrain piece29(-260, -100, "ground.png" );
	Terrain piece30(-190, -100, "ground.png" );

	Terrain enemy1(-840, -274, "slime_normal.png" );

	Terrain health1(-10, -10, "hud_heartFull.png" );
	Terrain health2(-80, -10, "hud_heartFull.png" );
	Terrain health3(-150, -10, "hud_heartFull.png" );
	Terrain health4(-10, -10, "hud_heartHalf.png" );
	Terrain health5(-80, -10, "hud_heartHalf.png" );
	Terrain health6(-150, -10, "hud_heartHalf.png" );
	background.push_back(piece1);
	background.push_back(piece2);
	background.push_back(piece3);
	background.push_back(piece4);
	background.push_back(piece5);
	background.push_back(piece6);
	background.push_back(piece7);
	background.push_back(piece8);
	background.push_back(piece9);
	background.push_back(piece10);
	background.push_back(piece11);
	background.push_back(piece12);
	background.push_back(piece13);
	background.push_back(piece14);
	background.push_back(piece15);
	background.push_back(piece16);
	background.push_back(piece17);
	background.push_back(piece18);
	background.push_back(piece19);
	background.push_back(piece20);
	background.push_back(piece21);
	background.push_back(piece22);
	background.push_back(piece23);
	background.push_back(piece24);
	background.push_back(piece25);
	background.push_back(piece26);
	background.push_back(piece27);
	background.push_back(piece28);
	background.push_back(piece29);
	background.push_back(piece30);

	badGuyz.push_back(enemy1);

	Healthbar.push_back(health1);
	Healthbar.push_back(health2);
	Healthbar.push_back(health3);
	Healthbar.push_back(health4);
	Healthbar.push_back(health5);
	Healthbar.push_back(health6);

	//loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		play.move(background, badGuyz);
		window.clear();
		if (play.getHealth() == 0) {
			sf::RenderWindow window1(sf::VideoMode(458, 347), "YOU DIED!"); //358 x 247
			window.clear();
			window1.clear();
			Terrain gameOver(-50, -50, "gameover.png");
			gameOver.drawTerrain(window1);
			window.display();
			window1.display();
			while (window1.isOpen()) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					window1.close();
					exit(0);
				}
			}
			
		}
		else {

		
		if (play.getHealth() == 1) {
			Healthbar[3].drawTerrain(window);
		}
		else if (play.getHealth() == 2) {
			Healthbar[0].drawTerrain(window);
		}
		if (play.getHealth() == 3) {
			Healthbar[0].drawTerrain(window);
			Healthbar[4].drawTerrain(window);
		}
		else if (play.getHealth() == 4) {
			Healthbar[0].drawTerrain(window);
			Healthbar[1].drawTerrain(window);
		}
		if (play.getHealth() == 5) {
			Healthbar[0].drawTerrain(window);
			Healthbar[1].drawTerrain(window);
			Healthbar[5].drawTerrain(window);
		}
		else if (play.getHealth() == 6) {
			Healthbar[0].drawTerrain(window);
			Healthbar[1].drawTerrain(window);
			Healthbar[2].drawTerrain(window);
		}
		}
		play.drawPlayer(window);
		for (int i = 0; i < background.size(); i++) {
			background[i].drawTerrain(window);
		}
		for (int k = 0; k < badGuyz.size(); k++) {
			badGuyz[k].drawTerrain(window);
		}
		window.display();
		
		/*
		//move right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			// right key is pressed: move our character
			isRight = true;
			delay++;
			if (delay > 30)
			{
				delay = 0;
				//determines which picture to use for the sprite
				i++;
				if (i >= 11)
					i = 0;
			}
			xpos++;
			if (xpos >= MAX)
				xpos--;
		}
		//move left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			// left key is pressed: move our character
			isRight = false;
			delay++;
			if (delay > 30)
			{
				delay = 0;
				//determines which picture to use for the sprite
				i++;
				if (i >= 11)
					i = 0;
			}
			xpos--;
			if (xpos <= MIN)
				xpos++;
		}
		//jump
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (isJump == false)
				isJump = true;
		}
		//create a texture and a sprite
		sf::Texture texture;
		sf::Sprite sprite;
		//if jumping
		if (isJump)
		{
			//load the jumping picture
			if (!texture.loadFromFile("p1_jump.png"))
			{
				// error...
			}
			if (isRight)
			{
				//set the sprite to jump right
				sprite.setTexture(texture);
			}
			else
			{
				//set the sprite to jump left
				sprite.setTexture(texture);
				sprite.scale(-1.f, 1.f);
			}
			//after time, slow down the jump speed and make the sprite go down
			time++;
			if (time >= 3)
			{
				time = 0;
				speed = speed - 0.2;

			}
			//jump and fall
			ypos -= speed;
			//if at the floor, stop jump
			if (ypos >= basepos)
			{
				isJump = false;
				ypos = basepos;
				time = 0;
				speed = 6;
			}
		}
		else
		{
			//load sprite from the walking vector
			if (!texture.loadFromFile(playerSprite[i]))
			{
				// error...
			}
			if (isRight)
			{
				//the sprite goes right
				sprite.setTexture(texture);
			}
			else
			{
				//the sprite goes left
				sprite.setTexture(texture);
				sprite.scale(-1.f, 1.f);
			}
		}
		//draw the sprite
		sprite.setOrigin(36, 48);
		sprite.setPosition(xpos, ypos);
		sf::Texture back;
		sf::Sprite background;
		if (!back.loadFromFile(playerSprite[i]))
		{
			// error...
		}
		window.clear();
		window.draw(sprite);
		window.display();
		*/
		
	}

	return 0;
}