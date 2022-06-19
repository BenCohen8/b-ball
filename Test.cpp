#include "doctest.h"
#include "b-ball.hpp"

#include <string>

TEST_CASE("League1")
{
   Team A{"a"};
Team B{"b"};
Team C{"c"};
Team d{"d"};Team n{"n"};
Team e{"e"};Team o{"o"};
Team f{"f"};Team p{"p"};
Team g{"g"};Team q{"q"};
Team h{"h"};Team r{"r"};
Team i{"i"};Team s{"s"};
Team j{"j"};Team t{"t"};
Team k{"k"};Team u{"u"};
Team l{"l"};
Team *tl[20]={&A,&B,&C,&g,&h,&i,&j,&k,&l,&n,&o,&p,&q,&r,&s};
League *L=new League(tl);
    Schedule sc(L);
    int g1=0;
    int b1=0;
    for (size_t i = 0; i < 20; i++)
    {
        CHECK(L->TL[i]->gp==38);
        CHECK(L->TL[i]->w+L->TL[i]->l==38);
        g1+=L->TL[i]->getgoodp();
        b1+=L->TL[i]->getbadp();


    }
    CHECK(b1==g1);

}
TEST_CASE("League2")
{
    
    League g{};
    Schedule sc(&g);
    for (size_t i = 0; i < 20; i++)
    {
        CHECK(g.TL[i]->gp==38);
    }
    
    
}