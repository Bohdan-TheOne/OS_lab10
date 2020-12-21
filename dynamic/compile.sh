#!/bin/bash

cd ../library/
if c++ -fPIC -c labfunks.cpp; then
  echo library compiled
else
  echo library not compiled
  return
fi

if c++ -shared -o liblabTenDyn.so labfunks.o; then
  echo dynamic library created
else
  echo fail to create library
  return
fi
rm *.o

cd ../dynamic/
if c++ -c main.cpp proj.cpp; then
  echo main program compiled
else
  echo fail to compile main
  return
fi

if c++ main.o proj.o -o start -L../library/ -llabTenDyn -ldl; then
  echo main was built
else
  echo fail to build main
fi

rm *.o #clear extra files

