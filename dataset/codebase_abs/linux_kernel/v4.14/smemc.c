static int F_1 ( void )
{
V_1 [ 0 ] = F_2 ( V_2 ) ;
V_1 [ 1 ] = F_2 ( V_3 ) ;
V_4 = F_2 ( V_5 ) ;
V_6 = F_2 ( V_7 ) ;
V_8 [ 0 ] = F_2 ( V_9 ) ;
V_8 [ 1 ] = F_2 ( V_10 ) ;
V_8 [ 2 ] = F_2 ( V_11 ) ;
V_8 [ 3 ] = F_2 ( V_12 ) ;
return 0 ;
}
static void F_3 ( void )
{
F_4 ( V_1 [ 0 ] , V_2 ) ;
F_4 ( V_1 [ 1 ] , V_3 ) ;
F_4 ( V_4 , V_5 ) ;
F_4 ( V_6 , V_7 ) ;
F_4 ( V_8 [ 0 ] , V_9 ) ;
F_4 ( V_8 [ 1 ] , V_10 ) ;
F_4 ( V_8 [ 2 ] , V_11 ) ;
F_4 ( V_8 [ 3 ] , V_12 ) ;
F_4 ( 0x2 , V_13 ) ;
}
static int T_1 F_5 ( void )
{
if ( F_6 () ) {
F_4 ( 0x2 , V_13 ) ;
F_7 ( & V_14 ) ;
}
return 0 ;
}
