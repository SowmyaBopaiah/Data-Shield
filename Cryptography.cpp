#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class easy
{
	public:
		char msg[1000];
		void encrypt_level_easy();
		void decrypt_level_easy();
};

class medium : public easy
{
	public:
		void encrypt_level_medium();
		void decrypt_level_medium();
};

class hard : public easy
{
	private:
		char key[10]={'{','[','(','*','?','+','-',')',']','}'};
	public:
		void encrypt_level_hard();
		void decrypt_level_hard();
};

void easy::encrypt_level_easy()
{
	int i;
	for(i=0;i<strlen(msg);i++)
	{
		if(msg[i]>64 && msg[i]<91)
		{
			if(msg[i]=='Z')
				msg[i]='B';
			else if(msg[i]=='Y')
				msg[i]='A';
			else
			{
				msg[i]+=2;
			}
		}
	}
	cout<<"\n\n"<<msg;
}

void easy::decrypt_level_easy()
{
	int i;
	for(i=0;i<strlen(msg);i++)
	{
		if(msg[i]>64 && msg[i]<91)
		{
			if(msg[i]=='B')
				msg[i]='Z';
			else if(msg[i]=='A')
				msg[i]='Y';
			else
			{
				msg[i]-=2;
			}
		}
	}
	cout<<"\n\n"<<msg;
}

void medium::encrypt_level_medium()
{
	int i,ascii;
	for(i=0;i<strlen(msg);i++)
	{
		ascii=msg[i];
		cout<<ascii;
	}
}

void medium::decrypt_level_medium()
{
	int i,ascii;
	char h;
	for(i=0;i<strlen(msg);i+=2)
	{
		ascii=((msg[i]-'0')*10)+(msg[i+1]-'0');
		h=ascii;
		cout<<h;
	}
}

void hard::encrypt_level_hard()
{
	int i,ascii;
	for(i=0;i<strlen(msg);i++)
	{
		ascii=msg[i];
		cout<<key[ascii/10]<<key[ascii%10];
	}
}

void hard::decrypt_level_hard()
{
	int i,j,num1,num2,ascii;
	char c;
	for(i=0;i<strlen(msg);i+=2)
	{
		for(j=0;j<10;j++)
		{
			if(msg[i]==key[j])
			{
				num1=j;
				break;
			}
		}
		for(j=0;j<10;j++)
		{
			if(msg[i+1]==key[j])
			{
				num2=j;
				break;
			}
		}
		ascii=(num1*10)+num2;
		c=ascii;
		cout<<c;
	}
}

int main()
{
	int ch,choice;
	easy e;
	medium m;
	hard h;
	
	while(1)
	{
		system("cls");
		cout<<"1. Encrypt a msg\n";
		cout<<"2. Decrypt a msg\n";
		cout<<"3. Exit\n\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		
		if(ch==1)
		{
			while(1)
			{
				system("cls");
				cout<<"Encrypt a msg in\n";
				cout<<"1. EASY level\n";
				cout<<"2. MEDIUM level\n";
				cout<<"3. HARD level\n";
				cout<<"4. Exit\n\n";
				cout<<"Enter your choice : ";
				cin>>choice;
				
				fflush(stdin);			//to empty the buffer
				
				if(choice==1)
				{
					cout<<"Enter massage : ";
					gets(e.msg);
					strupr(e.msg);
					e.encrypt_level_easy();
				}
				else if(choice==2)
				{
					cout<<"Enter massage : ";
					gets(m.msg);
					strupr(m.msg);
					m.encrypt_level_medium();
				}
				else if(choice==3)
				{
					cout<<"Enter massage : ";
					gets(h.msg);
					strupr(h.msg);
					h.encrypt_level_hard();
				}
				else if(choice==4)
				{
					break;
				}
				else
					cout<<"Invalid";
				cout<<"\n\n";
				system("pause");
			}
		}
		else if(ch==2)
		{
			while(1)
			{
				system("cls");
				cout<<"Decrypt a msg in\n";
				cout<<"1. EASY level\n";
				cout<<"2. MEDIUM level\n";
				cout<<"3. HARD level\n";
				cout<<"4. Exit\n\n";
				cout<<"Enter your choice : ";
				cin>>choice;
				
				fflush(stdin);			//to empty the buffer
				
				if(choice==1)
				{
					cout<<"Enter encrypted massage : ";
					gets(e.msg);
					strupr(e.msg);
					e.decrypt_level_easy();
				}
				else if(choice==2)
				{
					cout<<"Enter encrypted massage : ";
					gets(m.msg);
					strupr(m.msg);
					m.decrypt_level_medium();
				}
				else if(choice==3)
				{
					cout<<"Enter encrypted massage : ";
					gets(h.msg);
					strupr(h.msg);
					h.decrypt_level_hard();
				}
				else if(choice==4)
				{
					break;
				}
				else
					cout<<"Invalid";
				cout<<"\n\n";
				system("pause");
			}
		}
		else if(ch==3)
		{
			exit(0);
		}
		else
			cout<<"\n\nInvalid";
		system("pause");
	}
	return 0;
}
