#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"List.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	struct list* mine = init(9); 
	for (int i = 0; i < 9; ++i) {
		push(mine, i);
	}
	
	add_before_elem(mine, 7, 518);
	add_before_elem(mine, 7, -518);
	add_in_tail(mine, -1000);
	listprint(mine);
	cout << "\n";
	//delete_negative(mine);
	//delete_elem(mine, 518);
	int pp=1;
	while (pp != 0) {
		cout << "������� ������� ";
		cin >> pp;
		switch (pp) {
		case 1: {
			cout << "�������� ����� ������� ������: ";
			int a, b;
			cin >> a >> b;
			add_after_elem(mine, a, b);
			listprint(mine);
			cout << "\n";
			break; 
		}
		case 2: {
			cout << "�������� � ������: ";
			int a;
			cin >> a;
			push(mine, a);
			listprint(mine);
			cout << "\n";
			break;
		}
		case 3: {
			cout << "������� ������� - ��� �����: ";
			int a;
			cin >> a;
			delete_elem(mine, a);
			listprint(mine);
			cout << "\n";
			break;
		}
		case 4: {
			cout << "Elfkbnm gthdsq 'ktvtyn: ";
			delete_first(mine);
			listprint(mine);
			cout << "\n";
			break;
		}
		case 5: {
			cout << "�������� ����� ������ ������: ";
			int a, b;
			cin >> a >> b;
			add_before_elem(mine, a, b);
			listprint(mine);
			cout << "\n";
			break;
		}
		  case 6: {
			  cout << "�������� � ����� ������: ";
			  int a;
			  cin >> a;
			  add_in_tail(mine, a);
			  listprint(mine);
			  cout << "\n";
			  break;
		}
		case 7: {
			cout << "������� ��������� ������� ";
			delete_last(mine);
			listprint(mine);
			cout << "\n";
			break;
		}
		case 8: {
			cout << "��������������, ������� ��� ������������� ��������: ";
			delete_negative(mine);
			listprint(mine);
			cout << "\n";
			break;
		}
		}
	}
	listprint(mine);
}