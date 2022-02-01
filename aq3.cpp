#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

       /*function to produce new questions for the student using srand and rand . */
       void newque(int &m,int &n,int &flag)
        {
              if(flag==1)
              {
             m=rand()%10;
             n=rand()%10;
             }
             else
             {
             m=rand()%((10*flag)-flag)+flag;
             n=rand()%((10*flag)-flag)+flag;
             }
        }

        /*function to choose the remarks for the student. */
        void  remarks(int &c)
        {
              c= (rand()%4) + 1 ;
        }

       int main()
       {
           /*m and n to store the two numbers of the question , ans to store the answer entered by the student , c to store the random remark for the student among the given one according to his/her performance , r and w to store the frequency of the correct and the wrong answers entered by the student and using flag to alter the number of digits according to the level . */
           int  m,n,ans,c,r=0,w=0,flag=1;

          //to store the percentage of the student in each level.
           double  per=0.0 ;
          cout<<"WELCOME TO THE WORLD OF DIGIT MULTIPLICATION IN MATHEMATICS!!"<<endl;
          srand(time(NULL));
          //labeling the point to use the goto statement.
          again :
          newque(m,n,flag);
          cout<<"How  much  is  "<<m<<"  times  "<<n<<"  ?  "<<endl;


          //labeling the another point to use the goto statement.
          begin:
          /* Asking the input from the user as the answer of the questions. */
          cin>>ans;
          if(ans==(m*n))
          {
              r=r+1;
             remarks(c);
            /*choosing the random remark among the following. */
            switch(c)
            {
               case 1 :
               cout<<"   Very    good  !\n "<<endl;
               break;

              case 2 :
              cout<<"   Excellent  !  \n "<<endl;
              break;

              case 3:
              cout<<"   Nice   Work  !\n  "<<endl;
              break;

              case 4:
              cout<<"   keep  up  the  good    work  ! \n  "<<endl;
              break;

             default:
             cout<<"Never  executed  "<<endl;
          }

           /*if the frequency of the answers is equal to 10 the calculating the percentage of the student in the current level. */
           if((r+w)==10)
           {
              mark :
              per=(r*10);
             /* If the percentage of the student in this level is greater than equal to 75 percent than promote the student to the next level. */
             if(per>=75)
               {
                  cout<<"\nCongratulations,  you   are    ready    to    go    to    the     next     level  !  "<<endl ;
                  cout<<"Your  Percentage  in  this  level  is  "<<per<<" % "<<endl ;
                  cout<<endl ;
                  cout<<"\nWELCOME TO THE NEXT LEVEL :) "<<endl ;
                  /*Promoting the flag to design the new question for the student. */
                  flag=flag*10 ;
                 /*Framing the new level for the student. */
                  newque(m,n,flag);
                  r=0;
                  w=0;
                  per=0.0;
              }
             else
              {
                  cout<<"Please, Ask your teacher for help. "<<endl;
                  cout<<"As your percentage i.e "<<per<<"is less than 75 %. So, you should play this level again under the guidance of your teacher for your better performance."<<endl;
                  cout<<".................................ALL    THE   BEST....................................."<<endl ;
                  r=0;w=0;per=0.0;
             }
           }
                goto again;
         }
          else
          {
           /*If student has entered the wrong answer then providing his/her the chances untill and unless he/she writes the right answer. */
            w=w+1;
            remarks(c);
           /*choosing the random remark among the following. */
           switch(c)
         {
               case 1 :
               cout<<"   No.  Please   Try   again.\n"<<endl;
               break;

              case 2 :
              cout<<"   Wrong.  Try   once   more.\n "<<endl;
              break;

              case 3:
              cout<<"   Don't  give   up !  \n"<<endl;
              break;

              case 4:
              cout<<"  No.  Keep   trying. \n "<<endl;
              break;

             default:
             cout<<"Never  executed  "<<endl;
         }
              if((r+w)==10)
              {
                 goto mark;
              }
         goto begin;
         }

         return 0;
     }
