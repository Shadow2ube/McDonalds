#include <iostream>
#include <tuple>
#include <variant>
#include "constants.h"
#include "util.h"
#include "printers.h"

using namespace std;

template<typename T>
tuple<T, bool> find_type(vector<tuple<T, string>> vec);

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
      {"-s", constants::skip_timers}
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
      case UNKNOWN:if (util::prompt<string>("Are you sure you want to exit (YES/NO): ") == "YES") return 0;
        break;
      case Burgers: {
        print_burgers();
        auto [o, e] = find_type(burger_strings);
        if (e) continue;
        int amt = util::prompt<int>("How many? ");
        if (amt < 0) {
          cout << "That's invalid" << endl;
          continue;
        }
        order.emplace_back(o, amt);
        break;
      }
      case Wraps: {
        print_wraps();
        auto [o, e] = find_type(burger_strings);
        if (e) continue;
        int amt = util::prompt<int>("How many? ");
        if (amt < 0) {
          cout << "That's invalid" << endl;
          continue;
        }
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
        }
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
        }
        order.emplace_back(o, amt);
        break;
      }
      case Checkout: {
        print_order(order);

        int o = util::prompt<int>("Is there anything you want to change (0 to continue)? ");
        if (o == 0) {
          print_total(order);
          return 0;
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
  auto opt = util::prompt<string>("Enter an option: ");
  T p = (T) -1;
  if (!util::is_num(opt)) {
    p = util::find_from(vec, opt);
    auto &[x, _] = vec[vec.size() - 1];
    if (p == x) {
      print("Invalid option (Watch for case sensitivity)!");
      return {p, true};
    }
  } else p = (T) stoi(opt);
  return {p, false};
}
