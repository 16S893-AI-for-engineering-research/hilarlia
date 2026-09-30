import BBPSSW.Twirl

/-!
# BBPSSW verification certificate
Reference: Bennett et al., PRL 76, 722 (1996), Eq. (7), A1–A3;
erratum PRL 78, 2031 (1997). We use the locally equivalent Φ+ convention.
-/
noncomputable section
namespace BBPSSW

theorem round_density {F : ℝ} (hlo : 1/2 < F) (hhi : F < 1) :
    IsDensity (roundOutput F) := by
  rw [round_output]
  apply werner_density
  · have := update_improves hlo hhi
    linarith
  · exact le_of_lt (update_lt_one hlo hhi)

/-- A valid output state, the actual success probability, and strict fidelity gain. -/
theorem bbpssw_correct {F : ℝ} (hlo : 1/2 < F) (hhi : F < 1) :
    IsDensity (werner F) ∧
    Matrix.trace (accepted (werner F) (werner F)) = (successProbability F : ℂ) ∧
    5/9 < successProbability F ∧ successProbability F ≤ 1 ∧
    roundOutput F = werner (update F) ∧
    IsDensity (roundOutput F) ∧
    fidelity (roundOutput F) = (update F : ℂ) ∧
    F < update F ∧ update F < 1 := by
  refine ⟨werner_density (by linarith) (by linarith), accepted_trace F,
    success_gt_five_ninths hlo, success_at_most_one (by linarith) (by linarith),
    round_output F, round_density hlo hhi, ?_, update_improves hlo hhi, update_lt_one hlo hhi⟩
  rw [round_output, fidelity_werner]
end BBPSSW
