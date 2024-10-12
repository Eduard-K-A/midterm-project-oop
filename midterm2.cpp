#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

void menu()
{
    cout << "----------------------------------" << endl;
    cout << "Menu" << endl;
    cout << "1 - Add Item" << endl;
    cout << "2 - Update Item" << endl;
    cout << "3 - Remove Item" << endl;
    cout << "4 - Display Items by Category" << endl;
    cout << "5 - Display All Items" << endl;
    cout << "6 - Search Item" << endl;
    cout << "7 - Sort Items" << endl;
    cout << "8 - Display Low Stock Items" << endl;
    cout << "9 - Exit" << endl;
    cout << "----------------------------------" << endl;
}

bool isCorrectInt(int x)
{
    if (x <= 0)
    {
        cout << "You can not input 0 or a negative number! Try another." << endl;
        return false;
    }
    return true;
}

bool isCorrectDouble(double x)
{
    if (x <= 0)
    {
        cout << "You can not input 0 or a negative number! Try another." << endl;
        return false;
    }
    return true;
}

string getUpperCase(const string &x)
{
    string result = x;
    for (char &c : result)
    {
        c = toupper(c);
    }

    return result;
}

bool categoryCheck(string category)
{
    if (category == "CLOTHING" || category == "ELECTRONICS" || category == "ENTERTAINMENT")
    {
        cout << "Category Found!" << endl;
        return false;
    }
    else
    {
        cout << "Input a valid category!" << endl;
        return true;
    }
}

template <typename V>
V getValidInput(const string &prompt)
{
    V input;
    while (true)
    {
        cout << prompt;
        cin >> input;

        if (cin.fail())
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
    }
}
// Abstract base class
class Category
{
public:
    string name, category, ID;
    int quantity;
    double price;

    virtual void addItem() = 0;
    virtual void updateItem(const string &searchID, const string &change, double newQuantity, double newPrice) = 0;
    virtual void displayItems() = 0;
    virtual bool searchItem(const string &searchID) = 0;
    virtual void removeItem(const string &searchID) = 0;

    string getID() { return ID; }
    string getCategory() { return category; }
};
// Clothing category class
class Clothing : public Category
{
public:
    Clothing() { category = "CLOTHING"; }

    void addItem() override
    {
        cout << "Input Name: ";
        getline(cin, name);

        do
        {
            quantity = getValidInput<int>("Input Quantity: ");
        } while (!isCorrectInt(quantity));

        do
        {
            price = getValidInput<double>("Input Price: ");
        } while (!isCorrectDouble(price));

        cout << "Item Added Successfully!" << endl;
    }

    void updateItem(const string &searchID, const string &change, double newQuantity, double newPrice) override
    {
        if (searchID == ID)
        {
            if (change == "QUANTITY")
            {
                cout << "The quantity of the item has been updated from: " << quantity << " to: " << newQuantity << endl;
                quantity = newQuantity;
            }
            else if (change == "PRICE")
            {
                cout << "The price of the item has been updated from: " << price << " to: " << newPrice << endl;
                price = newPrice;
            }
        }
    }

    void displayItems() override
    {
        cout << ID << setw(30) << name << setw(30) << quantity << setw(30) << price << setw(30) << category << endl;
    }

    bool searchItem(const string &searchID) override
    {
        return (searchID == ID);
    }

    void removeItem(const string &searchID) override
    {
        if (searchID == ID)
        {
            ID = "";
            name = "";
            category = "";
            price = 0;
            quantity = 0;
        }
    }
    bool checkID(const string &inputID, const Clothing inputCloth[], int counter)
    {
        for (int i = 0; i < counter; i++)
        {
            if (inputID == inputCloth[i].ID)
            {
                cout << "ID already exists! Input a new one." << endl;
                return false;
            }
        }
        return true;
    }
};
// Electronics category class
class Electronics : public Category
{
public:
    Electronics() { category = "ELECTRONICS"; }

    void addItem() override
    {
        cout << "Input Name: ";
        getline(cin, name);

        do
        {
            quantity = getValidInput<int>("Input Quantity: ");
        } while (!isCorrectInt(quantity));

        do
        {
            price = getValidInput<double>("Input Price: ");
        } while (!isCorrectDouble(price));

        cout << "Item Added Successfully!" << endl;
    }

    void updateItem(const string &searchID, const string &change, double newQuantity, double newPrice) override
    {
        if (searchID == ID)
        {
            if (change == "QUANTITY")
            {
                cout << "The quantity of the item has been updated from: " << quantity << " to: " << newQuantity << endl;
                quantity = newQuantity;
            }
            else if (change == "PRICE")
            {
                cout << "The price of the item has been updated from: " << price << " to: " << newPrice << endl;
                price = newPrice;
            }
        }
    }

