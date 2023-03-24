//---------------------------------------------Importing the required libraries-------------------------------------------------
#include<iostream>
#include<vector>
#include<sstream>
#include<stdio.h>
#include<string>
#include<array>
using namespace std;

//-----------------------------------------------------main() function----------------------------------------------------------
int main(){

    char trial;                                                                                                
    do {                                                                                                        //do_while loop for trying the whole program again
        cout << "-----------------------------------------------------";
        cout << "\nEXERCISE 2";

        int vacancy = 0;                                                                                        //to check the vacancy in array
        int invalid;                                                                                            //to check the validity of input
 
        array<array<int, 3>, 3> slots{{                                                                         //2D array of 3*3
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        }};

//--------------------------------------------Printing the availability in 2D array------------------------------------------------
        cout << "\n-----------------------------------------------------\n";
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout << slots.at(i).at(j) << " ";               
            }       
            cout << "\n";
        }

//--------------------------------------------------------Red Peg yes/no-------------------------------------------------------------
        char red_peg;
        cout << "\n-----------------------------------------------------\n";
        do{                                                                                                     //do_while loop for valid input
            cout << "Do you want to place red pegs (y, n)? ";
            cin >> red_peg;
        }
        while(!(red_peg == 'y' || red_peg == 'n'));

        vector<int> track_record{};                                                                             //to keep the track of filled places

//-----------------------------------------------------Available Red Peg places-------------------------------------------------------------
        if(red_peg == 'y'){
            do{
                invalid = 0;
                string red_input_slots{};
                cout << "Where to place red pegs(1-9)? ";
                getline(cin >> ws, red_input_slots);

//-----------------------------------------------------Input for red peg places-------------------------------------------------------------

                string temp;
                stringstream s(red_input_slots);
                while(getline(s, temp, ' ')) {
                    int i{0}, swtch(0);
                    while(i<3){
                        int j(0);
                        while(j<3){
                            
                            //Checking validity within 1-9 digits
                            if(!(stoi(temp) == 1 || stoi(temp) == 2 || stoi(temp) == 3 || stoi(temp) == 4 ||
                            stoi(temp) == 5 || stoi(temp) == 6 || stoi(temp) == 7 || stoi(temp) == 8 || stoi(temp) == 9)){
                                invalid = 1;
                                break;
                            }
                            
                            //Replacing the input places
                            if(stoi(temp) == slots.at(i).at(j)){
                                slots.at(i).at(j) = 0;
                                track_record.push_back(stoi(temp));
                                swtch = 1;
                                break;
                            }
                        j++;
                        }
                        if(swtch || invalid){
                            break;
                        }
                    i++;
                    }
                }
            }
            while(invalid);  
            cout << "-----------------------------------------------------";
        }

//------------------------------------------------Printing the updated 2D array-----------------------------------------------------
        cout << "\n";     
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(slots.at(i).at(j) != 0){
                    cout << slots.at(i).at(j) << " ";
                    vacancy = 1;
                }else{
                    cout << "r" << " ";
                }
            }       
            cout << "\n";
        }

//----------------------------------------------------Green Peg yes/no-----------------------------------------------------------
        if (vacancy){
            vacancy = 0;
            char green_peg;
            do{
                cout << "\n";
                cout << "\nDo you want to place green pegs (y, n)? ";
                cin >> green_peg;
            }
            while(!(green_peg == 'y' || green_peg == 'n'));

//------------------------------------------------Available green Peg places------------------------------------------------------
            do{
                invalid = 0;
                if(green_peg == 'y'){
                    cout << "Where to place green pegs (";
                    int i{0};
                    vector<int> temp_2;
                    while(i<3){
                        int j(0);
                        while(j<3){
                            if(slots.at(i).at(j) != 0){
                                temp_2.push_back(slots.at(i).at(j));
                            }
                            j++;
                        }
                        i++;
                    }
                    for(int a = 0; a<temp_2.size()-1; a++){
                        cout << temp_2.at(a) << ", ";
                    }
                    cout << temp_2[temp_2.size()-1]<< ")?";
                    

//-----------------------------------------------Input for green peg places---------------------------------------------------------
                    string green_input_slots{};
                    string temp;
                    getline(cin >> ws, green_input_slots);
                    stringstream s(green_input_slots);

                    while (getline(s, temp, ' ')) {
                        int i{0}, swtch(0);
                        while(i<3){
                            int j(0);
                            while(j<3){

                                //Checking validity within 1-9 digits
                                if(!(stoi(temp) == 1 || stoi(temp) == 2 || stoi(temp) == 3 || stoi(temp) == 4 ||
                                stoi(temp) == 5 || stoi(temp) == 6 || stoi(temp) == 7 || stoi(temp) == 8 || stoi(temp) == 9)){
                                    invalid = 1;
                                    break;
                                }

                                //Checking validity for used places
                                for(int a=0; a<track_record.size(); a++){
                                    if(stoi(temp) == track_record.at(a)){
                                        invalid = 1;
                                        break;
                                    }
                                }   
                                if(invalid){
                                    break;
                                }

                                //Replacing the input places
                                if(stoi(temp) == slots.at(i).at(j)){
                                    slots.at(i).at(j) = -1;
                                    track_record.push_back(stoi(temp));
                                    swtch = 1;
                                    break;
                                }
                                j++;
                            }
                            if(swtch || invalid){
                                break;
                            }
                        i++;
                        }
                    }    
                }
                else{
                    cout << "-----------------------------------------------------";
                }
            }
            while(invalid);
            cout << "-----------------------------------------------------";



//------------------------------------------------Printing the updated 2D array-----------------------------------------------------
            
            cout << "\n";
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(slots.at(i).at(j) == 0){
                        cout << "r" << " ";
                    }
                    else if(slots.at(i).at(j) == -1){
                        cout << "g" << " ";
                    }
                    else{
                        cout << slots.at(i).at(j) << " ";
                        vacancy = 1;
                    }
                }       
                cout << "\n";
            }


        }
        
