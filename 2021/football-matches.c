#include <stdio.h>
#include <stdlib.h>

#define TEAM_NUM 10

int main()
{
    int teams[TEAM_NUM][5] = {0}, count = 0;
    // score of match, Goals For,Goals Against ,Goal Difference 

    for(int i = 0; i < TEAM_NUM; i++){
        for(int j = 0; j < TEAM_NUM; j++){
            if(i >= j)
                continue;

            int a = rand() % 10 % 5, b = rand() % 10 % 5;
            teams[i][1] += a;
            teams[i][2] += b;
            teams[j][1] += b;
            teams[j][2] += a;
            
            if (a == b){
                teams[i][0] += 1;
                teams[j][0] += 1;
            }
            if (a > b){
                teams[i][0] += 3;
                teams[j][0] += 0;
            }
            if (a < b){
                teams[i][0] += 0;
                teams[j][0] += 3;
            }
            count = count + 1;
            if(j == 10)
                printf("\n|  Match %d: team %d vs team %d |", count, i + 1, j + 1);
            else 
                printf("\n|  Match %d: team %d vs team %d  |",count, i + 1, j + 1);
            printf("\n|  Result:       %d  :  %d       |", a, b);
            printf("\n -------------------------------");
      }
    }

    printf("\n ========FINAL RANKING========");
    
    for(int i = 0; i < TEAM_NUM; i++){
        teams[i][3] = teams[i][1] - teams[i][2];
        printf("\nTeam %d's score is %d, Goals Difference is %d", i+1, teams[i][0], teams[i][3]);
    }
    return 0;
}
