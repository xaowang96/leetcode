#ifndef __LOG_H__
#define __LOG_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************串口颜色输出****************************************************/
#ifndef NONE
#define NONE                 "\033[0m"		   //关闭所有属性 恢复默认值。
#endif
#ifndef BLACK
#define BLACK                "\033[0;30m"     //字体黑色
#endif
#ifndef L_BLACK
#define L_BLACK              "\033[1;30m"     //高亮黑
#endif
#ifndef RED
#define RED                  "\033[0;31m"     //字体红色
#endif
#ifndef L_RED
#define L_RED                "\033[1;31m"     //高亮红
#endif
#ifndef GREEN
#define GREEN                "\033[0;32m"     //字体绿色
#endif 
#ifndef L_GREEN
#define L_GREEN              "\033[1;32m"     //高亮绿
#endif
#ifndef YELLOW
#define YELLOW               "\033[0;33m"     //字体黄色
#endif 
#ifndef L_YELLOW
#define L_YELLOW             "\033[1;33m"     //高亮黄
#endif
#ifndef BLUE
#define BLUE                 "\033[0;34m"     //字体蓝色
#endif
#ifndef L_BLUE
#define L_BLUE               "\033[1;34m"     //高亮蓝
#endif
#ifndef PURPLE
#define PURPLE               "\033[0;35m"     //字体紫色
#endif
#ifndef L_PURPLE
#define L_PURPLE             "\033[1;35m"     //高亮紫
#endif
#ifndef CYAN
#define CYAN                 "\033[0;36m"     //字体青色
#endif
#ifndef L_CYAN
#define L_CYAN               "\033[1;36m"     //高亮青
#endif
#ifndef GRAY
#define GRAY                 "\033[0;37m"     //字体灰色
#endif
#ifndef WHITE
#define WHITE                "\033[1;37m"     //字体白色
#endif
#ifndef BOLD
#define BOLD                 "\033[1m"        //字体加粗
#endif
#ifndef UNDERLINE
#define UNDERLINE            "\033[4m"        //字体下划线
#endif
#ifndef BLINK
#define BLINK                "\033[5m"        //字体闪烁
#endif
#ifndef CLEAR
#define CLEAR                "\033[2J"        //清屏
#endif


#define FONT_COLOR_DEFAULT		    0
#define FONT_COLOR_BLACK            30
#define FONT_COLOR_RED		        31
#define FONT_COLOR_GREEN		    32
#define FONT_COLOR_YELLOW	        33
#define FONT_COLOR_BLUE 	        34
#define FONT_COLOR_PURPLE	        35
#define FONT_COLOR_DARK_GREEN	    36
#define FONT_COLOR_WHITE            37

#define FONT_BACK_COLOR_DEFAULT		0
#define FONT_BACK_COLOR_BLACK       40
#define FONT_BACK_COLOR_RED		    41
#define FONT_BACK_COLOR_GREEN		42
#define FONT_BACK_COLOR_YELLOW	    43
#define FONT_BACK_COLOR_BLUE 	    44
#define FONT_BACK_COLOR_PURPLE	    45
#define FONT_BACK_COLOR_DARK_GREEN	46
#define FONT_BACK_COLOR_WHITE       47


#define ___MACRO2STR_(n)    #n
#define __MACRO2STR(n) ___MACRO2STR_(n)

/*
#define _LOG_COMMON(color, fmt, args...)  do {                    \
        fprintf(stderr, "[" __FILE__ ":" __MACRO2STR(__LINE__) "]"  \
                        "\e[0;%dm%s(): "   \
                        fmt "\e[0m\n",              \
                        (int)color, __FUNCTION__);                      \
    } while (0)
*/

#define _LOG_COMMON(color, fmt, args...)  do {                    \
        fprintf(stderr, "[" __FILE__ ":" __MACRO2STR(__LINE__) "]"  \
                        "\e[0;" __MACRO2STR(color) "m%s\e[0m(): "   \
                        fmt  " \e[0m\n",              \
                        __func__, ##args);                          \
    } while (0)

#define LOG_INFO(format, args...)   _LOG_COMMON(FONT_COLOR_GREEN, format, ##args)
#define LOG_WARN(format, args...)   _LOG_COMMON(FONT_COLOR_YELLOW, format, ##args)
#define LOG_ERROR(format, args...)  _LOG_COMMON(FONT_COLOR_RED, format, ##args)       



#define LOG_PthreadExit(fmt, args...)       fprintf(stderr,L_GREEN "%s [%d] exit >>> " NONE fmt "\n",__FUNCTION__,__LINE__);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
