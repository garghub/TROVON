const char * F_1 ( void )
{
return L_1 ;
}
void T_1 F_2 ( void )
{
F_3 ( 0xbfd00000 ) ;
F_4 () ;
}
void T_1 F_5 ( void )
{
F_3 ( 0xbfd00000 ) ;
F_6 () ;
if ( V_1 ) {
if ( ! F_7 () )
return;
#ifdef F_8
F_9 ( & V_2 ) ;
return;
#endif
}
F_10 () ;
}
static void T_1 F_4 ( void )
{
#ifdef F_11
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_5 = 0x3f8 ;
V_4 . V_6 = 0 ;
V_4 . V_7 = 1843200 ;
V_4 . V_8 = V_9 | V_10 ;
V_4 . V_11 = V_12 ;
V_4 . V_13 = 0 ;
V_4 . V_14 = 4 ;
if ( F_12 ( & V_4 ) != 0 ) {
F_13 ( V_15 L_2 ) ;
}
#endif
}
