
Name: Alex Bochman	

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
 
This assignment expands upon PS3a by implementing the motion of celestial bodies.
This is accomplished by performing the necessary calculations to find: delta x/y, distance,
net force in the x/y directions, acceleration, velocity, and position. These calculations
build upon one another to determine a single body's position relative to every other body.
 
  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

 
The key algorithm in this assignment would be calculating all the variables (dX, dY, xAccel, yAccel, ect)
properly, and in the correct order. Additionally, these needs to be done for every body [i] with every other
body [j], where [i] does not equal [j]. 

for(int i = 0; i < numBodies; ++i) {
	for(int j; j < numbBodies; ++j) {
		if(i != j ) {
		
		// Calculate delta x/y, distance, net force, AND SUM net force x, net force y
		}
	}
// Calcualte acceleration and velocity for body [i], and set the new velocity
}

(for int i = 0; i < numBodies; ++i) {
	// Call step functionion (This function calculates the new position and updates)
	// Call draw function to draw bodies to the screen.
}


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/

Smart Pointers:

	vector <unique_ptr<Body>> bodyVector;
	for (int i = 0; i < nBody; ++i) {
		cin >> xPos >> yPos >> xVel >> yVel >> mass >> fileName;			
		unique_ptr <Body> tempBody = make_unique<Body>(radius, sf::Vector2u(640, 480), xPos, yPos, xVel, yVel, mass, fileName);
		bodyVector.push_back(move(tempBody));
	}

How I implemented smart pointers in PS3b: 

	//Calculating delta x, delta y, and distance
	double dX = bodyVector.at(j)->getXpos() - bodyVector.at(i)->getXpos();
	double dY = bodyVector.at(j)->getYpos() - bodyVector.at(i)->getYpos();
	double dist = sqrt((dX * dX) + (dY * dY));

In the above code, I'm using the pointers in my bodyVector that are pointing to
the actual object. I'm grabbing the values of the individual bodies when I need them,
and likewise, setting them when they need to be set. 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Not summing my forces, and implementing the updated positions caused my 
bodies to not draw within the FOV of the screen.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 
 make
 
 ./[Executable] [TOTAL_TIME] [STEP_TIME] < [.txt FILE]
 ./NBody 157788000.0 25000.0 < planets.txt 
 
 
 //for xming
 -open xming
 -in terminal run: DISPLAY=:0.0
 
 
 