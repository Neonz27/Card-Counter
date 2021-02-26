#pragma once

#include "Card.hpp"
#include <vector>

/// <summary>
/// An exception thrown when the user tells the parser to parse from a deck file that doesn't exist.
/// </summary>
struct DeckFileDoesntExist : public std::exception {
	const char* what() const throw() {
		return "There is no deck file with that name in the same directory as this program!\nPlease press the enter key to continue.";
	}
};

/// <summary>
/// The Parser class is used to parse a deck file containing information such as the name &amp; quantity of each card in a deck.
/// </summary>
class Parser {
	public:
		/// <summary>
		/// The default constructor for the Parser class.
		/// </summary>
		/// <param name="file_name"></param>
		Parser(const std::string& file_name);

		// Public Member Variable(s)
		std::vector<card> m_cards;
		unsigned short int m_card_quantity;
};