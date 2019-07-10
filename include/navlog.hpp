/*
** navlog.h for MSCNAV in /media/fwt/学习/程序/myprogram/01-MSCNAV/include
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Mon Dec 17 下午3:13:11 2018 little fang
** Last update Thu Jul 10 上午10:04:13 2019 little fang
*/

#ifndef NAVLOG_H_
#define NAVLOG_H_
#include <string>
#define GLOGOUTPUT

#ifdef GLOGOUTPUT
#include <glog/logging.h>
#endif // GLOGOUTPUT

namespace utiltool
{
  
inline void navloginit(const char *argv, const std::string &path)
{
#ifdef GLOGOUTPUT
  google::InitGoogleLogging((const char *)argv);
  google::SetLogDestination(google::GLOG_INFO, path.c_str());
#endif
}

#ifdef GLOGOUTPUT
#define navinfolog(format, ...)                                                                                                            \
  {                                                                                                                                        \
    char log[4096] = {0};                                                                                                                  \
    sprintf(log, format, ##__VA_ARGS__);                                                                                                   \
    LOG(INFO) << log << std::endl;                                                                                                         \
  }

#define navwarnlog(format, ...)                                                                                                         \
  {                                                                                                                                        \
    char log[4096] = {0};                                                                                                                  \
    sprintf(log, format, ##__VA_ARGS__);                                                                                                   \
    LOG(WARNING) << log << std::endl;                                                                                                      \
  }

#define naverrorlog(format, ...)                                                                                                           \
  {                                                                                                                                        \
    char log[4096] = {0};                                                                                                                  \
    sprintf(log, format, ##__VA_ARGS__);                                                                                                   \
    LOG(ERROR) << log << std::endl;                                                                                                        \
  }

#define navfatallog(format, ...)                                                                                                           \
  {                                                                                                                                        \
    char log[4096] = {0};                                                                                                                  \
    sprintf(log, format, ##__VA_ARGS__);                                                                                                   \
    LOG(FATAL) << log << std::endl;                                                                                                        \
  }
#else
#define navinfolog(format, ...)
#define navwarnlog(format, ...)
#define naverrorlog(format, ...)
#define navfatallog(format, ...)
#endif

} // namespace untiltool


#endif /* !NAVLOG_H_ */
