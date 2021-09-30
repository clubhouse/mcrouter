#!/usr/bin/env bash
# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

source common.sh

if [ ! -d "$PKG_DIR/fbthrift" ]; then
  git clone https://github.com/facebook/fbthrift
fi

cd "$PKG_DIR/fbthrift" || die "cd fail"

# Use a known compatible version
# v2020.08.24.00
#   Published stable release - CMake linking errors
# v2021.09.27.00
#   This needs to be linked closely to Folly and this version works well with extra linking fix in mcrouter
gitEnsureTreeish v2021.09.27.00

cd "$PKG_DIR/fbthrift/build" || die "cd fbthrift failed"

CXXFLAGS="$CXXFLAGS -fPIC" \
LDFLAGS="-Wl,-rpath=$INSTALL_DIR/lib $LDFLAGS" \
cmake .. -DCMAKE_INSTALL_PREFIX="$INSTALL_DIR"
make -j "$(nproc)" && make install
