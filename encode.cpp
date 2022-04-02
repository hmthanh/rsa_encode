#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

void write_file(vector<int64_t> res)
{
    ofstream output_file("output.txt");
    for (size_t i; i < res.size(); i++)
    {
        // cout <<"res.size"  <<  res.size();
        string r = std::to_string(res[i]);
        output_file << r << endl;
        ;
    }
}

vector<pair<int64_t, int64_t>> read_file()
{
    vector<pair<int64_t, int64_t>> res;
    ifstream input_file("input.txt");
    pair<int64_t, int64_t> item;

    string line;
    while (getline(input_file, line))
    {
        cout << line;
    }

    return res;
}

// num in Z_p
int64_t zp_mod(int64_t num, int64_t p)
{
    for (; num >= p;)
    {
        num = num % p;
    }
    return num;
}

int64_t gcd(int64_t a, int64_t h)
{

    for (int64_t temp = a % h; temp != 0; temp = a % h)
    {
        a = h;
        h = temp;
    }
    return h;
}

// power x^y in Z_p
int64_t encode(int64_t x, int64_t y, int64_t p)
{
    int64_t pow = 1;
    for (int64_t i = 0; i < y; i++)
    {
        pow = (pow * x) % p;
    }
    return pow;
}

int main(int argc, char *argv[])
{
    int64_t p; // Z_p
    int64_t E; // E : encode E
    int64_t x;
    // ./encode Zp E x
    if (argc < 4)
    {
        // File input format: Zp E  x
        ifstream input_file("input.txt");
        input_file >> p >> E >> x;
        cout << "p : " << p << endl;
        cout << "E : " << E << endl;
        cout << "x : " << x << endl;
        int64_t encoded = encode(x, E, p);

        cout << "encoded : " << to_string(encoded) << endl;

        // File output format: m = x^E in Z_p
        ofstream output_file("output.txt");
        output_file << encoded << endl;

        return 0;
    }
    else
    {
        // File input format: Zp E  x
        p = strtoll(argv[1], NULL, 0);
        E = strtoll(argv[2], NULL, 0);
        x = strtoll(argv[3], NULL, 0);

        cout << "p : " << p << endl;
        cout << "E : " << E << endl;
        cout << "x : " << x << endl;

        int64_t encoded = encode(x, E, p);
        cout << "encoded : " << to_string(encoded) << endl;

        return 0;
    }

    return 1;
}