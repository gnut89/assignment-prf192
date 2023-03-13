#include<stdio.h>


int a;
a = 10;
int b = 20;




int main(){
	int income, income_tax;
	scanf("%d",&income);
	int pa = 9000000;
	int pd = 3600000;
	int n;
	scanf("%d",&n);
	int tf = 12 * (pa + n * pd);
	int ti = imcome - tf;
	if (ti <= 0) {
		income_tax = 0;
	} else {
		if (ti <= 5000000) {
			income_tax = ti * 5 / 100;
		} else if (ti <= 10000000) {
			income_tax = ti * 10 / 100;
		} else if (ti <= 18000000) {
			income_tax = ti * 15 / 100;
		} else {
			income_tax = ti * 20 / 100;
		}
	}
	printf("%d %d %d", imcome, ti, income_tax);
	return 0;
}