#pragma once

#include<iostream>

using namespace std;

class Worker
{
public:

	virtual void showInfo() = 0;

	virtual string getDepName() = 0;

	int m_ID;

	string m_Name;

	string m_DepName;
};
