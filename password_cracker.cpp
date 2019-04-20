#include <iostream>

using namespace std;

int main(){
	std::cout << "Welcome to the C++ password cracker\n";
	std::cout << "Would you like to use a wordlist?\n (y/n)";
    
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
    
}

//brute force
void bruteForce(){
    
}
