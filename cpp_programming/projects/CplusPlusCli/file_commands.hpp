// file commands
#include <iostream>
#ifndef FILE_COMMANDS_HPP
#define FILE_COMMANDS_HPP
using namespace std;



void executeCdCommand(const string& path);
void executeLsCommand();
void executePwdCommand();
void executeMkdirCommand(const string& directory);
void executeRmdirCommand(const string& directory);
void executeCpCommand(const string& source, const string& destination);
void executeMvCommand(const string& source, const string& destination);
void executeRmCommand(const string& file);
void executeCatCommand(const string& file);
void executeGrepCommand(const string& pattern, const string& file);

#endif
