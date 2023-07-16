# Password Encryption Program

This repository contains a C++ program that provides password-based encryption and decryption using a symmetric encryption algorithm. The program offers features such as random salt generation, customizable difficulty levels, and prevention against brute force attacks. It also includes password strength validation to ensure the use of strong passwords for enhanced security.

## Features

- Password-based encryption and decryption
- Symmetric encryption algorithm
- Random salt generation
- Customizable difficulty levels
- Brute force attack prevention
- Password strength validation

## Preview
![ENDY v1 0](https://github.com/Shashank519915/ENDY-v1.0/assets/120128150/a63d9912-bd7c-4d6e-9817-3b966943dd30)

## Getting Started

### Prerequisites

- C++ compiler
- Standard Template Library (STL)

### Usage

1. Clone the repository:

```shell
git clone https://github.com/your-username/password-encryption-program.git
```

2. Compile the program using your C++ compiler.

3. Run the compiled executable.

4. Follow the prompts to enter the input string, password, difficulty level for encryption, and maximum difficulty level for brute force attack.

5. The program will encrypt the input string, display the encrypted string, and save it to a text file named `encrypted.txt`.

6. The program will then attempt to decrypt the encrypted string using brute force, starting from difficulty level 1 up to the maximum difficulty level specified. If successful, the decrypted string will be displayed.

## Contributing

Contributions are welcome! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License.

## Acknowledgments

- The program uses the Standard Template Library (STL) for string manipulation and file operations.
- The symmetric encryption algorithm used in the program is for demonstration purposes only and should not be considered secure for real-world use.

## Disclaimer

Please note that the security of the encryption algorithm depends on various factors, including the strength of the password and the encryption method used. This program is intended for educational and demonstration purposes only. Use it at your own risk.
