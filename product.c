#include <stdio.h>
#include "product.h"
#define DEBUG

int createProduct(Product *p){
	#ifdef DEBUG
		printf("=> DEBUGMODE\n");
		getchar();
    		printf("제품명: ");
       		scanf("%[^\n]s", p->name);
    		getchar();
    		printf("중량: ");
    		scanf("%d", &p->weight);
	    	getchar();
	    	printf("판매가격: ");
	    	scanf("%d", &p->price);
	    	getchar();
    		printf("별점: ");
    		scanf("%d", &p->score);
    		getchar();
    		printf("별점개수: ");
    		scanf("%d", &p->s_cnt);
	#endif
    		return 1;
}

void readProduct(Product p){
	printf("\t%-55s%-10d%-10d%-10d%-10d\n", p.name, p.weight, p.price, p.score, p.s_cnt);
}

int updateProduct(Product *p){
	getchar();
	printf("제품명: ");
	scanf("%[^\n]s", p->name);
	getchar();
	printf("중량: ");
	scanf("%d", &p->weight);
    	getchar();
    	printf("판매가격: ");
    	scanf("%d", &p->price);
   	getchar();
    	printf("별점: ");
    	scanf("%d", &p->score);
    	getchar();
    	printf("별점개수: ");
    	scanf("%d", &p->s_cnt);
    	printf("=> 수정됨!\n");
    	return 1;
}

int deleteProduct(Product *p){
	p->weight = -1;
	p->price = -1;
    	p->score = -1;
    	p->s_cnt = -1;
    	printf("=> 삭제됨!\n");
    	return 1;
}
