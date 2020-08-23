#pragma once
#pragma once
#pragma warning(disable:26495)
#include <fstream>
#include <iostream>
using namespace std;
//ifstream in("C:\\Users\\Thinkpad\\Desktop\\md.txt");
//ofstream out("C:\\Users\\Thinkpad\\Desktop\\mdtohtml.html");
class md2html
{
    char mdFile[100];
    char htmlFile[100];
    char line[1024];
    ifstream in;
    ofstream out;
public:
    void setAll()
    {
        char esc = false;

        while (!esc)
        {
            char md[100];
            cout << "请输入要转换的文档" << endl;
            cin >> md;
            cout << "请输入网页的名字" << endl;
            char html[100];
            cin >> html;
            char isCenter;
            cout << "请输入是否居中？(Y/N)" << endl;
            cin >> isCenter;
            in.open(md);
            out.open(html);
            out << "<!DOCTYPE html>" << endl;
            out << endl;
            out << "<html>" << endl;
            out << endl;
            out << "<head>" << endl;
            out << endl;

            out << "<meta charset=\"utf-8\">" << endl;
            out << endl;
            out << "<title>md2html</title>" << endl;
            out << endl;
            out << "<!--[if lt IE 9]>" << endl;
            out << endl;
            out << "<script src=\"http://html5shim.googlecode.com/svn/trunk/html5.js\">< / script> <![endif]-->" << endl;
            out << endl;
            out << "</head>" << endl;
            out << endl;
            out << "<body>" << endl;
            out << endl;
            if (isCenter == 'Y' || isCenter == 'y')
            {
                out << "<center>" << endl;
            }
            out << "<center>" << endl;
            out << "<EMBED src=\"https://www.bilibili.com/audio/au13390\" width=500 height=100 type=audio/mpeg loop=\" -1\" autostart=\"true\" volume=\"20\"></EMBED>" << endl;
            out << "</center>" << endl;
            while (in.getline(line, 1024))
            {
                bool isTitle = false;
                isTitle = setTitle();
                bool isList = false;
                isList = setList();
                bool isLink = false;
                isLink = setLink();
                bool isPicture = false;
                isPicture = setPicture();
                bool isCode = false;
                isCode = setCode();
                if ((isCode || isPicture || isList || isTitle || isLink) == false)
                {
                    out << line << endl;
                }
                cout << isTitle << isList << isLink << isPicture << isCode << endl;

            }
            if (isCenter == 'Y' || isCenter == 'y')
            {
                out << "</center>" << endl;
            }
            out << "</body>" << endl;
            out << endl;
            out << "</html>" << endl;
            out << endl;
            in.close();
            out.close();
            cout << "转换完成" << endl;

            cout << "退出？（Y/N）" << endl;
            char choice;
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                esc = true;
            }
        }
    }

    int countTitle(const char* s)
    {
        int count = 0;
        unsigned int i = 0;
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] == '#')
            {
                count++;
            }
            else
            {
                break;
            }
        }

        return count;
    }
    bool setTitle()
    {
        int num = countTitle(line);
        if (num >= 1 && num <= 6)
        {
            out << "<h" << num << ">" << &(line[1 + num]) << "</h" << num << ">" << endl;
            cout << "<h" << num << ">" << &(line[1 + num]) << "</h" << num << ">" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool inList = false;
    bool setList()
    {
        if ((line[0] == '*' || line[0] == '+' || line[0] == '-') && line[1] == ' ')
        {
            if (inList == false)
            {
                //cout << "<ul>" << endl;
                out << "<ul>" << endl;
                inList = true;
            }
            cout << "<li>" << &(line[2]) << "</li>" << endl;
            out << "<li>" << &(line[2]) << "</li>" << endl;
            return true;
        }
        else
        {
            if (inList == true)
            {
                cout << "</ul>" << endl;
                out << "</ul>" << endl;
                inList = false;
                return true;
            }
            return false;
        }
    }

    bool setTable()
    {
        return false;
    }

    bool setLink()
    {
        string str(line);
        int title_1, title_2, link_1, link_2;
        if (((str.find('!') + 1) != str.find('[')) && (str.find('[') < str.find(']')) && (str.find('(') < str.find(')')) && (str.find(']') + 1 == str.find('(')))
        {
            title_1 = str.find('[');
            title_2 = str.find(']');
            link_1 = str.find('(');
            link_2 = str.find(')');

            out << str.substr(0, title_1) << endl;
            out << "<a href=\"" << str.substr(link_1 + 1, link_2 - link_1 - 1) << "\">" << str.substr(title_1 + 1, title_2 - title_1) << "</a>" << endl;
            cout << str.substr(0, title_1) << endl;
            cout << "<a href=\"" << str.substr(link_1 + 1, link_2 - link_1 - 1) << "\">" << str.substr(title_1 + 1, title_2 - title_1) << "</a>" << endl;
            return true;
        }
        return false;
    }

    bool inCode = false;
    bool setCode()
    {
        string str(line);
        if (str.find("```") != string::npos)
        {
            if (inCode == false)
            {
                out << "<div class=\"highlight\"><pre class=\"highlight\"><code>" << endl;
                inCode = true;
                return true;
            }
            else
            {
                out << "</code></pre></div>" << endl;
                inCode = false;
                return true;
            }
        }
        return false;
    }

    bool setPicture()
    {
        string str(line);
        int title_1, title_2, link_1, link_2;
        if ((str.find('[') == str.find('!') + 1) && (str.find('[') < str.find(']')) && (str.find('(') < str.find(')')) && (str.find(']') + 1 == str.find('(')))
        {
            title_1 = str.find('[');
            title_2 = str.find(']');
            link_1 = str.find('(');
            link_2 = str.find(')');

            out << str.substr(0, title_1 - 1) << endl;
            out << "<center>" << endl;
            out << "<img src=\"" << str.substr(link_1 + 1, link_2 - link_1 - 1) << "\" alt=\"" << str.substr(title_1 + 1, title_2 - title_1 - 1) << "\" />" << endl;
            out << "</center>" << endl;

            cout << str.substr(0, title_1 - 1) << endl;
            cout << "<center>" << endl;
            cout << "<img src=\"" << str.substr(link_1 + 1, link_2 - link_1 - 1) << "\" alt=\"" << str.substr(title_1 + 1, title_2 - title_1 - 1) << "\" />" << endl;
            cout << "</center>" << endl;
            return true;
        }
        return false;
    }


};