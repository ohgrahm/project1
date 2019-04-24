#include <stdio.h>
#include <string.h>


// prototype
void rotEncryption(char message[1024], char text[1024], int k);
void rotDecryption(char message[1024], char text[1024], int k);
//void subEncryption(char message[1024], char text[1024], int k);
//void subDecryption(char message[1024], char text[1024], int k);

int main(){
    FILE *input, *output;
    char message[1024]; //input message is stored here 
    char text[1024]; //encrypted/decrypted text is stored here
    int i, k; // i is used to iterate through message, c is used to read the slection from user for which encryption, k is used to determine the shift amout
    int c;
   // Initialises input & output files.
   output = fopen("output.txt", "w");
   input = fopen("input.txt", "r");
   // prints error if there is no input
   if (input == NULL){
      perror("File Input");
  }

   // gets the input and puts into the array "message"
   while (fgets(message, sizeof(message), input)) {
      i++;
   }
// menu for function selection
   printf(" \n Please enter key between 0 & 25:");
   scanf("%d", &k);
   rotEncryption(message, text, k);
   //Printf menu
   printf("Please choose a number: \n");
   printf("1. Rotation Cipher Encryption\n");
   printf("2. Rotation Cipher Decryption\n");
   printf("3. Substitution Cipher Encryption\n");
   scanf("%d", &c);
   // determines which one to use
    switch (c) {
        case 1:
            printf(" \n Please enter key between 0 & 25:");
            scanf("%d", &k);
            rotEncryption(message, text, k);
        break;
        
        
  /*      case 2:
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
            printf("Please valid option (1, 2, 3, 4).\n");
            break;
    }   
 //prints the encrypted/decrypted text to the output file   
  printf("\n");
   for (i = 0; message[i] != '\0'; i++) {
      printf("%c", text[i]);
      fprintf(output, "%c", text[i]);
   }
   fclose(stdin);
} 

//def
// encrypts the rotation cipher
void rotEncryption(char message[1024], char text[1024], int k){
    int i;
    //iterates through each character in the inputted message
    for (i = 0; message[i] != '\0'; i++) {
        //if the current character is greater than ascii A and less than ascii Z
        if (message[i] >= 'A' && message[i] <= 'Z') {
            // gives encrypted character (e(x) = (m + k)(mod 26))
            text[i] = message[i] + (k % 26);
            //if encrypted value is greater than ascii z, value of current character is equal to calculated to be in ascii range
            if (text[i] > 'Z'){
                text[i] = ('A' - 1 + (text[i] - 'Z') % 26);
            }    
            //if encrypted value is greater than ascii z, value of current character is calculated to be in ascii range
            if (text[i] < 'A'){
                text[i] = ('Z' - 1 + (text[i] - 'A') % 26);
        } else {
            text[i] = message[i]; // Skips any non-alphabet character
            }		
        }
    }
}


