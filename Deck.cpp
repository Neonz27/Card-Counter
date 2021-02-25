#include "Deck.hpp"
#include "Utility.hpp"
#include <algorithm>
#include <iomanip>

Deck::Deck(
	std::vector<card>& cards,
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
			<< std::get<2>(card) << "%" << " | "
			<< std::get<1>(card) << " | "
			<< std::get<0>(card) << std::endl;
}

card& Deck::find_card(const std::string& card_name) {
	auto get_lowercase = [](const std::string& card_name) -> const std::string {
		std::string lowercase_card_name = card_name;
		
		std::transform(
			lowercase_card_name.begin(),
			lowercase_card_name.end(),
			lowercase_card_name.begin(),
			[](char letter) {
				return std::tolower(letter);
			}
		);

		return lowercase_card_name;
	};

	for(card& card : m_cards)
		if(get_lowercase(std::get<0>(card)) == get_lowercase(card_name))
			return card;

	throw CardDoesntExist();
}

void Deck::add_card_copy(const std::string& card_name) {
	try {
		std::get<1>(find_card(card_name)) += 1;
		m_deck_size += 1;
	} catch(CardDoesntExist exception) {
		std::cerr << exception.what() << std::endl;
		pause_console();
	}
}

void Deck::remove_card_copy(const std::string& card_name) {
	try {
		std::get<1>(find_card(card_name)) -= 1;
		m_deck_size -= 1;
	} catch(CardDoesntExist exception) {
		std::cerr << exception.what() << std::endl;
		pause_console();
	}
}