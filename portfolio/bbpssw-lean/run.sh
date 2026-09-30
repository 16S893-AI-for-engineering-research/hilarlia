#!/usr/bin/env bash
# Run from any directory: bash /path/to/bbpssw-lean/run.sh
set -euo pipefail
cd -- "$(dirname -- "${BASH_SOURCE[0]}")"
for program in git curl; do
  if ! command -v "$program" >/dev/null 2>&1; then
    echo "Please install $program, then run this script again." >&2
    exit 1
  fi
done
if ! command -v elan >/dev/null 2>&1 && [[ -x "$HOME/.elan/bin/elan" ]]; then
  export PATH="$HOME/.elan/bin:$PATH"
fi
if ! command -v elan >/dev/null 2>&1; then
  echo 'Installing the Lean toolchain manager (elan) into your user account.'
  installer=$(mktemp)
  trap 'rm -f "$installer"' EXIT
  curl --fail --location --retry 3 \
    https://raw.githubusercontent.com/leanprover/elan/master/elan-init.sh -o "$installer"
  sh "$installer" -y --default-toolchain none
  export PATH="$HOME/.elan/bin:$PATH"
fi
elan toolchain install leanprover/lean4:v4.19.0
# Avoid Mathlib's native cache executable, including its update hook.
# Older Lean linkers can produce executables rejected by newer macOS loaders.
export MATHLIB_NO_CACHE_ON_UPDATE=1
lake build '@mathlib/+Cache.Main:olean'
# Only the transitive dependencies of the actual imports are downloaded.
lake env lean --run .lake/packages/mathlib/Cache/Main.lean get \
  Mathlib.Data.Complex.Basic \
  Mathlib.Data.Matrix.ConjTranspose \
  Mathlib.LinearAlgebra.Matrix.Trace \
  Mathlib.Tactic.FinCases Mathlib.Tactic.NormNum \
  Mathlib.Tactic.Ring Mathlib.Tactic.Linarith \
  Mathlib.Tactic.Positivity Mathlib.Tactic.FieldSimp
lake build 2>&1 | tee build.log
lake env lean Audit.lean 2>&1 | tee audit.log
echo 'Verified: BBPSSW one-round correctness and standard-axiom audit.'
