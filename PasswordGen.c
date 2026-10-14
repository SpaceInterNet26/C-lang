#include <stdio.h>
#include <windows.h>
#include <wincrypt.h>
#include <string.h>
#pragma comment(lib, "bcrypt.lib")
void Name();
void Gen(int, char*);

int main(){
    int Length, count;
    char char_set[4];
    int choice;
    do{
    system("cls");
    Name();
    printf("\nMain Menu:");
    printf("\n1. Password Generation\n2. Exit\nSelect number of your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
        system("cls");
        Name();
        printf("\n\tConfiguration Options");
        printf("\n-Length (12-48) = ");
        scanf("%d", &Length);
        if(Length < 12 || Length > 48){
            printf("\n Wrong Input. Try again.\n");
            system("pause");
            break;
        }
        printf("-Count (1-25) = ");
        scanf("%d", &count);
        if(count < 1 || count > 25){
            printf("\n Wrong Input. Try again.\n");
            system("pause");
            break;
        }
        printf("\n\tCharacter set");
        printf("\n-Uppercase (Y/N) : ");
        scanf(" %c", &char_set[0]);
        if(char_set[0] != 'Y' && char_set[0] != 'N'){
            printf("\n Wrong Input. Try again.\n");
            system("pause");
            break;
        }
        printf("-lowercase (Y/N) : ");
        scanf(" %c", &char_set[1]);
        if(char_set[1] != 'Y' && char_set[1] != 'N'){
            printf("\n Wrong Input. Try again.\n");
            system("pause");
            break;
        }
        printf("-numbers (Y/N) : ");
        scanf(" %c", &char_set[2]);
        if(char_set[2] != 'Y' && char_set[2] != 'N'){
            printf("\n Wrong Input. Try again.\n");
            system("pause");
            break;
        }
        printf("-symbols (Y/N) : ");
        scanf(" %c", &char_set[3]);
        if(char_set[3] != 'Y' && char_set[3] != 'N'){
            printf("\n Wrong Input. Try again.\n");
            system("pause");
            break;
        }
        char *ptr = char_set;
        for(int j = 1; j <= count; j++){
        printf("%d.\t", j);
        Gen(Length, ptr);}
        system("pause");
        break;
        case 2:
            system("exit");
            break;
        default:
            printf("Invalid choice. Try again.");
            system("pause");
            break;
    }}while(choice != 2);

    return 0;
}




    void Gen(int Length, char* ptr){
        unsigned char bytes[48];
        NTSTATUS status = BCryptGenRandom(NULL , bytes, sizeof(bytes), BCRYPT_USE_SYSTEM_PREFERRED_RNG );
        if (status != 0){
        printf("\nCryptic Generation Failed");
        }
        if (*ptr == 'Y' && *(ptr+1) == 'Y' && *(ptr+2) == 'Y' && *(ptr+3) == 'Y'){
            char everything[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$^&*_-=+";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 74;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        else if (*ptr == 'N' && *(ptr+1) == 'Y' && *(ptr+2) == 'Y' && *(ptr+3) == 'Y'){
            char everythingUP[] = "0123456789abcdefghijklmnopqrstuvwxyz!@#$^&*_-=+";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 48;
            printf("%c",everythingUP[bytes[i]]);
            }
            printf("\n");
        }
        else if (*ptr == 'Y' && *(ptr+1) == 'N' && *(ptr+2) == 'Y' && *(ptr+3) == 'Y'){
            char everythingLOW[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$^&*_-=+";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 48;
            printf("%c", everythingLOW[bytes[i]]);
            }
            printf("\n");
        }
        else if (*ptr == 'Y' && *(ptr+1) == 'Y' && *(ptr+2) == 'N' && *(ptr+3) == 'Y'){
            char everythingNUM[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$^&*_-=+";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 64;
            printf("%c", everythingNUM[bytes[i]]);
            }
            printf("\n");
        }
        else if (*ptr == 'Y' && *(ptr+1) == 'Y' && *(ptr+2) == 'Y' && *(ptr+3) == 'N'){
            char everythingSPEC[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 63;
            printf("%c", everythingSPEC[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'N' && *(ptr+1) == 'N' && *(ptr+2) == 'Y' && *(ptr+3) == 'Y'){
            char everything[] = "0123456789!@#$^&*_-=+";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 22;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'N' && *(ptr+1) == 'Y' && *(ptr+2) == 'N' && *(ptr+3) == 'Y'){
            char everything[] = "abcdefghijklmnopqrstuvwxyz!@#$^&*_-=+";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 38;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'N' && *(ptr+1) == 'Y' && *(ptr+2) == 'Y' && *(ptr+3) == 'N'){
            char everything[] = "0123456789abcdefghijklmnopqrstuvwxyz";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 37;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'Y' && *(ptr+1) == 'N' && *(ptr+2) == 'N' && *(ptr+3) == 'Y'){
            char everything[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$^&*_-=+";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 38;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'Y' && *(ptr+1) == 'N' && *(ptr+2) == 'Y' && *(ptr+3) == 'N'){
            char everything[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 37;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'Y' && *(ptr+1) == 'Y' && *(ptr+2) == 'N' && *(ptr+3) == 'N'){
            char everything[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 53;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'N' && *(ptr+1) == 'N' && *(ptr+2) == 'N' && *(ptr+3) == 'N'){
            printf("\n Invalid Options. Try again.\n");
        }
        if (*ptr == 'Y' && *(ptr+1) == 'N' && *(ptr+2) == 'N' && *(ptr+3) == 'N'){
            char everything[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 27;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'N' && *(ptr+1) == 'Y' && *(ptr+2) == 'N' && *(ptr+3) == 'N'){
            char everything[] = "abcdefghijklmnopqrstuvwxyz";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 27;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'N' && *(ptr+1) == 'N' && *(ptr+2) == 'Y' && *(ptr+3) == 'N'){
            char everything[] = "0123456789";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 11;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        if (*ptr == 'N' && *(ptr+1) == 'N' && *(ptr+2) == 'N' && *(ptr+3) == 'Y'){
            char everything[] = "!@#$^&*_-=+";
            for(int i = 0; i < Length; i++){
            bytes[i] %= 12;
            printf("%c",everything[bytes[i]]);
            }
            printf("\n");
        }
        


    }







void Name(){
printf(" ____                                     _    ____                           _             \n"
"|  _ \\ __ _ ___ _____      _____  _ __ __| |  / ___| ___ _ __   ___ _ __ __ _| |_ ___  _ __ \n"
"| |_) / _` / __/ __\\ \\ /\\ / / _ \\| '__/ _` | | |  _ / _ \\ '_ \\ / _ \\ '__/ _` | __/ _ \\| '__|\n"
"|  __/ (_| \\__ \\__ \\  V  V / (_) | | | (_| | | |_| |  __/ | | |  __/ | | (_| | || (_) | |   \n"
"|_|   \\__,_|___/___/ \\_/\\_/ \\___/|_|  \\__,_|  \\____|\\___|_| |_|\\___|_|  \\__,_|\\__\\___/|_|   \n");



}
