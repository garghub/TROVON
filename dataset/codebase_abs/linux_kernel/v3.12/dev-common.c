void T_1 F_1 ( void )
{
unsigned long V_1 ;
V_1 = F_2 ( L_1 ) ;
if ( F_3 () ||
F_4 () ||
F_5 () ||
F_6 () ||
F_7 () ) {
V_2 [ 0 ] . V_3 = V_1 ;
F_8 ( & V_4 ) ;
} else if ( F_9 () ) {
V_5 . V_3 = V_1 ;
F_8 ( & V_6 ) ;
} else {
F_10 () ;
}
}
void T_1 F_11 ( void )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_9 = V_10 ;
V_8 . V_11 = V_12 + V_13 ;
V_8 . V_14 = V_8 . V_11 + 0x8 - 1 ;
F_12 ( L_2 , - 1 , & V_8 , 1 ) ;
}
