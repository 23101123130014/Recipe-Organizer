#include <iostream>  // Allows using input and output functions like cout
#include <vector>    // Allows using the vector data structure to store multiple items
#include <string>    // Allows using the string type for text
#include <limits>    // Allows using std::numeric_limits

<<<<<<< HEAD
using namespace std; // Allows avoiding writing 'std::' before every standard library function

// Definition of the Recipe class
=======
using namespace std; //requred for using standard namespace
// definition of the recipe class
>>>>>>> 237da0b9866bd86cbef9da4012389b53dd8f979a
class Recipe {
public:
    string title;         // Title of the recipe
    string category;      // Category (e.g., Dessert, Main Course)
    string ingredients;   // Ingredients needed
    string instructions;  // Steps to prepare the recipe

    // Constructor to create a new Recipe
    Recipe(string t, string c, string i, string ins) 
        : title(t), category(c), ingredients(i), instructions(ins) {}
};

// Definition of the Recipe Organizer class
class RecipeOrganizer {
private:
    vector<Recipe> recipes; // List to store all recipes

public:
    // Method to add a new recipe
    void addRecipe(string title, string category, string ingredients, string instructions) {
        recipes.push_back(Recipe(title, category, ingredients, instructions));
    }

    // Method to display recipes by category
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

    // Method to search for recipes by keyword
    void searchRecipeByKeyword(string keyword) {
        cout << "Search results for keyword: " << keyword << endl;
        for (const auto& recipe : recipes) {
            if (recipe.title.find(keyword) != string::npos || recipe.ingredients.find(keyword) != string::npos) {
                cout << "Title: " << recipe.title << endl;
                cout << "Category: " << recipe.category << endl;
                cout << "Ingredients: " << recipe.ingredients << endl;
                cout << "Instructions: " << recipe.instructions << endl;
                cout << "|||||" << endl;
            }
        }
    }
};

// Function to get user input for a new recipe
void getRecipeInput(RecipeOrganizer& organizer) {
    string title, category, ingredients, instructions;

    cout << "Enter the title of the recipe: ";
    getline(cin, title);

    cout << "Enter the category of the recipe: ";
    getline(cin, category);

    cout << "Enter the ingredients of the recipe: ";
    getline(cin, ingredients);

    cout << "Enter the instructions for the recipe: ";
    getline(cin, instructions);

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
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1:
                getRecipeInput(organizer);
                break;
            case 2:
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
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}