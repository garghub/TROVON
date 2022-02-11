static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_3 = F_2 ( NULL , 0 ,
V_4 | V_5 ,
0 , 256 , L_1 ) ;
F_3 ( V_3 == NULL ) ;
F_4 ( V_3 ) ;
V_2 = F_5 ( NULL , NULL , L_2 ) ;
if ( ! V_2 ) {
F_6 ( V_6 L_3 ) ;
return;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static void T_1 F_9 ( void )
{
#ifdef F_10
struct V_1 * V_2 ;
#endif
if ( V_7 . V_8 )
V_7 . V_8 ( L_4 , 0 ) ;
#ifdef F_10
F_11 (np, L_5 , L_6 )
F_12 ( V_2 , 1 ) ;
#endif
}
static int T_1 F_13 ( void )
{
unsigned long V_9 = F_14 () ;
if ( F_15 ( V_9 , L_7 ) )
return 1 ;
return 0 ;
}
