# Student Management System in C++

This repository hosts a basic Student Management System written in C++. It provides functionalities to manage and manipulate student information, including name, age, class, grade, and various administrative features.

## Features

### Person Class
- **`Person`**: Represents a person with attributes such as name and age.

### Student Class
- **User Management**: Handles up to 100 users with functions to add, delete, search, sort, and modify user information.
- **File Operations**: Read and write to text files, including backup and restore functionalities.
- **Authentication**: Simple login mechanism with default admin credentials.
- **Age Counter**: Functionality to handle age-related operations.
- **Class and Grade Management**: Set class and grade for students.

## How to Use

### Basic Operations
- **`Builder`**: Builds the student information.
- **`Search`**: Searches for a student by name.
- **`SearchByAge`**: Searches for students by age.
- **`WriteToText`**: Writes student information to a text file.
- **`ReadFiles`**: Reads student information from a file.
- **`start`**: Initializes the program.
- **`Backup`**: Creates a backup of the data.
- **`ReadFromBackup`**: Reads from a backup file.

### Login and Security
- **`Login`**: Handles the login process.
- **`ChangePasswordAndUsername`**: Allows changing the password and username for the system.

### Sorting and Deletion
- **`Sort`**: Sorts students by specified criteria.
- **`AdvancedDelete`**: Provides an advanced deletion mechanism.
- **`DeleteAll`**: Deletes all student records.

## Usage Example

Include the classes in your project, and you can create and manage Student objects.

```cpp
#include "Person.hpp"
#include "Student.hpp"

int main() {
    Student studentManagement;
    studentManagement.start();
}
```
# Requirements

- A `C++` compiler with support for standard libraries such as `iostream`, `vector`, `string`, `fstream`, `etc`.

- Windows operating system, as the code includes `<Windows.h>`.

# Contributing
- Feel free to contribute to this project by opening an issue or a pull request.

