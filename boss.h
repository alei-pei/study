#pragma once
#include<iostream>
#include "worker.h"

using namespace std;

class Boss : public Worker
{
public:

	Boss(int id, string name, string depName);

	void showInfo();

	string getDepName();

};