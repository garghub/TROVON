static void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 , V_2 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
}
static void T_1 F_5 ( void )
{
if ( V_3 . V_4 )
V_3 . V_4 ( L_2 , 0 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
T_2 V_7 , V_8 ;
V_7 = F_7 ( V_9 ) ;
F_8 ( V_6 , L_3 ) ;
F_8 ( V_6 , L_4 , V_7 ) ;
V_8 = F_7 ( V_10 ) ;
F_8 ( V_6 , L_5 , ( ( V_8 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_9 ( void )
{
F_10 ( NULL , V_11 , NULL ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
unsigned long V_12 = F_12 () ;
return F_13 ( V_12 , L_6 ) ;
}
