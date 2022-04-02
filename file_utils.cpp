#include "file_utils.h"

vector<pair<int64_t, int64_t>> FileUtils::read_file()
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

void FileUtils::write_file(vector<int64_t> res)
{
    // cout << "res.size" << res.size();
    ofstream output_file("output.txt");
    for (size_t i; i < res.size(); i++)
    {
        // cout <<"res.size"  <<  res.size();
        string r = std::to_string(res[i]);
        output_file << r << endl;
        ;
    }
    output_file << endl;
    output_file.close();
}
