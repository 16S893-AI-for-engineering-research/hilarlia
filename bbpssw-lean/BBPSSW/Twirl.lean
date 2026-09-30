import BBPSSW.Protocol

/-!
# Finite local-unitary symmetrization
V = U ⊗ conjugate(U) fixes Φ+ and cycles the other Bell projectors.
The average over I,V,V² restores the Werner form on Bell-diagonal inputs.
The classical random choice is discarded, as in standard BBPSSW twirling.
-/
set_option maxRecDepth 4000
set_option maxHeartbeats 2000000
noncomputable section
open Matrix Complex
open scoped Matrix
namespace BBPSSW

def cycleU : Matrix (Fin 2) (Fin 2) ℂ :=
  !![(1-I)/2, (-1-I)/2; (1-I)/2, (1+I)/2]

def cyclePair : M4 := fun i j =>
  cycleU (aliceBit i) (aliceBit j) * star (cycleU (bobBit i) (bobBit j))

theorem cycleU_unitary : cycleU * cycleUᴴ = 1 := by
  ext i j
  fin_cases i <;> fin_cases j <;>
    norm_num [cycleU, Matrix.mul_apply, Matrix.conjTranspose_apply, Fin.sum_univ_succ,
      Matrix.one_apply, map_ofNat, Complex.ext_iff, Complex.mul_re, Complex.mul_im]

/-- Evaluate the tensor product once, so later proofs use small exact entries. -/
theorem cyclePair_matrix : cyclePair =
    !![1/2, I/2, -I/2, 1/2;
       1/2, -I/2, -I/2, -1/2;
       1/2, I/2, I/2, -1/2;
       1/2, -I/2, I/2, 1/2] := by
  ext i j
  fin_cases i <;> fin_cases j <;>
    norm_num [cyclePair, cycleU, aliceBit, bobBit, map_ofNat,
      Complex.ext_iff, Complex.mul_re, Complex.mul_im]

theorem cyclePair_unitary : cyclePair * cyclePairᴴ = 1 := by
  ext i j
  fin_cases i <;> fin_cases j <;>
    norm_num [cyclePair_matrix, Matrix.mul_apply,
      Matrix.conjTranspose_apply, Fin.sum_univ_succ, Matrix.one_apply,
      map_ofNat, Complex.ext_iff, Complex.mul_re, Complex.mul_im]

def cycleConj (ρ : M4) : M4 := cyclePair * ρ * cyclePairᴴ
def cycleLabel : Q → Q := ![0,2,3,1]

def twirl (ρ : M4) : M4 := (1/3 : ℂ) • (ρ + cycleConj ρ + cycleConj (cycleConj ρ))

theorem cycle_mixture (w : Q → ℝ) :
    cycleConj (mixture w) = mixture ![w 0, w 3, w 1, w 2] := by
  ext i j
  fin_cases i <;> fin_cases j <;>
    simp [cycleConj, cyclePair_matrix, mixture, bell, bellVector,
      Matrix.mul_apply, Matrix.vecMul, dotProduct, Matrix.conjTranspose_apply, Fin.sum_univ_succ,
      map_ofNat, Complex.ext_iff, Complex.mul_re, Complex.mul_im] <;> ring_nf

/-- The four Bell cases follow from the general Bell-diagonal calculation. -/
theorem cycle_bell (k : Q) : cycleConj (bell k) = bell (cycleLabel k) := by
  have hm (j : Q) : mixture (fun i => if i = j then 1 else 0) = bell j := by
    fin_cases j <;> ext a b <;> simp [mixture, Fin.sum_univ_succ]
  rw [← hm k, cycle_mixture]
  fin_cases k <;> ext i j <;>
    simp [mixture, cycleLabel, Fin.sum_univ_succ]

theorem twirl_mixture (w : Q → ℝ) :
    twirl (mixture w) =
      mixture ![w 0, (w 1+w 2+w 3)/3, (w 1+w 2+w 3)/3, (w 1+w 2+w 3)/3] := by
  unfold twirl
  rw [cycle_mixture, cycle_mixture]
  ext i j
  fin_cases i <;> fin_cases j <;>
    simp [mixture, bell, bellVector, Fin.sum_univ_succ] <;> ring

theorem cycle_smul (c : ℂ) (ρ : M4) : cycleConj (c • ρ) = c • cycleConj ρ := by
  simp [cycleConj, Matrix.mul_smul, Matrix.smul_mul]

theorem twirl_smul (c : ℂ) (ρ : M4) : twirl (c • ρ) = c • twirl ρ := by
  simp [twirl, cycle_smul, smul_add, smul_smul, mul_comm]

def roundOutput (F : ℝ) : M4 := twirl (conditionalOutput F)

/-- Complete state-level recurrence for the physically defined round. -/
theorem round_output (F : ℝ) : roundOutput F = werner (update F) := by
  have hp : successProbability F ≠ 0 := ne_of_gt (success_positive F)
  unfold roundOutput conditionalOutput
  rw [twirl_smul, accepted_werner, twirl_mixture]
  rw [← Complex.ofReal_inv, mixture_real_smul]
  unfold werner
  apply congrArg mixture
  funext k
  fin_cases k <;> simp [weights, acceptedWeights, update]
  all_goals
    field_simp [hp] <;> unfold successProbability goodWeight <;> ring
end BBPSSW
