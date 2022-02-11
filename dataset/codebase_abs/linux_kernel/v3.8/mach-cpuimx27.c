static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_4 ) ;
}
static int T_1 F_4 ( char * V_5 )
{
if ( ! strcmp ( V_5 , L_1 ) )
V_6 = true ;
else if ( ! strcmp ( V_5 , L_2 ) )
V_6 = false ;
else
F_5 ( L_3
L_4 ) ;
return 1 ;
}
static void T_1 F_6 ( void )
{
F_7 () ;
F_8 ( V_7 ,
F_9 ( V_7 ) , L_5 ) ;
F_10 ( & V_8 ) ;
F_11 ( & V_9 ) ;
F_12 ( 0 , V_10 ,
F_9 ( V_10 ) ) ;
F_13 ( 0 , & V_11 ) ;
F_14 ( NULL ) ;
F_15 ( V_12 , F_9 ( V_12 ) ) ;
F_16 () ;
F_17 () ;
#if F_18 ( V_13 )
F_19 ( 1 , NULL ) ;
#endif
#if F_18 ( V_14 )
F_20 ( & V_8 ) ;
#endif
#if F_18 ( V_15 ) || F_18 ( V_16 )
V_17 [ 0 ] . V_18 = F_21 ( 2 , 23 ) ;
V_17 [ 1 ] . V_18 = F_21 ( 2 , 22 ) ;
V_17 [ 2 ] . V_18 = F_21 ( 2 , 27 ) ;
V_17 [ 3 ] . V_18 = F_21 ( 2 , 30 ) ;
F_22 ( & V_19 ) ;
#endif
if ( V_6 ) {
V_20 . V_21 = F_23 ( V_22 |
V_23 ) ;
if ( V_20 . V_21 )
F_24 ( & V_20 ) ;
} else {
F_25 ( & V_24 ) ;
}
V_25 . V_21 = F_23 ( V_22 |
V_23 ) ;
if ( V_25 . V_21 )
F_26 ( 2 , & V_25 ) ;
#ifdef F_27
F_28 () ;
#endif
}
static void T_1 F_29 ( void )
{
F_30 ( 26000000 ) ;
}
