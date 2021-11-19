
#include <stdio.h>

#define NUMCARS 3

typedef struct {
	char first[50];
	char last[50];
	double weight;
}Person;

typedef struct {
	char make[50];
	char model[50];
	double weight;
	int numPeople;
	Person people[10];
}CarInfo;

//Function prototypes
void readCarInfo(CarInfo* c); //Prompt user for car info and read it in
void readPassengerInfo(Person* p); //Prompt user for info on a single person
double getTotalCarWeight(CarInfo* c); //Returns the weight of the car + the weight of all passengers
void printPassengerList(CarInfo* c); //Prints a list of all passengers in a car


int main() {

   //Defining loop index and list of cars
	int i;	
	CarInfo cars[NUMCARS]; 

   //Reading list of cars
	for (i = 0; i < NUMCARS; i++)
	{
		printf("\nNow reading info for car #%d...\n", i);
		/**Call readCarInfo function here*/
		readCarInfo(&(cars[i]));
	}

   //Printing list of cars and the total/raw weight of each
	for (i = 0; i < NUMCARS; i++)
	{
		/**Uncomment and complete the following line with the make and model of the car*/
		printf("\n\nCar #%d (%s %s) info:\n", i, cars[i].make, cars[i].model);
		printf("Passengers:\n");
		
		/**Call printPassengerList function here */
		printPassengerList(&(cars[i]));

      /**Uncomment and complete the following two lines*/
		printf("\nCar #%d total weight (with passengers) is %.2lf lbs.\n",i,  getTotalCarWeight(&(cars[i])));
		printf("Car #%d raw weight is %.2lf lbs.\n", i, cars[i].weight);
	}
	
	return 0;
}

void readCarInfo(CarInfo* c)
{
   //This function requests and reads the info on a single car from the user
	int i;

   /**Uncomment and complete the following scanf() lines*/
	printf("Enter car make: ");
	scanf("%s", (*c).make);

	printf("Enter car model: ");	
	scanf("%s", (*c).model);

	printf("Enter car weight: ");
	scanf("%lf", &(*c).weight);

	printf("How many passengers? ");
	scanf("%d", &(*c).numPeople);

   /**Uncomment and complete the loop condition to loop through all the people in the car*/
	for (i = 0;  i < (*c).numPeople; i++) {
		printf("For passenger #%d...\n", i);
		/**Call readPassengerInfo here*/
		readPassengerInfo(&((*c).people[i]));
	}

}

void readPassengerInfo(Person* p)
{
   //This function prompts for and reads information on a single person from the user
	
	
	/**Uncomment and fill scanf statements to read in the passenger info. You may assume the names have no whitespace*/
	printf("Enter first name: ");
	scanf("%s", (*p).first);

	printf("Enter last name: ");
	scanf("%s", (*p).last);

	printf("Enter weight: ");
	scanf("%lf", &(*p).weight);

}

double getTotalCarWeight(CarInfo* c)
{
   //This function returns the weight of a single car plus the weight of all people in the car 
   //Note that it should NOT modify the weight of the car itself, but should merely return the total
	
	double totW;
	int i;

   /**Add the car's weight to the total */
   totW = (*c).weight;
	
	/*Uncomment the loop condition and complete to loop through all the people*/
	for (i = 0; i < (*c).numPeople; i++) {
	   /**Sum each passenger's weight here*/
	   totW += (*c).people[i].weight;
	}
	return totW;
}

void printPassengerList(CarInfo* c)
{
   //This function lists the name and weight of all passengers in a single car
	int i;

	/**Uncomment the loop condition and complete to loop through all the people*/
	for (i = 0; i < (*c).numPeople; i++) {
		/**Uncomment and complete the following printf statement with the first name, last name, and weight*/
		printf("Passenger #%d: %s %s, %.2lf lbs.\n", i, (*c).people[i].first, (*c).people[i].last, (*c).people[i].weight);
	}
}
