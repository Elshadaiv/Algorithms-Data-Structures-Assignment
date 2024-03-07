
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
	struct Car* element;
	struct LinearNode *link;
}; // ive made a change to this and below made the errors go away but need to find a better soloution


struct LinearNode* last = NULL;
 

void addCar() 
{
int i;
	struct LinearNode *carNode;
	struct Car *anElement;

	  anElement = (struct Car *)malloc(sizeof(struct Car));
	  carNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));
	// this is making car have to -> element to the car model, car reg etc


	for(i=0; i< SIZE; i++)
{
	printf("Enter car registration by (yyDxnnnn)");
	scanf("%9s", carNode ->element->Registration);


	if(!isValidRegistration(carNode ->Redistration))
	{
		printf("Invalid Registration");
		return;
	}

	printf("Enter the car make and model");
	scanf("%s", carNode ->element->make_model);


	printf("Enter the car colour");
	scanf("%s", carNode->element->colour);


	printf("Enter the number of previous owners (between 0-3)");
	scanf("%d", &carNode ->element->previous_owners);

	if(carNode ->element-> previous_owners < 0 || carNode -> element->previous_owners > 3)
	{
		printf("This is a invalid number of previous owners");
		return;
	}

	printf("Is car reserved?");
	scanf("%d", carNode ->element-> reserved);

//add boolean indicator

	carNode ->element->reserveAmount = 0.0;

	if(carNode ->element->reserved)
{
	printf("Reserbed amount");
	scanf("%d", &carNode->element->reserveAmount);

	if(carNode ->element->reserveAmount < 500.00 || carNode ->element->reserveAmount >1500.0)
	{
		printf("This amount is invalid");
		return;
	}

if(carNode ->element->reserveAmount < 500.00 || carNode ->element->reserveAmount >1500.0)
	{
		printf("This amount is invalid");
		return;
	}
}

	if(carNode == NULL)
	{
	printf("There's no space for new cars");
	}
	else 
{
		carNode->link = NULL;
		 	carNode->element = anElement;
	
			if (isEmpty())  
			{
				front = carNode;
				last = carNode;
		    }
			else
			 {
				carNode->link = front;
				front = carNode;

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
	struct LinearNode *current;

	printf("1) View all Cars/n");
	printf("2) View car with specific type")
}

void viewSpecificCar()
{

}

void exit()
{
		printf("Thank you!");

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
	

	
