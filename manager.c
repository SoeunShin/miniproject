#include <stdio.h>
#include <string.h>
#include "manager.h"

// 상품 목록 보기 
void listProduct(Product *p, int cnt){
    printf("No\t제품명\t\t\t\t\t   중량      판매가격  별점\t 별점개수\n");
    printf("=============================================================================\n");
    for(int i=0; i<cnt; i++) {
        if (p[i].price == -1) {
            continue;
        }
        printf("%d", i+1);
        readProduct(p[i]);
    }
}

// 상품 번호 선택 
int selectNo(){
    int no;
    printf("번호는 (취소:0)? ");
    scanf("%d", &no);
    return no;
}

// 메뉴 선택
int selectMenu(){
    int menu;
    printf("\n***쇼핑몰***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 이름검색\n");
    printf("6. 별점검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

// 상품명 검색
void searchName(Product *p, int cnt){
    int pcnt = 0;
    char pname[50];

    printf("검색할 제품명? ");
    scanf("%s", pname);

    printf("No\t제품명\t\t\t\t\t   중량      판매가격  별점\t 별점개수\n");
    printf("========================================================================================\n");
    for(int i=0; i<cnt; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, pname)){
            printf("%d", i+1);
            readProduct(p[i]);
            pcnt++;
        }
    }
    if(pcnt==0)
        printf("=> 검색된 데이터 없음!\n");
}

// 별점 검색
void searchScore(Product *p, int cnt){
    int pcnt = 0;
    int pscore;

    printf("검색할 별점? ");
    scanf("%d", &pscore);

    printf("No\t제품명\t\t\t\t\t   중량      판매가격  별점\t 별점개수\n");
    printf("========================================================================================\n");
    for(int i=0; i<cnt; i++){
        if(p[i].price == -1) continue;
        if(p[i].score == pscore){
            printf("%d", i+1);
            readProduct(p[i]);
            pcnt++;
        }
    }
    if(pcnt==0)
        printf("=> 검색된 데이터 없음!\n");
}
