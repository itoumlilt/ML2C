/**
 *  ftest.java engendre par ml2java 
 */


/**
 *  de'claration de la fonction null___1
 *    vue comme la classe : MLfun_null___1
 */ 
class MLfun_null___1 extends MLfun {

  private static int MAX = 1;

  MLfun_null___1() {super();}

  MLfun_null___1(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLparam);
    }
    else {
      MLfun_null___1 l = new MLfun_null___1(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue l___2) {

    { 
      MLvalue T___3;
      { 
        MLvalue T___4;
        MLvalue T___5;
        T___4=l___2;
        T___5=MLruntime.MLnil;
        T___3=MLruntime.MLequal( (MLlist )T___4,(MLlist )T___5);
      }
      if (((MLbool)T___3).MLaccess())
        { 
          MLvalue T___6;
          T___6=MLruntime.MLtrue;
          return T___6;
        }
      else
        { 
          MLvalue T___7;
          T___7=MLruntime.MLfalse;
          return T___7;
        }
    }
  }

}
// fin de la classe MLfun_null___1


/**
 *  de'claration de la fonction g___8
 *    vue comme la classe : MLfun_g___8
 */ 
class MLfun_g___8 extends MLfun {

  private static int MAX = 1;

  MLfun_g___8() {super();}

  MLfun_g___8(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLparam);
    }
    else {
      MLfun_g___8 l = new MLfun_g___8(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue x___9) {

    { 
      MLvalue T___10;
      MLvalue T___11;
      T___10=x___9;
      T___11=MLruntime.MLnil;
      return MLruntime.MLequal( (MLlist )T___10,(MLlist )T___11);
    }
  }

}
// fin de la classe MLfun_g___8


/**
 *  de'claration de la fonction h___12
 *    vue comme la classe : MLfun_h___12
 */ 
class MLfun_h___12 extends MLfun {

  private static int MAX = 2;

  MLfun_h___12() {super();}

  MLfun_h___12(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLenv[0], MLparam);
    }
    else {
      MLfun_h___12 l = new MLfun_h___12(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue x___13, MLvalue y___14) {

    { 
      MLvalue T___15;
      MLvalue T___16;
      T___15=x___13;
      T___16=y___14;
      return MLruntime.MLlist( (MLvalue )T___15,(MLlist )T___16);
    }
  }

}
// fin de la classe MLfun_h___12


/**
 *  de'claration de la fonction q___17
 *    vue comme la classe : MLfun_q___17
 */ 
class MLfun_q___17 extends MLfun {

  private static int MAX = 1;

  MLfun_q___17() {super();}

  MLfun_q___17(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLparam);
    }
    else {
      MLfun_q___17 l = new MLfun_q___17(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue x___18) {

    { 
      MLvalue T___19;
      MLvalue T___22;
      { 
        MLvalue T___20;
        MLvalue T___21;
        T___20=MLruntime.MLhd;
        T___21=x___18;
        T___19=((MLfun)T___20).invoke(T___21);
      }
      { 
        MLvalue T___23;
        MLvalue T___24;
        T___23=MLruntime.MLtl;
        T___24=x___18;
        T___22=((MLfun)T___23).invoke(T___24);
      }
      return MLruntime.MLpair( (MLvalue )T___19,(MLlist )T___22);
    }
  }

}
// fin de la classe MLfun_q___17


/**
 *  de'claration de la fonction v___25
 *    vue comme la classe : MLfun_v___25
 */ 
class MLfun_v___25 extends MLfun {

  private static int MAX = 1;

  MLfun_v___25() {super();}

  MLfun_v___25(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLparam);
    }
    else {
      MLfun_v___25 l = new MLfun_v___25(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue x___26) {

    return MLruntime.MLnil;
  }

}
// fin de la classe MLfun_v___25


/**
 *  de'claration de la fonction w___27
 *    vue comme la classe : MLfun_w___27
 */ 
class MLfun_w___27 extends MLfun {

  private static int MAX = 2;

  MLfun_w___27() {super();}

