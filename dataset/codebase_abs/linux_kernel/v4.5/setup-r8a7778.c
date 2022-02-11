static void T_1 F_1 ( void )
{
T_2 V_1 ;
void T_3 * V_2 = F_2 ( V_3 , 4 ) ;
F_3 ( ! V_2 ) ;
V_1 = F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( V_1 ) ;
}
static void T_1 F_7 ( void )
{
void T_3 * V_4 = F_2 ( 0xfe700000 , 0x00100000 ) ;
F_3 ( ! V_4 ) ;
F_8 () ;
F_9 ( 0x73ffffff , V_4 + V_5 ) ;
F_9 ( 0xffffffff , V_4 + V_6 ) ;
F_9 ( 0x08330773 , V_4 + V_7 ) ;
F_9 ( 0x00311110 , V_4 + V_8 ) ;
F_5 ( V_4 ) ;
}
