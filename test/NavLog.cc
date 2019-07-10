/*
** NavLog.cc for MSCNAV in /media/fwt/学习/程序/myprogram/01-MSCNAV/example
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Mon Dec 17 下午3:30:10 2018 little fang
** Last update Thu Jul 10 下午8:57:27 2019 little fang
*/
#include "navstruct.hpp"
#include "navlog.hpp"
#include "navtime.h"
#include <Eigen/Core>

using namespace utiltool;

// void base_out(BaseData::Ptr ptr)
// {
//   navinfolog("%s,%d", ptr->get_time().Time2String().c_str(), ptr->get_type());
// }

int main(int argc, char const *argv[])
{

  // Eigen::Matrix<double, 3, 3> mat;
  // mat << 1, 2, 3, 4, 5, 6, 7, 8, 9;
  // navloginit(argv[0], "./log/");
  // navinfolog("%02d \t INFO", 1);
  // navwarnlog("%02d \t WARNING", 2);
  // naverrorlog("%02d \t ERROR", 3);

  // GnssData gnss(NavTime::NowTime());
  // gnss.pos_ << 2, 3, 1.89;
  // gnss.vel_ << 3.6, 3.2, 9.1;
  // naverrorlog("%s", gnss.to_string().c_str());
  // {
  //   base_out(dynamic_cast<BaseData *>(&gnss));
  // }
  return 0;
}
