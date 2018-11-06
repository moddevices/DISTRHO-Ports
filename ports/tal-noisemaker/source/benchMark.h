//this is a altered version of a benchMark test written by by Filipe Coelho
#ifndef _H_BENCHMARK_
#define _H_BENCHMARK_

//dependencies
#include <stdio.h>
#include <stdint.h>
#include <sched.h>
#include <unistd.h>


class BenchMark
{
public:
  BenchMark(const char* c)
  {
    this->c=c;
  }
  ~BenchMark()
  {
    log();
  }
  //sets the state of the CPU ready for measurement
  void initTicks(void)
  {
      cpu_set_t cpuset;
      CPU_ZERO(&cpuset);
      CPU_SET(0, &cpuset);
      sched_setaffinity(0, sizeof(cpuset), &cpuset);
  }
  //reads the amount of ticks from the PMCCNTR register
  //code by Filipe Coelho
  uint32_t getTicks(void)
  {
      uint32_t r;
      asm volatile("mrc p15, 0, %0, c9, c13, 0\t\n" : "=r"(r));   /* Read PMCCNTR       */
      return r;                                                   /* 1 tick = 64 clocks */
  }
  //writes ticks between two time points to log with identifier c
  void writeTicks(uint32_t t1, uint32_t t2)
  {
    totalAmountOfticks = totalAmountOfticks + (t2-t1);
    amountOfTicks++;
  }

  void log()
  {
    FILE *fp; //create log file
    fp = fopen("benchMarkLog.txt", "a"); //open the file in append mode
    //take average of ticks
    totalAmountOfticks = totalAmountOfticks / amountOfTicks;
    //write timeBetweenTicks to log + newline
    fprintf(fp, "%s :Time between ticks was %i ticks\n", c, totalAmountOfticks);
    fclose(fp); //close the file
  }
private:
  const char* c;
  uint32_t t1, t2;
  int totalAmountOfticks = 0;
  int amountOfTicks = 0;
};

#endif //_H_BENCHMARK_
