#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ofstream file("output.txt");
    file << " hello" << endl;
    file << "world." << endl;
    file.close();

    ifstream read_obj("output.txt", ios::binary | ios::ate);
    if (read_obj.is_open()) {
        int length = read_obj.tellg();
        char *array = new char[length];
        read_obj.seekg(0, ios::beg);
        read_obj.read(array, length);
        read_obj.close();

        reverse(array, array + length);
          for (int i = 0; i < length; i++) {
        cout << array[i];
    }
        cout << endl;
        delete[] array;
    } else {
        cout << "Could not open the file for reading." << endl;
        return 1;
    }

    return 0;
}
