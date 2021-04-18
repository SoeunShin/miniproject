#include <stdio.h>
#include "manager.h"

int main(void){
    Product plist[20];
    int index = 0;
    int count = 0, menu;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1 && count > 0){
            listProduct(plist, index);
        }
        else if (menu == 1 && count == 0) {
            printf("입력된 상품이 없습니다.\n");
        }
        else if (menu == 2){
            count += createProduct(&plist[index]);
            index++;
        }
        else if (menu == 3){
            listProduct(plist, index);
            printf("\n");
            int no = selectNo(plist, index);
            if (no == 0){
                printf("=> 취소됨!\n");
                continue;
          }
            updateProduct(&plist[no-1]);
        }
        else if (menu == 4){
            listProduct(plist, index);
            printf("\n");
            int no = selectNo(plist, index);
            if (no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int delok;
            printf("정말 삭제하시겠습니까(삭제:1)? ");
            scanf("%d", &delok);
            if (delok == 1) {
                if (deleteProduct(&plist[no-1])) 
                count--;
            }
            else {
                printf("=> 취소됨!\n");
                continue;
            }
        }
        else if(menu == 5){
            searchName(plist, index);
        }
        else if(menu == 6){
            searchScore(plist, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}