    void displayItems() override
    {
        cout << ID << setw(30) << name << setw(30) << quantity << setw(30) << price << setw(30) << category << endl;
    }

    bool searchItem(const string &searchID) override
    {
        return (searchID == ID);
    }

    void removeItem(const string &searchID) override
    {
        if (searchID == ID)
        {
            ID = "";
            name = "";
            category = "";
            price = 0;
            quantity = 0;
            cout << "Item Removed from inventory!" << endl;
        }
    }

    bool checkID(const string &inputID, const Electronics inputElect[], int counter)
    {
        for (int i = 0; i < counter; i++)
        {
            if (inputID == inputElect[i].ID)
            {
                cout << "ID already exists! Input a new one." << endl;
                return false;
            }
        }
        return true;
    }
};
// Entertainment category class
class Entertainment : public Category
{
public:
    Entertainment() { category = "ENTERTAINMENT"; }

    void addItem() override
    {
        cout << "Input Name: ";
        getline(cin, name);

        do
        {
            quantity = getValidInput<int>("Input Quantity: ");
        } while (!isCorrectInt(quantity));

        do
        {
            price = getValidInput<double>("Input Price: ");
        } while (!isCorrectDouble(price));

        cout << "Item Added Successfully!" << endl;
    }

    void updateItem(const string &searchID, const string &change, double newQuantity, double newPrice) override
    {
        if (searchID == ID)
        {
            if (change == "QUANTITY")
            {
                cout << "The quantity of the item has been updated from: " << quantity << " to: " << newQuantity << endl;
                quantity = newQuantity;
            }
            else if (change == "PRICE")
            {
                cout << "The price of the item has been updated from: " << price << " to: " << newPrice << endl;
                price = newPrice;
            }
        }
    }

    void displayItems() override
    {
        cout << ID << setw(30) << name << setw(30) << quantity << setw(30) << price << setw(30) << category << endl;
    }

    bool searchItem(const string &searchID) override
    {
        return (searchID == ID);
    }

    void removeItem(const string &searchID) override
    {
        if (searchID == ID)
        {
            ID = "";
            name = "";
            category = "";
            price = 0;
            quantity = 0;
            cout << "Item Removed from inventory!" << endl;
        }
    }

    bool checkID(const string &inputID, const Entertainment inputEnter[], int counter)
    {
        for (int i = 0; i < counter; i++)
        {
            if (inputID == inputEnter[i].ID)
            {
                cout << "ID already exists! Input a new one." << endl;
                return false;
            }
        }
        return true;
    }
};
void sortItemsAscend(Category *items[], int totalItems, const string &sortBy)
{
    for (int i = 0; i < totalItems - 1; i++)
    {
        for (int j = 0; j < totalItems - i - 1; j++)
        {
            if (sortBy == "QUANTITY")
            {
                if (items[j]->quantity > items[j + 1]->quantity) // Sort by quantity
                {
                    swap(items[j], items[j + 1]);
                }
            }
            else if (sortBy == "PRICE")
            {
                if (items[j]->price > items[j + 1]->price) // Sort by price
                {
                    swap(items[j], items[j + 1]);
                }
            }
        }
    }
}
void sortItemsDescend(Category *items[], int totalItems, const string &sortBy)
{
    for (int i = 0; i < totalItems - 1; i++)
    {
        for (int j = 0; j < totalItems - i - 1; j++)
        {
            if (sortBy == "QUANTITY")
            {
                if (items[j]->quantity < items[j + 1]->quantity) // Sort by quantity
                {
                    swap(items[j], items[j + 1]);
                }
            }
            else if (sortBy == "PRICE")
            {
                if (items[j]->price < items[j + 1]->price) // Sort by price
                {
                    swap(items[j], items[j + 1]);
                }
            }
        }
    }
}

