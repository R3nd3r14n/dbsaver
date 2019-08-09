#!/bin/bash

INPUT='dbsaver.cpp'
OUTPUT='dbsaver'
CC_FLAGS='-g -lsqlite3 -lpthread -I. -I./include -std=c++11'
#CC='g++'
CC='clang++'

rm -f $OUTPUT

$CC $CC_FLAGS -o $OUTPUT $INPUT
