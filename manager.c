#include <stdio.h>
#include <string.h>
#include "manager.h"

// 상품 목록 보기 
void listProduct(Product *p, int cnt){
    printf("No\t제품명\t\t\t\t\t   중량      판매가격  별점\t 별점개수\n");
    printf("=========================================================================================\n");
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
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("7. 별점검색\n");
    printf("8. 가격검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

// 파일에 저장하기
void saveFile(Product *p, int cnt){
    FILE *fp;
    fp = fopen("product.txt", "wt");
    for(int i=0; i<cnt; i++){
        if(p[i].price == -1) continue;
        fprintf(fp, "%s\t%d\t%d\t%d\t%d\n", p[i].name, p[i].weight, p[i].price, p[i].score, p[i].s_cnt);
    }
    fclose(fp);
    printf("저장됨!\n");
}

// 파일 줄 세기
int fileLine(){
        FILE *fp;
        char ch;
        int linenum=0;
        fp=fopen("product.txt", "r");
        while((ch=fgetc(fp)) != EOF)
                if (ch == '\n')
                        linenum++;
        fclose(fp);
        return linenum;
}

// 파일내용 불러오기
int loadData(Product *p){
        int i=0;
        FILE *fp = fopen("product.txt", "rt");
        int line = fileLine();
        for(; i<line; i++){
                if(feof(fp)) break;
                fscanf(fp, "%s", p[i].name);
                fscanf(fp, "%d", &p[i].weight);
                fscanf(fp, "%d", &p[i].price);
                fscanf(fp, "%d", &p[i].score);
                fscanf(fp, "%d", &p[i].s_cnt);
        }
        fclose(fp);
        return i;
}

// 상품명 검색
void searchName(Product *p, int cnt){
    int pcnt = 0;
    char pname[50];

    printf("검색할 제품명? ");
    scanf("%s", pname);

    printf("No\t제품명\t\t\t\t\t   중량      판매가격  별점\t 별점개수\n");
    printf("=========================================================================================\n");
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
    printf("=========================================================================================\n");
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

// 가격 검색
void searchPrice(Product *p, int cnt){
        int pcnt = 0;
        int pprice;

        printf("검색할 가격? ");
        scanf("%d", &pprice);

        printf("No\t제품명\t\t\t\t\t   중량      판매가격  별점\t 별점개수\n");
        printf("=====================================================================================\n");
        for(int i=0; i<cnt; i++){
                if(p[i].price == -1) continue;
                if(p[i].price == pprice){
                        printf("%d", i+1);
                        readProduct(p[i]);
                        pcnt++;
                }
        }
        if(pcnt==0)
                printf("=> 검색된 데이터 없음!\n");
}
