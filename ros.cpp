#include <iostream> 
#include <vector>    
#include <string>    
#include <limits>    

using namespace std;

// Tafsiri ya mpango wa Recipe
class Recipe {
public:
    string title;         // Jina la mapishi
    string category;      // Aina (mfano, Dessert, Main Course)
    string ingredients;   // Viungo vinavyohitajika
    string instructions;  // Hatua za kuandaa mapishi

    // Constructor ya kuunda Recipe mpya
    Recipe(string t, string c, string i, string ins) 
        : title(t), category(c), ingredients(i), instructions(ins) {}
};

// Tafsiri ya Recipe Organizer
class RecipeOrganizer {
private:
    vector<Recipe> recipes; // Orodha ya kuhifadhi mapishi yote

public:
    // Njia ya kuongeza mapishi mapya
    void addRecipe(string title, string category, string ingredients, string instructions) {
        recipes.push_back(Recipe(title, category, ingredients, instructions));
    }

    // Njia ya kuonyesha mapishi kwa aina
    void displayRecipesByCategory(string category) {
        cout << "Mapishi katika aina: " << category << endl;
        for (const auto& recipe : recipes) {
            if (recipe.category == category) {
                cout << "Jina: " << recipe.title << endl;
                cout << "Viungo: " << recipe.ingredients << endl;
                cout << "Maelekezo: " << recipe.instructions << endl;
                cout << "-----------------" << endl;
            }
        }
    }

    // Njia ya kutafuta mapishi kwa neno kuu
    void searchRecipeByKeyword(string keyword) {
        cout << "Matokeo ya utafutaji kwa neno kuu: " << keyword << endl;
        for (const auto& recipe : recipes) {
            if (recipe.title.find(keyword) != string::npos || recipe.ingredients.find(keyword) != string::npos) {
                cout << "Jina: " << recipe.title << endl;
                cout << "Aina: " << recipe.category << endl;
                cout << "Viungo: " << recipe.ingredients << endl;
                cout << "Maelekezo: " << recipe.instructions << endl;
                cout << "-----------------" << endl;
            }
        }
    }
};

// Njia ya kupata pembejeo za mtumiaji kwa mapishi mapya
void getRecipeInput(RecipeOrganizer& organizer) {
    string title, category, ingredients, instructions;

    cout << "Ingiza jina la mapishi: ";
    getline(cin, title);

    cout << "Ingiza aina ya mapishi: ";
    getline(cin, category);

    cout << "Ingiza viungo vya mapishi: ";
    getline(cin, ingredients);

    cout << "Ingiza maelekezo ya mapishi: ";
    getline(cin, instructions);

    organizer.addRecipe(title, category, ingredients, instructions);
}

int main() {
    RecipeOrganizer organizer;
    int choice;
    string category, keyword;

    while (true) {
        cout << "\nMenyu ya Recipe Organizer" << endl;
        cout << "1. Ongeza Mapishi" << endl;
        cout << "2. Onyesha Mapishi kwa Aina" << endl;
        cout << "3. Tafuta Mapishi kwa Neno Kuu" << endl;
        cout << "4. Toka" << endl;
        cout << "Ingiza chaguo lako: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Puuza herufi ya newline iliyobaki kwenye buffer ya pembejeo

        switch (choice) {
            case 1:
                getRecipeInput(organizer);
                break;
            case 2:
                cout << "Ingiza aina ya kuonyesha mapishi: ";
                getline(cin, category);
                organizer.displayRecipesByCategory(category);
                break;
            case 3:
                cout << "Ingiza neno kuu la kutafuta mapishi: ";
                getline(cin, keyword);
                organizer.searchRecipeByKeyword(keyword);
                break;
            case 4:
                cout << "Kuhitimisha mpango." << endl;
                return 0;
            default:
                cout << "Chaguo batili. Jaribu tena." << endl;
        }
    }

    return 0;
}