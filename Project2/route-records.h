#ifndef ROUTE_RECORDS_H
#define ROUTE_RECORDS_H

//Struct that holds information about a route that is operated by one airline.
typedef struct RouteRecord_Struct{

    char airportOrigin[4]; //The 3 letter IATA Airport Code for the origin + 1 for null
    char airportDesti[4]; //The 3 letter IATA Airport Code for the destination + 1 for null
    char airlineCode[3]; //The 2 lettter IATA Airline Code for the airline + 1 for null
    int passengerCnt[6]; //Array of passenger counts, six months worth of data, 0 = January - 6 is June + 1 for null

}RouteRecord;

//enum that is used to determine what type of search to conduct.
typedef enum SearchType{
    ROUTE,
    ORIGIN,
    DESTINATION,
    AIRLINE
} SearchType;

//Prototypes for the functions!
RouteRecord* createRecords(FILE* fileIn);
int fillRecords( RouteRecord* r, FILE* fileIn);
int findAirlineRoute( RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx);
void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2, SearchType st);
void printMenu();

#endif