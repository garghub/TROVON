static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
T_2 V_2 ;
F_3 ( 0x1f , V_3 ) ;
V_2 = F_4 ( V_4 ) ;
V_2 &= 0x3f3f ;
F_5 ( V_2 , V_4 ) ;
#endif
}
static void T_1 F_6 ( void )
{
F_3 ( F_7 ( V_5 ) | 0xf0 , V_5 ) ;
}
void T_1 F_8 ( char * V_6 , int V_7 )
{
V_8 = V_9 ;
F_6 () ;
F_1 () ;
}
