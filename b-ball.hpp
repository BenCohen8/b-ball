#include <iostream>
#include <string>
#include <vector>
#include <sys/queue.h>
#include <queue>          // std::queue
#include <algorithm>



using namespace std;
vector<string> randomNames={"aa","bb","cc","dd","ee","ff","gg","hh","ii","jj","kk","ll","mm","nn","oo","pp","qq","rr","zs","tt","uu","vv","ww","xx","yy","zz"};
class Team
{
private:
    string name;
    int talent;
    int goodp;
    int badp;
public:
bool operator<(const Team& b);

int gp=0;
    int w;
    int l;
    void setgoodp(int p)
    {
        this->goodp+=p;
    }
        void setbadp(int p)
    {
        this->badp+=p;
    }
    int getgoodp(){return this->goodp;}
    int getbadp(){return this->badp;}
    int gettalent(){return this->talent;}
    string getName(){return this->name;}

    Team(string n);
    Team(){}
    ~Team();
    
};
struct less_than_key
{
    inline bool operator() ( Team& t1,  Team &t2)
    {
        if (t1.w!=t2.w)
        {
            return (t1.w > t2.w);
        }
        if (t1.getgoodp()-t1.getbadp()!=t2.getgoodp()-t2.getbadp())
        {
            return t1.getgoodp()-t1.getbadp()>t2.getgoodp()-t2.getbadp();
        }
        return t1.getgoodp()>t2.getgoodp();
        
    }
    
};
bool Team::operator<(const Team &b)
{
   return this->w<b.w;
}
Team::Team(string n)
{
    this->talent=rand()%2;
    this->name=n;
    this->goodp=0;
    this->badp=0;
    this->w=0;
    this->l=0;
}

Team::~Team()
{
}

class Game
{
private:
    Team *H;
    Team *A;
    int score[2];
    
public:
    Game(Team*,Team*);
    ~Game();
};

Game::Game(Team *H,Team* A)
{
    this->H=H;
    this->A=A;
    int hs=rand()%55+45 +10*H->gettalent();
    int as=rand()%50+50+ 10*A->gettalent();
    this->A->setgoodp(as);
    this->A->setbadp(hs);
    this->H->setbadp(as);
    this->H->setgoodp(hs);
    A->gp++;
    H->gp++;
    if (as>=hs)
    {
        this->A->w+=1;
        this->H->l+=1;
    }else
    {
        this->H->w+=1;
        this->A->l+=1;
    }
    
    
}

Game::~Game()
{
}

class League
{
private:
public:
string name;
    Team *TL[20];//define 20 Teams in the league
    void printl();
    League( Team  * t[]);
    League();
    ~League();
};

League::League( Team * t[])
{
    int r=0;
    for (size_t i = 0; i < 20; i++)
    {
        if (t[i])
        {
        this->TL[i]=t[i];
        r++;
        }
        
    }  
    cout<<r<<endl; 
    
        for (size_t i = r; i < 20; i++)
        {
            int j=rand()%26;
            Team * team=new Team(randomNames[j]);
            this->TL[i]=team;
         //   randomNames.erase(randomNames.begin()+j);
        }
        
    
    

}
void League::printl()
{
        cout<<"Name\tGames\tWins\tLosses\tGoodPO\tBadPO\t+-"<<endl;
            vector<Team> vt(20);

 for (unsigned long i = 0; i < 20; i++)
    {
        vt[i]=*this->TL[i];

    }
      sort(vt.begin(),vt.end(),less_than_key());

   for (size_t i = 0; i < 20; i++)
   {
       cout<<vt[i].getName()<<"\t"<<this->TL[i]->gp<<"\t"<<vt[i].w<<"\t"<<vt[i].l<<"\t"<<vt[i].getgoodp()<<"\t"<<vt[i].getbadp()<<"\t"<<vt[i].getgoodp()-vt[i].getbadp()<<endl;
   }
}
League::League()
{
    this->name="ggg";
         vector<string> t1;
         t1=randomNames;
         int i1=sizeof(t1);
        for (size_t i = 0; i < 20; i++)
        {
            Team * team=new Team{t1[i]};
            this->TL[i]=team;
            //t1.erase(t1.begin()+j);  
        }
}

League::~League()
{

}
vector<int> home={1,2,3,4,5,6,7,8,9};
vector<int> away={19,18,17,16,15,14,13,12,11,10};
int w=0;
class MatchDay
{
private:
 Game * Games[10];
int count;

public:
    MatchDay(League * L,int c);
    ~MatchDay();
};
    

MatchDay::MatchDay(League * L,int c)
{
    w=away[0];
    away.erase(away.begin());
    if (c<20)
    {        
        Game A{L->TL[0],L->TL[w]};
        Games[0]=&A;
    }else
    {
        Game A{L->TL[w],L->TL[0]};
        Games[0]=&A;
    }
    
    for (int i = 0; i < 9; i++)
    {
        if(c<20)
        {
         //   cout<<away[i]<<endl;
            Game A{L->TL[home[i]],L->TL[away[i]]};  
            Games[i]=&A;      
        }else
        {
            Game A{L->TL[home[i]],L->TL[away[i]]};    
            Games[i]=&A;      
        }
    }
    home.insert(home.begin(),w);
    int t=home[9];
    home.erase(home.end()-1);
    away.push_back(t);
  //  cout<<endl;
}



MatchDay::~MatchDay()
{

}
class Schedule
{
private:
    MatchDay * MD[38];
public:
    Schedule(League *l);
    Schedule();
    ~Schedule();

};

Schedule::Schedule(League *l)
{
    for (int i = 1; i <= 38; i++)
    {
        MatchDay x(l,i);
       // MD[i]=&x;
    }
    
}
Schedule::Schedule()
{
}
Schedule::~Schedule()
{
}


