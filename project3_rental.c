//Name: Paramveer Singh Bhele
//UNumber: U82076898
//Description : Project 3 - Task 1 - Modifying Project 1
//I had used switch case in project 1. So, I kept the calculation type same but this time i am calculating the values only once.
//I have defined the number of equipments to 4 at the start. Then I stored the values in order of the equipment in arrays according to the question.
// I have used the arrays to calculate the different values of the equipments.

#include <stdio.h>

// Define the number of equipments.
#define NUM_EQUIPS 4

// Define the arrays for the hourly, daily, and weekly rates.
int hourly_rates[NUM_EQUIPS] = {7, 27, 61, 59};
int daily_rates[NUM_EQUIPS] = {10, 39, 87, 84};
int weekly_rates[NUM_EQUIPS] = {40, 156, 348, 336};

int main() {
    // Get the equipment ID from the user.
    int equip_id;
    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    printf("Enter equipment selection: ");
    scanf("%d", &equip_id);

    // Validate the equipment ID.
    if (equip_id < 1 || equip_id > NUM_EQUIPS) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 1;
    }

    // Get the number of days and hours from the user.
    int days;
    int hours;
    printf("Enter days: ");
    scanf("%d", &days);
    printf("Enter hours: ");
    scanf("%d", &hours);

    // Validate the hours.
    if (hours < 0 || hours >= 24) {
        printf("Invalid hours.\n");
        return 1;
    }

    int hours_charge=0; //hourly charge
    int days_charge=0; //daily charge
    int weekly_charge=0; //weekly charge
    int rem=days%7; //the remaining number of days after calculating the weeks
    int weeks=days/7; //calculate the number of weeks by dividing the days
    if (rem>=4) //if the remaining number of days is greater than or equal to 4 then the charge of 1 week will be added
    {   rem=0;
        weeks=weeks+1;
        days=0;
        hours=0;} //the number of days and hours will be set as 0 as we are adding the weekly charge

    // Calculate the total charge.
    int total_charge = 0;
    if (hours<=4&&hours>0){
                hours_charge=hourly_rates[equip_id-1];}
            else if (hours>4){ //if greater than 4 then the day's charge will be added
                hours_charge=daily_rates[equip_id - 1];}
            if (days>7){ 
                days_charge=rem * daily_rates[equip_id - 1];}
            else{
                days_charge=days*daily_rates[equip_id - 1];}
            weekly_charge= weeks*weekly_rates[equip_id - 1];
            total_charge=hours_charge+days_charge+weekly_charge;
            

    // Print the total charge.
    printf("Charge($): %d\n", total_charge);

    return 0;
}
