/*
** navbase.hpp for mscnav in /home/fwt/myprogram/mscnav/submodules/tools/include
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Thu Jul 11 上午9:11:49 2019 little fang
** Last update Thu Jul 17 下午5:57:33 2019 little fang
*/

#ifndef UTIL_BASE_H_
#define UTIL_BASE_H_
#include <string>
#include <regex>
#include <vector>
#include <exception>
#include <iostream>
#include <Eigen/Dense>

#include "navstruct.hpp"
#include "constant.hpp"

namespace utiltool
{
/**
 * @brief  spilt string 
 * @note   
 * @param  &in: string in which need split
 * @param  &delim: spliter mark
 * @retval 
 */
std::vector<std::string> TextSplit(const std::string &in, const std::string &delim)
{
    std::vector<std::string> ret;
    try
    {
        std::regex re{delim};
        return std::vector<std::string>{std::sregex_token_iterator(in.begin(), in.end(), re, -1), std::sregex_token_iterator()};
    }
    catch (const std::exception &e)
    {
        std::cout << "error:" << e.what() << std::endl;
    }
    return ret;
}

std::string &trim(std::string &s)
{
    if (s.empty())
    {
        return s;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

/**
  * @brief  override the ostream output vector<T>
  * @note   
  * @param  &output: 
  * @param  &data: output data vector<T>
  * @retval 
  */
template <typename T>
std::ostream &
operator<<(std::ostream &output, const std::vector<T> &data)
{
    for (auto index : data)
    {
        output << index << "\t";
    }
    return output;
}

std::ostream &operator<<(std::ostream &output, const NavTime &time)
{
    output << time.Time2String() << " " << time.Time2String("%d %10.3f", NavTime::GPSTIME) << "\t";
    return output;
}
/**
 * @brief  override the ostream output NavResultInfo
 * @note   
 * @param  &output: ostream& 
 * @param  nav_res_info: 
 * @retval 
 */
std::ostream &operator<<(std::ostream &output, const NavInfo &nav_info)
{
    output << nav_info.time_ << "\t";
    output << nav_info.pos_.transpose() << "\t";
    output << nav_info.vel_.transpose() << "\t";
    output << nav_info.att_.transpose() * constant::rad2deg << "\t";
    output << nav_info.pos_std_.transpose() << "\t";
    output << nav_info.vel_std_.transpose() << "\t";
    output << nav_info.att_std_.transpose() << "\t";
    output << nav_info.gyro_bias_.transpose() << "\t";
    output << nav_info.acce_bias_.transpose() << "\t";
    output << nav_info.gyro_scale_.transpose() << "\t";
    output << nav_info.acce_scale_.transpose();
    return output;
}

/**
  * @brief  calculate the euler from Rotation Matrix 
  * @note   reference the Eigen::Matrix::eulerAngles 
  * @note   roll [-pi/2~pi/2], pitch[-pi/2~pi/2], heading/yaw[-pi~pi]
  * @param  Eigen::Matrix<Derived:  the vector of euler by order roll -> pitch -> heading/yaw
  * @param  &coeff: Rotation Matrix
  * @retval 
  */
template <typename Derived>
inline Eigen::Matrix<Derived, 3, 1> eulerAngles(const Eigen::Matrix<Derived, 3, 3> &coeff)
{
    Eigen::Matrix<Derived, 3, 1> res;

    const size_t i = 2;
    const size_t j = 1;
    const size_t k = 0;
    typedef Eigen::Matrix<Derived, 2, 1> Vector2;

    res[2] = atan2(coeff(j, k), coeff(k, k));
    Derived c2 = Vector2(coeff(i, i), coeff(i, j)).norm();
    // if (res[2] < Derived(0))
    // {
    //     res[2] += Derived(EIGEN_PI) * 2;
    // }
    res[1] = atan2(-coeff(i, k), c2);
    Derived s1 = sin(res[2]);
    Derived c1 = cos(res[2]);
    res[0] = atan2(s1 * coeff(k, i) - c1 * coeff(j, i), c1 * coeff(j, j) - s1 * coeff(k, j));

    return res;
}
/**
 * @brief  skew matrix from vector
 * @note   
 * @param  vector: 
 * @retval 
 */
Eigen::Matrix3d skew(const Eigen::Vector3d &vector)
{
    Eigen::Matrix3d dcm1;
    dcm1(0, 0) = 0;
    dcm1(0, 1) = -vector(2);
    dcm1(0, 2) = vector(1);

    dcm1(1, 0) = vector(2);
    dcm1(1, 1) = 0;
    dcm1(1, 2) = -vector(0);

    dcm1(2, 0) = -vector(1);
    dcm1(2, 1) = vector(0);
    dcm1(2, 2) = 0;

    return dcm1;
}

} // namespace utiltool

#endif /* !UTIL_BASE_H_ */
