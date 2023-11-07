#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "route-records.h"

int main( int argc, char *argv[] )
{
    
    /* 1. Declare variables here */
    FILE *fileIn = NULL;
    RouteRecord *records = NULL;
    int recordCount = 0;

    /* 2. Check command line arguments here. If a command line argument (for the file name) is missing, print out the following: ERROR: Missing file name and end the program */
        // Check command line arguments
    if (argc != 2) {
        printf("ERROR: Missing file name\n");
        return 1;
    }

    /* 3. Attempt to open the file. Print out Opening <filename>... before you call fopen(). */
    printf("Opening %s...\n", argv[1]);
    fileIn = fopen(argv[1], "r");

    /* 4. Check to see if the file opens. If it does not open, print out ERROR: Could not open file and end the program. */
   if (fileIn == NULL) {
        printf("ERROR: Could not open file\n");
        return 1;
    }
    
    /* 5. Do the following to load the records into an array of RouteRecords
    	
    		5.1 Call createRecords(), which will read through the file once to find the total number of lines/records in the file. Use this count, to dynamically allocate memory for an array of RouteRecords. It returns a pointer to that array. Don't forget to rewind the file pointer. */
    rewind(fileIn);
    records = createRecords(fileIn);
    		//5.2 Call fillRecords() to go through the CSV file again to fill in the values. It will then return the actual number of items the array has. Recall that not all records in the original CSV file will be entered into the array. Print the number of unique routes operated by different airlines: Unique routes operated by airlines: ???
    recordCount = fillRecords(records, fileIn);
    		//5.3 Close the the file.
    printf("Unique routes operated by airlines: : %d",recordCount);
    fclose(fileIn);
    
     //6. Create an infinite loop that will do the following:
    while(1){
    		//6.1 Call printMenu()
    		printMenu();
    		//6.2 Ask the user to input a value for the menu
    		int choice;
            if (scanf("%d", &choice) != 1){
    		//6.3 Handle the case in which a non-integer value is entered
    		     printf("Invalid input. Please enter a numeric value.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
    		//6.4 Create a switch/case statement to handle all the menu options
    		switch (choice) {
                case 1:
	    		//6.4.1 Each option requires the user to enter a search key
	    		
	    		//6.4.2 Quit needs to free the array
                {
                    char origin[4], destination[4];
                    printf("Enter origin: ");
                    scanf("%s", origin);
                    printf("Enter destination:");
                    scanf("%s", destination);
                    searchRecords(records, recordCount, origin, destination, ROUTE);
                }
                break;

                case 2:
                {
                    char origin[4];
                    printf("Enter origin airport code: ");
                    scanf("%s", origin);
                    searchRecords(records, recordCount, origin, NULL, ORIGIN);
                }
                break;

            case 3:
                {
                    char destination[4];
                    printf("Enter destination airport code: ");
                    scanf("%s", destination);
                    searchRecords(records, recordCount, destination, NULL, DESTINATION);
                }
                break;

            case 4:
                {
                    char airline[3];
                    printf("Enter airline code: ");
                    scanf("%s", airline);
                    searchRecords(records, recordCount, airline, NULL, AIRLINE);
                }
                break;

            case 5:
                free(records); // Free dynamically allocated memory
                printf("Good-bye!");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}
