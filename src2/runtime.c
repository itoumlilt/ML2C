#include "runtime.h"


MLvalue * new_MLint(int x){
  MLvalue * n = malloc(sizeof(MLvalue));
  n->type=MLINT;
  n->MLint=x;
  return n;
}

MLvalue * new_MLdouble(double x){
  MLvalue * n = malloc(sizeof(MLvalue));
  n->type=MLDOUBLE;
  n->MLdouble=x;
  return n;
}

MLvalue * new_MLbool(int b){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type=MLBOOL;
  m->MLbool=b;
  return m;
}

MLvalue * new_MLstring(char *s){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type=MLSTRING;
  m->MLstring=s;
  return m;
}

MLvalue * new_MLfun(MLvalue * f, int counter, MLvalue * (*invoke)(MLvalue *, MLvalue *)){
  MLvalue * ff = malloc(sizeof(MLvalue));
  int i;
  ff->type=MLFUN;
  if(f){
    ff->MLfun.nbparams=f->MLfun.nbparams;
    ff->MLfun.counter=counter;
    ff->MLfun.env=malloc(counter*sizeof(MLvalue *));
    for(i=0;i<counter;i++){
      ff->MLfun.env[i]=NULL;
    }
    if(f->MLfun.env){
      memcpy(ff->MLfun.env,f->MLfun.env,f->MLfun.counter*(sizeof(MLvalue)));
    }
    ff->MLfun.invoke=f->MLfun.invoke;
  }else{
    ff->MLfun.nbparams=counter;
    ff->MLfun.counter=0;
    ff->MLfun.env=NULL;
    ff->MLfun.invoke=invoke;
  }
  return ff;
}

void MLaddenv(MLvalue * f, MLvalue * p){
  int i;
  for(i=0;f->MLfun.env[i]!=NULL;i++);
  f->MLfun.env[i]=p;
}

MLvalue * MLpair(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type=MLPAIR;
  m->MLpair.MLfst=x;
  m->MLpair.MLsnd=y;
  return m;
}

MLvalue * MLlist(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type=MLLIST;
  m->MLlist=malloc(sizeof(struct _mllist_));
  m->MLlist->MLcar=x;
  m->MLlist->MLcdr=y;
  return m;
}

MLvalue * MLaddint(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type = MLINT;
  m->MLint = (x->MLint)+(y->MLint);
  return m;
}

MLvalue * MLsubint(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type = MLINT;
  m->MLint = x->MLint-y->MLint;
  return m;
}

MLvalue * MLmulint(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type = MLINT;
  m->MLint = x->MLint*y->MLint;
  return m;
}

MLvalue * MLdivint(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type = MLINT;
  m->MLint = x->MLint/y->MLint;
  return m;
}

MLvalue * MLequal(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type = MLBOOL;
  if(x->type==MLINT){
    m->MLbool=(x->MLint)==(y->MLint);
  }else if(x->type==MLBOOL){
    m->MLbool=(x->MLbool)==(y->MLbool);
  }else if(x->type==MLDOUBLE){
    m->MLbool=(x->MLdouble)==(y->MLdouble);
  }else if(x->type==MLSTRING){
    m->MLbool=(strcmp(x->MLstring,y->MLstring)==0);
  }else if(x->type==MLPAIR){
    MLvalue * v1=MLequal(x->MLpair.MLfst,y->MLpair.MLfst);
    MLvalue * v2=MLequal(x->MLpair.MLsnd,y->MLpair.MLsnd);
    m->MLbool = v1->MLbool && v2->MLbool;
    free(v1);
    free(v2); 
  }else if (x->type==MLLIST){
    if((x->MLlist == NULL) && (y->MLlist==NULL)){
      m->MLbool=1;
      return m;
    }else if ((x->MLlist == NULL) || (y->MLlist==NULL)){
      m->MLbool=0;
      return m;
    }else{
      MLvalue * v1=MLequal(x->MLlist->MLcar, y->MLlist->MLcar);
      MLvalue * v2=MLequal(x->MLlist->MLcdr, y->MLlist->MLcdr);
      m->MLbool = v1->MLbool && v2->MLbool;
      free(v1);
      free(v2); 
    }
  } else {
    m->MLbool=(x->type==MLUNIT) && (y->type==MLUNIT);
  }
  return m;
}

MLvalue * MLltint(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type = MLBOOL;
  m->MLbool = (x->MLint)<(y->MLint);
  return m;
}

