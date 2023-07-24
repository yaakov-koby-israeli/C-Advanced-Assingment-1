// Course: Advanced C programming
// exercise 1, question 3
// file name: ex1_q3.c
#define _CRT_SECURE_NO_WARNINGS
// --------------------------- //
// include package section:
#include <stdio.h>
#include <stdlib.h>

// --------------------------- //
//
//	Assigned by:
//		Student1_Full_Name Bar Brener #ID 207703026
//		Student2_Full_Name Yaakov Israeli #ID 208196816
//
// --------------------------- //

// structs and function declarations section:
typedef struct rectangle {
	int xTopSmall;
	int yTopSmall;
	int xButtomRight;
	int yButtomRight;
}rectangle;

typedef struct recElement {
	rectangle Rect;
	struct recElement* next;
}recElement;

int validateRectangle(rectangle* rec);
rectangle scanRectangle();
recElement* createElement();
recElement* createRectList();
rectangle findSmallest(recElement* head);
void printRectangle(rectangle* rec);
void printList(recElement* head);
void freeList(recElement* head);

// --------------------------- //

int main()
{
	rectangle rec;
	recElement* head = NULL;

	// Start Program:
	printf("Start Program\n");

	// call functions:
	head = createRectList();

	printf("\n\nRectangle list:\n");
	printList(head);

	rec = findSmallest(head);

	printf("\n\nFilling rectangle:\n");
	printRectangle(&rec);

	freeList(head);
	head = NULL;

	printf("\n\n");

	return 0;
}
// --------------------------- //


/// <summary>
/// Function gets an address of a rectangle and check validity.
/// </summary>
/// <param>Address of rectangle</param>
/// <returns>0- if rectangle is not valid, 1-if rectangle is a valid, 2-if rectangle is a point</returns>
int validateRectangle(rectangle* rec)
{
	// your code:
	if (rec->xButtomRight == rec->xTopSmall && rec->yButtomRight == rec->yTopSmall) return 2;
	else if (rec->xButtomRight > rec->xTopSmall && rec->yButtomRight < rec->yTopSmall) return 1;
	return 0;
}
// --------------------------- //



/// <summary>
/// Function scan a rectangle in the plane,
/// Used as auxiliary function for createElement.
/// </summary>
/// <param>None</param>
/// <returns>a newly scanned rectangle</returns>
rectangle scanRectangle()
{
	// your code:
	rectangle r1;
 
	int flag =0;
	while (!flag) {
		printf("please enter xTopSmall\n");// int xTopSmall int yTopSmall int xButtomRight; int yButtomRight;;
		scanf("%d", &(r1.xTopSmall));
		printf("please enter yTopSmall\n");
		scanf("%d", &(r1.yTopSmall));
		printf("please enter xButtomRight\n");
		scanf("%d", &(r1.xButtomRight));
		printf("please enter yButtomRight\n");
		scanf("%d", &(r1.yButtomRight));
		flag = validateRectangle(&r1);
	}
	return r1;


}
// --------------------------- //


/// <summary>
/// Function allocate a new recElement.
/// Calls scanRectangle during the process. 
/// if the scanned rectangle is a point, returns NULL.
/// </summary>
/// <returns>New allocated recElement or NULL if rectangle is a point</returns>
recElement* createElement()
{
	// your code:
	recElement* r1 = (recElement*)malloc(sizeof(recElement));
	if (!r1) return 0;
	r1->Rect = scanRectangle();
	r1->next = NULL;
	int check = validateRectangle(&(r1->Rect));
	if (check == 2) return NULL;
	return r1;
}
// --------------------------- //


/// <summary>
/// Function creates a list of rectangles.
/// Calls function createElement in a loop.
/// Scan stops when createElement returns null.
/// </summary>
/// <param>None</param>
/// <returns>The Euclidean distance between p1 and p2</returns>
recElement* createRectList()
{
	// your code:
	recElement* head = createElement();
	if (!head) return NULL;
	recElement* ptr = head;
	while (ptr) {
		ptr->next = createElement();
		ptr = ptr->next;
	}
	return head;

}
// --------------------------- //


/// <summary>
/// Function gets a list and returns the filling rectangle
/// </summary>
/// <param>recElement* head - the list of rectangles</param>
/// <returns>The filling rectangle. if the list is empty return rectangle with (0,0,0,0)</returns>
rectangle findSmallest(recElement* head)
{
	// your code:
	rectangle r1;
	if (!head) {
		
		r1.xButtomRight = 0;
		r1.yButtomRight = 0;
		r1.xTopSmall = 0;
		r1.yTopSmall = 0;
		return r1;
	}
	recElement* ptr = head;
	ptr = ptr->next;
	r1.xButtomRight = head->Rect.xButtomRight;
	r1.xTopSmall = head->Rect.xTopSmall;
	r1.yButtomRight = head->Rect.yButtomRight;
	r1.yTopSmall = head->Rect.yTopSmall;
	while (ptr) {
		if (ptr->Rect.xButtomRight > r1.xButtomRight)
			r1.xButtomRight = ptr->Rect.xButtomRight;
		if (ptr->Rect.xTopSmall< r1.xTopSmall)
			r1.xTopSmall = ptr->Rect.xTopSmall;
		if (ptr->Rect.yButtomRight < r1.yButtomRight)
			r1.yButtomRight = ptr->Rect.yButtomRight;
		if (ptr->Rect.yTopSmall > r1.yTopSmall)
			r1.yTopSmall = ptr->Rect.yTopSmall;
		ptr = ptr->next;
	}
	return r1;
}
// --------------------------- //


/// <summary>
/// Function print rectangle cordinates on screen. (not drawing the rectangle!)
/// </summary>
/// <param>rectangle* rec - pointer to rectangle</param>
/// <returns>None</returns>
void printRectangle(rectangle* rec)
{
	// your code:
	printf("[(%d,%d)(%d,%d)]\n", rec->xTopSmall, rec->yTopSmall,rec->xButtomRight, rec->yButtomRight);
}
// --------------------------- //


/// <summary>
/// Function print list on screen.
/// </summary>
/// <param>recElement* head - list address</param>
/// <returns>None</returns>
void printList(recElement* head)
{
	// your code:
	recElement* ptr = head;
	while (ptr) {
		printRectangle(&(ptr->Rect));
		ptr = ptr->next;
	}
}
// --------------------------- //


/// <summary>
/// Function free alocated memory of list 
/// </summary>
/// <param>recElement* head - pointer to head of the list</param>
/// <returns>None</returns>
void freeList(recElement* head)
{
	// your code:
	recElement* curr = head;
	recElement* next = head->next;
	if (!next) free(head);
		
	while (next) {
		free(curr);
		curr = next;
		next = next->next;
	}
}
// --------------------------- //