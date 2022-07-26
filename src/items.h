//
// Created by christian on 7/26/22.
//

#ifndef MCDONALDS_SRC_ITEMS_H_
#define MCDONALDS_SRC_ITEMS_H_

#include <array>


/*
 * Enums are used as an inbetween for the types
 * Instead of having to parse strings each time, we only do each once
 */

// enum for allowed burger types, unknown will become UNKNOWN_BURGER
enum Burger {
  Big_Mac,
  Quarter_Pounder_with_Cheese,
  BLT_Quarter_Pounder,
  Bacon_Habanero_Ranch_Quarter_Pounder,
  Bacon_and_Cheese_Quarter_Pounder,
  Deluxe_Quarter_Pounder,
  Double_Quarter_Pounder_with_Cheese,
  Hamburger,
  Cheeseburger,
  Grilled_Onion_Cheddar_Burger,
  Double_Cheeseburger,
  McDouble,
  Daily_Double,
  McRib,
  UNKNOWN_BURGER,
};

std::array


// enum for allowed wraps, unknown will become UNKNOWN_WRAP
enum Wrap {
  McWrap_Chicken,
  McWrap_Sweet_Chili_Chicken,
  Chipotle_BBQ_Snack_Wrap,
  Honey_Mustard_Snack_Wrap,
  Ranch_Snack_Wrap,
  Mac_Snack_Wrap,
  UNKNOWN_WRAP,
};

// enum for allowed Chicken and fish, unknown will become UNKNOWN_C_F
enum Chicken_Fish {
  Chicken_McNuggets,
  Chicken_Classic_Sandwich,
  Chicken_Club,
  Premium_Crispy_Chicken_Ranch_BLT_Sandwich,
  McChicken,
  Southern_Style_Chicken,
  Filet_O_Fish,
  UNKNOWN_C_F,
};

// enum for allowed Drinks, unknown will become UNKNOWN_DRINK
enum Drinks {
  Coffee,
  Latte,
  Mocha,
  Caramel_Mocha,
  Hot_Chocolate,
  Iced_Coffee,
  Iced_Mocha,
  Iced_Caramel_Mocha,
  Frappe_Mocha,
  Frappe_Caramel,
  Frappe_Chocolate_Chip,
  Blueberry_Pomegranate_Smoothie,
  Strawberry_Banana_Smoothie,
  Mango_Pineapple_Smoothie,
  Frozen_Strawberry_Lemonade,
  Cherry_Berry_Chiller,
  Vanilla_Shake,
  Chocolate_Shake,
  Strawberry_Shake,
  Dulce_de_Leche_Shake,
  UNKNOWN_DRINK,
};

#endif //MCDONALDS_SRC_ITEMS_H_
