#!/bin/bash

PUSH_SWAP=./push_swap
CHECKER=./checker

# 👉 change this to 5 / 100 / 500 depending on what you want
N=500

# sanity checks
if [ ! -x "$PUSH_SWAP" ]; then
  echo "Error: $PUSH_SWAP not found or not executable"
  exit 1
fi

if [ ! -x "$CHECKER" ]; then
  echo "Error: $CHECKER not found or not executable"
  exit 1
fi

FAIL=0
MAX_MOVES=0
TOTAL_MOVES=0

for i in $(seq 1 500); do
  ARG=$(seq 1 $N | shuf)

  OPS=$($PUSH_SWAP $ARG)
  RESULT=$(echo "$OPS" | $CHECKER $ARG)

  if [ "$RESULT" != "OK" ]; then
    echo "❌ Test $i FAILED: $RESULT"
    echo "Input: $ARG"
    exit 1
  fi

  MOVES=$(printf "%s\n" "$OPS" | wc -l)
  [ "$MOVES" -gt "$MAX_MOVES" ] && MAX_MOVES=$MOVES
  TOTAL_MOVES=$((TOTAL_MOVES + MOVES))

  echo "✅ Test $i OK – moves: $MOVES"
done

AVG_MOVES=$((TOTAL_MOVES / 500))

echo "--------------------------------"
echo "All 500 tests OK ✅"
echo "Max moves: $MAX_MOVES"
echo "Avg moves: $AVG_MOVES"
