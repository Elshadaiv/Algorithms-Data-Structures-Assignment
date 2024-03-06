
#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#define SIZE 5
#include <stdio.h>
#include <stdlib.h>
#include <cstddef>4

#struct Car
{
	char Registration[20];
	char make_model[20];
	char colour[15];
	int previous_owners;
	bool reserved;
	double reserveAmount;
	float sale; //Special FEATURE
};

struct LinearNode 
{
	struct Data *element;
	struct LinearNode *next;
};

struct LinearNode* front = NULL;
struct LinearNode* last = NULL;
 


// calling all my methods which are needed for thr question
void addCar() 
{

}

void sellCar()
{

}

void reserveCar()
{

}

void unreserveCar()
{

}

void viewAllCars()
{

}

void viewSpecificCar()
{

}

void exit()
{
		printf("Thank you!");
		return 0;
}

int main()
{
	int option = 0;

	while (1)
	{
		printf("1) Add a new car to the showroom\n");
		printf("2) Sell a car from the showroom\n");
		printf("3) Reserve a car in the showroom\n");
		printf("4)  Unreserve a car in the showroom\n");
		printf("5) View all cars in the showroom\n");
		printf("6) View a specific car in the showroom\n");
		printf("7) ShowRoom Sale\n"); //Special Feature
		printf("8) Exit\n");
		printf("Which will you like to choose: ");

		scanf("%d", &option);

		switch (option)
		{
		case 1:
			addCar();
			break;

		case 2:
			sellCar();
			break;

		case 3:
			reserveCar();
			break;

		case 4:
			unreserveCar();
			break;

		case 5:
			viewAllCars();
			break;

		case 6:
			viewSpecificCar();
			break;

		case 7:
			SP();
			break;

		case 8:
			exit();
			break;
		}
		
	}
}
	

	
