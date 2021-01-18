#!/bin/bash

cd ../library/
if c++ -fPIC -c labfunks.cpp; then
  echo library compiled
else
  echo library not compiled
  exit 1
fi

if c++ -shared -o liblabTenDyn.so labfunks.o; then
  echo dynamic library created
else
  echo fail to create library
  exit 1
fi
rm *.o

cd ../dynamic_implicit/
if c++ -c main.cpp proj.cpp; then
  echo main program compiled
else
  echo fail to compile main
  exit 1
fi

if c++ main.o proj.o -o start -L../library/ -llabTenDyn -ldl; then
  echo main was built
else
  echo fail to build main
  exit 1
fi

#LD_LIBRARY_PATH=/home/zumori/documents/pgr/univer/os/OS_lab10/library:${LD_LIBRARY_PATH}
#export LD_LIBRARY_PATH

rm *.o #clear extra files
