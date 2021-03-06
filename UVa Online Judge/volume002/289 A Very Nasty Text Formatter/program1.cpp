// A Very Nasty Text Formatter
// UVa ID: 289
// Verdict: Accepted
// Submission Date: 2016-06-07
// UVa Run Time: 0.080s
//
// 版权所有（C）2016，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

list <string> words;
int n;

void process()
{
    vector <string> buffer;
    
    int length = 0;
    while (!words.empty())
    {
        if (length + buffer.size() + words.front().length() <= n)
        {
            length += words.front().length();
            buffer.push_back(words.front());
            words.erase(words.begin());
        }
        else
            break;
    }
    
    if (buffer.size() == 0)
    {
        int cut = n - 1;
        cout << words.front().substr(0, cut) << "-" << endl;
        words.front() = words.front().substr(cut);
    }
    else if (buffer.size() == 1)
    {
        if (!words.empty() && (buffer.front().length() + 3 <= n))
        {
            string next_word = words.front();
            int cut = n - buffer.front().length() - 2;
            cout << buffer.front() << " " << next_word.substr(0, cut);
            cout << "-" << endl;
            words.front() = next_word.substr(cut);
        }
        else
            cout << buffer.front() << endl;
    }
    else
    {
        if (!words.empty())
        {
            int space = n - length;
            
            while (space > 0)
            {
                for (int i = 0; i < buffer.size() - 1 && space > 0; i++)
                {
                    buffer[i] += ' ';
                    space--;
                }
            }
        }
        else
        {
            for (int i = 0; i < buffer.size() - 1; i++)
                buffer[i] += ' ';
        }
        
        for (int i = 0; i < buffer.size(); i++)
            cout << buffer[i];
        cout << endl;
    }
    
    if (words.size())
        process();
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    
    string line;
    while (getline(cin, line))
    {
        words.clear();
        string word;
        istringstream iss(line);
        while (iss >> word)
            words.push_back(word);
            
        n = stoi(words.front());
        words.erase(words.begin());
        
        process();
    }
    
	return 0;
}
