static void T_1 F_1 ( void )
{
void T_2 * V_1 = F_2 ( 0xffd85000 ) ;
F_3 ( 0x0131000e , V_1 + V_2 ) ;
F_3 ( 0 , V_1 + V_3 ) ;
}
static inline void F_1 ( void ) {}
void T_1 F_4 ( void )
{
static int V_4 ;
if ( ! V_4 ++ )
F_1 () ;
}
