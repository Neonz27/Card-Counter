#pragma once

#include <string>
#include <tuple>

/// <summary>
/// A tuple that contains a card's name, quantity, and likelihood to be drawn.
/// </summary>
using card = std::tuple<
	const std::string, // Card Name
	unsigned short int, // Card Quantity
	float // Card Draw (%) 
>;