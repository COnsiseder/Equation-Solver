
/******************************************************************************
      SOLVING POLYNOMIAL EQUATIONS AND FINDING UNKOWNS
*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void POLYNOMIAL(void);
void print(long double g[3][4]);
void UNKOWNS(void);
void three(float *a,float *b,float *c,float *d);
int main ()
{ 
    int choice;
    printf("\n                              WELCOME TO MY C PROGRAM!!\n");
    printf("\nI AM GONNA HELP YOU SOLVE POLYNOMIAL EQUATIONS OF DEGREE UPTO 2 AND FINDING UNKOWNS(MAX 3)\n");
    do
    {
        printf("\nselect from the below:\n1.POLYNOMIAL\n2.UNKOWNS\n3.EXIT\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:POLYNOMIAL();
            break;
            case 2:UNKOWNS();
            break;
            case 3:break;
            default:printf("\ninvalid entry..!!!\n");
        }
    }while(choice!=3);
    printf("\nPROGRAM ENDED\n");
    printf("\n\nTHANK YOU !!\n");
    return 0;
}


void POLYNOMIAL(void)
{
    int choice;
    float a,b,c,x1,x2,det;
    label :
   printf("\nchoose one:\n1.ax+b=0\n2.ax^2+bx+c=0\n\n");
   scanf("%d",&choice);
   switch(choice)
   {
       case 1:printf("\nenter cnstants a & b in ax+b\n\n");
       scanf("%f%f",&a,&b);
       if(a==0)
       {
         printf("\nroots don't exist\n");
       }
       else
       {
       x1=-b/a;
       printf("\nroot of equation (%0.3f)x+%0.3f=0 is\n\nx=%f\n",a,b,x1);
       }
       break;
       
       case 2:printf("\nenter the constants a, b, c in ax^2+bx+c\n\n");
       scanf("%f%f%f",&a,&b,&c);
       if(a==0)
       {
           printf("\nnot a quadratice equation\n");
       }
       else
       {
          det=b*b-4*a*c;
          if(det>=0)
          {
            x1=(-b+sqrt(det))/(2*a);
            x2=(-b-sqrt(det))/(2*a);
            printf("\nthe roots of the quadratic equation (%0.3f)x^2+(%0.3f)x+%0.3f=0 are\n\nx1=%f\n\nx2=%f\n",a,b,c,x1,x2);
            if(x1==x2)
            {
              printf("\nthe roots are equal\n");
            }
          }
          else
          {
            printf("\nthe roots are complex\n");
            printf("\nthe roots of the quadratic equation (%0.3f)x^2+(%0.3f)x+%0.3f=0 are\n",a,b,c);
            printf("\nx1=%0.4f+i(%0.4f)\n\nx2=%0.4f-i(%0.4f)\n",-b/2*a,sqrt(-det)/2*a,-b/2*a,sqrt(-det)/2*a);
          }
       }
       break;
       
       default:printf("\nwrong entry..!!\n");
       goto label;
       break;
   }
   
   return;
}


void UNKOWNS(void)
{
   int n,i;
   float a[3],b[3],c[3],d[3],A,B,C;
   label:
   printf("\nenter the number of unkowmns (max 3)\n");
   scanf("%d",&n);
   if(n>3)
   {
       printf("\ninvalid entry..!!\n");
   }
   else
   {
       switch(n)
       {
           case 1:printf("\nenter a & b in ax=b\n\n");
           scanf("%f%f",&a[0],&b[0]);
           printf("\nx=%f\n",b[0]/a[0]);
           break;
           
           case 2:printf("\nenter a1, b1, c1 in a1x+b1y=c1\n");
           scanf("%f%f%f",&a[0],&b[0],&c[0]);
           printf("\nenter a2, b2, c2 in a2x+b2y=c2\n");
           scanf("%f%f%f",&a[1],&b[1],&c[1]);
           B=(a[1]*c[0]-a[0]*c[1])/(b[0]*a[1]-a[0]*b[1]);
           A=(b[1]*c[0]-b[0]*c[1])/(a[0]*b[1]-b[0]*a[1]);
           printf("\nx=%f\n\ny=%f\n",A,B);
           break;
           
           case 3:
           for(i=0;i<3;i++)
           {
               printf("\nenter the a%d, b%d, c%d, d%d in a%dx+b%dy+c%dz=d%d\n",i+1,i+1,i+1,i+1,i+1,i+1,i+1,i+1);
               scanf("%f%f%f%f",&a[i],&b[i],&c[i],&d[i]);
           }
           three(a,b,c,d);
           break;
           
           default:printf("\ninvalid entry..!!!\n");
           goto label;
           break;
       }
   }
   return;
}


void three(float *a,float *b,float *c,float *h)
{
  long double d[3][4],t1,t2,t3;
  int i;
  for(i=0;i<3;i++)
  {
      d[i][0]=*(a+i);
      d[i][1]=*(b+i);
      d[i][2]=*(c+i);
      d[i][3]=*(h+i);
  }
 print(d);
 t1=d[0][0];
 t2=d[1][0];
 t3=d[2][0];
  for(i=0;i<4;i++)
  {
      d[1][i]=t1*d[1][i]-t2*d[0][i];
      d[2][i]=t1*d[2][i]-t3*d[0][i];
  }
  print(d);
  t1=d[1][1];
  t2=d[2][1];
  for(i=1;i<4;i++)
  {
      d[2][i]=t1*d[2][i]-t2*d[1][i];
  }
  print(d);
  if(d[2][2]==0&&d[2][3]!=0)
  printf("\nit has INFINITE SOLUTIONS\n");
  else if(d[2][2]==0&&d[2][2]==0)
  printf("\nit has NO SOLUTION\n");
  else
  {
      t1=d[1][2];
      t2=d[2][2];
      for(i=1;i<4;i++)
      {
        d[1][i]=t2*d[1][i]-t1*d[2][i];
      }
      print(d);
      t1=d[0][1];
      t2=d[0][2];
      for(i=0;i<4;i++)
      {
          d[0][i]=d[1][1]*d[2][2]*d[0][i]-t1*d[1][i]*d[2][2]-t2*d[2][i]*d[1][1];
      }
      print(d);
      printf("\nx=%Lf\n\ny=%Lf\n\nz=%Lf\n",d[0][3]/d[0][0],d[1][3]/d[1][1],d[2][3]/d[2][2]);
  }
  return;

}

void print(long double g[3][4])
{
    int i,j;
    printf("\n\n");
      for(i=0;i<3;i++)
  {
      for(j=0;j<4;j++)
      printf("%Lf\t",g[i][j]);
      printf("\n");
  }
}
