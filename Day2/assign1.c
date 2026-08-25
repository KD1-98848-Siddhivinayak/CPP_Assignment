#include<stdio.h>
struct Date {
    int day ;
    int month;
    int year ;
};
void initDate(struct Date* ptrDate){
ptrDate->day=1;
ptrDate->month=10;
ptrDate->year=2004;

}
void printDateOnConsole(struct Date* ptrDate){
printf("-----Date------");


printf("\n    :%d-%d-%d",ptrDate->day,ptrDate->month,ptrDate->year);
} 
void acceptDateFromConsole(struct Date* ptrDate){
    printf("\n-------enter the date-------");
    printf("\nenter the day ");
    scanf("%d",&ptrDate->day);
    printf("\nenter the month ");
    scanf("%d",&ptrDate->month);
    printf("\nenter the year ");
    scanf("%d",&ptrDate->year);
    
}



int  menulist(void){
    int choice;
    
    printf("\n0.for exit\n1.for init date\n2.accept date\n3.print date\n");
    scanf("%d",&choice);
    return choice;


}
int main (){
    struct Date d1;
    int choice ;
    while((choice = menulist())!=0){
        switch (choice){
            case 1:
            initDate(&d1);
            break;
            case 2:
            acceptDateFromConsole(&d1);
            break;
            case 3:
            printDateOnConsole(&d1);
            break;

        }

    }


    // initDate(&d1);
    // printDateOnConsole(&d1);
    // acceptDateFromConsole(&d1);
    // printDateOnConsole(&d1);



}