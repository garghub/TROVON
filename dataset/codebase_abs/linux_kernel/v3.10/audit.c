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
if ( V_3 == V_2 )
return F_4 ( V_4 ) ;
#endif
switch( V_4 ) {
case V_5 :
return 2 ;
case V_6 :
return 3 ;
case V_7 :
return 4 ;
case V_8 :
return 5 ;
default:
return 0 ;
}
}
static int T_1 F_5 ( void )
{
#ifdef F_2
F_6 ( V_9 , V_10 ) ;
F_6 ( V_11 , V_12 ) ;
F_6 ( V_13 , V_14 ) ;
F_6 ( V_15 , V_16 ) ;
F_6 ( V_17 , V_18 ) ;
#endif
F_6 ( V_19 , V_20 ) ;
F_6 ( V_21 , V_22 ) ;
F_6 ( V_23 , V_24 ) ;
F_6 ( V_25 , V_26 ) ;
F_6 ( V_27 , V_28 ) ;
return 0 ;
}
