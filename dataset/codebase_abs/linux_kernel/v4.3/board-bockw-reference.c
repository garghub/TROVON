static void T_1 F_1 ( void )
{
void T_2 * V_1 ;
void T_2 * V_2 ;
#ifndef F_2
F_3 () ;
#endif
F_4 ( 1 ) ;
F_5 () ;
V_1 = F_6 ( V_3 , V_4 ) ;
if ( V_1 ) {
T_3 V_5 = F_7 ( V_1 + V_6 ) ;
V_5 &= ~ ( 1 << 4 ) ;
F_8 ( V_5 , V_1 + V_6 ) ;
F_9 ( V_1 ) ;
}
V_2 = F_6 ( V_7 , 0x200 ) ;
if ( V_2 ) {
F_10 ( F_11 ( V_2 + V_8 ) | ( 3 << 26 ) , V_2 + V_8 ) ;
F_9 ( V_2 ) ;
}
F_12 ( NULL , V_9 , NULL , NULL ) ;
}
