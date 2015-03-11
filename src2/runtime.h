#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef RUNTIME_H_
#define RUNTIME_H_

#define MLUNIT   1
#define MLBOOL   2
#define MLINT    3
#define MLDOUBLE 4
#define MLSTRING 5
#define MLPAIR   6
#define MLLIST   7
#define MLFUN    8

typedef struct _mlvalue_ {
  int type;
  union {
    int MLunit;
    int MLint;
    int MLbool;
    double MLdouble;
    char* MLstring;
    struct _mlpair_ {
      struct _mlvalue_ *MLfst, *MLsnd;
    } MLpair;
    struct _mllist_ {
      struct _mlvalue_ *MLcar;
      struct _mlvalue_ *MLcdr;
    } *MLlist;
    struct _mlfun_ {
      int counter;
      int nbparams;
      struct _mlvalue_** env;
      struct _mlvalue_ * (*invoke)(struct _mlvalue_ *, struct _mlvalue_ *);
    } MLfun;
  };
} MLvalue;


/***********************/
/******* Runtime *******/
/***********************/

// Constructors
MLvalue * new_MLint(int x);
MLvalue * new_MLdouble(double x);
MLvalue * new_MLbool(int b);
MLvalue * new_MLstring(char * s);
MLvalue * MLpair(MLvalue *x, MLvalue *y);
MLvalue * MLlist(MLvalue *x, MLvalue *y);
MLvalue * new_MLfun(MLvalue * f, int counter, MLvalue * (*invoke)(MLvalue *, MLvalue *));
void MLaddenv(MLvalue * f, MLvalue * p);
// init
void init();
// Booleens
MLvalue * MLtrue;
MLvalue * MLfalse;
// Unit
MLvalue * MLlrp;
// nil
MLvalue * MLnil;
//primitives
MLvalue * MLfst_real;
MLvalue * MLsnd_real;
MLvalue * MLhd_real;
MLvalue * MLtl_real;

// integer arithmetics
MLvalue * MLaddint(MLvalue * x, MLvalue * y);
MLvalue * MLsubint(MLvalue * x, MLvalue * y);
MLvalue * MLmulint(MLvalue * x, MLvalue * y);
MLvalue * MLdivint(MLvalue * x, MLvalue * y);
// equals
MLvalue * MLequal(MLvalue * x, MLvalue * y);
// integer comparisons
MLvalue * MLltint(MLvalue * x, MLvalue * y);
MLvalue * MLleint(MLvalue * x, MLvalue * y);
MLvalue * MLgtint(MLvalue * x, MLvalue * y);
MLvalue * MLgeint(MLvalue * x, MLvalue * y);
// string
MLvalue * MLconcat(MLvalue * x, MLvalue *  y);
// pair accessors
MLvalue * MLfst(MLvalue * p);
MLvalue * invoke_MLfst(MLvalue * f, MLvalue * p);
MLvalue * MLsnd(MLvalue * p);
MLvalue * invoke_MLsnd(MLvalue * f, MLvalue * p);
// list accessors
MLvalue * MLhd(MLvalue * l);
MLvalue * invoke_MLhd(MLvalue * f, MLvalue * p);
MLvalue * MLtl(MLvalue * l);
MLvalue * invoke_MLtl(MLvalue * f, MLvalue * p);
// print
MLvalue * MLprint(MLvalue * x);

#endif
