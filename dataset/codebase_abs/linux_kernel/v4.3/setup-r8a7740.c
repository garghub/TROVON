static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
static void T_1 F_5 ( void )
{
void T_2 * V_2 ;
V_2 = F_6 ( V_3 , 4 ) ;
if ( V_2 ) {
F_7 ( 0x01600164 , V_2 ) ;
F_8 ( V_2 ) ;
}
}
static void T_1 F_9 ( void )
{
void T_2 * V_4 = F_6 ( 0xe6900010 , 0x10 ) ;
void T_2 * V_5 = F_6 ( 0xe6900040 , 0x10 ) ;
void T_2 * V_6 = F_6 ( 0xe605807c , 0x4 ) ;
F_10 () ;
F_7 ( 0x0 , V_6 ) ;
F_7 ( 0x0 , V_4 + 0x0 ) ;
F_7 ( 0x0 , V_4 + 0x4 ) ;
F_7 ( 0x0 , V_4 + 0x8 ) ;
F_7 ( 0x0 , V_4 + 0xc ) ;
F_11 ( 0xff , V_5 + 0x0 ) ;
F_11 ( 0xff , V_5 + 0x4 ) ;
F_11 ( 0xff , V_5 + 0x8 ) ;
F_11 ( 0xff , V_5 + 0xc ) ;
F_8 ( V_4 ) ;
F_8 ( V_5 ) ;
F_8 ( V_6 ) ;
}
static void T_1 F_12 ( void )
{
F_5 () ;
#ifdef F_13
F_14 ( F_15 ( 0xf0002000 ) , 0x00400000 , 0xc20f0fff ) ;
#endif
F_16 ( NULL , V_7 , NULL , NULL ) ;
}
