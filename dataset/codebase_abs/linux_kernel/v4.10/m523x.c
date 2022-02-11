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
#if F_2 ( V_5 )
T_3 V_2 ;
V_2 = F_7 ( V_6 ) ;
V_2 |= 0x0f ;
F_3 ( V_2 , V_6 ) ;
#endif
}
static void T_1 F_8 ( void )
{
F_3 ( F_7 ( V_6 ) | 0xf0 , V_6 ) ;
}
void T_1 F_9 ( char * V_7 , int V_8 )
{
V_9 = V_10 ;
F_8 () ;
F_1 () ;
F_6 () ;
}
