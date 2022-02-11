static void T_1 F_1 ( void )
{
void T_2 * V_1 = F_2 ( 0xe6900010 , 0x10 ) ;
void T_2 * V_2 = F_2 ( 0xe6900040 , 0x10 ) ;
void T_2 * V_3 = F_2 ( 0xe605807c , 0x4 ) ;
F_3 ( 0x0 , V_3 ) ;
F_3 ( 0x0 , V_1 + 0x0 ) ;
F_3 ( 0x0 , V_1 + 0x4 ) ;
F_3 ( 0x0 , V_1 + 0x8 ) ;
F_3 ( 0x0 , V_1 + 0xc ) ;
F_4 ( 0xff , V_2 + 0x0 ) ;
F_4 ( 0xff , V_2 + 0x4 ) ;
F_4 ( 0xff , V_2 + 0x8 ) ;
F_4 ( 0xff , V_2 + 0xc ) ;
F_5 ( V_1 ) ;
F_5 ( V_2 ) ;
F_5 ( V_3 ) ;
}
void T_1 F_6 ( void )
{
F_7 () ;
F_1 () ;
}
void T_1 F_8 ( void )
{
void T_2 * V_4 = F_2 ( 0xc2800000 , 0x1000 ) ;
void T_2 * V_5 = F_2 ( 0xc2000000 , 0x1000 ) ;
F_9 ( 0 , 29 , V_4 , V_5 ) ;
F_1 () ;
}
