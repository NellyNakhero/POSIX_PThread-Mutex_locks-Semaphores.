#include <iostream>
#include <fstream>

using namespace std;

int main() {

    double data[100];
    int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0, count_5 = 0, count_6 = 0, count_7 = 0, count_8 = 0, count_9 = 0, count_10 = 0;

    //reads from a file
    std::ifstream input("example.txt");

    //Read 100 integers from given input file
    for (int i = 0; i < 100; i++) {
        input >> data[i];

        //Identify the group (bin) that it belongs to, and
        //Increment the respective group count.
        if (data[i] > 0 && data[i] < 10)
        {
            count_1++;
        }
        else if (data[i] < 20)
        {
            count_2++;
        }
        else if (data[i] < 30)
        {
            count_3++;
        }
        else if (data[i] < 40)
        {
            count_4++;
        }
        else if (data[i] < 50)
        {
            count_5++;
        }
        else if (data[i] < 60)
        {
            count_6++;
        }
        else if (data[i] < 70)
        {
            count_7++;
        }
        else if (data[i] < 80)
        {
            count_8++;
        }
        else if (data[i] < 90)
        {
            count_9++;
        }
        else if (data[i] < 100)
        {
            count_10++;
        }
        else
        {
         std::cout<< "Group DNE: "  <<std::endl;   
        }
        
        
        // std::cout<< data[i]<<std::endl;
        }

        std::cout<< "Group 1 (0..9) Count: " << count_1 <<std::endl;
        std::cout<< "Group 2 (10..19) Count: " << count_2 <<std::endl;
        std::cout<< "Group 3 (20..29) Count: " << count_3 <<std::endl;
        std::cout<< "Group 4 (30..39) Count: " << count_4 <<std::endl;
        std::cout<< "Group 5 (40..49) Count: " << count_5 <<std::endl;
        std::cout<< "Group 6 (50..59) Count: " << count_6 <<std::endl;
        std::cout<< "Group 7 (60..69) Count: " << count_7 <<std::endl;
        std::cout<< "Group 8 (70..79) Count: " << count_8 <<std::endl;
        std::cout<< "Group 9 (80..89) Count: " << count_9 <<std::endl;
        std::cout<< "Group 10 (90..99) Count: " << count_10 <<std::endl;


        // std::cout<< count_1<<std::endl;

        // for(int j =0; j < 100; j++){
        //     std::cout << data[j] << ' ';
        // }

}