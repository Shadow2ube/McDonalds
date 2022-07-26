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

void print_burgers() {
  util::menu("Burgers", util::remove_last(util::strip(burger_strings)));
}

void print_wraps() {
  util::menu("Wraps: ", util::remove_last(util::strip(wrap_strings)));
}

void print_cf() {
  util::menu("Chicken & Fish", util::remove_last(util::strip(c_f_strings)));
}

void print_drinks() {
  util::menu("Drinks", util::remove_last(util::strip(drink_strings)));
}

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

void print_total(const vector<tuple<int, int>> &order) {
  double total = 0.00;
  for (auto &[idx, quantity]: order) {
    total += prices[idx] * quantity;
  }
  char total_str[26]; // the size of "$0.00" with \0 at the end
  sprintf(total_str, "The grand total is: $%.2f", total);
  cout << "a" << endl;
  util::boxed(string(total_str));
  cout << "b" << endl;
  wait(100ms);
  cout << "b" << endl;
}

#endif //MCDONALDS_SRC_PRINTERS_H_
