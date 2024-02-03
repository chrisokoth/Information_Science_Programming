#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<unistd.h> // for getcwd()
#include <cstring>
#include<dirent.h> // for directroy operations
#include<sys/types.h>// for data types
#include <unistd.h> // for access
#include <sys/stat.h>
#include <cstring> // for strerror()
#include <fstream>
#include <regex>
// include the header for the command parser object
#include "parser.hpp"
#include "file_commands.hpp"

using namespace std;


//available commands with descriptions

map<string, string> availableCommands = {
    //file manipulation
    {"cd", "Change directory"},
    {"ls", "List directory contents"},
    {"pwd", "Print working directory"},
    {"mkdir", "Create a directory"},
    {"rmdir", "Remove a directory"},
    {"cp", "Copy files"},
    {"mv", "Move or rename files"},
    {"rm", "Remove files"},
    {"cat", "Display the contents of a file"},
    {"grep", " search for a text in files"},
    //process management activity+
    {"ps", "list processes"},
    {"kill", "Terminate a process"},
    {"top", "Monitor process activity"},
    //Text manipulation commands
    {"head", " Display the beginning of a file"},
    {"tail", "Display the end of a file"},
    {"sort", "Sort lines in afile"},
    {"uniq", "Remove duplicatd lines from a file"},
    //miscellaneous
    {"clear", "Clear the terminal screen"},
    {"man", "Display the manual page for a command"}
    



};

// create a function to print the available commands
void displayHelp(const map< string, string>& commands){
    cout<<"Available commands:\n";
    for (const auto& [command, description]: commands){
        std::cout<< "- " <<command << ": " << description<<std:: endl;
    }
}

// a function to check for Unrecognizd commands
bool isCommandRecognised(const string& commandName){
    return availableCommands.count(commandName) >0;
}

// a function for other commands
//bool isCommandRecognised(const string& commandName){
//    return availableCommands.count(commandName)> 0;
//}

// function to handle cd command
void executeCdCommand(const string& path){
    if (path.empty()){
        std::cerr<<" Error: Missing path argument for cd command. "<<std::endl;
        return;
    }
    if (chdir(path.c_str())==0){
        //directory changed succesfully
        std::cout<< "Directory changed successfully. "<<std::endl;
    }else{
        //directory change failed
        std::cerr<< "Enter chnaging directory: "<<strerror(errno) << std::endl;

    }
}

// function to handle 'ls' command

void executeLsCommand(){
    DIR* dir = opendir("."); // to open the current directory
    if (dir == nullptr){
        std::cerr<<" Error opening directory: "<<strerror(errno)<< std::endl;
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        std::string filename = entry->d_name;

        // Check for file type and print accordingly
        struct stat fileStat;
        if(::stat(filename.c_str(), &fileStat)==0){
            if(S_ISDIR(fileStat.st_mode)){
        //if (stat(filename.c_str(), &fileStat) == 0) {
          //  if (S_ISDIR(fileStat.st_mode)) {
                std::cout << filename << "/" << std::endl;
            } else {
                std::cout << filename << std::endl;
            }
        } else {
            std::cerr << "Error getting file information: " << strerror(errno) << std::endl;
        }
    }

    closedir(dir);

}


// function to handle pwd command

void executePwdCommand(){
    char buffer[4096];

    if (getcwd(buffer, sizeof(buffer)) != nullptr){
        std::cout<<buffer << std::endl;

    }else{
        std::cerr<< "Error getting current working directory: "<< strerror(errno) << std::endl;
    }
}


// a function to implement mkdir command

void executeMkdirCommand(const string& path){
    if (path.empty()){
        std::cerr<<"Error: Missing path argument for mkdir command. "<<std::endl;
        return;

    }
    if (mkdir(path.c_str(), 0755) == 0){
        std::cout << "Directory created successfully. "<<std::endl;
    }else{
        std::cerr <<"Error creating directory: "<< strerror(errno)<<std::endl;
    }
}

// a function to implement rmdir command
void executeRmdirCommand(const string& path){
    if (path.empty()){
        std::cerr<< "Error: Missing path arguments for rmdir command. "<<std::endl;
        return;
    }
    if (rmdir(path.c_str()) == 0) {
        std::cout << "Directory removed successfully." << std::endl;
    } else {
        std::cerr << "Error removing directory: " << strerror(errno) << std::endl;
    }
    
}


// afunction to implement cp command

void executeCpCommand(const std::string& sourcePath, const std::string& destinationPath) {
    if (sourcePath.empty() || destinationPath.empty()) {
        std::cerr << "Error: Missing source or destination path for cp command." << std::endl;
        return;
    }

    std::ifstream sourceFile(sourcePath.c_str(), std::ios::binary);
    std::ofstream destinationFile(destinationPath.c_str(), std::ios::binary);

    if (!sourceFile.is_open()) {
        std::cerr << "Error opening source file: " << strerror(errno) << std::endl;
        return;
    }

    if (!destinationFile.is_open()) {
        std::cerr << "Error creating destination file: " << strerror(errno) << std::endl;
        sourceFile.close();
        return;
    }

    destinationFile << sourceFile.rdbuf();  // Copy file contents

    sourceFile.close();
    destinationFile.close();

    std::cout << "File copied successfully." << std::endl;
}

// a function to implement mv command

