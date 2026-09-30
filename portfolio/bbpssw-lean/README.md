# BBPSSW entanglement purification in Lean

**Scope:** one complete successful round of the BBPSSW recurrence protocol on two independent, identically prepared Werner pairs. The formalization includes local gates, computational-basis measurement, acceptance, normalization, an explicit finite local twirl, and strict fidelity improvement for `1/2 < F < 1`.

## Run

On macOS or Linux, unzip this project and run in its directory:

```bash
bash run.sh
```

The script installs the Lean toolchain manager into your user account if needed, downloads **Lean 4.19.0** and the pinned Mathlib dependencies, compiles the project, and performs an axiom audit. Git, curl, an internet connection, and several GB of free disk space are needed for the first run. The first download and proof compilation can each take several minutes. Subsequent builds reuse the downloads.

If Lean is already installed, the essential verification commands are:

```bash
lake build
lake env lean Audit.lean
```

A successful audit prints `BBPSSW AUDIT PASSED` and writes `build.log` and `audit.log`. The audit fails if any listed theorem depends transitively on an axiom other than `propext`, `Classical.choice`, or `Quot.sound`. There are no mathematical assumptions hidden behind custom axioms, no incomplete proof placeholders, and no native-evaluation proof tactic.

This release compiled successfully and all 42 named theorems passed the audit. See `VERIFICATION.md` and the recorded logs in `verification/`.

## macOS cache downloader compatibility

The runner uses Lean's interpreter to execute Mathlib's downloader. This avoids
running the locally linked `.lake/packages/mathlib/.lake/build/bin/cache` binary,
which can trigger `__DATA_CONST segment missing SG_READ_ONLY flag` on newer macOS
versions with the pinned toolchain. It also disables Mathlib's automatic native
cache invocation during dependency updates.

If the earlier runner stopped with that error, replace `run.sh` with this version
and run `bash run.sh` again in the existing project. Existing dependencies and
cached files are reused. The Lean and Mathlib versions stay pinned at 4.19.0.

Upstream reports:
- <https://github.com/leanprover/lean4/issues/7917>
- <https://leanprover-community.github.io/archive/stream/113488-general/topic/Mathlib.204.2E15.20build.20failure.20on.20macOS.20Tahoe.20(26.2E1).html>

## Paper and precise scope

C. H. Bennett, G. Brassard, S. Popescu, B. Schumacher, J. A. Smolin, W. K. Wootters, **Purification of Noisy Entanglement and Faithful Teleportation via Noisy Channels**, Physical Review Letters **76**, 722–725 (1996), DOI: <https://doi.org/10.1103/PhysRevLett.76.722>.

Open manuscript: <https://arxiv.org/pdf/quant-ph/9511027>.

Erratum: Physical Review Letters **78**, 2031 (1997), <https://doi.org/10.1103/PhysRevLett.78.2031>.

The target is **Equation (7) and protocol steps A1–A3**, with the corrected success-probability bound. We work in the locally equivalent Phi-plus convention throughout, absorbing the paper's initial/final single-qubit Bell-basis changes into the convention.

This project does not prove the paper's asymptotic positive-rate distillation theorem, a hashing theorem, optimality over LOCC, or robustness to imperfect gates. The inputs are independent copies with the same fidelity and the local operations are ideal. The twirl discards its classical randomization record, as in the usual averaged-state protocol.

## Mathematical definitions

Computational labels `0,1,2,3` mean `00,01,10,11`. Bell labels in that order mean `Phi+`, `Phi-`, `Psi+`, `Psi-`.

`bell k` is the normalized Bell projector. It is written as half an outer product of a vector with entries 0 and ±1, avoiding unnecessary square roots without changing the state.

`werner F` is the Bell-diagonal density matrix with weights

```
[F, (1-F)/3, (1-F)/3, (1-F)/3].
```

`Positive rho` explicitly means that `rho` is self-adjoint and the real part of `x† rho x` is nonnegative for **every complex vector x**. `IsDensity rho` adds trace one. These are the conventional finite-dimensional density-matrix conditions. No numerical sampling or tolerance is used.

Two-pair indices are `(source pair, target pair)`. The bilateral-CNOT permutation sends `(s,t)` to `(s, s XOR t)`. The lemma `xor4_local` verifies that Alice's target bit depends only on Alice's source bit, and likewise for Bob. `bxor_eq_conjugation` connects index reordering to matrix conjugation by the explicitly unitary permutation matrix.

`branch m rho sigma` is the unnormalized source density matrix for one measured target outcome. `accepted` sums the branches `00` and `11`. Its trace is the success probability, which is proved equal to

```
P(F) = F^2 + (2/3) F (1-F) + (5/9) (1-F)^2.
```

Its target-projector overlap is

```
N(F) = F^2 + (1-F)^2/9.
```

`conditionalOutput` divides the accepted matrix by `P(F)`, after a separate theorem proves that this denominator is positive. The update is `f(F) = N(F)/P(F)`.

## Symmetrization

The retained pair before twirling is generally Bell-diagonal but not Werner. The project defines an explicit one-qubit unitary `U` and the local tensor-product unitary `V = U ⊗ conjugate(U)`. It proves that `V` fixes `Phi+` and cycles the other three Bell projectors. Averaging the three local-unitary branches `I`, `V`, `V^2` therefore equalizes the three error weights while preserving target fidelity.

This is an explicit finite twirl sufficient for the Bell-diagonal inputs produced by the recurrence. It is not asserted to twirl arbitrary input matrices to Werner form. It uses an equivalent cyclic averaging construction rather than repeating the original paper's corrected finite rotation list verbatim.

`roundOutput` is the normalized, twirled output. The state-level theorem is

```
round_output : roundOutput F = werner (update F).
```

The main theorem `bbpssw_correct` combines input and output validity, the actual circuit success probability, `5/9 < P(F) <= 1`, the output-state identity, and `F < f(F) < 1` under `1/2 < F < 1`.

## File guide

| File | Role |
|---|---|
| `BBPSSW/Basic.lean` | Exact complex matrices, Bell projectors, positivity, trace, fidelity |
| `BBPSSW/Recurrence.lean` | Rational recurrence, denominator positivity, success bound, strict gain |
| `BBPSSW/Protocol.lean` | Local CNOT, measurement branches, accepted state, normalization |
| `BBPSSW/Twirl.lean` | Local Clifford averaging and complete state-level recurrence |
| `BBPSSW/Main.lean` | Main physical correctness theorem |
| `Audit.lean` | Transitive axiom whitelist audit and printed main theorem |

For a course presentation, explain the mathematical meaning of these definitions first, then show the circuit-to-state calculation and the final theorem. A compiler success establishes the encoded statement; interpreting that statement against the paper remains part of the mathematical review. Disclose assistance in accordance with your course rules.

The exact example `F = 3/4` has success probability `13/18` and updated fidelity `41/52`; `example_three_quarters` verifies these equalities.
