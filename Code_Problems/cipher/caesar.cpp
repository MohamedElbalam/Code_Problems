#include <iostream>
#include <string>

using namespace std;

/*

Author: Mohamed Elbalam

Course: CSCI-150

Instructor: Genady Maryash 

Assignment: Lab 6B
Use ceaser cipher to encrypt a message 
The program should ask user for input text and input shift key, then output the encrypted message.

I just want to try my own algorithms eventhough using mod would be much cleaner but I just want diff solution

my approach is simple. use the key shift to add to the current alphabet value in the ascii table and return the new value but if its greater than ascii table 26 character, i just added that extra value as start from the begging

*/


//this function return the character with the key shift
// char shiftChar(char c, int rshift){

// //check if the char is not an alpha character and return it 
// if(!isalpha(c)){
//     return c;
// }

// //calculate extra number if it is bigger than the ascii alphabet
// int extra = rshift+int(c) ;

// //if the character is an Uppercase
// if(isupper(c)){
//     while(extra > 90){
//         //This reset the characters to start from A again if the keyshift passed the ascii table of 90 which is char Z
//         return char(64 + ((rshift + int(c)) - 90));
//     }
// }
// //this is is for lower characters
// if(islower(c) && extra>122){
//     return char(96 + ((rshift + int(c)) - 122));
// }

// //
// return char((int(c) + rshift) ) ;    

// }


//simpler function
char shiftChar(char c, int rshift){

//check if the char is not an alpha character and return it 
if(!isalpha(c)){
    return c;
}

//calculate extra number if it is bigger than the ascii alphabet
int extra = rshift+int(c) ;

//if the character is an Uppercase

    if((extra > 90 && isupper(c)) || (islower(c) && extra>122) ){
        //This reset the characters to start from A again if the keyshift passed the ascii table of 90 which is char Z
      
      //this to return the uppper characters
        return char(64 + ((rshift + int(c)) - 90));

        //this to return the lower characters 
        return char(96 + ((rshift + int(c)) - 122));

    }


return char((int(c) + rshift) ) ;    

}

//this to get the text and key shift from user
string encryptCaesar(string text, int rshift){

    string result;
    for(int i =0 ; i<text.length(); i++){
        result += shiftChar( text[i] , rshift);
    }
    return result;
}

int main(){

    //cout << int('T')<<endl;
    //cout << shiftChar('t', 4);
    string str;
    int key;
    cout << "Enter plaintext: ";
    getline(cin, str);
    cout << "Enter shift: ";
    cin >> key;

    cout <<"Ciphertext: "<< encryptCaesar(str, key) << endl;

    return 0;
}