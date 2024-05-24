#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define MAX_STR_LEN 10

int isOperator(char c) {
    return (c == '*' || c == '/' || c == '+' || c == '-' || c == '=');
}

int isDelimiter(char c) {
    return (c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == ',');
}

int main() {
    char input[] = "int a = x*(2+y);";
    char ans[100][MAX_STR_LEN + 1]; // +1 for null terminator
    char curr[MAX_STR_LEN + 1]; // +1 for null terminator
    int curr_count = 0;
    int ans_count = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (isOperator(input[i]) || isDelimiter(input[i])) {
            if (curr_count > 0) {
                curr[curr_count] = '\0'; // Null terminate the current word
                strcpy(ans[ans_count++], curr);
                curr_count = 0;
            }
            ans[ans_count][0] = input[i];
            ans[ans_count++][1] = '\0'; // Null terminate the operator/delimiter
        } else if (isspace(input[i])) {
            if (curr_count > 0) {
                curr[curr_count] = '\0'; // Null terminate the current word
                strcpy(ans[ans_count++], curr);
                curr_count = 0;
            }
        } else {
            curr[curr_count++] = input[i];
        }
    }

    // Handle the last word
    if (curr_count > 0) {
        curr[curr_count] = '\0'; // Null terminate the last word
        strcpy(ans[ans_count++], curr);
    }

    // Print the ans array
    for (int i = 0; i < ans_count; i++) {
        printf("%s:", ans[i]);
        if(strlen(ans[i])==1 && !isalpha(ans[i][0])){
            if(isOperator(ans[i][0])) printf("operator\n");
            else if(isDelimiter(ans[i][0])) printf("delimiter\n");
            else if(isdigit(ans[i][0])) printf("constant\n");
            else printf("special character\n");
        }
        else {
            char keys[][10] = {"int","for","float","char","while","if","else"};
            int flag = 1;
            for(int j=0;j<7;j++){
                if(strcmp(ans[i],keys[j])==0){
                printf("keyword\n");
                flag = 0;
                break;    
                } 
            }
            if(flag==1) printf("identifier\n");
        }
    }

    return 0;
}
