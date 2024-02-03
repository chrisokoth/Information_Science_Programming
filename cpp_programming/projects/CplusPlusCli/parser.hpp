#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;
//structure to represent a parsed vommnad
struct Command{
    bool isInternal =false;// 
    string name;
    vector<string> arguments;
    // will add more fields for arguments and flags as needed
};
//class for parsing command strings
class Parser {
    public:
    Parser();
    Command parse(const string& input);
};



// Add function prototypes for the new commands:
void executeMvCommand(const string& sourcePath, const string& destinationPath);
void executeRmCommand(const string& path);
void executeCatCommand(const string& filename);
void executeGrepCommand(const string& pattern, const string& filename);

// Add a command map within the Parser class:
class Parser{
    public:


    // ... (other members)

private:
    map<string, function<void(const vector<string>&)>> commands = {
        {"cd", executeCdCommand},
        {"ls", executeLsCommand},
        {"pwd", executePwdCommand},
        {"cp", executeCpCommand},
        {"mkdir", executeMkdirCommand},
        {"rmdir", executeRmdirCommand},
        {"mv", executeMvCommand},  // Add new commands here
        {"rm", executeRmCommand},
        {"cat", executeCatCommand},
        {"grep", executeGrepCommand}
    };
};
#endif //PARSER_HPP