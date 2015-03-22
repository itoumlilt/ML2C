/**
 *  ftest.c produced by ml2c 
 */
#include "runtime.h"

  MLvalue* null___1;
  MLvalue* g___8;
  MLvalue* h___12;
  MLvalue* q___17;
  MLvalue* v___25;
  MLvalue* w___27;
  MLvalue* map___37;
  MLvalue* iter___57;
  MLvalue* inter___71;
  MLvalue* mult___87;
  MLvalue* i___92;
  MLvalue* l___98;
  MLvalue* fd___106;
  MLvalue* ig___108;
  MLvalue* bi___114;
  MLvalue* ik___118;
  MLvalue* b___122;
  MLvalue* umap___126;
  MLvalue* value___146;

/**
 *  de'claration de la fonction null___1
 *    vue comme la classe : MLfun_null___1
 */ 


  MLvalue* invoke_real_MLfun_null___1(MLvalue* l___2) {

    { 
      MLvalue* T___3;
      { 
        MLvalue* T___4;
        MLvalue* T___5;
        T___4=l___2;
        T___5=MLnil;
        T___3=MLequal( (MLvalue* )T___4,(MLvalue* )T___5);
      }
      if ((T___3)->MLbool)
        { 
          MLvalue* T___6;
          T___6=MLtrue;
          return T___6;
        }
      else
        { 
          MLvalue* T___7;
          T___7=MLfalse;
          return T___7;
        }
    }
  }

  MLvalue* invoke_MLfun_null___1(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_null___1(MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_null___1


/**
 *  de'claration de la fonction g___8
 *    vue comme la classe : MLfun_g___8
 */ 


  MLvalue* invoke_real_MLfun_g___8(MLvalue* x___9) {

    { 
      MLvalue* T___10;
      MLvalue* T___11;
      T___10=x___9;
      T___11=MLnil;
      return MLequal( (MLvalue* )T___10,(MLvalue* )T___11);
    }
  }

  MLvalue* invoke_MLfun_g___8(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_g___8(MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_g___8


/**
 *  de'claration de la fonction h___12
 *    vue comme la classe : MLfun_h___12
 */ 


  MLvalue* invoke_real_MLfun_h___12(MLvalue* x___13, MLvalue* y___14) {

    { 
      MLvalue* T___15;
      MLvalue* T___16;
      T___15=x___13;
      T___16=y___14;
      return newMLlist( (MLvalue* )T___15,(MLvalue* )T___16);
    }
  }

  MLvalue* invoke_MLfun_h___12(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_h___12(f->MLfun.env[0], MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_h___12


/**
 *  de'claration de la fonction q___17
 *    vue comme la classe : MLfun_q___17
 */ 


  MLvalue* invoke_real_MLfun_q___17(MLvalue* x___18) {

    { 
      MLvalue* T___19;
      MLvalue* T___22;
      { 
        MLvalue* T___20;
        MLvalue* T___21;
        T___20=MLhdPrimary;
        T___21=x___18;
        T___19=(T___20)->MLfun.invoke(T___20, T___21);
      }
      { 
        MLvalue* T___23;
        MLvalue* T___24;
        T___23=MLtlPrimary;
        T___24=x___18;
        T___22=(T___23)->MLfun.invoke(T___23, T___24);
      }
      return newMLpair( (MLvalue* )T___19,(MLvalue* )T___22);
    }
  }

  MLvalue* invoke_MLfun_q___17(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_q___17(MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_q___17


/**
 *  de'claration de la fonction v___25
 *    vue comme la classe : MLfun_v___25
 */ 


  MLvalue* invoke_real_MLfun_v___25(MLvalue* x___26) {

    return MLnil;
  }

  MLvalue* invoke_MLfun_v___25(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_v___25(MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_v___25


/**
 *  de'claration de la fonction w___27
 *    vue comme la classe : MLfun_w___27
 */ 


  MLvalue* invoke_real_MLfun_w___27(MLvalue* l___28, MLvalue* x___29) {

    { 
      MLvalue* T___30;
      { 
        MLvalue* T___31;
        MLvalue* T___32;
        T___31=l___28;
        T___32=MLnil;
        T___30=MLequal( (MLvalue* )T___31,(MLvalue* )T___32);
      }
      if ((T___30)->MLbool)
        { 
          MLvalue* T___33;
          T___33=MLnil;
          return T___33;
        }
      else
        { 
          MLvalue* T___34;
          { 
            MLvalue* T___35;
            MLvalue* T___36;
            T___35=x___29;
            T___36=MLnil;
            T___34=newMLlist( (MLvalue* )T___35,(MLvalue* )T___36);
          }
          return T___34;
        }
    }
  }

  MLvalue* invoke_MLfun_w___27(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_w___27(f->MLfun.env[0], MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_w___27


/**
 *  de'claration de la fonction map___37
 *    vue comme la classe : MLfun_map___37
 */ 


  MLvalue* invoke_real_MLfun_map___37(MLvalue* f___38, MLvalue* l___39) {

    { 
      MLvalue* T___40;
      { 
        MLvalue* T___41;
        MLvalue* T___42;
        T___41=null___1;
        T___42=l___39;
        T___40=(T___41)->MLfun.invoke(T___41, T___42);
      }
      if ((T___40)->MLbool)
        { 
          MLvalue* T___43;
          T___43=MLnil;
          return T___43;
        }
      else
        { 
          MLvalue* T___44;
          { 
            MLvalue* T___45;
            MLvalue* T___50;
            { 
              MLvalue* T___46;
              MLvalue* T___47;
              T___46=f___38;
              { 
                MLvalue* T___48;
                MLvalue* T___49;
                T___48=MLhdPrimary;
                T___49=l___39;
                T___47=(T___48)->MLfun.invoke(T___48, T___49);
              }
              T___45=(T___46)->MLfun.invoke(T___46, T___47);
            }
            { 
              MLvalue* T___51;
              MLvalue* T___54;
              { 
                MLvalue* T___52;
                MLvalue* T___53;
                T___52=map___37;
                T___53=f___38;
                T___51=(T___52)->MLfun.invoke(T___52, T___53);
              }
              { 
                MLvalue* T___55;
                MLvalue* T___56;
                T___55=MLtlPrimary;
                T___56=l___39;
                T___54=(T___55)->MLfun.invoke(T___55, T___56);
              }
              T___50=(T___51)->MLfun.invoke(T___51, T___54);
            }
            T___44=newMLlist( (MLvalue* )T___45,(MLvalue* )T___50);
          }
          return T___44;
        }
    }
  }

  MLvalue* invoke_MLfun_map___37(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_map___37(f->MLfun.env[0], MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_map___37


/**
 *  de'claration de la fonction iter___57
 *    vue comme la classe : MLfun_iter___57
 */ 


  MLvalue* invoke_real_MLfun_iter___57(MLvalue* f___58, MLvalue* l___59) {

    { 
      MLvalue* T___60;
      { 
        MLvalue* T___61;
        MLvalue* T___62;
        T___61=null___1;
        T___62=l___59;
        T___60=(T___61)->MLfun.invoke(T___61, T___62);
      }
      if ((T___60)->MLbool)
        { 
          MLvalue* T___63;
          T___63=MLnil;
          return T___63;
        }
      else
        { 
          MLvalue* T___64;
          { 
            MLvalue* T___65;
            MLvalue* T___66;
            T___65=iter___57;
            { 
              MLvalue* T___67;
              MLvalue* T___68;
              T___67=f___58;
              { 
                MLvalue* T___69;
                MLvalue* T___70;
                T___69=MLtlPrimary;
                T___70=l___59;
                T___68=(T___69)->MLfun.invoke(T___69, T___70);
              }
              T___66=(T___67)->MLfun.invoke(T___67, T___68);
            }
            T___64=(T___65)->MLfun.invoke(T___65, T___66);
          }
          return T___64;
        }
    }
  }

  MLvalue* invoke_MLfun_iter___57(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_iter___57(f->MLfun.env[0], MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_iter___57


/**
 *  de'claration de la fonction inter___71
 *    vue comme la classe : MLfun_inter___71
 */ 


  MLvalue* invoke_real_MLfun_inter___71(MLvalue* a___72, MLvalue* b___73) {

    { 
      MLvalue* T___74;
      { 
        MLvalue* T___75;
        MLvalue* T___76;
        T___75=a___72;
        T___76=b___73;
        T___74=MLgtint( (MLvalue* )T___75,(MLvalue* )T___76);
      }
      if ((T___74)->MLbool)
        { 
          MLvalue* T___77;
          T___77=MLnil;
          return T___77;
        }
      else
        { 
          MLvalue* T___78;
          { 
            MLvalue* T___79;
            MLvalue* T___80;
            T___79=a___72;
            { 
              MLvalue* T___81;
              MLvalue* T___86;
              { 
                MLvalue* T___82;
                MLvalue* T___83;
                T___82=inter___71;
                { 
                  MLvalue* T___84;
                  MLvalue* T___85;
                  T___84=a___72;
                  T___85=newMLint(1);
                  T___83=MLaddint( (MLvalue* )T___84,(MLvalue* )T___85);
                }
                T___81=(T___82)->MLfun.invoke(T___82, T___83);
              }
              T___86=b___73;
              T___80=(T___81)->MLfun.invoke(T___81, T___86);
            }
            T___78=newMLlist( (MLvalue* )T___79,(MLvalue* )T___80);
          }
          return T___78;
        }
    }
  }

  MLvalue* invoke_MLfun_inter___71(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_inter___71(f->MLfun.env[0], MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_inter___71


/**
 *  de'claration de la fonction mult___87
 *    vue comme la classe : MLfun_mult___87
 */ 


  MLvalue* invoke_real_MLfun_mult___87(MLvalue* x___88, MLvalue* y___89) {

    { 
      MLvalue* T___90;
      MLvalue* T___91;
      T___90=x___88;
      T___91=y___89;
      return MLmulint( (MLvalue* )T___90,(MLvalue* )T___91);
    }
  }

  MLvalue* invoke_MLfun_mult___87(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_mult___87(f->MLfun.env[0], MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_mult___87


/**
 *  de'claration de la fonction umap___126
 *    vue comme la classe : MLfun_umap___126
 */ 


  MLvalue* invoke_real_MLfun_umap___126(MLvalue* l___127, MLvalue* x___128) {

    { 
      MLvalue* T___129;
      { 
        MLvalue* T___130;
        MLvalue* T___131;
        T___130=null___1;
        T___131=l___127;
        T___129=(T___130)->MLfun.invoke(T___130, T___131);
      }
      if ((T___129)->MLbool)
        { 
          MLvalue* T___132;
          T___132=MLnil;
          return T___132;
        }
      else
        { 
          MLvalue* T___133;
          { 
            MLvalue* T___134;
            MLvalue* T___139;
            { 
              MLvalue* T___135;
              MLvalue* T___138;
              { 
                MLvalue* T___136;
                MLvalue* T___137;
                T___136=MLhdPrimary;
                T___137=l___127;
                T___135=(T___136)->MLfun.invoke(T___136, T___137);
              }
              T___138=x___128;
              T___134=(T___135)->MLfun.invoke(T___135, T___138);
            }
            { 
              MLvalue* T___140;
              MLvalue* T___145;
              { 
                MLvalue* T___141;
                MLvalue* T___142;
                T___141=umap___126;
                { 
                  MLvalue* T___143;
                  MLvalue* T___144;
                  T___143=MLtlPrimary;
                  T___144=l___127;
                  T___142=(T___143)->MLfun.invoke(T___143, T___144);
                }
                T___140=(T___141)->MLfun.invoke(T___141, T___142);
              }
              T___145=x___128;
              T___139=(T___140)->MLfun.invoke(T___140, T___145);
            }
            T___133=newMLlist( (MLvalue* )T___134,(MLvalue* )T___139);
          }
          return T___133;
        }
    }
  }

  MLvalue* invoke_MLfun_umap___126(MLvalue* f, MLvalue* MLparam){
    if (f->MLfun.counter == (f->MLfun.nbparams-1)) {
     return invoke_real_MLfun_umap___126(f->MLfun.env[0], MLparam);
    }
    else {
      MLvalue* l = newMLfun(f, f->MLfun.counter+1,NULL);
      MLaddenv(l,MLparam); return l;
    }
  }

// end of function MLfun_umap___126
/**
 * 
 */


int main(int argc, char ** argv) {
  init();

  null___1 = newMLfun(NULL, 1, invoke_MLfun_null___1);
  g___8 = newMLfun(NULL, 1, invoke_MLfun_g___8);
  h___12 = newMLfun(NULL, 2, invoke_MLfun_h___12);
  q___17 = newMLfun(NULL, 1, invoke_MLfun_q___17);
  v___25 = newMLfun(NULL, 1, invoke_MLfun_v___25);
  w___27 = newMLfun(NULL, 2, invoke_MLfun_w___27);
  map___37 = newMLfun(NULL, 2, invoke_MLfun_map___37);
  iter___57 = newMLfun(NULL, 2, invoke_MLfun_iter___57);
  inter___71 = newMLfun(NULL, 2, invoke_MLfun_inter___71);
  mult___87 = newMLfun(NULL, 2, invoke_MLfun_mult___87);
  umap___126 = newMLfun(NULL, 2, invoke_MLfun_umap___126);
{ 
  MLvalue* T___93;
  MLvalue* T___96;
  { 
    MLvalue* T___94;
    MLvalue* T___95;
    T___94=inter___71;
    T___95=newMLint(1);
    T___93=(T___94)->MLfun.invoke(T___94, T___95);
  }
  T___96=newMLint(10);
  i___92=(T___93)->MLfun.invoke(T___93, T___96);
}
{ 
  MLvalue* bidon___97;
  bidon___97=MLlrp;
  bidon___97=MLprint( (MLvalue* )i___92);
}
{ 
  MLvalue* T___99;
  MLvalue* T___104;
  { 
    MLvalue* T___100;
    MLvalue* T___101;
    T___100=map___37;
    { 
      MLvalue* T___102;
      MLvalue* T___103;
      T___102=mult___87;
      T___103=newMLint(5);
      T___101=(T___102)->MLfun.invoke(T___102, T___103);
    }
    T___99=(T___100)->MLfun.invoke(T___100, T___101);
  }
  T___104=i___92;
  l___98=(T___99)->MLfun.invoke(T___99, T___104);
}
{ 
  MLvalue* bidon___105;
  bidon___105=MLlrp;
  bidon___105=MLprint( (MLvalue* )l___98);
}
fd___106=map___37;
{ 
  MLvalue* bidon___107;
  bidon___107=MLlrp;
  bidon___107=MLprint( (MLvalue* )fd___106);
}
{ 
  MLvalue* T___109;
  MLvalue* T___110;
  T___109=map___37;
  { 
    MLvalue* T___111;
    MLvalue* T___112;
    T___111=mult___87;
    T___112=newMLint(5);
    T___110=(T___111)->MLfun.invoke(T___111, T___112);
  }
  ig___108=(T___109)->MLfun.invoke(T___109, T___110);
}
{ 
  MLvalue* bidon___113;
  bidon___113=MLlrp;
  bidon___113=MLprint( (MLvalue* )ig___108);
}
{ 
  MLvalue* T___115;
  MLvalue* T___116;
  T___115=ig___108;
  T___116=l___98;
  bi___114=(T___115)->MLfun.invoke(T___115, T___116);
}
{ 
  MLvalue* bidon___117;
  bidon___117=MLlrp;
  bidon___117=MLprint( (MLvalue* )bi___114);
}
{ 
  MLvalue* T___119;
  MLvalue* T___120;
  T___119=map___37;
  T___120=mult___87;
  ik___118=(T___119)->MLfun.invoke(T___119, T___120);
}
{ 
  MLvalue* bidon___121;
  bidon___121=MLlrp;
  bidon___121=MLprint( (MLvalue* )ik___118);
}
{ 
  MLvalue* T___123;
  MLvalue* T___124;
  T___123=ik___118;
  T___124=i___92;
  b___122=(T___123)->MLfun.invoke(T___123, T___124);
}
{ 
  MLvalue* bidon___125;
  bidon___125=MLlrp;
  bidon___125=MLprint( (MLvalue* )b___122);
}
{ 
  MLvalue* T___147;
  MLvalue* T___150;
  { 
    MLvalue* T___148;
    MLvalue* T___149;
    T___148=umap___126;
    T___149=b___122;
    T___147=(T___148)->MLfun.invoke(T___148, T___149);
  }
  T___150=newMLint(10);
  value___146=(T___147)->MLfun.invoke(T___147, T___150);
}
{ 
  MLvalue* bidon___151;
  bidon___151=MLlrp;
  bidon___151=MLprint( (MLvalue* )value___146);
}
}

// end of file ftest.c
