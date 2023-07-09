// Variable Declaration
char *vidptr = (char*)0xb8000;
unsigned int j = 0;
unsigned int i = 0;
unsigned int x = 0;
unsigned int currLine = 0;
unsigned int isLineEnd = 0;
char *kout;

// Screen Driver
void println(char *str, unsigned int line) {
	i = (line*160);
	while(str[j] != 0) {
		vidptr[i] = str[j];
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
		x++;
	}

	currLine++;
	j = 0;
	i = 0;
} 



void clearScreen(void) {
	while(j < 80 * 25 * 2) {
		vidptr[j] = ' ';
		vidptr[j+1] = 0x07;
		j = j + 2;
	
	
	}
	j = 0;
}

void clearLine(unsigned int line) {
	j = (line*160);
	while(j < (j+159)) {
		vidptr[j] = ' ';
		vidptr[j+1] = 0x07;
		j = j + 2;
	}
	j = 0;
}

// Keyboard driver

void inputStr(void) {

   	while(isLineEnd==0) {
		asm ("in $0x60, %%eax; mov %%eax, %[lbl];"
		: [lbl] "=r" (kout));
		println(kout,currLine);


	}

}


// Main
void kmain(void) {

	
	clearScreen();
	println("Hello World!", currLine);
	println("This is my OS, BoeningBOS", currLine);
	println("You should not see this line", currLine);
	clearLine(2);
	inputStr();
	return;
}
