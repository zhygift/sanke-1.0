#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

int n;
int snake_x, snake_y;
int food_x, food_y;
int score = 0;

void creatfood(){
    
    while (1)
    {
        food_x = rand() % (n - 2) + 1;
        food_y = rand() % (n - 2) + 1;
        if(food_x != snake_x || food_y != snake_y){
            break;
        }
    }
}

int main(){
    srand((unsigned)time(NULL));

    printf("请输入行列数(建议>=5)：");
    scanf("%d",&n);
    snake_x = n / 2;
    snake_y = n / 2;
    creatfood();
    int key;

    while (1){
        system("cls");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == snake_x && j == snake_y){
                    
                    printf("@");
                }
                else if(i == food_x && j == food_y){
                    printf("s");
                }
                else if(i == 0 || i == n-1 || j == 0 || j == n-1)
                {
                    
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
                if(j != n-1) printf(" ");
            }
            printf("\n");
            
        }

        printf("====================\n");
        printf("当前得分：%d\n", score);
        printf("操作：W上 S下 A左 D右 | 撞墙壁游戏结束\n");
        printf("====================\n");

        if(_kbhit()){
            key = _getch();
            int new_x = snake_x;
            int new_y = snake_y;
            
            switch (key)
            {
                case 'w':
                    new_x--;
                    break;
                
                case 's':
                    new_x++;
                    break;
                
                case 'a':
                    new_y--;
                    break;

                case 'd':
                    new_y++;
                    break;
            
                default:
                    break;
            }
            if(new_x == 0 || new_x == n-1 || new_y == 0 || new_y == n-1)
                {
                    printf("结束\n");
                    return 0;
                }
            if(new_x == food_x && new_y == food_y)
            {
                creatfood();
                score++;
            }   
            snake_x = new_x;
            snake_y = new_y;
                

        }
        Sleep(100);
    }   

    return 0;
}