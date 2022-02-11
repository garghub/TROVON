static void T_1 F_1 ( void )
{
T_2 V_1 ;
F_2 ( 0x1f , V_2 ) ;
V_1 = F_3 ( V_3 ) ;
V_1 &= 0x3f3f ;
F_4 ( V_1 , V_3 ) ;
}
static void T_1 F_5 ( void )
{
T_2 V_1 ;
T_3 V_4 ;
V_1 = F_3 ( V_5 + 0x100082 ) ;
F_4 ( V_1 | 0xf00 , V_5 + 0x100082 ) ;
V_4 = F_6 ( V_5 + 0x100078 ) ;
F_2 ( V_4 | 0xc0 , V_5 + 0x100078 ) ;
}
void T_1 F_7 ( char * V_6 , int V_7 )
{
V_8 = V_9 ;
F_5 () ;
#if F_8 ( V_10 )
F_1 () ;
#endif
}
