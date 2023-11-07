/*Computer Monitoring Lab
 * Professor Dakota Hernandez
 * Name: Sakif Chowdhury
 * Date: 10/12/2023
 */
 
 #include <iostream>

const int NUM_LABS = 4;

// Function to initialize the lab arrays
void createArrays(int* labs[], int labsizes[]) {
    for (int i = 0; i < NUM_LABS; i++) {
        labs[i] = new int[labsizes[i]];
        for (int j = 0; j < labsizes[i]; j++) {
            labs[i][j] = 0; // Initialize all stations as empty (0)
        }
    }
}


void freeArrays(int* labs[]) {
    for (int i = 0; i < NUM_LABS; i++) {
        delete[] labs[i]; 
    }
}

// Function to search for a user in the lab
void search(int* labs[], int labsizes[]) {
    int userID;
    std::cout << "Enter the 5 digit ID number of the user to search for: ";
    std::cin >> userID;

    for (int i = 0; i < NUM_LABS; i++) {
        for (int j = 0; j < labsizes[i]; j++) {
            if (labs[i][j] == userID) {
                std::cout << "User " << userID << " is in Lab " << (i + 1) << " at computer " << (j + 1) << "\n";
                return;
            }
        }
    }
    std::cout << "User " << userID << " is not logged in.\n";
}

// Function to log in a user
void login(int* labs[], int labsizes[]) {
    int userID, labNum, compNum;
    std::cout << "Enter the 5 digit ID number of the user logging in: ";
    std::cin >> userID;
    std::cout << "Enter the lab number the user is logging in from (1-4): ";
    std::cin >> labNum;
    std::cout << "Enter computer station number the user is logging in to (1-" << labsizes[labNum - 1] << "): ";
    std::cin >> compNum;

    if (labNum >= 1 && labNum <= NUM_LABS && compNum >= 1 && compNum <= labsizes[labNum - 1]) {
        if (labs[labNum - 1][compNum - 1] == 0) {
            labs[labNum - 1][compNum - 1] = userID;
            std::cout << "User " << userID << " logged in Lab " << labNum << " at computer " << compNum << "\n";
        } else {
            std::cout << "Computer station " << compNum << " in Lab " << labNum << " is already in use.\n";
        }
    } else {
        std::cout << "Invalid input. Please check lab and computer station numbers.\n";
    }
}

// Function to log out a user
void logout(int* labs[], int labsizes[]) {
    int userID;
    std::cout << "Enter the 5 digit ID number of the user logging out: ";
    std::cin >> userID;

    for (int i = 0; i < NUM_LABS; i++) {
        for (int j = 0; j < labsizes[i]; j++) {
            if (labs[i][j] == userID) {
                labs[i][j] = 0; // Log the user out
                std::cout << "Logout user " << userID << " in Lab " << (i + 1) << " at computer " << (j + 1) << "\n";
                return;
            }
        }
    }
    std::cout << "User " << userID << " is not logged in.\n";
}

// Function to display the status of all labs
void showLabs(int* labs[], int labsizes[]) {
    std::cout << "LAB STATUS\n";
    for (int i = 0; i < NUM_LABS; i++) {
        std::cout << "Lab " << (i + 1) << ":\n";
        for (int j = 0; j < labsizes[i]; j++) {
            std::cout << j + 1 << ": ";
            if (labs[i][j] == 0) {
                std::cout << "empty ";
            } else {
                std::cout << labs[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    int* labs[NUM_LABS];
    int labsizes[NUM_LABS];

    std::cout << "Welcome to the LabMonitorProgram!\n";
    for (int i = 0; i < NUM_LABS; i++) {
        std::cout << "How many computers in Lab " << (i + 1) << "? ";
        std::cin >> labsizes[i];
    }

    createArrays(labs, labsizes);

    int choice = -1;
    while (choice != 0) {
        std::cout << "\nMAIN MENU\n";
        std::cout << "0) Quit\n1) Simulate login\n2) Simulate logout\n3) Search\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Bye!\n";
                break;
            case 1:
                login(labs, labsizes);
                break;
            case 2:
                logout(labs, labsizes);
                break;
            case 3:
                search(labs, labsizes);
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        showLabs(labs, labsizes);
    }

    freeArrays(labs);
    return 0;
}
