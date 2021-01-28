#include "Deck.hpp"
#include <iomanip>
#include <iostream>

int main() {
	deck standard_deck {
		{"Ace", 4},
		{"Two", 4},
		{"Three", 4},
		{"Four", 4},
		{"Five", 4},
		{"Six", 4},
		{"Seven", 4},
		{"Eight", 4},
		{"Nine", 4},
		{"Ten", 4},
		{"Jack", 4},
		{"Queen", 4},
		{"King", 4}
	};

	Deck example_deck(52, standard_deck);

	probabilities example_probabilities = example_deck.get_probabilities();

	for(probabilities::iterator iterator = example_probabilities.begin(); iterator != example_probabilities.end(); iterator++)
		std::cout << std::setprecision(2) << std::fixed << iterator->first << ": " << iterator->second << "%" << std::endl;

	return 0;
}