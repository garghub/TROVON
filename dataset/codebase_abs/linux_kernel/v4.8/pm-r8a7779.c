static void T_1 F_1 ( void )
{
F_2 ( 0xffd85000 , 0x0131000e ) ;
}
static inline void F_1 ( void ) {}
void T_1 F_3 ( void )
{
static int V_1 ;
if ( ! V_1 ++ )
F_1 () ;
}
