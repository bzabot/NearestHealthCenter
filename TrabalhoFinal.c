#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    // Open the file
    FILE *pont_arq;
    pont_arq = fopen("UbsCtba.txt", "r");
    if(pont_arq == NULL){
        printf("Error.");
        return 0;
    }
    
    // Variables
    int i, j, counter;
    i = j = counter = 0;
    char buffer[500000], latitude[50], longitude[50];
    char latitudeC[500], longitudeC[500], name[500], street[500], neighborhood[500], city[500], phone[500], formattedPhone[500];
    char userLat[500], userLong[500];
    double lat, userLatFloat, longi, userLongFloat, distance, minDistance;

    // Read the latitude/longitude
    printf("Enter your location coordinates in the fields below: ");
    printf("\nEnter the latitude: ");
    gets(userLat);
    printf("\nEnter the longitude: ");
    gets(userLong);
    
    // Format the obtained latitude/longitude
    for(i = 0; userLat[i] != '\0'; i++){
        if(userLat[i] == ','){
            userLat[i] = '.';
        }
    }
    for(i = 0; userLong[i] != '\0'; i++){
        if(userLong[i] == ','){
            userLong[i] = '.';
        }
    }
    
    // Convert the formatted string to float
    userLatFloat = atof(userLat);
    userLongFloat = atof(userLong);
    
    // Loop through the file
    while(fgets(buffer, sizeof(buffer), pont_arq) != NULL){

        // Get the latitude/longitude
        for(i = 0; buffer[i] != ','; i++){
            latitude[i] = buffer[i];
        }
        i++; // to skip the comma
        while(buffer[i] != ','){
            longitude[j] = buffer[i];
            j++;
            i++;
        }
        i++;
        j = 0;
        
        // Convert from string to float
        lat = atof(latitude);
        longi = atof(longitude);
        // Calculate the distance
        distance = sqrt(pow((lat - userLatFloat), 2) + pow((longi - userLongFloat), 2));
        
        // Assign variables in the first loop
        if(counter == 0){
            minDistance = distance;
            
            // Save the coordinates (IN CASE IT IS NECESSARY TO PRINT THE HEALTH CENTER COORDINATES)
            strcpy(latitudeC, latitude);
            strcpy(longitudeC, longitude);
            
            // Skip the useless data
            for(j = 0; j < 2; j++){
                while(buffer[i] != ','){
                    i++;
                }
            }
            i++;
            j = 0;
            // Assign the name of the establishment
            while(buffer[i] != ','){
                name[j] = buffer[i];
                i++;
                j++;
            }
            i++;
            j = 0;
            // Assign the street
            while(buffer[i] != ','){
                street[j] = buffer[i];
                i++;
                j++;
            }
            i++;
            j = 0;
            // Assign the neighborhood
            while(buffer[i] != ','){
                neighborhood[j] = buffer[i];
                i++;
                j++;
            }
            i++;
            j = 0;
            // Assign the city
            while(buffer[i] != ','){
                city[j] = buffer[i];
                i++;
                j++;
            }
            i++;
            j = 0;
            // Assign the phone number
            while(buffer[i] != ','){
                phone[j] = buffer[i];
                i++;
                j++;
            }
            j = 0;
        }
        
        // Assign variables if the distance is smaller
        else if(minDistance > distance){
            minDistance = distance;

            // Save the coordinates (IN CASE IT IS NECESSARY TO PRINT THE HEALTH CENTER COORDINATES)
            strcpy(latitudeC, latitude);
            strcpy(longitudeC, longitude);
            
            // "Clear" the variables to avoid leftover text at the end
            for(j = 0; name[j] != '\0'; j++){
                name[j] = '\0';
            }
            for(j = 0; street[j] != '\0'; j++){
                street[j] = '\0';
            }
            for(j = 0; neighborhood[j] != '\0'; j++){
                neighborhood[j] = '\0';
            }
            for(j = 0; city[j] != '\0'; j++){
                city[j] = '\0';
            }
            for(j = 0; phone[j] != '\0'; j++){
                phone[j] = '\0';
            }

            // Skip the useless data
            for(j = 0; j < 2; j++){
                while(buffer[i] != ','){
                    i++;
                }
                i++;
            }
            j = 0;
            
            // Assign the name of the establishment
            while(buffer[i] != ','){
                name[j] = buffer[i];
                i++;
                j++;
            }
            i++;
            j = 0;
            // Assign the street
            while(buffer[i] != ','){
                street[j] = buffer[i];
                i++;
                j++;
            }
            i++;
            j = 0;
            // Assign the neighborhood
            while(buffer[i] != ','){
                neighborhood[j] = buffer[i];
                i++;
                j++;
            }
            i++;
            j = 0;
            // Assign the city
            while(buffer[i] != ','){
                city[j] = buffer[i];
                i++;
                j++;
            }
            i++;
            j = 0;
            // Assign the phone number
            while(buffer[i] != ','){
                phone[j] = buffer[i];
                i++;
                j++;
            }
            j = 0;
        }
        
        // INCREMENT THE COUNTER
        counter++;
    }
    
    // FORMAT THE PHONE NUMBER
    if(strlen(phone) == 8){
        for(i = 0; i < 9; i++){
            if(i == 4){
                formattedPhone[i] = '-';
            } else {
                formattedPhone[i] = phone[j];
                j++;
            }
        }
    } else {
        for(i = 0; i < 13; i++){
            if(i == 0){
                formattedPhone[i] = '(';
            } else if(i == 3){
                formattedPhone[i] = ')';
            } else if(i == 8){
                formattedPhone[i] = '-';
            } else {
                formattedPhone[i] = phone[j];
                j++;
            }
        }
    }
    
    // PRINT THE OBTAINED DATA
    printf("\nHealth Center: ");
    for(i = 0; name[i] != '\0'; i++){
        printf("%c", name[i]);
    }
    printf("\nAddress: ");
    for(i = 0; street[i] != '\0'; i++){
        printf("%c", street[i]);
    }
    printf("\nNeighborhood: ");
    for(i = 0; neighborhood[i] != '\0'; i++){
        printf("%c", neighborhood[i]);
    }
    printf("\nPhone: ");
    for(i = 0; formattedPhone[i] != '\0'; i++){
        printf("%c", formattedPhone[i]);
    }

    return 0;
}
