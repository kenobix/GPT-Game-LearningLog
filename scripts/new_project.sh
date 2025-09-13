#!/usr/bin/env bash
set -e
NN=$1; LV=$2; SLUG=$3; LANG=$4
DIR=$(printf "%02d-lv%s-%s_%s" "$NN" "$LV" "$SLUG" "$LANG")
mkdir -p "$DIR/src"
cp TEMPLATES/project-readme.md "$DIR/README.md"
echo "Created $DIR"
