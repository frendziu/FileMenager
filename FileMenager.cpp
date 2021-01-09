#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int isObjectWrong(string object, int index)
{
    int objectIndex;
    string id;
    string message;
    string controlToken;

    id = object.substr(0, 4);
    message = object.substr(4, 3);
    controlToken = object.substr(7, 1);

    if (message == "000" || stoi(id, nullptr, 2)%2==0 && controlToken =="1" || stoi(id, nullptr, 2) % 2 != 0 && controlToken == "0")  
        return objectIndex = index;
    else
        return objectIndex = -1;
}

vector<string> getGoodObjectVector(vector<string> objectsVector, int count)
{
    int wrongObjectIndex;
    vector<string> goodObjectsVector;
    for (int i = 0; i < count; i++)
    {
        wrongObjectIndex = isObjectWrong(objectsVector[i], i);
        if (wrongObjectIndex == -1)
        {
            goodObjectsVector.push_back(objectsVector[i]);
        }
        
    }
    return goodObjectsVector;
}



int main()
{
    string values;

    int count = 0;
      
    vector<string> objects;
    vector<string> goodObjects;

    //Input File
    ifstream InputFile("input.txt");
    if (InputFile.is_open())
    {
        while (getline(InputFile, values)) {
            
            objects.push_back(values);
            count++;                  
        }

        InputFile.close();
    }
    else
    {
        cout << "Unable to read file" << endl;
        return 0;
    }
    
    //Calculations
    goodObjects = getGoodObjectVector(objects, count);

    //Output file
    ofstream OutputFile("output.txt");

    OutputFile << "Number of objects: " << count << endl;
    OutputFile << "Number of wrong objects: " << count-goodObjects.size() << endl;
    for (int i = 0; i < goodObjects.size(); i++)
    {
        OutputFile << goodObjects[i] << endl;
    } 
    
    OutputFile.close();
    
 
    
    system("pause");
    return 0;
}
