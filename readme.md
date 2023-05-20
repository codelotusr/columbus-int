# Columbus internship exercises and explanations
- [void menu()](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#LL25C11-L25C11) function - 
- [void clearScreen()](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#L122) function - 
- [void enterToContinue()](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#L131) function -
- [int *generateRandomNumberArray()](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#LL154C1-L154C33) function - 
## Task 1
> Parašykite algoritmą, kuris įvestą tekstinę reikšmę pateikia atbuline tvarką. Tarkim įvedame
> „Programuotojas“, rezultatą turi pateikti **„sajotoumargorP“**.

- [std::string reverseString()](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#L139) function -
## Task 2
> Parašykite algoritmą, kuris skaičių masyve surastų mažiausią ir didžiausią skaičių. Skaičių masyvą
> suformuoti galima naudojant **“Random”** funkciją, arba suformuoti pačiam. Masyvo ilgis 100.

- [void printMinAndMax(int A[])](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#L195) function -
- [int findMin(int A[])](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#LL173C1-L173C21) function -
- [int findMax(int A[])](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#L184) function -
## Task 3
> Parašykite algoritmą, kuris skaičių masyve surastų besidubliuojančius skaičius. Skaičių masyvą
> suformuoti galima naudojant **“Random”** funkciją, arba suformuoti pačiam. Masyvo ilgis 100.

- [void findDuplicateNumbers(int A[])](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#L213) function - 
## Task 4
> Parašykite algoritmą, kuris suskaičiuotu balsių ir priebalsių skaičių tekste **“Programuotojo ar**
> **tiesiog bet kokio IT specialisto profesija taps vis labiau įprasta.“**

- [void countVowelsAndConsonants(std::string tekstas)](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#L260) function -
- [unsigned int countVowels(std::string tekstas)](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#LL231C1-L231C46) function -
- [unsigned int countConsonants(std::string tekstas)](https://github.com/codelotusr/columbus-int/blob/c54a4cff90b39edf3858dbcebe49d5dd1383d9e8/src/main.cpp#L245) function -

# Executing the CLI software
1. Install a C++ compiler: You can choose a C++ compiler based on your operating system. Some popular options include:
- Windows: You can install the MinGW-w64 compiler, which provides a C++ development environment for Windows. You can download it from the MinGW-w64 website.
- Mac: macOS usually comes with the Clang compiler installed. You can verify this by opening the Terminal and typing clang --version. If it's not installed, you can install the Xcode Command Line Tools by running xcode-select --install in the Terminal.
- Linux: Most Linux distributions come with the GNU Compiler Collection (GCC) installed by default. You can verify this by opening the Terminal and typing ```g++ --version```. If it's not installed, you can install it using your distribution's package manager. For example, on Ubuntu, you can run sudo apt-get install build-essential to install GCC.
2. Navigate to the directory where the source file is saved using the Terminal or Command Prompt and use ```./bin/columbus``` to run it or if that doesn't work, use the appropriate command to compile and then run the program. For example, with MinGW-w64 on Windows, you can run ```g++ -o columbus ./src/main.cpp``` to compile the program and ```./bin/columbus``` to run it.
