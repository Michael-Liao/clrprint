#!/bin/bash

### usage notice ###
# there are 2 ways of doing it
#1.- source this script before running the tests
# source run.sh
# build
#2.- add the desired test at the bottom
###
# default variables
project_root="/home/michael/Documents/CPP/clrprint"
build_dir="build"
project_name=$(basename $project_root)
# make sure we are at project root
cd $project_root

function build {
  # create build directory if not already exist
  if [[ ! -d ${build_dir} ]]; then
    mkdir ${project_root}/${build_dir}
  fi
  # go to build directory if not already there
  local current_dir=$(basename `pwd`)
  if [[ current_dir != $build_dir ]]; then
    cd $build_dir
  fi
  cmake ..
  make
  # back to project root
  cd $project_root
}

function run {
  # go to where the binary is
  cd ${project_root}/${build_dir}/src
  ./$project_name $1
  cd $project_root
}

# function debug {
#   # use gdb to debug
# }

echo "test script updated, ready to run :]"

## uncomment/change the following lines the do some tests
# build
