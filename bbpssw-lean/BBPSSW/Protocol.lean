import BBPSSW.Basic
import BBPSSW.Recurrence

/-!
# Bilateral CNOT and postselection
Two-pair indices are (source pair, target pair); the two bits within each
pair are Alice and Bob. Accepted outcomes on the measured target are 00,11.
-/
set_option maxRecDepth 4000
set_option maxHeartbeats 2000000
noncomputable section
open Matrix Complex
open scoped Matrix
namespace BBPSSW

def xor4 : Q → Q → Q :=
  ![![0,1,2,3], ![1,0,3,2], ![2,3,0,1], ![3,2,1,0]]
def aliceBit : Q → Fin 2 := ![0,0,1,1]
def bobBit : Q → Fin 2 := ![0,1,0,1]

/-- Each target bit changes only by the source bit at the same site. -/
theorem xor4_local (s t : Q) :
    aliceBit (xor4 s t) = aliceBit s + aliceBit t ∧
    bobBit (xor4 s t) = bobBit s + bobBit t := by
  fin_cases s <;> fin_cases t <;> decide

theorem xor4_involutive (s t : Q) : xor4 s (xor4 s t) = t := by
  fin_cases s <;> fin_cases t <;> decide

def bxorPerm : Equiv.Perm (Q × Q) where
  toFun x := (x.1, xor4 x.1 x.2)
  invFun x := (x.1, xor4 x.1 x.2)
  left_inv x := by simp [xor4_involutive]
  right_inv x := by simp [xor4_involutive]

def bxorUnitary : M16 := (1 : M16).submatrix bxorPerm id

def bxor (ρ : M16) : M16 := ρ.submatrix bxorPerm bxorPerm

theorem bxor_eq_conjugation (ρ : M16) :
    bxor ρ = bxorUnitary * ρ * bxorUnitaryᴴ := by
  unfold bxorUnitary
  rw [Matrix.conjTranspose_submatrix, Matrix.conjTranspose_one]
  change bxor ρ = (1 : M16).submatrix bxorPerm (Equiv.refl _) * ρ *
    (1 : M16).submatrix (Equiv.refl _) bxorPerm
  rw [Matrix.one_submatrix_mul _ (Equiv.refl _)]
  rw [Matrix.mul_submatrix_one (Equiv.refl _)]
  rfl

theorem bxor_unitary : bxorUnitary * bxorUnitaryᴴ = 1 := by
  have h := bxor_eq_conjugation (1 : M16)
  simp only [Matrix.mul_one] at h
  rw [← h]
  ext i j
  simp [bxor, Matrix.submatrix_apply, Matrix.one_apply, bxorPerm.injective.eq_iff]

def twoCopies (ρ σ : M4) : M16 := fun i j => ρ i.1 j.1 * σ i.2 j.2

/-- Unnormalized source state for one computational target measurement outcome. -/
def branch (m : Q) (ρ σ : M4) : M4 := fun i j =>
  bxor (twoCopies ρ σ) (i,m) (j,m)

def accepted (ρ σ : M4) : M4 := branch 0 ρ σ + branch 3 ρ σ

def acceptedWeights (F : ℝ) : Q → ℝ :=
  ![goodWeight F, 2*F*(1-F)/3, 2*(1-F)^2/9, 2*(1-F)^2/9]

/-- State calculation derived directly from both accepted circuit branches. -/
theorem accepted_werner (F : ℝ) :
    accepted (werner F) (werner F) = mixture (acceptedWeights F) := by
  ext i j
  fin_cases i <;> fin_cases j <;>
    simp [accepted, branch, bxor, twoCopies, bxorPerm, xor4, Matrix.submatrix_apply,
      werner, weights, mixture, bell, bellVector, acceptedWeights, goodWeight,
      Fin.sum_univ_succ] <;> ring

theorem accepted_branches_equal (F : ℝ) :
    branch 0 (werner F) (werner F) = branch 3 (werner F) (werner F) := by
  ext i j
  fin_cases i <;> fin_cases j <;>
    simp [branch, bxor, twoCopies, bxorPerm, xor4, Matrix.submatrix_apply,
      werner, weights, mixture, bell, bellVector, Fin.sum_univ_succ]

theorem accepted_trace (F : ℝ) :
    Matrix.trace (accepted (werner F) (werner F)) = (successProbability F : ℂ) := by
  rw [accepted_werner, trace_mixture]
  congr 1
  simp [acceptedWeights, goodWeight, successProbability, Fin.sum_univ_succ]
  ring

theorem accepted_fidelity (F : ℝ) :
    fidelity (accepted (werner F) (werner F)) = (goodWeight F : ℂ) := by
  rw [accepted_werner, fidelity_mixture]
  rfl

def conditionalOutput (F : ℝ) : M4 :=
  ((successProbability F : ℂ)⁻¹) • accepted (werner F) (werner F)

theorem conditional_fidelity (F : ℝ) :
    fidelity (conditionalOutput F) = (update F : ℂ) := by
  unfold conditionalOutput fidelity
  rw [Matrix.mul_smul, Matrix.trace_smul]
  change (successProbability F : ℂ)⁻¹ *
    fidelity (accepted (werner F) (werner F)) = _
  rw [accepted_fidelity]
  simp [update, div_eq_mul_inv, mul_comm]
end BBPSSW
