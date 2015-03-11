/**
 * ML2C - Runtime Header
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
  int type; /* takes a value from defines above */
  union {   /* value's content */
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
/* all returns MLint */
MLvalue* MLaddint(MLvalue* x, MLvalue* y); /* addition       */
MLvalue* MLsubint(MLvalue* x, MLvalue* y); /* soustraction   */
MLvalue* MLmulint(MLvalue* x, MLvalue* y); /* multiplication */
MLvalue* MLdivint(MLvalue* x, MLvalue* y); /* division       */

/*******************************************************************************
 * Comparison Operations
 ******************************************************************************/
/* all retunrs MLbool */
MLvalue* MLequal(MLvalue* a, MLvalue* b); /* a =  b ? */
MLvalue* MLltint(MLvalue* a, MLvalue* b); /* a <  b ? */
MLvalue* MLleint(MLvalue* a, MLvalue* b); /* a <= b ? */
MLvalue* MLgtint(MLvalue* a, MLvalue* b); /* a >  b ? */
MLvalue* MLgeint(MLvalue* a, MLvalue* b); /* a >= b ? */

/*******************************************************************************
 * String Operations
 ******************************************************************************/
/**
 * Concatenate two strings
 *
 * @param a first string ( MLstring )
 * @param b second string ( MLstring )
 * @return Mlvalue the concatenated string ( MLstring )
 */
MLvalue* MLconcat(MLvalue* a, MLvalue* b);

/*******************************************************************************
 * Accessors
 ******************************************************************************/
/**
 * MLpair's first element getter 
 *
 * @param v ( MLpair )
 * @return MLvalue* first element of the pair 
 */
MLvalue* MLpairGetFst(MLvalue* v);

/**
 * MLpair's second element getter
 *
 * @param v ( MLpair )
 * @return MLvalue* second element of the pair
 */
MLvalue* MLpairGetSnd(MLvalue* v);

/**
 * MLlist's head getter
 *
 * @param v ( MLlist )
 * @return MLvalue* head of the list
 */
MLvalue* MLlistGetCar(MLvalue* v);

/**
 * MLlist's cdr getter
 *
 * @param v ( MLlist )
 * @return MLvalue* cdr of the list ( MLlist )
 */
MLvalue* MLlistGetCdr(MLvalue* v);

/*******************************************************************************
 * Print Operations
 ******************************************************************************/
/**
 * print value's content on STDOUT
 *
 * @param v the MLvalue to print
 * @return MLValue* the MLclr constant
 */ 
MLvalue* MLprint(MLvalue* v);

/*******************************************************************************
 * Env Operations
 ******************************************************************************/
/**
 * Add's a value to an environment
 *
 * @param f function's environment ( MLfun )
 * @param v the value to add 
 */
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
