#include "code_win64.h"
#include "number2str.h"

code_win64::code_win64()
{
}

std::string code_win64::header()
{
    std::string kk=R"AAA(
format PE64 console
include 'win64wx.inc' ;
entry main

)AAA";

    // you can simply switch between win32ax, win32wx, win64ax and win64wx here
    // a--ascii. w--wide char.
    return kk;
}

std::string code_win64::trailer()
{
    std::string kk=R"AAA(
section '.idata' data readable import
        library kernel32, 'kernel32.dll', msvcrt,   'msvcrt.dll'
        import kernel32, ExitProcess, 'ExitProcess'
        import msvcrt, printf, 'printf'  , getchar, 'getchar'
)AAA";

    return  kk;
}

std::string code_win64::gen_comment()
{
    return ";";
}

std::string code_win64::code_segment_gtext()
{
    return "section '.text' code readable executable\n";
}

std::string code_win64::data_segment_gdata()
{
    return "section '.data' data readable writeable";
}

std::string code_win64::bss_segment_data()
{
    return "section '.bss' readable writeable;";
}

std::string code_win64::gen_push(int reg)
{
    if(reg==0)
    {
        return "push rax;";
    }
    else
    {
        return "push rbx;";
    }

    return ";error unknown reg index\n";
}

std::string code_win64::gen_pop(int reg)
{
    if(reg==0)
    {
        return "pop rax;";
    }
    else
    {
        return "pop rbx;";
    }

    return ";error unknown reg index";
}

std::string code_win64::gen_call(char *sname)
{
    return std::string("call [")+ sname+ "]";
}

std::string code_win64::declare_entry_point(char *symbol_name)
{
    return std::string("")+symbol_name+":";
}

std::string code_win64::gen_ret()
{
    return "ret";
}

std::string code_win64::put_immediate(long i)
{
    return "mov rax, " + NumberToStrDec(i)+";";
}







