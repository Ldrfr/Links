#pragma once
#include<iostream>


struct list
{
	int field; // поле данных
	struct list* ptr; // указатель на следующий элемент
};


struct list* init(int a);
struct list* push(list* lst, int number);
struct list* delete_first(list* lst);
struct list* delete_elem(list* lst, int number);
struct list* delete_head(list* head);
struct list* add_after_elem(list* head, int number, int id);
struct list* add_before_elem(list* head, int number, int id);
struct list* add_in_tail(list* lst, int number);
struct list* delete_last(list* lst);

struct list* delete_negative(list* lst);
void listprint(list* lst);
