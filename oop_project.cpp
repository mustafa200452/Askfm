#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include <string>
using namespace std;
string answer_user;
struct Question//from user to anther user
{
    int from_user;
    int to_user;
    bool tast=0;
    string question;
};
struct User
{
    string username;
    string pass;
    int ID_user;
};
struct Answer_Question
{
    int user_iid;
    int posation_Question;
    string answer_Question;
};

void download_Question (int n,vector<Question>& Question0)
{
    fstream tast_00("Question.txt",ios::out|ios::in); 
  for (int i = 0; i < n; i++)
  {
    int a,b;string s;bool f;
    tast_00>>a>>b>>f;
    getline(tast_00,s,'?');
    Question0[i].from_user=a;
    Question0[i].to_user=b;
    Question0[i].tast=f;
    Question0[i].question=s;
  }
}
void download(int n,vector<User>& x)
{
  fstream tast0("user.txt",ios::out|ios::in); 
  for (int i = 0; i < n; i++)
{
    string a,b;int c;
    tast0>>a>>b>>c;
    x[i].username=a;
    x[i].pass=b;
    x[i].ID_user=c;
}
tast0.close(); 
}
void upload_Question(int n,vector<Question>& Question0)
{
    fstream Q0 ("Question.txt",ios::out|ios::in);
    for (int i = 0; i <n; i++)
    {
        Q0<<Question0[i].from_user<<" "<<Question0[i].to_user<<"\n"<<Question0[i].tast<<Question0[i].question<<'?'<<'\n';
    }
    Q0.close();
}
void download_Answer(int n,vector<Answer_Question>& answer)
{
fstream A ("Answer.txt",ios::in|ios::out);
for (int i = 0; i <n; i++)
{
    int id,po;string a;
    A>>id>>po;
    getline(A,a,'.');
    answer[i].user_iid=id;
    answer[i].posation_Question=po;
    answer[i].answer_Question=a;
}

}
   void menu2()
    {
        cout<<"1:Print Question To Me\n";
        cout<<"2: Print Question From Me\n";
        cout<<"3: Answer Question\n";
        cout<<"4: Delete Question\n";
        cout<<"5: Ask Question\n";
        cout<<"6: List System User\n";
        cout<<"7: Feed\n";
        cout<<"8: logout\n";
        cout<<"Enter in the namber of process\n";
    }

class menu1
{
private:

public:
    menu1()
    {
        cout<<"1: Login\n";
        cout<<"2: Sign Up\n";
        cout<<"int in the namber of process\n";
    }
};
 class login
 {
    int user_id; bool tast=0;
     public:
    void print_log(){cout<<"enter in username and password\n";}
    void search(string a,string b,int n,vector<User>& x)
    {
        for (int i = 0; i < n; i++)
        {
            if (a==x[i].username&&b==x[i].pass)
            {
                menu2();
                user_id=i;
                tast=1;
                break;
            }
            
        }
    }
    int return_id()
    {
        return user_id;
    }
    bool res_login()
    {
        if (tast==0)
        {
            return 0;
        }
        else return 1;
    }
 };
