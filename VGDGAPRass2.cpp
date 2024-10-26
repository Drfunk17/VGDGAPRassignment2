#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class Character {
private:
    string name;
    string ancestry;
    string characterClass;
    int strength, dexterity, constitution, wisdom, intelligence, charisma;

public:
    Character() : strength(0), dexterity(0), constitution(0), wisdom(0), intelligence(0), charisma(0) {}

    // Function to set the character's name with validation
    void setName() {
        do {
            cout << "Enter character name (1-10 characters): ";
            getline(cin, name);
            if (name.empty() || name.length() > 10) {
                cout << "Invalid name! Please enter a name with 1-10 characters.\n";
            }
        } while (name.empty() || name.length() > 10);
    }

    // Function to select ancestry with bonus application
    void setAncestry() {
        vector<string> ancestries = { "Human", "Elf", "Minotaur", "Satyr", "Nymph" };
        int choice;

        do {
            cout << "\nChoose your ancestry:\n";
            for (size_t i = 0; i < ancestries.size(); ++i) {
                cout << i + 1 << ". " << ancestries[i] << endl;
            }
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            if (choice < 1 || choice > 5) {
                cout << "Invalid choice. Please select a valid ancestry.\n";
            }
        } while (choice < 1 || choice > 5);

        ancestry = ancestries[choice - 1];
        applyAncestryBonuses();
    }

    // Function to set character class
    void setClass() {
        vector<string> classes = { "Warrior", "Mage", "Hunter", "Priest", "Bard" };
        int choice;

        do {
            cout << "\nChoose your class:\n";
            for (size_t i = 0; i < classes.size(); ++i) {
                cout << i + 1 << ". " << classes[i] << endl;
            }
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            if (choice < 1 || choice > 5) {
                cout << "Invalid choice. Please select a valid class.\n";
            }
        } while (choice < 1 || choice > 5);

        characterClass = classes[choice - 1];
    }

    // Function to generate ability scores in range 8-18
    void generateAbilityScores() {
        srand(static_cast<unsigned>(time(0)));
        strength = rand() % 11 + 8;
        dexterity = rand() % 11 + 8;
        constitution = rand() % 11 + 8;
        wisdom = rand() % 11 + 8;
        intelligence = rand() % 11 + 8;
        charisma = rand() % 11 + 8;
    }

    // Apply ancestry bonuses
    void applyAncestryBonuses() {
        if (ancestry == "Human") {
            constitution += 2;
            cout << "Human bonus applied: +2 to Constitution\n";
        }
        else if (ancestry == "Elf") {
            dexterity += 3;
            cout << "Elf bonus applied: +3 to Dexterity\n";
        }
        else if (ancestry == "Minotaur") {
            strength += 4;
            cout << "Minotaur bonus applied: +4 to Strength\n";
        }
        else if (ancestry == "Satyr") {
            charisma += 2;
            cout << "Satyr bonus applied: +2 to Charisma\n";
        }
        else if (ancestry == "Nymph") {
            wisdom += 3;
            cout << "Nymph bonus applied: +3 to Wisdom\n";
        }
    }

    // Display character details
    void displayCharacter() const {
        cout << "\nCharacter Details:\n";
        cout << "Name: " << name << endl;
        cout << "Ancestry: " << ancestry << endl;
        cout << "Class: " << characterClass << endl;
        cout << "Strength: " << strength << endl;
        cout << "Dexterity: " << dexterity << endl;
        cout << "Constitution: " << constitution << endl;
        cout << "Wisdom: " << wisdom << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Charisma: " << charisma << endl;
    }
};

int main() {
    Character character;
    int choice;

    do {
        cout << "\nGreek Mythology RPG Character Creation\n";
        cout << "1. Create a new character\n";
        cout << "2. Display character\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            character.setName();
            character.setAncestry();
            character.setClass();
            character.generateAbilityScores();
            cout << "Character created successfully!\n";
            break;
        case 2:
            character.displayCharacter();
            break;
        case 3:
            cout << "Exiting character creation.\n";
            break;
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}
