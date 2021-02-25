#include "Deck.hpp"
#include "Utility.hpp"

/// <summary>
/// Asks the user what their intentions are.
/// </summary>
/// <returns>An integer corresponding to the user's intentions.</returns>
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

/// <summary>
/// Asks the user which card they wish to select.
/// </summary>
/// <returns>The name of the card selected by the user.</returns>
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

	Deck deck(standard_cards, 52);

	bool is_playing = true;
	while(is_playing) {
		clear_buffer();
		clear_console();
		
		deck.get_probabilities();

		std::cout << std::endl;

		const unsigned short choice = get_choice();
		switch(choice) {
			case 1:
				deck.add_card_copy(get_card_name());
				break;

			case 2:
				deck.remove_card_copy(get_card_name());
				break;

			case 3:
				is_playing = false;
				break;
		}
	}

	return 0;
}