#include <iostream>
#include <regex>

using namespace std ;

void passwordConditions();
void strongPassword();
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
