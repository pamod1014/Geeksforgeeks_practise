#include<stdio.h>
#include<string.h>
void Reversed(char*string){
            int l=strlen(string);
            for(int i=0;i<l/2;i++){
                char temp=string[i];
                string[i]=string[l-i-1];
                string[l-i-1]=temp;
            }
        }
        void print(char*string){
            printf("%s",string);
        }
        int main(){
            char str[50];
            printf("enter the string:");
            scanf("%s",str);
            if(strlen(str)>50){
                printf("string is too long");
            }
            else{
                Reversed(str);
                print(str);
            }
            return 0;
        }