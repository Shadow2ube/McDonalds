//
// Created by christian on 7/26/22.
//

#ifndef MCDONALDS_SRC_ITEMS_H_
#define MCDONALDS_SRC_ITEMS_H_

#include <array>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

/*
 * Enums are used as an inbetween for the types
 * Instead of having to parse strings each time, we only do each once
 */

enum Item {
  Burgers = 0,
  Wraps = 1,
  ChickenAndFish = 2,
  Drinks = 3,
  Checkout = 4,
  UNKNOWN = -1,
};
vector<tuple<Item, string>> item_strings = {
    {Burgers, "Burgers"},
    {Wraps, "Wraps"},
    {ChickenAndFish, "ChickenAndFish"},
    {Drinks, "Drinks"},
    {Checkout, "Checkout"},
    {UNKNOWN, "UNKNOWN"},
};

const int burger_offset = 0; // how much is required to get to 0
// enum for allowed burger types, unknown will become UNKNOWNBURGER
enum Burger {
  BigMac = 0,
  QuarterPounderwithCheese = 1,
  BLTQuarterPounder = 2,
  BaconHabaneroRanchQuarterPounder = 3,
  BaconAndCheeseQuarterPounder = 4,
  DeluxeQuarterPounder = 5,
  DoubleQuarterPounderwithCheese = 6,
  Hamburger = 7,
  Cheeseburger = 8,
  GrilledOnionCheddarBurger = 9,
  DoubleCheeseburger = 10,
  McDouble = 11,
  DailyDouble = 12,
  McRib = 13,
  UNKNOWNBURGER = -1,
}; // 14 items

const vector<tuple<Burger, string>> burger_strings = {
    {BigMac, "BigMac"},
    {QuarterPounderwithCheese, "QuarterPounderWithCheese"},
    {BLTQuarterPounder, "BLTQuarterPounder"},
    {BaconHabaneroRanchQuarterPounder, "BaconHabaneroRanchQuarterPounder"},
    {BaconAndCheeseQuarterPounder, "BaconAndCheeseQuarterPounder"},
    {DeluxeQuarterPounder, "DeluxeQuarterPounder"},
    {DoubleQuarterPounderwithCheese, "DoubleQuarterPounderWithCheese"},
    {Hamburger, "Hamburger"},
    {Cheeseburger, "Ceeseburger"},
    {GrilledOnionCheddarBurger, "GrilledOnionCheddarBurger"},
    {DoubleCheeseburger, "DoubleCheeseburger"},
    {McDouble, "McDouble"},
    {DailyDouble, "DailyDouble"},
    {McRib, "McRib"},
    {UNKNOWNBURGER, "UNKNOWNBURGER"},
};

const int wrap_offset = 14; // how much is required to get to 0
// enum for allowed wraps, unknown will become UNKNOWN_WRAP
enum Wrap {
  McWrapChicken = 14,
  McWrapSweetChiliChicken = 15,
  ChipotleBBQSnackWrap = 16,
  HoneyMustardSnackWrap = 17,
  RanchSnackWrap = 18,
  MacSnackWrap = 19,
  UNKNOWNWRAP = -1,
}; // 7 items

const vector<tuple<Wrap, string>> wrap_strings = {
    {McWrapChicken, "McWrapChicken"},
    {McWrapSweetChiliChicken, "McWrapSweetChiliChicken"},
    {ChipotleBBQSnackWrap, "ChipotleBBQSnackWrap"},
    {HoneyMustardSnackWrap, "HoneyMustardSnackWrap"},
    {RanchSnackWrap, "RanchSnackWrap"},
    {MacSnackWrap, "MacSnackWrap"},
    {UNKNOWNWRAP, "UNKNOWNWRAP"},
};

const int cf_offset = 20; // how much is required to get to 0
// enum for allowed Chicken and fish, unknown will become UNKNOWNCF
enum Chicken_Fish {
  ChickenMcNuggets = 20,
  ChickenClassicSandwich = 21,
  ChickenClub = 22,
  PremiumCrispyChickenRanchBLTSandwich = 23,
  McChicken = 24,
  SouthernStyleChicken = 25,
  FiletOFish = 26,
  UNKNOWNCF = -1,
}; // 8 items