class Sign_Up
{
    public:
    void print_sign(){cout<<"enter in username and password\n";}
   void set_user(string x,string y,int z)
    {
        fstream user0;
        user0.open("user.txt",ios::out|ios::app);
        user0<<x<<" "<<y<<" "<<z<<'\n';

    }
};
class Print_Question_To_Me
{
    public:
    void search1(int n,int id,vector<Question>& Question0)
    {
        bool tast=0;
        for (int i = 0; i < n; i++)
        {
            if (id==Question0[i].to_user)
            {
                cout<<Question0[i].question<<"?"<<'\n';
                
                tast=1;
            }
            
        }
        if (tast==0)
        {
            cout<<"There are no questions for you\n";
        }
        
    }

};
class Print_Question_From_Me
{
    public:
    void search2(int n,int id,vector<Question>& Question0)
    {
        bool tast=0;
        for (int i = 0; i < n; i++)
        {
            if (id==Question0[i].from_user)
            {
                cout<<Question0[i].question<<"?"<<'\n';
                tast=1;   
            }
            
        }
        if (tast==0)
        {
            cout<<"There are no questions from you\n";
        }
        
    }

};
class Answer
{
    private:
    int posation_Q=-1;
    public:
   void search3(int n,int id,vector<Question>& Question0)
    {
        bool tast=0;
        for (int i = 0; i < n; i++)
        {
            if (id==Question0[i].to_user)
            {
                if (Question0[i].tast==1)
                {
                    continue;
                }
                else{
                cout<<Question0[i].question<<"?"<<'\n';
                tast=1;
                posation_Q=i;
                }   
            }
            
        }
        if (tast==0)
        {
            cout<<"There are no questions need to answer form you\n";
        }
        
    }
    int get_posation_Q()
    {
        return posation_Q;
    }
};
class Delete_Question
{
    int posation0=-1;
    public:
    void search4(int n,int id,vector<Question>& Question0)
    {
        bool tast=0;
        for (int i = 0; i < n; i++)
        {
            if (id==Question0[i].from_user)
            {
                posation0=i;
                tast=1;   
            }
            
        }
        if (tast==0)
        {
            cout<<"There are no questions from you\n";
        }
        
    }
    int get_posation_Q_D()
    {
        return posation0;
    }
    void upload_Question_D(int n,int p,vector<Question>& Question0)
{
    fstream Q00 ("Question.txt",ios::out|ios::in|ios::trunc);
    Q00.close();
    fstream q0 ("Question.txt",ios::out|ios::in);
    for (int i = 0; i <n; i++)
    {
        if (i!=p)
        {
            q0<<Question0[i].from_user<<" "<<Question0[i].to_user<<"\n"<<Question0[i].tast<<Question0[i].question<<'?'<<'\n';
        }
        else continue;
    }
    q0.close();
}

};
class Ask_Question
{
    public:
    void print_Ask_Question()
    {
        cout<<"Enter in the user id that you will ask\n";
    }
    void get_Ask_Question(int id_f,int id_t,string Q0,string q)
    {
        fstream A_Q ("Question.txt",ios::out|ios::in|ios::app);
        A_Q<<id_f<<" "<<id_t<<'\n'<<0<<Q0<<q<<'\n';
        A_Q.close();

    }
    void cou_Q(int i)
    {
        i+=1;
        ofstream x0("counter_Question.txt",ios::trunc);
            x0<<i;
            x0.close();
    }

};
class List_System_User
{
    public:
    void display (int co,vector<User>& x)
    {
        for (int i = 0; i <co; i++)
        {
            cout<<x[i].username<<" "<<x[i].ID_user<<'\n';
        }
        
    }
};
// class Feed
// {
//     public:
//     void display(int n,vector<Question>& Question0,vector<Answer_Question>& answer)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             int x=answer[i].posation_Question;
//             cout<<Question0[x]<<answer[i].answer_Question;
//         }
        
