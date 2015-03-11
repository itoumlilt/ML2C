/**
 * ML2C - Runtime Implementation
 *
 * @author Ilyas Toumlilt <toumlilt.ilyas@gmail.com>
 * @copyright (c) 2015, toumlilt
 *
 * @version 1.0
 * @package toumlilt/M1/ML2C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <runtime.h>

/*******************************************************************************
 * Private Declarations
 ******************************************************************************/
MLvalue* MLprintRecursive(MLvalue* v);

/*******************************************************************************
 * Constructors
 ******************************************************************************/
MLvalue* newMLint(int v)
{
  MLvalue* r = (MLvalue*)malloc5
  r->MLint   = x;
  return r;
}

MLvalue* newMLdouble(double v)
{
  MLvalue* r  = (MLvalue*)malloc(sizeof(MLvalue));
  r->type     = MLdouble;
  r->MLdouble = v;
  return r;
}

MLvalue* newMLbool(int v)
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLbool;
  r->MLbool  = v;
  return r;
}

MLvalue* newMLstring(char* s)
{
  MLvalue* r  = (MLvalue*)malloc(sizeof(MLvalue));
  r->type     = MLstring;
  r->MLstring = s;
  return r;
}

MLvalue* newMLfun(MLvalue *f, int c, MLvalue* (*invoke)(MLvalue*, MLvalue*))
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLfun;
  int i;
  if(f){
    r->MLfun.nbparams = f->MLfun.nb.params;
    r->MLfun.counter  = c;
    r->MLfun.env      = (MLvalue**)malloc(sizeof(MLvalue*));
    for(i=0; i<c; i++)
      r->MLfun.env[i] = NULL;
    if(f->MLfun.env)
      memcpy(r->MLfun.env, f->MLfun.env,
	     f->MLfun.counter*(sizeof(MLvalue)));
    r->MLfun.invoke = f->MLfun.invoke;
  } else {
    r->MLfun.nbparams = counter;
    r->MLfun.counter  = 0;
    r->MLfun.env      = NULL;
    r->MLfun.invoke   = invoke;
  }
  return r;
}

MLvalue* newMLpair(MLvalue* n1, MLvalue* n2)
{
  MLvalue* r      = (MLvalue*)malloc(sizeof(MLvalue));
  r->type         = MLPAIR;
  r->MLpair.MLfst = n1;
  r->MLpair.MLsnd = n2;
  return r;
}

MLvalue* newMLlist(MLvalue* v, MLvalue* l)
{
  MLvalue* r       = (MLvalue*)malloc(sizeof(MLvalue));
  r->type          = MLlist;
  r->MLlist        = (MLList*)malloc(sizeof(MLList));
  r->MLlist->MLcar = v;
  r->MLlist->MLcdr = l;
  return r;
}

/*******************************************************************************
 * Basic Operations
 ******************************************************************************/
MLvalue* MLaddint(MLvalue* x, MLvalue* y)
{
  MLvalue *r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLINT;
  r->MLint   = (x->MLint) + (y->MLint);
  return r;
}

MLvalue* MLsubint(MLvalue* x, MLvalue* y)
{
  MLvalue *r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLINT;
  r->MLint   = (x->MLint) - (y->MLint);
  return r;
}

MLvalue* MLmulint(MLvalue* x, MLvalue* y)
{
  MLvalue *r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLINT;
  r->MLint   = (x->MLint) * (y->MLint);
  return r;
}

MLvalue* MLdivint(MLvalue* x, MLvalue* y)
{
  MLvalue *r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLINT;
  r->MLint   = (x->MLint) / (y->MLint);
  return r;
}

/*******************************************************************************
 * Comparison Operations
 ******************************************************************************/
MLvalue* MLequal(MLvalue* a, MLvalue* b)
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLBOOL;
  switch( a->type ){
  case MLINT :
    r->MLbool = (a->MLint) == (b->MLint);
    break;
  case MLBOOL :
    r->MLbool = (a->MLbool) == (b->MLbool);
    break;
  case MLDOUBLE :
    r->MLbool = (a->MLdouble) == (b->MLdouble);
    break;
  case MLSTRING :
    r->MLbool = (strcmp(a->MLstring, b->MLstring) == 0);
    break;
  case MLPAIR :
    MLvalue* fst = MLequal(a->MLpair.MLfst, y->MLpair.MLfst);
    MLvalue* snd = MLequal(a->MLpair.MLsnd, y->MLpair.MLsnd);
    r->MLbool = fst->MLbool && snd->MLbool;
    free(fst);
    free(snd);
    break;
  case MLLIST :
    if(!a->MLlist && !b->MLlist ){
      r->MLbool = 1;
      return r;
    }
    else if(!a->MLlist || !b->MLlist){
      r->MLbool = 0;
      return r;
    }
    else {
      MLvalue* v1 = MLequal(a->MLlist->MLcar, b->MLlist->MLcar);
      MLvalue* v2 = MLequal(a->MLlist->MLcdr, b->MLlist->MLcdr);
      r->MLbool = v1->MLbool && v2->MLbool;
      free(v1);
      free(v2);
    }
    break;
  default: break;
  }
  else {
    r->MLbool = (a->type == MLUNIT && b->type == MLUNIT);
  }
  return r;
}

MLvalue* MLltint(MLvalue *a, MLvalue *b)
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLBOOL;
  r->MLbool  = (a->MLint) < (b->MLint);
  return r;
}

