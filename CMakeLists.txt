cmake_minimum_required(VERSION 3.21)
project(C__Primer_COPY)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__Primer_COPY main.cpp)

add_executable(copyNoMove 13/copyNoMove.cpp)
add_executable(Folder 13/Folder.cpp 13/Folder.h 13/FolderMain.cpp)
add_executable(HasPtrValueLike 13/HasPtrValueLike.cpp)
add_executable(HasPtrUseCount 13/HasPtrUseCount.cpp)
add_executable(moveHP 13/moveHP.cpp)
add_executable(serial 13/serial.cpp)
add_executable(StrFolder 13/StrFolder.h 13/StrFolder.cpp 13/String.h 13/String.cpp)
add_executable(StrVec 13/StrVec.h 13/StrVec.cpp)
add_executable(absInt 14/absInt.cpp)
add_executable(add 14/add.cpp 14/Sales_data.h 14/Sales_data.cpp)
add_executable(calc 14/calc.cpp)
add_executable(directcall 14/directcall.cpp)
add_executable(fcnobj 14/fcnobj.cpp)
add_executable(newcount-size 14/newcount-size.cpp)
add_executable(readStr 14/readStr.cpp)

add_executable(and_orQueryTest 15/and_orQueryTest.cpp)
