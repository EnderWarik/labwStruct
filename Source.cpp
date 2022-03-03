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
//		default: puts("���� ������� ����� �� 1 �� 7"); break;
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
//		puts("----------------�������-----------------------");
//		puts("1 - �� ���");
//		puts("2 - �� �����(������)");
//		puts("3 - �� �������� ������");
//		cin.getline(buf, 9);
//		option = atoi(buf);
//	} while (!option); //1 - ���, !1=0 =�����
//	if (option == 1) {
//		puts("��� ��������: ");
//		cin >> st.firstName >> st.lastName >> st.thirdName;
//	}
//
//	if (option == 2) {
//		puts("���������� ���(������):");
//		cin >> st.age;
//	}
//	if (option == 3) {
//		puts("����� �������� ������: ");
//		cin >> st.zBook;
//	}
//	cin.ignore();
//	Student* pv = new Student(st); // ��������� ��  ������
//	//�������, �� st ���������
//
//	bool find = false;
//
//	//������ �� ����
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
//		temp = temp->next;//����� ����� ������
//	}
//
//
//
//	if (!find) {
//		cout << "�� �������" << endl;
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
//		puts("----------------�����-----------------------");
//		puts("1 - �� ���");
//		puts("2 - �� �����(������)");
//		puts("3 - �� �������� ������");
//		cin.getline(buf, 9);
//		option = atoi(buf);
//	} while (!option); //1 - ���, !1=0 =�����
//	if (option == 1) {
//		puts("��� ��������: ");
//		cin >> st.firstName >> st.lastName >> st.thirdName;
//	}
//
//	if (option == 2) {
//		puts("���������� ���(������):");
//		cin >> st.age;
//	}
//	if (option == 3) {
//		puts("����� �������� ������: ");
//		cin >> st.zBook;
//	}
//	cin.ignore();
//	Student* pv = new Student(st); // ��������� ��  ������
//	//�������, �� st ���������
//
//	bool find = false;
//
//	//������ �� ����
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
//		temp = temp->next;//����� ����� ������
//	}
//
//
//
//	if (!find) {
//		cout << "C����� ����" << endl;
//		return beg;
//	}
//
//	return temp;
//}
//
//
//Student* Add(Student* beg, const Student& st) {
//	Student* pv = new Student(st); // ������������ ������ �������� *py = ank
//	//�������, �� st ���������. � ����� �������� 
//	pv->next = 0;
//	if (beg) {
//		//������ �� ����
//		Student* temp = beg;
//		while (temp->next)
//			temp = temp->next;//����� ����� ������
//		temp->next = pv; // ����������� ������ ��������
//	}
//	else { //������ �����
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
//	puts("��� ��������: ");
//	cin >> st.firstName >> st.lastName >> st.thirdName;
//	//gets_s(buf);
//	//ank.age = atoi(buf);
//
//
//	puts("���������� ���(������):");
//	cin >> st.age;
//	puts("����� �������� ������: ");
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
//		puts("1 - ����������");
//		puts("2 - ��������");
//		puts("3 - ����������� ����� ������");
//		puts("4 - ����� �������� �� ��������");
//		puts("4 - �������������� �������� ������");
//		puts("5 - ����� ������ �� �����");
//		puts("6 - ���������/����� �� �������");
//		puts("7 - �����");
//		//������� ������ ������ 40 ���, ������� ������ ����������� �������� ��
//		cin.getline(buf, 9);
//		option = atoi(buf);
//	} while (!option); //1 - ���, !1=0 =�����
//	return option;
//}