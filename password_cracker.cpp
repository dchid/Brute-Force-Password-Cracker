#include <iostream>
#include <fstream>
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
    
    //enter in wordList
    
    //While loop terminates when the list is done or a match has been found
    //while (wordlist is not empty && plaintext.compare(hash) == 0){}
    
    //if a match has been found, output the matched plaintext
    
    //else cout << "sorry no match found";
}

//brute force
void bruteForce(){
    
}
