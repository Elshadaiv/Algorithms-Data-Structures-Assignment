
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
	


	for(i=0; i< SIZE; i++)
{
	printf("Enter car registration by (yyDxnnnn)");
	scanf("%8s", &anElement->Registration);

if(strlen(anElement->Registration)!=8) // reg string is 8 characters long
	{
		printf("This is an invalid registration, try again");
		free(anElement);
		free(carNode);
	return false;

	printf("Enter the car make and model");
	scanf("%s",&anElement->make_model);


	printf("Enter the car colour");
	scanf("%s", anElement->colour);

	do{
	printf("Enter the number of previous owners (between 0-3)\n");
	scanf("%d", &anElement->previous_owners); // previous owners

	if(anElement-> previous_owners < 0 || anElement->previous_owners > 3)
	{
		printf("This is a invalid number of previous owners\n");
		return;
	}// if the amount of previous oweners in the list car is under 0 or 3 the error message will occur
}while(anElement-> previous_owners < 0 || anElement->previous_owners > 3);

do{
	printf("Is car reserved? 1 = Yes, 2 = No\n");
	scanf("%d",&ReservedOpt);

	if(ReservedOpt== 1)
	{
	printf("Reserved amount\n");
	scanf("%d", &anElement->reserveAmount);
	
	if(anElement->reserveAmount < 500.00 || anElement->reserveAmount >1500.0)
	{
		printf("This amount is invalid\n");
		
	}
	else {
		printf("Thank you, this car is now reserved\n");
	}
	}
}while (anElement->reserved == 1 && (anElement->reserveAmount < 500.00 || anElement->reserveAmount > 1500.0));

	if(ReservedOpt== 2)
	{
		printf("This car is now stored! Thank you!\n");
		return;
	}
}
 // if the reserved car in the list is between 500/1500 i will be stored


	if(anElement == NULL)
	{
	printf("There's no space for new cars");
	}
	else 
{
		 	carNode->element = anElement;
			carNode->link = NULL;
	
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
	char* Registration;
		struct LinearNode*current;
		current = front;
		struct LinearNode* previous = NULL;	
		
		printf("Enter the Registration number you wish to sell");
		scanf("%9s", Registration);

		while(current != NULL)
		{
			if(strcmp(current ->element-> Registration, Registration) == 0)
			{
			if(previous == NULL)
			{
				front = current ->link;
			}
			else {
				previous ->link = current ->link;
			}

				printf("Car reg '%s' sold.\n", &Registration);
				free(current->element);
				free(current);
				return;
			}
			else 
			{
				printf("Car reg '%s' is not reserved and will not be sold\n", &Registration);
				return;
			}
		}
		previous = current;
        current = current->link;


	if(strlen(Registration)!=8) // reg string is 8 characters long
	{
		printf("This is an invalid registration, try again\n");
	return;
	}
}
	



void reserveCar()
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
		// special feature
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
	

	
