#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // Thư viện POSIX thread

// Hàm thực thi của tiểu trình (Thread function)
void* thread_helper(void* arg) {
    printf("--> Tieu trinh con dang chay...\n");
    sleep(2); // Giả lập tiểu trình làm việc trong 2 giây
    printf("--> Tieu trinh con da hoan thanh va tu giai phong!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t my_thread;
    pthread_attr_t my_attr; // 1. Khai bao bien thuoc tinh

    // 2. Khoi tao thuoc tinh voi gia tri mac dinh
    pthread_attr_init(&my_attr);

    // 3. Thay doi thuoc tinh: Chuyen sang trang thai DETACHED (Doc lap)
    // Tieu trinh nay khi ket thuc se tu thu hoi bo nho, khong can ham pthread_join()
    pthread_attr_setdetachstate(&my_attr, PTHREAD_CREATE_DETACHED);

    printf("Tien trinh chinh: Dang tao tieu trinh con voi thuoc tinh DETACHED...\n");
    
    // 4. Tao tieu trinh va truyen bien thuoc tinh `my_attr` vao tham so thu hai
    if (pthread_create(&my_thread, &my_attr, thread_helper, NULL) != 0) {
        perror("Khong the tao tieu trinh!");
        return 1;
    }

    // 5. Sau khi tao thread xong, ta co the huy bien thuoc tinh vi khong dung den nua
    pthread_attr_destroy(&my_attr);

    // Vi tieu trinh con o trang thai DETACHED, ta KHONG THE va KHONG CAN dung:
    // pthread_join(my_thread, NULL);
    
    // De tien trinh chinh khong bi thoat truoc khi tieu trinh con kip chay xong,
    // ta cho tien trinh chinh ngu 3 giay.
    printf("Tien trinh chinh: Dang doi tieu trinh con hoan thanh (khong dung join)...\n");
    sleep(3);

    printf("Tien trinh chinh: Ket thuc chuong trinh.\n");
    return 0;
}
