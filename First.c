#include<stdio.h>
#include<ctype.h>
#include<string.h>
char productions[10][20];
int n=10;
int nonTerminal[26];
char subResult[100];
int subresult_pos=0;

void First(char c){
    if(c<65 || c>90){
        subResult[subresult_pos++]=c;
        subResult[subresult_pos]='\0';
        return;
    }
    for(int i=0;i<n;i++){
        if(productions[i][0]==c){
            int j=3;
            while(j<strlen(productions[i]) && productions[i][j]=='#'){
                j++;
            }
            if(j==strlen(productions[i])){
                subResult[subresult_pos++]='#';
                subResult[subresult_pos]='\0';
            }
            else{
                First(productions[i][j]);
            }
        }
    }

}

int main(){

    printf("Enter the no of productions:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter production %d:\n",i+1);
        scanf("%s",productions[i]);
        nonTerminal[productions[i][0]-'A']=1;
    }
    for(int i=0;i<26;i++){
        if(nonTerminal[i]==1){
           
            First(i+'A');
            printf("First of %c:{",i+'A');
            for(int i=0;i<strlen(subResult);i++){
                printf("%c",subResult[i]);
            }
            printf("}\n");
            
            subresult_pos=0;
        }
    }
    return 0;
}
