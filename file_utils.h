#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

class FileUtils
{
public:
    static void write_file(vector<int64_t> res);
    static vector<pair<int64_t, int64_t>> read_file();
};
