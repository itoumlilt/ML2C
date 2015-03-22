/**
 * ML2C - Runtime Implementation
 *
 * @author Ilyas Toumlilt <toumlilt.ilyas@gmail.com>
 * @copyright (c) 2015, toumlilt
 *
 * @version 1.0
 * @package toumlilt/M1/ML2C
 */


#include "runtime.h"

/*******************************************************************************
 * Private Declarations
 ******************************************************************************/
MLvalue* MLprintRecursive(MLvalue* v);

/*******************************************************************************
 * Constructors
 ******************************************************************************/
MLvalue* newMLint(int v)
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLINT;
  r->MLint   = v;
  return r;
}

MLvalue* newMLdouble(double v)
{
  MLvalue* r  = (MLvalue*)malloc(sizeof(MLvalue));
  r->type     = MLDOUBLE;
  r->MLdouble = v;
  return r;
}

MLvalue* newMLbool(int v)
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLBOOL;
  r->MLbool  = v;
  return r;
}

MLvalue* newMLstring(char* s)
{
  MLvalue* r  = (MLvalue*)malloc(sizeof(MLvalue));
  r->type     = MLSTRING;
  r->MLstring = s;
  return r;
}

MLvalue* newMLfun(MLvalue *f, int c, MLvalue* (*invoke)(MLvalue*, MLvalue*))
{
  MLvalue* r = (MLvalue*)malloc(sizeof(MLvalue));
  r->type    = MLFUN;
  int i;
  if(f){
    r->MLfun.nbparams = f->MLfun.nbparams;
    r->MLfun.counter  = c;
    r->MLfun.env      = (MLvalue**)malloc(sizeof(MLvalue*));
    for(i=0; i<c; i++)
      r->MLfun.env[i] = NULL;
    if(f->MLfun.env)
      memcpy(r->MLfun.env, f->MLfun.env,
	     f->MLfun.counter*(sizeof(MLvalue)));
    r->MLfun.invoke = f->MLfun.invoke;
  } else {
    r->MLfun.nbparams = c;
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
  r->type          = MLLIST;
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
  MLvalue *v1, *v2; /* for some cool usage */
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
    v1 = MLequal(a->MLpair.MLfst, b->MLpair.MLfst);
    v2 = MLequal(a->MLpair.MLsnd, b->MLpair.MLsnd);
    r->MLbool = v1->MLbool && v2->MLbool;
    free(v1);
    free(v2);
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
      v1 = MLequal(a->MLlist->MLcar, b->MLlist->MLcar);
      v2 = MLequal(a->MLlist->MLcdr, b->MLlist->MLcdr);
      r->MLbool = v1->MLbool && v2->MLbool;
      free(v1);
      free(v2);
    }
    break;
  default: 
    r->MLbool = (a->type == MLUNIT && b->type == MLUNIT);
    break;
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
  return MLpairGetFst(p);
}
MLvalue* invokeMLsnd(MLvalue * f, MLvalue * p)
{
  return MLpairGetSnd(p);
}
MLvalue* invokeMLhd(MLvalue * f, MLvalue * p)
{
  return MLlistGetCar(p);
}
MLvalue* invokeMLtl(MLvalue * f, MLvalue * p)
{
  return MLlistGetCdr(p);
}

/*******************************************************************************
 * Main Setup Operations
 ******************************************************************************/
void init()
{
  /* initialisation des constantes */
  MLtrue         = (MLvalue*)malloc(sizeof(MLvalue));
  MLtrue->type   = MLBOOL;
  MLtrue->MLbool = 1;

  MLfalse        = (MLvalue*)malloc(sizeof(MLvalue));
  MLfalse->type  = MLBOOL;
  MLfalse->MLbool= 0;
  
  MLlrp       = (MLvalue*)malloc(sizeof(MLvalue));
  MLlrp->type = MLUNIT;

  MLnil         = (MLvalue*)malloc(sizeof(MLvalue));
  MLnil->type   = MLLIST;
  MLnil->MLlist = NULL;

  MLfstPrimary              = malloc(sizeof(MLvalue));
  MLfstPrimary->type        = MLFUN;
  MLfstPrimary->MLfun.invoke= invokeMLfst; 

  MLsndPrimary              = malloc(sizeof(MLvalue));
  MLsndPrimary->type        = MLFUN;
  MLsndPrimary->MLfun.invoke= invokeMLsnd;

  MLhdPrimary               = malloc(sizeof(MLvalue));
  MLhdPrimary->type         = MLFUN;
  MLhdPrimary->MLfun.invoke = invokeMLhd;

  MLtlPrimary               = malloc(sizeof(MLvalue));
  MLtlPrimary->type         = MLFUN;
  MLtlPrimary->MLfun.invoke = invokeMLtl;
}
