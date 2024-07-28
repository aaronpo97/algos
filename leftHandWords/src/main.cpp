#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

const std::array<char, 26> englishAlphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                              'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                                              's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

const std::array<char, 15> leftHandChars = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd',
                                            'f', 'g', 'z', 'x', 'c', 'v', 'b'};

const size_t rightHandCharsSize = englishAlphabet.size() - leftHandChars.size();

const std::array<char, rightHandCharsSize> rightHandChars = []() {
  std::array<char, rightHandCharsSize> rightHandChars;

  size_t rightHandCharsIndex = 0;
  for (const auto &letter : englishAlphabet) {
    if (std::find(leftHandChars.begin(), leftHandChars.end(), letter) == leftHandChars.end()) {
      rightHandChars[rightHandCharsIndex] = letter;
      rightHandCharsIndex += 1;
    }
  }

  return rightHandChars;
}();

std::vector<std::string> filterWords(const std::vector<std::string> &words) {

  const size_t rightHandCharsSize = englishAlphabet.size() - leftHandChars.size();

  const std::array<char, 26> englishAlphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                                                's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  //
  const std::array<char, 15> leftHandChars   = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd',
                                                'f', 'g', 'z', 'x', 'c', 'v', 'b'};

  const std::array<char, rightHandCharsSize> rightHandChars = [englishAlphabet, leftHandChars]() {
    std::array<char, rightHandCharsSize> rightHandChars;

    size_t rightHandCharsIndex = 0;
    for (const auto &letter : englishAlphabet) {
      if (std::find(leftHandChars.begin(), leftHandChars.end(), letter) == leftHandChars.end()) {
        rightHandChars[rightHandCharsIndex] = letter;
        rightHandCharsIndex += 1;
      }
    }

    return rightHandChars;
  }();

  std::vector<std::string> leftHandWords;

  for (const auto &word : words) {
    bool isLeftHandWord = true;

    for (const auto &letter : word) {
      if (std::find(rightHandChars.begin(), rightHandChars.end(), letter) != rightHandChars.end()) {
        isLeftHandWord = false;
        break;
      }
    }

    if (!isLeftHandWord) {
      continue;
    }

    leftHandWords.push_back(word);
  }

  return leftHandWords;
}

std::vector<std::string> filterWordsWithRegex(const std::vector<std::string> &words) {
  std::vector<std::string> leftHandWords;
  const std::regex         leftHandRegex = std::regex("^[qwertasdfgzxcvb]+$");
  for (const auto &word : words) {
    if (!std::regex_match(word, leftHandRegex)) {
      continue;
    }

    leftHandWords.push_back(word);
  }
  return leftHandWords;
}

std::vector<std::string> readWordsFromFile(const std::string &fileName) {
  std::vector<std::string> words;
  std::ifstream            file(fileName);
  if (!file) {
    throw std::runtime_error("Unable to open file");
  }
  std::string word;
  while (std::getline(file, word)) {
    words.push_back(word);
  }
  file.close();
  return words;
}

void outputToFile(const std::vector<std::string> &words, const std::string &fileName) {
  std::ofstream outputFile(fileName);
  if (!outputFile) {
    throw std::runtime_error("Unable to open file");
  }
  for (size_t i = 0; i < words.size(); i++) {
    outputFile << words[i] << std::endl;
  }
  outputFile.close();
}

int main() {
  std::vector<std::string> words         = readWordsFromFile("../words.txt");
  std::vector<std::string> leftHandWords = filterWordsWithRegex(words);

  std::cout << "Number of left hand words: " << leftHandWords.size() << std::endl;

  outputToFile(leftHandWords, "left_hand_words.txt");

  std::cout << "Number of words read: " << words.size() << std::endl;
  std::cout << "Number of left hand words: " << leftHandWords.size() << std::endl;

  return 0;
}
