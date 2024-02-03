#include "file_commands.hpp"
#include <iostream>
#include <unistd.h> // to handle chdir() and getcwd()
#include <sys/stat.h> // for mkdir() and remove rmdir ()
#include <fstream> // for cat()
#include <dirent.h>

// cd command implementation
void executeCdCommand(const string& path){
     if (chdir(path.c_str()) != 0) {

    //if (chdir(path.c_str())) ! =0{
        perror("chdir");
    }
}

// ls command implememntation

void executeLsCommand() {
    DIR* dir = opendir(".");
    if (dir == nullptr) {
        perror("opendir");
        return;
    }

    dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::cout << entry->d_name << std::endl;
    }

    closedir(dir);
}


//pwd command implememntation
void executePwdCommand() {
    char buffer[4096];
    if (getcwd(buffer, sizeof(buffer)) == nullptr) {
        perror("getcwd");
    } else {
        std::cout << buffer << std::endl;
    }
}

//mkdir command implementation

void executeMkdirCommand(const std::string& directory) {
    if (mkdir(directory.c_str(), 0755) != 0) {
        perror("mkdir");
    }
}

// rmdir command implementation

void executeRmdirCommand(const std::string& directory) {
    if (rmdir(directory.c_str()) != 0) {
        perror("rmdir");
    }
}

//  cp command implememntation

void executeCpCommand(const std::string& source, const std::string& destination) {
    std::ifstream src(source, std::ios::binary);
    std::ofstream dst(destination, std::ios::binary);

    dst << src.rdbuf();
}

// mv command implementation

void executeMvCommand(const std::string& source, const std::string& destination) {
    if (rename(source.c_str(), destination.c_str()) != 0) {
        perror("rename");
    }
}

// rm command implememntation

void executeRmCommand(const std::string& file) {
    if (remove(file.c_str()) != 0) {
        perror("remove");
    }
}

// cat command implememntation

void executeCatCommand(const std::string& file) {
    std::ifstream f(file);
    std::string line;
    while (std::getline(f, line)) {
        std::cout << line << std::endl;
    }
}

// grep command implememntation

void executeGrepCommand(const std::string& pattern, const std::string& file) {
    std::ifstream f(file);
    std::string line;
    while (std::getline(f, line)) {
        if (line.find(pattern) != std::string::npos) {
            std::cout << line << std::endl;
        }
    }
}