#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string motherboardSocketType;

string motherboardRamType;
string motherboardStorageType;
string cpuSocketType;
string cpuRAMType;
int cpuWattage;
string ramType;
int coolerWattage;
string storageType;
int gpuWattage;
int powerSupplyMinWattage;
int powerSupplyMaxWattage;

bool parseCSVFile(const string& filename, vector<string>& componentList){
    ifstream file(filename);
    if (!file.is_open()){
        cout<<"The failed didn't open correctly"<<endl;
        return false;

    }
    string line;
    while (getline(file, line)){
        componentList.push_back(line);

    }
    file.close();
    return true;


}
int main(){
    vector<string> motherboardComponents;
    vector<string> cpuComponents;
    vector<string> ramComponents;
    vector<string> coolerComponents;
    vector<string> storageComponents;
    vector<string> gpuComponents;
    vector<string> powerSupplyComponents;

    parseCSVFile("components.csv", motherboardComponents);
    parseCSVFile("components.csv", cpuComponents);
    parseCSVFile("components.csv", ramComponents);
    parseCSVFile("components.csv", coolerComponents);
    parseCSVFile("components.csv", storageComponents);
    parseCSVFile("components.csv", gpuComponents);
    parseCSVFile("components.csv", powerSupplyComponents);
    
    bool parseSuccess = true;

    parseSuccess = parseCSVFile("components.csv", motherboardComponents);
    if (!parseSuccess) {
        // Handle error or exit the program
    }

    parseSuccess = parseCSVFile("components.csv", cpuComponents);
    if (!parseSuccess) {
        // Handle error or exit the program
    }

    // Repeat the above steps for each component type

    // Check if all parsing operations were successful
    if (parseSuccess) {
        // Parsing completed successfully
        cout << "Parsing completed successfully." << endl;
    } else {
        // Parsing failed for at least one component type
        cout << "Parsing failed." << endl;
    }

    return 0;
}