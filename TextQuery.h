#pragma once

#include "QueryResult.h"
#include <map>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <memory>

using namespace std;

class QueryResult;

class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &ifs);
    QueryResult query(const string &word) const;
private:
    shared_ptr<vector<string>> lineData; // 存储每行的数据
    map<string, shared_ptr<set<line_no>>> wordLine; // 存储每个词出现的行数
    map<string, int> wordFreQunency; // 存储词频                    
};

