/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp"

using namespace ariel;


int main() {
    Point a(32.3, 44), b(1.3, 3.5);
    assert(a.distance(b) == b.distance(a));
    Character *ch = new Cowboy("COWBOY", a);
    Character *ch1 = new OldNinja("Tommy1", a);
    Character *ch2 = new TrainedNinja("Tommy2", a);
    Character *ch3 = new YoungNinja("Tommy3", a);
    Character *ch4 = new Cowboy("COWBOY2", a);

    Character *ch9 = new Cowboy("COWBOY", a);
    Character *ch91 = new OldNinja("Tommy1", a);
    Character *ch92 = new TrainedNinja("Tommy2", a);
    Character *ch93 = new YoungNinja("Tommy3", a);
    Character *ch94 = new Cowboy("COWBOY2", a);

    Team team = {ch3};
    team.add(ch1);
    team.add(ch);
    team.add(ch2);
    team.add(ch4);
    //team.sortArray();

    team.print();
    cout << "-------------------" << endl;
    Team2 team2 = {ch93};
    team2.add(ch91);
    team2.add(ch9);
    team2.add(ch92);
    team2.add(ch94);
    team2.print();
    //    ch->print();
//    ch1->print();
//    ch2->print();
//    ch3->print();
//    ch->hit(120);
//    ch->print();


    /*Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));


     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;
*/
    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}
