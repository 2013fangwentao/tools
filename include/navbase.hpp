/*
** navbase.hpp for mscnav in /home/fwt/myprogram/mscnav/submodules/tools/include
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Thu Jul 11 上午9:11:49 2019 little fang
** Last update Thu Jul 11 上午9:11:49 2019 little fang
*/

#ifndef UTIL_BASE_H_
#define UTIL_BASE_H_
#include <string>
#include <regex>
#include <vector>
#include <exception>
#include <iostream>
#include <Eigen/Dense>

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

/**
  * @brief  override the ostream output vector<T>
  * @note   
  * @param  &output: 
  * @param  &data: output data vector<T>
  * @retval 
  */
template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &data)
{
    for (auto index : data)
    {
        output << index << "\t";
    }
    return output;
}

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

} // namespace utiltool

#endif /* !UTIL_BASE_H_ */
