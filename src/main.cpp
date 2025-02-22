#include <iostream>
#include <limits>
#include "game.h"

using namespace std;


int main() 
{
	//change per platform
	system("clear");
	string errorMessage = "Please select an option.\n"; //Error message is used to print program status on main menu under the title
    cout << "This is a Picross program written in C++ for a linux terminal\nWritten by: Joshua Stimpert\n\n";
	//Mode Select Screen Loop
	while(true){
		system("clear");
		cout << R"(

		 /$$$$$$$$         /$$$$$$                                     
		|__  $$__/        /$$__  $$                                    
		   | $$  /$$$$$$ | $$  \__//$$   /$$                           
		   | $$ /$$__  $$| $$$$   | $$  | $$                           
		   | $$| $$  \ $$| $$_/   | $$  | $$                           
		   | $$| $$  | $$| $$     | $$  | $$                           
		   | $$|  $$$$$$/| $$     |  $$$$$$/                           
		   |__/ \______/ |__/      \______/                            
                                                               
                                                               
                                                               
 /$$$$$$$  /$$                                                 
| $$__  $$|__/                                                 
| $$  \ $$ /$$  /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$$ /$$$$$$$
| $$$$$$$/| $$ /$$_____/ /$$__  $$ /$$__  $$ /$$_____//$$_____/
| $$____/ | $$| $$      | $$  \__/| $$  \ $$|  $$$$$$|  $$$$$$ 
| $$      | $$| $$      | $$      | $$  | $$ \____  $$\____  $$
| $$      | $$|  $$$$$$$| $$      |  $$$$$$/ /$$$$$$$//$$$$$$$/
|__/      |__/ \_______/|__/       \______/ |_______/|_______/ 
					   2025 - Tofu Shop
					Github: jStimpert0430
)";
		char uInput;
		cout << endl << endl << errorMessage;
		cout << "(n)ew game, (c)ontinue, (q)uit\n\n>>";
		cin.get(uInput);
		bool isValid = true;
    	switch(tolower(uInput)){
	 		case 'n':
	 			cout << "Creating new game - stub...\n\n\n";
	  			{
					Game gameInstance;
					gameInstance.initializeGame();
	  			}
	  			break;
	 		case 'c':
	  			cout << "Continuing old game - stub...\n\n\n";
	  			break;
	 		case 'q':
	  			cout << "Closing the program - stub...";
	  			break;
			case '\n':
				errorMessage = "\x1B[31mInput cannot be blank, Please select an option.\033[0m\n";
				isValid = false;
				break;
	 		default:
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore is used here to clear cin of the new line character so cin.get() doesn't pull on next loop and send the wrong error message
	  			errorMessage = "\x1B[31mThis is not a valid option choice.\033[0m\n";
	  			isValid = false;
    	}
		if(isValid){
	  		break;
		}
    }
	cout << "The program will close now.\n";
    return 0;
}


