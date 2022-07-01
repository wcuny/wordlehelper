#include <iostream>
#include <iomanip>
#include <vector>
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET   "\033[0m"
#define FONT_INVERSE "\033[7m"
#define FONT_BOLD "\033[1m"
#define FONT_DEFAULT "\033[0m"
#define FONT_VOLATILE "\033[38;5;208m"
#define FONT_BOLD_VOLATILE "\033[1;38;5;208m"


using namespace std;

#include "wordle.h"
class poop{
    public:
        void letterFind(char, int, vector <string> &, int);
        void greyFind (char, vector <string> &, int);
        void yellowFind(char, int, vector <string> &, int);
        void yellowfindMore(char, int, vector <string> &, int);
};

void poop::letterFind (char letter, int position, vector <string> &deleteVec, int runtimeSize){
    int runTimes = 0;
    for (int i = 0; i < runtimeSize; i++){
        string temp = deleteVec.at(i - runTimes);
        if (temp[position] != letter){
            deleteVec.erase(deleteVec.begin() + (i - runTimes));
            runTimes++;
        }
    }
    cout << "#   " << "Deleted " << runTimes << " words." << endl;
}

void poop::greyFind (char letter, vector <string> &deleteVec, int runtimeSize){
    int runTimes = 0;
    for (int i = 0; i < runtimeSize; i++){
        string temp = deleteVec.at(i - runTimes);
        for (int j = 0; j < 5; j++){
            if(temp[j] == letter){
                deleteVec.erase(deleteVec.begin() + (i - runTimes));
                runTimes++;
                break;
            }
        }
    }
    cout << "#   " << "Deleted " << runTimes << " words." << endl; 
}

void poop::yellowFind (char letter, int position, vector <string> &deleteVec, int runtimeSize){
    int runTimes = 0;
    for (int i = 0; i < runtimeSize; i++){
        string temp = deleteVec.at(i - runTimes);
        if (temp[position] == letter){
            deleteVec.erase(deleteVec.begin() + (i - runTimes));
            runTimes++;
        }
    }
    cout << "#   " << "Deleted " << runTimes << " words." << endl;
}

void poop::yellowfindMore (char letter, int position, vector <string> &deleteVec, int runtimeSize){
    int runTimes = 0;
    for (int i = 0; i < runtimeSize; i++){
        bool yellower = false;
        string temp = deleteVec.at(i - runTimes);
        for (int j = 0; j < 5; j++){
            if (temp[j] == letter){
                yellower = true;
                break;
            }
        }
        if (yellower == false){
            deleteVec.erase(deleteVec.begin() + (i - runTimes));
            runTimes++;
        }
    }
    cout << "#   " << "Deleted " << runTimes << " words." << endl;
}

