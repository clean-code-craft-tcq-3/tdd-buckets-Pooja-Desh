#!/bin/bash
set -e

if grep -q xxx *.md; then
  echo "Replace all the _enter with your input"
  exit 1
fi
