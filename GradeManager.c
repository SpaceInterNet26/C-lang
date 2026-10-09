#include <stdio.h>

int Avrg(int grades[],int students);
int SBL(int grades[], int students);
int SBH(int grades[], int students);
int Passed(int grades[], int students);
int Failed(int grades[], int students);

int main(){

    int students = 0;
    int grades[500] = {0};
    int choice;
    do{
        system("cls");
        printf("\t\tStudent Grade Calculator\n");
        printf("\n1. Enter grades\n2. Show all grades\n3.Exit");
        printf("\nSelect a number of your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                system("cls");
                printf("\t\tSTUDENT GRADE FILLER\n\n");
                printf("How many students? ");
                scanf("%d", &students);
                for(int i = 0; i < students; i++){
                printf("student nr. %d grades: ", i+1);
                
                scanf("%d", &grades[i] );
                if(grades[i] > 10 || grades[i] < 1){
                    printf("\nA grade is rated thru 1-10. Try again\n");
                    grades[i] = 0;
                    break;
                }
                }
                system("pause");
                break;

            case 2:
                system("cls");
                if(grades[0] >= 1){
                printf("\t\tSTUDENT GRADES\n\n");
                for(int i = 0; i < students; i++){
                   printf("Student Nr. %d : %d\n", i+1, grades[i] );
                   
                }
                printf("\n\n");
                printf("Highest grade in class: %d\n", SBH(grades, students ));
                printf("Lowest grade in class: %d\n", SBL(grades, students));
                printf("Average grade in class: %d\n", Avrg(grades, students));
                printf("Passed: %d,\tFailed: %d\n", Passed(grades, students), Failed(grades, students));


                system("pause");}
                else{
                    printf("\nYou have to assign grades to students first!\n");
                    system("pause");
                }
                break;
            case 3:
                break;
            default:
                printf("\n You have to choose between 1-3 . Try again!\n");
                system("pause");
                break;

                

 
        }
    
    
    
    }while(choice != 3);

return 0;
}


int SBH(int grades[], int students){
    int max = grades[0];
    for(int i = 0; i < students; i++){
        if(grades[i]> max){
            max = grades[i];
        }
    }
    return max;
}
int SBL(int grades[], int students){
    int min = grades[0];
    for(int i = 0; i < students; i++){
        if(grades[i] < min){
            min = grades[i];
        }

    }
    return min;
}
int Avrg(int grades[],int students){
    int avrg = 0;
    for(int i = 0; i < students; i++){
        avrg += grades[i];
    }
    return avrg/students;
}
int Passed(int grades[], int students){
    int pass = 0;
    for(int i = 0; i < students; i++){
        if(grades[i] >= 4)
        pass++;
    }
    return pass;
}
int Failed(int grades[], int students){
    int fail = 0;
    for(int i = 0; i < students; i++){
        if(grades[i] < 4)
        fail++;
    }
    return fail;
}
