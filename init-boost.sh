#!/usr/bin/env bash

BOOST_PREFIX="$PWD/libs/boost"

cd external/boost
git submodule update --depth 1 --init --recursive
./bootstrap.sh
./b2
./b2 install --prefix="$BOOST_PREFIX"

cd -
echo "Run 'source boost-env.sh' to set relevant environmenetal variables!"
