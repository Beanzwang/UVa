#include<stdio.h>
#include<stdlib.h>

struct Matrix {
    char name;
    int row;
    int col;
};

void read_matrix();
void read_multi();
int isEmpty();
int isFull();
void push(struct Matrix m);
struct Matrix pop();
struct Matrix peek();

int MAXSIZE = 10000;
struct Matrix stack[10000];
int top = -1;

unsigned int num;
struct Matrix *matrix;
int main() {
    read_matrix();
    read_multi();
    return 0;
}

void read_matrix() {
    scanf("%u\n", &num);
    int i = 0;
    matrix = malloc((num) * sizeof(struct Matrix));
    while(i < num) {
        scanf("%c %d %d\n", &matrix[i].name, &matrix[i].row, &matrix[i].col);
        i++;
    }
}

void read_multi() {
    char c;
    char pop_char;
    int i, j;
    int cur_num = -1;
    int error = 0;
    int cur_multi = 0;
    while((c = getchar()) != EOF) {
        struct Matrix temp;
        if (c >= 'A' && c <= 'Z') {
            int char_num = c - 65;
            temp.name = c;
            temp.row = matrix[char_num].row;
            temp.col = matrix[char_num].col;
            push(temp);
        } else if (c == '(') {
            temp.name = '(';
            temp.row = -1;
            temp.col = -1;
            push(temp);
        } else if (c == ')') {
             temp = pop();
             int row_1 = temp.row;
             int col_1 = temp.col;

             temp = pop();
             int row_2 = temp.row;
             int col_2 = temp.col;
             
             if (col_2 != row_1) {
                 printf("error\n");
                 error = 1;
             }
             pop();  /* pop out '(' */
             temp.name = '0';
             temp.row = row_2;
             temp.col = col_1;
             cur_multi += row_2 * col_2 * col_1;
             push(temp);
             
        } else if (c == '\n'){
            while(!isEmpty()) {
                pop();
                if (error == 0) {
                    printf("%d\n", cur_multi);
                }
                error = 0;
                cur_multi = 0;
            }
        }
    }
}

int isEmpty() {
    if (top == -1) return 1;
    else return 0;
}

int isFull () {
    if (top < MAXSIZE) return 0;
    else return 1;
}

void push(struct Matrix m) {
    if (!isFull()) {
        top++;
        stack[top].name = m.name;
        stack[top].row = m.row;
        stack[top].col = m.col;
    } else {
        printf("is Full!\n");
    }
}

struct Matrix pop() {
    struct Matrix stack_matrix = stack[top];
    top--;
    return stack_matrix;
}

struct Matrix peek() {
    return stack[top];
}