CC=i686-w64-mingw32.static-gcc CXX=i686-w64-mingw32.static-g++ TARGET_OS=OS_WINDOWS_CROSSCOMPILE make OPT="-pipe -fno-keep-inline-dllexport -D_FORTIFY_SOURCE=2 -O2" libleveldb.a libmemenv.a
i686-w64-mingw32.static-ranlib ./libleveldb.a
i686-w64-mingw32.static-ranlib ./libmemenv.a
