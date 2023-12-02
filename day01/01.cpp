#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int calculate(std::string line) {
  std::string number;
  int i = 0, j = line.size() - 1, result = 0;
  while (!std::isdigit(line[i])) ++i;
  while (!std::isdigit(line[j])) --j;
  number[0] = line[i];
  number[1] = line[j];
  result += std::stoi(number);
  return result;
}

void p1(std::vector<std::string> lines) { 
  std::string line;
  std::string number;
  int result = 0;
  for (auto line : lines) {
    result += calculate(line);
  }
  std::cout << result << std::endl;
}


void p2(std::vector<std::string> lines) {
  // reading in lines
  std::string line;
  std::string number;
  int result = 0;
  std::map<std::string, std::string> map = {
      {"one", "1"},   {"two", "2"},   {"three", "3"},
      {"four", "4"},  {"five", "5"},  {"six", "6"},
      {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};

  for (auto line : lines) {
    for (auto const &[key, val] : map) {
      std::string::size_type pos = 0;
      while ((pos = line.find(key, pos)) != std::string::npos) {
        line.replace(pos + 1, key.size() - 2, val);
        pos += val.size();
      }
    }
    result += calculate(line);
  }

  std::cout << result << std::endl;
}

int main() {
  auto lines = std::vector<std::string>{};
  std::string line;
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }

  p1(lines);
  p2(lines);
}
