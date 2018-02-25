
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

class FieldFileSetup {
    public:
        FieldFileSetup();
        ~FieldFileSetup();
        void dump();
        int loadFile(const string& filename);

        int setNumOfElement(int v1,int v2, int v3);

        float get3DVectorValue(vector<float> data, int i1, int i2, int i3);

        float getValue(vector<float> data, float p1, float p2, float p3);

        vector<float> data1,data2,data3,data4,data5,data6;
        int numOfAxis1,numOfAxis2,numOfAxis3;
        vector<string> header;
        string fname;
 private:
};