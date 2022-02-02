#include <iostream>
#include <iomanip>

using namespace std;

int i, j;

//Defines and Declares Function initialiseArray
void initialiseArray (char [][6]){
	//Initializes 2d array seating to hold '*' in a locations
	for (i = 0; i < 13; i++)
		for (j = 0; j < 6; j++)
			seating[i][j] = '*';
}

//Declare and Defines Function seatConditions
void seatConditions (char seating[][6]){
	//Prints a separator to make to lessen confusion
	cout << "---------------------------------------\n";
	
	//Prints Table Headings
	printf ("%12s %4s %4s %4s %4s %4s \n", "A", "B", "C", "D", "E", "F");
			
		for (i = 0; i < 13; i++) {
			//Prints Row Headings
			printf("%-4s %2d", "Row ", (i + 1));
			
			//Prints '*' or 'x' depending on what is in seating[var][var]
			for (j = 0; j < 6; j++)
				cout << right << setw(5) << seating[i][j];
				
			cout << endl;
		}
		cout << "---------------------------------------\n";
}

//Defines and Declares Function getInputs
void getInputs (char &desiredSeat, int &ticketType){
	//Describes The Table
	cout << "\nAbove are the conditons of the seats. \'*\' means available while \'x\' means taken.\n";
	cout << "Rows 1-2 are First Class. Rows 3-7 are Business Class. Seats 8-13 are Economy Class.\n";
	
	//Gets the class of the seat and which seat the user desires
	cout << "Which Class do you pick? Please enter its row's number(1-13): ";
	cin >> ticketType;
	cout << "Which seat do you choose? Please enter the letter associtated with it(A-F): ";
	cin >> desiredSeat;
}

//Defines and Declares Function seatArrangement
void seatArrangement(int ticketType, int seatPosition, char seating[][6], char &ans){
	//Checks seat availability
	if(seating[ticketType - 1][seatPosition] == '*'){
		//Changes availability of seat
		seating[ticketType - 1][seatPosition] = 'x';
		
		seatConditions(seating);
	
		//Queries whether to loop again or not
		cout << "\nAre you arranging another seat(Y/N): ";
		cin >> ans;
		cout << endl;
   }
   else {
		cout << "\nThis seat is already taken! Please enter another seat.\n";
   }
}

//Defines and Declares Function inputValidate
void inputValidate(char desiredSeat, int ticketType, int &seatPosition, char seating[][6], char &ans) {
	
	//Checks whether inputs are acceptable and does an action
	if ((ticketType > 0) && (ticketType < 14)) {
		
	//Depending on which seat was chosing, below sets it to its respective index
	switch (toupper(desiredSeat)) {
		case 'A': seatPosition = 0;
		seatArrangement(ticketType, seatPosition, seating, ans);
		break;
							
		case 'B': seatPosition = 1;
		seatArrangement(ticketType, seatPosition, seating, ans);
		break;
							
		case 'C': seatPosition = 2;
		seatArrangement(ticketType, seatPosition, seating, ans);
		break;
								
		case 'D': seatPosition = 3;
		seatArrangement(ticketType, seatPosition, seating, ans);
		break;
								
		case 'E': seatPosition = 4;
		seatArrangement(ticketType, seatPosition, seating, ans);
		break;
								
		case 'F': seatPosition = 5;
		seatArrangement(ticketType, seatPosition, seating, ans);
		break;				
		
		default: cout << "\nWhat was entered was not a seat position.\nProceeding to restart data entering phase...\n\n";
   		break;
	}
   }
   else {
   		cout << "\nWhat was entered was not a seat arrangement.\nProceeding to restart data entering phase...\n\n";
   		ans = 'y';
   }
}

int main() {
	//Declares and initialises variables
	char seating[13][6], desiredSeat = 'a', ans = 'y';
	int ticketType = 0, seatPosition = 0;
	
	//Calls Function initialiseArray
	initialiseArray(seating);
			
	cout << "Welcome To Seat Arrangment For Flight X\n";
	
	seatConditions(seating);
	
	do {
		//Calls Functions seatConditions, getInputs and inputValidate
		getInputs(desiredSeat, ticketType);
		inputValidate(desiredSeat, ticketType, seatPosition, seating, ans);
	} while (!(toupper(ans) == 'N'));
	
	//Displays Final Seat Arrangement
	if(toupper(ans) == 'N') {
		cout << "The Final Seat Arrangements Are:\n";
		seatConditions(seating);
	}
	
	return 0;
}
