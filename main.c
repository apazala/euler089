#include <stdio.h>
#include <string.h>

char input[1005];
char output[1005];

int getinput(int *len) {
	int n = 0;

	char *pin = input;
	while (*pin == 'M') {
		n += 1000;
		pin++;
	}

	if (*pin == 'C' && *(pin+1) == 'M') {
		n += 900;
		pin += 2;
	}

	if (*pin == 'D') {
		n += 500;
		pin++;
	}

	if (*pin == 'C' && *(pin + 1) == 'D') {
		n += 400;
		pin += 2;
	}

	while (*pin == 'C') {
		n += 100;
		pin++;
	}

	if (*pin == 'X' && *(pin + 1) == 'C') {
		n += 90;
		pin += 2;
	}



	if (*pin == 'L') {
		n += 50;
		pin++;
	}

	if (*pin == 'X' && *(pin + 1) == 'L') {
		n += 40;
		pin += 2;
	}

	while (*pin == 'X') {
		n += 10;
		pin++;
	}

	if (*pin == 'I' && *(pin + 1) == 'X') {
		n += 9;
		pin += 2;
	}

	if (*pin == 'V') {
		n += 5;
		pin++;
	}

	if (*pin == 'I' && *(pin + 1) == 'V') {
		n += 4;
		pin += 2;
	}

	while (*pin == 'I') {
		n++;
		pin++;
	}

	*len = (pin - input);
	return n;
}

void solve(int n, int *len) {
	int i = 0;

	while (n >= 1000) {
		output[i++] = 'M';
		n -= 1000;
	}

	if (n >= 900) {
		output[i++] = 'C';
		output[i++] = 'M';
		n -= 900;
	}

	if (n >= 500) {
		output[i++] = 'D';
		n -= 500;
	}

	if (n >= 400) {
		output[i++] = 'C';
		output[i++] = 'D';
		n -= 400;
	}

	while (n >= 100) {
		output[i++] = 'C';
		n -= 100;
	}

	if (n >= 90) {
		output[i++] = 'X';
		output[i++] = 'C';
		n -= 90;

	}

	if (n >= 50) {
		output[i++] = 'L';
		n -= 50;
	}

	if (n >= 40) {
		output[i++] = 'X';
		output[i++] = 'L';
		n -= 40;
	}

	while (n >= 10) {
		output[i++] = 'X';
		n -= 10;
	}

	if (n >= 9) {
		output[i++] = 'I';
		output[i++] = 'X';
		n -= 9;
	}

	if (n >= 5) {
		output[i++] = 'V';
		n -= 5;
	}

	if (n >= 4) {
		output[i++] = 'I';
		output[i++] = 'V';
		n -= 4;
	}

	while (n >= 1) {
		output[i++] = 'I';
		n--;
	}


	output[i] = '\0';
	*len = i;
}

int main()
{
	char filename[] = "p089_roman.txt";

	FILE *fin = fopen(filename, "r");
	if (!fin) {
		fprintf(stderr, "Can't open input file: %s\n", filename);
		return 1;
	}

	int ans = 0, len;
	while (fscanf(fin, "%s", input) == 1) {
		int n = getinput(&len);
		
		ans += len;

		solve(n, &len);

		ans -= len;

		//puts(output);
	}

	printf("%d\n", ans);

	fclose(fin);

	return 0;
}
