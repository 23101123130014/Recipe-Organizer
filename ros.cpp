#include <iostream> 
#include <vector>    
#include <string>    
#include <limits>    
using namespace std;
//
class Recipe {
public:
    string title;         
    string category;      
    string ingredients;   
    string instructions; 

   
    Recipe(string t, string c, string i, string ins) 
        : title(t), category(c), ingredients(i), instructions(ins) {}
};


class RecipeOrganizer {
private:
    vector<Recipe> recipes; 

public:
    
    void addRecipe(string title, string category, string ingredients, string instructions) {
        recipes.push_back(Recipe(title, category, ingredients, instructions));
    }

  
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
    string category;
    string keyword;

    while (true) {
        cout << "\nMenyu ya Recipe Organizer" << endl;
        cout << "1. Ongeza Mapishi" << endl;
        cout << "2. Onyesha Mapishi kwa Aina" << endl;
        cout << "3. Tafuta Mapishi kwa Neno Kuu" << endl;
        cout << "4. Toka" << endl;
        cout << "Ingiza chaguo lako: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                cout << "Kuhitimisha" << endl;
                return 0;
            default:
                cout << "Chaguo batili. Jaribu tena." << endl;
        }
    }

    return 0;
}
