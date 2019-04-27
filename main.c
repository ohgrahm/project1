#include <stdio.h>
#include <string.h>


// prototype
void rotEncryption(void);
//void rotDecryption(void);
//void subEncryption(void);
//void subDecryption(void);

int main(){

   //Printf menu
   printf("Please choose a number: \n");
   printf("1. Rotation Cipher Encryption\n");
   printf("2. Rotation Cipher Decryption\n");
   printf("3. Substitution Cipher Encryption\n");
   int c;
   scanf("%d", &c);
   // determines which one to use
    switch (c) {
        case 1:
            rotEncryption();
        break;
        
        /*
        case 2:
            printf("Please enter rotation amount between 0 & 25:\n");
            scanf("%d", &k);
            rotDecryption(message, text, k);
        break; 

        case 3:
            subEncryption(message, text);
            break;
        case 4:
            subDecryption(message, text);
            break;
      */
 
        default:
            printf("Please enter valid input (1, 2, 3, 4).\n");
            break;
    }
}

//def
// encrypts the rotation cipher
void rotEncryption(void){
   char text[] = "This is a test";
   int k = 5;
   for(int i=0; i < 18; i++){
       if(text[i] != 32 && text[i] !=0){
           //convert ascii
           text[i] = text[i] - 97; 
           // letter shift based on key
           text[i] = text[i] + k;
           text[i] = text[i] % 26;
           //converts back to alphabet
           text[i] = text[i] + 97;
       }
   }
    printf("%s\n", text);
}