#include <bits/stdc++.h>

using namespace std;

//递归过程，顺序生成所有的字串。str保存结果，n和L为题目中给出的同名变量
void sequence(string & str, int &n, int L)
{
    //记录字串长度，以加快运算
    int nLen = str.length(), nHalf = (str.length() + 1) / 2;
    //在结果字串后面依次尝试添加前L个大写字母
    for (char i = 'A', iEnd = L + 'A', m = 1; i < iEnd; ++i)
    {
        str.push_back(i);       //插入当前字符
        //下面判断新生成的字符串中是否存在相邻的重复
        //第1次判断最后1个字符，第2次判断最后2个字符，以此类推
        for (m = 1; m <= nHalf; ++m)
        {
            //将最后的i个字符与之前的i个字符比较，如果有相同则跳出
            if (equal(str.end() - m, str.end(), str.end() - m * 2))
            {
                m = 0;          //将m置为0表示存在重复的相邻子串
                break;          //跳出循环
            }
        }
        if (m != 0)
        {                       //如果不存在重复
            //如果生成的字串已经够数，返回上一级
            if (--n == 0)
                return;
            sequence(str, n, L);        //进入下一级调用
            //如果生成的字串已经够数，返回上一级
            if (n == 0)
                return;
        }                       //删除刚添加在后面的字符，保持结果字串在进入这一级时的原状
        str.erase(nLen);        //准备为添加下一个字符作准备
    }
}

//主函数
int main(void)
{
    for (int n, L; cin >> n >> L && n != 0;)
    {                           //循环读取每一组输入的数据
        string str;             //结果字符串
        sequence(str, n, L);    //递归生成所有的无相邻重复字串
        int nLen = str.length();        //保留生成字串的字符数量
        for (size_t i = 4; i < str.length(); i += 5)
        {                       //按格式处理字串
            //每隔4个插入一个空格，每隔80字符插入一个回车
            str.insert(str.begin() + i, i == 79 ? '\n' : ' ');
        }                       //输出结果字串和字符数量
        cout << str << '\n' << nLen << endl;
    }
    return 0;
}
