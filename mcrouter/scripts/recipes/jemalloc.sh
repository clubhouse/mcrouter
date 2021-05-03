#!/usr/bin/env bash
# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

source common.sh

if [ ! -d "$PKG_DIR/jemalloc" ]; then
  git clone https://github.com/jemalloc/jemalloc
fi

cd "$PKG_DIR/jemalloc" || die "cd failed"

# Use a known compatible version
gitEnsureTreeish 5.2.1

./autogen.sh --prefix="$INSTALL_DIR"
make -j "$(nproc)" && make install
