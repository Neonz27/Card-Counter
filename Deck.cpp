#include "Deck.hpp"
#include <iomanip>
#include <iostream>

Deck::Deck(
	std::vector<card> cards,
	unsigned short deck_size
) :
	m_cards(cards),
	m_deck_size(deck_size)
{
	set_probabilities();
}

void Deck::set_probabilities() {
	for(card& card : m_cards)
		std::get<2>(card) = (static_cast<float>(std::get<1>(card)) / static_cast<float>(m_deck_size)) * 100.f;
}

void Deck::get_probabilities() const {
	for(card card : m_cards)
		std::cout << std::setprecision(2) << std::fixed
			<< std::get<0>(card) << ": " << std::get<2>(card) << "%" << std::endl;
}