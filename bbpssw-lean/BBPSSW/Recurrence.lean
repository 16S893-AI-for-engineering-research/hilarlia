import Mathlib.Data.Real.Basic
import Mathlib.Tactic.NormNum
import Mathlib.Tactic.Ring
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.FieldSimp

/-! # Exact real-arithmetic properties of the BBPSSW recurrence -/
noncomputable section
namespace BBPSSW

def successProbability (F : ℝ) : ℝ := F^2 + 2/3*F*(1-F) + 5/9*(1-F)^2
def goodWeight (F : ℝ) : ℝ := F^2 + (1-F)^2/9
def update (F : ℝ) : ℝ := goodWeight F / successProbability F

theorem success_polynomial (F : ℝ) :
    successProbability F = (8*F^2-4*F+5)/9 := by unfold successProbability; ring

theorem success_positive (F : ℝ) : 0 < successProbability F := by
  rw [success_polynomial]
  nlinarith [sq_nonneg (F-1/4)]

theorem success_at_most_one {F : ℝ} (h0 : 0 ≤ F) (h1 : F ≤ 1) :
    successProbability F ≤ 1 := by
  rw [success_polynomial]
  nlinarith [mul_nonneg h0 (sub_nonneg.mpr h1)]

/-- The corrected 1997 bound, strict when F > 1/2. -/
theorem success_gt_five_ninths {F : ℝ} (h : 1/2 < F) :
    5/9 < successProbability F := by
  rw [success_polynomial]
  have hp : 0 < F*(2*F-1) := mul_pos (by linarith) (by linarith)
  nlinarith

theorem update_sub (F : ℝ) :
    update F-F = (1-F)*(4*F-1)*(2*F-1)/(8*F^2-4*F+5) := by
  have hd : 8*F^2-4*F+5 ≠ 0 := by
    have := success_positive F
    rw [success_polynomial] at this
    nlinarith
  unfold update goodWeight
  rw [success_polynomial]
  field_simp
  ring

theorem update_improves {F : ℝ} (hlo : 1/2 < F) (hhi : F < 1) : F < update F := by
  have hp : 0 < (1-F)*(4*F-1)*(2*F-1) :=
    mul_pos (mul_pos (by linarith) (by linarith)) (by linarith)
  have hd : 0 < 8*F^2-4*F+5 := by
    have := success_positive F
    rw [success_polynomial] at this
    linarith
  have := div_pos hp hd
  rw [← update_sub] at this
  linarith

theorem update_lt_one {F : ℝ} (hlo : 1/2 < F) (hhi : F < 1) : update F < 1 := by
  unfold update
  apply (div_lt_one (success_positive F)).mpr
  have hp : 0 < (1-F)*(F+2) := mul_pos (by linarith) (by linarith)
  unfold goodWeight successProbability
  nlinarith

@[simp] theorem update_one : update 1 = 1 := by norm_num [update, goodWeight, successProbability]
@[simp] theorem update_half : update (1/2) = 1/2 := by norm_num [update, goodWeight, successProbability]

theorem example_three_quarters :
    successProbability (3/4) = 13/18 ∧ update (3/4) = 41/52 := by
  norm_num [successProbability, update, goodWeight]
end BBPSSW
