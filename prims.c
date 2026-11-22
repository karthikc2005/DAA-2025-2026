#include <stdio.h>
int main() {
    int a[10][10],v[10]={0},n,i,j,k,min,x,y,c=0,found;
    printf("Enter vertices: ");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) scanf("%d",&a[i][j]);
    v[0]=1;
    for(k=1;k<n;k++) {
        found=0;
        for(i=0;i<n;i++)
            if(v[i])
                for(j=0;j<n;j++)
                    if(!v[j]&&a[i][j]>0&&(!found||a[i][j]<min))
                        min=a[i][j],x=i,y=j,found=1;
        if(!found) break;
        printf("%d - %d = %d\n",x,y,min);
        c+=min;
        v[y]=1;
    }
    printf("Total cost = %d",c);
    return 0;
}
