/*
** NavTime.cc for MSCNAV in /media/fwt/学习/程序/myprogram/01-MSCNAV/example
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Mon Dec 17 下午12:56:38 2018 little fang
** Last update Thu Jul 3 13:20:08 2019 little fang
*/

#include "navtime.h"
#include "navstruct.h"
#include "navlog.hpp"

using namespace mscnav::utiltool;

int main(int argc, char const *argv[])
{
  navloginit(argv[0], "./log");
  NavTime time1 = NavTime::NowTime();
  printf("%s\n", time1.Time2String().c_str());
  navsleep(2000);
  NavTime time2 = NavTime::NowTime();
  printf("%s\n", time2.Time2String().c_str());
  printf("%s\n", time1 <= time2 ? "True" : "FALSE");
  NavTime time3(2018, 12, 1, 0, 0, 0.0);
  time3 += 60.0;
  NavTime time4 = time3 + NavTime::MAXSECONDOFDAY;
  navinfolog("%s", time2.Time2String().c_str());
  navexit();
  return 0;
}
