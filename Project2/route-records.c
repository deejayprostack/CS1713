#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "route-records.h"

RouteRecord* createRecords (FILE* fileIn){
int recordCount = 0; //To count the records in the CSV
char buffer[500]; //Buffer for fgets()
RouteRecord* records = NULL; //Initialize as null

//Count number of records till it hits EOF
while(fgets(buffer, 500, fileIn) != NULL)
{
    recordCount++; //Counts each row/record
}

//Dynamically allocate memory through malloc based on the count
records = (RouteRecord*) malloc(sizeof(RouteRecord) * recordCount);

//Iniitialize each of the integers from each RouteRecord Struct object of passengers to 0;
for(int i = 0; i < recordCount; i++)
{
    for(int j = 0; j < 0; j++) 
    {
        records[i].passengerCnt[j] = 0;
    }
}

//Rewinding
rewind(fileIn);
return records;
}

int fillRecords( RouteRecord* r, FILE* fileIn){
    int numRecordsUsed = 0; //To count records for return
    char line[256]; //Buffer from fgets()

    //skip the first line of CSV
    fgets(line, sizeof(line), fileIn);

    // Read and process each line in the CSV
    while(fgets(line, sizeof(line), fileIn) != NULL)
    {
        char origin[4], destination[4], airline[3];
        int month, passengers;


        sscanf(line,"%d,%[^,],%[^,],%[^,],%*[^,],%d", &month, origin, destination, airline, &passengers);
        //findAirLineRoute returns a -1 if it cannot find three strings with the same struct object.
        int index = findAirlineRoute(r, numRecordsUsed, origin, destination, airline,0);

        if (index != -1) {
                r[index].passengerCnt[month - 1] = passengers;  // Not Repeated
        }else {
                strcpy(r[numRecordsUsed].airportOrigin, origin);
                strcpy(r[numRecordsUsed].airportDesti, destination);
                strcpy(r[numRecordsUsed].airlineCode, airline);
                r[numRecordsUsed].passengerCnt[month - 1] = passengers;  // Repeated, add to existing
                numRecordsUsed++;
            }
    }
    return numRecordsUsed;
}

int findAirlineRoute( RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx){
    if(curIdx >=length)
    {
     return -1; //Didn't find a match.
    }
    //Checking all three strings in the same struct object
    if (strcmp(r[curIdx].airportOrigin, origin) == 0 && 
        strcmp(r[curIdx].airportDesti, destination) == 0 &&
        strcmp(r[curIdx].airlineCode, airline) == 0) 
    {
        return curIdx;  // Found
    }

    //Recursively search next record
    return findAirlineRoute(r, length, origin, destination, airline, curIdx + 1);
    
}

void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2, SearchType st) {
    int totalPassengers = 0;
    int totalPassengersByMonth[6] = {0};
    int matchingCount = 0;

    for (int i = 0; i < length; i++) {
        int match = 0;
//According to Searchtype it traverses the array and commpares specific data members against the keys.
        switch (st) {
            case ROUTE:
                if (strcmp(r[i].airportOrigin, key1) == 0 && strcmp(r[i].airportDesti, key2) == 0) {
                    match = 1;
                }
                break;
            case ORIGIN:
                if (strcmp(r[i].airportOrigin, key1) == 0) {
                    match = 1;
                }
                break;
            case DESTINATION:
                if (strcmp(r[i].airportDesti, key1) == 0) {
                    match = 1;
                }
                break;
            case AIRLINE:
                if (strcmp(r[i].airlineCode, key1) == 0) {
                    match = 1;
                }
                break;
        }

        if (match) {
            matchingCount++;
            //totalPassengers += r[i].passengerCnt[0];
            for (int j = 0; j < 6; j++) {
                totalPassengersByMonth[j] += r[i].passengerCnt[j];
                totalPassengers += r[i].passengerCnt[j];
            }
        }
    }

    if (matchingCount > 0) {
        printf("\nSearching by route...\n");
        for (int i = 0; i < length; i++) {
            int match = 0;
            switch (st) {
                case ROUTE:
                    if (strcmp(r[i].airportOrigin, key1) == 0 && strcmp(r[i].airportDesti, key2) == 0) {
                        match = 1;
                    }
                    break;
                case ORIGIN:
                    if (strcmp(r[i].airportOrigin, key1) == 0) {
                        match = 1;
                    }
                    break;
                case DESTINATION:
                    if (strcmp(r[i].airportDesti, key1) == 0) {
                        match = 1;
                    }
                    break;
                case AIRLINE:
                    if (strcmp(r[i].airlineCode, key1) == 0) {
                        match = 1;
                    }
                    break;
            }

            if (match) {
                printf("%s (%s-%s) ", r[i].airlineCode, r[i].airportOrigin, r[i].airportDesti);
            }
        }
        printf("\n%d matches were found.\n\n",matchingCount);

        printf("Statistics\n");
        printf("Total passengers: %d\n", totalPassengers);
        //printf("Total passengers by month: ");
        for (int i = 0; i < 6; i++) {
            printf("Total Passengers in Month %d: ",i + 1);
            printf("%d \n", totalPassengersByMonth[i]);
        }
        printf("\n");
        printf("Average passengers per month: ");
        printf("%d ", totalPassengers / 6);
        printf("\n");
    } else {
        printf("No matching records found.\n"); //If search has 0 results
    }
}

void printMenu() 
{
    printf( "\n\n######### Airline Route Records Database MENU #########\n" );
    printf( "1. Search by Route\n" );
    printf( "2. Search by Origin Airport\n" );
    printf( "3. Search by Destination Airport\n" );
    printf( "4. Search by Airline\n" );
    printf( "5. Quit\n" );
    printf( "Enter your selection: " );
}

