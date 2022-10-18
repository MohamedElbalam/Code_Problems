#include <iostream>

using namespace std;

/*

Author: Mohamed Elbalam

Course: CSCI-150

Instructor: Genady Maryash 

Assignment: Lab 6C
vigenere cipher is used polyalphabetic cipher 
Method: there is a key word such as apple
the message that needed to be ciphered: eat banana
add the aplhabet value together and become the ciphered text

plain text   H e l l o , W o r l d !
            +
key          c a k e c   a k e c a 
            ----------------------
cipher text  J e v p  q, W y v n  d

the key is always lower case letter 
if the plain text  is upper case the cipher text should be same 
*/

char shiftChar(char c, char k){
// take c which is the plaintext letter and shift it by k which is the key shift
//convert these two letters to nums from 0 to 25 and calc the distance from A or a
 

if(!isalpha(c)){
    return c;
}

int text, key,result;
//toupper to avoid the case of lower or upper case letters 
 text = (toupper(c) - 97);
key = (k - 65);

result = (text + key) % 26;

  if(islower(c)){
    //returns the lower letters that is distnced from the lower case a
      return tolower(result + 'a');
  }
  //return the upper case letters that is distanced from the upper case A
  return result + 'A';
}


string encryptVigenere(string plaintext, string keyword){
    cout << plaintext.length() << endl;
    // int key_, text;
    // text = ((int(plaintext[0])-65)%26);
    // key_ = ((int(keyword[0]) - 97) % 26);

   //cout << "module "<< 4%4 << endl;

    cout << "cipher: " << shiftChar(plaintext[0], keyword[0]) << endl;  
    // cout << text << endl;
    // cout << key_ << endl;
    // cout << "-------------------" << endl;
    // cout << char((text + key_)) << endl;


 

//I need to loop through each word and repeat cake again when its done 
    string result;
    int counter{0},keyIndex{0};

while (counter < plaintext.length()){
    //I should not count key index with space and commas or other chars than alpha
    // cout << "counter: " << counter << " keyindex: " << keyIndex << endl;
    // cout << plaintext[counter] <<" + "<< keyword[keyIndex] << " = " <<shiftChar(plaintext[counter], keyword[keyIndex]) << endl;


//I dont want to repeat the key shift in case of non alphabet characters
    if(!isalpha(plaintext[counter])){
        keyIndex--;
    }

    result += shiftChar(plaintext[counter], keyword[keyIndex]);
    keyIndex++;

    if (keyIndex == keyword.length())
    {
        keyIndex = 0;
        }

    counter++;
}

        return result;
}

int main(){
    // string plaintext, keyword;
    // cout << "Enter plaintext: ";
    // getline(cin, plaintext);
    // cout << "Enter keyword: ";
    // cin >> keyword;

    cout << encryptVigenere("Hello, World!", "x");


    return 0;
}