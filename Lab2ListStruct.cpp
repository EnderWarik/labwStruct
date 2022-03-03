// Lab2ListStruct.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

const int l_name = 15, l_other = 10,l_maxStudent = 25 ,l_buf = 2 * l_name + 2 * l_other + 2 + 1;
int count1 = 0, count2 = 0;
struct Student {
    char firstName[l_name+1];
    char lastName[l_name+1];
	char thirdName[l_name + 1];
	int zBook;
	int age;



}model[l_maxStudent];

struct AkademStudent {
	char firstName[l_name + 1];
	char lastName[l_name + 1];
	char thirdName[l_name + 1];
	int zBook;
	int age;
    char timein[l_other + 1];
    char timeout[l_other + 1];
}modelA[l_maxStudent];

int Menu();
int ListsChange();
int Akadem(int list,int i);
int Add(const Student& st, int list);
int Find();
int Remove(int list,int i);
Student GetStuddent();
void PrintAll();
int Change(int list,int i);

int main()
{

	setlocale(LC_ALL, "Russian");


	while (true) {
		switch (Menu()) {
		case 1:Add(GetStuddent(),ListsChange() ); break;
		case 2:Remove(ListsChange(),Find());	 break;
		case 3:std::cout << "длина = " << count1 << std::endl;  break;
		case 4: Find(); break;
		case 5:Change(ListsChange(),Find());  break;
		case 6: PrintAll(); break;
		case 7:Akadem(ListsChange(),Find()); break;
		case 8:  return 0;
		default: puts("Надо вводить число от 1 до 8"); break;
		}
	}
}
int ListsChange() {
	char buf[20];
	int option;
	do {
		puts("Для какого списка? (1 - не в академе/2 - в академе)");
		std::cin.getline(buf, 9);
		option = atoi(buf);
	} while (!option);
	return option;
}

void PrintAll() {
	
	std::cout << "Не в академе:\n";
for(int i=0;i<count1;i++){
	
		printf("%-15s%-15s%-15s%-4i%-15i\n", model[i].firstName, model[i].lastName, model[i].thirdName, model[i].age, model[i].zBook);

	}
std::cout << "В академе:\n";
for (int i = 0; i < count2; i++) {

	printf("%-15s%-15s%-15s%-4i%-15i\n", modelA[i].firstName, modelA[i].lastName, modelA[i].thirdName, modelA[i].age, modelA[i].zBook);

}
}
int Change(int list,int i) {
	char buf[20];
	int option;
	do {
		puts("Что изменить?\n1 - ФИО\n2 - кол-во лет\n3 - Номер студентной книжки)");
		std::cin.getline(buf, 9);
		option = atoi(buf);
	} while (!option);
	if (list == 1) {
		if (option == 1) {
			puts("Новое ФИО студента: ");
			std::cin >> model[i].firstName >> model[i].lastName >> model[i].thirdName;
		}
		else if (option == 2) {
			puts("Новое количество лет(полных):");
			std::cin >> model[i].age;
		}
		else if (option == 3) {
			puts("Новый номер зачетной книжки: ");
			std::cin >> model[i].zBook;
		}
		std::cin.ignore();
	}
	else if (list == 2) {
		if (option == 1) {
			puts("Новое ФИО студента: ");
			std::cin >> modelA[i].firstName >> model[i].lastName >> model[i].thirdName;
		}
		else if (option == 2) {
			puts("Новое количество лет(полных):");
			std::cin >> modelA[i].age;
		}
		else if (option == 3) {
			puts("Новый номер зачетной книжки: ");
			std::cin >> modelA[i].zBook;
		}
		std::cin.ignore();

	}
	return 0;

}
int Remove(int list, int i) {
	int option; char buf[20];
	do { puts("Удалить? (1 - Yes/ 2 - No)");
	std::cin.getline(buf, 9);
	option = atoi(buf);
	} while (!option);

	if (option == 1) {
		if (list == 1) {
			for (int n = i; n < count1; n++) {
				model[n] = model[n + 1];
			}
			count1--;
		}
		else if (list == 2) {
			for (int n = i; n < count2; n++) {
				modelA[n] = modelA[n + 1];
			}
			count2--;
		}
	}

	return 0;

}

int Akadem(int list, int i) {
	int option; char buf[20];
	do {
		puts("Выдать этому студенту академ ?(1 - Yes/ 2 - No)");
		std::cin.getline(buf, 9);
		option = atoi(buf);
	} while (!option);
	if (option == 1) {
		puts("Дата начала: ");
		std::cin >> modelA[count2].timein;
		puts("До какого? ");
		std::cin >> modelA[count2].timeout;
		std::cin.ignore();
		modelA[count2].age = model[i].age;
		strcpy(modelA[count2].firstName, model[i].firstName);
		strcpy(modelA[count2].lastName, model[i].lastName);
		strcpy(modelA[count2].thirdName, model[i].thirdName);
		modelA[count2].zBook = model[i].zBook;
		Remove(i, ListsChange());
		count2++;
	}
	return 0;
}
int Find() {
	Student st; char buf[20];
	int option;
	do {
		puts("----------------Найти-----------------------");
		puts("1 - По ФИО");
		puts("2 - По годам(первый)");
		puts("3 - По зачетной книжке");
		std::cin.getline(buf, 9);
		option = atoi(buf);
	} while (!option); //1 - тру, !1=0 =фалсе
	if (option == 1) {
		puts("ФИО студента: ");
		std::cin >> st.firstName >> st.lastName >> st.thirdName;
	}

	if (option == 2) {
		puts("Количество лет(полных):");
		std::cin >> st.age;
	}
	if (option == 3) {
		puts("Номер зачетной книжки: ");
		std::cin >> st.zBook;
	}
	std::cin.ignore();
	
	bool find = false;
	int i = 0;

	for ( i = 0; i < count1; i++) {
		if ((strcmp(model[i].lastName,st.lastName)==0 && strcmp(model[i].firstName, st.firstName)==0  && strcmp(model[i].thirdName, st.thirdName)==0 )||
			model[i].age == st.age || model[i].zBook == st.zBook) {
			printf("Найден: %-15s%-15s%-15s%-4i%-15i\n", model[i].firstName, model[i].lastName, model[i].thirdName, model[i].age, model[i].zBook);
			find = true;
			break; //тк ищем первого
		}
	}
		if (!find) {
			std::cout << "Cписок пуст" << std::endl;
			return 1;
		}

		return i;
}


int Add(const Student& st,int list) {

	model[count1] = st;
	count1++;
	return 0;
}



Student GetStuddent() {
	Student st; char buf[20];


	puts("ФИО студента: ");
	std::cin >> st.firstName >> st.lastName >> st.thirdName;
	//gets_s(buf);
	//ank.age = atoi(buf);
	

	puts("Количество лет(полных):");
	std::cin >> st.age;
	puts("Номер зачетной книжки: ");
	std::cin >> st.zBook;
	std::cin.ignore();

	return st;

}
int Menu() {
	char buf[10];
	int option;
	do {
		puts("-----------------------------------------------------");
		puts("1 - добавление");
		puts("2 - удаление");
		puts("3 - определение длины списка");
		puts("4 - поиск элемента по значению"); 
		puts("5 - редактирование элемента списка");
		puts("6 - вывод списка на экран");
		puts("7 - получение академа");
		puts("8 - выход");
		//Сколько мужчин старше 40 лет, имеющих высшее образование ответили да
		std::cin.getline(buf,9);
		option = atoi(buf);
	} while (!option); //1 - тру, !1=0 =фалсе
	return option;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
