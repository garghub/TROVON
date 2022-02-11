static void T_1 F_1 ( void )
{
if ( F_2 ( L_1 ) ) {
struct V_1 * V_2 ;
void T_2 * V_3 ;
V_3 = F_3 ( V_4 , V_5 ) ;
if ( V_3 ) {
F_4 ( 0 , V_3 + 0x30 ) ;
F_4 ( 0xffffffff , V_3 + 0x20 ) ;
F_4 ( 0xffffffff , V_3 + 0x24 ) ;
F_4 ( 1 , V_3 + 0x30 ) ;
F_5 () ;
F_6 ( V_3 ) ;
} else {
F_7 ( L_2 ) ;
}
V_2 = F_8 ( L_3 ) ;
if ( ! F_9 ( V_2 ) )
F_10 ( V_2 , V_6 , 0x10000000 ) ;
else
F_7 ( L_4 ) ;
}
F_11 ( NULL ) ;
F_12 () ;
}
static void T_1 F_13 ( void )
{
F_14 () ;
}
