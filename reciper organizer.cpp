#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Recipe {
public:
    string title, category, ingredients, instructions;
    Recipe(string t, string c, string i, string ins) : title(t), category(c), ingredients(i), instructions(ins) {}
};

class RecipeOrganizer {
private:
    vector<Recipe> recipes;

public:
    void addRecipe(string title, string category, string ingredients, string instructions) {
        recipes.push_back(Recipe(title, category, ingredients, instructions));
    }

    void displayRecipesByCategory(string category) {
        cout << "Recipes in category: " << category << endl;
        for (const auto& recipe : recipes) {
            if (recipe.category == category) {
                cout << "Title: " << recipe.title << endl;
                cout << "Ingredients: " << recipe.ingredients << endl;
                cout << "Instructions: " << recipe.instructions << endl;
                cout << "-----------------" << endl;
            }
        }
    }

    void searchRecipeByKeyword(string keyword) {
        cout << "Search results for keyword: " << keyword << endl;
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
    cout << "Enter the title of the recipe: "; getline(cin, title);
    cout << "Enter the category of the recipe: "; getline(cin, category);
    cout << "Enter the ingredients of the recipe: "; getline(cin, ingredients);
    cout << "Enter the instructions for the recipe: "; getline(cin, instructions);
    organizer.addRecipe(title, category, ingredients, instructions);
}

int main() {
    RecipeOrganizer organizer;
    int choice;
    string category, keyword;

    while (true) {
        cout << "\nRecipe Organizer Menu\n1. Add a Recipe\n2. Display Recipes by Category\n3. Search Recipe by Keyword\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: getRecipeInput(organizer); break;
            case 2: cout << "Enter the category to display recipes: "; getline(cin, category); organizer.displayRecipesByCategory(category); break;
            case 3: cout << "Enter the keyword to search recipes: "; getline(cin, keyword); organizer.searchRecipeByKeyword(keyword); break;
            case 4: cout << "Exiting the program." << endl; return 0;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
