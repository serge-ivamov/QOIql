#!/usr/bin/env bash
rm -rf ~/Library/QuickLook/QOIql.qlgenerator
cp -a build/Release/QOIql.qlgenerator ~/Library/QuickLook/
codesign -fs - ~/Library/QuickLook/QOIql.qlgenerator/Contents/MacOS/QOIql
qlmanage -r
qlmanage -r cache
pkill -1 Finder
