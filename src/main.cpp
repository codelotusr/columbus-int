#include <iostream>
#include <string>
#include <unordered_set>
#include <random>

void menu(); // rodo pasirinkimus ir kviecia kitas funkcijas pagal pasirinkima
void clearScreen(); // valo ekrana isvedant tinkama komanda pagal operacine sistema
void enterToContinue(); // laukia, kol bus paspaustas 'ENTER' klavisas, pries tesiant darba
std::string reverseString(); // grazina apversta teksta (pvz.: "Programuotojas" -> "sajotoumargorP")
int *generateRandomNumberArray(); // grazina 100 atsitiktiniu skaiciu masyva sudarytu is 1-1000 skaiciu
int findMin(int A[]); // grazina maziausia skaiciu masyve
int findMax(int A[]); // grazina didziausia skaiciu masyve
void printMinAndMax(int A[]); // isveda maziausia ir didziausia skaiciu masyve
void findDuplicateNumbers(int A[]); // isveda pasikartojancius skaicius masyve
unsigned int countVowels(std::string tekstas); // grazina balsiu skaiciu tekste
unsigned int countConsonants(std::string tekstas); // grazina priebalsiu skaiciu tekste
void countVowelsAndConsonants(std::string tekstas); // isveda balsiu ir priebalsiu skaiciu tekste
static int *A = NULL; // globalus kintamasis, kuris bus naudojamas algoritmuose

int main() {
    menu();
    return 0;
}

void menu() {
    clearScreen();
    std::cout << "Algoritmai:\n";
    std::cout << "1. Teksto apvertimas\n";
    std::cout << "2. Min ir Max radimas\n";
    std::cout << "3. Rasti pasikartojancius skaicius\n";
    std::cout << "4. Balsiu ir priebalsiu skaicius tekste\n";
    std::cout << "5. Sukurti nauja masyva is 100 atsitiktiniu skaiciu\n";
    std::cout << "0. Iseiti\n";
    unsigned int choice;
    std::cout << "Pasirinkite algoritma: ";
    std::cin >> choice;
    // pasirinkimo tikrinimas
    switch (choice) {
    case 1: {
        std::cout << reverseString() << std::endl;
        enterToContinue();
        menu();
    }
    case 2: {
        if (A == NULL) // jeigu masyvas dar nera sugeneruotas, tai jis sugeneruojamas
            A = generateRandomNumberArray();
        std::cout << "Rasti min ar max? (1 - min, 2 - max, 3 - atspausdinti abu): ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Maziausias skaicius: " << findMin(A) << std::endl;
            enterToContinue();
            menu();
        }
        case 2: {
            std::cout << "Didziausias skaicius: " << findMax(A) << std::endl;
            enterToContinue();
            menu();
        }
        case 3: {
            printMinAndMax(A);
            enterToContinue();
            menu();
        }
        default: {
            std::cout << "Neteisingas pasirinkimas\n";
            enterToContinue();
            menu();
        }
        }
    }
    case 3: {
        if (A == NULL) // jeigu masyvas dar nera sugeneruotas, tai jis sugeneruojamas
            A = generateRandomNumberArray();
        findDuplicateNumbers(A);
        enterToContinue();
        menu();
    }
    case 4: {
        std::string tekstas = "Programuotojo ar tiesiog bet kokio IT specialisto profesija taps vis labiau įprasta.";
        std::cout << "Tekstas: " << tekstas << std::endl;
        std::cout << "Rasti balsiu ar priebalsiu skaiciu? (1 - balsiu, 2 - priebalsiu, 3 - atspausdinti abu): ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Balsiu skaicius: " << countVowels(tekstas) << std::endl;
            enterToContinue();
            menu();
        }
        case 2: {
            std::cout << "Priebalsiu skaicius: " << countConsonants(tekstas) << std::endl;
            enterToContinue();
            menu();
        }
        case 3: {
            countVowelsAndConsonants(tekstas);
            enterToContinue();
            menu();
        }
        default: {
            std::cout << "Neteisingas pasirinkimas\n";
            enterToContinue();
            menu();
        }
        }
        enterToContinue();
        menu();
    }
    case 5: {
        int *A = generateRandomNumberArray();
        std::cout << "Masyvas sugeneruotas\n";
        enterToContinue();
        menu();
    }
  }
}

