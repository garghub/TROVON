static void T_1 F_1 ( void )
{
F_2 () ;
}
static void T_1 F_3 ( struct V_1 * V_2 , char * * V_3 ,
struct V_4 * V_5 )
{
V_5 -> V_6 = 1 ;
V_5 -> V_7 [ 0 ] . V_8 = V_9 ;
V_5 -> V_7 [ 0 ] . V_10 = ( 101 * 1024 * 1024 ) ;
}
static void T_1 F_4 ( void )
{
int V_11 ;
F_5 ( V_12 , F_6 ( V_12 ) ) ;
#ifdef F_7
V_11 = F_8 ( V_13 ) ;
if ( V_11 )
F_9 ( V_14 L_1 , V_15 , V_11 ) ;
#endif
}
static void T_1 F_10 ( void )
{
F_11 () ;
F_12 ( V_16 , F_6 ( V_16 ) ) ;
#ifdef F_13
F_14 ( 0x80 , V_17 + 0x00 ) ;
#endif
F_15 ( V_18 , V_19 ) ;
}
