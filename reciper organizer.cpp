#include <iostream> //requred for using input and output operation
#include <vector> //requred for using vector function
#include <string> //requreid for using string class

using namespace std; //requred for using standard namespace
// definition of the recepe class
class Recipe {
public: // accsess specific
    string title, category, ingredients, instructions;

    Recipe(string t, string c, string i, string ins) : title(t), category(c), ingredients(i), instructions(ins) {}
};

class RecipeOrganizer {
private: // access specific
    vector<Recipe> recipes;

public:
    void addRecipe(string title, string category, string ingredients, string instructions) {
        recipes.push_back(Recipe(title, category, ingredients, instructions));
    }

    void displayRecipesByCategory(string category) {
        cout << "Recipes in category: " << category << endl;
        for (const auto& recipe : recipes) {
            if (recipe.category == category) {
                cout << "Title: " << recipe.title;
                cout << "\nIngredients: " << recipe.ingredients;
                cout << "\nInstructions: " << recipe.instructions;
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
                cout << "||" << endl;
            }
        }
    }
};

int main() {
    RecipeOrganizer organizer;
    organizer.addRecipe("Spaghetti Carbonara", "Main Course", "Spaghetti, Eggs, Pancetta, Parmesan, Black Pepper", "Cook spaghetti. Fry pancetta. Mix eggs and cheese. Combine all.");
    organizer.addRecipe("Chocolate Cake", "Dessert", "Flour, Cocoa Powder, Sugar, Eggs, Butter", "Mix ingredients. Bake at 350F for 25 minutes.");

    cout << "Recipe Organizer" << endl;
    organizer.displayRecipesByCategory("Dessert");
    organizer.searchRecipeByKeyword("Spaghetti");

    return 0;
}
