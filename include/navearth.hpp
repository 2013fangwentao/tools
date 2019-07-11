/*
** navearth.hpp for mscnav in /home/fwt/myprogram/mscnav/submodules/tools/include
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Thu Jul 11 下午7:17:43 2019 little fang
** Last update Thu Jul 11 下午7:17:43 2019 little fang
*/

#ifndef UTIL_EARTH_H_
#define UTIL_EARTH_H_

#include "constant.hpp"
#include <Eigen/Dense>

namespace utiltool
{
namespace earth
{
using constant::constant_J2;
using constant::constant_J4;
using constant::constant_J6;
using constant::WGS84_A;
using constant::WGS84_AngleRate;
using constant::WGS84_GM;
using Eigen::Vector3d;

template <typename T>
inline T POW3(const T &t)
{
    return t * t * t;
}

Vector3d CalculateGravity(const Vector3d &pos, bool IsECEF = true)
{
    if (IsECEF)
    {
        /*--------------------------------------董绪荣, 张守信与华仲春, GPS/INS组合导航定位及其应用. 1998: 国防科技大学出版社.page 78-83--------------------------------*/
        double p = sqrt(pos(0) * pos(0) + pos(1) * pos(1) + pos(2) * pos(2));
        double t = pos(2) / p;
        double a_p = WGS84_A / p;
        double a1 = -WGS84_GM / p / p;
        double a2 = 1 + 1.5 * constant_J2 * a_p * a_p - (15.0 / 8) * constant_J4 * POW3(a_p) * a_p + (35.0 / 16) * constant_J6 * POW3(a_p) * POW3(a_p);
        double a3 = -4.5 * constant_J2 * a_p * a_p + (75.0 / 4) * constant_J4 * POW3(a_p) * a_p - (735.0 / 16) * constant_J6 * POW3(a_p) * POW3(a_p);
        double a4 = -(175.0 / 8) * constant_J4 * POW3(a_p) * a_p + (2205.0 / 16) * constant_J6 * POW3(a_p) * POW3(a_p);
        double a5 = -(1617.0 / 16) * constant_J6 * POW3(a_p) * POW3(a_p);

        double b1 = 3 * constant_J2 * a_p * a_p - (15.0 / 2) * constant_J4 * POW3(a_p) * a_p + (105.0 / 8) * constant_J6 * POW3(a_p) * POW3(a_p);
        double b2 = (35.0 / 2) * constant_J4 * POW3(a_p) * a_p - (945.0 / 12) * constant_J6 * POW3(a_p) * POW3(a_p);
        double b3 = (693.0 / 8) * constant_J6 * POW3(a_p) * POW3(a_p);

        double c1 = a2;
        double c2 = a3 - b1;
        double c3 = a4 - b2;
        double c4 = a5 - b3;
        double d1 = a2 + b1;
        double d2 = c2 + b2;
        double d3 = c3 + b3;
        double d4 = c4;
        Vector3d ge_vec;
        ge_vec(0) = (c1 + c2 * t * t + c3 * POW3(t) * t + c4 * POW3(t) * POW3(t)) * pos(0) * a1 / p + WGS84_AngleRate * WGS84_AngleRate * pos(0);
        ge_vec(1) = (c1 + c2 * t * t + c3 * POW3(t) * t + c4 * POW3(t) * POW3(t)) * pos(1) * a1 / p + WGS84_AngleRate * WGS84_AngleRate * pos(1);
        ge_vec(2) = (d1 + d2 * t * t + d3 * POW3(t) * t + d4 * POW3(t) * POW3(t)) * pos(2) * a1 / p;
        return ge_vec;
    }
    else
    {
        double gn = 9.7803267715 * (1 + 0.0052790414 * sin(pos(0)) * sin(pos(0)) + 0.0000232719 * POW3(sin(pos(0))) * sin(pos(0)));
        gn += (-0.0000030876910891 + 0.0000000043977311 * sin(pos(0)) * sin(pos(0))) * pos(2);
        gn += 0.0000000000007211 * pos(2) * pos(2);
        Vector3d gn_vec{0, 0, gn};
        return gn_vec;
    }
}

} // namespace earth
} // namespace utiltool

#endif /* !UTIL_EARTH_H_ */
