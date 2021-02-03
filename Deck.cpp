#include "Deck.hpp"
#include <iomanip>
#include <iostream>

Deck::Deck(
	std::vector<card> cards,
	unsigned short deck_size
) :
	m_cards(cards),
	m_deck_size(deck_size)
{}

void Deck::calculate_probabilities() {
	for(card& card : m_cards)
		std::get<2>(card) = (static_cast<float>(std::get<1>(card)) / static_cast<float>(m_deck_size)) * 100.f;
}

void Deck::get_probabilities() {
	calculate_probabilities();

	for(card card : m_cards)
		std::cout << std::setprecision(2) << std::fixed
			<< std::get<0>(card) << ": " << std::get<2>(card) << "%" << std::endl;
}

card& Deck::find_card(const std::string& card_name) {
	struct CardDoesntExist : public std::exception {
		const char* what() const throw() {
			return "That card does not exist within the currently selected deck!";
		}
	};

	try {
		for(card& card : m_cards)
			if(std::get<0>(card) == card_name)
				return card;

		throw CardDoesntExist();
	} catch(CardDoesntExist exception) {
		std::cerr << exception.what() << std::endl;
	}
}

void Deck::add_card_copy(const std::string& card_name) {
	card& card = find_card(card_name);
	std::get<1>(card) += 1;
	m_deck_size += 1;
}

void Deck::remove_card_copy(const std::string& card_name) {
	card& card = find_card(card_name);
	std::get<1>(card) -= 1;
	m_deck_size -= 1;
}