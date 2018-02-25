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
    
    fname=filename;
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
        if (line.find("#")==0)
            {
            header.push_back(line);
            }
        else
            {
            dataFile >> val1 >> val2 >> val3 >> val4 >> val5 >> val6;
            data1.push_back(val1);
            data2.push_back(val2);
            data3.push_back(val3);
            data4.push_back(val4);
            data5.push_back(val5);
            data6.push_back(val6);
            }
        }

    //for (int i = 0; i < data1.size(); i++)
    //    {
    //    cout << data1[i] << "\n";
    //    }

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
	//cout << i1 << ","<< i2 <<"," << i3<< endl;
    //cout << i1+i2*numOfAxis1+i3*numOfAxis1*numOfAxis2<<endl;
	return data[i1+i2*numOfAxis1+i3*numOfAxis1*numOfAxis2];
    }
//////////////////////////////////////////////////////////////////////////

float FieldFileSetup::getValue(vector<float> data, float p1, float p2, float p3)
    {
	int c1 = int(p1);
	int c2 = int(p2);
	int c3 = int(p3);
	
	float v1 = get3DVectorValue(data, c1,   c2,   c3);
	float v2 = get3DVectorValue(data, c1+1, c2,   c3);
	float v3 = get3DVectorValue(data, c1,   c2+1, c3);
	float v4 = get3DVectorValue(data, c1+1, c2+1, c3);
	float v5 = get3DVectorValue(data, c1,   c2,   c3+1);
	float v6 = get3DVectorValue(data, c1+1, c2,   c3+1);
	float v7 = get3DVectorValue(data, c1,   c2+1, c3+1);
	float v8 = get3DVectorValue(data, c1+1, c2+1, c3+1);
	
	return 0.0;
    }
//////////////////////////////////////////////////////////////////////////

void FieldFileSetup::dump()
    {
    cout << "File name        : " << fname << endl;
    cout << "Number of Axis 1 : " << numOfAxis1 << endl;
    cout << "Number of Axis 2 : " << numOfAxis2 << endl;
    cout << "Number of Axis 3 : " << numOfAxis3 << endl;
    cout << "Data size        : " << data1.size() << endl;
    
    if (int(data1.size())!=numOfAxis1*numOfAxis2*numOfAxis3)
        cout << "Data size and Axis size are inconsistent."<<endl;;


    for (int i = 0; i < header.size(); i++)
        cout << "header           : "<<header[i] << endl;

    }

//////////////////////////////////////////////////////////////////////////

