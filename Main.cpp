#include<iostream>
#include<vector>
#include <stack>
using namespace std;
#include "Class.h"

int result(char*,int*);

int getting(char* expr,int* i)//преобразует из строки в число
{
	int result=0;
	while (expr[*i]-'0'>=0 && expr[*i]-'0'<=9) 
	{
		result=result*10+(expr[*i]-'0');
		*i=*i+1;
	}
	return result;
}

int get_int(char* expr,int* i,int oper)// если на входе стоит ( , то число отрицательное, 
//если нет, то положительное, получаем число и следуем в expr 
{
	int result=0;
	if (expr[*i]=='(') 
	{
		*i=*i+2;
		result=-getting(expr,i);
		*i=*i+1;
	}
	else
	{
		result=getting(expr,i);
	}
	return result*oper;
}

void expr(char* ex,int* i,stack<int>* arr, int flag)// пока не конец, продолжаем цикл
{
	if(*i<strlen(ex)) //разбиваем возможные варианты в стек + определяем знак и учитываем скобки + учитываем приоритет
	{
		if (ex[*i]=='(') {
			*i=*i+1;
			arr->push(result(ex,i));//отправляем в новый стек
			*i=*i+1;
			expr(ex,i,arr,flag);
		} else if (ex[*i]=='+') {
			if (ex[*i+1]=='(') {
				*i=*i+2;
				arr->push(result(ex,i));//отправляем в новый стек
				*i=*i+1;
				expr(ex,i,arr,flag);//сдвигаемся на сл. число/знак
			} else {
				*i=*i+1;
				arr->push(get_int(ex,i,flag));//отправляем в первый стек
				expr(ex,i,arr,flag);
			}
		} else if (ex[*i]=='-') {
			if (ex[*i+1]=='(') {
				*i=*i+2;
				arr->push(-result(ex,i));
				*i=*i+1;
				expr(ex,i,arr,flag);
			} else {
				*i=*i+1;
				arr->push(get_int(ex,i,-flag));
				expr(ex,i,arr,flag);
			}
		} else if (ex[*i]==')') {
			return;
		} else {
			arr->push(get_int(ex,i,flag));
			expr(ex,i,arr,flag);
		}
	}
}

int result(char* virazenie,int* i)
{
	stack<int>* arr=new stack<int>;//выделяем стек под запись каждого из чисел с их знаком
	expr(virazenie,i,arr,1);//получаем стек с числами

	int* result=new int[33];
	for(int i=0; i<33; result[i]=0,i++);
	while (!arr->empty())
	{
		result=functions::sum_bin(arr->top(),result);//отпраляем преобразовывать и складывать, а также приравниваем к переменной
		arr->pop();//удаляем вершину
	}
	int j=0;
	cout<<"Result in bin: ";
	while(j<32)
	{
		cout<<result[j];//выводим наш результат
		j++;
	}
	int suum=functions::transmorm_in_dec(result);//трансформируем в dec 
	cout<<endl<<"in dec "<<suum<<endl;
	return suum;
}

void main()
{
    setlocale(LC_ALL, "Russian");//для русского языка

    char virazenie[255];//устанавливаем некий предел
    cout<<"Введите выражение: "<<endl;
    cin>>virazenie;
	int i=0;
	cout<<endl<<"TOTAL RESULT: "<<result(virazenie,&i)<<endl;
}
