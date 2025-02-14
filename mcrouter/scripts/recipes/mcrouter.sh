#!/usr/bin/env bash
# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

source common.sh

cd "$SCRIPT_DIR/../.." || die "cd fail"

autoreconf --install
LD_LIBRARY_PATH="$INSTALL_DIR/lib:$LD_LIBRARY_PATH" \
    LD_RUN_PATH="$INSTALL_DIR/lib:$LD_RUN_PATH" \
    CPPFLAGS="-I$INSTALL_DIR/include $CPPFLAGS" \
    FBTHRIFT_BIN="$INSTALL_DIR/bin/" \
    ./configure --prefix="$INSTALL_DIR" --with-boost-libdir="$INSTALL_DIR/lib"

make -j "$(nproc)" && make install
