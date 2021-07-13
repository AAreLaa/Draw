#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>


int main()
{
    int i=0;
    std::vector<double>x;
    std::vector<double>y;
    std::vector<sf::VertexArray> vertices; 
    vertices.push_back(sf::VertexArray()); 
    vertices[0].setPrimitiveType(sf::LinesStrip); 
    int lines_number = 0; 
    int condition = false; 

    sf::Color pencolor = sf::Color::White;
    
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Draw Here(Press E/cross button to exit) ", sf::Style::Close); 
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::KeyPressed) 
                if(event.key.code == sf::Keyboard::Key::E)
                    window.close();
            if (event.type == sf::Event::Closed) 
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) 
            {
                condition = true;
                
            }

            if (event.type == sf::Event::MouseButtonReleased) 
            {
                lines_number++; 
                vertices.push_back(sf::VertexArray());
                vertices[lines_number].setPrimitiveType(sf::LinesStrip);
                condition = false; 
            }
        }

        if (condition) 
        {
            
            vertices[lines_number].append(sf::Vertex(sf::Vector2f(sf::Mouse::getPosition(window).x  , sf::Mouse::getPosition(window).y ), pencolor));
            if (event.type == sf::Event::MouseMoved )
              {
               x.push_back(sf::Mouse::getPosition(window).x );
               y.push_back(sf::Mouse::getPosition(window).y); 
               std::cout<<"("<<x[i]<<" , "<<y[i]<<')'<<std::endl;
               i++;
              }
        }

        window.clear(sf::Color::Black); 
        
        
        for (int i = 0; i < vertices.size(); i++)
        {
            window.draw(vertices[i]);
        }

        window.display();
    }


    return 0;
}