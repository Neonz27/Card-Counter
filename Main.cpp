#include "Deck.hpp"

int main() {
	std::vector<card> standard_cards = {
		std::make_tuple("One", 4, 0.0f),
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

	example_deck.get_probabilities();

	return 0;
}