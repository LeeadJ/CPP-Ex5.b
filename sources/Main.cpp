// #include "Node.hpp"
// #include "OrgChart.hpp"
// #include<queue>
// using namespace std;
// using namespace ariel;

// int main(){
//     // vector<string> names = {"Bulbasaur", "Charmander", "Squirtle", "Caterpie", "Weedle", "Pidgey"};
//     // vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     // vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     // vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     // OrgChart organization;
//     // organization.add_root(names[0])
//     //     .add_sub(names[0], names[1])
//     //     .add_sub(names[0], names[2])
//     //     .add_sub(names[0], names[3])
//     //     .add_sub(names[1], names[4])
//     //     .add_sub(names[3], names[5]);
//     // size_t i = 0;
//     // for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     // {
//     //     cout<<(*it)<<" ";
//     // } // Needs to be like exp_level_order
//     // cout<<""<<endl;

//     // i = 0;
//     // for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     // {
//     //     cout<<(*it)<<" ";
//     // } // Needs to be like exp_reverse_order
//     // cout<<""<<endl;

//     OrgChart o;
//     o.add_root("CEO")
//         .add_sub("CEO", "CTO")
//         .add_sub("CEO", "CFO")
//         .add_sub("CEO", "COO")
//         .add_sub("CTO", "VP_SI")
//         .add_sub("COO", "VP_BI");
//     cout<<"Level Order:"<<endl;
//     for (auto it = o.begin_level_order(); it != o.end_level_order(); ++it){
//         cout<<(*it)<<" ";
//     }
//     cout<<""<<endl;
//     cout<<"Pre Order:"<<endl;
//     for (auto itr = o.begin_preorder(); itr != o.end_preorder(); ++itr){
//         cout<<(*itr)<<" ";
//     }
//     cout<<""<<endl;

//     cout<<"Reverse Order:"<<endl;
//     for (auto it = o.begin_reverse_order(); it != o.reverse_order(); ++it){
//         cout<<(*it)<<" ";
//     }
//     cout<<""<<endl;


//     // class Person {
//     // public:
//     //     string name;
//     //     int age;

//     //     Person(string Name, int Age) : name(Name), age(Age) {}

//     //     bool operator==(Person &p1) {
//     //         return this->name == p1.name;
//     //     }
//     // };
//     // //instantiate People
//     // Person Great_GrandFather("Great_GrandFather", 85);
//     // Person Grandfather("GrandFather", 65);
//     // Person Father("Father", 45);
//     // Person Uncle("Uncle", 43);
//     // Person Aunt("Aunt", 43);
//     // Person Son("Son", 20);
//     // Person Daughter("Daughter", 18);
//     // Person Cousin("Cousin", 15);
//     // Person GreatGrandma("GreatGrandma", 84);
//     // Person Cousin2("Cousin2", 14);
//     // Person GreatUncle("GreatUncle", 62);
//     // OrgChart chart1;

//     // chart1.add_root(Aunt.name);
//     // chart1.add_root(Great_GrandFather.name);
//     // chart1.add_sub(Great_GrandFather.name, Grandfather.name);
//     // chart1.add_sub(Grandfather.name, Father.name);
//     // chart1.add_sub(Grandfather.name, Uncle.name);
//     // chart1.add_sub(Grandfather.name, Aunt.name);
//     // chart1.add_sub(Father.name, Son.name);
//     // chart1.add_sub(Father.name, Daughter.name);
//     // chart1.add_sub(Uncle.name, Cousin.name);
//     // chart1.add_sub(Aunt.name, Cousin2.name);
//     // chart1.add_sub(Great_GrandFather.name, GreatUncle.name); 
//     // chart1.add_root(GreatGrandma.name);




//     // cout<<"he"<<endl;
//     // vector<string> pre_order;
//     // for (auto it = chart1.begin_preorder(); it != chart1.end_preorder(); ++it) {
//     //     pre_order.push_back(*it);
//     //     cout<<(*it)<<endl;
//     //     // it.getCurrNodePtr()->printNode();
//     // }
//     // cout<<pre_order.size()<<endl;

//     // // cout<<"he"<<endl;
//     // cout<<(pre_order.at(0) == GreatGrandma.name)<<endl;;
//     // cout<<(pre_order.at(1) == Grandfather.name)<<endl;
//     // cout<<(pre_order.at(2)== Father.name)<<endl;
//     // cout<<(pre_order.at(3)== Son.name)<<endl;
//     return 0;
// }