  MLfun_w___27(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLenv[0], MLparam);
    }
    else {
      MLfun_w___27 l = new MLfun_w___27(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue l___28, MLvalue x___29) {

    { 
      MLvalue T___30;
      { 
        MLvalue T___31;
        MLvalue T___32;
        T___31=l___28;
        T___32=MLruntime.MLnil;
        T___30=MLruntime.MLequal( (MLlist )T___31,(MLlist )T___32);
      }
      if (((MLbool)T___30).MLaccess())
        { 
          MLvalue T___33;
          T___33=MLruntime.MLnil;
          return T___33;
        }
      else
        { 
          MLvalue T___34;
          { 
            MLvalue T___35;
            MLvalue T___36;
            T___35=x___29;
            T___36=MLruntime.MLnil;
            T___34=MLruntime.MLlist( (MLvalue )T___35,(MLlist )T___36);
          }
          return T___34;
        }
    }
  }

}
// fin de la classe MLfun_w___27


/**
 *  de'claration de la fonction map___37
 *    vue comme la classe : MLfun_map___37
 */ 
class MLfun_map___37 extends MLfun {

  private static int MAX = 2;

  MLfun_map___37() {super();}

  MLfun_map___37(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLenv[0], MLparam);
    }
    else {
      MLfun_map___37 l = new MLfun_map___37(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue f___38, MLvalue l___39) {

    { 
      MLvalue T___40;
      { 
        MLvalue T___41;
        MLvalue T___42;
        T___41=ftest.null___1;
        T___42=l___39;
        T___40=((MLfun)T___41).invoke(T___42);
      }
      if (((MLbool)T___40).MLaccess())
        { 
          MLvalue T___43;
          T___43=MLruntime.MLnil;
          return T___43;
        }
      else
        { 
          MLvalue T___44;
          { 
            MLvalue T___45;
            MLvalue T___50;
            { 
              MLvalue T___46;
              MLvalue T___47;
              T___46=f___38;
              { 
                MLvalue T___48;
                MLvalue T___49;
                T___48=MLruntime.MLhd;
                T___49=l___39;
                T___47=((MLfun)T___48).invoke(T___49);
              }
              T___45=((MLfun)T___46).invoke(T___47);
            }
            { 
              MLvalue T___51;
              MLvalue T___54;
              { 
                MLvalue T___52;
                MLvalue T___53;
                T___52=ftest.map___37;
                T___53=f___38;
                T___51=((MLfun)T___52).invoke(T___53);
              }
              { 
                MLvalue T___55;
                MLvalue T___56;
                T___55=MLruntime.MLtl;
                T___56=l___39;
                T___54=((MLfun)T___55).invoke(T___56);
              }
              T___50=((MLfun)T___51).invoke(T___54);
            }
            T___44=MLruntime.MLlist( (MLvalue )T___45,(MLlist )T___50);
          }
          return T___44;
        }
    }
  }

}
// fin de la classe MLfun_map___37


/**
 *  de'claration de la fonction iter___57
 *    vue comme la classe : MLfun_iter___57
 */ 
class MLfun_iter___57 extends MLfun {

  private static int MAX = 2;

  MLfun_iter___57() {super();}

  MLfun_iter___57(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLenv[0], MLparam);
    }
    else {
      MLfun_iter___57 l = new MLfun_iter___57(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue f___58, MLvalue l___59) {

    { 
      MLvalue T___60;
      { 
        MLvalue T___61;
        MLvalue T___62;
        T___61=ftest.null___1;
        T___62=l___59;
        T___60=((MLfun)T___61).invoke(T___62);
      }
      if (((MLbool)T___60).MLaccess())
        { 
          MLvalue T___63;
          T___63=MLruntime.MLnil;
          return T___63;
        }
      else
        { 
          MLvalue T___64;
          { 
            MLvalue T___65;
            MLvalue T___66;
            T___65=ftest.iter___57;
            { 
              MLvalue T___67;
              MLvalue T___68;
              T___67=f___58;
              { 
                MLvalue T___69;
                MLvalue T___70;
                T___69=MLruntime.MLtl;
                T___70=l___59;
                T___68=((MLfun)T___69).invoke(T___70);
              }
              T___66=((MLfun)T___67).invoke(T___68);
            }
            T___64=((MLfun)T___65).invoke(T___66);
          }
          return T___64;
        }
    }
  }

}
// fin de la classe MLfun_iter___57


/**
 *  de'claration de la fonction inter___71
 *    vue comme la classe : MLfun_inter___71
 */ 
class MLfun_inter___71 extends MLfun {

  private static int MAX = 2;

  MLfun_inter___71() {super();}

