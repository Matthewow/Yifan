#include <stdio.h>
#include <stdlib.h>

int main()
{
    int teams[10][4] = {0};
    // score of match, Goals For,Goals Against ,Goal Difference 
    int count = 0;
    for(int i=1; i<=10; i++){
        for(int j=1;j<=10;j++){
            if(i >= j){
                continue;
        }
            int a = rand() % 10 % 5;
            int b = rand() % 10 % 5;
            teams[i-1][1] += a;
            teams[i-1][2] += b;
            teams[j-1][1] += b;
            teams[j-1][2] += a;
            
            if (a == b){
                teams[i-1][0] += 1;
                teams[j-1][0] += 1;
            }
            if (a > b){
                teams[i-1][0] += 3;
                teams[j-1][0] += 0;
            }
            if (a < b){
                teams[i-1][0] += 0;
                teams[j-1][0] += 3;
            }
            count = count + 1;
            printf("\nMatch %d: team %d vs team %d",count, i, j);
            printf("\nresult is %d : %d", a, b);
            printf("\n------------------");
      }
    }

    printf("\n ========FINAL RANKING========");
    for(int i=0; i<10; i++){
        teams[i][3] = teams[i][1] - teams[i][2];
        printf("\nTeam %d's score is %d, Goals Difference is %d", i+1, teams[i][0], teams[i][3]);
    }
    return 0;
}
