/*
** navattitude.hpp for mscnav in /home/fwt/myprogram/mscnav/submodules/tools/include
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Wed Jul 10 下午12:39:42 2019 little fang
** Last update Thu Jul 10 下午9:39:48 2019 little fang
*/

#ifndef NAVATTITUDE_H_
#define NAVATTITUDE_H_
#include "stdio.h"
#include "navbase.hpp"
#include <Eigen/Dense>
#include <Eigen/Geometry>

namespace utiltool
{

using RotationVector = Eigen::Vector3d;
using Euler = Eigen::Vector3d; /*roll, pitch, heading*/

namespace attitude
{

/**
 * @brief  quaternion to rotation martrix by Eigen
 * @note   
 * @param  q: quaternion 
 * @retval rotation matrix 
 */
Eigen::Matrix3d Quaternion2RotationMatrix(const Eigen::Quaterniond &q)
{
    return q.toRotationMatrix();
}

/**
  * @brief  rotation martrix to quaternion by Eigen
  * @note   
  * @param  mat: 
  * @retval 
  */
Eigen::Quaterniond RotationMartix2Quaternion(const Eigen::Matrix3d &mat)
{
    Eigen::Quaterniond q(mat);
    return q;
}

/**
 * @brief  
 * @note   
 * @param  &euler: 
 * @retval 
 */
Eigen::Quaterniond Euler2Quaternion(const Euler &euler)
{
    //TODO need check the order
    return (Eigen::AngleAxisd(euler[2], Eigen::Vector3d::UnitZ()) *
            Eigen::AngleAxisd(euler[1], Eigen::Vector3d::UnitY()) *
            Eigen::AngleAxisd(euler[0], Eigen::Vector3d::UnitX()));
}

/**
 * @brief  Euler angle to rotation matrix
 * @note   
 * @param  euler: Euler angle
 * @retval 
 */
Eigen::Matrix3d Euler2RotationMatrix(const Euler &euler)
{
    return Quaternion2RotationMatrix(Euler2Quaternion(euler));
}

/**
  * @brief  Rotation Matrix to Euler by Eigen
  * @note   note the order of the axis
  * @param  &mat: 
  * @retval 
  */
Euler RotationMartix2Euler(const Eigen::Matrix3d &mat)
{
    // TODO need to check the order of the axis coincide with roll>pitch>heading/yaw
    return eulerAngles(mat);
}

/**
 * @brief  quaternion to euler by rotation matirx
 * @note   
 * @param  q: quaternion
 * @retval 
 */
Euler Quaternion2Euler(const Eigen::Quaterniond &q)
{
    return RotationMartix2Euler(q.toRotationMatrix());
}

/**
 * @brief  according the rotation vector construct the Quaternion
 * @note   
 * @param  rv: Equivalent rotation vector 
 * @retval 
 */
Eigen::Quaterniond RotationVector2Quaternion(const RotationVector &rv)
{
    Eigen::Quaterniond qfromrv;
    RotationVector rv_2 = rv * 0.5;
    double norm = rv_2.norm();
    qfromrv.w() = cos(norm);
    qfromrv.vec() = norm < 1e-5 ? rv_2 : (sin(norm) / norm) * rv_2;
    return qfromrv;
}

/**
 * @brief  Rotation Vector to Rotation Matrix
 * @note   
 * @param  &rv: Equivalent rotation vector 
 * @retval 
 */
Eigen::Matrix3d RotationVector2RotationMatrix(const RotationVector &rv)
{
    return Quaternion2RotationMatrix(RotationVector2Quaternion(rv));
}
} // namespace attitude
} // namespace utiltool

#endif /* !NAVATTITUDE */