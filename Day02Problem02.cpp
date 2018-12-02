#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <map>

int parseLine( std::string line)
{
  // List of all lines
  static std::vector<std::string> vLines;
  
  for (std::string strLine : vLines)
  {
    // Now we check to see how close it is
    if (strLine.length() == line.length())
    { 
      int diffs = 0;
      // Same length is important
      for (int Idx = 0; Idx < line.length(); Idx++)
      {
          if (line[Idx] != strLine[Idx])
          {
            diffs++;
          }
      }

      // Check number of diffs
      if (diffs == 1)
      {
        // Manually remove the duplicate character to submit this. I got lazy
        printf("Found it!\n%s\n%s\n", line.c_str(), strLine.c_str());
        return 1;
      }
    }
  }

  vLines.push_back(line);
  return 0;
}

int main()
{
  std::ifstream file("02_input.txt");
  if (file.is_open()) {
    std::string line;

    while (getline(file, line)) {
      // using printf() in all tests for consistency
      // printf( "%s\n", line.c_str() );
      if (parseLine(line))
      {
        return 0;
      }

    }

    file.close();
  }

  return 0;
}
