#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define bool int
#define SIZE 5


struct Car
{
	char Registration[20];
	char make_model[20];
	char colour[15];
	int previous_owners;
	bool reserved;
	int reserveAmount;
	float ReservedDiscount; //Special FEATURE
};//

bool isValidRegistration(const char* Registration)
{

	for (int i = 0; i < 2; i++) // first 2 are valid years
	{
		if ((Registration[i] < '0' || Registration[i] > '9'))
		{
			return false;
		}
	}

	if (Registration[2] != 'D') // D for dublin
	{
		return false;
	}

	if (Registration[3] != '1' && Registration[3] != '2') // 4 car 1 or 2
	{
		return false;
	}

	for (int i = 4; i < 8; i++) // last 4 are digits 
	{
		if ((Registration[i] < '0' || Registration[i] > '9'))
		{
			return false;
		}
	}

	int year = atoi(Registration); //valid year of 14 - 24
	if (year < 14 || year > 24)
	{
		return false;
	}

	return true;

}

struct LinearNode //one node
{
	struct Car* element;
	struct LinearNode* link;
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


		carNode = (struct LinearNode*)malloc(sizeof(struct LinearNode));
		if (carNode == NULL)
		{
			printf("There's no space for new cars"); //this message appears when theres no space for new cars
		}

		anElement = (struct Car*)malloc(sizeof(struct Car));
		if (anElement == NULL)
		{
			printf("There's no space for new cars");
		}

		printf("Enter car registration by (yyDxnnnn)\n");
		scanf("%s", anElement->Registration); //add car by the registration number

		if (strlen(anElement->Registration) != 8) // reg string is 8 characters long
		{
			printf("This is an invalid registration, try again\n"); // if the registration is not this many characters long it will print out this message as the registration becomes invalid
		}
		printf("Enter the car make and model\n");
		scanf("%s", anElement->make_model); // make and model

		printf("Enter the car colour\n");
		scanf("%s", anElement->colour); // colour

		do {
			printf("Enter the number of previous owners (between 0-3)\n");
			scanf("%d", &anElement->previous_owners); // previous owners

			if (anElement->previous_owners < 0 || anElement->previous_owners > 3)
			{
				printf("This is a invalid number of previous owners\n");
				
			}// if the amount of previous oweners in the list car is under 0 or 3 the error message will occur
		} while (anElement->previous_owners < 0 || anElement->previous_owners > 3);

		
			printf("Is car reserved? 1 = Yes, 2 = No\n");
			scanf("%d", &ReservedOpt); //car is reserved or not

			do{
			if (ReservedOpt == 1) // if the option is 1 then the user will be allowed to reserve the car
			{
				anElement->reserveAmount = 0.0; // reserved amount is 0
				printf("Reserved amount\n");
				scanf("%d", &anElement->reserveAmount); //enters the reserved amount

				if (anElement->reserveAmount < 500.00 || anElement->reserveAmount >1500.0)
				{
					printf("This amount is invalid\n"); // this this message when the element is less than or greater than the amounts

				}
				else {
					printf("Thank you, this car is now reserved\n", anElement->Registration);
					anElement->reserved = true; // if the reserved car in the list is between 500/1500 it will be stored
				
				}
			}
		} while (ReservedOpt == 1 && (anElement->reserveAmount < 500.00 || anElement->reserveAmount > 1500.0));

		if (ReservedOpt == 2)
		{
			printf("This car is now stored! Thank you!\n", anElement->Registration); //stores the car as unreserved and sets the car boolean as false
			anElement->reserved = false;
			anElement->reserveAmount = 0.0;

		}

		carNode->element = anElement; // carnode and element = anElement
		carNode->link = NULL;
	
