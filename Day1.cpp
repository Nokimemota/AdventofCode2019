
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int recurse(int fuel);

int main()
{	
	int module = 0;
	int fuel = 0;
	int sum = 0;
	fstream input;
	input.open("input.txt");
	while (!input.eof()) {
		input >> module;
		fuel = (module / 3) - 2;
		fuel+= recurse(fuel);
		sum += fuel;
	}
	input.close();

	cout << "The amount of fuel needed is " << sum << endl;
}
int recurse(int fuel) {
	int result = 0;
	while (fuel > 0) {
		fuel = floor(fuel/3) - 2;
		if(fuel>=0)
		result += fuel;
	}
	return result;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
