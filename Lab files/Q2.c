#include<stdio.h>
#include<string.h>

void main(){  

 char frame[50][50],str[50][50];

 char flag[5];
 strcpy(flag,"flag");

 char esc[5];
 strcpy(esc,"esc");

 int i,j,k=0,n;
 strcpy(frame[k++],"flag");

 printf("Enter no. of bytes in the frame: ");
 scanf("%d",&n);

 printf("Enter the bytes: \n");
 for(i=0;i<=n;i++)
   {
  gets(str[i]);
   }

 printf("\n You entered :\n");
 for(i=0;i<=n;i++)
  {
  printf("%s ", str[i]);
  }

 printf("\n");
 for(i=0;i<=n;i++)
   {
      if(strcmp(str[i],flag)!=0 && strcmp(str[i],esc)!=0)
            {
                   strcpy(frame[k++],str[i]);
            }
      else
         {
            strcpy(frame[k++],"esc");
            strcpy(frame[k++],str[i]);
         }
   }
 strcpy(frame[k++],"flag");
//frame[k++]='\0';

printf("\nByte stuffing at sender's side:\n\n");

for(i=0;i<k;i++)
  {
    printf("%s ",frame[i]);
  }
}