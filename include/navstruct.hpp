/*
** navstruct.h for tools in /home/fwt/program/myprogram/wsl_program/mscnav/submodules/tools/include
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Wed Jul 3 14:38:27 2019 little fang
** Last update Wed Jul 9 18:53:02 2019 little fang
*/

#ifndef NAVSTRUCT_H_
#define NAVSTRUCT_H_
#include "stdio.h"
#include <chrono>
#include <memory>
#include <string>
#include <thread>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <Eigen/Dense>

#include "navtime.h"

namespace utiltool
{

inline void navsleep(int _milliseconds)
{
  std::chrono::milliseconds msecond(_milliseconds);
  std::this_thread::sleep_for(msecond);
}

inline void navexit(const std::string &info = "Exitting...")
{
  std::cout << info << std::endl;
  navsleep(1000);
  exit(0);
}

enum DataType
{
  DATAUNKOWN = -1,
  IMUDATA,
  GNSSDATA,
  ODODATA,
  FEATUREDATA
};

enum GnssType
{
  GNSSUNKOWN = -1,
  GNSSSPP,
  GNSSPPP, 
  GNSSFIXED,
  GNSSRTD
};

class BaseData
{
public:
  BaseData(const NavTime &time) : t0_(time){}
  virtual ~BaseData(){}

public:
  using Ptr = std::shared_ptr<BaseData>;
  NavTime get_time() const { return t0_; }
  DataType get_type() const { return data_type_; }
  virtual std::string to_string();

private:
  DataType data_type_ = DATAUNKOWN;
  NavTime t0_;
  NavTime t1_; //bak receive time
};

class GnssData: public BaseData
{
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  
public:
  GnssData() {}
  ~GnssData(){}
  virtual std::string to_string()
  {}

public:
  Eigen::Vector3d pos_{0,0,0};
  Eigen::Vector3d vel_{0,0,0};
  Eigen::Vector3d pos_std_{0,0,0};
  Eigen::Vector3d vel_std_{0,0,0};
  GnssType gnss_type_ = GNSSUNKOWN;
};
} // namespace utiltool

#endif /* !NAVSTRUCT_H_ */
