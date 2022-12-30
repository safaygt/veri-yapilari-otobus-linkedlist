// veri_yapilari_2.odev.cpp : 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define MAX 5

struct yolcu {

	char name[20];
	char LastName[20];
	int koltukNo;
	struct yolcu* next;
	struct yolcu* prev;

};

struct bus {
	int busNo;
	struct bus* next;
	struct bus* prev;

};

struct stack {

	int top;
	struct bus* dizi[];

};

struct stack BUS = { -1,0 };

int count = 0;
int busCount = 0;

struct yolcu* root = NULL;
struct bus* root2 = NULL;

bool isEmpty() {
	if (BUS.top == -1) {
		return true;
	}
	else {
		return false;
	}

}

bool isFull() {
	if (BUS.top == MAX) {
		return true;

	}
	else {
		return false;
	}
}

void printYolcu() {
	int x = 1;
	if (root == NULL) {
		printf("Liste bos!\n");
	}
	else {
		struct yolcu* p;
		p = root;

		while (p != NULL) {
			if ((p->koltukNo) % 5 == 1){
				printf("********%d. Otobus*********\n", x);
				x++;
            }
			printf("%d nolu Yolcu - Yolcu Adi: %s - Yolcu Soyadi: %s\n", p->koltukNo, p->name, p->LastName);
			p = p->next;
		}
	}

	printf("\n");
}

void push(struct bus* list) {
	if (isFull()) {
		printYolcu();
		printf("\n\nOtobusler Dolu!!");
		exit(5);
	}
	else {
		BUS.top++;
		BUS.dizi[BUS.top] = list;
	}
}

void ekleBus() {
	struct bus* temp = (struct bus*)malloc(sizeof(struct bus));
	busCount++;
	temp->busNo = busCount;
	temp->next = NULL;
	temp->prev = NULL;

	push(temp);

	if (root2 == NULL) {
		root2 = temp;
	}
	else {
		struct bus* p2;
		p2 = root2;

		while (p2->next != NULL) {
			p2 = p2->next;
		}
		p2->next = temp;
		temp->prev = p2;

	}

}

void ekleYolcu() {
	if (count > 24) {
		printYolcu();
		printf("\n\n\n\nYer YOK!");
		exit(5);
	}
	else {
		if (count % 5 == 0) {
			ekleBus();
			if (isFull()) {
				return;
			}
		}

		struct yolcu* temp = (struct yolcu*)malloc(sizeof(struct yolcu));

		count++;
		temp->koltukNo = count;
		printf("İsim giriniz: ");
		scanf("%s", temp->name);
		printf("\nSoyisim giriniz: ");
		scanf("%s", temp->LastName);

		temp->next = NULL;
		temp->prev = NULL;

		if (root == NULL) {
			root = temp;
		}
		else {
			struct yolcu* p;
			p = root;

			while (p->next != NULL) {
				p = p->next;
			}
			p->next = temp;
			temp->prev = p;
		}

	}

}

int main()
{
	int secim;

	while (true) {
		printf("\n\n******\n\n");
		printf("1- Yolcu Ekle\n");
		printf("2- Yolcu Listele\n");
		printf("3- Cikis\n");

		printf("Secim yapiniz: ");
		scanf("%d", &secim);

		switch (secim) {
		case 1:
			ekleYolcu();
			break;
		case 2:
			printYolcu();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("\nBir daha seciniz.\n");
			break;

		}

	}
}

