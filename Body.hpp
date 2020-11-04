
#include <string>


#ifndef BODY_H
#define BODY_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Body : public sf::Drawable
{
public:
	Body();	//Default Constructor
	Body(float rad, sf::Vector2u winSize, float xp, float yp, float xv, float yv, float m, std::string s);

	void setXpos(float xp);
	void setYpos(float yp);
	void setXvel(float xv);
	void setYvel(float yv);
	void setMass(float m);
	void setRadius(float r);
	void setWinSize(sf::Vector2u ws);
	void setFileName(std::string s);

	float getXpos();
	float getYpos();
	float getXvel();
	float getYvel();
	float getMass();
	float getRadius();
	sf::Vector2u getWinSize();
	sf::Sprite getPlanetSprite();
	std::string getFileName();

	void step(const double stepT);
	void print();

private:
	float xPos;
	float yPos;
	float xVel;
	float yVel;
	float mass;
	float radius;
	sf::Vector2u winSize;
	sf::Texture planetTexture;
	sf::Sprite planetSprite;
	std::string fileName;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif