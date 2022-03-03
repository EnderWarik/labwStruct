//#define _CRT_SECURE_NO_WARNINGS
//#include <fstream>
//#include <iostream>
//using namespace std;
//const int l_name = 15, l_other = 10, l_maxStudent = 25, l_buf = 2 * l_name + 2 * l_other + 2 + 1;
//struct Student {
//	char firstName[l_name + 1];
//	char lastName[l_name + 1];
//	char thirdName[l_name + 1];
//	int zBook;
//	int age;
//	Student* next;
//}model[l_maxStudent];
//
//struct AkademStudent {
//	char firstName[l_name + 1];
//	char lastName[l_name + 1];
//	char thirdName[l_name + 1];
//	int zBook;
//	int age;
//	char timein[l_other + 1];
//	char timeout[l_other + 1];
//	AkademStudent* next;
//
//}modelA[l_maxStudent];
//
//int Menu();
//
//Student* Add(Student* beg, const Student& st);
//Student* Find(Student* beg);
//Student* Remove(Student* beg);
//Student GetStuddent();
//void PrintAll(Student* beg);
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	char buf[l_buf];
//	Student* beg = 0;
//	Student one;
//	while (true) {
//		switch (Menu()) {
//		case 1:beg = Add(beg, GetStuddent()); break;
//		case 2:beg = Remove(beg);	 break;
//		case 3:  break;
//		case 4: Find(beg); break;
//		case 5:PrintAll(beg);  break;
//		case 6:  break;
//		case 7:  return 0;
//		default: puts("Надо вводить число от 1 до 7"); break;
//		}
//	}
//}
//
//void PrintAll(Student* beg) {
//	Student* pv = beg;
//
//	while (pv) {
//
//		printf("%-15s%-15s%-15s%-4i%-15i\n", pv->firstName, pv->lastName, pv->thirdName, pv->age, pv->zBook);
//		pv = pv->next;
//	}
//}
//
//Student* Remove(Student* beg) {
//	Student st; char buf[20];
//	int option;
//	do {
//		puts("----------------Удалить-----------------------");
//		puts("1 - По ФИО");
//		puts("2 - По годам(первый)");
//		puts("3 - По зачетной книжке");
//		cin.getline(buf, 9);
//		option = atoi(buf);
//	} while (!option); //1 - тру, !1=0 =фалсе
//	if (option == 1) {
//		puts("ФИО студента: ");
//		cin >> st.firstName >> st.lastName >> st.thirdName;
//	}
//
//	if (option == 2) {
//		puts("Количество лет(полных):");
//		cin >> st.age;
//	}
//	if (option == 3) {
//		puts("Номер зачетной книжки: ");
//		cin >> st.zBook;
//	}
//	cin.ignore();
//	Student* pv = new Student(st); // указатель на  объект
//	//создаем, тк st константа
//
//	bool find = false;
//
//	//список не пуст
//	Student* temp = beg;
//	while (temp) {
//		if (strcmp(temp->lastName, pv->lastName) == 0 && strcmp(temp->firstName, pv->firstName) == 0 && strcmp(temp->thirdName, pv->thirdName) == 0 ||
//			temp->age == pv->age || temp->zBook == pv->zBook) {
//			find = true;
//			printf("%-15s%-15s%-15s%-4i%-15i\n", (temp - 1)->firstName, (temp - 1)->lastName, (temp - 1)->thirdName, (temp - 1)->age, (temp - 1)->zBook);
//			printf("%-15s%-15s%-15s%-4i%-15i\n", (temp + 1)->firstName, (temp + 1)->lastName, (temp + 1)->thirdName, (temp + 1)->age, (temp + 1)->zBook);
//			//(temp - 1)->next = (temp)->next;
//
//			break;
//
//		}
//		temp = temp->next;//поиск конца списка
//	}
//
//
//
//	if (!find) {
//		cout << "Не найдено" << endl;
//		return beg;
//	}
//	else {
//
//	}
//
//	return temp;
//
//}
//
//Student* Find(Student* beg) {
//	Student st; char buf[20];
//	int option;
//	do {
//		puts("----------------Найти-----------------------");
//		puts("1 - По ФИО");
//		puts("2 - По годам(первый)");
//		puts("3 - По зачетной книжке");
//		cin.getline(buf, 9);
//		option = atoi(buf);
//	} while (!option); //1 - тру, !1=0 =фалсе
//	if (option == 1) {
//		puts("ФИО студента: ");
//		cin >> st.firstName >> st.lastName >> st.thirdName;
//	}
//
//	if (option == 2) {
//		puts("Количество лет(полных):");
//		cin >> st.age;
//	}
//	if (option == 3) {
//		puts("Номер зачетной книжки: ");
//		cin >> st.zBook;
//	}
//	cin.ignore();
//	Student* pv = new Student(st); // указатель на  объект
//	//создаем, тк st константа
//
//	bool find = false;
//
//	//список не пуст
//	Student* temp = beg;
//	while (temp) {
//		if (strcmp(temp->lastName, pv->lastName) == 0 && strcmp(temp->firstName, pv->firstName) == 0 && strcmp(temp->thirdName, pv->thirdName) == 0 ||
//			temp->age == pv->age || temp->zBook == pv->zBook) {
//			find = true;
//
//			printf("%-15s%-15s%-15s%-4i%-15i\n", temp->firstName, temp->lastName, temp->thirdName, temp->age, temp->zBook);
//			break;
//
//		}
//		temp = temp->next;//поиск конца списка
//	}
//
//
//
//	if (!find) {
//		cout << "Cписок пуст" << endl;
//		return beg;
//	}
//
//	return temp;
//}
//
//
//Student* Add(Student* beg, const Student& st) {
//	Student* pv = new Student(st); // формирование нового элемента *py = ank
//	//создаем, тк st константа. А иначе жалуется 
//	pv->next = 0;
//	if (beg) {
//		//список не пуст
//		Student* temp = beg;
//		while (temp->next)
//			temp = temp->next;//поиск конца списка
//		temp->next = pv; // Привязвание нового элемента
//	}
//	else { //список пусть
//
//		beg = pv;
//
//	}
//	return beg;
//}
//
//
//
//Student GetStuddent() {
//	Student st; char buf[20];
//
//
//	puts("ФИО студента: ");
//	cin >> st.firstName >> st.lastName >> st.thirdName;
//	//gets_s(buf);
//	//ank.age = atoi(buf);
//
//
//	puts("Количество лет(полных):");
//	cin >> st.age;
//	puts("Номер зачетной книжки: ");
//	cin >> st.zBook;
//	cin.ignore();
//
//	return st;
//
//}
//int Menu() {
//	char buf[10];
//	int option;
//	do {
//		puts("-----------------------------------------------------");
//		puts("1 - добавление");
//		puts("2 - удаление");
//		puts("3 - определение длины списка");
//		puts("4 - поиск элемента по значению");
//		puts("4 - редактирование элемента списка");
//		puts("5 - вывод списка на экран");
//		puts("6 - получение/выход из академа");
//		puts("7 - выход");
//		//Сколько мужчин старше 40 лет, имеющих высшее образование ответили да
//		cin.getline(buf, 9);
//		option = atoi(buf);
//	} while (!option); //1 - тру, !1=0 =фалсе
//	return option;
//}