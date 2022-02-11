static void F_1 ( void )
{
void T_1 * V_1 ;
V_1 = F_2 ( F_3 () , 0x1000 ) ;
if ( ! V_1 ) {
F_4 ( 1 ) ;
return;
}
F_5 ( V_1 + V_2 , V_3 ,
V_4 ) ;
F_5 ( V_1 + V_5 , V_6 ,
V_7 ) ;
F_6 ( V_1 ) ;
}
static void T_2 F_7 ( void )
{
#ifdef F_8
struct V_8 * V_9 ;
#endif
if ( V_10 . V_11 )
V_10 . V_11 ( L_1 , 0 ) ;
#ifdef F_8
F_9 (np, L_2 , L_3 )
F_10 ( V_9 ) ;
F_9 (np, L_2 , L_4 )
F_10 ( V_9 ) ;
#endif
F_11 () ;
F_1 () ;
}
static int T_2 F_12 ( void )
{
F_13 ( NULL , V_12 , NULL ) ;
return 0 ;
}
static void T_2 F_14 ( void )
{
struct V_8 * V_9 ;
V_9 = F_15 ( NULL , NULL , L_5 ) ;
if ( ! V_9 )
return;
F_16 ( V_9 , 0 ) ;
F_17 () ;
}
static int T_2 F_18 ( void )
{
return F_19 ( F_20 () , V_13 ) ;
}
