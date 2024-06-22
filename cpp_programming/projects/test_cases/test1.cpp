#include <iostream>
#include <unistd.h>  // For chdir()
#include <cstring>  // For strerror()

void executeCdCommand(const std::string& path) {
    if (path.empty()) {
        std::cerr << "Error: Missing path argument for cd command." << std::endl;
        return;
    }

    if (chdir(path.c_str()) == 0) {
        // Change directory successful
        std::cout << "Directory changed successfully." << std::endl;
    } else {
        // Change directory failed
        std::cerr << "Error changing directory: " << strerror(errno) << std::endl;
    }
}

int main (){
//break
return 0;

}
