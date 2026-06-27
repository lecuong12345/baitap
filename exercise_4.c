#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/wait.h>

#include <sys/types.h>



int main() {

    // --- Yêu cầu a: In ra dòng chữ chào mừng kèm MSSV ---

    // Hãy thay thế "22520123" bằng mã số sinh viên thật của bạn

    printf("Welcome to IT007, I am CT230012!\n"); 

    

    // Đợi 2 giây để người dùng kịp nhìn thấy dòng chữ chào mừng trước khi chuyển qua vim

    sleep(2); 



    // --- Yêu cầu b: Mở tệp abcd.txt bằng vim ---

    pid_t pid = fork();



    if (pid < 0) {

        // Nếu fork thất bại

        perror("Fork failed");

        return 1;

    } 

    else if (pid == 0) {

        // Đây là tiến trình con

        // Tiến trình con sẽ bị thay thế hoàn toàn bởi trình soạn thảo vim

        // Lệnh tương đương trong terminal: vim abcd.txt

        printf("Dang khoi dong vim de mo file abcd.txt...\n");

        execlp("vim", "vim", "abcd.txt", NULL);

        

        // Nếu hàm execlp chạy thành công, các dòng lệnh bên dưới sẽ KHÔNG BAO GIỜ được chạy.

        // Nếu nó chạy xuống đây nghĩa là hệ thống của bạn chưa cài "vim".

        perror("Khong the mo vim (Co the do chua cai dat vim)");

        exit(1);

    } 

    else {

        // Đây là tiến trình cha

        // Tiến trình cha tạm dừng để chờ tiến trình con (vim) kết thúc

        wait(NULL);

        printf("\n[Tien trinh cha]: Ban da thoat khoi vim. Chuong trinh ket thuc.\n");

    }



    return 0;

}
