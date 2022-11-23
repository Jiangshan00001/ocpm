#ifndef CODE_WIN64_H
#define CODE_WIN64_H

#include <string>

class code_win64
{
public:
    code_win64();


public:


    /**
     * @brief header
     * 所有的代码之前的头信息
     */
    std::string header();

    /**
     * @brief trailer 所有代码结束内容
     */
    std::string trailer();

    /**
     * @brief gen_comment 添加注释前缀，便于后面写注释内容
     */
    std::string gen_comment();

    /**
     * @brief code_segment_gtext 代码段开始
     */
    std::string code_segment_gtext();
    /**
     * @brief data_segment_gdata 数据段开始
     */
    std::string data_segment_gdata();

    std::string bss_segment_data();

    /**
     * @brief gen_push 将primary register内容放入stack
     * @param reg
     */
    std::string gen_push(int reg);
    /**
     * @brief gen_pop 堆栈内容pop到secondary register
     */
    std::string gen_pop(int reg);

    /**
     * @brief gen_call 生成函数调用
     * @param sname
     */
    std::string gen_call(char *sname) ;
    /**
     * @brief declare_entry_point 声明入口点
     * @param symbol_name
     */
    std::string declare_entry_point(char *symbol_name);
    /**
     * @brief gen_ret 函数返回
     */
    std::string  gen_ret();


    /**
     * @brief put_immediate 将立即数放入primary register
     * @param i
     * @return
     */
    std::string put_immediate(long i);







};

#endif // CODE_WIN64_H


