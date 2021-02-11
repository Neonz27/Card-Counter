#include "Deck.hpp"
#include "Utility.hpp"
#include <iostream>


/*
I am quite aware that the code for this is messy.
I wrote it while I was bored & sleep-deprived.
Just cut me some slack, will ya? \(o-o)/
*/

const unsigned short get_choice() {
	std::cout 
		<< "1. Add Card" << std::endl 
		<< "2. Remove Card" << std::endl
		<< "3. Close Program" << std::endl
		<< "Your Choice: ";

	unsigned short choice;
	std::cin >> choice;

	return choice;
}

const std::string get_card_name() {
	clear_console();

	std::cout << "Card Name: ";
		
	std::string card_name;
	std::cin >> card_name;

	return card_name;
}

int main() {
	std::vector<card> standard_cards = {
		std::make_tuple("Ace", 4, 0.0f),
		std::make_tuple("Two", 4, 0.0f),
		std::make_tuple("Three", 4, 0.0f),
		std::make_tuple("Four", 4, 0.0f),
		std::make_tuple("Five", 4, 0.0f),
		std::make_tuple("Six", 4, 0.0f),
		std::make_tuple("Seven", 4, 0.0f),
		std::make_tuple("Eight", 4, 0.0f),
		std::make_tuple("Nine", 4, 0.0f),
		std::make_tuple("Ten", 4, 0.0f),
		std::make_tuple("Jack", 4, 0.0f),
		std::make_tuple("Queen", 4, 0.0f),
		std::make_tuple("King", 4, 0.0f)
	};

	Deck example_deck(standard_cards, 52);

	bool is_playing = true;
	while(is_playing) {
		clear_buffer();
		clear_console();
		
		example_deck.get_probabilities();

		std::cout << std::endl;

		const unsigned short choice = get_choice();

		if(choice == 1) {
			const std::string card_name = get_card_name();
			example_deck.add_card_copy(card_name);
		} else if(choice == 2) {
			const std::string card_name = get_card_name();
			example_deck.remove_card_copy(card_name);
		} else if(choice == 3) {
			is_playing = false;
		}
	}

	return 0;
}