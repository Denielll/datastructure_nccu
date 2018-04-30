#include <stdio.h>
void ChangeInputTo10_FAIL(int i);
void ChangeInputTo10(void* addr);
void ChangeInputTo10_V2(int* addr);
void ChangeInputTo10_V3(int addr);

void TestChangeInput() {
	int i = 6;
	ChangeInputTo10_FAIL(i);
	printf("%d\n", i);
	/*�L�X6
	ChangeInputTo10(i): copy i���ȡA
	����A��copy���ȶǵ�ChangeInputTo10
	*/

	i = 6;
	ChangeInputTo10(&i); //input��i���O�����m�C&variable: variable�b�O���骺��m
	printf("%d\n", i);//�ؼСG�L�X10
	i = 6;
	ChangeInputTo10_V2(&i); //input��i���O�����m�C&variable: variable�b�O���骺��m
	printf("%d\n", i);//�ؼСG�L�X10
	i = 6;
	ChangeInputTo10_V3(&i); //input��i���O�����m�C&variable: variable�b�O���骺��m
	printf("%d\n", i);//�ؼСG�L�X10


	return;
}

void ChangeInputTo10_FAIL(int i/*���ͤ@�ӷs���A�u�ݩ�ChangeInputTo10���ܼ�i*/) {
	i = 10;
}

void ChangeInputTo10(void* addr/*Input �ܼ��x�s�Y���ܼƪ��O�����m*/) {
	//�O���餤addr��m �x�s���ȧאּ10
	//*addr = 10; //*addr: �s�b�O�����maddr����
	//�W����code�O�����A�]���q�������Daddr�s���ܼƫ��A

	* (int*)addr = 10;// (int*) addr: addr�s���O�@��int
}

void ChangeInputTo10_V2(int* addr/*Input �ܼ��x�s�Y��int�ܼƪ��O�����m*/) {
	//�O���餤addr��m �x�s���ȧאּ10

	*addr = 10; //�binput���a��w�g�i�D�q��addr�s���Oint����m
}

void ChangeInputTo10_V3(int addr/*Input �ܼ��x�s�Y��int�ܼƪ��O�����m*/) {
	//�O���餤addr��m �x�s���ȧאּ10

	*(int*)addr = 10; //�binput���a��w�g�i�D�q��addr�s���Oint����m
}







int main(void) {
	TestChangeInput();
	getchar();
	return 0;
}
