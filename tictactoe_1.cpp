#include <iostream>
#include <array>
#include <ctime> // Wird benötigt, um rand() mit jedem Aufruf andere Ergebnisse liefern zu lassen
#include <string>

using namespace std;

string result(const array<array<int, 3 >, 3> &field){
	// Gibt aktuellen Zwischenstand als Bild zurück.
	string heading = "Ergebnis:";
	string newline = "\n";
	string y0 = "y0";
	string y1 = "y1";
	string y2 = "y2";
	string x0 = "x0| ";
	string x1 = "x1| ";
	string x2 = "x2| ";
	string border_type_0 = "    ";
	string border_type_1 = "| ";
	string border_type_2 = " | ";
	return (border_type_0 + heading + newline + border_type_0 + y0 + border_type_1 + y1 + border_type_1 + y2 + newline +
			x0 + to_string(field.at(0).at(0)) + border_type_2 + to_string(field.at(0).at(1)) + border_type_2 + to_string(field.at(0).at(2)) + newline +
			x1 + to_string(field.at(1).at(0)) + border_type_2 + to_string(field.at(1).at(1)) + border_type_2 + to_string(field.at(1).at(2)) + newline +
			x2 + to_string(field.at(2).at(0)) + border_type_2 + to_string(field.at(2).at(1)) + border_type_2 + to_string(field.at(2).at(2)) + newline + newline);
};


string greet(const array<array<int, 3 >, 3> &field){
	// Begrüßt Spieler und erklärt Funktionsweise des Spiels
	string newline = "\n";
	string a = "Hallo und herzlich willkommen beim Spiel Tic Tac Toe!\nDu bist Spieler 1, Spieler 2 ist der Computer!\nDas Spielfeld sieht wie folgt aus:";
	string b = "Stell dir das Spielfeld einfach wie ein umgedrehtes Koordinatensystem vor.\nGib zuerst die x-Koordinate, dann die y-Koordinate deines Zuges an. Bestaetige jeweils mit Enter.\nViel Spass!\n";
	return ( newline + a + newline + newline + result(field) +newline + b + newline);
};


int check_won(const array<array<int, 3>, 3> &field){
	// Prüft, ob ein Spieler gewonnen hat und gibt, falls dem so ist, eine entsprechende Nachricht aus.
	for (int i = 0; i <= 2; ++i){
		if (field.at(i).at(0) != 0 && field.at(i).at(0) == field.at(i).at(1) && field.at(i).at(1) == field.at(i).at(2))
			return field[i][0];
		if (field.at(0).at(i) != 0 && field.at(0).at(i) == field.at(1).at(i) && field.at(1).at(i) == field.at(2).at(i))
			return field[0][i];
		if (field.at(0).at(0) != 0 && field.at(0).at(0) == field.at(1).at(1) && field.at(1).at(1) == field.at(2).at(2))
			return field[0][0];
	}	if (field.at(2).at(0) != 0 && field.at(2).at(0) == field.at(1).at(1) && field.at(1).at(1) == field.at(0).at(2))
			return field[2][0];
		return 0;
};


int main(){
	srand(time(NULL)); // 'Seeden' des random number generators auf vergangene Sekunden seit 01.01.1970 -> Liefert bei jedem Aufruf andere Zahl.
	char repeat {'j'}; // Wird benötigt um Programm wiederholbar zu machen.
	array<array<int, 3>, 3> field; // Deklariere Array Spielfeld
	int a, b; // Deklariere Variablen um x- und y-Koordinaten der Spielzüge zwischenzuspeichern.
	
	while (repeat == 'j') {
		// Initialisiere Spielfeld zu Beginn des Spiels.
		field[0] = {0, 0, 0};
		field[1] = {0, 0 ,0};
		field[2] = {0, 0, 0};
	
		// Rufe Funktion greet, die Spieler begrüßt und das Spiel erklärt.
		cout << greet(field);			
		
		// Starte Spiel mit 9 Spielzügen.
		for (int i {0}; i<= 9; ++i){
		
			// Falls Nummer des Zuges (i) gerade, ist Spieler 1 an der Reihe.
			if (i%2 == 0){
				a = 3, b = 3;
				while ((a != 0 && a != 1 && a != 2 || b != 0 && b != 1 && b != 2) || field.at(a).at(b) == 1 || field.at(a).at(b) == 2){
					cout << "Spieler 1, bitte treffe deine Wahl: " << endl;
					cin >> a >> b;
				}
				field[a][b] = 1;
				cout << "Spieler 1 hat gespielt, ";
				cout << result(field);
				if (check_won(field)!= 0){
					cout << "Spieler " << check_won(field) << " hat gewonnen!" << endl;
					break;
				}
			}
			// Falls Nummer des Zuges (i) ungerade, ist Spieler 2 an der Reihe.	
			else{
				a = 3, b = 3;
				while ((a != 0 && a != 1 && a != 2 || b != 0 && b != 1 && b != 2) || field.at(a).at(b) == 1 || field.at(a).at(b) == 2){
					a = ((rand() % 10)-1) / 3;
					b = ((rand() % 10)-1) / 3;
				}	
				field[a][b] = 2;
				cout << "Spieler 2 hat gespielt, "; 
				cout << result(field);
				if (check_won(field)!= 0){
					cout << "Spieler " << check_won(field) << " hat gewonnen!" << endl;
					break;
				}
			}
			// Falls nach dem 9. Zug weder Spieler 1 noch 2 gewonnen haben, ist das Spiel unentschieden.
			if (i == 8){
				cout << "Unentschieden!" << endl;
				break;
			}
		}
		
		cout << "Noch eine Runde? (j/n)" << endl;
		cin >> repeat;

	}
	
	cout << "Das Programm wurde beendet" << endl;
	return 0;
}
