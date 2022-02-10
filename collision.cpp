#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

bool collision(int x,int y);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Base Code");

    //variables for red square
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(200, 200));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(200, 200);

    //variables for blue square
    sf::RectangleShape shape2;
    shape2.setSize(sf::Vector2f(100, 100));
    shape2.setFillColor(sf::Color::Blue);
    shape2.setPosition(200, 200);

    sf::Vector2i position; //creates a vector we'll use to hold the mouse position

    while (window.isOpen())//GAME LOOP--------------------------------
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // get global mouse position
            position = sf::Mouse::getPosition(window);//gets and stores mouse position coordinates
        }


        //uncomment this if it helps!
        //cout << "mouse is at "<<position.x<<" , "<<position.y << endl;
        shape2.setPosition(position.x, position.y); //this gets the shape to follow the mouse
        //if (collision(position.x) == 1)
        //    position.x = 400;

        cout << collision(position.x, position.y) << endl;

        //render section
        window.clear();
        window.draw(shape2);
        window.draw(shape);
        window.display();
    }//end game loop-------------------------------------------------

    return 0;
} //end main

bool collision(int x,int y) {
    if (x < 400 && x+100>200 && y+100 > 200 && y  < 400)
        return 1;
    else
        return 0;
}