void clearScreen() {
    // jeigu operacine sistema yra Windows, tai naudojama 'cls' komanda, kitu atveju 'clear'
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void enterToContinue() {
    std::cout << "Paspauskite ENTER, kad testumete darba";
    std::cin.get();
    std::cin.get();
}

// Uzduotis #1
std::string reverseString() {
    std::string tekstas;
    std::cout << "Iveskite teksta: ";
    // istrinamas buferis, kad getline() funkcija veiktu teisingai
    std::cin.ignore();
    // nuskaitomas tekstas
    std::getline(std::cin, tekstas);
    std::string apverstasTekstas;
    // apverciamas tekstas naudojant 'for' cikla
    for (size_t i(tekstas.length() - 1); i >= 0; --i)
        // pridedamas esamas simbolis prie apversto teksto kintamojo
        apverstasTekstas += tekstas[i];
    return apverstasTekstas;
}

int *generateRandomNumberArray() {
    // sukuriamas masyvo pointeris
    int *array = new int[100];
    // sukuriamas atsitiktiniu skaiciu generatorius
    std::random_device rd;
    // sukuriamas atsitiktiniu skaiciu generatoriaus objektas (seed'as)
    std::mt19937 mt(rd());
    // sukuriamas atsitiktiniu skaiciu generatoriaus intervalas
    std::uniform_int_distribution<int> dist(1, 1000);
    // uzpildomas masyvas atsitiktiniais skaiciais
    for (size_t i{0}; i < 100; ++i)
        array[i] = dist(mt);
    return array;
}

// Task #2

// Uzduotis #2.1
int findMin(int A[]) {
    int min = A[0];
    for (size_t i{0}; i < 100; ++i)
        // jeigu esamas skaicius masyve yra mazesnis uz min, tai min priskiriama esamo skaiciaus reiksme
        if (A[i] < min)
            min = A[i];
    return min;
}

// Uzduotis #2.2

int findMax(int A[]) {
    int max = A[0];
    for (size_t i{0}; i < 100; ++i)
        // jeigu esamas skaicius masyve yra didesnis uz max, tai max priskiriama esamo skaiciaus reiksme
        if (A[i] > max)
            max = A[i];
    return max;
}

// Uzduotis #2.3

void printMinAndMax(int A[]) {
    int min = A[0];
    int max = A[0];
    for (size_t i{0}; i < 100; ++i) {
        // jeigu esamas skaicius masyve yra mazesnis uz min, tai min priskiriama esamo skaiciaus reiksme
        if (A[i] < min)
            min = A[i];
        // jeigu esamas skaicius masyve yra didesnis uz max, tai max priskiriama esamo skaiciaus reiksme
        else if (A[i] > max)
            max = A[i];
    }
    // Konsoleje isvedami maziausias ir didziausias skaiciai masyve
    std::cout << "Maziausias skaicius: " << min << std::endl;
    std::cout << "Didziausias skaicius: " << max << std::endl;
}

// Uzduotis #3

void findDuplicateNumbers(int A[]) {
    // sukuriamas set'as, kuriame bus saugomi pasikartojantys skaiciai (naudojamas unordered_set, nes jis yra greitesnis nei set)
    std::unordered_set<int> nums;
    for (size_t i{0}; i < 100; ++i) {
        // jeigu esamas skaicius masyve nera set'e, tai jis pridedamas i set'a, jeigu jau yra, tai isvedamas i konsole
        if (nums.find(A[i]) == nums.end())
            nums.insert(A[i]);
        else
            std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// Uzduotis #4

// Uzduotis #4.1

unsigned int countVowels(std::string tekstas) {
    unsigned int vowels{0}; // balsiu kiekis negali buti neigiamas, todel naudojamas unsigned int
    // sukuriama set'as, kuriame bus saugomi balsiai (naudojamas unordered_set, nes jis yra greitesnis nei set)
    // taip pat vietoj galima naudoti std::tolower() funkcija, bet nezinau ar tai yra tiksline funkcija
    std::unordered_set<char> vowelsSet = {'a', 'A', 'e', 'E', 'i', 'I', char('į'), char('Į'), 'u', 'U', 'y', 'Y', 'o', 'O'};
    for (size_t i{0}; i < tekstas.length(); ++i)
        // jeigu esamas simbolis yra balsiu set'e, tai balsiu kiekis padidinamas vienetu
        if (vowelsSet.find(tekstas[i]) != vowelsSet.end())
            ++vowels;
    return vowels;
}

// Uzduotis #4.2

unsigned int countConsonants(std::string tekstas) {
    unsigned int consonants{0}; // priebalsiu kiekis negali buti neigiamas, todel naudojamas unsigned int
    // sukuriama set'as, kuriame bus saugomi priebalsiai (naudojamas unordered_set, nes jis yra greitesnis nei set)
    // taip pat vietoj galima naudoti std::tolower() funkcija, bet nezinau ar tai yra tiksline funkcija
    std::unordered_set<char> consonantsSet = {'p', 'P', 'r', 'R', 'g', 'G', 'm', 'M', 't', 'T', 
    'j', 'J', 'k', 'K', 's', 'S', 'c', 'C', 'l', 'L', 'f', 'F', 'v', 'V', 'b', 'B'};
    for (size_t i{0}; i < tekstas.length(); ++i)
        // jeigu esamas simbolis yra priebalsiu set'e, tai priebalsiu kiekis padidinamas vienetu
        if (consonantsSet.find(tekstas[i]) != consonantsSet.end())
            ++consonants;
    return consonants;
}

// Uzduotis #4.3

void countVowelsAndConsonants(std::string tekstas) {
    unsigned int vowels{0}; // balsiu kiekis negali buti neigiamas, todel naudojamas unsigned int
    // sukuriama set'as, kuriame bus saugomi balsiai (naudojamas unordered_set, nes jis yra greitesnis nei set)
    std::unordered_set<char> vowelsSet = {'a', 'A', 'e', 'E', 'i', 'I', char('į'), char('Į'), 'u', 'U', 'y', 'Y', 'o', 'O'};
    unsigned int consonants{0};
    std::unordered_set<char> consonantsSet = {'p', 'P', 'r', 'R', 'g', 'G', 'm', 'M', 't', 'T',
    'j', 'J', 'k', 'K', 's', 'S', 'c', 'C', 'l', 'L', 'f', 'F', 'v', 'V', 'b', 'B'};
    for (size_t i{0}; i < tekstas.length(); ++i) {
        // jeigu esamas simbolis yra balsiu set'e, tai balsiu kiekis padidinamas vienetu
        // kitu atveju jeigu esamas simbolis yra priebalsiu set'e, tai priebalsiu kiekis padidinamas vienetu
        if (vowelsSet.find(tekstas[i]) != vowelsSet.end())
            ++vowels;
        else if (consonantsSet.find(tekstas[i]) != consonantsSet.end())
            ++consonants;
    }
    std::cout << "Balsiu skacius: " << vowels << std::endl;
    std::cout << "Priebalsiu skaicius: " << consonants << std::endl;
}



