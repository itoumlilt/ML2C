/**
 * ML2C - Runtime Implementation
 *
 * @author Ilyas Toumlilt <toumlilt.ilyas@gmail.com>
 * @copyright (c) 2015, toumlilt
 *
 * @version 1.0
 * @package toumlilt/M1/ML2C
 */

#ifndef __RUNTIME_H_
#define __RUNTIME_H_

/*******************************************************************************
 * Types Definition
 ******************************************************************************/
#define MLUNIT   1
#define MLBOOL   2
#define MLINT    3
#define MLDOUBLE 4
#define MLSTRING 5
#define MLPAIR   6
#define MLLIST   7
#define MLFUN    8

/*******************************************************************************
 * Main Struct
 ******************************************************************************/
typedef struct _MLvalue MLvalue;
typedef struct _MLfun   MLFun;
typedef struct _MLlist  MLList;
typedef struct _MLfun   MLFun;

struct _MLvalue {
  int type;
  union {
    int MLunit;
    int MLint;
    int MLbool;
    double MLdouble;
    char* MLstring;
    struct _MLpair {
      MLvalue *MLfst, *MLsnd;
    } MLpair;
    struct _MLlist {
      MLvalue *MLcar;
      MLvalue *MLcdr;
    } *MLlist;
    struct _MLfun {
      int counter;
      int nbparams;
      MLvalue** env;
      MLvalue* (*invoke)(MLvalue*, MLvalue*);
    } MLfun;
  };
};

/*******************************************************************************
 * Global Constants
 ******************************************************************************/
/* Booleens */
MLvalue* MLtrue;
MLvalue* MLfalse;
/* Unit */
MLvalue* MLlrp;
/* nil */
MLvalue* MLnil;
/* Primitives */
MLvalue* MLfstPrimary;
MLvalue* MLsndPrimary;
MLvalue* MLhdPrimary;
MLvalue* MLtlPrimary;

/*******************************************************************************
 * Constructors
 ******************************************************************************/
MLvalue* newMLint(int v);
MLvalue* newMLdouble(double v);
MLvalue* newMLbool(int v);
MLvalue* newMLstring(char* s);
MLvalue* newMLfun(MLvalue *f, int c, MLvalue* (*invoke)(MLvalue*, MLvalue*));
MLvalue* newMLpair(MLvalue* n1, MLvalue* n2);
MLvalue* newMLlist(MLvalue* v, MLvalue* l);

/*******************************************************************************
 * Basic Operations
 ******************************************************************************/
MLvalue* MLaddint(MLvalue* x, MLvalue* y);
MLvalue* MLsubint(MLvalue* x, MLvalue* y);
MLvalue* MLmulint(MLvalue* x, MLvalue* y);
MLvalue* MLdivint(MLvalue* x, MLvalue* y);

/*******************************************************************************
 * Comparison Operations
 ******************************************************************************/
MLvalue* MLequal(MLvalue* a, MLvalue* b);
MLvalue* MLltint(MLvalue *a, MLvalue *b);
MLvalue* MLleint(MLvalue *a, MLvalue *b);
MLvalue* MLgtint(MLvalue *a, MLvalue *b);
MLvalue* MLgeint(MLvalue *a, MLvalue *b);

/*******************************************************************************
 * String Operations
 ******************************************************************************/
MLvalue* MLconcat(MLvalue* a, MLvalue* b);

/*******************************************************************************
 * Accessors
 ******************************************************************************/
MLvalue* MLpairGetFst(MLvalue* v);
MLvalue* MLpairGetSnd(MLvalue* v);
MLvalue* MLlistGetCar(MLvalue* v);
MLvalue* MLlistGetCdr(MLvalue* v);

/*******************************************************************************
 * Print Operations
 ******************************************************************************/
MLvalue* MLprint(MLvalue* v);

/*******************************************************************************
 * Env Operations
 ******************************************************************************/
void MLaddenv(MLvalue* f, MLvalue* v);

/*******************************************************************************
 * Invoke Operations
 ******************************************************************************/
MLvalue* invokeMLfst(MLvalue * f, MLvalue * p);
MLvalue* invokeMLsnd(MLvalue * f, MLvalue * p);
MLvalue* invokeMLhd(MLvalue * f, MLvalue * p);
MLvalue* invokeMLtl(MLvalue * f, MLvalue * p);

/*******************************************************************************
 * Main Setup Operations
 ******************************************************************************/
void init();



#endif
