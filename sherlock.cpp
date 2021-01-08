#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
 int value,flag=0;
unordered_map<char,int> str;
int i,l;
l=s.length(); 
while(i<l)
{
    if(!str[s[i]])
    str[s[i]]=1;
    else
    str[s[i]]++;
    i++;
}
value=str[s[0]];
for(i=1;i<l;i++)
if(str[s[i]]!=value)
{flag=1;
break;
}
if(flag==0)
return "YES";
else
{flag=0;
for(i=1;i<l;i++)
{if(str[s[i]]!=value&&str[s[i]]!=value+1)
  {flag++;
  }
}
if(flag<=1)
return "YES";
else
return "NO";
}
return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
