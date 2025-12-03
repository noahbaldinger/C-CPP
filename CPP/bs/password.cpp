#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

string generateRandomPassword(int length) {
  const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV"
                              "WXYZ0123456789,./?!@#$%^&*()_+-=[]{};:<>";
  string password = "";
  int charsetSize = static_cast<int>(charset.size());

  for (int i = 0; i < length; i++) {
    int randomIndex = rand() % charsetSize;
    password += charset[randomIndex];
  }

  return password;
}


bool IsGoodPassword(const string& password) {
    if (password.length() < 8)
        return false;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    string specials = "!@#$%^&*()-_=+[]{};:,.<>?/";

    for (char ch : password) {
        if (isupper(ch))
            hasUpper = true;
        else if (islower(ch))
            hasLower = true;
        else if (isdigit(ch))
            hasDigit = true;
        else if (specials.find(ch) != string::npos)
            hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
  // Seed the random number generator with the current time
  srand(static_cast<unsigned>(time(0)));

  // Generate a 20-character long random password
  int passwordLength;
  cout << "Choose your passwords length: ";
  cin >> passwordLength;
  
  string password;
  password = generateRandomPassword(passwordLength);

  cout << "This is your new Password: " << endl << password;

  return 0;
}
