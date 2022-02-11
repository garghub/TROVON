static int F_1 ( void )
{
return ! F_2 ( V_1 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
return F_4 ( V_3 -> V_4 , V_5 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
return F_4 ( V_3 -> V_4 , V_6 |
V_7 | V_8 ) ;
}
static int T_1 F_6 ( char * V_9 )
{
if ( ! strcmp ( V_9 , L_1 ) )
V_10 = true ;
else if ( ! strcmp ( V_9 , L_2 ) )
V_10 = false ;
else
F_7 ( L_3
L_4 ) ;
return 1 ;
}
static void T_1 F_8 ( void )
{
F_9 () ;
F_10 ( V_11 ,
F_11 ( V_11 ) ) ;
F_12 ( NULL ) ;
F_13 () ;
F_14 ( & V_12 ) ;
F_15 ( & V_13 ) ;
V_14 [ 1 ] . V_15 = F_16 ( V_1 ) ;
F_17 ( 0 , V_14 ,
F_11 ( V_14 ) ) ;
F_18 ( & V_16 ) ;
if ( V_10 )
F_19 ( & V_17 ) ;
else
F_20 ( & V_18 ) ;
F_21 ( & V_19 ) ;
#ifdef F_22
F_23 () ;
#endif
}
static void T_1 F_24 ( void )
{
F_25 () ;
}