MLvalue* MLleint(MLvalue *a, MLvalue *b)
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLBOOL;
  r->MLbool  = (a->MLint) <= (b->MLint);
  return r;
}

MLvalue* MLgtint(MLvalue *a, MLvalue *b)
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLBOOL;
  r->MLbool  = (a->MLint) > (b->MLint);
  return r;
}

MLvalue* MLgeint(MLvalue *a, MLvalue *b)
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLBOOL;
  r->MLbool  = (a->MLint) >= (b->MLint);
  return r;
}

/*******************************************************************************
 * String Operations
 ******************************************************************************/
MLvalue* MLconcat(MLvalue* a, MLvalue* b)
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  char* s = malloc((strlen(a->MLstring)+strlen(b->MLstring)+1*sizeof(char)));
  int i, len = strlen(a->MLstring);
  for(i=0; a->MLstring[i]!='\0'; i++)
    s[i] = a->MLstring[i];
  for(i=0; b->MLstring[i]!='\0'; i++)
    s[i+len] = b->MLstring[i];
  r->type     = MLSTRING;
  r->MLstring = s;
  return r;
}

/*******************************************************************************
 * Accessors
 ******************************************************************************/
MLvalue* MLpairGetFst(MLvalue* v)
{
  return v->MLpair.MLfst;
}

MLvalue* MLpairGetSnd(MLvalue* v)
{
  return v->MLpair.MLsnd;
}

MLvalue* MLlistGetCar(MLvalue* v)
{
  return v->MLlist->MLcar;
}

MLvalue* MLlistGetCdr(MLvalue* v)
{
  return v->MLlist->MLcdr;
}

/*******************************************************************************
 * Print Operations
 ******************************************************************************/
MLvalue* MLprintRecursive(MLvalue* v)
{
  int i;
  switch( v->type )
    {
    case MLUNIT :
      printf("()");
      break;
    case MLBOOL :
      printf("%s", v->MLbool ? "true" : "false");
      break;
    case MLINT :
      printf("%d", v->MLint);
      break;
    case MLDOUBLE :
      printf("%f", v->MLdouble);
      break;
    case MLSTRING :
      printf("\"%s\"", v->MLstring);
      break;
    case MLPAIR :
      printf("(");
      MLprintRecursive(v->MLpair.MLfst);
      printf(",");
      MLprintRecursive(v->MLpair.MLsnd);
      printf(")");
      break;
    case MLLIST :
      if( v->MLlist ){
	MLprintRecursive(v->MLlist->MLcar);
	printf("::");
	MLprintRecursive(v->MLlist->MLcdr);
      } else {
	printf("[]");
      }
      break;
    default :
      printf("<fun> [");
      for(i=0; i<v->MLfun.counter; i++)
	MLprintRecursive(v->MLfun.env[i]);
      printf("]");
      break;
    }
  return MLlrp;
}

MLvalue* MLprint(MLvalue* v)
{
  MLprintRecursive(v);
  printf("\n");
  return MLlrp;
}

/*******************************************************************************
 * Env Operations
 ******************************************************************************/
void MLaddenv(MLvalue* f, MLvalue* v)
{
  int i;
  for(i=0; f->MLfun.env[i]; i++);
  f->MLfun.env[i] = v;
}

/*******************************************************************************
 * Invoke Operations
 ******************************************************************************/
MLvalue* invokeMLfst(MLvalue * f, MLvalue * p)
{
  return MLfst(p);
}
MLvalue* invokeMLsnd(MLvalue * f, MLvalue * p)
{
  return MLsnd(p);
}
MLvalue* invokeMLhd(MLvalue * f, MLvalue * p)
{
  return MLhd(p);
}
MLvalue* invokeMLtl(MLvalue * f, MLvalue * p)
{
  return MLtl(p);
}

/*******************************************************************************
 * Main Setup Operations
 ******************************************************************************/
void init()
{
  /* initialisation des constantes */
  MLtrue         = (MLvalue*)malloc(sizeof(MLvalue));
  MLtrue->type   = MLbool;
  MLtrue->MLbool = 1;

  MLfalse        = (MLvalue*)malloc(sizeof(MLvalue));
  MLfalse->type  = MLbool;
  MLfalse->MLbool= 0;
  
  MLlrp       = (MLvalue*)malloc(sizeof(MLvalue));
  MLlrp->type = MLUNIT;

  MLnil         = (MLvalue*)malloc(sizeof(MLvalue));
  MLnil->type   = MLLIST;
  MLnil->MLlist = NULL;

  MLfstPrimary              = malloc(sizeof(MLvalue));
  MLfstPrimary->type        = MLFUN;
  MLfstPrimary->MLfun.invoke= invoke_MLfst; 

  MLsndPrimary              = malloc(sizeof(MLvalue));
  MLsndPrimary->type        = MLFUN;
  MLsndPrimary->MLfun.invoke= invoke_MLsnd;

  MLhdPrimary               = malloc(sizeof(MLvalue));
  MLhdPrimary->type         = MLFUN;
  MLhdPrimary->MLfun.invoke = invoke_MLhd;

  MLtlPrimary               = malloc(sizeof(MLvalue));
  MLtlPrimary->type         = MLFUN;
  MLtlPrimary->MLfun.invoke = invoke_MLtl;
}
