#include <bits/stdc++.h>
using namespace std;


int find_substring(string t, string p)
{
    int n = t.size(), m = p.size(), z = -1;
    for(int i=0; i+m<n; i++)
    {
        bool f = true;
        for(int j=0; j<m; j++)
        {
            if(t[i+j] != p[j])
            {
                f = false;
                break;
            }
        }
        if(f)
        {
            z = i+1;
            break;
        }
    }

    return z;
}

int main()
{
    string t = "A THING OF BEAUTY IS A JOY FOREVER";
    string p;

    int r;
    cout<<"Enter how many patterns you need to search: ";
    cin>>r;
    getchar();

    while(r--)
    {
        cout<<"Enter pattern: ";
        getline(cin, p);
        int n = t.size(), m = p.size(), z = 0;
        for(int i=0; i+m<n; i++)
        {
            bool f = true;
            for(int j=0; j<m; j++)
            {
                if(t[i+j] != p[j])
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                z = i+1;
                break;
            }
        }
        if(z)
            cout<<"'"<<p<<"'is f at position: "<<z<<endl;
        else
            cout<<"'"<<p<<"' is not f in text"<<endl;
    }


    string s;
    cout<<"Enter number of queries: ";
    cin>>r;

    int position;
    cout<<"Enter 1st_string, inserting_position, 2nd_string ["<<r<<" times]: "<<endl;
    while(r--)
    {
        cin>>s>>position>>t;

        string temp;
        for(int i=0; i<position-1; i++)
            temp += s[i];
        for(int i=0; i<t.size(); i++)
            temp += t[i];
        for(int i=position-1; i<s.size(); i++)
            temp += s[i];

        s = temp;
        cout<<"OUTPUT: "<<s<<endl;
    }


    cout<<"Enter number of queries: ";
    cin>>r;
    getchar();

    cout<<"Enter 1st_string, inserting_position, 2nd_string ["<<r<<" times]: "<<endl;
    while(r--)
    {
        getline(cin, s);
        cin>>position;
        getchar();
        getline(cin, t);

        string temp;
        for(int i=0; i<position-1; i++)
            temp += s[i];
        for(int i=0; i<t.size(); i++)
            temp += t[i];
        for(int i=position-1; i<s.size(); i++)
            temp += s[i];

        s = temp;
        cout<<"OUTPUT: "<<s<<endl;
    }


    cout<<"Enter number of queries: ";
    cin>>r;


    int len;

    while(r--)
    {

        string temp, t, f;

        cout<<"Enter operation ID: 1.Delete 2.Replace"<<endl;
        int n;
        cin>>n;
        getchar();

        if(n==1)
        {
            cout<<"Enter string, deletion_start_position, deletion_length: "<<endl;
            getline(cin, s);
            cin>>position>>len;
            getchar();
            for(int i=0; i<position-1; i++)
                temp += s[i];
            for(int i=position-1+len; i<s.size(); i++)
                temp += s[i];
        }
        else if(n==2)
        {
            cout<<"Enter string, replaceable_string, 2nd_string: "<<endl;
            getline(cin, s);
            getline(cin, f);
            getline(cin, t);
            int z = find_substring(s,f);
            len = f.size();
            for(int i=0; i<z-1; i++)
                temp += s[i];
            for(int i=0; i<t.size(); i++)
                temp += t[i];
            for(int i=z-1+len; i<s.size(); i++)
                temp += s[i];
        }

        s = temp;
        cout<<"OUTPUT: "<<s<<endl;
    }



    cout<<"Enter how many patterns you need to search: ";
    cin>>r;

    while(r--)
    {
        cout<<"Enter pattern: ";
        cin>>p;
        cout<<"Enter text: ";
        cin>>t;

        int n = t.size(), m = p.size(), z = 0;
        for(int i=0; i+m<n; i++)
        {
            bool f = true;
            for(int j=0; j<m; j++)
            {
                if(t[i+j] != p[j])
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                z = i+1;
                break;
            }
        }
        if(z)
            cout<<"'"<<p<<"' is found at position: "<<z<<endl;
        else
            cout<<"'"<<p<<"' is not found in the text!"<<endl;
    }

    return 0;
}
