#include "Deck.hpp"

Deck::Deck(
	const unsigned int deck_size,
	deck const& cards
) :
	m_deck_size(deck_size),
	m_cards(cards)
{}

const float Deck::calculate_probability(const unsigned int remaining) {
	return ((float)remaining / (float)m_deck_size) * 100;
}

const float Deck::get_probability(std::string const& card) {
	for(deck::iterator iterator = m_cards.find(card); iterator != m_cards.end(); iterator++)
		return calculate_probability(iterator->second);
}

probabilities Deck::get_probabilities() {
	probabilities card_probabilities;

	for(deck::iterator iterator = m_cards.begin(); iterator != m_cards.end(); iterator++)
		card_probabilities.insert({ iterator->first, calculate_probability(iterator->second)});

	return card_probabilities;
}