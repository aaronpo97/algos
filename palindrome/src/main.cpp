#include <iostream>
/**
 * Function to reverse a number. It takes an integer `number` and iteratively reverses it by:
 *   1. Getting the last digit of `number`.
 *   2. Moving `reversedNumber` one place to the left (e.g., tens to hundreds) and adding the last digit.
 *   3. Removing the last digit from `number` and assigning the result to itself.
 *   4. Repeat steps 1-3 until `number` is 0.
 *
 * @example reverseNumber(123) => 321
 */
int reverseNumber(int number) {
  int reversedNumber = 0;
  int lastDigit      = 0;
  while (number != 0) {
    // Step 1:
    lastDigit      = number % 10;
    // Step 2:
    reversedNumber = reversedNumber * 10 + lastDigit;
    // Step 3:
    number         = number / 10;
  }

  return reversedNumber;
}

int main() {
  const auto checkIfPalindrome = [](int number) -> bool { return number == reverseNumber(number); };

  const bool resultOne   = checkIfPalindrome(121);
  const bool resultTwo   = checkIfPalindrome(123);
  const bool resultThree = checkIfPalindrome(1221);
  const bool resultFour  = checkIfPalindrome(12321);
  const bool resultFive  = checkIfPalindrome(12345);

  std::cout << "121 is a palindrome: " << std::boolalpha << resultOne << std::endl;
  std::cout << "123 is a palindrome: " << std::boolalpha << resultTwo << std::endl;
  std::cout << "1221 is a palindrome: " << std::boolalpha << resultThree << std::endl;
  std::cout << "12321 is a palindrome: " << std::boolalpha << resultFour << std::endl;
  std::cout << "12345 is a palindrome: " << std::boolalpha << resultFive << std::endl;

  return 0;
}