#include <iostream>
#include <string>

using namespace std;

int doubleOdd(int array[], int size);
int reversesum(int array[], int size);
bool isNumeric(string s);
bool isCorrectLength(string s);

int main() {

	while (true) {
		string creditcard = "";
		cout << "Enter 16-digit credit card # or Q to quit: ";
		getline(cin, creditcard);
		if (cin.fail()) {
				break;
		}
		else if (!isNumeric(creditcard)) {
			cout << "Error - card number must contain only digits." << endl;
		}
		else if (!isCorrectLength(creditcard)) {
			cout << "Error - card number must contain 16 digits" << endl;
		}
		else {
			int array[16];
			for (int i = 0; i < 16; i++) {
				int digit = creditcard[i] - '0';
				array[i] = digit;
			}

			int sum = doubleOdd(array, 16) + reversesum(array, 16);

			if (sum == 50) {
				cout << "Card is valid" << endl;
			}
			else cout << "Card is not valid" << endl;
		}
	}
}

int reversesum(int array[], int size) {
	int sum = 0;
	for (int i = size - 1; i >= 0; i -= 2) {
		sum = sum + array[i];
	}
	return sum;
}

int doubleOdd(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i += 2) {
		int doubling = array[i] * 2;
		int remainder = doubling % 10;
		int tens = doubling / 10;
		sum = sum + remainder + tens;
	}
	return sum;
}

bool isNumeric(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			return false;
		}
	}
	return true;
}

bool isCorrectLength(string s) {
	if (s.length() > 16) {
		return true;
	}
	return false;
}