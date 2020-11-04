
#include "Body.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

int main(int argc, char *argv[])
{
	const double G = 6.67e-11;
	const double TOTAL_TIME = stoi(argv[1]);
	const double stepTime = stoi(argv[2]);
	cout << G << TOTAL_TIME << stepTime << endl;

	int nBody;		 // number of planets
	float radius;	 // universe/window radius
	float xPos;		 // x position of planet
	float yPos;		 // y position of planet
	float xVel;		 // x velocity of planet
	float yVel;		 // y velocity of planet
	float mass;		 // planet mass
	string fileName; // file name for .gif file
	cin >> nBody;
	cin >> radius;

	vector<unique_ptr<Body>> bodyVector;
	for (int i = 0; i < nBody; ++i)
	{
		cin >> xPos >> yPos >> xVel >> yVel >> mass >> fileName;
		unique_ptr<Body> tempBody = make_unique<Body>(radius, sf::Vector2u(640, 480), xPos, yPos, xVel, yVel, mass, fileName);
		bodyVector.push_back(move(tempBody));
	}

	int elapsedTime = 0;
	RenderWindow window(VideoMode(640, 480), "----- NBody Simulation -----");
	while (window.isOpen() && elapsedTime < TOTAL_TIME)
	{
		for (Event event; window.pollEvent(event);)
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.setFramerateLimit(60);
		window.clear(sf::Color::Black);

		//for every body (body1), make calculations relative to every other body (body2) ...
		//... where body1 does not equal body2.
		for (int i = 0; i < nBody; ++i)
		{
			double xF = 0;
			double yF = 0;

			for (int j = 0; j < nBody; ++j)
			{
				if (i != j)
				{

					//Calculating delta x, delta y, and distance
					double dX = bodyVector.at(j)->getXpos() - bodyVector.at(i)->getXpos();
					double dY = bodyVector.at(j)->getYpos() - bodyVector.at(i)->getYpos();
					double dist = sqrt((dX * dX) + (dY * dY));

					//Calculating the net force, force in x direction, and force in y direction
					double netF = (G * bodyVector.at(i)->getMass() * bodyVector.at(j)->getMass()) / (dist * dist);
					xF += netF * (dX / dist);
					yF += netF * (dY / dist);
				}
			}

			//Calculating the x and y accelerations
			double xAccel = xF / bodyVector.at(i)->getMass();
			double yAccel = yF / bodyVector.at(i)->getMass();

			//Using all of the above equations to calculate and set
			// the new x and y velocities for bodyVector.at(i)
			double tempXvel = bodyVector.at(i)->getXvel() + (stepTime * xAccel);
			double tempYvel = bodyVector.at(i)->getYvel() - (stepTime * yAccel);
			bodyVector.at(i)->setXvel(tempXvel);
			bodyVector.at(i)->setYvel(tempYvel);
		}

		for (int i = 0; i < nBody; ++i)
		{
			bodyVector.at(i)->step(stepTime);
			window.draw(bodyVector.at(i)->getPlanetSprite());
		}

		window.display();
		elapsedTime++;

		cout << "\n========================== STEP NUMBER " << elapsedTime << " ==========================" << endl;
		cout << nBody << endl;
		cout << radius << endl;
		for (int i = 0; i < nBody; ++i)
		{
			bodyVector.at(i)->print();
		}
	}
	cout << "\nElapsed Time: " << elapsedTime << endl;
	cout << "Total Time: " << TOTAL_TIME << endl;
}
