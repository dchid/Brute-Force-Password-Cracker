#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    cout << "Welcome to the C++ password cracker\n";
    cout << "please input the hashed password you'd like to crack\n";
    string inputHash;
    cin >> inputHash;
    cout << "you entered " + inputHash + "\n";
	cout << "Would you like to use a wordlist?\n (y/n)";
    
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

	}

//brute force
void bruteForce(){
    
}
