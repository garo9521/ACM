#include <bits/stdc++.h>
using namespace std;

int num[6];

void proceso (){
    scanf ("%d",&num[1]);
    scanf ("%d",&num[2]);
    scanf ("%d",&num[3]);
    while (num[1] != 0 || num[2] != 0 || num[3] != 0){
        sort (num + 1, num + 1 + 3);
        if (num[1] == num[2] && num[1] == num[3]){
            if (num[1] < 13){
                printf ("%d %d %d\n",num[1] + 1, num[1] + 1, num[1] + 1);
            }else{
                printf ("*\n");
            }
        }else{
            if (num[1] == num[2]){
                if (num[3] < 13){
                    if (num[1] - 1 == num[3]){
                        printf ("%d %d %d\n",num[1], num[1], num[3] + 2);
                    }else{
                        printf ("%d %d %d\n",num[1], num[1], num[3] + 1);
                    }
                }else{
                    printf ("1 %d %d\n",num[1] + 1, num[1] + 1);
                }
            }else{
                if (num[2] == num[3]){
                    if (num[1] == num[2] - 1){
                        if (num[2] == 13){
                            printf ("1 1 1\n");
                        }else{
                            printf ("%d %d %d\n", num[2], num[2], num[1] + 2);
                        }
                    }else{
                        printf ("%d %d %d\n",num[1] + 1, num[2], num[2]);
                    }                                        
                }else{
                    printf ("1 1 2\n");
                }
            }
        }
        scanf ("%d",&num[1]);
	    scanf ("%d",&num[2]);
	    scanf ("%d",&num[3]);
    }
}

int main (){

    proceso ();
    return 0;
}