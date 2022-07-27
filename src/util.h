//
// Created by christian on 7/26/22.
//

#ifndef MCDONALDS_SRC_UTIL_H_
#define MCDONALDS_SRC_UTIL_H_

#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include "constants.h"

using namespace std;

namespace util {

/**
 * @brief Prints a series of dots over time
 * @param amt amount of dots to print
 * @param t time per dot
 */
inline void dots(int amt, chrono::milliseconds t) {
  for (int i = 0; i < amt; ++i) {
    cout << ".";
    cout.flush();
    wait(t);
  }
}

/**
 * @brief Formats a menu of of given input
 * @param name The name of the menu/prompt
 * @param opts The possible options
 * @param back if true, the first (0) item is always exit
 */
inline void menu(const string &name, const vector<string> &opts) {
  printf("%s:\n  0: exit", name.c_str());
  int i = 0;
  for (auto &x: opts) {
    printf("\n  %i: %s", i + 1, x.c_str());
    ++i;
  }
  cout << endl;
}

template<typename A>
inline void menu(const string &name, const vector<A> &opts) {
  printf("%s:\n  0: exit", name.c_str());
  int i = 0;
  for (auto &[x, y]: opts) {
    printf("\n  %i: %i -> %s", i + 1, y, x.c_str());
    ++i;
  }
  cout << endl;
}

template<typename I, typename O>
inline vector<O> foreach(vector<I> in, O(*func)(I t)) {
  vector<O> out;
  for (I i: in) {
    out.emplace_back(func(i));
  }
  return out;
}

/**
 * @brief Gets user input after printing a prompt
 * @tparam T the type to return
 * @param p the prompt for the user
 * @return T - what the user returned
 */
template<typename T>
inline T prompt(const string &p) {
  T out;
  cout << p;
  cin >> out;
  return out;
}

/**
 * @brief Checks if a string is a number
 * @param in string to test
 * @return true if is number, else false
 */
bool is_num(const string &in) {
  return all_of(in.begin(), in.end(), [](char c) { return isdigit(c); });
}

/**
 * @brief Removes the last item in a vector
 * @tparam T to pass on to the vector types
 * @param in the starting vector
 * @return in - the last element
 */
template<typename T>
vector<T> remove_last(vector<T> in) {
  return vector<T>(in.begin(), in.end() - 1);
}

/**
 * @brief Returns vector of type B, where it is pulled from in
 * @tparam A unused
 * @tparam B the type of the second type in the tuple
 * @param in the vector of tuples
 * @return vector of type B
 */
template<typename A, typename B>
vector<B> strip(vector<tuple<A, B>> in) {
  vector<B> out;
  for (auto &[x, y]: in) {
    out.push_back(y);
  }
  return out;
}

/**
 * @brief Gets the key from a value, and returns it
 * @tparam T the type, usually an int or enum
 * @param in vector of tuples, or a map of sorts
 * @param find string to find in the array
 * @return the found key or the last element
 */
template<typename T>
T find_from(vector<tuple<T, string>> in, string find) {
  for (auto &[x, y]: in) {
    if (y == find) return x;
  }
  auto &[final, _] = in[in.size() - 1];
  return final;
}

/**
 * @brief repeats x, size times
 * @param x the string to repeat
 * @param size the amount of times to repeat
 * @return X repeated size times
 */
string x_of_size(const string &x, size_t size) {
  string out;
  for (int i = 0; i < size; ++i) {
    out += x;
  }
  return out;
}

void boxed(string in) {
  cout << x_of_size("*", in.size() + 4) << "\n* " << in << " *\n"
       << x_of_size("*", in.size() + 4) << "\n"
       << endl;
}

}

#endif //MCDONALDS_SRC_UTIL_H_
