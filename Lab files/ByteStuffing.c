#include<stdio.h>
#include<string.h>

int main()
{
 int i=0, j, count=0, dlen, slen=0;
 char data[50], stuffed[50];

 printf("Enter Data Charactres: ");
 scanf("%s", data);

dlen = strlen(data);

 printf("Data Byte Before Byte Stuffing:%s",data); 


//Finding flags or esc characters inside the data and adding 'E'(esc char) before them

 for(i=0; i<dlen; i++)
 {
    if(data[i]=='E' || data[i] == 'F')
    {
        dlen++;

        for(j = dlen-1; j >= i; j--)
        {
            data[j] = data[j - 1];
        }
        data[i] = 'E';
        i++;

    }
 }

// Adding Flags at start and end of data
 stuffed[0] = 'F';
 slen++;
 for(i=1; i<=dlen; i++){
    stuffed[i] = data[i-1];
    slen++;
 }

stuffed[slen++] = 'F';
stuffed[slen] = '\0';

printf("\nData Byte After Byte stuffing : ");

for(i=0; i<slen;i++)
{
    printf("%c", stuffed[i]);
}

printf("\nData afer destuffing: ");

for(i=0; i<dlen; i++)
{
    if(data[i] == 'E')
    {
        printf("%c", data[i+1]);
        i++;
    }
    else if(data[i] != 'F'){
        printf("%c", data[i]);
    }
}

 return 0;
}
