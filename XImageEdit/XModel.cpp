#include "XModel.h"

void XModel::Add(XPos pos)
{
	this->poss.push_back(pos);
	//֪ͨ�۲���
	//this->Notify();
}

void XModel::SetPara(std::string key, int val)
{
	//û�����
	if (paras.find(key) == paras.end()) 
	{
		paras.insert(make_pair(key, val));
	}
	else 
	{
		//�����ֵ  �޸�
		paras[key] = val;
	}


}

int XModel::GetPara(std::string key)
{
	//û�����
	if (paras.find(key) == paras.end())
	{
		return 0;
	}
	return paras[key];
}

XModel::XModel()
{
}

XModel::~XModel()
{
}
