#include <iostream> 
#include <sstream> 
#include <vector> 

using namespace std;

struct OrderBook {
   string value;
   int amount;
};


vector<string> split(string s, char delimiter=' '){

   stringstream ss(s); 

   string token; 
   vector<string> tokens; 

   while (getline(ss, token, delimiter)) { 
      tokens.push_back(token); 
   } 

   return tokens;
}


void insertOrderBook(OrderBook orderBook[], int position, string value, int amount){
   if(stod(value) > 0 && amount > 0){
      orderBook[position-1].value  = value;
      orderBook[position-1].amount = amount;
   }
}


void modifyOrderBook(OrderBook orderBook[], int position, string value, int amount){
   if(stod(value) > 0){
      orderBook[position-1].value = value;
   }else if(amount > 0){
      orderBook[position-1].amount  = amount;
   }else if(stod(value) > 0 && amount > 0){
      orderBook[position-1].value  = value;
      orderBook[position-1].amount = amount;
   }
}


void deleteOrderBook(OrderBook orderBook[], int position, int length){
   if(position < 1 || position > length)
      return;

   for (int i = position-1; i < length - 1; ++i){
      orderBook[i] = orderBook[i + 1]; // copy next element left
   }
}


void showOrderBook(OrderBook orderBook[], int length){
   int position = 1;
   cout << "\n";
   for(int i=0; i<length;i++){
      string value = orderBook[i].value;
      int amount = orderBook[i].amount;

      if(stod(value) != 0 && amount != 0){ 
         cout << position << "," << value << "," << amount;
         position++;
      }
      cout << "\n";
   }
}


int main(){

   int p; 
   cout << ">"; 
   cin >> p; 

   OrderBook orderBook[p];

   for(int i=0; i<p;i++){
      orderBook[i].value = "0";
      orderBook[i].amount = 0;
   }
   

   int i=0;
   while(i<p){
      string instruction; 
      cout << ">"; 
      cin >> instruction; 

      vector<string> tokens = split(instruction,',');

      int position = stoi(tokens[0]);
      int action   = stoi(tokens[1]);
      int amount   = stoi(tokens[3]);
      string value = tokens[2];


      if(action == 0){
         insertOrderBook(orderBook, position,value, amount);
      }else if(action == 1){
         modifyOrderBook(orderBook, position, value, amount);
      }else if(action == 2){
         deleteOrderBook(orderBook, position, p);
      }

      i++;
   }

   int lengthOrderBook = sizeof(orderBook)/sizeof(orderBook[0]);
   showOrderBook(orderBook, lengthOrderBook);

   return 0;
}