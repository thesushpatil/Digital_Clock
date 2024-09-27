# Digital_Clock

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>


// Function to display the current date and time 
 void display_Current_DateTime()
{
    time_t currentTime;
    struct tm *localTime;

    // Get the current time
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    printf("Current Date and Time: %02d-%02d-%04d %02d:%02d:%02d\n",
            localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900,
            localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}
  
  //function to set a clock
  int set_clock()
  {
    int sec,min,hour;
    int d=1000; //1000 milisecond=1sec
    printf("Enter Hour:");
    scanf("%d",&hour);

    printf("Enter Minute:");
    scanf("%d",&min);

    printf("Enter Second:");
    scanf("%d",&sec);

    if(hour>12 || min>60 || sec>60)
    {
      printf("\nInvalid Input!!\n");
      return -1;
    }

    do
    {
      printf("\033[36m\n                                                      DIGITAL CLOCK\033[0m\n");//cyan
      printf("\n                                            ==================================\n");
      printf("                                                        %02d:%02d:%02d",hour,min,sec);
      printf("\n                                            ==================================\n");
      printf("\n\033[31m                                                   Enter 'X' For Exit\033[0m\n ");//red
      Sleep(d);

      sec++;
      if(sec>59)
      {
        min++;
        sec=0;
      }
      if(min>59)
      {
        hour++;
        min=0;
      }
      if(hour>12)
      {
        hour=1;

      }
        // Check for a single key press to exit
        if(_kbhit()) {  // Use _kbhit for compatibility
            char input=_getch();  // Use _getch to get the character
            if (input == 'X' || input == 'x') {
                return -1;
            }
        }

      system("cls");

    }while(1);
    }

    //fuction to set a timer
    int timer()
    {
       int hr,minute,second ;  // Set the desired number of hour,minute and second for the timer
      printf("Enter timer You want to set:\n");
      printf("Enter Hour:");
      scanf("%d",&hr);

      printf("Enter Minute:");
      scanf("%d",&minute);

      printf("Enter Second:");
      scanf("%d",&second);


    if(hr<24 && minute<60 && second<60)
        {
    int timer=(hr*3600)+(minute*60)+second;   //this will convert all values in seconds

    printf("\033[31mTimer started... Waiting for %d hr %d minutes %d seconds.\033[0m\n",hr,minute,second);

    sleep(timer);  // The program will wait for the specified number of seconds

    Beep(1000,400);//frequency,duration
    Sleep(100);
    Beep(1000,400);
    Sleep(100);
    Beep(1000,400);
    Beep(1000,400);
    Sleep(100);
    Beep(1000,400);
    Sleep(100);

    printf("\033[32mTimer elapsed!! %d hr %d minutes %d seconds.\033[0m\n", hr,minute,second);//green
    }
    else{
      printf("The Timer is only for 24 hours\nInavalid !\n");
    }
    return 0;
    }

      //function to display a calendar
    int calendar()
    {

    do{
        int a;
      printf("\nThis Calendar Has Range Between 1950 and 2100\n");
      printf("\nChoose Option(1-2) :\n1.See Calendar\n2.Exit\n");

       if(scanf("%d",&a) != 1 )//check it is integer or not
         {
          scanf("%*[^\n]");//it Clears Input Buffer(discard remaining characters)
          printf("Invalid Input!\nEnter Valid Input\n");
          }
       switch(a)
        {
       case 1 : int year, month, daysInMonth, startingDay, dayOfWeek;

    // Input year and month
    printf("Enter year (1950-2100): ");
    if(scanf("%d",&year) != 1 )//check it is integer or not
         {
          scanf("%*[^\n]");//it Clears Input Buffer(discard remaining characters)
          printf("\n\nInvalid Input!Enter Valid Input\n");
          }

    printf("Enter month (1-12): ");
    if(scanf("%d",&month) != 1 )//check it is integer or not
         {
          scanf("%*[^\n]");//it Clears Input Buffer(discard remaining characters)
          printf("\n\nInvalid Input!Enter Valid Input\n");
          }

  if(year<=2100 && year>=1950 && month<13 && month>0)
  {
    // Calculate the number of days in the month
    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    // Calculate the starting day of the month  //doomsday algorithm
    startingDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 1; i < month; ++i) {
        if (i == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                startingDay += 29;
            else
                startingDay += 28;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            startingDay += 30;
        } else {
            startingDay += 31;
        }
    }
    dayOfWeek = (startingDay + 1) % 7; // Incrementing the starting day by 1

    // Display the calendar
    printf("\n==============================\n");
    printf("          %d-%02d\n", year, month);
    printf("==============================\n");
    printf("\033[35m Sun Mon Tue Wed Thu Fri Sat\033[0m\n");//purple

    // Print spaces for the days before the starting day of the month
    for (int i = 0; i < dayOfWeek; ++i) {
        printf("    ");
    }

    // Print the days of the month
    for (int day = 1; day <= daysInMonth; ++day) {
        printf("%4d", day);
        if ((day + dayOfWeek) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
    break;
    }
    else{
        printf("\nThe Range Of Year and Month Does'nt Match \n\n");
        break;
    }

     case 2: return -1;

    default:
            printf("\nYou Entered Invalid Input\n\n");
           break;

    }
    }while(1);

    printf("\nYou Entered Invalid Input\n\n");
    
    }

    int main()
    {

    while(1)
        {
       int choice;
       printf("\033[31m--------------------------------\033[0m\n");//red
       printf("\033[34mEnter Choice (1-5):\n 1.Get Current Time:\n 2.Set Timer:\n 3.Display Calendar:\n 4.Set clock:\n 5.Exit\n\033[0m");//blue
       printf("\033[31m--------------------------------\033[0m\n");//red

       if(scanf("%d",&choice) != 1 )//check it is integer or not
         {
          scanf("%*[^\n]");//it Clears Input Buffer(discard remaining characters)
          printf("\nInvalid Input!Enter Valid Input\n");
          }
    else{
            switch(choice)
    {
      case 1 : display_Current_DateTime();
          break;

      case 2 : timer();
          break;

      case 3: calendar();
          break;

      case 4 : set_clock();
                break;

      case 5 : exit(0);

      default:printf("Invalid Choice\n\n");
          break;
    }
    }
    }
    return 0;
}

