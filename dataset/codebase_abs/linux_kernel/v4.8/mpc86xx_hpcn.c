static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_5 == V_6 )
return F_2 ( V_2 , V_3 , V_4 ) ;
return V_7 ;
}
static void T_2
F_3 ( void )
{
if ( V_8 . V_9 )
V_8 . V_9 ( L_1 , 0 ) ;
#ifdef F_4
V_8 . V_10 = F_1 ;
#endif
F_5 ( L_2 ) ;
#ifdef F_6
F_7 () ;
#endif
F_8 () ;
F_9 () ;
}
static void
F_10 ( struct V_11 * V_12 )
{
T_3 V_13 = F_11 ( V_14 ) ;
F_12 ( V_12 , L_3 ) ;
F_12 ( V_12 , L_4 , V_13 ) ;
}
static int T_2 F_13 ( void )
{
if ( F_14 ( L_5 ) )
return 1 ;
if ( F_14 ( L_6 ) ) {
F_15 ( L_7 ) ;
return 1 ;
}
return 0 ;
}
static int T_2 F_16 ( void )
{
F_17 () ;
F_18 ( NULL , V_15 , NULL ) ;
return 0 ;
}
