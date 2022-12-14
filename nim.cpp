#include <bits/stdc++.h>

using namespace std;

int random_number(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

string ToBinary(int n) {
	string result="";
	int binaryNumber[100], num=n;
	int i = 0;
	while (n > 0) {
		binaryNumber[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		result += to_string(binaryNumber[j]);
	return result;
}

int one_index(string num) {
	string str_num = num;
	int nn = 0;
	for (int i = str_num.length()-1; i >= 0 ; i--) {
		if (str_num[i] == '1') {
			nn = num.length() - i - 1;
		}
	}
	return nn;
}

int computer_turn(int arr[3], int len) {
	int all_xor = 0, a=0;
	bool con=true;
	for (int i = 0 ; i <= sizeof(arr)/sizeof(arr[0]) ; i++) {
		all_xor = all_xor^arr[i];
	}
	string all_xors = ToBinary(all_xor);
	int one = one_index(all_xors);
	// cout << "xor kol: " << all_xors << endl;
	// cout << "first one: " << one << endl;

	if (all_xor == 0) {
		for (int i = 0; i < len; i++) {
			if (arr[i]>0) {
				arr[i] = random_number(0, arr[i]-1);
				break;
			}
		}
		for (int i = 0; i < len; i++) {
			if (arr[i] == a) {
				arr[i] = (all_xor^a);
			}
			cout << arr[i] << " ";
		}
	} else {

		for (int i = 0 ; i < len ; i++) {
			if (con==false) {
				break;
			}
			string abin = ToBinary(arr[i]);
			if (ToBinary(arr[i])[abin.length()-(one+1)] == '1') {
				a = arr[i];
				con = false;
			}
		}
		// cout << a << " ro khat bezan, bokon " << (all_xor^a) << endl;
		for (int i = 0; i < len; i++) {
			if (arr[i] == a) {
				arr[i] = (all_xor^a);
			}
			cout << arr[i] << " ";
		}
	}
	return 0;
}



int main() {
	int n, number;
	bool help=false;
	bool turn=true;
	srand(time(0));
	// int a=random_number(1, 50), b=random_number(1, 50), c=random_number(1, 50);
	// cout << a << " " << b << " " << c << endl;

	// cout << (a^b^c) << endl;
	// if (a^b^c != 0) {
	//     int one_index = one_index(a^b^c);
	//     for (int i = 0; i < 3; i++){

	//     }
	// }
	if (random_number(1, 2) == 1) {
		turn = false;
	} else {
		turn = true;
	}
	cout << "nim chand taee?" << endl;
	cin >> n;
	int numbers_list[n];

	cout << "aadad:" << endl;
	for (int i = 0; i < n; i++) {
		number = random_number(10, 50);
		numbers_list[i] = number;
		cout << number << " ";
	}
	cout << "\n--------------" << endl;
	while (true) {
		if (turn) {
			cout << "turn: computer" << endl;
		} else {
			cout << "turn: you" << endl;
		}

		if (turn) {
			help = false;
			turn = false;
			computer_turn(numbers_list, n);
			for (int i = 0; i < n; i++) {
				if (numbers_list[i] != 0) {
					help = true;
				}
				cout << " ";
			}
			cout << "\n--------------" << endl;
		} else {
			help = false;
			turn = true;
			for (int i = 0; i < n; i++) {
				cin >> number;
				if (number != 0) {
					help = true;
				}
				numbers_list[i] = number;
				// cout << " ";
			}
			cout << "--------------" << endl;

		}
		if (help==false) {
			if (turn) {
				cout << "you won" << endl;
			} else {
				cout << "computer won" << endl;
			}
			break;
		}
	}


	return 0;
}

