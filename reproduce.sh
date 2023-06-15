#!/usr/bin/env sh

rm -rf build
meson setup -Db_sanitize=address build
meson compile -C build
meson test -v -C build
