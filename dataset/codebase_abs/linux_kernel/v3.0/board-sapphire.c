static void T_1 F_1 ( void )
{
F_2 () ;
}
static void T_1 F_3 ( void )
{
F_4 ( V_1 , F_5 ( V_1 ) ) ;
}
static void T_1 F_6 ( struct V_2 * V_3 , struct V_4 * V_5 ,
char * * V_6 , struct V_7 * V_8 )
{
int V_9 = F_7 ( ( const struct V_4 * ) V_5 ) ;
V_8 -> V_10 = 1 ;
V_8 -> V_11 [ 0 ] . V_12 = V_13 ;
V_8 -> V_11 [ 0 ] . V_14 = F_8 ( V_13 ) ;
if ( V_9 == 32 ) {
V_8 -> V_11 [ 0 ] . V_15 = ( 84 * 1024 * 1024 ) ;
} else if ( V_9 == 64 ) {
V_8 -> V_11 [ 0 ] . V_15 = ( 101 * 1024 * 1024 ) ;
} else {
V_9 = 64 ;
V_8 -> V_11 [ 0 ] . V_15 = ( 101 * 1024 * 1024 ) ;
}
}
static void T_1 F_9 ( void )
{
F_10 () ;
F_11 ( V_16 , F_5 ( V_16 ) ) ;
F_12 () ;
}
