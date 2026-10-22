#!/usr/bin/env bash
# Compiles the original U-Card source to WebAssembly for the browser demo.
# Requires the Emscripten SDK (emcc) on PATH. Output goes to ./dist by default.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="${1:-$ROOT/dist}"

mkdir -p "$OUT"

# -fno-strict-return:            some helpers are declared int but never return a value.
# -ftrivial-auto-var-init=zero:  the score array is never initialised; make it start at 0.
emcc "$ROOT/cardgame/Card GAme/main.cpp" \
	-I "$ROOT/web/shim" \
	-O2 \
	-fno-strict-return \
	-ftrivial-auto-var-init=zero \
	-Wno-return-type \
	-sASYNCIFY \
	-sEXIT_RUNTIME=1 \
	-sENVIRONMENT=web \
	-o "$OUT/ucard.js"

cp "$ROOT/web/index.html" "$OUT/index.html"
cp "$ROOT/assets/logo.svg" "$OUT/logo.svg"

echo "Browser build written to $OUT"
