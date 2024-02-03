#include "parser.hpp"
using namespace std;
Parser::Parser(){}
//a function to parse a command string and return a command object
Command Parser::parse(const string& input){
    //simple parsing
    // extract the first word as the command name
    //ignore the remaining words or arguments for now
    string commandName;
    size_t spacePos= input.find(' ');
    if (spacePos != string::npos){
        commandName = input.substr(0, spacePos);
    }else{
        commandName =input;
    }
    //craete a command object with the extracted name
    Command parsedCommand;
    parsedCommand.name =commandName;
    parsedCommand.isInternal = // Determine if the command is internal
        // Example: Check against a list of known internal commands
        parsedCommand.name == "exit" || parsedCommand.name == "help";


// future features

//void displayHelp(const map< string, string>& commands);
void executeCdCommand(const string& path);
void executeLsCommand();
void executePwdCommand();
void executeMkdirCommand(const string& path);
void executeRmdirCommand(const string& path);
void executeCpCommand(const std::string& sourcePath, const std::string& destinationPath);
void executeMvCommand(const std::string& sourcePath, const std::string& destinationPath);
void executeRmCommand(const std::string& path);
void executeCatCommand(const std::string& filename);
void executeGrepCommand(const std::string& pattern, const std::string& filename);


return parsedCommand;

}