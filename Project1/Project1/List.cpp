#include"List.h";
using namespace std;
struct list* init(int a){ // а - значение первого узла
	struct list* lst;
	// выделение памяти под корень списка
	//lst = (struct list*)malloc(sizeof(struct list));
	lst = new list;
	lst->field = a;
	lst->ptr = NULL; // state last node
	return(lst);
}


struct list* push(list* head, int number){
	struct list* elem;
	elem = new list;
	elem->ptr = head->ptr;
	head->ptr = elem; 
	elem->field = number; 
	return head;
}

struct list* delete_first(list* head) {/////////////////////////
	struct list* tmp;
	struct list* p;
	tmp = head->ptr;
	if (tmp->ptr == NULL) delete_head(head);
	p = tmp->ptr;
	delete(tmp);////нужно ли освобождать или и так исчезает
	head->ptr = p;
	return head;
}

struct list* delete_elem(list* lst, int number) {
	struct list* tmp;
	tmp = lst;
	struct list* p;
	p = lst;
	while (tmp->ptr!=NULL && tmp->ptr->field != number) {
		tmp = tmp->ptr;
		p = p->ptr;
	}if (tmp->ptr == NULL) cout << "mistake" << "\n";
	else {
		p = p->ptr;
		//lst = lst->ptr;
		tmp->ptr = p->ptr;
		delete(p);
	}
	return lst;
}


struct list* add_after_elem(list* lst, int number, int id) {
	struct list* tmp;
	tmp = lst;
	struct list* elem = new list;
	elem->field = id;
	while (tmp!=NULL && tmp->field != number) {
		tmp = tmp->ptr;
	} if (tmp == NULL) cout << "mistake" << "\n";
	else {
		elem->ptr = tmp->ptr;
		tmp->ptr = elem;
	}
	return lst;
}



struct list* add_before_elem(list* lst, int number, int id) {
	struct list* tmp;////////почему нельзя написать = new list, как сделать проверку если элемента нет вернуть NULL не вариант
	tmp = lst;
	struct list* elem = new list;
	elem->field = id;
	while (tmp->ptr != NULL && tmp->ptr->field != number) {
		tmp = tmp->ptr;
	}if (tmp->ptr == NULL) cout << "mistake" << "\n";
	else {
		elem->ptr = tmp->ptr;
		tmp->ptr = elem;
	}
	return lst;
}


struct list* delete_head(list* lst){
	struct list* tmp;
	tmp = lst->ptr;
	delete(lst); // старый гуляет
	return(tmp); // головой будет
}

struct list* add_in_tail(list* lst, int number) {
	struct list* tmp;
	struct list* elem = new list;
	tmp = lst;
	while (tmp->ptr != NULL) {
		tmp = tmp->ptr;
	}
	elem->field = number;
	tmp->ptr = elem;
	elem->ptr = NULL;
	return tmp;
}

struct list* delete_last(list* lst) {///////////////////////////////////////

	struct list* tmp;
	tmp = lst;
	if (tmp->ptr==NULL) delete_head(lst);
	else {
		struct list* p;
		while (tmp->ptr->ptr != NULL) {
			tmp = tmp->ptr;
		}
		p = tmp->ptr;
		tmp->ptr = NULL;
		delete(p);
	}
	return lst;
}//////////////////////////////////

/*struct list* delete_negative(list* lst) {
	if (lst->field < 0) delete_head(lst);
	struct list* tmp;
	tmp = lst->ptr;
	struct list* next;
	struct list* prev;
	prev = lst;
	next = tmp->ptr;
	if (tmp->field < 0) {
		tmp = tmp->ptr;
		next = tmp->ptr;
		delete_first(lst);
	}
	while (next != NULL) {
		prev = tmp;
		tmp = tmp->ptr;//сдвиг
		next = tmp->ptr;
		if (tmp->field < 0) {
			prev->ptr = next;
			delete(tmp);
		}
	}
	return lst;
}*/

struct list* delete_negative(list* lst) {
	struct list* temp;
	temp = lst;
	while (temp->ptr != NULL) {
		if (temp->field < 0) {
			struct list* t;
			t = temp->ptr;
			delete_elem(lst, temp->field);
			temp->ptr = t;
		}
		temp = temp->ptr;
	}
	if (temp->field < 0) delete_last(lst);
	return lst;
}

void listprint(list* lst){
	struct list* p;
	p = lst;
	p = p->ptr;
	while (p != NULL) {
		cout << p->field << " ";
		p = p->ptr;
	}
	/*do{
		cout << p->field << " ";
		p = p->ptr; //transition
	} while (p != NULL);*/
}