void displayLowStockItems(Clothing userCloth[], Electronics userElect[], Entertainment userEnter[], const int &clothCtr, const int &electCtr, const int &enterCtr)
{
    int counter = clothCtr + electCtr + enterCtr;
    bool foundLowStock = false;
    // If there are items in the inventory
    if (counter > 0)
    {
        // Check clothing items for low stock
        for (int i = 0; i < clothCtr; i++)
        {
            if (userCloth[i].quantity <= 5)
            {
                foundLowStock = true; // Set flag if a low stock item is found
                break;                // No need to continue if at least one low stock is found
            }
        }
        // Check electronics items for low stock
        if (!foundLowStock) // Only check if not found yet
        {
            for (int i = 0; i < electCtr; i++)
            {
                if (userElect[i].quantity <= 5)
                {
                    foundLowStock = true;
                    break;
                }
            }
        }
        // Check entertainment items for low stock
        if (!foundLowStock) // Only check if not found yet
        {
            for (int i = 0; i < enterCtr; i++)
            {
                if (userEnter[i].quantity <= 5)
                {
                    foundLowStock = true;
                    break;
                }
            }
        }
        // If no low stock items were found, display the appropriate message
        if (!foundLowStock)
        {
            cout << "No low stock items to display!" << endl;
            return;
        }
        // Display the table only if there are low stock items
        cout << "Displaying low stock items... " << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "ID" << setw(30) << "NAME" << setw(30) << "QUANTITY" << setw(30) << "PRICE" << setw(30) << "CATEGORY" << endl;

        for (int i = 0; i < clothCtr; i++)
        {
            if (userCloth[i].quantity <= 5)
            {
                userCloth[i].displayItems();
            }
        }

        for (int i = 0; i < electCtr; i++)
        {
            if (userElect[i].quantity <= 5)
            {
                userElect[i].displayItems();
            }
        }

        for (int i = 0; i < enterCtr; i++)
        {
            if (userEnter[i].quantity <= 5)
            {
                userEnter[i].displayItems();
            }
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else // If inventory is empty
    {
        cout << "No low stock items to display!" << endl;
        return;
    }
}

template <typename T>
bool removeItemFromInventory(T *items, int &itemCount, const string &searchID)
{
    for (int i = 0; i < itemCount; i++)
    {
        if (items[i].searchItem(searchID))
        {
            cout << "Item " << items[i].name << " has been removed from the inventory!" << endl;

            for (int j = i; j < itemCount - 1; j++)
            {
                items[j] = items[j + 1]; // Shift items to the left
            }

            items[itemCount - 1].removeItem(searchID); // Optional: if you have specific cleanup in the item
            itemCount--;
            return true; // Item found and removed
        }
    }
    return false; // Item not found
}

template <typename Y>
bool displayItemsByCategory(Y *items, int &itemCount)
{
    cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "ID" << setw(30) << "NAME" << setw(30) << "QUANTITY" << setw(30) << "PRICE" << setw(30) << "CATEGORY" << endl;
    for (int i = 0; i < itemCount; i++)
    {
        items[i].displayItems();
    }
    cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
    return false;
}
template <typename U>
void updateItemFunc(U &items, string &searchID, int &itemCount, int &newQuantity, double &newPrice)
{
    string change;
    bool IDfound = false;
    bool repeat;
    do
    {
        cout << "Input quantity or price: ";
        getline(cin, change);
        change = getUpperCase(change);

        if (change == "QUANTITY")
        {
            repeat = false;
            do
            {
                newQuantity = getValidInput<int>("Enter new value: ");
                if (newQuantity == items.quantity)
                {
                    cout << "You cannot update the value to its similar previous value!" << endl;
                    repeat = true;
                }
                else if (!isCorrectInt(newQuantity))
                {
                    repeat = true;
                }
                else
                {
                    cout << "Invalid quantity. Please enter a valid integer." << endl;
                    repeat = false;
                }
            } while (repeat);
            items.updateItem(searchID, change, newQuantity, newPrice);
            return;
        }
        else if (change == "PRICE")
        {
            do
            {
                newPrice = getValidInput<double>("Enter new value: ");
                if (newPrice == items.price)
                {
                    cout << "You cannot update the value to its similar previous value!" << endl;
                    repeat = true;
                }
                else if (!isCorrectDouble(newPrice))
                {
                    repeat = true;
                }
                else
                {   cout << "Invalid Price. Please enter a valid value." << endl;
                    repeat = false;
                }
            } while (repeat);

            items.updateItem(searchID, change, newQuantity, newPrice);
            return;
        }
        else
        {
            cout << "Invalid Input. Try another!" << endl;
            IDfound = false;
        }
    } while (!IDfound);
    return;
}

int main()
{
    int choice = 0, clothingCtr = 0, electronicsCtr = 0, entertainmentCtr = 0, totalItems = 0, newQuantity = 0;

    string searchID, category, change, sort, sortBy, inputID;

    Clothing userCloth[20], clothVal;
    Electronics userElect[20], electVal;
    Entertainment userEnter[20], enterVal;

    double newPrice = 0;

    bool keySearch = false, IDfound = false, invalid = false;

    Category *allItems[60]; // Maximum size (20 items per category)
    do
    {
        menu();
        choice = getValidInput<int>("Enter the number: ");
        
        switch (choice)
        {
        case 1: // Add Item
            do
            {
                cout << "Input Category: ";
                getline(cin, category);
                category = getUpperCase(category);
            } while (categoryCheck(category));

            if (category == "CLOTHING" || category == "ELECTRONICS" || category == "ENTERTAINMENT")
            {
                string inputID;
                do
                {
                    cout << "Input ID: ";
                    getline(cin, inputID);
                } while (!((category == "CLOTHING" && clothVal.checkID(inputID, userCloth, clothingCtr)) ||
                           (category == "ELECTRONICS" && electVal.checkID(inputID, userElect, electronicsCtr)) ||
                           (category == "ENTERTAINMENT" && enterVal.checkID(inputID, userEnter, entertainmentCtr))));

                if (category == "CLOTHING")
                {
                    userCloth[clothingCtr].ID = inputID;
                    userCloth[clothingCtr].addItem();
                    clothingCtr++;
                }
                else if (category == "ELECTRONICS")
                {
                    userElect[electronicsCtr].ID = inputID;
                    userElect[electronicsCtr].addItem();
                    electronicsCtr++;
                }
                else if (category == "ENTERTAINMENT")
                {
                    userEnter[entertainmentCtr].ID = inputID;
                    userEnter[entertainmentCtr].addItem();
                    entertainmentCtr++;
                }
            }
            break;

        case 2: // Update Item
            if (clothingCtr + electronicsCtr + entertainmentCtr == 0)
            {
                cout << "Inventory is empty. Try adding in the menu!" << endl;
                break;
            }
            cout << "Input ID: ";
            getline(cin, searchID);

            for (int i = 0; i < clothingCtr; i++)
            {
                if (userCloth[i].searchItem(searchID))
                {
                    updateItemFunc(userCloth[i], searchID, clothingCtr, newQuantity, newPrice);
                    IDfound = true;
                    break;
                }
            }

            for (int i = 0; i < electronicsCtr; i++)
            {
                if (userElect[i].searchItem(searchID))
                {

                    updateItemFunc(userElect[i], searchID, electronicsCtr, newQuantity, newPrice);
                    IDfound = true;
                    break;
                }
            }
            for (int i = 0; i < entertainmentCtr; i++)
            {
                if (userEnter[i].searchItem(searchID))
                {
                    updateItemFunc(userEnter[i], searchID, entertainmentCtr, newQuantity, newPrice);
                    IDfound = true;
                    break;
                }
                IDfound = false;
            }

            if (!IDfound)
            {
                cout << "ID not found!" << endl;
                break;
            }
            break;

        case 3: // Remove Item
            if (clothingCtr + electronicsCtr + entertainmentCtr == 0)
            {
                cout << "Inventory is empty. Try adding in the menu!" << endl;
                break;
            }

            IDfound = false;

            cout << "Enter ID to remove: ";
            getline(cin, searchID);

            // Call the remove function for each category
            IDfound |= removeItemFromInventory(userCloth, clothingCtr, searchID);
            IDfound |= removeItemFromInventory(userElect, electronicsCtr, searchID);
            IDfound |= removeItemFromInventory(userEnter, entertainmentCtr, searchID);

            if (!IDfound)
            {
                cout << "Item with ID " << searchID << " not found." << endl;
            }
            break;

        case 4: // Display Items by Category
            cout << "Enter category to display: ";
            getline(cin, category);
            category = getUpperCase(category);

            if (category == "CLOTHING")
            {
                if (clothingCtr == 0)
                {
                    cout << "Category is empty. Try adding in the menu!" << endl;
                    break;
                }
                displayItemsByCategory(userCloth, clothingCtr);
            }
            else if (category == "ELECTRONICS")
            {
                if (electronicsCtr == 0)
                {
                    cout << "Category is empty. Try adding in the menu!" << endl;
                    break;
                }
                displayItemsByCategory(userElect, electronicsCtr);
            }
            else if (category == "ENTERTAINMENT")
            {
                if (entertainmentCtr == 0)
                {
                    cout << "Category is empty. Try adding in the menu!" << endl;
                    break;
                }
                displayItemsByCategory(userEnter, entertainmentCtr);
            }
            break;

        case 5: // Display All Items
            if (clothingCtr + electronicsCtr + entertainmentCtr == 0)
            {
                cout << "Inventory is empty. Try adding in the menu!" << endl;
                break;
            }
            cout << "Displaying all items..." << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "ID" << setw(30) << "NAME" << setw(30) << "QUANTITY" << setw(30) << "PRICE" << setw(30) << "CATEGORY" << endl;
            for (int i = 0; i < clothingCtr; i++)
            {
                userCloth[i].displayItems();
            }
            for (int i = 0; i < electronicsCtr; i++)
            {
                userElect[i].displayItems();
            }
            for (int i = 0; i < entertainmentCtr; i++)
            {
                userEnter[i].displayItems();
            }
            cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 6: // Search Item
            if (clothingCtr + electronicsCtr + entertainmentCtr == 0)
            {
                cout << "Inventory is empty. Try adding in the menu!" << endl;
                break;
            }
            cout << "Input ID to search: ";
            getline(cin, searchID);
            searchID = getUpperCase(searchID);

            for (int i = 0; i < clothingCtr; i++)
            {
                keySearch = userCloth[i].searchItem(searchID);
                if (keySearch)
                {
                    cout << "Item found in CLOTHING category" << endl;
                    cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "ID" << setw(30) << "NAME" << setw(30) << "QUANTITY" << setw(30) << "PRICE" << setw(30) << "CATEGORY" << endl;
                    userCloth[i].displayItems();
                    cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
                }
            }

            for (int i = 0; i < electronicsCtr; i++)
            {
                keySearch = userElect[i].searchItem(searchID);
                if (keySearch)
                {
                    cout << "Item found in ELECTRONICS category" << endl;
                    cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "ID" << setw(30) << "NAME" << setw(30) << "QUANTITY" << setw(30) << "PRICE" << setw(30) << "CATEGORY" << endl;
                    userElect[i].displayItems();
                    cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
                }
            }

            for (int i = 0; i < entertainmentCtr; i++)
            {
                keySearch = userEnter[i].searchItem(searchID);
                if (keySearch)
                {
                    cout << "Item found in ENTERTAINMENT category" << endl;
                    cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "ID" << setw(30) << "NAME" << setw(30) << "QUANTITY" << setw(30) << "PRICE" << setw(30) << "CATEGORY" << endl;
                    userEnter[i].displayItems();
                    cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
                }
            }

            if (!keySearch)
            {
                cout << "Item not found in inventory!" << endl;
            }
            break;

        case 7: // Sort Items
            totalItems = 0;
            // Combine all items into one array
            for (int i = 0; i < clothingCtr; i++)
                allItems[totalItems++] = &userCloth[i];
            for (int i = 0; i < electronicsCtr; i++)
                allItems[totalItems++] = &userElect[i];
            for (int i = 0; i < entertainmentCtr; i++)
                allItems[totalItems++] = &userEnter[i];

            if (totalItems == 0)
            {
                cout << "Inventory is empty. Try adding in the menu!" << endl;
                break;
            }
            // Get sort criteria
            do
            {
                cout << "Sort by QUANTITY or PRICE?: ";
                getline(cin, sort);
            } while ((sort = getUpperCase(sort)) != "QUANTITY" && sort != "PRICE" && cout << "Invalid input please try again!" << endl);
            // Get sort order
            do
            {
                cout << "Ascending or Descending? ";
                cin >> sortBy;
                sortBy = getUpperCase(sortBy);

                if (sortBy == "ASCENDING")
                    sortItemsAscend(allItems, totalItems, sort);
                else if (sortBy == "DESCENDING")
                    sortItemsDescend(allItems, totalItems, sort);
                else
                    cout << "Invalid Input. Please try again." << endl;
            } while (sortBy != "ASCENDING" && sortBy != "DESCENDING");
            // Display sorted items
            cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "ID" << setw(30) << "NAME" << setw(30) << "QUANTITY" << setw(30) << "PRICE" << setw(30) << "CATEGORY" << endl;
            for (int i = 0; i < totalItems; i++)
                allItems[i]->displayItems();
            cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 8: // Display Low Stock Items
            if (clothingCtr + electronicsCtr + entertainmentCtr == 0)
            {
                cout << "Inventory is empty. Try adding in the menu!" << endl;
                break;
            }
            displayLowStockItems(userCloth, userElect, userEnter, clothingCtr, electronicsCtr, entertainmentCtr);
            break;

        case 9: // Exit
            cout << "Exiting program!" << endl;
            break;

        default:
            cout << "Invalid option! Please select a valid option!" << endl;
            break;
        }
    } while (choice != 9);

    return 0;
}
