#include <iostream>
#include <limits>
using namespace std;
//Дано три числа. Знайти суму двох найбільших з них.
void task_if15(); // завдання 1 декларація функції

// Дано координати точки на площині (x, y).
// Визначити, чи потрапляє точка в фігуру заданого кольору (або групу фігур)
// і вивести відповідне повідомлення.
void task_geom11();// завдання 2 декларація функції

int main()
{
	int menu;
	cout << "Task number:";
	cin >> menu;

	// перемикання між завданнями
	switch (menu)
	{
	case 1: task_if15(); break;							// Завдання 1
	case 2: task_geom11(); break;						 // Завдання 2
	default: cout << "Wrong task! (Only 1,2) " << endl; //повідомлення про помилку
	}
	system("pause");
	return 0;
}

// завдання 1 реалізація
void task_if15()
{
	int a, b, c;
	cout << "************* If 15 *****************" << endl;

	//цикл із перевіркою правильності введення
	while (true) {
		cout << "Enter three numbers:";
		cin >> a >> b >> c;

		if (cin.fail()) {
			cin.clear();												//очищаємо стан потоку
			cin.ignore(numeric_limits<streamsize>::max(), '\n');		//пропускаємо неправильне введення
			cout << "Input error! Please enter only numbers. \n" << endl;
		}
		else {
			break;		//виходимо із циклу, якщо введено правильно
		}
	}


	int sum;

	// знайдемо суму двох найбільших
	if (a <= b && a <= c)
		sum = b + c;			//a-найменше
	else if (b <= a && b <= c)
		sum = a + c;			//b-найменше
	else
		sum = a + b;			//c-найменше

	cout << "Sum of the two largest numbers =" << sum << endl;

}

// завдання 2 реалізація
void task_geom11()
{
	float x, y, r;

	cout << "********** Point in geometry region 11 **********" << endl;

	//цикл із перевіркою правильності введення
	// Ввід координат x
	cout << "Enter x: ";
	while (!(cin >> x)) {
		cout << "Invalid input! Please enter a number for x: ";
		cin.clear();                                                // скидаємо стан потоку
		cin.ignore(numeric_limits<streamsize>::max(), '\n');        // чистимо буфер вводу
	}

	// Ввід координат y
	cout << "Enter y: ";
	while (!(cin >> y)) {
		cout << "Invalid input! Please enter a number for y: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	// Ввід радіуса r
	cout << "Enter radius r (> 0): ";
	while (!(cin >> r) || r <= 0) {
		cout << "Invalid input! Please enter a positive number for r: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	// Умова для області 1 (верхнє праве коло)
	bool inUpperRight = (x >= 0 && y >= 0 && (x * x + y * y <= r * r));
	// Умова для області 2 (нижнє ліве коло)
	bool inLowerLeft = (x <= 0 && y <= 0 && (x * x + y * y <= r * r));

	if (inUpperRight || inLowerLeft) {
		cout << "Point (" << x << ", " << y << ") is INSIDE region 11." << endl;
	}
	else {
		cout << "Point (" << x << ", " << y << ") is OUTSIDE region 11." << endl;
	}
}
