#include <iostream>
#include <string>

using namespace std;

struct Node{
	int key;
	Node* next;
};

struct List{
	Node* head;
	Node* tail;
};

//4.1

Node* createNode(int data){
	Node* p = new Node;
	p->key = data;
	p->next = NULL;
	return p;
}

//4.2
List* createList(Node* p){
	List* l = new List;
	l->head = p;
	l->tail = p;
	return l;
}

//4.3
bool addHead(List* &L, int data){
	Node* p = createNode(data);
	if(p == NULL) 
		return false;
	if(L == NULL){
		L = createList(p);
		return true;
	}
	p->next = L->head;
	L->head = p;
	return true;
}

//4.4
bool addTail(List* &L, int data){
	Node* p = createNode(data);
	if(p == NULL) 
		return false;
	if(L == NULL){
		L = createList(p);
		return true;
	}
	L->tail->next = p;
	L->tail = p;
	return true;
}


//4.5
void removeHead(List *&L){
	if(L == NULL)
		return;
	if(L->head == L->tail){
		delete L->head;
		L = NULL;
	}
	Node* p = L->head;
	L->head = L->head->next;
	delete p;
}

//4.6
void removeTail(List* &L){
	if(L == NULL)
		return;
	if(L->head == L->tail){
		delete L->head;
		L = NULL;
		return;
	}
	Node* p = L->head;
	while(p->next != L->tail){
		p = p->next;
	}
	delete L->tail;
	L->tail = p;
    p->next = NULL;
}

//4.7
void removeAll(List* &L){
	while(L != NULL){
		removeHead(L);
	}
}

//4.8
void removeBefore(List* &L, int val){
	if(L == NULL)
		return;
	if(L->head->next->key == val){
		removeHead(L);
		return;
	}
	Node* p1 = L->head;
	Node* p2 = L->head->next;
	while((p2 != NULL) && (p2->next->key != val)){
		p2 = p2->next;
		p1 = p1->next;
	}
	if(p2 == NULL)
		return;
	p1->next = p2->next;
	delete p2;
}
//4.12
bool addBefore(List* &L, int data, int val){ 
    if(L == NULL)
        return false;
    if(L->head->key == val){
		addHead(L, data);
		return true;
	}
	Node* p1 = L->head;
	Node* p2 = L->head->next;
	while((p2 != NULL) && (p2->key != val)){
		p2 = p2->next;
		p1 = p1->next;
	}
	if(p2 == NULL)
		return false;
    Node* p = createNode(data);
	p1->next = p;
    p->next = p2;
    return true;
}
//4.9
void removeAfter(List* &L, int val){
	if(L == NULL)
		return;
	Node* p1 = L->head;
	while((p1 != NULL) && (p1->key != val)){
		p1 = p1->next;
	}
    if(p1 == NULL)
		return;
	if(p1->next->next == NULL){
        removeTail(L);
        return;
    }
    Node* p = p1->next;
	p1->next = p->next;
	delete p;
}

//4.10
// bool addPos(List* &L, int data, int pos){
// 	if(L == NULL)
// 		return false;
//     int i = 1;
// 	Node* p = L->head;
// 	while((p != NULL) && (i != pos)){
// 		p = p->next;
//         i++;
// 	}
//     if(p == NULL)
// 		return false;
// 	if(p->next->next == NULL){
//         removeTail(L);
//         return ;
//     }
//     Node* p = p1->next;
// 	p1->next = p->next;
// 	delete p;
// }
// 4.13
void addAfter(List* &L,int data, int val){
	if(L == NULL)
		return false;
	Node* p1 = L->head;
	while((p1 != NULL) && (p1->key != val)){
		p1 = p1->next;
	}
    if(p1 == NULL)
		return false;
	if(p1->next == NULL){
        addTail(L, data);
        return true;
    }
    Node* p = p1->next;
    Node* p2 = createNode(data);
	p1->next = p;
    p->next = p2;
    return true;
}

// 4.11
void removePos(List* &L, int pos){
	if(L == NULL)
		return ;
    int i = 1;
	Node* p = L->head;
	while((p != NULL) && (i != pos)){
		p = p->next;
        i++;
	}
    if(p == NULL)
		return ;
    Node* p1 = p->next;
    if (p1 == NULL){
        removeTail(L);
    }
	removeBefore(L, p1->key );
}

//4.14
void printList(List* L){
    Node* p = L ->head;
    while(p != NULL){
        cout << p->key << " " ;
        p = p->next;
    }
    cout << endl;
    
}

// 4.16
List* reverseList(List* L){
    List* L1 = createList(createNode(L->head->key));
    Node* p = L ->head->next;
    while(p != NULL){
        addHead(L1, p->key);
        p = p->next;
    }
    return L1;    
}

// 4.17

void removeDuplicate(List* &L){
    if (L == NULL)
        return ;
    Node* p = L ->head;
    Node* p2 ;
    int i = 1, j;
    while(p != NULL){
        Node* p1 = p ->next;
        j = i++;
        while (p1 != NULL){
            if (p1->key == p->key){
                p2 = p1->next;
                if (p2 == NULL){
                    removeTail(L);
                }
                else{
                    removePos(L, j);
                }
                p1 = p2;
            }
            else{
                p1 = p1->next;
                j++;
            }
           
        }
        p = p->next;
        i++;
    }
}
int main(){
	
	//Permutation("ABCD", 0);
	
	//cout << countCommonDivisor(15, 45, 1);
	
	/*
	int** a = new int*[8];
	for(int i = 0; i < 8; i++){
		a[i] = new int[8];
	}
	generateMatrix1(a, 8, 8);
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
	
	int** b = findSubmatrix(a, 8, 8, 4, 4);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << b[i][j] << "   ";
		}
		cout << endl;
	}
	*/
	return 0;
}
