#include "first_unique_char_string.h"
#include<vector>
#include<iostream>

using namespace std;

void firstUniqCharRun() {
    cout << "Find first uniq character" << endl;
    cout << "abba" << firstUniqChar("abba") << endl;
    cout << "aabb" << firstUniqChar("aabb") << endl;
    cout << "adidas" << firstUniqChar("adidas") << endl;
    cout << "continuous integration" << firstUniqChar("continuous integration") << endl;
}

int firstUniqChar(string s) {

    cout << "string: " << s << endl;

    vector<pair<int, int> > store;
    store.resize(128);

    for (int i=0; i < int(s.length()); i++) {
        int code = int(s[i]);
        if (store[code].first == 0) {
            store[code].first = i;
        }
        store[code].second++;
        cout << "cache: " << store[code].first << "|" << store[code].second << endl;
    }

    int mindex = 10e5;
    for (auto p: store) {
        if (p.second == 1 && p.first < mindex) {
            mindex = p.first;
        }
    }

    if (mindex > int(s.length())) {
        return -1;
    }
    return mindex;
}
