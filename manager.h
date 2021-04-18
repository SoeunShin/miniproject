#include <stdio.h>
#include "product.h"

int selectMenu(); // 사용자가 원하는 기능을 선택하는 함수
void listProduct(Product *p, int cnt); // 제품을 출력할 때 번호를 부여하는 함수
int selectNo(); // 제품 번호를 고르는 함수
void searchName(Product *p, int cnt); // 제품명을 검색하는 함수
void searchScore(Product *p, int cnt); // 별점을 검색하는 함수
