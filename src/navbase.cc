
#include "navbase.hpp"

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
 * @brief  override the ostream output ImuData
 * @note   
 * @param  &output: 
 * @param  &imu_data: 
 * @retval 
 */
std::ostream &operator<<(std::ostream &output, const ImuData &imu_data)
{
    output << imu_data.get_time() << "\t";
    output << imu_data.gyro_.transpose() << "\t";
    output << imu_data.acce_.transpose() << "\t";
    return output;
}
/**
 * @brief  override the ostream output ImuData::Ptr
 * @note   
 * @param  &output: 
 * @param  &imu_data: 
 * @retval 
 */
std::ostream &operator<<(std::ostream &output, const ImuData::Ptr &imu_data)
{
    output << imu_data->get_time() << "\t";
    output << imu_data->gyro_.transpose() << "\t";
    output << imu_data->acce_.transpose() << "\t";
    return output;
}
/**
 * @brief  override the ostream output GnssData
 * @note   
 * @param  &output: 
 * @param  &imu_data: 
 * @retval 
 */
std::ostream &operator<<(std::ostream &output, const GnssData &gnss_data)
{
    output << gnss_data.get_time() << "\t";
    output << gnss_data.pos_.transpose() << "\t";
    output << gnss_data.vel_.transpose() << "\t";
    output << gnss_data.pos_std_.transpose() << "\t";
    output << gnss_data.vel_std_.transpose() << "\t";
    output << gnss_data.get_type();
    return output;
}

/**
 * @brief  override the ostream output GnssData::Ptr
 * @note   
 * @param  &output: 
 * @param  &imu_data: 
 * @retval 
 */
std::ostream &operator<<(std::ostream &output, const GnssData::Ptr &gnss_data)
{
    output << *gnss_data;
    return output;
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
