#include <iostream>

// I use linux, most people don't
// If the clearing of the screen doesn't work, I can't test the other OS's
#ifdef __unix
// #define clear_screen puts("\033[2J\0331;1H");
#define clear_screen system("clear");
#elif __APPLE__
#define clear_screen system("clear");
#else
#define clear_screen system("cls");
#endif

using namespace std;

int main(int argc, char **argv) {
  cout.flush();
  cout << "yeet" << endl;
  printf("%ld\n", __func__);
  cout.flush();
  return 0;
}
