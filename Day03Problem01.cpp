#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <map>
#include <regex>


// Shitty matrix
int maxSize = 1000;
std::vector <std::vector<int> > vec2D(maxSize, std::vector<int>(maxSize, 0));


void markClaim(int xpos, int ypos, int wid, int len)
{
  // Set X Position
  int XIdx = 0;
  for (auto XIter = vec2D.begin(); XIter != vec2D.end(); XIter++, XIdx++)
  {
    if ((XIdx >= xpos) && (XIdx < (xpos+wid)))
    {
      int YIdx = 0;
      for (auto YIter = XIter->begin(); YIter != XIter->end(); YIter++, YIdx++)
      {
        if ((YIdx >= ypos) && (YIdx < (ypos+len)))
        {
          (*YIter)++; // Add claim
        }
      }
    }
  }
}

void printMatrix()
{
  for (auto vec : vec2D)
  {
    for (auto Iter : vec)
    {
      printf("%c ", Iter == 0 ? '.' : 48 + Iter );
    }
    printf("\n");
  }
}

void countRepeatClaims()
{
  int repeatClaims = 0;
  for (auto vec : vec2D)
  {
    for (auto Iter : vec)
    {
      // How many square inches of fabric are within two or more claims?
      if ((Iter) >= 2)
      {
        repeatClaims++;
      }
    }
  }

  printf ("Repeat claims: %d\n", repeatClaims);
}

void parseLine( std::string line)
{

  std::regex claim("^#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)$");
  std::smatch matches;
  
  if (std::regex_search(line, matches, claim))
  {
    int claim = atoi(matches[1].str().c_str());
    int xpos = atoi(matches[3].str().c_str());
    int ypos = atoi(matches[2].str().c_str());
    int wid = atoi(matches[5].str().c_str());
    int len = atoi(matches[4].str().c_str());

    markClaim(xpos,ypos,wid,len);
  }
}

int main()
{
  std::ifstream file("03_input.txt");
  if (file.is_open()) {
    std::string line;

    while (getline(file, line)) {
      // using printf() in all tests for consistency
      // printf( "%s\n", line.c_str() );
      parseLine(line);
    }

    countRepeatClaims();

    file.close();
  }


//  printMatrix();

  return 0;
}
