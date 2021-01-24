#include <stdio.h>
#include <stdlib.h>

#define TEAM_NUM 10

int main()
{
    int teams[TEAM_NUM][5] = {0}, count = 0;
    // score of match, Goals For, Goals Against ,Goal Difference 

    for(int i = 0; i < TEAM_NUM; i++){
        for(int j = 0; j < TEAM_NUM; j++){
            if(i >= j)
                continue;

            int a = rand() % 5, b = rand() % 5; // a is Goals for, b is Goals Against
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

    printf("\n ======== FINAL RANKING ========");
    
    for(int i = 0; i < TEAM_NUM; i++){
        teams[i][3] = teams[i][1] - teams[i][2];
        printf("\nTeam %d, score: %d, Goals Difference: %d, Goals For %d", i+1, teams[i][0], teams[i][3], teams[i][1]);
    }
    
    // for (int i = 0; i < TEAM_NUM; i++){
    //     int temp = -1;
    //     for(int j = 0; j < TEAM_NUM; j++){
    //         if(teams[j][4] == 1)
    //             continue;
    //         if(temp == -1)
    //             temp = j;
    //         if(teams[j][0] < teams[temp][0])
    //             continue;
    //         else if(teams[j][0] == teams[temp][0])
    //             continue;
    //         else if(teams[j][1] <= teams[temp][1])
    //             continue;
    //         else
    //             temp = j;
    //     }
    //     teams[temp][4] = 1;
    //     printf("\nNo.%d: Team %d, score: %d, Goals Difference: %d, Goals For %d", i+1, temp+1, teams[temp][0], teams[temp][3], teams[temp][1]);
    // }
    return 0;
}
