#include"workManager.h"
#include "employ.h"
#include "worker.h"
#include "boss.h"
#include "manager.h"


int main()
{
	Worker* worker;

	//worker = new Employee(1, "李四", "项目部");	
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2,"昭武","研发部");
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", "业务部");
	//worker->showInfo();
	//delete worker;

	int choice = 0;

	WorkManager wm;
	while (true)
	{
		wm.Show_Menu();

		cout << "请输入你要进行的操作序号:";

		cin >> choice;

		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.AddEmp();			
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
			wm.delete_Emp();
			break;
		case 4:
			wm.change_Emp();
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}

	
	}


	system("pause");

	return 0;

}

