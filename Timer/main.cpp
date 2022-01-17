#include<iostream>
#include <thread>
#include<stdlib.h>
#include<ctime>
using namespace std;
using std::this_thread::sleep_for;
//pomodoro sess:
//Three Types:
/**
 * so three types:
 * 1. 25 minutes of work and 5 minutes of break
 * 2. 52 minutes of work and 17 minuest of break
 * 3.90 minutes of work and extended break
 * and the user can also customize the work and break time
 * #lets add the restriction features in the future
 */
class timer
{
    public:
        time_t pomo_start, pomo_finish;
        time_t break_start, break_finish;
        long int work_time, break_time;
        //we know diff time gives time in seconds
    void get_time()
    {
       int loop = true;
       while (loop)
       {
            
            int ans;
            cout<<"Please choose between the below options:"<<endl;
            cout<<"1. 25 minutes of work and 5 minutes of break\n";
            cout<<"2. 52 minutes of work and 17 minuest of break\n";
            cout<<"3. 90 minutes of work and extended break\n";
            cout<<"4. Custom";
            cin>>ans;
            switch (ans)
            {
            case 1:
                cout<<"You have chosen the first option"<<endl;
                work_time = 1500;
                break_time = 300;
                loop=false;
                break;
        case 2:
                cout<<"You have chosen the second option"<<endl;
                work_time = 2700;
                break_time = 1020;
                loop=false;
                break;
            case 3:
                cout<<"You have chosen the third option"<<endl;
                cout<<"Please enter the amount you time you want to take a beak for"<<endl;
                cin>>break_time;
                break_time = break_time*60;
                work_time = 5400;
                loop=false;
                break;
            case 4:
                long int minutes,seconds;
                cout<<"You have chosen to provide the time yourself:"<<endl;
                cout<<"Please enter the amount of time in minutes you want for study";
                cin>>minutes;
                cout<<"Please enter the amount of time in seconds you want for study";
                cin>>seconds;
                work_time = minutes*60 + seconds;
                cout<<"Please enter the amount of time in minutes you want for break";
                cin>>minutes;
                cout<<"Please enter the amount of time in seconds you want for break";
                cin>>seconds;
                break_time= minutes*60 + seconds;
                loop=false;
                break;
            default:
                cout<<"I guess you selected an invalid option"<<endl;
                loop=true;
                break;
            }
       }
        
    }
    void timer_start()
    {
        time(&pomo_start);
        time(&pomo_finish);
        while ((difftime(pomo_finish,pomo_start)) != work_time)
        {
            int seconds = difftime(pomo_finish,pomo_start);
            int mins= seconds/60;
            printf("***WORK-TIME****\n");
            printf("*************\n");
            printf("%2.2i:%2.2i\n",mins,(seconds%60));
            printf("*************\n");
            sleep_for(1000ms);
            system("CLS");
            time(&pomo_finish);
        }
        cout<<"Your work time has ended.\n Your break starts now"<<endl;
        time(&break_start);
        time(&break_finish);
        while ((difftime(break_finish,break_start)) != break_time)
        {
            int seconds = difftime(break_finish,break_start);
            int mins= seconds/60;
            printf("****Break_Time****\n");
            printf("*************\n");
            printf("%2.2i:%2.2i\n",mins,(seconds%60));
            printf("*************\n");
            sleep_for(1000ms);
            system("CLS");
            time(&break_finish);
        }
    }
    
};

int main()
{
    
    timer pomodoro;;
    pomodoro.get_time();
    pomodoro.timer_start();
}