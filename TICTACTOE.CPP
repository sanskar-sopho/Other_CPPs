//This game(TicTacToe) is made by Sanskar Agrawal

#include<iostream>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
//#include<process.h>

using namespace std;

int ch1,ch2,p,S1=0,S2=0,S3=0,fl=0,c,aa,k=0,flag1=0,flag2=0,easy=0,len1,len2=6;
char ox1,ox2,YN,name1[11],name2[11];
void check_space();
int draw_map();
void check_res();
void cpu_turn(int k);
void check_cpu();
void check_opp();
void random_turn();
void help();

char str[]={" | | \n------\n | | \n------\n | | "};
char str1[]={0,26,28,30,13,15,17,0,2,4};
int main()
{//clrscr();
k=flag1=flag2=0;

if(fl==0)
{
jmp3:
easy=S1=S2=S3=0;
len2=6;
cout<<"                          Welcome to Tic tac toe\n\n\n";
cout<<"Enter your choice\n\n1. Play with C.P.U.\n\n2. Play with other player\n\n3. Help\n\n4. Exit\n";
cin>>c;
if(c==3)
{help();
 goto jmp3;
 ;
}
if(c==1)
{ cout<<"\n\nChoose level...\n\n1. Easy.\n\n2. Difficult.\n\n";
cin>>aa;
//clrscr();
if(aa==1)
easy=1;
}
if(c>3)
exit(0);
}
cout<<"                          Welcome to Tic tac toe\n\n\n";
if(fl==0)
{cout<<"Player 1. Enter your First Name\n";
  scanf("%s",name1);
  //gets(name1);
len1=strlen(name1);
if(c==1)
strcpy(name2,"C.P.U.");
if(c==2)
{
cout<<"\nPlayer 2. Enter your First Name\n";
 scanf("%s",name2);
//gets(name2);
len2=strlen(name2);
}
}
cout<<"                                  Score\n\n                   ";
cout.write(name1,len1);
cout<<" : "<<S1;
cout<<"   ";
cout.write(name2,len2);
cout<<" : "<<S2<<"   Draw : "<<S3<<"\n\n";

p=1;

cout<<endl<<endl<<endl;
puts(str);
cout<<endl<<endl;
if(fl==0)
{
jmp:
cout<<"\n";
cout.write(name1,len1);
cout<<". Choose your character(O/X) or press 'e' to exit\n";
cin>>ox1;
if(ox1=='x'||ox1=='X')
{ox1='X'; ox2='O';}
else if(ox1=='o'||ox1=='O')
{ox1='O'; ox2='X';}
else if(ox1=='e'||ox1=='E')
exit(0);
else {cout<<"Wrong choice..\n";
goto jmp;}
}
fl++;
do{
if(p==1)
{cout<<endl;
cout.write(name1,len1);
cout<<". Enter your move(1-9) according to your numpad";
cin>>ch1; }
else if(p==-1)
{if(c==2)
{cout<<endl;
cout.write(name2,len2);
cout<<". Enter your move(1-9) according to your numpad";
cin>>ch2;}
if(c==1)
{
k++;
cpu_turn(k);

}
}

draw_map();
check_res();
check_space();
}
while(p!=0);

//getch();
}


int draw_map()
{ int k,n=0;
char l;
if(c==2 || p==1)
{
if(p==1)
{k=ch1; l=ox1;}
else {k=ch2; l=ox2;}

switch(k)
{case 1:if(str[26]!=' ')
	n=1;
	else str[26]=l;
	break;
case 2: if(str[28]!=' ')
	n=1;
	else str[28]=l;
	break;
case 3: if(str[30]!=' ')
	n=1;
	else str[30]=l;
	break;
case 4: if(str[13]!=' ')
	n=1;
	else str[13]=l;
	break;
case 5: if(str[15]!=' ')
	n=1;
	else str[15]=l;
	break;
case 6: if(str[17]!=' ')
	n=1;
	else str[17]=l;
	break;
case 7: if(str[0]!=' ')
	n=1;
	else str[0]=l;
	break;
case 8: if(str[2]!=' ')
	n=1;
	else str[2]=l;
	break;
case 9: if(str[4]!=' ')
	n=1;
	else str[4]=l;
	break;
default : cout<<"\n\nWrong choice...";
	  return 0;
}if(n==1)
{cout<<"\nSorry!! That place is already filled\n";
return 0;  }
}
//clrscr();
cout<<"                          Welcome to Tic tac toe\n\n\n";
cout<<"                                  Score\n\n                   ";
cout.write(name1,len1);
cout<<" : "<<S1;
cout<<"   ";
cout.write(name2,len2);
cout<<" : "<<S2<<"   Draw : "<<S3<<"\n\n";

puts(str);
p*=-1;
 return 0;
}

