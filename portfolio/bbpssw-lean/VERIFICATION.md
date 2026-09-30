# Verification record

Verified on 2026-09-30 using Lean 4.19.0 and Mathlib v4.19.0.

- Lean release commit: `6caaee842e94`.
- Mathlib commit: `c44e0c8ee63ca166450922a373c7409c5d26b00b`.
- `lake build`: passed, including the main theorem `BBPSSW.bbpssw_correct`.
- `lake env lean Audit.lean`: passed for all 42 named project theorems.
- Permitted transitive axioms: `propext`, `Classical.choice`, `Quot.sound`.
- No unfinished proofs, custom axioms, or native-evaluation proof tactics are used.
- `run.sh` passed Bash syntax checking.

The recorded outputs are in `verification/build.log` and `verification/audit.log`.
`SOURCE_SHA256.txt` identifies the Lean source files that were verified.

The verified statement is one-round BBPSSW correctness for identical independent
Werner inputs with `1/2 < F < 1`: density-matrix validity, the success probability,
its corrected bound, the complete output-state identity, and strict fidelity
improvement. The README explains the correspondence with the paper and the
finite local twirl used here. This is not a formalization of the entire paper.

## Environment and reproduction

The build and audit were executed on Linux. The hosted environment required an
adjustment to the installed Lean runtime's executable-location lookup string;
the kernel code was unchanged. The compiler and that adjustment are not included
in this source archive. `run.sh` installs the normal official Lean release.

The fresh-install elan bootstrap in `run.sh` was not exercised end-to-end here;
the proof build and axiom audit were executed using the installed pinned
toolchain. An internet connection, Git, curl, and several GB of disk space are
needed for first-time installation on macOS or Linux.

## Runner update for the macOS loader error

The runner now builds only the `Cache.Main` Lean module artifact and executes
`Cache/Main.lean` through `lean --run`. It sets `MATHLIB_NO_CACHE_ON_UPDATE=1`
to suppress the native downloader in Mathlib's update hook. The commands and
variable name were checked against the pinned Lean/Mathlib 4.19.0 sources.

Only the runner and documentation changed in this update. Every Lean source file
still matches the recorded SHA-256 values, so the earlier proof-build and
42-theorem audit records apply to these same proofs. Bash syntax checking passed
for the updated runner. The macOS loader workaround has not been run on a Mac in
this environment.