			if (front == NULL) // if front = null last will also mean the carnode
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

void sellCar() {
	char Registration[20];
	bool found = false; // set to false as we set it to true when the car is found

	struct LinearNode* current = front;
	struct LinearNode* previous = NULL;
	printf("Enter the registration number you wish to sell\n");
	scanf("%s", Registration); //enter the registration

	if (strlen(Registration) != 8) { // registration must be 8 characters long
		printf("This is an invalid registration, try again\n"); // if not invalid registration number
	}

	while (current != NULL) {
		if (strcmp(current->element->Registration, Registration) == 0) { // copies the registration
			found = true; //set to true when the car is found
			printf("The car has been found\n"); //prints this message
			if (current->element->reserved)
			{
				printf("The car with registration '%s' has been sold.\n", Registration);// the car the user inputted gets sold
				free(current->element);// frees memeory allocated to the car

				if (previous == NULL) {
					front = current->link;
				}
				else
				{
					previous->link = current->link;
				}
			}

				 if (current == last)
				{
					last = previous;

				}
				else
				{
				
					previous->link = current->link;
					free(current);
				}
		
			
		}
			current = current->link;
			previous = current;
		
	}

		if (!found)
			printf("The car with registration '%s' is not found in the list.\n", Registration);
			//if not found this message will pop up
	}


void reservedCar()//reserve or unreserve a car from the list
{
	char Registration[20];
	struct LinearNode* current = front;

	bool found = false;

	int option = 0;
	printf("1) Reserve a car\n");
	printf("2) Unreserve a car\n");
	printf("Wish what you like to choose\n");
	scanf("%d", &option); // asks the user to reserve or unreserve a car

	if (option == 1)
	{
		printf("Enter the Registration number of the car you wish to reserve\n");
		scanf("%s", Registration); // enter the registration

		while (current != NULL)
		{
			if (strcmp(current->element->Registration, Registration) == 0) //copies the registration that was entered in by the user
			{
				if (current->element->reserved)
				{
					printf("Car is already reserved\n"); // if the car is already reserved this messsage appears
				}
				else
				{
					printf("Enter deposit amount\n"); //if not the user will be asked to input
					scanf("%d", &current->element->reserveAmount); /// this car gets reserved with the amount 

					if (current->element->reserveAmount < 500.00 || current->element->reserveAmount >1500.0)
					{
						printf("This amount is invalid\n");// if the amount exceeds or is under the amount this message appears
					}
					else {
						current->element->reserved = true; // the car is set to true 
						printf("Thank you, this car is now reserved\n"); //returns true and the car is now reserved
					}
				}
				if(!found) // car not found it prints out this message
				printf("There is no car with this registration.\n");
	
			}
			current = current->link;
		}
		
	}

	if (option == 2) //option is 2
	{
		printf("Enter the registration number of the car you wish to unreserve\n");
		scanf("%s", Registration); //enter the registration

		while (current != NULL)
		{
			if (strcmp( current->element->Registration, Registration) == 0)
			{
				if (current->element->reserved)
				{
					current->element->reserved = false; //if the car reserved the car os now false
					printf("Car '%s' is now unreserved\n", Registration); // return false and the car becomes unreserved 
				}
				else {
					printf("This car is not reserved"); // the car is not reserved
				}
				
			}
			current = current->link;
		}
		if(!found)//if the car is not found prints this message
		printf("There is no car with this registration.\n");
	}
	
}

void viewAllCars()
{
	struct LinearNode* current;

	current = front;
	while (current != NULL)
	{
		printf("Registration %8s\n", current->element->Registration);
		printf("Make and Model %s\n", current->element->make_model);
		printf("Colour %s\n", current->element->colour);
		printf("Previous Owners %d\n", current->element->previous_owners);
		printf("Is the car reserved? 1 = Yes, 0 = No %d\n", current->element->reserved);
		printf("Car reserved amount %d\n", current->element->reserveAmount);
		printf("\n");
		current = current->link;
	}// method to view all cars in the list 
	if (isEmpty())
	{
		printf("There is no cars.\n"); // if empty returns this
	}

}

void viewSpecificCar()
{
	char Registration[20];
	struct LinearNode* current;
	current = front;
	bool found = false;

	printf("Enter the Regisitration number of the car you want to view\n");
	scanf("%s", Registration);// asking the user to input the registration
	

	while (current != NULL)
	{
		printf("Checking car with registratiom %s\n", current->element->Registration);

		if (strcmp(current->element->Registration, Registration) == 0) {

			printf("A Car is found\n");
			found = true;

			printf("Registration %8s\n", current->element->Registration);
			printf("Make and Model %s\n", current->element->make_model);
			printf("Colour %s\n", current->element->colour);
			printf("Previous Owners %d\n", current->element->previous_owners);
			printf("Is the car reserved? 1 = Yes 0 = No  = %d\n", current->element->reserved);
			printf("Car reserved amount %d\n", current->element->reserveAmount);
			printf("\n");
			// if the registration of the car is found it displays that cars detail
			current = current->link;
		}

		if (isEmpty())
		{
			printf("There is no cars in this list.\n");
			
		}
	}
}


void ReservedDiscount()

{ //  speical feature is that the car reserved gets a 10% discount on the already reserved amount they had on,
	char Registration[20];
	struct LinearNode* current = front;
	bool found = false;
	float ReservedDiscount = 0.90;

	printf("Enter the Registration of the reserved car you want to apply a discount for\n");
	scanf("%s", Registration); //enters the registration of the car 

	while (current != NULL)
	{
		if (strcmp(current->element->Registration, Registration) == 0)
		{
			found = true;
			printf("Checking car with registation %s in the list\n", Registration);
			if (current->element->reserved)
			{
				// the car gets a 10% discount on their reserved car when they enter in the registation number
				current->element->reserveAmount *= ReservedDiscount;

				printf("A 10 Percent discount was applied to the reserved amoint for car with registration '%s'.\n New reserved amount is %d\n", Registration, current->element->reserveAmount);

			}
			else 
			{
				printf("Car with the registration '%s' is not reserved.\n", Registration);
			}
		}
		current = current->link;
	}
	if (!found)
	{
		printf("There is no cars with this registration\n");
	}

	if (isEmpty()) // if the list is empty this message will appear
	{
		printf("There is no cars in the list\n");
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
	fptr = fopen("car.dat", "wb");

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
			fread(current->element, sizeof(struct Car), 1, fptr);
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

}
	
