//Stopwatch
#include<stdio.h>
#include<time.h>
 
int main(){
    printf("Click any button to stop\n");//Menu
    printf("L=lap\nspace for pause\n");//Menu
    int min,sec,ms,lap=1;//Variables
    clock_t start,stop;//Timer
    start=clock();//Define start value
    while (1)  {  
        while (1){  
            stop = clock();  //Define stop value
            printf("\r");  //Go to the start
            int time = stop - start;//Calculating time
            min = (time / 1000) / 60;//Calculating minutes
            sec = (time / 1000) % 60;//Calculating seconds
            ms = time % 1000;
            printf("Time-\t %d : %d : %d ", min, sec, ms); //Printing the time
            if (kbhit())//If key is pressed
                break;
        }
        char ch=getch();//Input
        if (ch == 'l') { //l for lap time

            printf("\nlap %d- %d : %d : %d \n",lap, min, sec, ms);//Printing lap no and time
            lap++;//Increasing lap number
            continue; //Continue the outer loop
        } else if (ch == ' ') { //Space for pause
            getch(); //Wait for another key press
        } else { //Any other key to stop the timer
            break; //Break out of both loops
        }

        start = start + (clock() - stop);
    }

}