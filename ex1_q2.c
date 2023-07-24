// Course: Advanced C programming
// exercise 1, question 2
// file name: ex1_q2.c
#define _CRT_SECURE_NO_WARNINGS
// --------------------------- //
// include package section:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// --------------------------- //
//
//	Assigned by:
//		Student1_Full_Name Bar Brener #ID 207703026
//		Student2_Full_Name Yaakov Israeli #ID 208196816
//
// --------------------------- //

// structs and function declarations section:
typedef struct point
{
	int x, y;
}point;

typedef struct polygon
{
	int n;
	point* points;
	double scope;
}polygon;

void scanPoint(point* p);
polygon* createPolygon();
double distance(point* p1, point* p2);
double calculateScope(point* points, int n);
int addPoint(polygon* poly);
int removePoint(polygon* poly, int idx);
void freeMemory(polygon* poly);

// --------------------------- //

int main()
{
	int i, n, idx;
	polygon *poly;

	// Start Program:
	printf("Start Program\n");

	// call functions:
	poly = createPolygon();
	printf("How many points to add: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Point #%d: \n", i + 1);
		addPoint(poly);
	}

	printf("Enter index value to remove, invalid index to stop: ");	
	do
	{
		scanf("%d", &idx);
	} while (removePoint(poly, idx));
	
	// write output:
	printf("Output: Scope of polygon: %.2lf\n", poly->scope);
	freeMemory(poly);

	return 0;
}
// --------------------------- //


/// <summary>
/// Function scan a point in the plane,
/// Used as auxiliary function for createPolygon.
/// </summary>
/// <param>point* p - pointer to p</param>
/// <returns>None</returns>
void scanPoint(point* p)
{
	// your code:
	printf("please enter point first x then y\n");
	scanf("%d", &p->x);
	scanf("%d", &p->y);

}
// --------------------------- //


/// <summary>
/// Function allocate an empty polygon.
/// </summary>
/// <returns>New allocated polygon</returns>
polygon* createPolygon()
{
	// your code:
	polygon* newPolygon = (polygon*)malloc(sizeof(polygon));
	newPolygon->n = 0;
	newPolygon->points = NULL;
	newPolygon->scope = 0;

	
}
// --------------------------- //


/// <summary>
/// Function calculates distance between 2 adjacent points  
/// </summary>
/// <param>point* p1 - pointer to the first point</param>
/// <param>point* p2 - pointer to the second point</param>
/// <returns>The Euclidean distance between p1 and p2</returns>
double distance(point* p1, point* p2)
{
	// your code:
	double distance = sqrt(((p1->x - p2->x) * (p1->x - p2->x)) + ((p1->y - p2->y) * (p1->y - p2->y)));
	return distance;
}
// --------------------------- //


/// <summary>
/// Function calculates and returns the Scope of a polygon.
/// </summary>
/// <param>point* points - array of points</param>
/// <param>int n - size of the array</param>
/// <returns>The Scope of a polygon</returns>
double calculateScope(point* points, int n)
{
	// your code:
	int i;
	double scope = 0;
	for (i = 0; i < n-1; i++) {
		scope+=distance(points + i, points + i + 1);
	}
	if (n > 2) {
		scope += distance(points, points + i);
	}
	return scope;
}
// --------------------------- //


/// <summary>
/// Function add a new point at the end of the polygon,
/// and update the scope falue.
/// </summary>
/// <param>polygon* poly - pointer to polygon</param>
/// <returns>1- success, 0- failure</returns>
int addPoint(polygon* poly)
{
	// your code:
	point* address_p = poly->points;
	int size = poly->n;
	address_p = (point*)realloc(address_p, (size + 1) * sizeof(point));
	if (!address_p) return 0;
	poly->points = address_p;
	poly->n = size + 1;
	point p1;
	scanPoint(&p1);
	address_p[size] = p1;
	poly->scope=calculateScope(address_p, size + 1);
	return 1;

}
// --------------------------- //


/// <summary>
/// Function remove a point from the polygon,
/// at spesific index.
/// </summary>
/// <param>polygon* poly - pointer to polygon</param>
/// <param>int idx - the index to remove</param>
/// <returns>1- success, 0- failure</returns>
int removePoint(polygon* poly, int idx)
{
	// your code:
	int i;
	if (idx + 1 > poly->n || idx < 0) return 0;
	for (i = idx; i < poly->n-1; i++) {
		poly->points[i] = poly->points[i + 1];
	}
	poly->n = poly->n - 1;
	point* address_p = poly->points;
	address_p = (point*)realloc(address_p, poly->n * sizeof(point));
	if(!address_p) return 0;
	poly->points = address_p;
	poly->scope = calculateScope(address_p, poly->n);
	return 1;


}
// --------------------------- //


/// <summary>
/// Function free alocated memory. 
/// </summary>
/// <param>polygon* poly - pointer to polygon</param>
/// <returns>None</returns>
void freeMemory(polygon* poly)
{
	// your code:
	free(poly);
	
}
// --------------------------- //