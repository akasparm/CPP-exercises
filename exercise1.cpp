//---------------------------------------------Importing the required libraries-------------------------------------------------
#include <iostream>
using namespace std;

//-----------------------------------------------------main() function----------------------------------------------------------
int main(){
    char trial;

    do {                                                                                                    //do_while loop for trying the whole program again
        cout << "-------------------------------------\n";
        cout << "EXERCISE 1\n";

//----------------------------------------------------Input for part----------------------------------------------------------
        char part;
        do{                                                                                                 //do_while loop to check the validity within 'c','b','p'
            cout << "-------------------------------------\n";
            cout << "Which part to pick up (c, b, p)? ";
            cin >> part;
        }
        while(!(part == 'c' || part == 'b' || part == 'p'));

//----------------------------------------------------Input for gripper----------------------------------------------------------
        char gripper;                                                                                       //do_while loop to check the validity within 's', 'f'
            do{
                cout << "-------------------------------------\n";
                cout << "Which gripper to use (s, f)? ";
                cin >> gripper;
            }
            while(!(gripper == 's' || gripper == 'f'));

        int temp{1};

//------------------------------switch cases for failure combinations of 'c','b','p' with 's','f'-------------------------------
        switch(int(part)){     

            case int('c'):
                if(gripper == 's'){
                    cout << "-------------------------------------\n";
                    cout << "Failure: Cannot pick up the cube with the suction gripper.\n";
                    temp = 0;
                }
                break;
                
            case int('b'):          
                if(gripper == 'f'){
                    cout << "-------------------------------------\n";
                    cout << "Failure: Cannot pick up the ball with the finger gripper.\n";
                    temp = 0;
                }
                break;

            case int('p'):          
                if(gripper == 's'){
                    cout << "-------------------------------------\n";
                    cout << "Failure: Cannot pick up the peg with the suction gripper.\n";
                    temp = 0;
                }
                break;                
        }

//----------------------------------------------------Input for table------------------------------------------------------------
        if(temp){
            char table;
        do{                                                                                                 //do_while loop to check the validity within 'r', 'g', 'b'
                cout << "-------------------------------------\n";
                cout << "Which table to use (r, g, b)? ";
                cin >> table;
            }
            while(!(table == 'r' || table == 'g' || table == 'b'));
        
        
            string part_temp;

            if(part == 'c'){
                part_temp = "cube";
            }
            else if (part == 'b'){
                part_temp = "ball";
            }
            else{
                part_temp = "peg";
            }

            string table_temp;
            
            if(table == 'r'){
                table_temp = "red";
            }
            else if (table == 'g'){
                table_temp = "green";
            }
            else{
                table_temp = "blue";
            }
                
//------------------------------switch cases for successful combinations of 'c','b','p' with 's','f'------------------------------
            int temp_2 = 1;
            switch(int(table)){
                
                case int('r'):
                    if(part == 'c'){
                        cout << "-------------------------------------\n";
                        cout << "Success: The cube was placed on the red table.\n";
                        temp_2 = 0;
                    }
                    break;

                case int('g'):
                    if(part == 'b'){
                        cout << "-------------------------------------\n";
                        cout << "Success: The ball was placed on the green table.\n";
                        temp_2 = 0;
                    }
                    break;

                case int('b'):
                    if(part == 'p'){
                        cout << "-------------------------------------\n";
                        cout << "Success: The peg was placed on the blue table.\n";
                        temp_2 = 0;
                    }
                    break;
            }

//--------------------------switch cases for remaining failure combinations of 'c','b','p' with 's','f'--------------------------------
            if(temp_2){
                cout << "-------------------------------------\n";
                cout << "Failure: Cannot place the " << part_temp << " on the " << table_temp << " table.\n";
            }
            
        }

//---------------------------------------------------Trial for the whole program-------------------------------------------------------
        do{                                                                                                 //do_while loop for the valid input
            cout << "-------------------------------------\n";
            cout << "Try again (y, n)? ";
            cin >> trial;
            cout << "\n";
        }
        while(!(trial== 'y' || trial== 'n'));
    }
        while(trial!='n');

    return 0;
}