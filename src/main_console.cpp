#include "ansi_c_header.h"
#include "ansi_c_otoken.h"
#include "ansi_c_lex_header.h"
#include "ansi_c_parser.h"


int main_test(int argc, char*argv[])
{
    ansi_c_lex *m_lex =  new ansi_c_lex();
    m_lex->set_file_name("../test.c");
    auto tk = m_lex->yylex();
    while(tk.m_ret!=EOF_20220422_EOF)
    {
        std::cout<< "get tk:"<< tk.m_yytext<<"\n";
        tk = m_lex->yylex();
    }

    return 0;
}

int main(int argc, char *argv[])
{
    ansi_c_parser<ansi_c_lex> *m_parser = new ansi_c_parser<ansi_c_lex>();

    m_parser->set_file_name("./test.c");
    m_parser->m_debug = 1;
    auto p_tree = m_parser->yyparse();

    m_parser->print_token_tree(p_tree);



    m_parser->process_top_down(p_tree);

    delete m_parser;
    
	return 0;
}
