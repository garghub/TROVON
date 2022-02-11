static void T_1 F_1 ( unsigned int V_1 , unsigned int V_2 )
{
T_2 * V_3 ;
V_3 = ( T_2 * ) V_2 ;
if ( ( V_3 [ 0 ] == 0xffff ) && ( V_3 [ 1 ] == 0xffff ) && ( V_3 [ 2 ] == 0xffff ) )
V_3 = ( T_2 * ) & V_4 [ 0 ] ;
F_2 ( 1 , V_5 + V_6 ) ;
F_2 ( V_3 [ 0 ] , V_1 + V_7 ) ;
F_2 ( V_3 [ 1 ] , V_1 + V_7 + 2 ) ;
F_2 ( V_3 [ 2 ] , V_1 + V_7 + 4 ) ;
}
static void T_1 F_3 ( void )
{
F_2 ( 0x00ec , V_8 ) ;
F_4 ( 0 , 0x0080 ) ;
F_2 ( 1 , V_5 + V_6 ) ;
F_2 ( 0x0067 , V_5 + V_9 ) ;
F_4 ( 0x0080 , 0 ) ;
F_2 ( 0x1180 , V_10 ) ;
F_5 ( V_11 ) ;
F_5 ( V_12 ) ;
F_1 ( V_5 , 0xf0006000 ) ;
F_1 ( V_13 , 0xf0006006 ) ;
}
static int T_1 F_6 ( void )
{
F_3 () ;
F_7 ( V_14 , F_8 ( V_14 ) ) ;
return 0 ;
}
