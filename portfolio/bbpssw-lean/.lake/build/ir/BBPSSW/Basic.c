// Lean compiler output
// Module: BBPSSW.Basic
// Imports: Init Mathlib.Data.Complex.Basic Mathlib.Data.Matrix.ConjTranspose Mathlib.LinearAlgebra.Matrix.Trace Mathlib.Tactic.FinCases Mathlib.Tactic.NormNum Mathlib.Tactic.Ring Mathlib.Tactic.Linarith Mathlib.Tactic.Positivity Mathlib.Tactic.FieldSimp
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern lean_object* l___private_Mathlib_Data_Real_Basic_0__Real_zero;
LEAN_EXPORT lean_object* l_BBPSSW_bellVector(lean_object*, lean_object*);
static lean_object* l_BBPSSW_bellVector___closed__11;
static lean_object* l_BBPSSW_bellVector___closed__15;
static lean_object* l_BBPSSW_bellVector___closed__19;
static lean_object* l_BBPSSW_bellVector___closed__13;
static lean_object* l_BBPSSW_bellVector___closed__21;
LEAN_EXPORT lean_object* l_BBPSSW_bellVector___boxed(lean_object*, lean_object*);
static lean_object* l_BBPSSW_bellVector___closed__17;
static lean_object* l_BBPSSW_bellVector___closed__3;
lean_object* l_Matrix_vecEmpty___boxed(lean_object*, lean_object*);
static lean_object* l_BBPSSW_bellVector___closed__4;
extern lean_object* l___private_Mathlib_Data_Real_Basic_0__Real_one;
static lean_object* l_BBPSSW_bellVector___closed__23;
static lean_object* l_BBPSSW_bellVector___closed__2;
lean_object* l_Real_definition____x40_Mathlib_Data_Real_Basic___hyg_579_(lean_object*);
static lean_object* l_BBPSSW_bellVector___closed__16;
static lean_object* l_BBPSSW_bellVector___closed__7;
static lean_object* l_BBPSSW_bellVector___closed__24;
static lean_object* l_BBPSSW_bellVector___closed__12;
lean_object* l_Fin_cases(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_BBPSSW_bellVector___closed__9;
static lean_object* l_BBPSSW_bellVector___closed__1;
static lean_object* l_BBPSSW_bellVector___closed__18;
static lean_object* l_BBPSSW_bellVector___closed__20;
static lean_object* l_BBPSSW_bellVector___closed__8;
static lean_object* l_BBPSSW_bellVector___closed__10;
static lean_object* l_BBPSSW_bellVector___closed__5;
lean_object* l_Matrix_vecCons___rarg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_BBPSSW_bellVector___closed__6;
static lean_object* l_BBPSSW_bellVector___closed__22;
static lean_object* l_BBPSSW_bellVector___closed__14;
static lean_object* _init_l_BBPSSW_bellVector___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l___private_Mathlib_Data_Real_Basic_0__Real_one;
x_2 = l___private_Mathlib_Data_Real_Basic_0__Real_zero;
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_Mathlib_Data_Real_Basic_0__Real_zero;
x_2 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_2, 0, x_1);
lean_ctor_set(x_2, 1, x_1);
return x_2;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_Matrix_vecEmpty___boxed), 2, 1);
lean_closure_set(x_1, 0, lean_box(0));
return x_1;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = l_BBPSSW_bellVector___closed__1;
x_3 = l_BBPSSW_bellVector___closed__3;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = l_BBPSSW_bellVector___closed__2;
x_3 = l_BBPSSW_bellVector___closed__4;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = l_BBPSSW_bellVector___closed__2;
x_3 = l_BBPSSW_bellVector___closed__5;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(3u);
x_2 = l_BBPSSW_bellVector___closed__1;
x_3 = l_BBPSSW_bellVector___closed__6;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__8() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_Mathlib_Data_Real_Basic_0__Real_one;
x_2 = l_Real_definition____x40_Mathlib_Data_Real_Basic___hyg_579_(x_1);
return x_2;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__9() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l___private_Mathlib_Data_Real_Basic_0__Real_zero;
x_2 = l_Real_definition____x40_Mathlib_Data_Real_Basic___hyg_579_(x_1);
return x_2;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__10() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_BBPSSW_bellVector___closed__8;
x_2 = l_BBPSSW_bellVector___closed__9;
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__11() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = l_BBPSSW_bellVector___closed__10;
x_3 = l_BBPSSW_bellVector___closed__3;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__12() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = l_BBPSSW_bellVector___closed__2;
x_3 = l_BBPSSW_bellVector___closed__11;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__13() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = l_BBPSSW_bellVector___closed__2;
x_3 = l_BBPSSW_bellVector___closed__12;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__14() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(3u);
x_2 = l_BBPSSW_bellVector___closed__1;
x_3 = l_BBPSSW_bellVector___closed__13;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__15() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = l_BBPSSW_bellVector___closed__2;
x_3 = l_BBPSSW_bellVector___closed__3;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__16() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = l_BBPSSW_bellVector___closed__1;
x_3 = l_BBPSSW_bellVector___closed__15;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__17() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = l_BBPSSW_bellVector___closed__1;
x_3 = l_BBPSSW_bellVector___closed__16;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__18() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(3u);
x_2 = l_BBPSSW_bellVector___closed__2;
x_3 = l_BBPSSW_bellVector___closed__17;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__19() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = l_BBPSSW_bellVector___closed__10;
x_3 = l_BBPSSW_bellVector___closed__15;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__20() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = l_BBPSSW_bellVector___closed__1;
x_3 = l_BBPSSW_bellVector___closed__19;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__21() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(3u);
x_2 = l_BBPSSW_bellVector___closed__2;
x_3 = l_BBPSSW_bellVector___closed__20;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__22() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = l_BBPSSW_bellVector___closed__21;
x_3 = l_BBPSSW_bellVector___closed__3;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__23() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = l_BBPSSW_bellVector___closed__18;
x_3 = l_BBPSSW_bellVector___closed__22;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_bellVector___closed__24() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = l_BBPSSW_bellVector___closed__14;
x_3 = l_BBPSSW_bellVector___closed__23;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* l_BBPSSW_bellVector(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_3 = lean_unsigned_to_nat(3u);
x_4 = l_BBPSSW_bellVector___closed__7;
x_5 = l_BBPSSW_bellVector___closed__24;
x_6 = l_Fin_cases(x_3, lean_box(0), x_4, x_5, x_1);
x_7 = lean_apply_1(x_6, x_2);
return x_7;
}
}
LEAN_EXPORT lean_object* l_BBPSSW_bellVector___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_BBPSSW_bellVector(x_1, x_2);
lean_dec(x_1);
return x_3;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_Complex_Basic(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_Matrix_ConjTranspose(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_LinearAlgebra_Matrix_Trace(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Tactic_FinCases(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Tactic_NormNum(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Tactic_Ring(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Tactic_Linarith(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Tactic_Positivity(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Tactic_FieldSimp(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_BBPSSW_Basic(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_Complex_Basic(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_Matrix_ConjTranspose(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_LinearAlgebra_Matrix_Trace(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Tactic_FinCases(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Tactic_NormNum(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Tactic_Ring(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Tactic_Linarith(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Tactic_Positivity(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Tactic_FieldSimp(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_BBPSSW_bellVector___closed__1 = _init_l_BBPSSW_bellVector___closed__1();
lean_mark_persistent(l_BBPSSW_bellVector___closed__1);
l_BBPSSW_bellVector___closed__2 = _init_l_BBPSSW_bellVector___closed__2();
lean_mark_persistent(l_BBPSSW_bellVector___closed__2);
l_BBPSSW_bellVector___closed__3 = _init_l_BBPSSW_bellVector___closed__3();
lean_mark_persistent(l_BBPSSW_bellVector___closed__3);
l_BBPSSW_bellVector___closed__4 = _init_l_BBPSSW_bellVector___closed__4();
lean_mark_persistent(l_BBPSSW_bellVector___closed__4);
l_BBPSSW_bellVector___closed__5 = _init_l_BBPSSW_bellVector___closed__5();
lean_mark_persistent(l_BBPSSW_bellVector___closed__5);
l_BBPSSW_bellVector___closed__6 = _init_l_BBPSSW_bellVector___closed__6();
lean_mark_persistent(l_BBPSSW_bellVector___closed__6);
l_BBPSSW_bellVector___closed__7 = _init_l_BBPSSW_bellVector___closed__7();
lean_mark_persistent(l_BBPSSW_bellVector___closed__7);
l_BBPSSW_bellVector___closed__8 = _init_l_BBPSSW_bellVector___closed__8();
lean_mark_persistent(l_BBPSSW_bellVector___closed__8);
l_BBPSSW_bellVector___closed__9 = _init_l_BBPSSW_bellVector___closed__9();
lean_mark_persistent(l_BBPSSW_bellVector___closed__9);
l_BBPSSW_bellVector___closed__10 = _init_l_BBPSSW_bellVector___closed__10();
lean_mark_persistent(l_BBPSSW_bellVector___closed__10);
l_BBPSSW_bellVector___closed__11 = _init_l_BBPSSW_bellVector___closed__11();
lean_mark_persistent(l_BBPSSW_bellVector___closed__11);
l_BBPSSW_bellVector___closed__12 = _init_l_BBPSSW_bellVector___closed__12();
lean_mark_persistent(l_BBPSSW_bellVector___closed__12);
l_BBPSSW_bellVector___closed__13 = _init_l_BBPSSW_bellVector___closed__13();
lean_mark_persistent(l_BBPSSW_bellVector___closed__13);
l_BBPSSW_bellVector___closed__14 = _init_l_BBPSSW_bellVector___closed__14();
lean_mark_persistent(l_BBPSSW_bellVector___closed__14);
l_BBPSSW_bellVector___closed__15 = _init_l_BBPSSW_bellVector___closed__15();
lean_mark_persistent(l_BBPSSW_bellVector___closed__15);
l_BBPSSW_bellVector___closed__16 = _init_l_BBPSSW_bellVector___closed__16();
lean_mark_persistent(l_BBPSSW_bellVector___closed__16);
l_BBPSSW_bellVector___closed__17 = _init_l_BBPSSW_bellVector___closed__17();
lean_mark_persistent(l_BBPSSW_bellVector___closed__17);
l_BBPSSW_bellVector___closed__18 = _init_l_BBPSSW_bellVector___closed__18();
lean_mark_persistent(l_BBPSSW_bellVector___closed__18);
l_BBPSSW_bellVector___closed__19 = _init_l_BBPSSW_bellVector___closed__19();
lean_mark_persistent(l_BBPSSW_bellVector___closed__19);
l_BBPSSW_bellVector___closed__20 = _init_l_BBPSSW_bellVector___closed__20();
lean_mark_persistent(l_BBPSSW_bellVector___closed__20);
l_BBPSSW_bellVector___closed__21 = _init_l_BBPSSW_bellVector___closed__21();
lean_mark_persistent(l_BBPSSW_bellVector___closed__21);
l_BBPSSW_bellVector___closed__22 = _init_l_BBPSSW_bellVector___closed__22();
lean_mark_persistent(l_BBPSSW_bellVector___closed__22);
l_BBPSSW_bellVector___closed__23 = _init_l_BBPSSW_bellVector___closed__23();
lean_mark_persistent(l_BBPSSW_bellVector___closed__23);
l_BBPSSW_bellVector___closed__24 = _init_l_BBPSSW_bellVector___closed__24();
lean_mark_persistent(l_BBPSSW_bellVector___closed__24);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
