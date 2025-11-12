#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

std::string generateRandomPassword(int length) {
  const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV"
                              "WXYZ0123456789,./?!@#$%^&*()_+-=[]{};:<>";
  std::string password = "";
  int charsetSize = static_cast<int>(charset.size());

  for (int i = 0; i < length; i++) {
    int randomIndex = rand() % charsetSize;
    password += charset[randomIndex];
  }

  return password;
}

int main() {
  // Seed the random number generator with the current time
  srand(static_cast<unsigned>(time(0)));

  // Generate a 20-character long random password
  int passwordLength = 30;
  std::string password = generateRandomPassword(passwordLength);

  std::cout << "This is your new Password: " << std::endl << password << std::endl << "Do you like it?";

  return 0;
}
