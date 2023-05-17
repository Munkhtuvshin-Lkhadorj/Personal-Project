#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Component {
public:
    string name;
    string socketType;
    string ramType;
    string property1; // Add properties as needed
    string property2;
    Component() = default;

    Component(const string& name, const string& socketType, const string& ramType)
        : name(name), socketType(socketType), ramType(ramType) {
    }
};

bool parseCSVFile(const string& filename, vector<Component>& componentList) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return false;
    }

    string line;
    getline(file, line);  // Skip the header row

    while (getline(file, line)) {
        stringstream ss(line);
        string category, name, socketType, ramType;
        getline(ss, category, ',');
        getline(ss, name, ',');
        getline(ss, socketType, ',');
        getline(ss, ramType, ',');

        Component comp;
        comp.name = name;
        comp.socketType = socketType;
        comp.ramType = ramType;

        componentList.push_back(comp);
    }

    file.close();
    return true;
}

void displayComponents(const vector<Component>& components) {
    for (size_t i = 0; i < components.size(); ++i) {
        cout << i + 1 << ". " << components[i].name << endl;
    }
}

Component selectComponent(const vector<Component>& components) {
    int choice;
    cout << "Enter the number corresponding to your choice: ";
    cin >> choice;

    // Subtract 1 to convert from user choice to vector index
    int index = choice - 1;
    if (index >= 0 && index < components.size()) {
        return components[index];
    } else {
        // Invalid choice, return an empty component
        return Component("", "", "");
    }
}

int main() {
    vector<Component> motherboardComponents;
    vector<Component> cpuComponents;
    vector<Component> ramComponents;
    vector<Component> coolerComponents;
    vector<Component> storageComponents;
    vector<Component> gpuComponents;
    vector<Component> powerSupplyComponents;

    bool parseSuccess = parseCSVFile("cpu.csv", cpuComponents);
    if (!parseSuccess) {
        cout << "Failed to parse the CSV file for CPU." << endl;
        return 1;
    }

    parseSuccess = parseCSVFile("motherboard.csv", motherboardComponents);
    if (!parseSuccess) {
        cout << "Failed to parse the CSV file Motherboard." << endl;
        return 1;
    }
    parseSuccess = parseCSVFile("Ram.csv", ramComponents);
    if (!parseSuccess) {
        cout << "Failed to parse the CSV Ram." << endl;
        return 1;
    }
    parseSuccess = parseCSVFile("Cooler.csv", coolerComponents);
    if (!parseSuccess) {
        cout << "Failed to parse the CSV Cooler." << endl;
        return 1;
    }
    parseSuccess = parseCSVFile("Storage.csv", storageComponents);
    if (!parseSuccess) {
        cout << "Failed to parse the CSV Storage." << endl;
        return 1;
    }
    parseSuccess = parseCSVFile("Gpu.csv", gpuComponents);
    if (!parseSuccess) {
        cout << "Failed to parse the CSV GPU." << endl;
        return 1;
    }
    parseSuccess = parseCSVFile("PowerSupply.csv", powerSupplyComponents);
    if (!parseSuccess) {
        cout << "Failed to parse the CSV PowerSupply." << endl;
        return 1;
    }


    // Display the available components and let the user choose one from each category
    cout << "Choose one component from each category:" << endl;

    // Motherboard
    cout << "Motherboard:" << endl;
    displayComponents(motherboardComponents);
    Component selectedMotherboard = selectComponent(motherboardComponents);
    cout << endl;

    // CPU
    cout << "CPU:" << endl;
    displayComponents(cpuComponents);
    Component selectedCPU = selectComponent(cpuComponents);
    cout << endl;

    // RAM
    cout << "RAM:" << endl;
    displayComponents(ramComponents);
    Component selectedRAM = selectComponent(ramComponents);
    cout << endl;

    // Cooler
    cout << "Cooler:" <<
    endl;
    displayComponents(coolerComponents);
    Component selectedCooler = selectComponent(coolerComponents);
    cout << endl;
    // Storage
    cout << "Storage:" << endl;
    displayComponents(storageComponents);
    Component selectedStorage = selectComponent(storageComponents);
    cout << endl;

    // GPU
    cout << "GPU:" << endl;
    displayComponents(gpuComponents);
    Component selectedGPU = selectComponent(gpuComponents);
    cout << endl;

    // Power Supply
    cout << "Power Supply:" << endl;
    displayComponents(powerSupplyComponents);
    Component selectedPowerSupply = selectComponent(powerSupplyComponents);
    cout << endl;

    // Do something with the selected components...

    return 0;
    }
