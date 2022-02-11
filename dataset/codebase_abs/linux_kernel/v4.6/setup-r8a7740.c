static void T_1 F_1 ( void )
{
void T_2 * V_1 ;
V_1 = F_2 ( V_2 , 4 ) ;
if ( V_1 ) {
F_3 ( 0x01600164 , V_1 ) ;
F_4 ( V_1 ) ;
}
}
static void T_1 F_5 ( void )
{
void T_2 * V_3 = F_2 ( 0xe6900010 , 0x10 ) ;
void T_2 * V_4 = F_2 ( 0xe6900040 , 0x10 ) ;
void T_2 * V_5 = F_2 ( 0xe605807c , 0x4 ) ;
F_6 () ;
F_3 ( 0x0 , V_5 ) ;
F_3 ( 0x0 , V_3 + 0x0 ) ;
F_3 ( 0x0 , V_3 + 0x4 ) ;
F_3 ( 0x0 , V_3 + 0x8 ) ;
F_3 ( 0x0 , V_3 + 0xc ) ;
F_7 ( 0xff , V_4 + 0x0 ) ;
F_7 ( 0xff , V_4 + 0x4 ) ;
F_7 ( 0xff , V_4 + 0x8 ) ;
F_7 ( 0xff , V_4 + 0xc ) ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
F_4 ( V_5 ) ;
}
static void T_1 F_8 ( void )
{
F_1 () ;
F_9 ( NULL , V_6 , NULL , NULL ) ;
}
