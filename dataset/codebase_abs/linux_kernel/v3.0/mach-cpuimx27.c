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
V_6 = 1 ;
else if ( ! strcmp ( V_5 , L_2 ) )
V_6 = 0 ;
else
F_5 ( L_3
L_4 ) ;
return 0 ;
}
static void T_1 F_6 ( void )
{
F_7 ( V_7 ,
F_8 ( V_7 ) , L_5 ) ;
F_9 ( & V_8 ) ;
F_10 ( & V_9 ) ;
F_11 ( 0 , V_10 ,
F_8 ( V_10 ) ) ;
F_12 ( 0 , & V_11 ) ;
F_13 ( NULL ) ;
F_14 ( V_12 , F_8 ( V_12 ) ) ;
F_15 ( NULL ) ;
F_16 ( NULL ) ;
#if F_17 ( V_13 )
F_18 ( 1 , NULL ) ;
#endif
#if F_17 ( V_14 )
F_19 ( & V_8 ) ;
#endif
#if F_17 ( V_15 ) || F_17 ( V_16 )
F_20 ( & V_17 ) ;
#endif
if ( V_6 ) {
V_18 . V_19 = F_21 ( V_20 |
V_21 ) ;
if ( V_18 . V_19 )
F_22 ( & V_18 ) ;
} else {
F_23 ( & V_22 ) ;
}
V_23 . V_19 = F_21 ( V_20 |
V_21 ) ;
if ( V_23 . V_19 )
F_24 ( 2 , & V_23 ) ;
#ifdef F_25
F_26 () ;
#endif
}
static void T_1 F_27 ( void )
{
F_28 ( 26000000 ) ;
}