//-----------------------------------------------------Blue Peg yes/no--------------------------------------------------------------
        if(vacancy){
            char blue_peg;
            cout << "\n";
            do{                
                cout << "Do you want to place blue pegs (y, n)? ";
                cin >> blue_peg;
            }
            while(!(blue_peg == 'y' || blue_peg == 'n'));

//--------------------------------------------------Available blue Peg places-------------------------------------------------------
            if(blue_peg == 'y'){
                do{
                    invalid = 0;                
                    cout << "Where to place blue pegs (";                    
                    int i = 0;
                    vector<int> temp_3;
                    
                    while(i<3){
                        int j(0);
                        while(j<3){
                            if(!(slots.at(i).at(j) == 0 || slots.at(i).at(j)== -1)){
                                temp_3.push_back(slots.at(i).at(j));
                            }
                            j++;
                        }
                        i++;
                    }
                    for(int a = 0; a<temp_3.size()-1; a++){
                        cout << temp_3.at(a) << ", ";
                    }
                    cout << temp_3[temp_3.size()-1]<< ")?";

//-------------------------------------------------Input for blue peg places----------------------------------------------------------
                    string blue_input_slots{};
                    string temp;
                    getline(cin >> ws, blue_input_slots);
                    stringstream s(blue_input_slots);
                    
                    while (getline(s, temp, ' ')) {
                        int i{0}, swtch(0);
                        while(i<3){
                            int j(0);
                            while(j<3){
                                
                                //Checking the validity within 1-9 digits
                                if(!(stoi(temp) == 1 || stoi(temp) == 2 || stoi(temp) == 3 || stoi(temp) == 4 ||
                                stoi(temp) == 5 || stoi(temp) == 6 || stoi(temp) == 7 || stoi(temp) == 8 || stoi(temp) == 9)){
                                    invalid = 1;
                                    break;
                                }

                                //Checking validity for used places
                                for(int a=0; a<track_record.size(); a++){
                                    if(stoi(temp) == track_record.at(a)){
                                        invalid = 1;
                                        break;
                                    }
                                }
                                if(invalid){
                                    break;
                                }
                                
                                //Replacing the input places
                                if(stoi(temp) == slots.at(i).at(j)){
                                    slots.at(i).at(j) = -2;
                                    track_record.push_back(stoi(temp));
                                    swtch = 1;
                                    break;
                                }
                                j++;
                            }
                            if(swtch){
                                break;
                            }
                        i++;
                        }
                    }
                }
                while(invalid);
                cout << "-----------------------------------------------------";
            }
            else{
                cout << "-----------------------------------------------------";
            }

//------------------------------------------------Printing the updated 2D array-----------------------------------------------------
            cout << "\n";
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(slots.at(i).at(j) == 0){
                        cout << "r" << " ";
                    }
                    else if(slots.at(i).at(j) == -1){
                        cout << "g" << " ";
                    }
                    else if(slots.at(i).at(j) == -2){
                        cout << "b" << " ";
                    }
                    else{
                        cout << slots.at(i).at(j) << " ";
                    }
                }       
                cout << "\n";
            }

        }

//--------------------------------------------------Trial for the whole program------------------------------------------------------
        cout << "-----------------------------------------------------";
        do{                                                                                                     //do_while loop for valid input
            cout << "\nTry again (y, n)? ";
            cin >> trial;
        }
        while(!(trial== 'y' || trial== 'n'));
        cout << "\n";
    }    
    while(trial!='n');
    
    return 0;    
}