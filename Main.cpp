#include "Parser.hpp"
#include "Deck.hpp"
#include "Utility.hpp"

/// <summary>
/// Asks the user which deck file to parse card data from.
/// </summary>
/// <returns>The name of the deck file the user chose.</returns>
const std::string get_deck_file() {
	clear_buffer();
	clear_console();

	std::cout << "Deck File (Case Sensitive): ";

	std::string deck_file;
	getline(std::cin, deck_file);

	return deck_file;
}

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
/// Asks the user which card they wish to select from the deck.
/// </summary>
/// <returns>The name of the card selected by the user.</returns>
const std::string get_card_name() {
	clear_buffer();
	clear_console();

	std::cout << "Card Name: ";
		
	std::string card_name;
	getline(std::cin, card_name);

	return card_name;
}

int main() {
	try {
		Parser parser(get_deck_file());
		Deck deck(parser.m_cards, parser.m_card_quantity);

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
	} catch(DeckFileDoesntExist exception) {
		std::cerr << exception.what() << std::endl;
		pause_console();

		return 1;
	}

	return 0;
}