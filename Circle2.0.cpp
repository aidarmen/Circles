// Circle2.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>





using namespace sf;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Circles! press R to restart");

	//scale the window size 1 to 1/2
	window.setSize(Vector2u(980, 540));
	window.setPosition(Vector2i(VideoMode::getDesktopMode().width /2 - window.getSize().x /2, VideoMode::getDesktopMode().height /2 - window.getSize().y /2));
	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.jpg");

	// Create a sprite
	Sprite spriteBackground;
	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	spriteBackground.setPosition(0, 0);

	Texture circle1color;
	circle1color.loadFromFile("graphics/circle1.png");
	Sprite circle1;
	circle1.setTexture(circle1color);
	circle1.setPosition(500, 100);

	Texture circle2color;
	circle2color.loadFromFile("graphics/circle2.png");
	Sprite circle2;
	circle2.setTexture(circle2color);
	circle2.setPosition(1100, 100);

	Texture circle3color;
	circle3color.loadFromFile("graphics/circle3.png");
	Sprite circle3;
	circle3.setTexture(circle3color);
	circle3.setPosition(1100, 700);

	Texture circle4color;
	circle4color.loadFromFile("graphics/circle4.png");
	Sprite circle4;
	circle4.setTexture(circle4color);
	circle4.setPosition(500, 700);


	Texture clockwisecolor;
	clockwisecolor.loadFromFile("graphics/clockwise.png");

	Sprite clockwise;
	clockwise.setTexture(clockwisecolor);
	clockwise.setScale(Vector2f(0.25, 0.25));
	clockwise.setPosition(100, 100);
	


	Texture anticlockwisecolor;
	anticlockwisecolor.loadFromFile("graphics/anticlockwise.png");

	Sprite anticlockwise;
	anticlockwise.setTexture(anticlockwisecolor);
	anticlockwise.setScale(Vector2f(0.25, 0.25));
	anticlockwise.setPosition(100, 100);
	

	bool circle1Active = false;
	bool circle2Active = false;
	bool circle3Active = false;
	bool circle4Active = false;

	//current rotation clockwise
	bool rotation = false;
	float rotate = 1.0f;

	// How fast is each circle
	float circle1Speed = 1000.0f;
	float circle2Speed = 1000.0f;
	float circle3Speed = 1000.0f;
	float circle4Speed = 1000.0f;

	// Variables to control time itself
	Clock clock;

	bool acceptInput = false;
	// Track whether the game is running
	bool paused = true;

	//////////////////////////////////////////////////////////////////////
	Text messageText;
	// We need to choose a font
	Font font;
	font.loadFromFile("fonts/Cowboys.ttf");
    
	// Set the font to our message
	messageText.setFont(font);


	// Assign the actual message
	messageText.setString("Press Enter to start!");


	// Make it really big
	messageText.setCharacterSize(75);
	

	// Choose a color
	messageText.setFillColor(Color::White);
	

	// Position the text
	FloatRect textRect = messageText.getLocalBounds();

	messageText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FloatRect clockwiseR = anticlockwise.getLocalBounds();

	anticlockwise.setOrigin(clockwiseR.left +
		clockwiseR.width / 2.0f,
		clockwiseR.top +
		clockwiseR.height / 2.0f);

	clockwise.setOrigin(clockwiseR.left +
		clockwiseR.width / 2.0f,
		clockwiseR.top +
		clockwiseR.height / 2.0f);
	
	// input speed
	float x;
	x = 1;
	Text Text1, Text2, Text3, Text4;

	RectangleShape speed1(Vector2f(200, 100));
	speed1.setFillColor(Color(255, 32, 82));
	speed1.setPosition(Vector2f(50, 200));
	
	Text1.setFont(font);
    Text1.setString("1");
    Text1.setCharacterSize(75);
	Text1.setFillColor(Color(32, 255, 205));
	Text1.setPosition(Vector2f(130, 200));

	RectangleShape speed2(Vector2f(200, 100));
	speed2.setFillColor(Color(255, 32, 82));
	speed2.setPosition(Vector2f(50, 400));

	Text2.setFont(font);
	Text2.setString("2");
	Text2.setCharacterSize(75);
	Text2.setFillColor(Color(32, 255, 205));
	Text2.setPosition(Vector2f(130, 400));

	RectangleShape speed3(Vector2f(200, 100));
	speed3.setFillColor(Color(255, 32, 82));
	speed3.setPosition(Vector2f(50, 600));

	Text3.setFont(font);
	Text3.setString("3");
	Text3.setCharacterSize(75);
	Text3.setFillColor(Color(32, 255, 205));
	Text3.setPosition(Vector2f(130, 600));

	RectangleShape speed4(Vector2f(200, 100));
	speed4.setFillColor(Color(255, 32, 82));
	speed4.setPosition(Vector2f(50, 800));

	Text4.setFont(font);
	Text4.setString("4");
	Text4.setCharacterSize(75);
	Text4.setFillColor(Color(32, 255, 205));
	Text4.setPosition(Vector2f(130, 800));


	while (window.isOpen())
	{
		Time dt = clock.restart();

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		//continue game
		if (Keyboard::isKeyPressed(Keyboard::Return)  && paused == true && acceptInput == true)
		{
			paused = false;
			acceptInput = false;

		}
		//stop game
		if (Keyboard::isKeyPressed(Keyboard::Return)  && paused == false && acceptInput == true)
		{
			paused = true;
			acceptInput = false;
		}

		//check if i can press again
		Event event;
		while (window.pollEvent(event))
		{

            if (event.type == Event::KeyReleased || event.type == Event::MouseButtonPressed)
			{
				// Listen for key presses again
				acceptInput = true;
			}
			if (Keyboard::isKeyPressed(Keyboard::R) && acceptInput == true)
			{
				acceptInput = false;
				circle1.setPosition(500, 100);
				circle2.setPosition(1100, 100);
				circle3.setPosition(1100, 700);
				circle4.setPosition(500, 700);
				
			}
			if (Keyboard::isKeyPressed(Keyboard::T) && acceptInput == true && paused==false)
			{
				acceptInput = false;
				paused = true;

			}
			if (Keyboard::isKeyPressed(Keyboard::T) && acceptInput == true && paused == true)
			{
				acceptInput = false;
				paused = false;

			}



			//close window 
			if (event.type==Event::Closed)
			{ 
				window.close(); 
			}
			//move clockwise
			if ( Mouse::isButtonPressed(Mouse::Left) && rotation==false && acceptInput == true )
			{
				if (Mouse::getPosition().x <= (80 + window.getPosition().x) && Mouse::getPosition().x >= (20 + window.getPosition().x))
				{
					if (Mouse::getPosition().y <= (80 + window.getPosition().y) && Mouse::getPosition().y >= (10 + window.getPosition().y)) 
					{
						rotation = true;
						acceptInput = false;
						std::cout << "counterclockwise" << std::endl;
						
					}
				}
				
			}
			//move counter clockwise
			if (Mouse::isButtonPressed(Mouse::Left) && rotation == true && acceptInput == true)
			{
				if (Mouse::getPosition(window).x <= 100  && Mouse::getPosition(window).x >= 10)
				{
					if (Mouse::getPosition().y <= (80 + window.getPosition().y) && Mouse::getPosition().y >= (10 + window.getPosition().y))
					{
						

						rotation = false;
						acceptInput = false;
						
						std::cout << "clockwise" << std::endl;
					}
				}
			
			}

			
			//speed 1 
			if  (Mouse::isButtonPressed(Mouse::Left) && acceptInput == true)
			{
				if (Mouse::getPosition(window).x <= (130) && Mouse::getPosition(window).x >= (25))
				{
					if (Mouse::getPosition(window).y <= (150) && Mouse::getPosition(window).y >= (99))
					{
						
						acceptInput = false;
						x = 1;
					}
					
				}
			}

			//speed2
			if (Mouse::isButtonPressed(Mouse::Left) && acceptInput == true)
			{
				if (Mouse::getPosition(window).x <= (130) && Mouse::getPosition(window).x >= (25))
				{
					if (Mouse::getPosition(window).y <= (250) && Mouse::getPosition(window).y >= (200))
					{
						
						acceptInput = false;
						x = 2;
					}

				}
			}

			//speed3
			if (Mouse::isButtonPressed(Mouse::Left) && acceptInput == true)
			{
				if (Mouse::getPosition(window).x <= (130) && Mouse::getPosition(window).x >= (25))
				{
					if (Mouse::getPosition(window).y <= (350) && Mouse::getPosition(window).y >= (300))
					{
						
						acceptInput = false;
						x = 3;
					}

				}
			}
			//speed4
			if (Mouse::isButtonPressed(Mouse::Left) && acceptInput == true)
			{
				if (Mouse::getPosition(window).x <= (130) && Mouse::getPosition(window).x >= (25))
				{
					if (Mouse::getPosition(window).y <= (450) && Mouse::getPosition(window).y >= (400))
					{
						
						acceptInput = false;
						x = 4;
					}

				}
			}
			
		}

		if (!paused)//////////////////////////////////////////////////////////////////////fgergergrtg
		{
			if (!rotation)
			{
				rotate = 1.0f;
				
				
			}
			else
			{
				rotate = -1.0f;
				
			}
			
			float circle1Speed = x*1000.0f * (rotate);
			float circle2Speed = x*1000.0f* (rotate);
			float circle3Speed = x*1000.0f * (rotate);
			float circle4Speed = x*1000.0f* (rotate);

			if (!circle1Active)
			{
				
				circle1Active = true;

			}
			else
				// Move the circle
			{

				//from left to right
				if (circle1.getPosition().x >= 500 && circle1.getPosition().x <= 1100.0f && circle1.getPosition().y >= 100 && circle1.getPosition().y <=100.0f)
				{
					circle1.setPosition(
						circle1.getPosition().x + 
						(circle1Speed* 0.001f),
						100);
				}
				//from up to bottom
				if (circle1.getPosition().y >= 100.0f && circle1.getPosition().y <= 700.0f && circle1.getPosition().x >= 1100.0f && circle1.getPosition().x <= 1100.0f)
				{
					circle1.setPosition(
						1100,
						circle1.getPosition().y +
						(circle1Speed * 0.001f));
				}
				//from right to left
				if (circle1.getPosition().x >= 500 && circle1.getPosition().x <= 1100.0f && circle1.getPosition().y >= 700.0f && circle1.getPosition().y <=700.0f)
				{
					circle1.setPosition(
						circle1.getPosition().x -
						(circle1Speed* 0.001f),
						700);
				}
				//from bottom to left
				if (circle1.getPosition().y >= 100.0f && circle1.getPosition().y <= 700.0f && circle1.getPosition().x >= 500.0f && circle1.getPosition().x <= 500.0f)
				{
					circle1.setPosition(
						500,
						circle1.getPosition().y -
						(circle1Speed* 0.001f));
				}
			}

			if (!circle2Active)
			{

				circle2Active = true;

			}
			else	// Move the circle
			{

				
				//from up to bottom
				if (circle2.getPosition().y >= 100.0f && circle2.getPosition().y <= 700.0f && circle2.getPosition().x >= 1100.0f && circle2.getPosition().x <= 1100.0f)
				{
					circle2.setPosition(
						1100,
						circle2.getPosition().y +
						(circle2Speed * 0.001f));
				}
				//from right to left
				if (circle2.getPosition().x >= 500 && circle2.getPosition().x <= 1100.0f && circle2.getPosition().y >= 700.0f && circle2.getPosition().y <= 700.0f)
				{
					circle2.setPosition(
						circle2.getPosition().x -
						(circle2Speed * 0.001f),
						700);
				}
				//from bottom to left
				if (circle2.getPosition().y >= 100.0f && circle2.getPosition().y <= 700.0f && circle2.getPosition().x >= 500.0f && circle2.getPosition().x <= 500.0f)
				{
					circle2.setPosition(
						500,
						circle2.getPosition().y -
						(circle2Speed *0.001f));
				}
				//from left to right
				if (circle2.getPosition().x >= 500 && circle2.getPosition().x <= 1100.0f && circle2.getPosition().y >= 100 && circle2.getPosition().y <= 100.0f)
				{
					circle2.setPosition(
						circle2.getPosition().x +
						(circle2Speed * 0.001f),
						100);
				}
			}

			if (!circle3Active)
			{

				circle3Active = true;

			}
			else	// Move the circle
			{

				//from right to left
				if (circle3.getPosition().x >= 500 && circle3.getPosition().x <= 1100.0f && circle3.getPosition().y >= 700.0f && circle3.getPosition().y <= 700.0f)
				{
					circle3.setPosition(
						circle3.getPosition().x -
						(circle3Speed * 0.001f),
						700);
				}
				//from bottom to left
				if (circle3.getPosition().y >= 100.0f && circle3.getPosition().y <= 700.0f && circle3.getPosition().x >= 500.0f && circle3.getPosition().x <= 500.0f)
				{
					circle3.setPosition(
						500,
						circle3.getPosition().y -
						(circle3Speed *0.001f));
				}
				//from left to right
				if (circle3.getPosition().x >= 500 && circle3.getPosition().x <= 1100.0f && circle3.getPosition().y >= 100 && circle3.getPosition().y <= 100.0f)
				{
					circle3.setPosition(
						circle3.getPosition().x +
						(circle3Speed * 0.001f),
						100);
				}
				//from up to bottom
				if (circle3.getPosition().y >= 100.0f && circle3.getPosition().y <= 700.0f && circle3.getPosition().x >= 1100.0f && circle3.getPosition().x <= 1100.0f)
				{
					circle3.setPosition(
						1100,
						circle3.getPosition().y +
						(circle3Speed * 0.001f));
				}
			}

			if (!circle4Active)
			{

				circle4Active = true;

			}
			else	// Move the circle
			{

				
				//from bottom to left
				if (circle4.getPosition().y >= 100.0f && circle4.getPosition().y <= 700.0f && circle4.getPosition().x >= 500.0f && circle4.getPosition().x <= 500.0f)
				{
					circle4.setPosition(
						500,
						circle4.getPosition().y -
						(circle4Speed *0.001f));
				}
				//from left to right
				if (circle4.getPosition().x >= 500 && circle4.getPosition().x <= 1100.0f && circle4.getPosition().y >= 100 && circle4.getPosition().y <= 100.0f)
				{
					circle4.setPosition(
						circle4.getPosition().x +
						(circle4Speed * 0.001f),
						100);
				}
				//from up to bottom
				if (circle4.getPosition().y >= 100.0f && circle4.getPosition().y <= 700.0f && circle4.getPosition().x >= 1100.0f && circle4.getPosition().x <= 1100.0f)
				{
					circle4.setPosition(
						1100,
						circle4.getPosition().y +
						(circle4Speed * 0.001f));
				}
				//from right to left
				if (circle4.getPosition().x >= 500 && circle4.getPosition().x <= 1100.0f && circle4.getPosition().y >= 700.0f && circle4.getPosition().y <= 700.0f)
				{
					circle4.setPosition(
						circle4.getPosition().x -
						(circle4Speed * 0.001f),
						700);
				}
			}

			/*if (!circle2Active)
			{
				
				circle2Active = true;

			}
			else
				// Move the circle
			{

				//from left to right
				if (circle2.getPosition().x > 499 && circle2.getPosition().x < 1099.0f && circle2.getPosition().y > 99 && circle2.getPosition().y <101.0f)
				{
					circle2.setPosition(
						circle2.getPosition().x +
						(circle2Speed * dt.asSeconds()),
						100);
				}
				//from up to bottom
				if (circle2.getPosition().y > 99.0f && circle2.getPosition().y < 699.0f && circle2.getPosition().x > 1099.0f && circle2.getPosition().x <= 1100.0f)
				{
					circle2.setPosition(
						1100,
						circle2.getPosition().y +
						(circle2Speed * dt.asSeconds()));
				}
				//from right to left
				if (circle2.getPosition().x > 500 && circle2.getPosition().x < 1101.0f && circle2.getPosition().y > 699.0f && circle2.getPosition().y <= 700.0f)
				{
					circle2.setPosition(
						circle2.getPosition().x -
						(circle2Speed * dt.asSeconds()),
						700);
				}
				//from bottom to left
				if (circle2.getPosition().y > 100.0f && circle2.getPosition().y <= 700.0f && circle2.getPosition().x >= 499.0f && circle2.getPosition().x < 501.0f)
				{
					circle2.setPosition(
						500,
						circle2.getPosition().y -
						(circle2Speed * dt.asSeconds()));
				}
			}

			if (!circle3Active)
			{

				circle3Active = true;

			}
			else
				// Move the circle
			{

				//from left to right
				if (circle3.getPosition().x > 499 && circle3.getPosition().x < 1099.0f && circle3.getPosition().y > 99 && circle3.getPosition().y <101.0f)
				{
					circle3.setPosition(
						circle3.getPosition().x +
						(circle3Speed * dt.asSeconds()),
						100);
				}
				//from up to bottom
				if (circle3.getPosition().y > 99.0f && circle3.getPosition().y < 699.0f && circle3.getPosition().x > 1099.0f && circle3.getPosition().x <= 1100.0f)
				{
					circle3.setPosition(
						1100,
						circle3.getPosition().y +
						(circle3Speed * dt.asSeconds()));
				}
				//from right to left
				if (circle3.getPosition().x > 500 && circle3.getPosition().x < 1101.0f && circle3.getPosition().y > 699.0f && circle3.getPosition().y <= 700.0f)
				{
					circle3.setPosition(
						circle3.getPosition().x -
						(circle3Speed * dt.asSeconds()),
						700);
				}
				//from bottom to left
				if (circle3.getPosition().y > 100.0f && circle3.getPosition().y <= 700.0f && circle3.getPosition().x >= 499.0f && circle3.getPosition().x < 501.0f)
				{
					circle3.setPosition(
						500,
						circle3.getPosition().y -
						(circle3Speed * dt.asSeconds()));
				}
			}

			if (!circle4Active)
			{

				circle4Active = true;

			}
			else
				// Move the circle
			{

				//from left to right
				if (circle4.getPosition().x > 499 && circle4.getPosition().x < 1099.0f && circle4.getPosition().y > 99 && circle4.getPosition().y <101.0f)
				{
					circle4.setPosition(
						circle4.getPosition().x +
						(circle4Speed * dt.asSeconds()),
						100);
				}
				//from up to bottom
				if (circle4.getPosition().y > 99.0f && circle4.getPosition().y < 699.0f && circle4.getPosition().x > 1099.0f && circle4.getPosition().x <= 1100.0f)
				{
					circle4.setPosition(
						1100,
						circle4.getPosition().y +
						(circle4Speed * dt.asSeconds()));
				}
				//from right to left
				if (circle4.getPosition().x > 500 && circle4.getPosition().x < 1101.0f && circle4.getPosition().y > 699.0f && circle4.getPosition().y <= 700.0f)
				{
					circle4.setPosition(
						circle4.getPosition().x -
						(circle4Speed * dt.asSeconds()),
						700);
				}
				//from bottom to left
				if (circle4.getPosition().y > 100.0f && circle4.getPosition().y <= 700.0f && circle4.getPosition().x >= 499.0f && circle4.getPosition().x < 501.0f)
				{
					circle4.setPosition(
						500,
						circle4.getPosition().y -
						(circle4Speed * dt.asSeconds()));
				}
			}
			*/
		}
	

		
		// Clear everything from the last frame
		window.clear();

		// Draw our game scene here
		window.draw(spriteBackground);

		// Draw the clouds
		window.draw(circle1);
		window.draw(circle2);
		window.draw(circle3);
		window.draw(circle4);
		window.draw(speed1);
		window.draw(speed2);
		window.draw(speed3);
		window.draw(speed4);
		window.draw(Text1);
		window.draw(Text2);
		window.draw(Text3);
		window.draw(Text4);
		
		if (!rotation)
		{
			window.draw(clockwise);
		}
		else
		{

			window.draw(anticlockwise);
		}
		
		
		if (paused)
		{
			// Draw our message
			window.draw(messageText);
		}

		window.display();

	}
	return 0;
}
