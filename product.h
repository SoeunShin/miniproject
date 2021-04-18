#include <stdio.h>

typedef struct{
    char name[50]; // 제품명
    int weight; // 중량
    int price; // 판매가격
    int score; // 별점
    int s_cnt; // 별점개수
} Product;

int createProduct(Product *p); // 제품을 추가하는 함수
void readProduct(Product p); // 제품 하나를 출력하는 함수
int updateProduct(Product *p); // 제품을 수정하는 함수
int deleteProduct(Product *p); // 제품을 삭제하는 함수
