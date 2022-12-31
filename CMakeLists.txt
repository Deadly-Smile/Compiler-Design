cmake_minimum_required(VERSION 3.22)
project(Compiler_Design)

set(CMAKE_CXX_STANDARD 20)

add_executable(Compiler_Design PreprocessingHandler.cpp PreprocessingHandler.h Utility.cpp Utility.h main.cpp Tokenizer.cpp Tokenizer.h Token.cpp Token.h Types.h ParseTree.cpp ParseTree.h)
