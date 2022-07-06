#ifndef  __SYLAR_LOG_H__
#define  __SYLAR_LOG_H__
#include <string>
#include <stdint.h>
#include <memory>
#include <list>
//logger

namespace sylar {

//log destination
class LogEvent{
public:
    typedef std::shared_ptr<LogEvent> ptr;  
    LogEvent();
    void log();

private:
    const char* m_file = nullptr;
    int32_t m_line =  0;
    uint32_t m_threadId =0;
    uint32_t m_elapse =0;           //程序已经执行的时间
    uint32_t m_fiberId = 0;         //协程ID
    uint64_t m_time;                //时间戳
    std::string m_content;

};

class LogLevel{
public:
       enum Level{
        DEBUG	= 1,
        INFO	= 2,
        WARNING	= 3,
        ERROR	= 4,
        FATAL	= 5
    };
private:

};
class LogFormatter{
public:
    typedef std::shared_ptr<LogFormatter> ptr;
    std::string format(LogEvent::ptr event);

private:

};

class LogAppender{
public:
    typedef std::shared_ptr<LogAppender> ptr;
    virtual ~LogAppender(){};
    void log(LogLevel::Level level ,LogEvent::ptr event);

private:
    LogLevel::Level m_level;

};

class Logger{
public:
    typedef std::shared_ptr<Logger> ptr; 
 
    Logger(const std::string& name = "root ");
    void log(LogLevel::Level level, LogEvent::ptr event);
    
    void debug(LogEvent::ptr event);
    void info(LogEvent::ptr event);
    void warn(LogEvent::ptr event);
    void error(LogEvent::ptr event);
    void fatal(LogEvent::ptr event);
    
    void addAppender(LogAppender::ptr appender);
    void delAppender(LogAppender::ptr appender); 
    LogLevel::Level getLevel()const {return m_level;}
    void setLevel(LogLevel::Level val){m_level = val;}
private: 
    std::string m_name;
    LogLevel::Level m_level;
    std::list<LogAppender::ptr> m_appenders;
};

class StdoutLogAppender : public LogAppender {

};
class FileLogAppender: public LogAppender{

};

}

#endif
