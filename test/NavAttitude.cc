/*
** NavAttitude.cc for Attitude Test in /home/fwt/myprogram/mscnav/submodules/tools/test
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Wed Jul 10 下午7:55:29 2019 little fang
** Last update Thu Jul 10 下午9:12:09 2019 little fang
*/

#include "navattitude.hpp"
#include "navlog.hpp"
#include "navstruct.hpp"
#include "glog/logging.h"
#include <iomanip>

using namespace utiltool;

int main(int argc, const char **argv)
{
    LogInit(argv[0], "./log/", google::INFO);
    RotationVector rv{0.25, 0.3, 0.4};
    auto rotation_mat = attitude::RotationVector2RotationMatrix(rv);
    auto euler = attitude::RotationMartix2Euler(rotation_mat);
    auto rotation_mat2 = attitude::Euler2RotationMatrix(euler);
    LOG(INFO) << "mat2 " << std::setprecision(10) << std::endl
              << rotation_mat2;
    LOG(WARNING) << "mat " << std::setprecision(10) << std::endl
                 << rotation_mat;
    return 0;
}