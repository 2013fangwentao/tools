/*
** navattitude.hpp for mscnav in /home/fwt/myprogram/mscnav/submodules/tools/include
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Wed Jul 10 下午12:39:42 2019 little fang
** Last update Thu Jul 10 下午1:06:47 2019 little fang
*/

#ifndef NAVATTITUDE_H_
#define NAVATTITUDE_H_
#include "stdio.h"
#include <Eigen/Dense>
#include <Eigen/Geometry>

namespace utiltool
{

struct Euler
{
    double roll;
    double pitch;
    double heading;
};

namespace Attitude
{

/**
 * @brief  quaternion to rotation martrix by Eigen
 * @note   
 * @param  q: quaternion 
 * @retval rotation matrix 
 */
Eigen::Matrix3d Quaternion2RotationMatrix(Eigen::Quaterniond &q)
{
    return q.toRotationMatrix();
}

/**
  * @brief  rotation martrix to quaternion by Eigen
  * @note   
  * @param  mat: 
  * @retval 
  */
Eigen::Quaterniond RotationMartix2Quaternion(Eigen::Matrix3d &mat)
{
    Eigen::Quaterniond q(mat);
    return q;
}
} // namespace Attitude
} // namespace utiltool

#endif /* !NAVATTITUDE */