  MLfun_inter___71(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLenv[0], MLparam);
    }
    else {
      MLfun_inter___71 l = new MLfun_inter___71(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue a___72, MLvalue b___73) {

    { 
      MLvalue T___74;
      { 
        MLvalue T___75;
        MLvalue T___76;
        T___75=a___72;
        T___76=b___73;
        T___74=MLruntime.MLgtint( (MLint )T___75,(MLint )T___76);
      }
      if (((MLbool)T___74).MLaccess())
        { 
          MLvalue T___77;
          T___77=MLruntime.MLnil;
          return T___77;
        }
      else
        { 
          MLvalue T___78;
          { 
            MLvalue T___79;
            MLvalue T___80;
            T___79=a___72;
            { 
              MLvalue T___81;
              MLvalue T___86;
              { 
                MLvalue T___82;
                MLvalue T___83;
                T___82=ftest.inter___71;
                { 
                  MLvalue T___84;
                  MLvalue T___85;
                  T___84=a___72;
                  T___85=new MLint(1);
                  T___83=MLruntime.MLaddint( (MLint )T___84,(MLint )T___85);
                }
                T___81=((MLfun)T___82).invoke(T___83);
              }
              T___86=b___73;
              T___80=((MLfun)T___81).invoke(T___86);
            }
            T___78=MLruntime.MLlist( (MLint )T___79,(MLlist )T___80);
          }
          return T___78;
        }
    }
  }

}
// fin de la classe MLfun_inter___71


/**
 *  de'claration de la fonction mult___87
 *    vue comme la classe : MLfun_mult___87
 */ 
class MLfun_mult___87 extends MLfun {

  private static int MAX = 2;

  MLfun_mult___87() {super();}

  MLfun_mult___87(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLenv[0], MLparam);
    }
    else {
      MLfun_mult___87 l = new MLfun_mult___87(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue x___88, MLvalue y___89) {

    { 
      MLvalue T___90;
      MLvalue T___91;
      T___90=x___88;
      T___91=y___89;
      return MLruntime.MLmulint( (MLint )T___90,(MLint )T___91);
    }
  }

}
// fin de la classe MLfun_mult___87


/**
 *  de'claration de la fonction umap___126
 *    vue comme la classe : MLfun_umap___126
 */ 
class MLfun_umap___126 extends MLfun {

  private static int MAX = 2;

  MLfun_umap___126() {super();}

  MLfun_umap___126(int n) {super(n);}

  public MLvalue invoke(MLvalue MLparam){
    if (MLcounter == (MAX-1)) {
      return invoke_real(MLenv[0], MLparam);
    }
    else {
      MLfun_umap___126 l = new MLfun_umap___126(MLcounter+1);l.MLaddenv(MLenv,MLparam); return l;
    }
  }


  MLvalue invoke_real(MLvalue l___127, MLvalue x___128) {

    { 
      MLvalue T___129;
      { 
        MLvalue T___130;
        MLvalue T___131;
        T___130=ftest.null___1;
        T___131=l___127;
        T___129=((MLfun)T___130).invoke(T___131);
      }
      if (((MLbool)T___129).MLaccess())
        { 
          MLvalue T___132;
          T___132=MLruntime.MLnil;
          return T___132;
        }
      else
        { 
          MLvalue T___133;
          { 
            MLvalue T___134;
            MLvalue T___139;
            { 
              MLvalue T___135;
              MLvalue T___138;
              { 
                MLvalue T___136;
                MLvalue T___137;
                T___136=MLruntime.MLhd;
                T___137=l___127;
                T___135=((MLfun)T___136).invoke(T___137);
              }
              T___138=x___128;
              T___134=((MLfun)T___135).invoke(T___138);
            }
            { 
              MLvalue T___140;
              MLvalue T___145;
              { 
                MLvalue T___141;
                MLvalue T___142;
                T___141=ftest.umap___126;
                { 
                  MLvalue T___143;
                  MLvalue T___144;
                  T___143=MLruntime.MLtl;
                  T___144=l___127;
                  T___142=((MLfun)T___143).invoke(T___144);
                }
                T___140=((MLfun)T___141).invoke(T___142);
              }
              T___145=x___128;
              T___139=((MLfun)T___140).invoke(T___145);
            }
            T___133=MLruntime.MLlist( (MLvalue )T___134,(MLlist )T___139);
          }
          return T___133;
        }
    }
  }

}
// fin de la classe MLfun_umap___126
/**
 * 
 */
class ftest {