void check_space()
{
int z=0;
for(int i=0;i<=9;i++)
 {if(str[str1[i]]==' ')
   z++;
   }
   if(z==0)
   {S3++;
   //clrscr();
cout<<"                          Welcome to Tic tac toe\n\n\n";
cout<<"                                  Score\n\n                  ";
cout.write(name1,len1);
cout<<" : "<<S1;
cout<<"   ";
cout.write(name2,len2);
cout<<" : "<<S2<<"   Draw : "<<S3<<"\n\n";

puts(str);

   cout<<"\nThis match is draw..";
   cout<<"\n\n\nWant to play more(Y/N)\n\n\n\n\n\n\nPress N for main menu.";
   cin>>YN;
   if(YN=='y'||YN=='Y')
   {for(int i=0;i<=9;i++)
   str[str1[i]]=' ';
   main();}
    else
     { fl=0;
       for(int i=0;i<=9;i++)
   str[str1[i]]=' ';
       main();
     }
   }

}
void check_res()
{ int p1=0,p2=0;
char z;

if((str[26]==str[28])&&(str[28]!=' ')&&(str[28]==str[30])||(str[13]==str[15])&&(str[15]!=' ')&&(str[15]==str[17])||(str[0]==str[2])&&(str[2]!=' ')&&(str[2]==str[4])||(str[0]==str[13])&&(str[13]!=' ')&&(str[13]==str[26])||(str[2]==str[15])&&(str[15]!=' ')&&(str[15]==str[28])||(str[4]==str[17])&&(str[17]!=' ')&&(str[17]==str[30])||(str[0]==str[15])&&(str[15]!=' ')&&(str[15]==str[30])||(str[4]==str[15])&&(str[15]!=' ')&&(str[15]==str[26]))
  { for(int i=0;i<=31;i++)
	{if(str[i]==ox1)
	 p1++;
	 else if(str[i]==ox2)
	  p2++;
	  else ;}
  if(p1>p2)
  {S1++;
  //clrscr();
cout<<"                          Welcome to Tic tac toe\n\n\n";
cout<<"                                  Score\n\n                   ";
cout.write(name1,len1);
cout<<" : "<<S1;
cout<<"   ";
cout.write(name2,len2);
cout<<" : "<<S2<<"   Draw : "<<S3<<"\n\n";

puts(str);
  cout<<"\n\n";
  cout.write(name1,len1);
  cout<<" wins..!!";

  }
  else
  { S2++;
  //clrscr();
cout<<"                          Welcome to Tic tac toe\n\n\n";
cout<<"                                  Score\n\n                   ";
cout.write(name1,10);
cout<<" : "<<S1;
cout<<"   ";
cout.write(name2,10);
cout<<" : "<<S2<<"   Draw : "<<S3<<"\n\n";

puts(str);

  cout<<"\n\n";
  cout.write(name2,len2);
  cout<<" wins..!!";

  }
  cout<<"\n\n\nWant to play again(Y/N)\n\nPress N for main menu";
  cin>>z;
  if(z=='y'||z=='Y')
  {for(int i=0;i<=9;i++)
   str[str1[i]]=' ';
   main();
   }
  else
    {
       fl=0;
       for(int i=0;i<=9;i++)
       str[str1[i]]=' ';
       main();
    }
  }
  }

void cpu_turn(int k)
{
if(k==1)
{       if(easy)
	random_turn();
	else {
	  srand(time(NULL));
	int str2[]={0,4,26,30};
	if(str[15]==' ')
	str[15]=ox2;
	else
	{
	str[str2[rand()%4]]=ox2;

	}     }
}
if(k>1)
{flag1=flag2=0;
check_cpu();
if(flag1==0)
check_opp();
if(flag1==0 && flag2==0)
random_turn();
}

}

