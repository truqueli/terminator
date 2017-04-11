#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>

int global_var=10;
int main() {
    std::string child_or_parent;
    int local_var=20;
    pid_t pid=fork();
    if(pid==0){
        child_or_parent="Child";
        global_var++;
        local_var++;
    }
    else if(pid>0){
        child_or_parent="Parent";
    } else{
        std::cerr<<"failed fork"<<std::endl;
    }
    std::cout<<child_or_parent<<" global_var: " << global_var <<" local_var: "<<local_var<<std::endl;

}