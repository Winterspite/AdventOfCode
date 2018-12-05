#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <map>
#include <regex>
#include <set>


const char* filename = "04_input.txt";
std::set<std::string> lines;

// Day 04 Stuff
int activeGuard = 0;
int startSleepMinute = 0;
int stopSleepMinute = 0;

std::map<int,std::vector<int> > SleepMap;

void processNap()
{
  // If the key isn't in the map, add it.
  if (SleepMap.find(activeGuard) == SleepMap.end())
  {
    std::vector<int> temp;
    for (int Idx = 0; Idx < 60; Idx++)
    {
      temp.push_back(0);
    }
    SleepMap[activeGuard] = temp;
  }
  // Set the sleep values
  for (int Idx = startSleepMinute; Idx < stopSleepMinute; Idx++)
  {
    SleepMap[activeGuard][Idx] += 1;
  }
}

void parseLine( std::string line)
{

  std::regex rTimestamp("^\\[(\\d+)-(\\d+)-(\\d+) (\\d+):(\\d+)\\] (.*)");
  std::smatch matches;
  
  if (std::regex_search(line, matches, rTimestamp))
  {
    int year = atoi(matches[1].str().c_str());
    int month = atoi(matches[2].str().c_str());
    int day = atoi(matches[3].str().c_str());
    int hour = atoi(matches[4].str().c_str());
    int minute = atoi(matches[5].str().c_str());
    // So we can split this
    std::string leftover = matches[6].str();

    const std::regex rSleep("falls asleep");
    const std::regex rWake("wakes up");
    const std::regex rGuard("Guard #(\\d+) begins shift");
    std::smatch subMatch;

    if (std::regex_search(leftover,subMatch,rGuard))
    {
      activeGuard = atoi(subMatch[1].str().c_str());
      /* printf("[%04d-%02d-%02d %02d:%02d] Guard %d ON DUTY\n", year, month, day, hour, minute, activeGuard); */
    }
    else if (std::regex_search(leftover,subMatch,rSleep))
    {
      // Starts sleeping
      /* printf("[%04d-%02d-%02d %02d:%02d] Guard %d SLEEP BEGIN\n", year, month, day, hour, minute, activeGuard); */
      startSleepMinute = minute;
    }
    else if (std::regex_search(leftover,subMatch,rWake))
    {
      // Wakes up
      /* printf("[%04d-%02d-%02d %02d:%02d] Guard %d SLEEP END\n", year, month, day, hour, minute, activeGuard); */
      stopSleepMinute = minute;
      // Process Nap
      processNap();
    }
  }
}

void findTopGuard()
{
  int topGuardID = 0;
  int topMinute = 0;
  int topPlace = -1;

  for (const auto &Iter : SleepMap)
  {

    printf("Guard[%04d]:", Iter.first);
    for (int Idx = 0; Idx < 60; Idx++)
    {
      int Minute = Iter.second[Idx];

      printf("%02d ", Minute);
      if (Minute > topMinute)
      {
        topMinute = Minute;
        topGuardID = Iter.first;
        topPlace = Idx;
      }
    }

    printf("\n");
  }

  //
  printf("Top Guard: %d\n", topGuardID);
  printf("Top Minute: %d\n", topMinute);
  printf("Top Place: %d\n", topPlace);
  printf("Value: %d\n", topGuardID * topPlace);
}

int main()
{
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;

    while (getline(file, line)) {
      // Insert into set to ensure they get sorted
      lines.insert(line);
    }
    file.close();
  }

  for (auto line : lines)
  {
    parseLine(line);
  }

  findTopGuard();
  return 0;
}
