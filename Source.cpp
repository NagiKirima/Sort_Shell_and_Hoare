#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
struct Lake 
{
	public:
		string name;
		float square;
		void Get_name() 
		{
			cin.ignore();
			getline(cin, name);
		}
		void Get_square() 
		{
			while (!(cin >> square) || (cin.peek() != '\n') || (square <= 0)) 
			{
				cin.clear();
				while (cin.get() != '\n') 
				{
					cout << "������� ���������� �������:\t";
				}
			}
		}
};
int GetSize()
{
	int size;
	while (!(cin >> size) || (cin.peek() != '\n') || (size < 1))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			cout << "������� ���������� ������ ������" << endl;
		}
	}
	return size;
}
void Fill_list(vector <Lake>&list)
{
	for (int i = 0; i < list.size(); i++) 
	{
		cout << "==========================================" << endl;
		cout << "������� ������ " << i + 1 << "-� ������" << endl;
		cout << "������� ���:\t";
		list[i].Get_name();
		cout << "������� �������:\t";
		list[i].Get_square();
	}
}
void Print_list(vector <Lake>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << i + 1 << "-�� ������" << endl;
		cout << "Name:\t" << list[i].name << endl;
		cout << "Square:\t" << list[i].square << endl;
	}
}
vector<Lake> Shell_sort(vector <Lake> list)
{
	
	int size = list.size();
	for (int step = size / 2; step > 0; step /= 2) 
	{
		for (int i = step; i < size; i++) 
		{
			for (int j = i; j >= step; j -= step)
			{
				if (list[j].square > list[j - step].square)
				{
					Lake temp = list[j];
					list[j] = list[j - step];
					list[j - step] = temp;
				}
			}
		}
	}
	return list;
}
void Quick_sort(vector <Lake>& list, int left, int right)
{
	int i = left;
	int j = right;
	float pivot = list[(i + j)/2].square;
	do 
	{
		while (list[i].square > pivot) 
		{
			i++;
		}
		while (list[j].square < pivot) 
		{
			j--;
		}
		if (i <= j)
		{
			Lake tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
			i++;
			j--;
		}

	} while (i <= j);
	if (j > left) 
	{
		Quick_sort(list, left, j);
	}
	if (i < right)
	{
		Quick_sort(list, i, right);
	}
}
void Quick_sort_stack(vector <Lake>& list, int left, int right)
{
	stack <int> limites;
	limites.push(left);
	limites.push(right);
	int i, j;
	float pivot;
	do
	{
		right = limites.top(); 
		limites.pop();
		left = limites.top(); 
		limites.pop();
		i = left;
		j = right;
		pivot = list[(i + j) / 2].square;
		do
		{
			while (list[i].square > pivot)
			{
				i++;
			}
			while (list[j].square < pivot)
			{
				j--;
			}
			if (i <= j)
			{
				Lake tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
				i++;
				j--;
			}
		} while (i <= j);
		if (j > left)
		{
			limites.push(left);
			limites.push(j);
		}
		if (i < right)
		{
			limites.push(i);
			limites.push(right);
		}
	} while (!limites.empty());
}

int main() 
{
	setlocale(LC_ALL, "ru");
	cout << "������� ������ ������ �����:\t";
	int size = GetSize();
	vector <Lake> list (size);
	Fill_list(list);
	cout << "==========================================" << endl;
	Print_list(list);
	cout << "==========================================" << endl << "���������� �����:" << endl;
	list = Shell_sort(list);
	Print_list(list);
	cout << "==========================================" << endl;
	Fill_list(list);
	Print_list(list);
	cout << "==========================================" << endl << "������� ���������� �����:" << endl;
	//Quick_sort(list, 0, list.size() - 1);
	Quick_sort_stack(list, 0, list.size() - 1);
	Print_list(list);
	cout << "==========================================" << endl;
}