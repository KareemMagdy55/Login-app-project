#include <iostream>
#include <regex>
#include <conio.h>
#include <fstream>

using namespace std ;

void passwordConditions();
void strongPassword();
string passwordPreview();
void storeInfo(bool infoValid, string userProfile, string ID , string password, const char *usersDBname);

int main() {

    return 0;
}

void passwordConditions(){
    cout << "Password must require at least one of the following:\n"
            "\n"
            "1.Uppercase and lowercase letter (A, z)\n"
            "2.Numeric character (0-9)\n"
            "3.Special character (any character your environment will accept that is not an uppercase or a"
            " lowercase letter or a numeric character, for example ( !, %, @, #, and so on).\n";
}


void strongPassword(string password){
    regex strongForm ("(?:[a-z]+[A-Z]+)|(?:[A-Z]+[a-z]+)|\\W+|(?:[A-Za-z]+[0-9]+)" );

    if (regex_search(password, strongForm )){

        cout << "strong form";

    }else cout << "weak form";

}
string passwordPreview() {
    // this function decrypt password with ****
    string userKey;
    string password;
    int i = 0;
    cout << "\nPlease enter your password :";

    while (1){
        userKey[i] = getch();

        if (userKey[i] == '\r') break;
        if (userKey[i] != '\b') {
            password += userKey[i];
            cout << '*';
            i++;
        }else{
            if (i != 0) {
                cout << "\b \b";
                i--;
            }
        }
    }

    return password;
}
void storeInfo(bool infoValid, string userProfile, string ID , string password, const char *usersDBname) {
    ofstream usersDB;
    usersDB.open(usersDBname, std::ios::out|std::ios::app);
    if (infoValid && usersDB.is_open()) {
        usersDB << userProfile << '\t' << password << '\t' << ID << endl;
    }
    usersDB.close();
}
