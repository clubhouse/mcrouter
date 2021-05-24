#!/usr/bin/env bash

# This creates an archive suitable for distribution to other hosts with the same system.

set -euo pipefail

INSTALL_DIR="$1"
ARCHIVE="$2"

function die() {
    printf "%s: %s\n" "$0" "$@"
    exit 1
}

[ -n "$1" ] || die "INSTALL_DIR missing"
[ -n "$2" ] || die "ARCHIVE missing"

ARCHIVE_INSTALL_DIR=$(mktemp -d)
mkdir "${ARCHIVE_INSTALL_DIR}"/lib
mkdir "${ARCHIVE_INSTALL_DIR}"/bin

# This expression uses "ldd" to locate all dynamically linked library dependencies.
# We then copy them to a tempdir so we can simply create an archive of only the needed dependencies.
# This will suck in libraries both from the "compiled from source" libraries (e.g. folly, thrift) as libraries
# from the host system.

LD_LIBRARY_PATH="${INSTALL_DIR}"/lib ldd "${INSTALL_DIR}"/bin/mcrouter "${INSTALL_DIR}"/bin/mcpiper \
    | grep "=>" | tr -s "[:blank:]" " " | cut -d " " -f 4 | sort -u \
    | xargs -I '%' cp '%' "${ARCHIVE_INSTALL_DIR}"/lib
cp "${INSTALL_DIR}"/bin/mcrouter "${INSTALL_DIR}"/bin/mcpiper "${ARCHIVE_INSTALL_DIR}"/bin/

tar czfv "${ARCHIVE}" -C "${ARCHIVE_INSTALL_DIR}" bin lib
