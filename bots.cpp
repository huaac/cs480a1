#include "bots.hpp"
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string>

sem_t FLAG;
pthread_mutex_t LOCK = PTHREAD_MUTEX_INITIALIZER;
int total_thread = 7;
int total_runs = 8;

void* BotAction(void* id_num)
{
    int id = *(int*)id_num;
    int sleep_timer = 0;
    std::string quote = "";

    //set sleep timer based off of id num
    if(id % 2 == 0) // if id even number
    {
        sleep_timer = 2;
        quote = " \"Controlling complexity is the essence of computer programming.\" -Brian Kernighan";
    }
    else // if id is odd number
    {
        sleep_timer = 3;
        quote = " \"Computer science is no more about computers than astronomy is about telescopes.\" -Edsger Dijkstra";
    }

    for(int i = 0; i < total_runs; i++)
    {
        sleep(sleep_timer);

        //get semaphore
        sem_wait(&FLAG);

        //open QUOTE and write to end of file
        std::ofstream file1("QUOTE.txt", std::ios::app);
        file1 << "THREAD ID: " << id << quote << "\r\n";

        //write to console
        pthread_mutex_lock(&LOCK); //makes it so that threads dont write on same line
        std::cout << "Thread " << id  << " is running" << std::endl;
        pthread_mutex_unlock(&LOCK);

        file1.close();

        //release semaphore
        sem_post(&FLAG);
    }
    pthread_exit(nullptr);

}

int main()
{
    //write pID(process ID) in quote
    std::ofstream file("QUOTE.txt");

    pid_t pid = getpid();
    file << "Process ID: " << pid << "\r\n";

    file.close();

    //create semaphore FLAG for threads to manage access
    sem_init(&FLAG, 0,1);


    pthread_t threads[total_thread]; // stores thread id/handles to know which thread to wait for
    int ids[total_thread]; //stores id number i at thread number i


    //create 7 threads
    for( int i=0; i < total_thread; i++)
    {
        std::cout << "Creating thread, in main(): " << (i + 1) << std::endl;
        ids[i] = i + 1;

        pthread_create(
            &threads[i],    //where thread id stored
            nullptr,        //no thread attributes
            BotAction,      //function we want to run
            &ids[i]         //argument we pass into the function parameters
        );
    }

    //wait for all 7 threads to complete their work
    for(int i = 0; i < total_thread; i++)
    {
        pthread_join(threads[i], nullptr);
    }

    //destroy semaphore
    sem_destroy(&FLAG);

    std::cout << "All bots have completed sharing their message." << std::endl;

    return 0;

}
// std::cout << "Hello" << std::endl;
//"Controlling complexity is the essence of computer programming." -Brian Kernighan
//"Computer science is no more about computers than astronomy is about telescopes." -Edsger Dijkstra
