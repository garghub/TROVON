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
#ifdef F_7
if ( V_1 )
F_8 ( & V_2 ) ;
else
F_8 ( & V_3 ) ;
#endif
#ifdef F_9
if ( V_1 )
F_8 ( & V_4 ) ;
else
F_8 ( & V_3 ) ;
#endif
}
static void T_1 F_4 ( void )
{
#ifdef F_10
struct V_5 V_6 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_7 = 0x3f8 ;
V_6 . V_8 = 0 ;
V_6 . V_9 = 1843200 ;
V_6 . V_10 = V_11 | V_12 ;
V_6 . V_13 = V_14 ;
V_6 . V_15 = 0 ;
V_6 . V_16 = 4 ;
if ( F_11 ( & V_6 ) != 0 ) {
F_12 ( V_17 L_2 ) ;
}
#endif
}
