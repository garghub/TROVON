static int T_1 F_1 ( void )
{
return F_2 ( NULL , V_1 , NULL ) ;
}
static void T_1 F_3 ( void )
{
#ifdef F_4
struct V_2 * V_3 ;
#endif
if ( V_4 . V_5 )
V_4 . V_5 ( L_1 , 0 ) ;
#ifdef F_4
F_5 (np, L_2 , L_3 )
F_6 ( V_3 ) ;
#endif
#ifdef F_7
F_8 () ;
#endif
}
static void T_1 F_9 ( void )
{
struct V_2 * V_3 ;
V_3 = F_10 ( NULL , NULL , L_4 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , 0 ) ;
F_12 () ;
F_13 ( V_3 ) ;
#ifdef F_7
V_3 = F_10 ( NULL , NULL , L_5 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , 0 , V_6 , V_7 ) ;
F_13 ( V_3 ) ;
#endif
}
static int T_1 F_15 ( void )
{
unsigned long V_8 = F_16 () ;
return F_17 ( V_8 , L_6 ) ;
}