//     }
// };
int main()
{
    menu1 ob1;
    Sign_Up ob2;
    login ob3;
    Print_Question_To_Me ob4;
    Print_Question_From_Me ob5;
    Answer ob6;
    Delete_Question ob7;
    Ask_Question ob8;
    List_System_User ob9;
    int n;
    cin>>n;
    vector <User> x(1000);
    vector<Question> Question0(1000);
    vector<Answer_Question> answer(1000);
     int i;
    fstream Co ("counter.txt",ios::out|ios::in);
    Co>>i;
    Co.close();
    if (n==2)
    {
       ob2.print_sign();
       cin>>x[i].username;
       cin>>x[i].pass;
       ob2.set_user(x[i].username,x[i].pass,i);
        i++;
        ofstream x("counter.txt");
        x<<i;
        x.close();
    }
    download(i,x);
    // for (int j = 0; j < i; j++)
    // {
    //     cout<<x[i].username<<"   "<<x[i].pass<<'\n';
    // }
    int co_Question;
    fstream Co_q ("counter_Question.txt",ios::out|ios::in);
    Co_q>>co_Question;
    Co_q.close();
    int co_Answer;
    fstream Co_Answer ("counter_Answer.txt",ios::out|ios::in);
    Co_Answer>>co_Answer;
    Co_Answer.close();
    if (n==1)
    {
        ob3.print_log();
        string a,b;
        cin>>a>>b;
        ob3.search(a,b,i,x);
        if (ob3.res_login()==0)
        {
            cout<<"username or password wrong plasse try agane\n";
            return 0;
        }
        
        int m2;
        while(cin>>m2)
        {
       //cout<<ob3.return_id();
       if (m2==1)
       {
        download_Question(co_Question,Question0);
        ob4.search1(co_Question,ob3.return_id(),Question0);
        menu2();
        
       }
       if (m2==2)
       {
        download_Question(co_Question,Question0);
        ob5.search2(co_Question,ob3.return_id(),Question0);
        menu2();
       }
       if (m2==3)
       {
        download_Question(co_Question,Question0);
        ob6.search3(co_Question,ob3.return_id(),Question0);
        if (ob6.get_posation_Q()==-1)
        {
            menu2();
            continue;
        }
        else
        {
            string ff,zz;
            cout<<"Write the answer to the question\n";
            cin>>zz;
            getline(cin,ff);
            ff.push_back('.');
           // cout<<zz<<ff;
            co_Answer++;
            ofstream x0("counter_Answer.txt",ios::trunc);
            x0<<co_Answer;
            x0.close(); 
            fstream answer0("Answer.txt",ios::app|ios::in|ios::out);
           answer0<<ob3.return_id()<<" "<<ob6.get_posation_Q()<<"\n"<<zz<<ff<<"\n";
           //answer0<<zz<<ff<<endl;
            answer0.close();
            Question0[ob6.get_posation_Q()].tast=1;
            upload_Question(co_Question,Question0);
            menu2();
        }
       }  
       if (m2==4)
       {
         download_Question(co_Question,Question0);
         ob7.search4(co_Question,ob3.return_id(),Question0);
         //int Po=ob7.get_posation_Q_D();
         if (ob7.get_posation_Q_D()==-1)
         {
            menu2();
            continue;
         }
         else
         {
            ob7.upload_Question_D(co_Question,ob7.get_posation_Q_D(),Question0);
            //upload_Question(co_Question,Question0);
            co_Question-=1;
            ofstream lol("counter_Question.txt");
            lol<<co_Question;
            lol.close();
            menu2();

         }
       }
       if (m2==5)
       {
           string Ask0,ask;int num_Q;
           ob8.print_Ask_Question();
           cin>>num_Q;
           if (num_Q==ob3.return_id())
           {
            cout<<"You can not ask yourself\n";
            menu2();
            continue;
           }
           else
           {
           cout<<"Write Your question\n";
           cin>>Ask0;
           getline(cin,ask);ask.push_back('?');
           //cout<<Ask0<<ask;
           ob8.get_Ask_Question(ob3.return_id(),num_Q,Ask0,ask);
           ob8.cou_Q(co_Question);
           menu2();
           }
       }
       if(m2==6)
       {
            ob9.display(i,x);
            menu2();
       }
       if (m2==7)
       {
        download_Question(co_Question,Question0);
        download_Answer(co_Answer,answer);
        for (int i = 0; i <co_Answer; i++)
        {
            int d=answer[i].posation_Question;
            string v=Question0[d].question;
            string c=answer[i].answer_Question;
            cout<<v<<c<<'\n';
        }
        menu2();
       }
       if (m2==8)
       {
        return 0;
       }
       
        }
    }
    return 0;
}
