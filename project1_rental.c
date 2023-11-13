//Name: Paramveer Singh Bhele
//UNumber: U82076898
//Description : Project 1 - First the program asks the user to enter the quipment selection. 
//It then checks whether the selection is valid or not and if the selection is from 1 to 4. Terminates the program if it is not valid.
//Next the user enters the days and hours for the equipment and validates the hours if it is from 1 to 24.
//Then the weeks and the remaining days are calculated. If it is greater than or equal to 4 then 1 week is added.
//I have used the switch case statement to switch betweeen the equipments.
//Case 1 is for Carpet Blower. Case 2 is Carpet Cleaner. Case 3 is Carpet Extractor with heater. 
//Case 4 is Hard Flooring Cleaner. Break statements are used to break the case statements and then break out of the switch statement.

#include <stdio.h>
int main() {
    // Get the equipment ID from the user.
    int equip_id;
    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    printf("Enter equipment selection: ");
    scanf("%d", &equip_id);

    // Validate the equipment ID.
    if (equip_id < 1 || equip_id > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 1;}

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
        return 1;}

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

    int total_charge=0; //the total charge which will be calculated
    switch (equip_id) { 
        case 1:{ //case for the first equipment 
            if (hours<=4&&hours>0){
                hours_charge=7;}
            else if (hours>4){ //if greater than 4 then the day's charge will be added
                hours_charge=10;}
            if (days>7){ 
                days_charge=rem*10;}
            else{
                days_charge=days*10;}
            weekly_charge= weeks*40;
            total_charge=hours_charge+days_charge+weekly_charge;
            printf("Charge($): %d\n", total_charge); } //the total charge to be printed
            break;// breaks this case

        case 2:{ //the 2nd case
            if (hours<=4 &&hours>0){
                hours_charge=27;}
            else if (hours>4){
                hours_charge=39;}
            if (days>7){
                days_charge=rem*39;}
            else{
                days_charge=days*39;}
            weekly_charge= weeks*156;
            total_charge=hours_charge+days_charge+weekly_charge;
            printf("Charge($): %d\n", total_charge);}
            break;

        case 3:{ //the 3rd case
            if (hours<=4 &&hours>0){
                hours_charge=61;}
            else if (hours>4){
                hours_charge=87;}
            if (days>7){
                days_charge=rem*87;}
            else{
                days_charge=days*87;}
            weekly_charge= weeks*348;
            total_charge=hours_charge+days_charge+weekly_charge;
            printf("Charge($): %d\n", total_charge);}
            break;

        case 4:{//the 4th case
            if (hours<=4){
                hours_charge=59;}
            else if (hours>4){
                hours_charge=84;}
            if (days>7){
                days_charge=rem*84;}
            else{
                days_charge=days*84;}
            weekly_charge= weeks*336;
            total_charge=hours_charge+days_charge+weekly_charge;
            printf("Charge($): %d\n", total_charge);}
            break;
        default: printf("Invalid Values\n");}
    return 0; //to exit the program successfully
}