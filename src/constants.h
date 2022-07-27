//
// Created by christian on 7/26/22.
//

#ifndef MCDONALDS_SRC_CONSTANTS_H_
#define MCDONALDS_SRC_CONSTANTS_H_

#include <string>
#include <thread>

// I use linux, most people don't
// If the clearing of the screen doesn't work, I can't test the other OS's
#ifdef __unix
#define clear_screen system(constants::dont_clear ? "" : "clear");
#elif __APPLE__
#define clear_screen system("clear");
#else
#define clear_screen system("cls");
#endif

using namespace std;

// some macros for making life slightly easier
#define wait(x) std::this_thread::sleep_for(constants::skip_timers ? 0ms : (x))
#define print(x) cout << (x) << endl

// used to split up things into categories
namespace constants {
// the welcome screen as a constant string, because it doesn't change
const string welcome_screen = R"(******************************************************
*  __  __      _____                    _     _      *
* |  \/  |    |  __ \                  | |   | |     *
* | \  / | ___| |  | | ___  _ __   __ _| | __| |___  *
* | |\/| |/ __| |  | |/ _ \| '_ \ / _` | |/ _` / __| *
* | |  | | (__| |__| | (_) | | | | (_| | | (_| \__ \ *
* |_|  |_|\___|_____/ \___/|_| |_|\__,_|_|\__,_|___/ *
******************************************************)";

// some global variables for debugging
bool skip_timers = false;
bool dont_clear = true;

}

#endif //MCDONALDS_SRC_CONSTANTS_H_
