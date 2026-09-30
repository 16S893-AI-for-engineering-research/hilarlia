import Mathlib.Data.Complex.Basic
import Mathlib.Data.Matrix.ConjTranspose
import Mathlib.LinearAlgebra.Matrix.Trace
import Mathlib.Tactic.FinCases
import Mathlib.Tactic.NormNum
import Mathlib.Tactic.Ring
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Positivity
import Mathlib.Tactic.FieldSimp

/-!
# Bell projectors and mixtures
Computational labels 0,1,2,3 are 00,01,10,11.
Bell labels 0,1,2,3 are Φ+, Φ−, Ψ+, Ψ−.
All scalar calculations take place in exact ℂ and ℝ.
-/
set_option maxRecDepth 4000
set_option maxHeartbeats 2000000
noncomputable section
open Matrix Complex
open scoped Matrix
namespace BBPSSW
abbrev Q := Fin 4
abbrev M4 := Matrix Q Q ℂ
abbrev M16 := Matrix (Q × Q) (Q × Q) ℂ

def bellVector : Q → Q → ℂ :=
  ![![1,0,0,1], ![1,0,0,-1], ![0,1,1,0], ![0,1,-1,0]]

/-- Normalized Bell projector. The vector above has squared norm two. -/
def bell (k : Q) : M4 := fun i j => bellVector k i * star (bellVector k j) / 2

def mixture (w : Q → ℝ) : M4 := fun i j => ∑ k, (w k : ℂ) * bell k i j

def weights (F : ℝ) : Q → ℝ := ![F,(1-F)/3,(1-F)/3,(1-F)/3]
def werner (F : ℝ) : M4 := mixture (weights F)

/-- The usual complex positive-semidefinite condition, stated as a quadratic form.
Self-adjointness is included explicitly. No spectral assumptions are introduced. -/
def Positive (ρ : M4) : Prop :=
  ρᴴ = ρ ∧ ∀ x : Q → ℂ, 0 ≤ (dotProduct (star x) (ρ *ᵥ x)).re

def IsDensity (ρ : M4) : Prop := Positive ρ ∧ Matrix.trace ρ = 1

@[simp] theorem trace_bell (k : Q) : Matrix.trace (bell k) = 1 := by
  fin_cases k <;> norm_num [Matrix.trace, Matrix.diag, bell, bellVector, Fin.sum_univ_succ]

theorem bell_hermitian (k : Q) : (bell k)ᴴ = bell k := by
  ext i j
  fin_cases k <;> fin_cases i <;> fin_cases j <;>
    norm_num [bell, bellVector, Matrix.conjTranspose_apply]

theorem bell_idempotent (k : Q) : bell k * bell k = bell k := by
  ext i j
  fin_cases k <;> fin_cases i <;> fin_cases j <;>
    norm_num [bell, bellVector, Matrix.mul_apply, Fin.sum_univ_succ]

theorem bell_positive (k : Q) : Positive (bell k) := by
  refine ⟨bell_hermitian k, ?_⟩
  intro x
  have heq : (dotProduct (star x) (bell k *ᵥ x)).re =
      ((∑ i, star (bellVector k i) * x i).re^2 +
       (∑ i, star (bellVector k i) * x i).im^2) / 2 := by
    fin_cases k <;>
      simp [dotProduct, Matrix.mulVec, bell, bellVector, Fin.sum_univ_succ,
        Complex.mul_re, Complex.mul_im, Complex.div_re, Complex.div_im] <;> ring
  rw [heq]
  positivity

theorem positive_real_smul (ρ : M4) (hρ : Positive ρ) (c : ℝ) (hc : 0 ≤ c) :
    Positive ((c : ℂ) • ρ) := by
  constructor
  · simp [Matrix.conjTranspose_smul, hρ.1]
  · intro x
    simp only [Matrix.smul_mulVec_assoc, dotProduct_smul]
    simpa using mul_nonneg hc (hρ.2 x)

theorem positive_add (ρ σ : M4) (hρ : Positive ρ) (hσ : Positive σ) :
    Positive (ρ + σ) := by
  constructor
  · simp [Matrix.conjTranspose_add, hρ.1, hσ.1]
  · intro x
    simpa [Matrix.add_mulVec, dotProduct_add] using add_nonneg (hρ.2 x) (hσ.2 x)

theorem mixture_positive (w : Q → ℝ) (hw : ∀ k, 0 ≤ w k) : Positive (mixture w) := by
  have heq : mixture w = (w 0 : ℂ) • bell 0 + (w 1 : ℂ) • bell 1 +
      (w 2 : ℂ) • bell 2 + (w 3 : ℂ) • bell 3 := by
    ext i j
    simp [mixture, Fin.sum_univ_succ]
    ring
  rw [heq]
  apply positive_add
  · apply positive_add
    · apply positive_add
      · exact positive_real_smul _ (bell_positive 0) _ (hw 0)
      · exact positive_real_smul _ (bell_positive 1) _ (hw 1)
    · exact positive_real_smul _ (bell_positive 2) _ (hw 2)
  · exact positive_real_smul _ (bell_positive 3) _ (hw 3)

theorem mixture_real_smul (c : ℝ) (w : Q → ℝ) :
    (c : ℂ) • mixture w = mixture (fun k => c * w k) := by
  ext i j
  simp [mixture, Fin.sum_univ_succ]
  ring

@[simp] theorem trace_mixture (w : Q → ℝ) :
    Matrix.trace (mixture w) = ((∑ k, w k : ℝ) : ℂ) := by
  simp [Matrix.trace, Matrix.diag, mixture, bell, bellVector, Fin.sum_univ_succ]
  ring

theorem werner_density {F : ℝ} (h0 : 0 ≤ F) (h1 : F ≤ 1) : IsDensity (werner F) := by
  have hdiff : 0 ≤ 1 - F := sub_nonneg.mpr h1
  constructor
  · apply mixture_positive
    intro k
    fin_cases k <;> simp [weights] <;> positivity
  · simp [werner, weights, Fin.sum_univ_succ]
    ring

def fidelity (ρ : M4) : ℂ := Matrix.trace (bell 0 * ρ)

@[simp] theorem fidelity_mixture (w : Q → ℝ) : fidelity (mixture w) = (w 0 : ℂ) := by
  simp [fidelity, Matrix.trace, Matrix.diag, Matrix.mul_apply, mixture,
    bell, bellVector, Fin.sum_univ_succ]
  ring

@[simp] theorem fidelity_werner (F : ℝ) : fidelity (werner F) = (F : ℂ) := by
  simp [werner, weights]
end BBPSSW
