class functions
{
public:
	//+КОНСТРУКТОР для объявления, что пока все переменные равны 0 (ст.107)
	//+Деструктор
	static void change_number_of_row(int);
	static void add_element(char*, int, char*);
};

class Elem
{
	int* phone[6];
	char name[20];
	char comments[50];
public:
	static void setMessage(char*, int, char*); 
    static void showMessage(int); 
};

void functions::change_number_of_row(int a)//a - номер строки, сама функция доступна для исользования пользователем, но вывод ошибки, за неимением прав!
{
			cout<<"Error! You don't have rights for it!";
}

void functions::add_element(char* name, int phone, char* comments)
{

			int counter=0;	
			int j=0;
			int rest=0;
			int i=0;
			cout<<"Put full name: ";
			cin>>name;
			cout<<"Put phone number: ";
			//Определение числа разрядов
			cin>>phone;
			while(j!=2)
			{
				int i=0;
				while(phone>0)
				{
					phone/=10;
					i++;
				}
				if(i>7)
				{
					cout<<"Incorrect phone number!"<<endl;
					j=1;
				}
				else if(i==7)
				{
					j=2;
				}
				else if(i<7)
				{
					j=1;
					cout<<"Incorrect phone number!"<<endl;
				}
			}

			cout<<"Put comments: ";
			cin>>comments;
		// как по порядковому номеру потом вывести инфу???
			const int n=50;//всего записей
			int* record[n];
		//record [n]= record(name,phone,comments);
}


void Elem::setMessage(char* message_name, int message_phone, char* message_comments)
{
			char* name=message_name;
			int phone=message_phone;
			char* comments=message_comments;
}

void Elem::showMessage(int n)
{
	/*cout<<setw(20)<<endl;
	cout<<setw(7)<<endl;
	cout<<setw(50)<<endl;*/
			//Record* n=new Record(name, phone, comments);
			//нужно в массив положить разные типы инфы!^
			//cout<<"Information about the "<<n<<"number :"<<name<<"	"<<phone<<"	"
			//<<comments<<endl;

}
