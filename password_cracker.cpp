#include <iostream>
#include <fstream>
#include <string>
#include "md5.h"

using namespace std;

void bruteForce();
void wordList();
bool hashCompare(string plaintext, string hash);

int main(){
    cout << "Welcome to the C++ password cracker\n";
    cout << "please input the hashed password you'd like to crack\n";
    string inputHash;
    cin >> inputHash;
    cout << "you entered " + inputHash + "\n";
	cout << "Would you like to use a wordlist?\n (y/n)\n";
    
    char yesOrNo;
    
    bool inputInvalid = true;
    while (inputInvalid){
        cin >> yesOrNo;
        if (yesOrNo == 'y' || yesOrNo == 'Y'){
            cout << "Ok using wordlist\n";
            inputInvalid = false;
        }
        else if (yesOrNo == 'n' || yesOrNo == 'N'){
            cout << "Ok brute forcing\n";
            inputInvalid = false;
            bruteForce();
        }
        else cout << "Bad input: please type either 'y' or 'n'\n";
    }

	string test = "test";
    string test2 = "test";
	if (test.compare(test2) == 0){
		cout << "Match Found!\n";
	}
	return 0;
}

//read in using wordlist
void wordList(){
    cout << "please enter your wordlist\n";
    string plainText;
    std::ifstream file("rockyou.txt");
    std::string s;
    bool matchfound = hashCompare("ponies", "47346fc7580de7596d7df8d115a3545d");
    while (std::getline(file, s)){

if (!file){ //testing if file opens
cout << "unable to open file";
exit(1);

if (file has next line){
        s = file current line;

        }
else {
        current line = next line;
  }
}   
}
string line;
	string str;
string hash = "FF0EB2864FEB22354747F8C85D42CCB5"; //testing hash
bool found = false;

while (wordlist has next line && found == false){
        str = wordlist current line;
        string hashedStr = hash(str);
        if (hashedStr.compare(hash) == true){
                print("the plain text string is " + str);
                found = true
        }
        else {
                current line = next line;
        }




    //enter in wordList
    
    //While loop terminates when the list is done or a match has been found
    //while (wordlist is not empty && plaintext.compare(hash) == 0){}
    
    //if a match has been found, output the matched plaintext
    
    //else cout << "sorry no match found";
}

//brute force
void bruteForce(){
    cout << "how long would you like your maximum string to be?\n";
    int maxLength;
    cin >> maxLength;
    //making a command to give to system
    string strcmd = "crunch 1 " + to_string(maxLength) + " -o output.txt";
    cout << "\ngenerating strings\n";
    const char *command = strcmd.c_str();
    system(command);
    wordList();
}

bool hashCompare(string plaintext, string hash){

    string hashedString = md5(plaintext);

    cout << hashedString + "\n" + hash;

    return plaintext.compare(hash) == 0;
}
