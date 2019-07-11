/*
** NavLog.cc for MSCNAV in /media/fwt/学习/程序/myprogram/01-MSCNAV/example
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Mon Dec 17 下午3:30:10 2018 little fang
** Last update Fri Jul 11 上午8:29:49 2019 little fang
*/
#include "navstruct.hpp"
#include "navlog.hpp"
#include "navtime.h"
#include "navconfig.hpp"
#include <Eigen/Core>

using namespace utiltool;
using std::string;

int main(int argc, char const *argv[])
{
  string text_split("3,4,5,6,9,");
  auto res = TextSplit(text_split, ",");
  for (auto index : res)
  {
    std::cout << index << std::endl;
  }

  //
  ConfigInfo::Ptr config = ConfigInfo::GetInstance();
  config->open("../config/configture.ini");
  std::cout << config->get<string>("text") << std::endl;
  std::cout << std::fixed << std::setprecision(3) << config->get_array<int>("angle") << std::endl;
  std::cout << config->get_array<double>("pixel") << std::endl;
  std::cout << config->get_array<string>("LOGLEVEL") << std::endl;
  std::cout << config->get_array<double>("example") << std::endl;
  std::cout << config->get<string>("table") << std::endl;

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
