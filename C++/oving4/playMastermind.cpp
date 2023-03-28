#include <iostream>
using namespace std;
#include "playMastermind.h"
#include "utilities.h"
#include "tests.h"


void playMastermind() {
	char answer;
	do{	
		int const numberOfTries = 3;
		int const SIZE = 5;
		int const LETTERS = 6;
		char code[SIZE + 1] = {};
		char guess[SIZE + 1] = {};

		randomizeCString(code, SIZE, 'A', 'A' + LETTERS - 1);
		cout << "Fasit: "<<code << endl;
	

		for (int i = 0; i < numberOfTries; i++) {
			readInputToCString(guess, SIZE, 'A', 'A' + LETTERS - 1);
			cout << "Du gjettet: " << guess << endl;

			int numberCorrectPosition = checkCharactersAndPosition(code, guess, SIZE);
			cout << "Antall korrekt plassert: " << numberCorrectPosition << endl;
			int numberCorrectCharacter = checkCharacters(code, guess, SIZE, LETTERS);
			cout << "Antall korrekte, men mulig feil plassert: " << numberCorrectCharacter << endl;

			if (numberCorrectPosition == SIZE - 1) {
				cout << "\nGRATULERER! Du klarte � knekke koden. Du m� v�re et geni." << endl;
				break;
			}
			if (i==numberOfTries-1){
				cout << "\nDu har tapt. Du har brukt dine " << numberOfTries << " fors�k uten � klare � f� alle riktig." <<
					"Koden var "<<code<<"."<<endl;
			}
		}
		cout << "Vil du pr�ve p� ny? Skriv q � avlsutte eller noe annet for nytt fors�k" << endl;
		cin >> answer;
	} while (answer !='q');
}