int main(){
    cout << "\e[8;50;43t";
    cout << "\033[2J\033[1;1H";
    vector <string> deleteVec = defaultWords;
    int runners = 2315;
    for (int runs = 0; runs < 6; runs++){
        if (runs == 0){
            cout << endl << "###########################################" <<
            endl <<      "##             \033[32mWORDLE HELPER\033[0m             ##" << endl 
            <<      "###########################################" << endl 
            << "#   " << endl;
        }
        else{
            cout << "------------------------------------------" << endl << "#   " << endl;
        }
        poop obj;
        cout << "#   " << "Enter guess: " << endl;
        string guess;
        cout << "#   ";
        cin >> guess;
        cout << "\033[2J\033[1;1H";
        cout << 
        endl <<"###########################################" <<
        endl <<"##             \033[32mWORDLE HELPER\033[0m             ##" << 
        endl << "###########################################" << 
        endl << "#   " << endl;
        bool callable = true;
        bool callable2 = true;
        bool callable3 = true;

        cout << "#   " << FONT_BOLD_VOLATILE << setw(5) << guess[0] << "  " 
        << guess[1] << "  " 
        << guess[2] << "  "
        << guess[3] << "  " 
        << guess[4] << FONT_DEFAULT << endl;
        cout << "#   " << "    " << "^  ^  ^  ^  ^" << endl;
        cout << "#   " << "    " << "0  1  2  3  4" << endl;
        cout << "#   " << GREEN << "\033[7mGreen letters:\033[7m" << endl << RESET;
        cout << "#   " << " -1 = none" << endl << "#   " << " -2 = done" << endl;
        bool check = true;
        vector <int> vec;
        string checker;
        while (check == true){
            int num;
            cout << "#   " << "              ";
            cin >> num;
            if (num == -1){
                check = false;
                callable = false;
                break;
            }
            else if (num == -2){
                check = false;
                break;
            }
            else{
                vec.push_back(num);
            }
        }
        if (callable == true){
            for (int i = 0; i < vec.size(); i++){
                obj.letterFind(guess.at(vec.at(i)), vec.at(i), deleteVec, runners);
                runners = deleteVec.size();
            }
        }
        cout << "\033[2J\033[1;1H";
        cout << 
        endl <<"###########################################" <<
        endl <<"##             \033[32mWORDLE HELPER\033[0m             ##" << 
        endl << "###########################################" << 
        endl << "#   " << endl;

        cout << "#   " << endl;
        cout << "#   " << FONT_BOLD_VOLATILE << setw(5) << guess[0] << "  " 
        << guess[1] << "  " 
        << guess[2] << "  "
        << guess[3] << "  " 
        << guess[4] << FONT_DEFAULT << endl;
        cout << "#   " << "    " << "^  ^  ^  ^  ^" << endl;
        cout << "#   " << "    " << "0  1  2  3  4" << endl;
        cout << "#   " << "\033[7mGrey letters:\033[7m" << FONT_DEFAULT << endl;
        cout << "#   " << " -1 = none" << endl << "#   " << " -2 = done" << endl;
        bool check2 = true;
        vector <int> vec2;
        string checker2;
        while (check2 == true){
            int num2;
            cout << "#   " << "              ";
            cin >> num2;
            if (num2 == -1){
                callable2 = false;
                check2 = false;
                break;
            }
            else if(num2 == -2){
                check2 = false;
                break;
            }
            else{
                vec2.push_back(num2);
            }
        } 
        if (callable2 == true){
            for (int x = 0; x < vec2.size(); x++){
                obj.greyFind(guess.at(vec2.at(x)), deleteVec, runners);
                runners = deleteVec.size();
            }
        }
        cout << "\033[2J\033[1;1H";
        cout << 
        endl <<"###########################################" <<
        endl <<"##             \033[32mWORDLE HELPER\033[0m             ##" << 
        endl << "###########################################" << 
        endl << "#   " << endl;

        cout << "#   " << endl;
        cout << "#   " << FONT_BOLD_VOLATILE << setw(5) << guess[0] << "  " 
        << guess[1] << "  " 
        << guess[2] << "  "
        << guess[3] << "  " 
        << guess[4] << FONT_DEFAULT << endl;
        cout << "#   " << "    " << "^  ^  ^  ^  ^" << endl;
        cout << "#   " << "    " << "0  1  2  3  4" << endl;
        cout << "#   " << YELLOW << "\033[7mYellow letters:\033[7m" << FONT_DEFAULT << endl << RESET;
        cout << "#   " << " -1 = none" << endl << "#   " << " -2 = done" << endl;
        bool check3 = true;
        vector <int> vec3;
        string checker3;
        while (check3 == true){
            int num3;
            cout << "#   " << "              ";
            cin >> num3;
            if (num3 == -1){
                callable3 = false;
                check3 = false;
                break;
            }
            else if(num3 == -2){
                check3 = false;
                break;
            }
            else{
                vec3.push_back(num3);
            }
        } 
        if (callable3 == true){
            for (int t = 0; t < vec3.size(); t++){
                obj.yellowFind(guess.at(vec3.at(t)), vec3.at(t), deleteVec, runners);
                runners = deleteVec.size();
            }
        }
        if (callable3 == true){
            for (int t = 0; t < vec3.size(); t++){
                obj.yellowfindMore(guess.at(vec3.at(t)), vec3.at(t), deleteVec, runners);
                runners = deleteVec.size();
            }
        }
        
        cout << "\033[2J\033[1;1H";
        cout << 
        endl <<"###########################################" <<
        endl <<"##             \033[32mWORDLE HELPER\033[0m             ##" << 
        endl << "###########################################" << 
        endl << "#   " << endl;

        cout << "#   " << endl << "#   " << endl;
        cout << "#   " << "Possible Words:" << endl;
        for (int j = 0; j < deleteVec.size(); j++){
            //every 5 words, new line
            if (j % 5 == 0 && j != 0){
                cout << endl << "#   ";
            }
            if (j == 0){
                cout << "#   ";
            }
            cout << FONT_BOLD << BLUE << deleteVec.at(j) << " " << RESET;
            cout << FONT_DEFAULT;
        }
        cout << endl << "#   " << "Number of Possible Words: " << deleteVec.size() << endl << endl;
        vec.clear();
        vec2.clear();
        vec3.clear();
    }
    return 0;
 }
