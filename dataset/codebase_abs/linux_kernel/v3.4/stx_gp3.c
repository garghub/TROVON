static void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 , V_2 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
F_5 () ;
}
static void T_1 F_6 ( void )
{
#ifdef F_7
struct V_3 * V_4 ;
#endif
if ( V_5 . V_6 )
V_5 . V_6 ( L_2 , 0 ) ;
#ifdef F_8
F_9 () ;
#endif
#ifdef F_7
F_10 (np, L_3 , L_4 )
F_11 ( V_4 , 1 ) ;
#endif
}
static void F_12 ( struct V_7 * V_8 )
{
T_2 V_9 , V_10 , V_11 ;
V_9 = F_13 ( V_12 ) ;
V_10 = F_13 ( V_13 ) ;
F_14 ( V_8 , L_5 ) ;
F_14 ( V_8 , L_6 , V_9 ) ;
F_14 ( V_8 , L_7 , V_10 ) ;
V_11 = F_13 ( V_14 ) ;
F_14 ( V_8 , L_8 , ( ( V_11 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_15 ( void )
{
unsigned long V_15 = F_16 () ;
return F_17 ( V_15 , L_9 ) ;
}
