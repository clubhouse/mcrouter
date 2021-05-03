#!/usr/bin/env bash
# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

source common.sh

if [ ! -d "$PKG_DIR/glog" ]; then
    git clone https://github.com/google/glog.git
fi

cd "$PKG_DIR/glog" || die "cd fail"

# Use a known compatible version
# N.B. More recent versions (v0.5.0.rcx) failed to work with mcrouter.
gitEnsureTreeish v0.4.0

autoreconf --install
LDFLAGS="-Wl,-rpath=$INSTALL_DIR/lib,--enable-new-dtags $LDFLAGS" \
    CPPFLAGS="-I$INSTALL_DIR/include -DGOOGLE_GLOG_DLL_DECL='' $CPPFLAGS" \
    ./configure --prefix="$INSTALL_DIR" &&
    make -j "$(nproc)" && make install
