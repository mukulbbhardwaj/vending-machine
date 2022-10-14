#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int order;
vector<string>coffee;
vector<string>add;
vector<int>bil;
class Coffee_House{
public:
    vector<string>item={"Espresso","Cappuccino","Latte"};
    vector<string>add_ons={"Milk","Cream","Latte","No Add-On"};
    vector<int>item_price={100,100,100};
    vector<vector<int>>ad_price={{60,80,100},{80,90,125},{100,125,150}};
    void show_item(){
        cout<<"___________________"<<endl;
        cout<<"-> Products/Add-on       |  Milk  |  Cream  |  Latte  |"<<endl;
        cout<<"___________________"<<endl;
        cout<<"1.  Espresso -> Rs.100    |  60    |  75     |  100    |"<<endl;
        cout<<"___________________"<<endl;
        cout<<"2.  Cappuccino -> Rs.100  |  80    |  90     |  125    |"<<endl;
        cout<<"___________________"<<endl;
        cout<<"3.  Latte -> Rs.100       |  100   |  125    |  150    |"<<endl;
        cout<<"___________________"<<endl;
        cout<<endl;
    }
    void bill(int ord){
        int res=0;
        cout<<"Your Product-> "<<item[ord-1]<<endl;
        int addon;
        cout<<"Do you want Add-on? \n 1. Milk \n 2. Cream \n 3. Latte \n Choose(0 for no add-on):";
        cin>>addon;
        cout<<endl;
        cout<<"Order Details:"<<endl;
        cout<<"Your Product-> "<<item[ord-1]<<endl;
        coffee.push_back(item[ord-1]);
        if(addon==0){
            cout<<"Your Add-on-> "<<add_ons[3]<<endl;
            add.push_back(add_ons[3]);
            bil.push_back(0);
            return;
        }
        cout<<"Your Add-on-> "<<add_ons[addon-1]<<endl;
        add.push_back(add_ons[addon-1]);
        cout<<"Price = "<<item_price[ord-1]+ad_price[ord-1][addon-1]<<endl;
        cout<<"-------------------------------------------"<<endl;
        bil.push_back(item_price[ord-1]+ad_price[ord-1][addon-1]);
    }
};

int main(){
 Coffee_House o;
 int n=1;
 o.show_item();
 cout<<"-------------------------------------------"<<endl;
 while(n!=0){
        cout<<"Please select the product(Choose 0 to exit): ";
        cin>>order;
        if(order<0 || order>3){
            cout<<"---------Choose Correct Order-----------"<<endl;
            continue;
        }
        if(order==0){
            break;
        }
        o.bill(order);
 }
 if(coffee.size()==0){
        cout<<"---------Thanks For Coming-----------"<<endl;
 }
 else{
        cout<<"-------------------------------------------"<<endl;
        cout<<"Your Full Order Details:"<<endl;
        for(int i=0;i<coffee.size();i++){
            cout<<"Product "<<i+1<<" -> "<<coffee[i]<<endl;
            cout<<"Add-on-> "<<add[i]<<endl;
        }cout<<endl;
        int total=accumulate(bil.begin(),bil.end(),0);
        cout<<"Your total Bill payment: Rs"<<total<<endl;
        cout<<"---------Thanks For Coming-----------"<<endl;
 }
    return 0;
}