void executeMvCommand(const std::string& sourcePath, const std::string& destinationPath) {
    if (sourcePath.empty() || destinationPath.empty()) {
        std::cerr << "Error: Missing source or destination path for mv command." << std::endl;
        return;
    }

    // Check if source path exists
    struct stat sourceStat;
    if (stat(sourcePath.c_str(), &sourceStat) != 0) {
        std::cerr << "Error: Source path does not exist: " << sourcePath << std::endl;
        return;
    }

    // Determine if source is a file or directory
    if (S_ISDIR(sourceStat.st_mode)) {
        // Source is a directory: use rename() to move it
        if (rename(sourcePath.c_str(), destinationPath.c_str()) == 0) {
            std::cout << "Directory moved successfully." << std::endl;
        } else {
            std::cerr << "Error moving directory: " << strerror(errno) << std::endl;
        }
    } else {
        // Source is a file: copy and then remove
        executeCpCommand(sourcePath, destinationPath);  // Reuse the cp implementation

        if (remove(sourcePath.c_str()) == 0) {
            std::cout << "File moved successfully." << std::endl;
        } else {
            std::cerr << "Error removing source file after copy: " << strerror(errno) << std::endl;
        }
    }
}


// a function to implement the rm command

void executeRmCommand(const std::string& path) {
    if (path.empty()) {
        std::cerr << "Error: Missing path argument for rm command." << std::endl;
        return;
    }

    struct stat fileStat;
    if (stat(path.c_str(), &fileStat) != 0) {
        std::cerr << "Error: Path does not exist: " << path << std::endl;
        return;
    }

    if (S_ISDIR(fileStat.st_mode)) {
        // Path is a directory: use rmdir()
        if (rmdir(path.c_str()) == 0) {
            std::cout << "Directory removed successfully." << std::endl;
        } else {
            std::cerr << "Error removing directory: " << strerror(errno) << std::endl;
        }
    } else {
        // Path is a file: use unlink()
        if (unlink(path.c_str()) == 0) {
            std::cout << "File removed successfully." << std::endl;
        } else {
            std::cerr << "Error removing file: " << strerror(errno) << std::endl;
        }
    }
}

// a function to implement cat command
void executeCatCommand(const std::string& filename) {
    if (filename.empty()) {
        std::cerr << "Error: Missing filename argument for cat command." << std::endl;
        return;
    }

    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << strerror(errno) << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}


// a function to implement the grep command

void executeGrepCommand(const std::string& pattern, const std::string& filename) {
    if (pattern.empty() || filename.empty()) {
        std::cerr << "Error: Missing pattern or filename argument for grep command." << std::endl;
        return;
    }

    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << strerror(errno) << std::endl;
        return;
    }

    std::regex regexPattern(pattern);
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        if (std::regex_search(line, regexPattern)) {
            std::cout << filename << ":" << lineNumber << ": " << line << std::endl;
        }
    }

    file.close();
}


int main(){
    //Display a welcome message
    cout<<"Welcome to CplusPlusCli!\n";
    // create an instance for the command parser
    Parser parser;
    //main loop to handle user input
    while(true){
        cout<<"$ ";//used to display the prompt
        string input;
        getline(cin, input); //to read the user input

        //parse the command using the parser object
        Command parsedCommand = parser.parse(input);
      
      

        //handle the command based on its type
        if (parsedCommand.isInternal){
            //handle internal commands like exit, help directly
            if (parsedCommand.name == "exit"){
                break; //exit the loop and terminate program
            }else if (parsedCommand.name == "help"){
                //display help information
                //cal the displayHelp function
                displayHelp(availableCommands);



             }else{
                // handle other internal commands


        //if (isCommandRecognized(parsedCommand.name)) {
            if (parsedCommand.name == "cd") {
                //executeCdCommand(const string& path);
                executeCdCommand(parsedCommand.arguments[0]);
            } else if (parsedCommand.name == "ls") {
                executeLsCommand();
            } else if (parsedCommand.name == "pwd") {
                executePwdCommand();
            } else if (parsedCommand.name == "mkdir") {
                executeMkdirCommand(parsedCommand.arguments[0]);
            } else if (parsedCommand.name == "rmdir") {
                executeRmdirCommand(parsedCommand.arguments[0]);
            } else if (parsedCommand.name == "cp") {
                executeCpCommand(parsedCommand.arguments[0], parsedCommand.arguments[1]);
            } else if (parsedCommand.name == "mv") {
                executeMvCommand(parsedCommand.arguments[0], parsedCommand.arguments[1]);
            } else if (parsedCommand.name == "rm") {
                executeRmCommand(parsedCommand.arguments[0]);
            } else if (parsedCommand.name == "cat") {
                executeCatCommand(parsedCommand.arguments[0]);
            } else if (parsedCommand.name == "grep") {
                executeGrepCommand(parsedCommand.arguments[0], parsedCommand.arguments[1]);
            } else {
                // Handle other recognized commands
            }











        
        }
        }else{
            //execute external commands using systme calls or other methods
            if (isCommandRecognised(parsedCommand.name)){
                //handle recognised external commands 
            }else{
                cout << "Unrecognised CplusplusCLI command: "<<parsedCommand.name<< endl;
            }
            //int result = system(parsedCommand.name.c_str());
            //handle execution results and potentuial errors



        }


    }
    //display a goodbye message]
    cout<< " You are now exiitng CPlusPlusCLI................. Goodbye!\n";
    return 0;
}

