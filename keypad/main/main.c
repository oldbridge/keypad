#include <stdio.h>
main(){
	init_keypad();
	printf("Starts \n");
	char in_char;
	in_char=wait_key();
	printf("Tekla: %c \n",in_char);
}
