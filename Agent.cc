// Agent.cc


#include <iostream>
#include "Agent.h"

using namespace std;

Agent::Agent ()
{

	 
}

Agent::~Agent ()
{

}

void Agent::Initialize ()
{
	hasGold = false;
	hasArrow = false;
	location = std::make_pair(1, 1);
	orientation = 'r';
}

Action Agent::Process (Percept& percept)
{

	Action action;

    // a. If the Glitter percept is True, then execute the GRAB action.
	// b. If the agent is in the (1,1) location and has the gold, then CLIMB.
	// c. If the agent has an arrow, and the agent is in the top row (Y=4), and the agent’s
	// orientation=RIGHT, then SHOOT.
	// d. If the agent has an arrow, and the agent is in the rightmost column (X=4), and the
	// agent’s orientation=UP, then SHOOT.
	// e. If none of the above conditions are met, then the agent should randomly choose one
	// of the actions: GOFORWARD, TURNLEFT, TURNRIGHT.
	if (percept.Glitter == true) {
		action = GRAB;
		hasGold = true;
	} else if (hasGold == true && location == std::make_pair(1,1)) {
		action = CLIMB;
	} else if (hasArrow == true && orientation == 'r' && location.second == 4){
		action = SHOOT;
	} else if (hasArrow == true && orientation == 'u' && location.first == 4) {
		action = SHOOT;
	} else {
		action = (Action) (rand() % 3);	
		// if agent chooses to go forward update the location coordinates based on 
		// current location and orientation 
		if (action == 0) {
			switch (orientation)
			{
			  case 'r':
				if (location.first != 4)
					location.first++;
				break;
			  case 'l':
				if (location.first != 1)
					location.first--;
				break;
			  case 'u':
				if (location.second != 4)
					location.second++;
				break;
			  case 'd':
				if (location.second != 1)
					location.second--;
				break;
			}
		}
		// turning left based on the current orientation
		if (action == 1) {
			switch (orientation)
			{
			  case 'r':
				orientation = 'u';
				break;
			  case 'l':
				orientation = 'd';
				break;
			  case 'u':
				orientation = 'l';
				break;
			  case 'd':
				orientation = 'r';
				break;
			}
		}
		// turing right based on the current orientation
		if (action == 2)
		{
			switch (orientation)
			{
			  case 'r':
				orientation = 'd';
				break;
			  case 'l':
				orientation = 'u';
				break;
			  case 'u':
				orientation = 'r';
				break;
			  case 'd':
				orientation = 'l';
				break;
			}
		}
	}


	return action;
	// char c;
	// Action action;
	// bool validAction = false;

	// while (! validAction)
	// {
	// 	validAction = true;
	// 	cout << "Action? ";
	// 	cin >> c;
	// 	if (c == 'f') {
	// 		action = GOFORWARD;
	// 	} else if (c == 'l') {
	// 		action = TURNLEFT;
	// 	} else if (c == 'r') {
	// 		action = TURNRIGHT;
	// 	} else if (c == 'g') {
	// 		action = GRAB;
	// 	} else if (c == 's') {
	// 		action = SHOOT;
	// 	} else if (c == 'c') {
	// 		action = CLIMB;
	// 	} else {
	// 		cout << "Huh?" << endl;
	// 		validAction = false;
	// 	}
	// }
	// return action;
}

void Agent::GameOver (int score)
{

}

