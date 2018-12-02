#include <stdio.h>
#include <stdlib.h>
#include <fstream>

int main()
{
  int total = 0;
  std::ifstream file("01_input.txt");
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      // using printf() in all tests for consistency
      int temp = 0;
      temp = atoi(line.c_str());
      if (temp != 0)
      {
        total += temp;
      }
    }
    file.close();
  }

  printf("Total: %d\n", total);

  return 0;
}
