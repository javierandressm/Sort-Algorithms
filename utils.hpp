#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

using namespace std;

vector<string> readDataset(const string& filename);
bool isSorted(const vector<string>& arr);
size_t estimateVectorMemory(const vector<string>& data);

#endif

