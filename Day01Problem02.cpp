#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{

  std::vector<int> freqs;

  int freq = 0;
  bool bDuplicateFound = false;

  while(!bDuplicateFound)
  {
    std::ifstream file("01_input.txt");
    if (file.is_open()) {
      std::string line;
      while (getline(file, line)) {
        // using printf() in all tests for consistency
        int temp = 0;
        temp = atoi(line.c_str());
        if (temp != 0)
        {
          freq += temp;

          /* Check and see if vector contains new frequency */
          if(std::find(freqs.begin(), freqs.end(), freq) != freqs.end())
          {
            printf("Duplicate found: %d\n", freq);
            bDuplicateFound = true;
            return 0;
          }

          /* Add new frequency to list */
          freqs.push_back(freq);
          // printf("Adding frequency %d\n", freq);
        }
      }
      file.close();
    }
  }

  return 0;
}
