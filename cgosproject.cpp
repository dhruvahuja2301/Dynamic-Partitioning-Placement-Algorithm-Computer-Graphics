#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void max(int m[],int nm,float pos[])
{
    for(int i=0;i<nm-1;i++)
    {
        for(int j=0;j<nm-1;j++)
        {
            if(m[j+1]>m[j])
            {
                int temp=m[j+1];
                m[j+1]=m[j];
                m[j]=temp;
                float temp1=pos[j+1];
                pos[j+1]=pos[j];
                pos[j]=temp1;
            }
        }
    }
}
void min(int m[],int nm,float pos[])
{
    for(int i=0;i<nm-1;i++)
    {
        for(int j=0;j<nm-1;j++)
        {
            if(m[j+1]<m[j])
            {
                int temp=m[j+1];
                m[j+1]=m[j];
                m[j]=temp;
                float temp1=pos[j+1];
                pos[j+1]=pos[j];
                pos[j]=temp1;
            }
        }
    }
}
void worstfit(int m[],int p[],int nm,int np,int i,int f[],int l[],int h[],float ratio,float pos[])
{
    static int z=0;
    for(int j=0;j<nm;j++)
    {
        if(p[i]<=m[j])
        {
            if(f[j]==0)
            {
                float x=p[i]*ratio;
                if(x<=1)
                {
                    printf("small size not visible");
                    h[i]=1;
                    break;
                }
                printf("%d in %d of color ",p[i],m[j]);
                setcolor(5+i);
                int c=getcolor();
                printf("%d\n",c);
                rectangle(100,pos[j]+100,300,pos[j]+x+100);
                setfillstyle(8,5+i);
                floodfill(110,pos[j]+101,5+i);
                if(x>=10)
                {
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                else
                {
                    settextstyle(2,0,0.005);
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                pos[j]=pos[j]+x;
            }
            else
            {
                printf("%d in %d (%d number of partion) of color ",p[i],m[j],f[j]);
                float x=p[i]*ratio;
                if(x<=1)
                {
                    printf("small size not visible");
                    h[i]=1;
                    break;
                }
                setcolor(5+i);
                int c=getcolor();
                printf("%d\n",c);
                rectangle(100,pos[j]+100,300,pos[j]+x+100);
                setfillstyle(8,5+i);
                floodfill(110,pos[j]+101,5+i);
                if(x>=10)
                {
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                else
                {
                    settextstyle(2,0,0.005);
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                pos[j]=pos[j]+x;
            }
            m[j]=m[j]-p[i];
            f[j]++;
            l[i]=j;h[i]=1;
            break;
        }
    }
    if(h[i]==0)
    {
        char s1[10];
        printf("%d is waiting\n",p[i]);
        sprintf(s1,"%d",p[i]);
        strcat(s1," is waiting");
        outtextxy(400,100+z,s1);
        z=z+20;
    }
}
void bestfit(int m[],int p[],int nm,int np,int i,int f[],int l[],int h[],float ratio,float pos[])
{
    static int z=0;
    for(int j=0;j<nm;j++)
    {
        if(p[i]<=m[j])
        {

            if(f[j]==0)
            {
                float x=p[i]*ratio;
                if(x<=1)
                {
                    printf("small size not visible");
                    h[i]=1;
                    break;
                }
                printf("%d in %d of color ",p[i],m[j]);
                setcolor(5+i);
                int c=getcolor();
                printf("%d\n",c);
                rectangle(100,pos[j]+100,300,pos[j]+x+100);
                setfillstyle(8,5+i);
                floodfill(110,pos[j]+101,5+i);
                if(x>=10)
                {
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                else
                {
                    settextstyle(2,0,0.005);
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                pos[j]=pos[j]+x;
            }
            else
            {
                printf("%d in %d (%d number of partion) of color ",p[i],m[j],f[j]);
                float x=p[i]*ratio;
                if(x<=1)
                {
                    printf("small size not visible");
                    h[i]=1;
                    break;
                }
                setcolor(5+i);
                int c=getcolor();
                printf("%d\n",c);
                rectangle(100,pos[j]+100,300,pos[j]+x+100);
                setfillstyle(8,5+i);
                floodfill(110,pos[j]+101,5+i);
                if(x>=10)
                {
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                else
                {
                    settextstyle(2,0,0.005);
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);

                }
                pos[j]=pos[j]+x;
            }
            m[j]=m[j]-p[i];
            f[j]++;
            l[i]=j;h[i]=1;
            break;
        }
    }
    if(h[i]==0)
    {
        char s1[10];
        printf("%d is waiting\n",p[i]);
        sprintf(s1,"%d",p[i]);
        strcat(s1," is waiting");
        outtextxy(400,100+z,s1);
        z=z+20;
    }
}
void firstfit(int m[],int p[],int nm,int np,int i,int f[],int l[],int h[],float ratio,float pos[])
{
    static int z=0;
    for(int j=0;j<nm;j++)
    {
        if(p[i]<=m[j])
        {
            if(f[j]==0)
            {
                float x=p[i]*ratio;
                if(x<=1)
                {
                    printf("small size not visible");
                    h[i]=1;
                    break;
                }
                printf("%d in %d of color ",p[i],m[j]);
                setcolor(5+i);
                int c=getcolor();
                printf("%d\n",c);
                rectangle(100,pos[j]+100,300,pos[j]+x+100);
                setfillstyle(8,5+i);
                floodfill(110,pos[j]+101,5+i);
                if(x>=10)
                {
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                else
                {
                    settextstyle(2,0,0.005);
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                pos[j]=pos[j]+x;
            }
            else
            {
                printf("%d in %d (%d number of partion) of color ",p[i],m[j],f[j]);
                float x=p[i]*ratio;
                if(x<=1)
                {
                    printf("small size not visible");
                    h[i]=1;
                    break;
                }
                setcolor(5+i);
                int c=getcolor();
                printf("%d\n",c);
                rectangle(100,pos[j]+100,300,pos[j]+x+100);
                setfillstyle(8,5+i);
                floodfill(110,pos[j]+101,5+i);
                if(x>=10)
                {
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                else
                {
                    settextstyle(2,0,0.005);
                    char str[5];
                    sprintf(str,"%d",p[i]);
                    outtextxy(70,pos[j]+100+(x/2)-5,str);
                }
                pos[j]=pos[j]+x;
            }
            m[j]=m[j]-p[i];
            f[j]++;
            l[i]=j;h[i]=1;
            break;
        }
    }
    if(h[i]==0)
    {
        char s1[10];
        printf("%d is waiting\n",p[i]);
        sprintf(s1,"%d",p[i]);
        strcat(s1," is waiting");
        outtextxy(400,100+z,s1);
        z=z+20;
    }
}
int main()
{
    int m[10],m1[10],p[10],ch,sum=0;
    int nm,np,gd=DETECT,gm;
    printf("enter number of holes:");
	scanf("%d",&nm);
	printf("enter number of processes:");
	scanf("%d",&np);
	for(int i=0;i<nm;i++)
	{
		printf("enter size of hole %d in Kb:",i+1);
		scanf("%d",&m1[i]);
		sum+=m1[i];
	}
    float ratio=300.0/sum,pos[10]={0.0f},temp=0;
    initgraph(&gd,&gm,"c:\\bgi");
    do
    {
        int f[10]={0},l[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},h[10]={0};
        printf("1.FirstFit\n2.BestFit\n3.WorstFit\n4.Exit\nEnter choice:");
        scanf("%d",&ch);
        ratio=300.0/sum;pos[10]={0.0f};temp=0;
        for(int i=0;i<nm;i++)
        {
            m[i]=m1[i];
            pos[i]=temp;
            temp=temp+(ratio*m[i]);
        }
        cleardevice();
        rectangle(100,100,300,400);
        for(int j=0;j<nm;j++)
        line(100,pos[j]+100,300,pos[j]+100);
        switch(ch)
        {
            case 1:
                printf("FIRST FIT : \n");
                for(int i=0;i<np;i++)
                {
                    printf("enter size of process %d in Kb:",i+1);
                    scanf("%d",&p[i]);
                    firstfit(m,p,nm,np,i,f,l,h,ratio,pos);
                }
                break;
            case 2:
                printf("BEST FIT : \n");
                min(m,nm,pos);
                for(int i=0;i<np;i++)
                {
                    printf("enter size of process %d in Kb:",i+1);
                    scanf("%d",&p[i]);
                    bestfit(m,p,nm,np,i,f,l,h,ratio,pos);
                }
                break;
            case 3:
                printf("WORST FIT : \n");
                max(m,nm,pos);
                for(int i=0;i<np;i++)
                {
                    printf("enter size of process %d in Kb:",i+1);
                    scanf("%d",&p[i]);
                    worstfit(m,p,nm,np,i,f,l,h,ratio,pos);
                }
                break;
            default:
                printf("\nEnter choice between 1 and 4\n");
        }
        pos[nm]=400.0f;
        for(int i=0;i<nm;i++)
        {
            float x=m[i]*ratio;
            if(x<1)
                continue;
            setcolor(15);
            rectangle(100,pos[i]+100,300,pos[i]+(ratio*m[i]+100));
            setfillstyle(8,15);
            floodfill(110,pos[i]+101,15);
            if(x>=10)
            {
                char str[5];
                sprintf(str,"%d",m[i]);
                outtextxy(70,pos[i]+100+(x/2)-5,str);
            }
            else
            {
                settextstyle(2,0,0.005);
                char str[5];
                sprintf(str,"%d",m[i]);
                outtextxy(70,pos[i]+100+(x/2)-5,str);
            }
        }
    }while(ch!=4);
    getch();
}
