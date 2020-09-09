// Agent.h

#ifndef AGENT_H
#define AGENT_H

#include <utility>
#include "Action.h"
#include "Percept.h"

class Agent
{
public:
	Agent ();
	~Agent ();
	void Initialize ();
	Action Process (Percept& percept);
	void GameOver (int score);
	
	bool hasGold;
	bool hasArrow;
	std::pair<int, int> location;
	char orientation;
};

#endif // AGENT_H
