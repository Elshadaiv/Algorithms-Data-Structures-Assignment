#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define false 0 // Why do i have to add this so the errors on the return statement are not mark as erros?
#define bool int
#define SIZE 5


struct Car
{
	char Registration[8];
	char make_model[20];
	char colour[15];
	int previous_owners;
	bool reserved;
	int reserveAmount;
	float discountAmount; //Special FEATURE
};//

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

}

struct LinearNode //one node
{
	struct Car* element;
	struct LinearNode *link;
};


struct LinearNode* front = NULL; //front of the list
struct LinearNode* last = NULL;

bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false; // boolean method to check if list is empty
}

void addCar() // add car method
{
	int i;
	int ReservedOpt = 0;
	struct LinearNode* carNode;
	struct Car* anElement;


	for (i = 0; i < SIZE; i++) // 5 cars get added into list
	{

	struct LinearNode* carNode = (struct LinearNode*)malloc(sizeof(struct LinearNode));
	if (carNode == NULL)
	{
		printf("There's no space for new cars");
		return;
	}

	struct Car* anElement = (struct Car*)malloc(sizeof(struct Car));
	if (anElement == NULL)
	{
		printf("There's no space for new cars");
		free(carNode);
		return;
	}

	printf("Enter car registration by (yyDxnnnn)\n");
	scanf(" %8s", anElement->Registration); //add car by the reg
	anElement->Registration[8] = '\0';

	if (strlen(anElement->Registration) != 8) // reg string is 8 characters long
	{
		printf("This is an invalid registration, try again\n");
		free(anElement);
		free(carNode);
		return;;
	}
		printf("Enter the car make and model\n");
		scanf("%s", &anElement->make_model); // make and model


		printf("Enter the car colour\n");
		scanf("%s", &anElement->colour); // colour

		do {
			printf("Enter the number of previous owners (between 0-3)\n");
			scanf("%d", &anElement->previous_owners); // previous owners

			if (anElement->previous_owners < 0 || anElement->previous_owners > 3)
			{
				printf("This is a invalid number of previous owners\n");
				return;
			}// if the amount of previous oweners in the list car is under 0 or 3 the error message will occur
		} while (anElement->previous_owners < 0 || anElement->previous_owners > 3);

		do {
			printf("Is car reserved? 1 = Yes, 2 = No\n");
			scanf("%d", &ReservedOpt);

			if (ReservedOpt == 1)
			{
				anElement->reserveAmount = 0.0; // reserved amount is 0
				printf("Reserved amount\n");
				scanf("%d", &anElement->reserveAmount);

				if (anElement->reserveAmount < 500.00 || anElement->reserveAmount >1500.0)
				{
					printf("This amount is invalid\n");

				}
				else {
					printf("Thank you, this car is now reserved\n");
					anElement->reserved = true;// if the reserved car in the list is between 500/1500 i will be stored


				}
			}
		} while (ReservedOpt == 1 && (anElement->reserveAmount < 500.00 || anElement->reserveAmount > 1500.0));

		if (ReservedOpt == 2)
		{
			printf("This car is now stored! Thank you!\n");
			anElement->reserved = false;

			return;
		}
		carNode->element = anElement;
		carNode->link = NULL;

		
		if (carNode == NULL)
		{
			printf("There's no space for new cars");
		} // null = no space for car
		else {

			if (front == NULL)
			{
				front = carNode;
				last = carNode;
			}
			else
			{
				last->link = carNode;
				last = carNode;

			}
		}
	}



void sellCar()
{
	char Registration[9];
	struct LinearNode* current = front;
	struct LinearNode* previous = NULL;

	printf("Enter the Registration number you wish to sell\n");
	scanf("%9s", Registration); //the user enters the reg number

	while (current != NULL) // while the current node is not null this command happens
	{
		if (strcmp(current->element->Registration, Registration) == 0)
		{
			if (previous == NULL)
			{
				front = current->link;
				rintf("Theres no car in the list to sell"); // previous is node this message appears 
					return;
			}
			else {
				previous->link = current->link;
			}

			printf("Car reg '%s' sold.\n", Registration); // car sells with this registration and the previous node becomes the current node and links to the link node
			free(current->element);
			free(current);
			return;
			previous = current;
			current = current->link;
		}
		else
		{
			printf("Car reg '%s' is not reserved and will not be sold\n", Registration);
			return;
		}
	
	}
	

	if (strlen(Registration) != 8) // reg string is 8 characters long
	{
		printf("This is an invalid registration, try again\n");
		return;
	}
}
	


void reservedCar()
{	
		char Registration[9];
	struct LinearNode* carNode = front;

	int option = 0;
	printf("1) Reserve a car\n");
	printf("2) Unreserve a car\n");
	printf("Wish what you like to choose\n");
	scanf("%d", &option); // asks the user to reserve or unreserve a car

	if (option == 1)
	{
		printf("Enter the Registration number of the car you wish to reserve\n");
		scanf("%8s", Registration); // enter the registration

		while (carNode != NULL)
		{
			if (strcmp(carNode->element->Registration, Registration) == 0)
			{
				if (carNode->element->reserved)
				{
					printf("Car is already reserved\n");
				}
				else
				{
					printf("Enter deposit amount\n");
					scanf("%f", &carNode->element->reserveAmount); /// this car gets reserved with the amount 

					if (carNode->element->reserveAmount < 500.00 || carNode->element->reserveAmount >1500.0)
					{
						printf("This amount is invalid\n");
					}
					else {
						carNode->element->reserved = true;
						printf("Thank you, this car is now reserved\n"); //returns true and the car is now reserved
					}
				}
				return;
			}
			carNode = carNode->link;
		}
		printf("There is no car with this registration.\n");
	}

	if (option == 2)
	{
		printf("Enter the registration number of the car you wish to unreserve\n");
		scanf("%8s", Registration);

		while (carNode != NULL)
		{
			if (strcmp(carNode->element->Registration, Registration) == 0)
			{
				if (carNode->element->reserved)
				{
					carNode->element->reserved = false;
					printf("Car '%s' is now unreserved\n", Registration); // return false and the car becomes unreserved 
				}
				else {
					printf("This car is not reserved");
				}
				return;
			}
			carNode = carNode->link;
		}
		printf("There is no car with this registration.\n");
	}
}

void viewAllCars()
{
	struct LinearNode*current;

	current = front;
	while(current !=NULL)
	{
		printf("Registration %8s\n", current->element->Registration);
        printf("Make and Model %s\n", current->element->make_model);
        printf("Colour %s\n", current->element->colour);
        printf("Previous Owners %d\n", current->element->previous_owners);
        printf("\n");
		return;
		current = current->link; 
	}// method to view all cars in the list 
	if (isEmpty())
	{
		printf("There is no cars.\n"); // if empty returns this
	}

}

void viewSpecificCar()
{
	char Registration[9];
	struct LinearNode* current = front;

	printf("Enter the Regisitration number of the car you want to view\n");
	scanf("%8s", Registration); 

		while (current != NULL)
		{
			printf("Checking car with registratiom %8s\n", current->element->Registration); 

			if (strcmp(current->element->Registration, Registration) == 0) {

			printf("A Car is found\n");

			printf("Registration %8s\n", current->element->Registration);
			printf("Make and Model %s\n", current->element->make_model);
			printf("Colour %s\n", current->element->colour);
			printf("Previous Owners %d\n", current->element->previous_owners);
			printf("Reserved %s\n", current->element->reserved);
			printf("Reserved Amount %d\n", current->element->reserveAmount);
			return;
			// if the registration of the car is found it displays that cars detail
			current = current->link;
		}

		if (isEmpty())
		{
			printf("There is no cars with this registration.\n");
			return;
		}
	}
}


void ReservedDiscount()
	void ReservedDiscount()
{ //  speical feature is that the car reserved gets a 10% discount on the already reserved amount they had on,
	char Registration[9];
	struct LinearNode* current = front;
	int found = 0;

	printf("Enter the Registration of the reserved car you want to apply a discount for\n");
	scanf("%8s", Registration);

	if (isEmpty())
	{
		printf("There is no cars with this registration.\n");
		return;
	}

	while (current != NULL)
	{
		if (strcmp(current->element->Registration, Registration) == 0)
		{
			found = 1;
			if (current->element->reserved)
			{
				current->element->reserveAmount *= 0.90;

				printf("A 10 Percent discount was applied to the reserved amoint for car with registration '%s'.\n New reserved amount is %.2f\n", Registration, current->element->reserveAmount);
				return;

			}
			else
			{
				printf("Car with the registration '%s' is not reserved.\n", Registration);
				return;
			}
		}
		current = current->link;


	}
	if (!found)
	{
		printf("There is no cars with this registration\n");
	}
}

void exit() // exit method
{
	printf("Thank you!");
	exit(0);
}

int main()
{

//File handling method
FILE* fptr;
fptr = fopen("car.dat", "rb");

if (fptr == NULL)
{
	printf("The File 'car.dat' does not exist, you'll need to input cars to the list\n");
	
}

else
{
	printf("The file 'car.dat' does exist.\n");
	struct LinearNode* current = front;
	while (current != NULL)
	{
		fwrite(current->element, sizeof(struct Car), 1, fptr);
		current = current->link;
	}

	printf("Cars are loaded\n");
	fclose(fptr);
}
	


    	int option = 0;

	while (1)
	{
		printf("1) Add a new car to the showroom\n");
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
			reservedCar();
			break;

		case 4:
			viewAllCars();
			break;

		case 5:
			viewSpecificCar();
			break;

		case 6:
			ReservedDiscount();//Speical Feature
			break;

		case 7:
			exit();
			break;
		}

	}

}
	
