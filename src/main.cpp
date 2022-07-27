/**
 * By: Christian LaForest
 * Date: July 25-27, 2022
 * Notes:
 *  - The program has a lot more options than required, it was because I read the
 *      part that says I need 5-6 items after I had already sort-of implemented the
 *      whole system, so there are 47-ish under 4 categories
 *  - Follow the README.md to build and run this application
 */

#include <iostream>
#include <tuple>
#include <variant>
#include "constants.h"
#include "util.h"
#include "printers.h"

using namespace std;

template<typename T>
tuple<T, bool> find_type(vector<tuple<T, string>> vec);
void get_total(const vector<tuple<int, int>> &order);

void parse_args(int argc, char **argv, const vector<tuple<string, bool &>> &args);

int main(int argc, char **argv) {
  // parse commandline arguments and put them into the variables specified
  parse_args(argc, argv, {
      {"-s", constants::skip_timers},
      {"-r", constants::dont_clear},
  });

  vector<tuple<int, int>> order; // initialize the order

  // wait for start
  print(constants::welcome_screen);
  print_start();
  clear_screen
  print(constants::welcome_screen);
  print("Press enter to start...");
  cin.get();

  do {
    clear_screen
    print_categories(!order.empty()); // print the categories, add "Checkout" if the cart isn't empty
    auto [p, err] = find_type(item_strings); // ask user for input and get type of order
    if (err) continue; // if there's an error (invalid input), skip everything and repeat
    clear_screen


    /*
     * Burgers, Wraps, ChickenAndFish, and Drinks are all the same logically except that
     *    they do the process for their specific list
     */
    switch (p) {
      case UNKNOWN: // ask user if they want to exit
        if (util::prompt<string>("Are you sure you want to exit (y/n): ") == "y") return 0;
        break;
      case Burgers: {
        print_burgers(); // print the list of burgers
        auto [o, e] = find_type(burger_strings); // get user input and the enum type
        if (e) continue; // if there's an error, continue
        if (o == -1) continue; // if it's an invalid burger, continue
        int amt = util::prompt<int>("How many? "); // ask how many
        if (amt < 0) { // if < 0, print its invalid, and continue
          cout << "That's invalid" << endl;
          continue;
        } else if (amt == 0) continue; // if equal to 0, continue without printing anything
        order.emplace_back(o, amt); // add the item type and quantity to the order
        break;
      }
      case Wraps: { // same thing as burger, but with wraps
        print_wraps();
        auto [o, e] = find_type(wrap_strings);
        if (e) continue;
        if (o == -1) continue; // if it's an invalid burger, continue
        int amt = util::prompt<int>("How many? ");
        if (amt < 0) {
          cout << "That's invalid" << endl;
          continue;
        } else if (amt == 0) continue;
        order.emplace_back(o, amt);
        break;
      }
      case ChickenAndFish: { // same things as burger, but with chicken and fish
        print_cf();
        auto [o, e] = find_type(cf_strings);
        if (e) continue;
        if (o == -1) continue; // if it's an invalid burger, continue
        int amt = util::prompt<int>("How many? ");
        if (amt < 0) {
          cout << "That's invalid" << endl;
          continue;
        } else if (amt == 0) continue;
        order.emplace_back(o, amt);
        break;
      }
      case Drinks: { // same thing as burger, but with drinks
        print_drinks();
        auto [o, e] = find_type(drink_strings);
        if (e) continue;
        if (o == -1) continue; // if it's an invalid burger, continue
        int amt = util::prompt<int>("How many? ");
        if (amt < 0) {
          cout << "That's invalid" << endl;
          continue;
        } else if (amt == 0) continue;
        order.emplace_back(o, amt);
        break;
      }
      case Checkout: {
        checkout: // goto flag, lets us go back without a loop
        clear_screen
        print_order(order); // print order

        // confirm checkout
        if (util::prompt<string>("Do you want to checkout (y/n)? ") != "y") continue;

        // get item to change
        int o = util::prompt<int>("Is there anything you want to change (0 to continue)? ");
        if (o == 0) { // no items to change, finish up
          get_total(order); // print total, and get payment
          return 0;
        } else {
          // get item to remove
          int r = util::prompt<int>("How much do you want (0 to remove)? ");
          o -= 1; // 1 for the user is 0 for us, so we need to move it over
          auto &t = order[o]; // get the tuple out of the order
          auto &[x, y] = t; // get the values out of the tuple (t)

          if (r == 0) { // if r == 0, remove the item from the list
            std::remove(order.begin(), order.end(), t);
            goto checkout; // goes back to top of case
          } else { // else modify item
            order[o] = {x, r}; // overwrite order[o] with the new value
            goto checkout; // goes back to top of case
          }
        }
        break;
      }
      default: { // catch everything else
        print("Invalid option");
        wait(100ms);
        break;
      }
    }
  } while (true);
  return 0;
}

/**
 * @brief Gets the user's option, turns it into the enum
 * @tparam T The enum type
 * @param vec the vector of T and string names
 * @return T, bool - tuple of both
 */
template<typename T>
tuple<T, bool> find_type(vector<tuple<T, string>> vec) {
  auto opt = util::prompt<string>("Enter an option: "); // get input
  T p = (T) -1; // set a default type (in our case, UNKNOWN<type>)
  if (!util::is_num(opt)) { // check if the string is a number
    p = util::find_from(vec, opt); // find the key from the value
    auto &[x, _] = vec[vec.size() - 1]; // get the last item from the map, should be UNKNOWN<type>
    if (p == x) { // check if they are equal
      print("Invalid option (Watch for case sensitivity)!"); // print an error
      return {p, true}; // return the end, and that there is an error
    }
  } else p = std::get<0>(vec[stoi(opt) - 1]); // else get the option through index

  return {p, false}; // return p and no error
}

/**
 * @brief Prints the total,
 * Then gets user to input cash until the amount paid >= amount owed
 * @param order The list of items
 */
void get_total(const vector<tuple<int, int>> &order) {
  const double total = print_total(order); // print total, it also returns it as a double
  double total_due = total;
  double change;
  do {
    auto tender = util::prompt<double>("Enter amount tendered: "); // get amount entered
    if (tender == total_due) { // amt paid == total due
      print("Exact change!\n");
      break; // exit
    } else if (tender > total_due) { // amt paid > total due
      printf("Change Due: %.2f\n", tender - total_due); // formatting the output
      change = tender - total_due;
      break; // exit
    } else {
      total_due -= tender;
      printf("Your short $%.2f\n", total_due); // formatting the output
    }
    cout.flush(); // compatibility with more terminals
  } while (total_due > 0);
  if (util::prompt<char>("Would you like a receipt (y/n)? ")=='n') return;
  cout << endl; // spacing
  print_receipt(order, total, change);
}

/**
 * @brief Parses the arguments out of argv, and places them into a predefined array
 * @param argc int - size of argv
 * @param argv char ** - array of char *(strings)
 * @param args list of pairs of string and bool &, the value will be placed in the bool &
 */
void parse_args(int argc, char **argv, const vector<tuple<string, bool &>> &args) {
  // make everything false
  for (auto &[_, y]: args) y = false;

  // check if the argument is in the list, if it is, make true
  for (int i = 0; i < argc; ++i)
    for (auto &[x, y]: args) if (argv[i] == x) y = true;
}