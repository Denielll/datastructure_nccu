#include <stdio.h>
void ChangeInputTo10_FAIL(int i);
void ChangeInputTo10(void* addr);
void ChangeInputTo10_V2(int* addr);
void ChangeInputTo10_V3(int addr);

void TestChangeInput() {
	int i = 6;
	ChangeInputTo10_FAIL(i);
	printf("%d\n", i);
	/*印出6
	ChangeInputTo10(i): copy i的值，
	之後再把copy的值傳給ChangeInputTo10
	*/

	i = 6;
	ChangeInputTo10(&i); //input為i的記憶體位置。&variable: variable在記憶體的位置
	printf("%d\n", i);//目標：印出10
	i = 6;
	ChangeInputTo10_V2(&i); //input為i的記憶體位置。&variable: variable在記憶體的位置
	printf("%d\n", i);//目標：印出10
	i = 6;
	ChangeInputTo10_V3(&i); //input為i的記憶體位置。&variable: variable在記憶體的位置
	printf("%d\n", i);//目標：印出10


	return;
}

void ChangeInputTo10_FAIL(int i/*產生一個新的，只屬於ChangeInputTo10的變數i*/) {
	i = 10;
}

void ChangeInputTo10(void* addr/*Input 變數儲存某個變數的記憶體位置*/) {
	//記憶體中addr位置 儲存的值改為10
	//*addr = 10; //*addr: 存在記憶體位置addr的值
	//上面的code是錯的，因為電腦不知道addr存的變數型態

	* (int*)addr = 10;// (int*) addr: addr存的是一個int
}

void ChangeInputTo10_V2(int* addr/*Input 變數儲存某個int變數的記憶體位置*/) {
	//記憶體中addr位置 儲存的值改為10

	*addr = 10; //在input的地方已經告訴電腦addr存的是int的位置
}

void ChangeInputTo10_V3(int addr/*Input 變數儲存某個int變數的記憶體位置*/) {
	//記憶體中addr位置 儲存的值改為10

	*(int*)addr = 10; //在input的地方已經告訴電腦addr存的是int的位置
}







int main(void) {
	TestChangeInput();
	getchar();
	return 0;
}
