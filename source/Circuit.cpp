#include <vector>
#include <iostream>
#include<sstream>
using namespace std;

bool ValidDescription(string s);
float get_equivalent_resistance(vector<string> circuit);
float calculate_seriesR(vector<float> numbers);
float calculate_parallelR(vector<float> numbers);

int main()
{
    string s;
    getline(cin, s);

    if (!ValidDescription(s))
        return 0;

    vector<string> vc;
    string feed;
    stringstream ss(s);
    while (ss >> feed){
        vc.push_back(feed);
    }

    float z = get_equivalent_resistance(vc);
    if (z == 0)
        cout << "Incorrect Input";
    else
        cout << "The total resistance = " << z;
}

float get_equivalent_resistance(vector<string> circuit)
{
    vector<float> Rvalues;
    for (int i = 1; i < circuit.size(); i++)
    {
        if (circuit[i] == "e")
            break;
        if (circuit[i] == "S" || circuit[i] == "s")
        {
            int n = 0;
            float Req = 0, Num = 0;
            while (i + 1 < circuit.size())
            {
                if (circuit[i + 1] == "e"){
                    i++;
                    break;
                }
                Num = stof(circuit[i + 1]);
                Req += Num;
                i++;
                n++;
            }
            if (n < 1)
                return 0;
            Rvalues.push_back(Req);
        }
        else if (circuit[i] == "P" || circuit[i] == "p")
        {
            int n = 0;
            float Req = 0, Num = 0;
            while (i + 1 < circuit.size())
            {
                if (circuit[i + 1] == "e"){
                    i++;
                    break;
                }
                Num = stof(circuit[i + 1]);
                Req += (1 / Num);
                i++;
                n++;
            }
            if (n < 2)
                return 0;
            Rvalues.push_back(1 / Req);
        }
        else
            Rvalues.push_back(stof(circuit[i]));
    }

    if (circuit[0] == "S" || circuit[0] == "s")
        return (calculate_seriesR(Rvalues));
    else
        return (calculate_parallelR(Rvalues));
}

bool ValidDescription(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '.' && !isdigit(s[i]) && s[i] != 's' && s[i] != 'p' && s[i] != 'S' && s[i] != 'P' && s[i] != 'e' && s[i] != ' ')
        {
            cout << "Wrong Description";
            return 0;
        }
    }
    return 1;
}

float calculate_seriesR(vector<float> numbers)
{
    float Req = 0;
    if (numbers.size() < 1)
        return 0;

    for (int i = 0; i < numbers.size(); i++){
        Req += numbers[i];
        }
    return Req;
}

float calculate_parallelR(vector<float> numbers)
{
    float Req = 0;
    if (numbers.size() < 2)
        return 0;

    for (int i = 0; i < numbers.size(); i++){
        Req += (1 / numbers[i]);
    }
    return (1 / Req);
}