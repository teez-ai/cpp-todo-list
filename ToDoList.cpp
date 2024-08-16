#include <iostream>
#include <string>
#include <list>

class ToDoItem
{
private:
	int id;
	std::string description; 
	bool completed;		// Check if completed or not

public:
	ToDoItem() : id(0), description(""), completed(false) {}
	~ToDoItem() = default;

	bool create(std::string new_description)	// Adds new item
	{
		id =  1 + rand() % 100;		// Generates a random integer between 1 and 100
		description = new_description;
		return true;
	}

	// Getters
	int getId() { return id; }
	std::string getDescription() { return description; }
	bool isCompleted() { return completed; }

	void setCompleted(bool val) { completed = val; }

};
int main()
{
	char choice;
	int input_id;
	std::string input_description;

	std::list<ToDoItem> toDoItems1;
	std::list<ToDoItem>::iterator iter;	// Making an iterator to point through each item

	srand(time(NULL));	// Creating a new seed everytime our program launches

	toDoItems1.clear();

	//ToDoItem test1; 
	//test1.create("My first task");
	//toDoItems1.push_back(test1);

	while (1)
	{
		system("cls");	// In-between each loop, this will clear the screen
		std::cout << "/////////////To-Do List App/////////////\n";
		std::cout << '\n' << '\n';

		for (iter = toDoItems1.begin(); iter != toDoItems1.end(); iter++)
		{
			std::string completed = iter->isCompleted() ? "done" : "not done";   

			std::cout << iter->getId() << " | " << iter->getDescription() << " | "
				<< completed << '\n';
		}


		if (toDoItems1.empty())
		{
			std::cout << "No items in this list: Add some tasks! \n";
		}

		std::cout << "A. Add new Todo Item" << '\n';
		std::cout << "B. Complete Todo Item" << '\n';
		std::cout << "Q. Exit Program" << '\n';

		std::cout << "Please select your choice: ";

		std::cin >> choice;

		switch (choice) 
		{
			case 'q':
			case 'Q':			
				std::cout << "You have exited, the program. Goodbye.\n";
				break;

			case 'b':
			case 'B':		
				std::cout << "Enter ID to Mark Complete\n";
				std::cin >> input_id;
				for (iter = toDoItems1.begin(); iter != toDoItems1.end(); iter++)
				{
					if (input_id == iter->getId())
					{
						iter->setCompleted(true);
						break;
					}
				}
			
			case 'a':	// We had to put A last since it will create an error with the switch due to the late instantiation
			case 'A':
				std::cout << "Add a new description: ";
				std::cin.clear();	// Clear buffer
				std::cin.ignore();	// Ignore any characters from the input buffer
				std::getline(std::cin, input_description);

				ToDoItem newItem;	
				newItem.create(input_description);
				toDoItems1.push_back(newItem);
		}
		

	}

 
	return 0;
}

