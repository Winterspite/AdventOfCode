#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <map>

void parseLine( std::string line, int& foundTwo, int& foundThree)
{
  std::map<char,int> characterCount;
  
  for (int Idx = 0; Idx < line.length(); Idx++)
  {
    if (characterCount.count(line[Idx]))
    {
      // Found
      characterCount[line[Idx]] += 1;
    }
    else
    {
      // Not Found
      characterCount[line[Idx]] = 1;
    }
  }

  // Now we count occurances
  for (const auto &character: characterCount) {
      if (character.second == 2)
      {
        foundTwo = 1;
      }
      if (character.second == 3)
      {
        foundThree = 1;
      }
  }
}

int main()
{
  std::ifstream file("02_input.txt");
  if (file.is_open()) {
    std::string line;
    int exactlyTwo = 0;
    int exactlyThree = 0;

    while (getline(file, line)) {
      // using printf() in all tests for consistency
      // printf( "%s\n", line.c_str() );
      int foundTwo = 0;
      int foundThree = 0;
      parseLine( line, foundTwo, foundThree);

      exactlyTwo += foundTwo;
      exactlyThree += foundThree;

    }

    printf( "Exactly Two: %d\n", exactlyTwo );
    printf( "Exactly Three: %d\n", exactlyThree );

    printf( "Checksum: %d\n", (exactlyTwo * exactlyThree));
    file.close();
  }

  return 0;
}
