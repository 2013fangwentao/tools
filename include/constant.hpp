/*
** units.hpp for mscnav in /home/fwt/myprogram/mscnav/submodules/tools/include
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Wed Jul 10 下午9:46:55 2019 little fang
** Last update Thu Jul 10 下午9:53:31 2019 little fang
*/

#ifndef CONSTANT_H_
#define CONSTANT_H_
#include <cmath>

namespace constant
{

constexpr double WGS84_RE = 6378137.0;
constexpr double WGS84_F = (1.0 / 298.257223563);

// constexpr double constant_wie = 7.2921151467e-5;
// constexpr double constant_meru = constant_wie / 1000;
// constexpr double constant_g0 = 9.7803267714;
// constexpr double constant_mg = 1e-3 * constant_g0;
// constexpr double constant_ug = 1e-3 * constant_mg;
// constexpr double constant_mGal = 1e-3 * 0.01; // milli Gal = 1cm/s^2 ~= 1.0E-6*g0
// constexpr double constant_ugpg2 = constant_ug / constant_g0 / constant_g0;
// constexpr double constant_ppm = 1e-6;
// constexpr double constant_deg = M_PI / 180;        // arcdeg
// constexpr double constant_min = constant_deg / 60; // arcmin
// constexpr double constant_sec = constant_min / 60; // arcsec
// constexpr double constant_hur = 3600;
// constexpr double constant_dps = constant_deg / 1;                   // arcdeg / second
// constexpr double constant_dph = constant_deg / constant_hur;        // arcdeg / hour
// constexpr double constant_dpss = constant_deg / sqrt(1.0);          // arcdeg / sqrt(second)
// constexpr double constant_dpsh = constant_deg / sqrt(constant_hur); // arcdeg / sqrt(hour)
// constexpr double constant_dphpsh = constant_dph / sqrt(constant_hur);
// constexpr double constant_Hz = 1 / 1; // Hertz
// constexpr double constant_dphpsHz = constant_dph / constant_Hz;
// constexpr double constant_mgpsHz = constant_mg / sqrt(constant_Hz);
// constexpr double constant_ugpsHz = constant_ug / sqrt(constant_Hz);
// constexpr double constant_ugpsh = constant_ug / sqrt(constant_hur); // ug / sqrt(hour)
// constexpr double constant_mpsh = 1 / 1 / sqrt(constant_hur);
// constexpr double constant_ppmpsh = constant_ppm / sqrt(constant_hur);
// constexpr double constant_mil = 2 * M_PI / 6000;
// constexpr double constant_nm = 1853;                       // nautical mile
// constexpr double constant_kn = constant_nm / constant_hur; // 海里每小时
// // added
// constexpr double constant_mps = 1 / 1;
// constexpr double constant_km = 1000;
// constexpr double constant_kmph = constant_km / constant_hur;
// constexpr double constant_mpr = 1 / WGS84_RE;
// constexpr double constant_m = 1.0;
// constexpr double constant_cm = constant_m / 100; // cm

constexpr double operator"" _deg(long double x) { return x / 180 * M_PI; }

} // namespace constant

#endif /* !CONSTANT_H_ */
