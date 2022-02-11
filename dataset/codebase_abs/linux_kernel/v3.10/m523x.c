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
F_2 ( F_6 ( V_4 ) | 0xf0 , V_4 ) ;
}
void T_1 F_7 ( char * V_5 , int V_6 )
{
V_7 = V_8 ;
F_5 () ;
#if F_8 ( V_9 )
F_1 () ;
#endif
}
