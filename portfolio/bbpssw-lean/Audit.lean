import BBPSSW
import Lean.Util.CollectAxioms

/-!
The audit rejects any transitive axiom outside Lean's three standard
mathematical foundations. In particular it rejects sorryAx and axioms
introduced by native evaluation. It does not change any proof or definition.
-/
open Lean Elab Command in
elab "#audit_bbpssw" : command => do
  let allowed : Array Name := #[``propext, ``Classical.choice, ``Quot.sound]
  let theorems : Array Name := #[
    ``BBPSSW.trace_bell,
    ``BBPSSW.bell_hermitian,
    ``BBPSSW.bell_idempotent,
    ``BBPSSW.bell_positive,
    ``BBPSSW.positive_real_smul,
    ``BBPSSW.positive_add,
    ``BBPSSW.mixture_positive,
    ``BBPSSW.mixture_real_smul,
    ``BBPSSW.trace_mixture,
    ``BBPSSW.werner_density,
    ``BBPSSW.fidelity_mixture,
    ``BBPSSW.fidelity_werner,
    ``BBPSSW.success_polynomial,
    ``BBPSSW.success_positive,
    ``BBPSSW.success_at_most_one,
    ``BBPSSW.success_gt_five_ninths,
    ``BBPSSW.update_sub,
    ``BBPSSW.update_improves,
    ``BBPSSW.update_lt_one,
    ``BBPSSW.update_one,
    ``BBPSSW.update_half,
    ``BBPSSW.example_three_quarters,
    ``BBPSSW.xor4_local,
    ``BBPSSW.xor4_involutive,
    ``BBPSSW.bxor_eq_conjugation,
    ``BBPSSW.bxor_unitary,
    ``BBPSSW.accepted_werner,
    ``BBPSSW.accepted_branches_equal,
    ``BBPSSW.accepted_trace,
    ``BBPSSW.accepted_fidelity,
    ``BBPSSW.conditional_fidelity,
    ``BBPSSW.cycleU_unitary,
    ``BBPSSW.cyclePair_matrix,
    ``BBPSSW.cyclePair_unitary,
    ``BBPSSW.cycle_mixture,
    ``BBPSSW.cycle_bell,
    ``BBPSSW.twirl_mixture,
    ``BBPSSW.cycle_smul,
    ``BBPSSW.twirl_smul,
    ``BBPSSW.round_output,
    ``BBPSSW.round_density,
    ``BBPSSW.bbpssw_correct]
  for name in theorems do
    let axioms ← Lean.collectAxioms name
    for ax in axioms do
      unless allowed.contains ax do
        throwError "AUDIT FAILED: {name} depends on {ax}"
    logInfo m!"PASS {name}: {axioms}"
  logInfo "BBPSSW AUDIT PASSED: all listed theorems use only standard Lean axioms."

#audit_bbpssw
#check BBPSSW.bbpssw_correct
