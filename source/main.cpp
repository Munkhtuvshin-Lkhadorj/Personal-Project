#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//CREDITS
//FILE PARSING : https://www.youtube.com/watch?v=NFvxA-57LLA
//STOI FUNCTION AND ITS USE: https://www.youtube.com/watch?v=NFvxA-57LLA


using namespace std;

class Component {
public:
    string property1;
    string property2;
    string property3;
    string property4;
    string property5;
    string property6;

    Component() = default;

    Component(const string& property1, const string& property2, const string& property3,
              const string& property4, const string& property5, const string& property6)
        : property1(property1), property2(property2), property3(property3),
          property4(property4), property5(property5), property6(property6) {
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
        string property1, property2, property3, property4, property5, property6;
        getline(ss, property1, ',');
        getline(ss, property2, ',');
        getline(ss, property3, ',');
        getline(ss, property4, ',');
        getline(ss, property5, ',');
        getline(ss, property6, ',');

        Component comp;
        comp.property1 = property1;
        comp.property2 = property2;
        comp.property3 = property3;
        comp.property4 = property4;
        comp.property5 = property5;
        comp.property6 = property6;

        componentList.push_back(comp);
    }

    file.close();
    return true;
}

void displayComponents(const vector<Component>& components) {
    for (size_t i = 0; i < components.size(); ++i) {
        cout << i + 1 << ". " << components[i].property1 << endl;
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
        return Component("", "", "", "", "", "");
    }
}
bool isRAMCompatible(const Component& selectedRAM, const Component& selectedMotherboard) {
    // Check if the DDR information matches
    return selectedRAM.property2 == selectedMotherboard.property4;
}

int main() { // Create vectors and get the values of CSV files and move it to the vectors
    vector<Component> motherboardComponents;
    vector<Component> cpuComponents;
    vector<Component> ramComponents;
    vector<Component> coolerComponents;
    vector<Component> storageComponents;
    vector<Component> gpuComponents;
    vector<Component> powerSupplyComponents;

    bool parseSuccess = parseCSVFile("motherboard.csv", motherboardComponents); // Motherboard components are passed to its corrosponding vector
    if (!parseSuccess) {
        cout << "Failed to parse the CSV file for Motherboard." << endl;
        return 1;
    }

    parseSuccess = parseCSVFile("cpu.csv", cpuComponents);// Cpu components are passed to its corrosponding vector
    if (!parseSuccess) {
        cout << "Failed to parse the CSV file for CPU." << endl;
        return 1;
    }

    parseSuccess = parseCSVFile("Ram.csv", ramComponents);// Ram components are passed to its corrosponding vector
    if (!parseSuccess) {
        cout << "Failed to parse the CSV file for RAM." << endl;
        return 1;
    }

    parseSuccess = parseCSVFile("Cooler.csv", coolerComponents);// Cooler components are passed to its corrosponding vector
    if (!parseSuccess) {
        cout << "Failed to parse the CSV file for Cooler." << endl;
        return 1;
    }

    parseSuccess = parseCSVFile("Storage.csv", storageComponents);// Storage components are passed to its corrosponding vector
    if (!parseSuccess) {
        cout << "Failed to parse the CSV file for Storage." << endl;
        return 1;
    }

    parseSuccess = parseCSVFile("Gpu.csv", gpuComponents);// Gpu components are passed to its corrosponding vector
    if (!parseSuccess) {
        cout << "Failed to parse the CSV file for GPU." << endl;
        return 1;
    }

    parseSuccess = parseCSVFile("PowerSupply.csv", powerSupplyComponents);// PSU components are passed to its corrosponding vector
    if (!parseSuccess) {
        cout << "Failed to parse the CSV file for Power Supply." << endl;
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
    cout << "Cooler:" << endl;
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

    //Checks for Ram compatibility
    bool ramCompatible = isRAMCompatible(selectedRAM, selectedMotherboard);
    // Display compatibility result
    if (ramCompatible) {
        cout << "The selected RAM is compatible with the chosen motherboard." << endl;
    } else {
        cout << "The selected RAM is not compatible with the chosen motherboard." << endl;
    }

    // Calculate the wattage of the selected components
    int totalWattage = 0;
        totalWattage += stoi(selectedCooler.property2); // Stoi function is used to convert String type integer to normal integer for calculation purpose Credit: https://www.youtube.com/watch?v=JuvyOJ1iVSM
        totalWattage += stoi(selectedGPU.property2);
        totalWattage += stoi(selectedCPU.property2);
        totalWattage += stoi(selectedMotherboard.property2);

        int selectedPowerSupplyWattage = stoi(selectedPowerSupply.property2);

        if (selectedPowerSupplyWattage >= totalWattage) {
            cout << "The wattage rate of your power supply is sufficient to handle the chosen components." << endl;
        } else {
            cout << "The wattage rate of your power supply is not sufficient to handle the chosen components. Expect crashes under load." << endl;
        }

    return 0;
}
