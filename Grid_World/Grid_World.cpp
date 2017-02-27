//ME 493 HW 2
//Etzal Corona


#include<iostream>
#include<time.h>
#include<assert.h>
#include<fstream>

#define x  15
#define y  15

using namespace std;



void display_grid(char inarray [x][y]);

void clear_grid(char inarray[x][y]);

void update_grid(int agentx, int agenty, int goalx, int goaly, char inarray[x][y]);

void move_agent(int & agentx, int & agenty, char direction);

void auto_move_agent(int & agentx, int & agenty, int & goalx, int & goaly);

void play_gridworld(char inarray[x][y]);

void simulate_gridworld(char inarray[x][y]);




int main() {

	char Board[x][y];
	srand(time(NULL));

	//Initial Menu
	int choice;
	cout << " Welcome to the Grid World" << endl << " Choose from the following options" << endl << " Click 1 to play game" << endl << " Click 2 for simulation" << endl << " Click 0 to abort Application" << endl << endl;
	cin >> choice; //Taking in the choice the user wants
	

				   //Create an error message for invalid choice and get a second choice
	while ((choice != 1) && (choice != 2) && (choice != 0))
	{
		cout << "Invalid selection.  Please choose 1, 2 or 0: ";
		cin >> choice;
	}

	//if user wants to play, this function will run
	if (choice == 1) {
		play_gridworld(Board);
	}


	if (choice == 2) {
		simulate_gridworld(Board);
	}
	cin >> choice;
}





//This functions displays the grid to the user and for the simulation
void display_grid(char inarray[x][y]) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << inarray[i][j];
		}
		cout << endl;
	}
}





void clear_grid(char inarray[x][y]) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			inarray[i][j] = '_';
		}
	}
}





void update_grid(int agentx, int agenty, int goalx, int goaly,  char inarray[x][y]) {
	clear_grid(inarray);
	inarray[agentx][agenty] = 'A';
	inarray[goalx][goaly] = 'G';
}



void move_agent(int & agentx, int & agenty, char direction) {
	if (direction == 'w') {
		agentx -= 1;
	}
	if (direction == 'a') {
		agenty -= 1;
	}
	if (direction == 's') {
		agentx += 1;
	}
	if (direction == 'd') {
		agenty += 1;
	}

	//These if statments make sure the agent doesn't pass the boundary
	if (agentx < 0) {
		agentx = 0;
	}
	if (agentx >= x) {
		agentx = x - 1;
	}
	if (agenty < 0) {
		agenty = 0;
	}
	if (agenty >= y) {
		agenty = y - 1;
	}
}





//This function is used for when the user actually plays the game
void play_gridworld(char inarray[x][y]) {
	//Declarations
	int agentx;
	int agenty;
	int goalx;
	int goaly;
	char direction;

	//Assigning starting position and goal at random square
	agentx = rand() % (x);
	agenty = rand() % (y);
	goalx = rand() % (x);
	goaly = rand() % (y);

	while (1) {
		clear_grid(inarray);
		update_grid(agentx, agenty, goalx, goaly, inarray);
		display_grid(inarray);
		cout << " Game Ready use w,a,s,d, keys to move piece" << endl << endl;
		cout << " w=up, s= down, a=left, d=right" << endl << endl;
		cin >> direction;
		if (direction == '0') {
			break;
		}
		move_agent(agentx, agenty, direction);

		if ((agentx == goalx) && (agenty == goaly)) {
			cout << " You beat the grid world! " << endl;
			break;
		}
	}
}



void auto_move_agent(int & agentx, int & agenty, int & goalx, int & goaly) {
	if (agentx < goalx) {
		agentx += 1;
	}
	if (agentx > goalx) {
		agentx -= 1;
	}
	if (agenty < goaly) {
		agenty += 1;
	}
	if (agenty > goaly) {
		agenty -= 1;
	}
}



//This function simulates the agent to play the gridworld game
void simulate_gridworld(char inarray[x][y]) {
	//Declarations
	int agentx;
	int agenty;
	int goalx;
	int goaly;

	//Assigning starting position and goal at random square
	agentx = rand() % (x);
	agenty = rand() % (y);
	goalx = rand() % (x);
	goaly = rand() % (y);
	while (1) {
		clear_grid(inarray);
		update_grid(agentx, agenty, goalx, goaly, inarray);
		display_grid(inarray);
		cout << endl << endl;
		auto_move_agent(agentx, agenty, goalx, goaly);
		if ((agentx == goalx) && (agenty == goaly)) {
			cout << " You beat the grid world! " << endl;
			break;
		}
	}
}