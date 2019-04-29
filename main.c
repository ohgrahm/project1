#include <stdio.h>
#include <string.h>


// prototype
void rotEncryption(void);
void rotDecryption(void);
//could not figure out substitution
//void subEncryption(void);
//void subDecryption(void);

int main(){
   //Printf menu
   printf("Options\n");
   printf("1. Rotation Cipher Encryption\n");
   printf("2. Rotation Cipher Decryption\n");
   printf("Please choose a number: \n");
   // determines which method
   int c=0;
   do{
        //reads user selection, and chooses which function to call
        scanf("%d", &c); 
        switch(c){
            case 1:
                rotEncryption();  
            break;
            case 2:
                rotDecryption();   
            break;
            default:
                printf("Please enter valid input\n");
            
        }
    }while(c>2);
}
//def
// encrypts the rotation cipher
void rotEncryption(void){
   char text[1024];
   printf("Please enter text to encrypt followed by a key\n");
   //scanf reads spaces with %[0-9a-zA-Z]
   scanf(" %[0-9a-zA-Z] ", text); 
   int k;
   scanf("%d", &k);
   for(int i=0; i < 12; i++){
       if(text[i] != 32 && text[i] !=0){
           //convert ascii
           text[i] = text[i] - 97; 
           // letter shift based on key
           text[i] = text[i] + k;
           //overflow
           text[i] = text[i] % 26;
           //converts back to alphabet
           text[i] = text[i] + 97;
       } 
   }
    printf("%s\n", text);
}
//decrypts given message
void rotDecryption(void){
   char text[1024];
   printf("Please enter text to decrypt followed by a key\n");
   //scanf reads spaces with %[0-9a-zA-Z]
   scanf(" %[0-9a-zA-Z] ", text);
   int k;
   scanf("%d", &k);
   //decryption process
   for (int i=0; i<400; i++){
        if(text[i] != 32 && text[i] != 0){
            //convert ascii
            text[i] = text[i] - 97; 
            // complete shift
            text[i] = text[i] + (26 - k);
            //overflow
            text[i] = text[i] % 26;
            //converts back to alphabet
            text[i] = text[i] + 97;
        }
    }
    printf("%s\n", text);
}

