/* Sakif Chowdhury
 * CISC 1600
 * Campus Travel Game
 * Last Edited Valentines Day
 * Professor Dakota Hernandez
*/

#include <iostream>
using namespace std;
int main () {
	int distance = 14;
	int turns = 4;
	int transport;

	while (turns >0) {
		cout << "Choose your transport! (1=Bus, 2=Subway, 3=Jetpack):";
		cin >> transport;
	
	while (transport < 1 || transport > 3) {
		cout << "Invalid input. Choose your transport! (1=Bus, 2=Subway, 3=Jetpack): ";
		cin >> transport;

	switch (transport) {
		case 1: distance -= 2; break;
		case 2: distance -= 5; break;
		case 3: distance -= 10; break;
	}

	cout << "Distance remaining; " << distance << "miles." << endl;

	if (distance ==0) {
		cout << "You have won!" << endl;
		return 0;
	} else if (distance < 0) {
		cout <, "You have overshot your target! You lose!" endl;
		return 0;
	}

	turns--;

	}

	cout << "You haven't reached your target! You lose!" << endl;
	return 0;
}
