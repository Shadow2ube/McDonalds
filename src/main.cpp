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

/**
 * @brief Parses the arguments out of argv, and places them into a predefined array
 * @param argc int - size of argv
 * @param argv char ** - array of char *(strings)
 * @param args list of pairs of string and bool &, the value will be placed in the bool &
 */
void parse_args(int argc, char **argv, vector<tuple<string, bool &>> args) {
  // make everything false
  for (auto &[_, y]: args) y = false;

  // check if the argument is in the list, if it is, make true
  for (int i = 0; i < argc; ++i)
    for (auto &[x, y]: args) if (argv[i] == x) y = true;
}

int main(int argc, char **argv) {
  bool invalid_credit;
  parse_args(argc, argv, {
      {"-c", invalid_credit},
      {"-s", constants::skip_timers},
      {"-r", constants::dont_clear},
  });

  vector<tuple<int, int>> order;

  // wait for start
  print(constants::welcome_screen);
  print_start();
  clear_screen
  print(constants::welcome_screen);
  print("Press enter to start...");
  cin.get();

  do {
    clear_screen
    print_categories(!order.empty());
    auto [p, err] = find_type(item_strings);
    if (err)continue;
    clear_screen


    // both will be set in switch statement
    switch (p) {
      case UNKNOWN:if (util::prompt<string>("Are you sure you want to exit (y/n): ") == "y") return 0;
        break;
      case Burgers: {
        print_burgers();
        auto [o, e] = find_type(burger_strings);
        if (e) continue;
        int amt = util::prompt<int>("How many? ");
        if (amt < 0) {
          cout << "That's invalid" << endl;
          continue;
        } else if (amt == 0) continue;
        order.emplace_back(o, amt);
        break;
      }
      case Wraps: {
        print_wraps();
        auto [o, e] = find_type(wrap_strings);
        if (e) continue;
        int amt = util::prompt<int>("How many? ");
        if (amt < 0) {
          cout << "That's invalid" << endl;
          continue;
        } else if (amt == 0) continue;
        order.emplace_back(o, amt);
        break;
      }
      case ChickenAndFish: {
        print_cf();
        auto [o, e] = find_type(c_f_strings);
        if (e) continue;
        int amt = util::prompt<int>("How many? ");
        if (amt < 0) {
          cout << "That's invalid" << endl;
          continue;
        } else if (amt == 0) continue;
        order.emplace_back(o, amt);
        break;
      }
      case Drinks: {
        print_drinks();
        auto [o, e] = find_type(drink_strings);
        if (e) continue;
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
        print_order(order);
        if (util::prompt<string>("Do you want to checkout (y/n)? ") != "y") continue;

        int o = util::prompt<int>("Is there anything you want to change (0 to continue)? ");
        if (o == 0) {
          get_total(order);
          return 0;
        } else {
          int r = util::prompt<int>("How much do you want (0 to remove)? ");
          o -= 1; // 1 for the user is 0 for us, so we need to move it over
          auto &t = order[o];
          auto &[x, y] = t;

          if (r == 0) {
            std::remove(order.begin(), order.end(), t);
            goto checkout; // goes back to top of case
          } else {
            order[o] = {x, r};
            goto checkout; // goes back to top of case
          }
        }
        break;
      }
      default: { // catch everything else
        print("Invalid option");
        wait(1000ms);
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
  } else p = std::get<0>(vec[stoi(opt) - 1]);

  return {p, false}; // return p and no error
}

void get_total(const vector<tuple<int, int>> &order) {
  double total_due = print_total(order);
  do {
    int tender = util::prompt<int>("Enter amount tendered: ");
    if (tender > total_due) {
      printf("Change Due: %.2f\n", tender - total_due); // formatting the output
      return;
    } else {
      total_due -= tender;
      printf("Your short $%.2f\n", total_due); // formatting the output
    }
    cout.flush(); // compatibility
  } while (total_due > 0);
}
