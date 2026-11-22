#include <stdio.h>
int main() {
    int a[10][10],p[10],n,i,j,k,x,y,u,w,m,c=0,found;
    printf("Enter vertices: ");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++) {
        p[i]=i;
        for(j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    for(k=1;k<n;) {
        found=0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(a[i][j]>0&&(!found||a[i][j]<m))
                    m=a[i][j],x=i,y=j,found=1;
        if(!found) break;
        a[x][y]=a[y][x]=0;
        u=x; while(p[u]!=u) u=p[u];
        w=y; while(p[w]!=w) w=p[w];
        if(u!=w) {
            printf("%d - %d = %d\n",x,y,m);
            c+=m;
            p[u]=w;
            k++;
        }
    }
    printf("Total cost = %d",c);
    return 0;
}
