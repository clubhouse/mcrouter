# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

set -ex

function die { printf "%s: %s\n" "$0" "$@"; exit 1; }

# Ensures a git repository working tree is set to the specific commit
function gitEnsureTreeish {
    # In the case of a commit or tag, this will put the repo into DETACHED HEAD state
    git checkout "$1" --
    # Ensures that there are edited files in git index or working directory
    git reset --hard HEAD
    git clean -fdx .
}

[ -n "$1" ] || die "PKG_DIR missing"
[ -n "$2" ] || die "INSTALL_DIR missing"

PKG_DIR="$1"
INSTALL_DIR="$2"
INSTALL_AUX_DIR="$3"
shift $#

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
export SCRIPT_DIR

mkdir -p "$PKG_DIR" "$INSTALL_DIR"

if [ -n "$3" ]; then
	mkdir -p "$INSTALL_AUX_DIR"
fi

cd "$PKG_DIR" || die "cd fail"
