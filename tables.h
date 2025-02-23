#ifndef TABLES_H
#define TABLES_H

#include <string>
using namespace std ;
class tables {
private:
  struct node{
  string date ;
  int tables_per_hours[9]= {10,10,10,10,10,10,10,10,10} ;//each hour Contains 10 table- hours from 4pm to 12am
  node * link ;  
  }*head = nullptr;  //head pointer
    
  public:
   void create_node(string date);
   int tabel_numbers(int number_of_people);
   void Reserve_tables(string date , int timee , int number_of_tables);//تطرح عدد الطاولات اللي بيتم حجزها من عدد الطاولات المتاحه
   void cancelReserve_tables(string date , int timee , int number_of_tables);//ترجع عدد الطاولات المحجوزه 
   bool check(string date , int timee , int number_of_tables);//check If there are tables available
   
   };

#endif