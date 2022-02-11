static void T_1 F_1 ( void )
{
F_2 () ;
}
static void T_1 F_3 ( void )
{
F_4 ( V_1 , F_5 ( V_1 ) ) ;
}
static void T_1 F_6 ( struct V_2 * V_3 , char * * V_4 ,
struct V_5 * V_6 )
{
int V_7 = F_7 ( ( const struct V_2 * ) V_3 ) ;
V_6 -> V_8 = 1 ;
V_6 -> V_9 [ 0 ] . V_10 = V_11 ;
V_6 -> V_9 [ 0 ] . V_12 = F_8 ( V_11 ) ;
if ( V_7 == 32 ) {
V_6 -> V_9 [ 0 ] . V_13 = ( 84 * 1024 * 1024 ) ;
} else if ( V_7 == 64 ) {
V_6 -> V_9 [ 0 ] . V_13 = ( 101 * 1024 * 1024 ) ;
} else {
V_7 = 64 ;
V_6 -> V_9 [ 0 ] . V_13 = ( 101 * 1024 * 1024 ) ;
}
}
static void T_1 F_9 ( void )
{
F_10 () ;
F_11 ( V_14 , F_5 ( V_14 ) ) ;
F_12 () ;
}