vector<tuple<Chicken_Fish, string>> c_f_strings = {
    {ChickenMcNuggets, "ChickenMcNuggets"},
    {ChickenClassicSandwich, "ChickenClassicSandwich"},
    {ChickenClub, "ChickenClub"},
    {PremiumCrispyChickenRanchBLTSandwich, "PremiumCrispyChickenRanchBLTSandwich"},
    {McChicken, "McChicken"},
    {SouthernStyleChicken, "SouthernStyleChicken"},
    {FiletOFish, "FiletOFish"},
    {UNKNOWNCF, "UNKNOWNCF"},
};

const int drink_offset = 27; // how much to zero
// enum for allowed Drinks, unknown will become UNKNOWNDRINK
enum Drink {
  Coffee = 27,
  Latte = 28,
  Mocha = 29,
  CaramelMocha = 30,
  HotChocolate = 31,
  IcedCoffee = 32,
  IcedMocha = 33,
  IcedCaramelMocha = 34,
  FrappeMocha = 35,
  FrappeCaramel = 36,
  FrappeChocolateChip = 37,
  BlueberryPomegranateSmoothie = 38,
  StrawberryBananaSmoothie = 39,
  MangoPineappleSmoothie = 40,
  FrozenStrawberryLemonade = 41,
  CherryBerryChiller = 42,
  VanillaShake = 43,
  ChocolateShake = 44,
  StrawberryShake = 45,
  DulcedeLecheShake = 46,
  UNKNOWNDRINK = -1,
}; // 21 items

vector<tuple<Drink, string>> drink_strings = {
    {Coffee, "Coffee"},
    {Latte, "Latte"},
    {Mocha, "Mocha"},
    {CaramelMocha, "CaramelMocha"},
    {HotChocolate, "HotChocolate"},
    {IcedCoffee, "IcedCoffee"},
    {IcedMocha, "IcedMocha"},
    {IcedCaramelMocha, "IcedCaramelMocha"},
    {FrappeMocha, "FrappeMocha"},
    {FrappeCaramel, "FrappeCaramel"},
    {FrappeChocolateChip, "FrappeChocolateChip"},
    {BlueberryPomegranateSmoothie, "BlueberryPomegranateSmoothie"},
    {StrawberryBananaSmoothie, "StrawberryBananaSmoothie"},
    {MangoPineappleSmoothie, "MangoPineappleSmoothie"},
    {FrozenStrawberryLemonade, "FrozenStrawberryLemonade"},
    {CherryBerryChiller, "CherryBerryChiller"},
    {VanillaShake, "VanillaShake"},
    {ChocolateShake, "ChocolateShake"},
    {StrawberryShake, "StrawberryShake"},
    {DulcedeLecheShake, "DulcedeLecheShake"},
    {UNKNOWNDRINK, "UNKNOWNDRINK"},
};

// randomly generated prices
const float prices[47] = {
    8.40,
    3.94,
    7.83,
    7.98,
    9.12,
    1.98,
    3.35,
    7.68,
    2.78,
    5.54,
    4.77,
    6.29,
    3.65,
    5.13,
    9.52,
    9.16,
    6.36,
    7.17,
    1.42,
    6.07,
    0.16,
    2.43,
    1.37,
    8.04,
    1.57,
    4.01,
    1.30,
    1.09,
    9.99,
    2.18,
    5.13,
    8.39,
    6.13,
    2.96,
    6.38,
    5.24,
    4.94,
    9.73,
    2.93,
    7.71,
    5.27,
    7.70,
    4.00,
    8.92,
    2.83,
    3.52,
    4.20,
};

/**
 * @brief Gets the name of a type that is unknown
 * @param i the int index of the type, casting to int will do
 * @return the name as a string
 */
string name_from_possible(int i) {
  if (i >= 0 && i < 14) return get<1>(burger_strings[i - burger_offset]);
  if (i >= 14 && i < 20) return get<1>(wrap_strings[i - wrap_offset]);
  if (i >= 20 && i < 27) return get<1>(c_f_strings[i - cf_offset]);
  if (i >= 27 && i <= 46) return get<1>(drink_strings[i - drink_offset]);
  return "UNKNOWN";
}

#endif //MCDONALDS_SRC_ITEMS_H_
