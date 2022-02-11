static int F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
return F_4 ( V_5 -> V_6 , V_7 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
return F_4 ( V_5 -> V_6 , V_8 |
V_9 | V_10 ) ;
}
static int T_1 F_6 ( char * V_11 )
{
if ( ! strcmp ( V_11 , L_1 ) )
V_12 = true ;
else if ( ! strcmp ( V_11 , L_2 ) )
V_12 = false ;
else
F_7 ( L_3
L_4 ) ;
return 1 ;
}
static void T_1 F_8 ( void )
{
F_9 () ;
F_10 ( V_13 ,
F_11 ( V_13 ) ) ;
F_12 ( NULL ) ;
F_13 () ;
F_14 ( & V_14 ) ;
F_15 ( & V_15 ) ;
V_16 [ 1 ] . V_17 = F_16 ( V_3 ) ;
F_17 ( 0 , V_16 ,
F_11 ( V_16 ) ) ;
F_18 ( & V_18 ) ;
if ( V_12 )
F_19 ( & V_19 ) ;
else
F_20 ( & V_20 ) ;
F_21 ( & V_21 ) ;
#ifdef F_22
F_23 () ;
#endif
}
static void T_1 F_24 ( void )
{
F_25 () ;
}
