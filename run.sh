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
  build_dir="build"
  # create build directory if not already exist
  if [[ ! -d $build_dir ]]; then
    mkdir $project_root/$build_dir
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

function build-dbg {
  build_dir="debug"
  if [[ ! -d $build_dir ]]; then
    mkdir $project_root/$build_dir
  fi
  local current_dir=$(basename `pwd`)
  if [[ current_dir != $build_dir ]]; then
    cd $build_dir
  fi
  cmake -DCMAKE_BUILD_TYPE=Debug ..
  # -DCMAKE_BUILD_TYPE=RelWithDebInfo
  make
  cd $project_root
}

function run {
  printf "running ${build_dir}\n"
  printf "command: echo \"colorful\" | clrprint %s\n\n" "$*"
  # go to where the binary is
  cd $project_root
  echo "colorful" | ./${build_dir}/src/${project_name} $*
}

function debug {
  build_dir="debug"
  # using arguments
  if [[ ! -d $build_dir ]]; then
    read -p "the debug build is not created, build it now [Y/n]:" choice
    case $choice in
      [yY]* ) build-dbg
        ;;
      [nN]* ) echo "error: no target"
        return 1
        ;;
      *) build-dbg
        ;;
    esac
  fi
  gdb --args $project_root/$build_dir/src/$project_name $*

  # gdb --args $project_name $*
}

echo "test script updated, ready to run :]"

## uncomment/change the following lines the do some tests
# build