  static MLvalue null___1= new MLfun_null___1(1);
  static MLvalue g___8= new MLfun_g___8(1);
  static MLvalue h___12= new MLfun_h___12(2);
  static MLvalue q___17= new MLfun_q___17(1);
  static MLvalue v___25= new MLfun_v___25(1);
  static MLvalue w___27= new MLfun_w___27(2);
  static MLvalue map___37= new MLfun_map___37(2);
  static MLvalue iter___57= new MLfun_iter___57(2);
  static MLvalue inter___71= new MLfun_inter___71(2);
  static MLvalue mult___87= new MLfun_mult___87(2);
  static MLvalue i___92;
  static MLvalue l___98;
  static MLvalue fd___106;
  static MLvalue ig___108;
  static MLvalue bi___114;
  static MLvalue ik___118;
  static MLvalue b___122;
  static MLvalue umap___126= new MLfun_umap___126(2);
  static MLvalue value___146;

public static void main(String []args) {

{ 
  MLvalue T___93;
  MLvalue T___96;
  { 
    MLvalue T___94;
    MLvalue T___95;
    T___94=ftest.inter___71;
    T___95=new MLint(1);
    T___93=((MLfun)T___94).invoke(T___95);
  }
  T___96=new MLint(10);
  i___92=((MLfun)T___93).invoke(T___96);
}
{ 
  MLvalue bidon___97;
  bidon___97=MLruntime.MLlrp;
  bidon___97=MLruntime.MLprint( (MLvalue )i___92);
}
{ 
  MLvalue T___99;
  MLvalue T___104;
  { 
    MLvalue T___100;
    MLvalue T___101;
    T___100=ftest.map___37;
    { 
      MLvalue T___102;
      MLvalue T___103;
      T___102=ftest.mult___87;
      T___103=new MLint(5);
      T___101=((MLfun)T___102).invoke(T___103);
    }
    T___99=((MLfun)T___100).invoke(T___101);
  }
  T___104=i___92;
  l___98=((MLfun)T___99).invoke(T___104);
}
{ 
  MLvalue bidon___105;
  bidon___105=MLruntime.MLlrp;
  bidon___105=MLruntime.MLprint( (MLvalue )l___98);
}
fd___106=ftest.map___37;
{ 
  MLvalue bidon___107;
  bidon___107=MLruntime.MLlrp;
  bidon___107=MLruntime.MLprint( (MLvalue )fd___106);
}
{ 
  MLvalue T___109;
  MLvalue T___110;
  T___109=ftest.map___37;
  { 
    MLvalue T___111;
    MLvalue T___112;
    T___111=ftest.mult___87;
    T___112=new MLint(5);
    T___110=((MLfun)T___111).invoke(T___112);
  }
  ig___108=((MLfun)T___109).invoke(T___110);
}
{ 
  MLvalue bidon___113;
  bidon___113=MLruntime.MLlrp;
  bidon___113=MLruntime.MLprint( (MLvalue )ig___108);
}
{ 
  MLvalue T___115;
  MLvalue T___116;
  T___115=ig___108;
  T___116=l___98;
  bi___114=((MLfun)T___115).invoke(T___116);
}
{ 
  MLvalue bidon___117;
  bidon___117=MLruntime.MLlrp;
  bidon___117=MLruntime.MLprint( (MLvalue )bi___114);
}
{ 
  MLvalue T___119;
  MLvalue T___120;
  T___119=ftest.map___37;
  T___120=ftest.mult___87;
  ik___118=((MLfun)T___119).invoke(T___120);
}
{ 
  MLvalue bidon___121;
  bidon___121=MLruntime.MLlrp;
  bidon___121=MLruntime.MLprint( (MLvalue )ik___118);
}
{ 
  MLvalue T___123;
  MLvalue T___124;
  T___123=ik___118;
  T___124=i___92;
  b___122=((MLfun)T___123).invoke(T___124);
}
{ 
  MLvalue bidon___125;
  bidon___125=MLruntime.MLlrp;
  bidon___125=MLruntime.MLprint( (MLvalue )b___122);
}
{ 
  MLvalue T___147;
  MLvalue T___150;
  { 
    MLvalue T___148;
    MLvalue T___149;
    T___148=ftest.umap___126;
    T___149=b___122;
    T___147=((MLfun)T___148).invoke(T___149);
  }
  T___150=new MLint(10);
  value___146=((MLfun)T___147).invoke(T___150);
}
{ 
  MLvalue bidon___151;
  bidon___151=MLruntime.MLlrp;
  bidon___151=MLruntime.MLprint( (MLvalue )value___146);
}
}}

// fin du fichier ftest.java
