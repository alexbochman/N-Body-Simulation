
#include "Body.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <iostream>

using namespace std;

Body::Body()
{
	xPos = 0, yPos = 0, xVel = 0, yVel = 0, mass = 0;
	fileName = "";
}

Body::Body(float rad, sf::Vector2u winSize, float xp, float yp, float xv, float yv, float m, std::string s)
{
	xPos = xp, yPos = yp; // (x, y) position
	xVel = xv, yVel = yv; // (x, y) velocity
	mass = m;
	radius = rad;
	fileName = s;

	//set image
	sf::Image image;
	image.loadFromFile(fileName);
	planetTexture.loadFromImage(image);
	planetSprite.setTexture(planetTexture);

	//Set sprite origin
	planetSprite.setOrigin(planetTexture.getSize().x / 2, planetTexture.getSize().y / 2);

	//Set origin
	float xWinRadius = winSize.x / 2; //Half of the window along the x-axis
	float yWinRadius = winSize.y / 2; //Half of the window along the y-axis
	float xScalar = (xWinRadius) / rad;
	float yScalar = (yWinRadius) / rad;
	float xOrigin = xPos * xScalar + xWinRadius;
	float yOrigin = yPos * yScalar + yWinRadius;
	planetSprite.setPosition(xOrigin, yOrigin);
}

void Body::setXpos(float xp) { xPos = xp; }

void Body::setYpos(float yp) { yPos = yp; }

void Body::setXvel(float xv) { xVel = xv; }

void Body::setYvel(float yv) { yVel = yv; }

void Body::setMass(float m) { mass = m; }

void Body::setRadius(float r) { radius = r; }

void Body::setWinSize(sf::Vector2u ws) { winSize = ws; }

void Body::setFileName(std::string s) { fileName = s; }

float Body::getXpos() { return xPos; }

float Body::getYpos() { return yPos; }

float Body::getXvel() { return xVel; }

float Body::getYvel() { return yVel; }

float Body::getMass() { return mass; }

float Body::getRadius() { return radius; }

sf::Vector2u Body::getWinSize() { return winSize; }

sf::Sprite Body::getPlanetSprite() { return planetSprite; }

std::string Body::getFileName() { return std::string(); }

void Body::step(const double stepT)
{
	xPos += stepT * xVel; //xpos = xpos + blah
	yPos -= stepT * yVel;

	double xWinRadius = 640 / 2; //Half of the window along the x-axis
	double yWinRadius = 480 / 2; //Half of the window along the y-axis
	double xScalar = (xWinRadius) / radius;
	double yScalar = (yWinRadius) / radius;

	double scaledXpos = (xPos * xScalar) + xWinRadius;
	double scaledYpos = (yPos * yScalar) + yWinRadius;

	planetSprite.setPosition(scaledXpos, scaledYpos);
}

void Body::print()
{
	cout << xPos << " " << yPos << " " << xVel << " " << yVel << " " << mass << " \t" << fileName << endl;
}

void Body::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(Body::planetSprite, states);
}
