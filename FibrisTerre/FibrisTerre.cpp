// FibrisTerre.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "MeasurementRepository.h"
#include "Utilities.h"


MeasurementRepository measurementRepository;

enum  Commands
{
    QUIT,
    NEW_MEASUREMENT,
    DISPLAY_ALL_MEASUREMENT,
    DELETE_MEASUREMENT,
    SWITCH_MEASUREMENT,
    SORT_MEASUREMENT,
    EXPORT_TO_FILE,
    IMPORT_FROM_FILE
    
};


void PrintNormalOutString() {

    std::cout <<
        "Welcome to Measurements Application\n\n"
        "To Enter new Measurement Enter 1\n"
        "To Display All Measurements Enter 2\n"
        "To Delete Existing Measurements Enter 3\n"
        "To Switch Positions of Measurements Enter 4\n"
        "To Sort All Measurements Enter Alphabetically Enter 5\n"
        "To export All Measurement to A file Entter 6\n"
        "To Import Measurement from file Enter 7\n";
    "To Quit Enter 0";
}

void AddNewMeasurement() {

    std::cin.ignore();
    std::cout << "Add New Measurement in this format or Enter to Exit\n"
        "Key(string) Length(uint32) 693,369,365.25,558.5\n";

    char measurement[256];

     std::cin.getline(measurement,256);

     std::shared_ptr<Measurement> newMeasurement = Utilities::GetMeasurementFromString(measurement);

     if (newMeasurement != nullptr) {
         measurementRepository.saveMeasurement(*newMeasurement);
         AddNewMeasurement();
     }

     if (newMeasurement == nullptr) {
     
         std::cout << "\n\nInvalid Measurement Format\n\n";
         
     }

     PrintNormalOutString();

}

void DeleteMeasurement() {

    std::cin.ignore();
    std::cout << "Please Enter the Measurement Key to be deleted\n";

    char measurement[256];

    std::cin.getline(measurement, 256);

    bool deleted =  measurementRepository.deleteMeasurementByName(measurement);

    
    if (deleted) {

        std::cout << "\n\nKey can't be found\n\n";

    }

    PrintNormalOutString();

}


void displayAllMeasurement() {

    std::cin.ignore();

    auto it = measurementRepository.getAllMeasurements().begin();

    std::cout << "-----------------------------------------------------------\n";

    while (it != measurementRepository.getAllMeasurements().end())
    {
        std::cout << it->second.toString() << '\n';


        it++;
    }
    
    std::cout << "-----------------------------------------------------------\n";

    PrintNormalOutString();

}

void saveMeasurementToFile() {

    std::cin.ignore();

   measurementRepository.saveMeasurementsToFile("output.test");

    std::cout << "----------------------Measurements have been saved to output.test -------------\n";

    std::cout << "-----------------------------------------------------------\n";

    PrintNormalOutString();

}

void ImportMeasurementFromFile() {

    std::cin.ignore();

    measurementRepository.loadMeasurementsFromFile("output.test");

    std::cout << "----------------------Measurements have been loaded from put.test -------------\n";

    std::cout << "-----------------------------------------------------------\n";

    PrintNormalOutString();

}



int main()
{


 
    PrintNormalOutString();

        char command;
        int CommandInex = -1;
        while (std::cin.get(command)) {

            CommandInex = command - 48;

            switch (CommandInex)
            {
            case QUIT:
                return 0;

            case NEW_MEASUREMENT:
                AddNewMeasurement();
                break;

            case DISPLAY_ALL_MEASUREMENT:
                displayAllMeasurement();
                break;

            case DELETE_MEASUREMENT:
                DeleteMeasurement();
                break;

            case SORT_MEASUREMENT:

                break;

            case EXPORT_TO_FILE:
                saveMeasurementToFile();
                break;

            case IMPORT_FROM_FILE:
                ImportMeasurementFromFile();
                break;


            default:
                break;
            }

        }

     //    std::string command;

       
     //    std::getline(std::cin, command);


        return 0;
}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
