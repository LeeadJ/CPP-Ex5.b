// #include "Node.hpp"
// #include "OrgChart.hpp"
// #include<queue>
// using namespace std;
// using namespace ariel;

// int main(){
//     OrgChart army;
//     army.add_root("Battalion");
//     army.add_sub("Battalion", "Company1");
//     army.add_sub("Battalion", "Company2");
//     army.add_sub("Battalion", "Company3");

//     army.add_sub("Company1", "Platoon1.1");
//     army.add_sub("Company1", "Platoon1.2");
//     army.add_sub("Company1", "Platoon1.3");

//     army.add_sub("Company2", "Platoon2.1");
//     army.add_sub("Company2", "Platoon2.2");
//     army.add_sub("Company2", "Platoon2.3");

//     army.add_sub("Company3", "Platoon3.1");
//     army.add_sub("Company3", "Platoon3.2");
//     army.add_sub("Company3", "Platoon3.3");

//     army.add_sub("Platoon1.1", "Squad1.1.1");
//     army.add_sub("Platoon1.1", "Squad1.1.2");
//     army.add_sub("Platoon1.1", "Squad1.1.3");
//     army.add_sub("Platoon1.2", "Squad1.2.1");
//     army.add_sub("Platoon1.2", "Squad1.2.2");
//     army.add_sub("Platoon1.2", "Squad1.2.3");
//     army.add_sub("Platoon1.3", "Squad1.3.1");
//     army.add_sub("Platoon1.3", "Squad1.3.2");
//     army.add_sub("Platoon1.3", "Squad1.3.3");

//     army.add_sub("Platoon2.1", "Squad2.1.1");
//     army.add_sub("Platoon2.1", "Squad2.1.2");
//     army.add_sub("Platoon2.1", "Squad2.1.3");
//     army.add_sub("Platoon2.2", "Squad2.2.1");
//     army.add_sub("Platoon2.2", "Squad2.2.2");
//     army.add_sub("Platoon2.2", "Squad2.2.3");
//     army.add_sub("Platoon2.3", "Squad2.3.1");
//     army.add_sub("Platoon2.3", "Squad2.3.2");
//     army.add_sub("Platoon2.3", "Squad2.3.3");

//     army.add_sub("Platoon3.1", "Squad3.1.1");
//     army.add_sub("Platoon3.1", "Squad3.1.2");
//     army.add_sub("Platoon3.1", "Squad3.1.3");
//     army.add_sub("Platoon3.2", "Squad3.2.1");
//     army.add_sub("Platoon3.2", "Squad3.2.2");
//     army.add_sub("Platoon3.2", "Squad3.2.3");
//     army.add_sub("Platoon3.3", "Squad3.3.1");
//     army.add_sub("Platoon3.3", "Squad3.3.2");
//     army.add_sub("Platoon3.3", "Squad3.3.3");
    
//     cout<<"Level Order:"<<endl;
//     for (auto it = army.begin_level_order(); it != army.end_level_order(); ++it){
//         cout<<(*it)<<" ";
//     }
//     cout<<""<<endl;
//     cout<<"\nPre Order:"<<endl;
//     for (auto itr = army.begin_preorder(); itr != army.end_preorder(); ++itr){
//         cout<<(*itr)<<" ";
//     }
//     cout<<""<<endl;

//     cout<<"\nReverse Order:"<<endl;
//     for (auto it = army.begin_reverse_order(); it != army.reverse_order(); ++it){
//         cout<<(*it)<<" ";
//     }
//     cout<<""<<endl;
    
//     return 0;
// }