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
if ( V_3 . V_4 )
V_3 . V_4 ( L_2 , 0 ) ;
F_7 () ;
#ifdef F_8
F_9 () ;
#endif
}
static void F_10 ( struct V_5 * V_6 )
{
T_2 V_7 , V_8 , V_9 ;
V_7 = F_11 ( V_10 ) ;
V_8 = F_11 ( V_11 ) ;
F_12 ( V_6 , L_3 ) ;
F_12 ( V_6 , L_4 , V_7 ) ;
F_12 ( V_6 , L_5 , V_8 ) ;
V_9 = F_11 ( V_12 ) ;
F_12 ( V_6 , L_6 , ( ( V_9 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_13 ( void )
{
unsigned long V_13 = F_14 () ;
return F_15 ( V_13 , L_7 ) ;
}
