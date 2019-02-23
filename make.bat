@mkdir build
@cd build
@mkdir imports
@g++ -std=c++14 -I%CS_DEV_PATH%\include -I..\include -shared -static -fPIC -s -O3 ..\codec.cpp -L%CS_DEV_PATH%\lib -lcovscript -o .\imports\codec.cse