#include <iostream> 
#include <vector>
#include <string>
#include <limits>

using namespace std;


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

    // Method to display all recipes in a given category
    void displayRecipesByCategory(string category) {
        cout << "Recipes in category: " << category << endl;
        cout << "-----------------" << endl;

        
        for (const auto& recipe : recipes) {
            if (recipe.category == category) {
                cout << "Title: " << recipe.title << endl;
                cout << "Ingredients: " << recipe.ingredients << endl;
                cout << "Instructions: " << recipe.instructions << endl;
                cout << "-----------" << endl;
            }
        }
    }

    // Method to search for recipes by a keyword
    void searchRecipeByKeyword(string keyword) {
        cout << "Search results for keyword: " << keyword << endl;
        cout << "-----------------" << endl;

        // Loop through the recipes and display those that contain the keyword in the title or ingredients
        for (const auto& recipe : recipes) {
            if (recipe.title.find(keyword) != string::npos || recipe.ingredients.find(keyword) != string::npos) {
                cout << "Title: " << recipe.title << endl;
                cout << "Category: " << recipe.category << endl;
                cout << "Ingredients: " << recipe.ingredients << endl;
                cout << "Instructions: " << recipe.instructions << endl;
                cout << "-----------------" << endl;
            }
        }
    }
};


void getRecipeInput(RecipeOrganizer& organizer) {
    string title, category, ingredients, instructions;

    // Prompt user for recipe details
    cout << "Enter the title of the recipe: ";
    getline(cin, title);

    cout << "Enter the category of the recipe: ";
    getline(cin, category);

    cout << "Enter the ingredients of the recipe: ";
    getline(cin, ingredients);

    cout << "Enter the instructions for the recipe: ";
    getline(cin, instructions);

    // A
    organizer.addRecipe(title, category, ingredients, instructions);
}

int main() {
    RecipeOrganizer organizer;
    int choice;                
    string category, keyword;  

    while (true) {
        
        cout << "\nRecipe Organizer Menu" << endl;
        cout << "1. Add a Recipe" << endl;
        cout << "2. Display Recipes by Category" << endl;
        cout << "3. Search Recipe by Keyword" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        // Get user choice and ignore newline character in the input buffer
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Perform actions based on user choice
        switch (choice) {
            case 1:
               
                getRecipeInput(organizer);
                break;
            case 2:
                //
                cout << "Enter the category to display recipes: ";
                getline(cin, category);
                organizer.displayRecipesByCategory(category);
                break;
            case 3:
              
                cout << "Enter the keyword to search recipes: ";
                getline(cin, keyword);
                organizer.searchRecipeByKeyword(keyword);
                break;
            case 4:
                //
                cout << "Exiting the program." << endl;
                return 0;
            default:
                
                cout << "Invalid choice try again." << endl;
        }
    }

    return 0;
}
