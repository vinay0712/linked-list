#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main() {
    ofstream file;
    file.open("output.txt");

    if (file.is_open()) {
        file << "HELLO." << endl;
        file << "WORLD." << endl;
        cout << "Text written to the file successfully." << endl;
        file.close();
    } else {
        cout << "Could not open the file." << endl;
        return 1;
    }

    ifstream file_in("output.txt");
    vector<string> lines;

    if (file_in.is_open()) {
        string line;
        while (getline(file_in, line)) {
            lines.push_back(line);
        }
        file_in.close();
    } else {
        cout << "Could not open the file for reading." << endl;
        return 1;
    }

    cout << "The contents of the file in reverse order are :" << endl;
    reverse(lines.begin(), lines.end());
    for (int i = 0; i < lines.size(); ++i) {
    cout << lines[i] << endl;
}


    return 0;
}
