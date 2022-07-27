//
// Created by christian on 7/26/22.
//

#ifndef MCDONALDS_SRC_PRINTERS_H_
#define MCDONALDS_SRC_PRINTERS_H_

#include <iostream>
#include "util.h"
#include "items.h"
using namespace std;

/**
 * @brief Prints a simple startup sequence
 */
void print_start() {
  cout << "Loading";
  cout.flush();
  util::dots(4, 500ms);
  cout << "Done!" << endl;
}

/**
 * @brief Prints the possible categories for the user
 * @param checkout whether or not to add the checkout flag
 */
void print_categories(bool checkout = false) {
  if (!checkout)
    util::menu("Categories", {
        "Burgers",
        "Wraps",
        "Chicken and Fish",
        "Drinks",
    });
  else
    util::menu("Categories", {
        "Burgers",
        "Wraps",
        "Chicken and Fish",
        "Drinks",
        "Checkout",
    });
}

/**
 * @brief Prints a menu for the burgers
 * takes the burger_strings, removes the keys, making it a vector of strings (remove the keys)
 *      then removes the last item, because it's an UNKNOWN, that shouldn't be accessible to users
 */
void print_burgers() {
  util::menu("Burgers", util::remove_last(util::strip(burger_strings)));
}

/**
 * @brief Prints a menu for the wraps
 * takes the wrap_strings, removes the keys, making it a vector of strings (remove the keys)
 *      then removes the last item, because it's an UNKNOWN, that shouldn't be accessible to users
 */
void print_wraps() {
  util::menu("Wraps: ", util::remove_last(util::strip(wrap_strings)));
}

/**
 * @brief Prints a menu for the chicken and fish
 * takes the cf_strings, removes the keys, making it a vector of strings (remove the keys)
 *      then removes the last item, because it's an UNKNOWN, that shouldn't be accessible to users
 */
void print_cf() {
  util::menu("Chicken & Fish", util::remove_last(util::strip(cf_strings)));
}

/**
 * @brief Prints a menu for the drinks
 * takes the drink_strings, removes the keys, making it a vector of strings (remove the keys)
 *      then removes the last item, because it's an UNKNOWN, that shouldn't be accessible to users
 */
void print_drinks() {
  util::menu("Drinks", util::remove_last(util::strip(drink_strings)));
}

/**
 * @brief Prints the order from the order string
 * @param order the map of id number and quantities
 */
void print_order(vector<tuple<int, int>> order) {
  // make a menu of the cart. Since the stored items are as their ids,
  //  we need to get their names from the map. The foreach essentially makes
  //  a new vector (array) out of the ids and quantities, into a vector of
  //  the name and quantities
  util::menu("Cart", util::foreach<tuple<int, int>, tuple<string, int>>(
      order,
      [](tuple<int, int> t) -> tuple<string, int> {
        // This is a lambda, it allows us to have code called in another
        //  function when we want
        auto [x, y] = t; // get the values out of the tuple
        // return the name string and the quantity
        return {name_from_possible(x), y};
      }));
}

/**
 * @brief Prints the total and also returns it
 * @param order map of ids and quantities
 * @return the total
 */
double print_total(const vector<tuple<int, int>> &order) {
  double total = 0.00;
  for (auto &[idx, quantity]: order) {
    total += prices[idx] * quantity;
  }
  char total_str[26]; // the size of "$0.00" with \0 at the end
  sprintf(total_str, "The grand total is: $%.2f", total * 1.8);
  util::boxed(string(total_str));
  return total * 1.8;
}

#endif //MCDONALDS_SRC_PRINTERS_H_
