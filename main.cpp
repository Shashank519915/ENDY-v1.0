#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

string generateRandomSalt(int length = 16)
{
    static const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./";
    string salt;
    for (int i = 0; i < length; ++i)
    {
        int index = rand() % characters.length();
        salt += characters[index];
    }
    return salt;
}

string hashPassword(const string &password, const string &salt)
{
    string hashedPassword = password + salt; // Placeholder implementation
    return hashedPassword;
}

string encryptString(const string &input, const string &password, int difficulty, string &salt)
{
    salt = generateRandomSalt();
    string hashedPassword = hashPassword(password, salt);

    string encryptedString = hashedPassword;

    for (char c : input)
    {
        int encryptedChar = static_cast<int>(c) + difficulty;
        encryptedString += static_cast<char>(encryptedChar);
    }

    return encryptedString;
}

string decryptString(const string &input, const string &password, int difficulty, const string &salt)
{
    string hashedPassword = hashPassword(password, salt);
    string encryptedString = input.substr(hashedPassword.length());

    string decryptedString;
    for (char c : encryptedString)
    {
        int decryptedChar = static_cast<int>(c) - difficulty;
        decryptedString += static_cast<char>(decryptedChar);
    }

    return decryptedString;
}


void saveEncryptedStringToFile(const string &encryptedString, const string &filename)
{
    ofstream file(filename);
    if (file)
    {
        file << encryptedString;
        cout << "Encrypted string saved to file: " << filename << endl;
    }
    else
    {
        cout << "Error: Unable to open file for writing!" << endl;
    }
}

string readEncryptedStringFromFile(const string &filename)
{
    ifstream file(filename);
    string encryptedString;

    if (file)
    {
        stringstream buffer;
        buffer << file.rdbuf();
        encryptedString = buffer.str();
    }
    else
    {
        cout << "Error: Unable to open file for reading!" << endl;
    }

    return encryptedString;
}

int getPasswordStrength(const string &password)
{
    int strength = 0;
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (char c : password)
    {
        if (isupper(c))
            hasUppercase = true;
        else if (islower(c))
            hasLowercase = true;
        else if (isdigit(c))
            hasDigit = true;
        else if (ispunct(c) || isspace(c))
            hasSpecialChar = true;
    }

    if (hasUppercase)
        strength++;
    if (hasLowercase)
        strength++;
    if (hasDigit)
        strength++;
    if (hasSpecialChar)
        strength++;

    return strength;
}

int main()
{
    cout << "ENDY v1.0 - Shashank" << endl << endl;
    srand(time(nullptr)); // Seed the random number generator

    string input, password, salt;
    int difficulty, maxDifficulty;

    cout << "Enter the input string: ";
    getline(cin >> ws, input);

    cout << "Enter the password: ";
    getline(cin >> ws, password);

    // Validate password strength
    int passwordStrength = getPasswordStrength(password);
    if (passwordStrength < 2)
    {
        cout << "Weak password! Please choose a stronger password." << endl;
        return 1;
    }

    cout << "Enter the difficulty level (1-10) for encryption: ";
    cin >> difficulty;

    cout << "Enter the maximum difficulty level for brute force attack: ";
    cin >> maxDifficulty;
    cout << endl;
    cout << "*******************************************************************" << endl;
    string encrypted = encryptString(input, password, difficulty, salt);
    cout << "Encrypted string: " << encrypted << endl;

    // Save encrypted string to file
    string filename = "encrypted.txt";
    saveEncryptedStringToFile(encrypted, filename);
    
    // Read encrypted string from file
    string encryptedFromFile = readEncryptedStringFromFile(filename);
    cout << "Encrypted string read from file: " << encryptedFromFile << endl;
    cout << endl;
    cout << "*******************************************************************" << endl;
    cout << "Enter the difficulty level (1-10) for decryption: ";
    cin >> difficulty;
    cout << endl;
    cout << "*******************************************************************" << endl;
    cout << "Attempting to decrypt using brute force..." << endl;
    bool foundDecryption = false;
    for (int i = 1; i <= maxDifficulty; ++i)
    {
        string decrypted = decryptString(encryptedFromFile, password, difficulty, salt);
        if (decrypted != "")
        {
            cout << "Decrypted string (brute force): " << decrypted << endl;
            foundDecryption = true;
            break;
        }
        else
        {
            cout << "Brute force decryption failed at difficulty level " << i << endl;
        }
    }

    if (!foundDecryption)
    {
        cout << "Brute force decryption failed at all difficulty levels." << endl;
    }

    return 0;
}

