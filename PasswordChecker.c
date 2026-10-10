#include <stdio.h>
#include <string.h>

int upcase(char password[], int length);
int lowcase(char password[], int length);
int num(char password[], int length);
int spec(char password[], int length);
void Strength(int length, int countup, int countlow, int countnum, int countspec);

int main(){
    system("cls");
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    printf("\n\tPassword analysis:\n");
    int length = strlen(password);
    printf("Password length: %d\n", length );
    printf("Contains uppercase: ");

    int countup = upcase(password, length);
    printf("\nContains lowercase: ");
    int countlow = lowcase(password, length);
    printf("\nContains numbers: ");
    int countnum = num(password, length);
    printf("\nContains special characters: ");
    int countspec = spec(password, length);
    printf("\n\n\tPassword Strength: ");
    Strength(length, countup, countlow, countnum, countspec);
    return 0;
}

int upcase(char password[], int length){
    int count = 0;
    for(int i = 0; i <= length; i++){
        if(password[i] >= 65 && password[i] <= 90){
            count++;
        }
    }
    if(count > 0)
    printf("TRUE");
    else
    printf("FALSE");
    return count;
}
int lowcase(char password[], int length){
    int count = 0;
    for(int i = 0; i <= length; i++){
        if(password[i] >= 97 && password[i] <= 122){
            count++;
        }
    }
    if(count > 0)
    printf("TRUE");
    else
    printf("FALSE");
    return count;
}
int num(char password[], int length){
    int count = 0;
    for(int i = 0; i <= length; i++){
        if(password[i] >= 48 && password[i] <= 57){
            count++;
        }
    }
    if(count > 0)
    printf("TRUE");
    else
    printf("FALSE");
    return count;
}
int spec(char password[], int length){
    int count = 0;
    for(int i = 0; i <= length; i++){
        if(password[i] >= 33 && password[i] <= 44 || password[i] >= 58 && password[i] <= 64 || password[i] >= 91 && password[i] <= 96 || password[i] >= 123 && password[i] <= 126){
            count++;
        }
    }
    if(count > 0)
    printf("TRUE");
    else
    printf("FALSE");
    return count;
}

void Strength(int length, int countup, int countlow, int countnum, int countspec){
    if(length > 12 && countup > 0 && countlow > 0 && countnum > 0 && countspec > 0){
        printf("STRONG");
    }
    else if(length > 8 && countup >= 0 && countlow > 0 && countnum >= 0 && countspec >= 0){
        printf("MEDIUM");
    }
    else{
        printf("WEAK");
    }
}
