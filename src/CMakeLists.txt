aux_source_directory(. SRC_LISTA)
aux_source_directory(util SRC_LISTB)

include_directories(.)
include_directories(util)
include_directories(ansi_c)

include_directories(${CMAKE_CURRENT_BINARY_DIR})



add_custom_command(
  OUTPUT
  	${CMAKE_CURRENT_BINARY_DIR}/ansi_c_parser.h
  COMMAND
    obison -i ${CMAKE_CURRENT_SOURCE_DIR}/ansi_c/ansi_c.yy -p ${CMAKE_CURRENT_BINARY_DIR}/ansi_c_parser.h -e ${CMAKE_CURRENT_BINARY_DIR}/ansi_c_header.h -c ansi_c_parser -n ansi_c_header

  WORKING_DIRECTORY
  	${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS
  	${CMAKE_CURRENT_SOURCE_DIR}/ansi_c/ansi_c.yy
  COMMENT
  	"yy->parser"
  )
  
add_custom_command(
  OUTPUT
  	${CMAKE_CURRENT_BINARY_DIR}/ansi_c_lex_header.h
  COMMAND
    oflex -i ${CMAKE_CURRENT_SOURCE_DIR}/ansi_c/ansi_c.l  -o ${CMAKE_CURRENT_BINARY_DIR}/ansi_c_lex_header.h -t ${CMAKE_CURRENT_BINARY_DIR}/ansi_c_otoken.h -p ansi_c_lex -k ansi_c_token
  WORKING_DIRECTORY
  	${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS
  	${CMAKE_CURRENT_SOURCE_DIR}/ansi_c/ansi_c.l
  COMMENT
  	".l->lex"
  )
  
add_executable(ocpm ${SRC_LISTA} ${SRC_LISTB} ${SRC_LISTC} ${CMAKE_CURRENT_BINARY_DIR}/ansi_c_parser.h ${CMAKE_CURRENT_BINARY_DIR}/ansi_c_lex_header.h)
