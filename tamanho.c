#include <sys/ioctl.h>
#include <stdio.h>

void space (int t, char text1[30]){
	if (t%2==0){
		for (int i=1;i<=(t/2);i++){
			printf(" ");
		}
		printf("%s", text1);
		for (int i=1;i<=(t/2);i++){
			printf(" ");
		}
	}else{
		for (int i=0;i<=(t/2);i++){
			printf(" ");
		}
		printf("%s", text1);
		for (int i=1;i<=(t/2);i++){
			printf(" ");
		}
	}
}

int main (void)
{
	int i,j;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    for (i = 1; i<=w.ws_col; i++){
    	printf("#");
    }
    w.ws_row--;
	printf("\n#");
	char text[100] = "GereVendas\nMIEI 2015/2016\nLI III\nSpeedy, Maga, Frank, Paul\n";
	char text1[30];
	i=0;
	for (j=0; text[i]!='\0'; i++){
		if (text[i] == '\n'){
			text1[j]='\0';
			space ((w.ws_col-2)-(j),text1);
			printf("#\n#");
			j=0;
			w.ws_row--;
		}else{
			text1[j] = text[i];
			j++;
		}
	}
	for (int i = 0; i<=(w.ws_row-3); i++){
		text1[0]='\0';
		space(w.ws_col-2,text1);
    	printf("#\n#");
    }
	for (int i = 2; i<=w.ws_col; i++){
    	printf("#");
    }
    printf("\n");
    return 0;
}