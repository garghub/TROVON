int F_1 ( int V_1 )
{
#ifdef F_2
if ( V_1 == V_2 )
return 1 ;
#endif
return 0 ;
}
int F_3 ( int V_3 , unsigned V_4 )
{
#ifdef F_2
extern int V_5 ( unsigned ) ;
if ( V_3 == V_2 )
return V_5 ( V_4 ) ;
#endif
switch( V_4 ) {
case V_6 :
return 2 ;
case V_7 :
return 3 ;
case V_8 :
return 5 ;
default:
return 0 ;
}
}
static int T_1 F_4 ( void )
{
#ifdef F_2
extern T_2 V_9 [] ;
extern T_2 V_10 [] ;
extern T_2 V_11 [] ;
extern T_2 V_12 [] ;
extern T_2 V_13 [] ;
F_5 ( V_14 , V_10 ) ;
F_5 ( V_15 , V_11 ) ;
F_5 ( V_16 , V_9 ) ;
F_5 ( V_17 , V_12 ) ;
F_5 ( V_18 , V_13 ) ;
#endif
F_5 ( V_19 , V_20 ) ;
F_5 ( V_21 , V_22 ) ;
F_5 ( V_23 , V_24 ) ;
F_5 ( V_25 , V_26 ) ;
F_5 ( V_27 , V_28 ) ;
return 0 ;
}
