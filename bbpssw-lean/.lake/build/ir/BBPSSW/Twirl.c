// Lean compiler output
// Module: BBPSSW.Twirl
// Imports: Init BBPSSW.Protocol
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
static lean_object* l_BBPSSW_cycleLabel___closed__4;
static lean_object* l_BBPSSW_cycleLabel___closed__1;
lean_object* l_Matrix_vecEmpty___boxed(lean_object*, lean_object*);
static lean_object* l_BBPSSW_cycleLabel___closed__3;
static lean_object* l_BBPSSW_cycleLabel___closed__2;
lean_object* l_Fin_cases(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BBPSSW_cycleLabel(lean_object*);
LEAN_EXPORT lean_object* l_BBPSSW_cycleLabel___boxed(lean_object*);
lean_object* l_Matrix_vecCons___rarg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* _init_l_BBPSSW_cycleLabel___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_Matrix_vecEmpty___boxed), 2, 1);
lean_closure_set(x_1, 0, lean_box(0));
return x_1;
}
}
static lean_object* _init_l_BBPSSW_cycleLabel___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = lean_unsigned_to_nat(1u);
x_3 = l_BBPSSW_cycleLabel___closed__1;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_cycleLabel___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = lean_unsigned_to_nat(3u);
x_3 = l_BBPSSW_cycleLabel___closed__2;
x_4 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_2);
lean_closure_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_BBPSSW_cycleLabel___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = l_BBPSSW_cycleLabel___closed__3;
x_3 = lean_alloc_closure((void*)(l_Matrix_vecCons___rarg___boxed), 4, 3);
lean_closure_set(x_3, 0, x_1);
lean_closure_set(x_3, 1, x_1);
lean_closure_set(x_3, 2, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_BBPSSW_cycleLabel(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_2 = lean_unsigned_to_nat(3u);
x_3 = lean_unsigned_to_nat(0u);
x_4 = l_BBPSSW_cycleLabel___closed__4;
x_5 = l_Fin_cases(x_2, lean_box(0), x_3, x_4, x_1);
return x_5;
}
}
LEAN_EXPORT lean_object* l_BBPSSW_cycleLabel___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l_BBPSSW_cycleLabel(x_1);
lean_dec(x_1);
return x_2;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_BBPSSW_Protocol(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_BBPSSW_Twirl(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_BBPSSW_Protocol(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_BBPSSW_cycleLabel___closed__1 = _init_l_BBPSSW_cycleLabel___closed__1();
lean_mark_persistent(l_BBPSSW_cycleLabel___closed__1);
l_BBPSSW_cycleLabel___closed__2 = _init_l_BBPSSW_cycleLabel___closed__2();
lean_mark_persistent(l_BBPSSW_cycleLabel___closed__2);
l_BBPSSW_cycleLabel___closed__3 = _init_l_BBPSSW_cycleLabel___closed__3();
lean_mark_persistent(l_BBPSSW_cycleLabel___closed__3);
l_BBPSSW_cycleLabel___closed__4 = _init_l_BBPSSW_cycleLabel___closed__4();
lean_mark_persistent(l_BBPSSW_cycleLabel___closed__4);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
