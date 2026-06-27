#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    printf("Welcome to IT007, I am CT230012!\n");
    sleep(2); 

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        printf("Dang khoi dong vim de mo file abcd.txt...\n");
        execlp("vim", "vim", "abcd.txt", NULL);
        perror("Khong the mo vim");
        exit(1);
    } 
    else {
        wait(NULL);
        printf("\n[Tien trinh cha]: Ban da thoat khoi vim. Chuong trinh ket thuc.\n");
    }
    return 0;
}
