#include "FieldFileSetup.h"
#include <cstdio>
#include <cmath>
#include <iostream>


FieldFileSetup::FieldFileSetup() 
    {
    }

FieldFileSetup::~FieldFileSetup() 
    {
    }

//////////////////////////////////////////////////////////////////////////

int FieldFileSetup::loadFile(const string& filename)
    {
    data1.clear();
    data2.clear();
    data3.clear();
    data4.clear();
    data5.clear();
    data6.clear();
    
    float val1,val2,val3,val4,val5,val6;

    ifstream dataFile;
    dataFile.open(filename.c_str());

    string line;
    if (dataFile.fail())
        {
        cerr << "error" << endl;
        return -1;
        }
    while (getline(dataFile, line))
        {
        dataFile >> val1 >> val2 >> val3 >> val4 >> val5 >> val6;
        data1.push_back(val1);
        data2.push_back(val2);
        data3.push_back(val3);
        data4.push_back(val4);
        data5.push_back(val5);
        data6.push_back(val6);
        }

    for (int i = 0; i < data1.size(); i++)
        {
        cout << data1[i] << "\n";
        }

    return 0;
    }

//////////////////////////////////////////////////////////////////////////

int FieldFileSetup::setNumOfElement(int v1,int v2, int v3)
    {
	numOfAxis1=v1;
	numOfAxis2=v2;
	numOfAxis3=v3;
	
	return 0;
    }
//////////////////////////////////////////////////////////////////////////

float FieldFileSetup::get3DVectorValue(vector<float> data, int i1, int i2, int i3)
    {
	return data[i1+i2*numOfAxis1+i3*numOfAxis1*numOfAxis2];
    }

//////////////////////////////////////////////////////////////////////////

void FieldFileSetup::dump()
    {
    cout << "Hello" << endl;
    }

//////////////////////////////////////////////////////////////////////////

