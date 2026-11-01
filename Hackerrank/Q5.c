#include<stdio.h>                                      
#include<stdlib.h>                                     
#include<string.h>                                     
#include<stdbool.h>                                    
                                                       
                                                       
struct Node                                            
{                                                      
    char data;                                         
    struct Node *next;                                 
};                                                     
struct Stack                                           
{                                                      
    struct Node *top;                                  
};                                                     
                                                       
                                                       
                                                       
                                                       
struct Stack* createStack()                              
{                                                      
    struct Stack *stack = malloc(sizeof(struct Stack)); 
                                                       
                                                       
    stack->top = NULL;                                 
                                                       
                                                       
    return stack;                                      
}                                                        
                                                       
                                                       
struct Node* createNode(char value)                    
{                                                      
    struct Node *newNode = malloc(sizeof(struct Node));
                                                       
                                                       
    newNode->data = value;                             
    newNode->next = NULL;                              
                                                       
                                                       
    return newNode;                                    
}                                                      
                                                                                                            
                                                       
                                                                                                                                                             
int isEmpty(struct Stack *stack){                      
    if(stack->top == NULL){                            
        return 1;                                      
    }                                                  
    return 0;                                          
}                                                      
                                                       
                                                       
void push(struct Stack *stack,char value){             
    struct Node *newNode = createNode(value);          
                                                       
                                                       
    if(isEmpty(stack)){                                
        stack->top = newNode;                          
        return;                                        
    }                                                  
                                                       
                                                       
                                                       
    newNode->next = stack->top;                        
    stack->top = newNode;                              
}                                                      
                                                       
                                                       
char pop(struct Stack *stack){                         
    if(isEmpty(stack)){                                
        printf("Empty\n");                             
        return '\0';                                   
    }                                                  
    struct Node *temp = stack->top;                    
    char tempValue = stack->top->data;                 
                                                       
                                                       
    stack->top = stack->top->next;                     
    free(temp);                                        
    return tempValue;                                  
}                                                      
                                                       
                                                       
void displayStack(struct Stack *stack){                
    if(isEmpty(stack)){                                
        printf("Stack is an Empty\n");                 
        return;                                        
    }                                                  
    struct Node *temp = stack->top;                    
                                                       
                                                       
                                                       
                                                       
    while(temp != NULL){                               
        printf("%c -> ", temp->data);                  
        temp=temp->next;                               
    }                                                  
} 

int isMatchingPair(char opening,char closing)       
{                                                   
    if(opening == '(' && closing == ')')            
        return 1;                                   
    if(opening == '{' && closing == '}')            
        return 1;                                   
    if(opening == '[' && closing == ']')            
        return 1;                                   
    return 0;                                       
}                                                   
                                                                                                                                                                                                      
int isBalanced(char paranthesis[]){                  
    struct Stack *stack= createStack();                             
                                    
                                                    
    for(int i = 0; paranthesis[i] !='\0';i++ ){     
        char ch= paranthesis[i]; 
                                                    
        if(ch == '(' || ch == '{' || ch == '[')     
        {                                           
            push(stack,ch);                        
        }                                           
        else if(ch == ')' || ch == '}' || ch == ']')
        {                                           
            if(isEmpty(stack))                     
            {                                       
                printf("Mismatch at position %d: \n",i+1);   
                return 0;                           
            }                                       
            char opening = pop(stack);             
                                                    
                                                    
            if(!isMatchingPair(opening,ch))         
            {  
                printf("Mismatch at position %d:\n",i+1);
                free(stack);                           
                return 0;                           
            }                                       
        }                                           
    }  
    if(isEmpty(stack))
    {
        return 1;
    }
    else
    {
        return 0;
    }                                             
                                                    
                                                    
}                                                   



int main()                                        
{          
    struct Stack *stack= createStack();                                                                                              
    char paranthesis[][50] =                                                                              
    {                                             
        "(a+b)",                                  
        "{[a+b]*(c-d)}",                          
        "((a+b)",                                 
        "(a+b])",                                 
        "[{()}]",                                 
        "a+b)"                                    
    };                                            
                                                  
                                                  
    int n = 6;                                    
                                                  
                                                  
    for(int i = 0; i < n; i++)                    
    {                                             
        printf("Expression: %s\n", paranthesis[i]);
                                                  
                                                  
        if(isBalanced(paranthesis[i]))             
            printf(" Balanced\n");                
        else                                      
            printf(" Not Balanced\n");            
                                                  
                                                  
        printf("\n");                             
    }                                             
                                                  
                                                  
    return 0;                                     
}                                                 