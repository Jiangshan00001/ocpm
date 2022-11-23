#include "ansi_c_header.h"
#include "ansi_c_otoken.h"
#include "ansi_c_lex_header.h"
#include "ansi_c_parser.h"
#include "code_win64.h"

#if 0
int main_testw64(int argc, char*argv[])
{
    code_win64 w64;
    //https://learn.microsoft.com/en-us/cpp/build/x64-software-conventions?source=recommendations&view=msvc-170

    std::ofstream f("out.asm");
    f<<w64.header()<<"\n";
    f<<w64.code_segment_gtext()<<"\n";
    f<<w64.declare_entry_point("main")<<"\n";
    f<<w64.gen_call("getchar")<<"\n";


    f<<w64.put_immediate(0)<<"\n";
    f<<w64.gen_push(0)<<"\n";
    f<<w64.gen_call("ExitProcess")<<"\n"<<"\n";
    f<<w64.data_segment_gdata()<<"\n";
    f<<"hello db 'Hello world!', 10, 0  \n";
    f<<w64.trailer()<<"\n";

    f.close();

    return 0;
}
#endif

int main(int argc, char *argv[])
{
    ansi_c_parser<ansi_c_lex> *m_parser = new ansi_c_parser<ansi_c_lex>();

    char * file_name="./test.c";
    if(argc>1)
    {
        file_name = argv[1];
    }
    printf("file_name: %s\n", file_name);
    m_parser->set_file_name(file_name);
    m_parser->m_debug = 1;
    auto p_tree = m_parser->yyparse();

    m_parser->print_token_tree(p_tree);



    m_parser->process_top_down(p_tree);

    delete m_parser;
    
	return 0;
}
