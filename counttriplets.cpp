#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
unordered_map<long,long>prev,next;
long current;
long n,rc=0,lc=0,sum=0,i;
n=arr.size();
for(i=0;i<n;i++)
{if(next.find(arr[i])!=next.end())
next[arr[i]]++;
else
next[arr[i]]=1;
}

for(i=0;i<n;i++)
{
    current=arr[i];
    rc=0;
    lc=0;
    next[arr[i]]--;

    if(!prev.empty())
    {
        if(prev.find(current/r)!=prev.end()&&(current%r)==0)
        lc=prev[current/r];
        
    }
    if(!next.empty())
    {if(next.find(current*r)!=next.end())
     rc=next[current*r];
    }

    sum+=rc*lc;
    if(prev.find(current)!=prev.end())
    prev[current]++;
    else
    prev[current]=1;
}
return sum;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
