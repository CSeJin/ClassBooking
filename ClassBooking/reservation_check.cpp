//reservation_check
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream reservation_file("reservation.txt");
    map<string, string> day_map = {
        {"1", "Mon"},
        {"2", "Tue"},
        {"3", "Wed"},
        {"4", "Thu"},
        {"5", "Fri"},
    };
    string line;
    bool found = false;
    while (getline(reservation_file, line)) {
        stringstream ss(line);
        string user_id, class_num_str, start_time, end_time, day_str;

        getline(ss, user_id, '\t');
        getline(ss, class_num_str, '\t');
        getline(ss, start_time, '\t');
        getline(ss, end_time, '\t');
        getline(ss, day_str, '\t');

        cout << user_id << " "
             << class_num_str << " " 
             << day_map[day_str] << " "
             << start_time << " " << end_time << " " << endl;
        
        found = true; // ���� ������ ã�����Ƿ� true�� ����
    }
    
    reservation_file.close();

    if (!found) {
        cout << "No reservation history found." << endl;
    }

    cout << "\npress any key to continue..." << endl;
    cin.get();

    return 0;
}
