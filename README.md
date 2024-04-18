Introduction
This project is a simple to-do task organizer implemented in C++ using the wxWidgets library. It provides a graphical user interface (GUI) for users to manage their daily tasks efficiently.

Features
Task Management: Add, edit, and delete tasks easily.
Task Prioritization: Assign priorities to tasks to manage them effectively.
User-Friendly Interface: Intuitive GUI for seamless interaction.
Cross-Platform: Works on Windows, macOS, and Linux.
Customizable: Easily customizable according to specific requirements.
Lightweight: Minimal dependencies, ensuring fast performance.
Requirements
C++ compiler supporting C++11 or higher
wxWidgets library installed (version 3.0 or higher)
CMake (for building)
Installation
Install wxWidgets:
On Debian/Ubuntu:
arduino
Copy code
sudo apt-get install libwxgtk3.0-dev
On macOS (using Homebrew):
Copy code
brew install wxwidgets
On Windows, download wxWidgets from the official website and follow the installation instructions.
Clone the Repository:
bash
Copy code
git clone https://github.com/yourusername/todo-task-organizer.git
Build the Project:
bash
Copy code
cd todo-task-organizer
mkdir build && cd build
cmake ..
make
Usage
Run the Application:
bash
Copy code
./todo_task_organizer
Adding a Task:
Click on the "Add Task" button.
Enter the task description and select the priority.
Click "Save" to add the task.
Editing a Task:
Double-click on a task in the list to edit.
Modify the task description or priority.
Click "Save" to apply changes.
Deleting a Task:
Select a task from the list.
Click on the "Delete Task" button.
Exiting the Application:
Click on the "Exit" button or close the window.
