#include <iostream>
#include <map>
#include <string>
#include <vector>

void p1(std::vector<std::string> lines) {
  int result = 0;

  for (auto line : lines) {
    std::vector<std::string> words = {};
    std::string word = "";
    for ( size_t i = 0; i < line.size(); i++) {
      if (line[i] == ' ' || i == line.size() - 1) {
        words.push_back(word);
        word = "";
      } else {
        word += line[i];
      }
    }
    int game_id = std::stoi(words[1]);

    auto len = words.size();
    int blue_count = 0;
    int red_count = 0;
    int green_count = 0;
    int red_max = 12;
    int green_max = 13;
    int blue_max = 14;

    std::map<int, int> game_map = {};
    game_map[game_id] = 0;

    for (size_t i = 2; i < len; i++) {
      if (words[i][0] == 'b') {
        blue_count += std::stoi(words[i - 1]);
      } else if (words[i][0] == 'r') {
        red_count += std::stoi(words[i - 1]);
      } else if (words[i][0] == 'g') {
        green_count += std::stoi(words[i - 1]);
      }

      if (words[i][words[i].size() - 1] == ';') {
        if (blue_count > blue_max || red_count > red_max ||
            green_count > green_max) {
          game_map[game_id]++;
        }
        blue_count = 0;
        red_count = 0;
        green_count = 0;
      }

      if (blue_count > blue_max || red_count > red_max ||
          green_count > green_max) {
        game_map[game_id]++;
      }
    }

    for (auto game : game_map) {
      if (game.second == 0) {
        result += game_id;
      }
    }
  }
  printf("%d\n", result);
}

void p2(std::vector<std::string> lines) {
  int result = 0;

  for (auto line : lines) {

    std::vector<std::string> words = {};
    std::string word = "";
    
    for ( size_t i = 0; i < line.size(); i++) {
      if (line[i] == ' ' || i == line.size() - 1) {
        words.push_back(word);
        word = "";
      } else {
        word += line[i];
      }
    }

    int min_blue = 0;
    int min_red = 0;
    int min_green = 0;
    for (size_t i = 2; i < words.size(); i++) {
      if (words[i][0] == 'b') {
        min_blue = (std::stoi(words[i - 1])) > min_blue ? std::stoi(words[i - 1]) : min_blue;
      } else if (words[i][0] == 'r') {
        min_red = (std::stoi(words[i - 1])) > min_red ? std::stoi(words[i - 1]) : min_red;
      } else if (words[i][0] == 'g') {
        min_green = (std::stoi(words[i - 1])) > min_green ? std::stoi(words[i - 1]) : min_green;
      }

      if (i == words.size() - 1) {

        if (words[i][0] == 'b') {
          min_blue = (std::stoi(words[i - 1])) > min_blue ? std::stoi(words[i - 1]) : min_blue;
        } else if (words[i][0] == 'r') {
          min_red = (std::stoi(words[i - 1])) > min_red ? std::stoi(words[i - 1]) : min_red;
        } else if (words[i][0] == 'g') {
          min_green = (std::stoi(words[i - 1])) > min_green ? std::stoi(words[i - 1]) : min_green;
        }
        result += min_blue * min_red * min_green;
      }
    }
  }
  printf("%d\n", result);
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