void check_cpu()
{
  int i,j,k,l;
int str3[]={0,13,26,2,15,28,4,17,30,0,2,4,13,15,17,26,28,30,0,15,30,4,15,26};
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{ if(i==j)
  continue;
  for(l=0;l<3;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox2 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag1=1;
    break;
   }
}

if(flag1) return;
for(i=3;i<6;i++)
for(j=3;j<6;j++)
{ if(i==j)
  continue;
  for(l=3;l<6;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox2 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag1=1;
    break;
   }
}

if(flag1) return;
for(i=6;i<9;i++)
for(j=6;j<9;j++)
{ if(i==j)
  continue;
  for(l=6;l<9;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox2 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag1=1;
    break;
   }
}

if(flag1) return;
for(i=9;i<12;i++)
for(j=9;j<12;j++)
{ if(i==j)
  continue;
  for(l=9;l<12;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox2 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag1=1;
    break;
   }
}

if(flag1) return;
for(i=12;i<15;i++)
for(j=12;j<15;j++)
{ if(i==j)
  continue;
  for(l=12;l<15;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox2 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag1=1;
    break;
   }
}

if(flag1) return;
for(i=15;i<18;i++)
for(j=15;j<18;j++)
{ if(i==j)
  continue;
  for(l=15;l<18;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox2 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag1=1;
    break;
   }
}

if(flag1) return;
for(i=18;i<21;i++)
for(j=18;j<21;j++)
{ if(i==j)
  continue;
  for(l=18;l<21;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox2 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag1=1;
    break;
   }
}

if(flag1) return;
for(i=21;i<24;i++)
for(j=21;j<24;j++)
{ if(i==j)
  continue;
  for(l=21;l<24;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox2 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag1=1;
    break;
   }
}
}


void check_opp()
{

  int k,l,j,i;
int str3[]={0,13,26,2,15,28,4,17,30,0,2,4,13,15,17,26,28,30,0,15,30,4,15,26};
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{ if(i==j)
  continue;
  for(l=0;l<3;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]== ox1 && str[str3[k]]==' ')
   {str[str3[k]]=ox2 ;
    flag2=1;
    break;
   }
}

if(flag2)    return;
for(i=3;i<6;i++)
for(j=3;j<6;j++)
{ if(i==j)
  continue;
  for(l=3;l<6;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox1 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag2=1;
    break;
   }
}

if(flag2)    return;
for(i=6;i<9;i++)
for(j=6;j<9;j++)
{ if(i==j)
  continue;
  for(l=6;l<9;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox1 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag2=1;
    break;
   }
}
if(flag2)    return;
for(i=9;i<12;i++)
for(j=9;j<12;j++)
{ if(i==j)
  continue;
  for(l=9;l<12;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox1 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag2=1;
    break;
   }
}
if(flag2)    return;
for(i=12;i<15;i++)
for(j=12;j<15;j++)
{ if(i==j)
  continue;
  for(l=12;l<15;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox1 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag2=1;
    break;
   }
}

if(flag2)    return;
for(i=15;i<18;i++)
for(j=15;j<18;j++)
{ if(i==j)
  continue;
  for(l=15;l<18;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox1 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag2=1;
    break;
   }
}

if(flag2)    return;

for(i=18;i<21;i++)
for(j=18;j<21;j++)
{ if(i==j)
  continue;
  for(l=18;l<21;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox1 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag2=1;
    break;
   }
}
if(flag2)    return;
for(i=21;i<24;i++)
for(j=21;j<24;j++)
{ if(i==j)
  continue;
  for(l=21;l<24;l++)
  { if(l!=i && l!=j)
    k=l;
  }
  if(str[str3[i]]==str[str3[j]] && str[str3[j]]==ox1 && str[str3[k]]==' ')
   {str[str3[k]]=ox2;
    flag2=1;
    break;
   }
}
}

void random_turn()
{
  int a=0,i,arr[11];
int str4[]={0,2,4,13,15,17,26,28,30};
for(i=0;i<=10;i++)
arr[i]=1;

for(i=0;i<=8;i++)
{ if(str[str4[i]]!=' ')
  continue;
  else
  {
  arr[a]=str4[i];
  a++;
  }
}

int l,n,m;
switch(k)
{case 1 : m=8;
	  break;
 case 2 : m=6;
	  break;
 case 3 : m=4;
	  break;
 case 4 : m=2;
	  break;
 case 5 : m=1;
	  break;
 default : m=2;
	  break;


 }
for(i=0;arr[i]!=1;i++)
l=i;
jmp2:
 srand(time(NULL));
n=rand()%m;
if(n>l)
goto jmp2;
str[arr[n]]=ox2;
}

void help()
{//clrscr();
cout<<"\n\n   This game provides option to play multiplayer or single player , enter your \n\nchoice in the main menu , then you have to enter your name not more than 10 \n\ncharacters , then choose your character (O/X) , play your turn according to \n\nthe numpad of your keyboard as given below...\n\n\n\n7|8|9\n------\n4|5|6\n------\n1|2|3\n\n\nPress a key to continue.....\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                        By Sanskar Agrawal";
//getch();
//clrscr();
}
