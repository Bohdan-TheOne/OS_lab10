#/bin/bash

cd ../library/
if c++ -c labfunks.cpp; then
  echo library compiled
else
  echo library not compiled
  return
fi

if ar rc liblabTen.a labfunks.o; then
  echo static library created
else
  echo fail to create library
  return
fi

ranlib liblabTen.a
ar -t liblabTen.a

cd ../static/
if c++ -c main.cpp proj.cpp; then
  echo main program compiled
else
  echo fail to compile main
  return
fi

if c++ main.o proj.cpp -lpthread -lrt -L../library/ -llabTen -o start; then
  echo main was built
else
  echo fail to build main
fi

rm *.o #clear extra files


