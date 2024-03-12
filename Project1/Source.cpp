
#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#define SIZE 5
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define false 0 // Why do i have to add this so the errors on the return statement are not mark as erros?

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

bool isValidRegistration (const char*Registration)
{
	
	if(strlen(Registration)!=8) // reg string is 8 characters long
	{
	return false;
	}
	
	for(int i = 0; i< 2; i++) // first 2 are valid years
	{
		if((Registration[i] < '0' || Registration[i] > '9'))
		{
			return false;
		}
	}

	if(Registration[2] != 'D') // D for dublin
	{
		return false;
	}

	if(Registration[3] != '1' && Registration[3] !='2') // 4 car 1 or 2
	{
		return false;
	}

	for(int i = 4; i < 8; i++) // last 4 are digits 
	{
		if((Registration[i] <'0' || Registration[i] > '9'))
		{
			return false;
		}
	}

	int year = atoi(Registration); //valid year of 14 - 24
	if(year <14 || year > 24)
	{
		return false;
	}

return true;


struct LinearNode
{
	struct Car* element;
	struct LinearNode *link;
};


struct LinearNode* front = NULL;
struct LinearNode* last = NULL;

bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}
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
	scanf("%8s", carNode ->element->Registration);


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
struct LinearNode*current;
		current = front;
			struct LinearNode*previous = NULL;

			if(current->element->reserved)
			{
			front = current->link;
					free(current);
			}
			
			else if (current == last){
					last = previous;
					last->link=NULL;
					free(current);
				}
				else { 
						previous->link= current->link;
						free(current);
	}
}

void reserveCar()
{

}

void unreserveCar()
{

}

void viewAllCars()
{
	struct LinearNode*current;

	current = front;
	while(current !=NULL)
	{
		("Registration %s, Make and Model %s, Colour %s, Previous Owners %d",  current->element->Registration, current->element->make_model, current->element->colour, current->element->previous_owners);
		current = current->link;
	}
	if (isEmpty())
	{
		printf("There is no cars.\n");
	}
}

void viewSpecificCar()
{

}

void exit()
{
		printf("Thank you!");

}

void SP()
	{

	}

int main()
{
	int option = 0;

	while (1)
	{printf("1) Add a new car to the showroom\n");
		printf("2) Sell a car from the showroom\n");
		printf("3) Reserved/Unreserved a car in the showroom\n");
		printf("4) View all cars in the showroom\n");
		printf("5) View a specific car in the showroom\n");
		printf("6) ShowRoom Sale\n"); //Special Feature
		printf("7) Exit\n");
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
			reserved();
			break;

		case 4:
			viewAllCars();
			break;

		case 5:
			viewSpecificCar();
			break;

		case 6:
			SP();
			break;

		case 7:
			exit();
			break;
		}
		
	}
}
	

	