MLvalue * MLleint(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type = MLBOOL;
  m->MLbool = (x->MLint)<=(y->MLint);
  return m;

}

MLvalue * MLgtint(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type = MLBOOL;
  m->MLbool = (x->MLint)>(y->MLint);
  return m;
}

MLvalue * MLgeint(MLvalue *x, MLvalue *y){
  MLvalue * m = malloc(sizeof(MLvalue));
  m->type = MLBOOL;
  m->MLbool = (x->MLint)>=(y->MLint);
  return m;
}

MLvalue * MLconcat(MLvalue * x, MLvalue * y){
  MLvalue * m = malloc(sizeof(MLvalue));
  char * s = malloc((strlen(x->MLstring)+strlen(y->MLstring)+1)*sizeof(char));
  int i, len = strlen(x->MLstring);
  for(i=0;x->MLstring[i]!='\0';i++){
    s[i]=x->MLstring[i];
  }
  for(i=0;y->MLstring[i]!='\0';i++){
    s[i+len]=y->MLstring[i];
  }
  m->type=MLSTRING;
  m->MLstring=s;
  return m;
}

MLvalue * MLfst(MLvalue * p){
  return p->MLpair.MLfst;
}

MLvalue * MLsnd(MLvalue * p){
  return p->MLpair.MLsnd;
}

MLvalue * MLhd(MLvalue * l){
  return l->MLlist->MLcar;
}

MLvalue * MLtl(MLvalue * l){
  return l->MLlist->MLcdr;
}

MLvalue * MLprint_rec(MLvalue * x){
  int i;
  if(x->type==MLUNIT){
    printf("()");
  }else if(x->type==MLBOOL){
    printf("%s", x->MLbool ? "true" : "false");
  }else if(x->type==MLINT){
    printf("%d",x->MLint);
  }else if(x->type==MLDOUBLE){
    printf("%f",x->MLdouble);
  }else if(x->type==MLSTRING){
    printf("\"%s\"",x->MLstring);
  }else if(x->type==MLPAIR){
    printf("(");
    MLprint_rec(x->MLpair.MLfst);
    printf(",");
    MLprint_rec(x->MLpair.MLsnd);
    printf(")");
  }else if(x->type==MLLIST){
    if(x->MLlist){
      MLprint_rec(x->MLlist->MLcar);
      printf("::");
      MLprint_rec(x->MLlist->MLcdr);
    }else{
      printf("[]");
    }
  }else{
    printf("<fun> [");
    for(i=0;i<(x->MLfun.counter);i++){
      MLprint_rec(x->MLfun.env[i]);
    }
    printf("]");
  }
  return MLlrp;
}
MLvalue * MLprint(MLvalue * x){
  MLprint_rec(x);
  printf("\n");
  return MLlrp;
}
void init(){
  MLtrue=malloc(sizeof(MLvalue));
  MLtrue->type=MLBOOL;
  MLtrue->MLbool=1;

  MLfalse=malloc(sizeof(MLvalue));
  MLfalse->type=MLBOOL;
  MLfalse->MLbool=0;

  MLlrp=malloc(sizeof(MLvalue));
  MLlrp->type=MLUNIT;

  MLnil=malloc(sizeof(MLvalue));
  MLnil->type=MLLIST;
  MLnil->MLlist=NULL;

  MLfst_real=malloc(sizeof(MLvalue));
  MLfst_real->type=MLFUN;
  MLfst_real->MLfun.invoke=invoke_MLfst; 

  MLsnd_real=malloc(sizeof(MLvalue));
  MLsnd_real->type=MLFUN;
  MLsnd_real->MLfun.invoke=invoke_MLsnd;

  MLhd_real=malloc(sizeof(MLvalue));
  MLhd_real->type=MLFUN;
  MLhd_real->MLfun.invoke=invoke_MLhd;

  MLtl_real=malloc(sizeof(MLvalue));
  MLtl_real->type=MLFUN;
  MLtl_real->MLfun.invoke=invoke_MLtl;
}

MLvalue * invoke_MLfst(MLvalue * f, MLvalue * p){
  return MLfst(p);
}
MLvalue * invoke_MLsnd(MLvalue * f, MLvalue * p){
  return MLsnd(p);
}
MLvalue * invoke_MLhd(MLvalue * f, MLvalue * p){
  return MLhd(p);
}
MLvalue * invoke_MLtl(MLvalue * f, MLvalue * p){
  return MLtl(p);
}
