static int T_1 F_1 ( void )
{
int V_1 ;
T_2 V_2 ;
const T_2 * V_3 = F_2 () ;
if ( ! V_3 )
return - V_4 ;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
V_2 = V_3 [ V_1 ] ;
V_5 [ V_1 ] . V_6 [ 0 ] = 0xC0 ;
V_5 [ V_1 ] . V_6 [ 1 ] = 0xE5 ;
V_5 [ V_1 ] . V_6 [ 2 ] = 0x4E ;
V_5 [ V_1 ] . V_6 [ 3 ] = ( V_2 >> 16 ) & 0xff ;
V_5 [ V_1 ] . V_6 [ 4 ] = ( V_2 >> 8 ) & 0xff ;
V_5 [ V_1 ] . V_6 [ 5 ] = ( V_2 >> 0 ) & 0xff ;
}
return 0 ;
}
static void T_1 F_3 ( void )
{
F_4 ( V_7 , F_5 ( V_7 ) ) ;
F_6 () ;
F_7 () ;
F_8 () ;
if ( ! F_1 () ) {
F_9 ( 0 , & V_5 [ 0 ] ) ;
F_9 ( 1 , & V_5 [ 1 ] ) ;
}
F_10 ( 0 , NULL ) ;
F_10 ( 1 , NULL ) ;
F_11 ( & V_8 ) ;
F_12 ( 0 , & V_9 [ 0 ] ) ;
F_12 ( 1 , & V_9 [ 1 ] ) ;
F_13 ( 0 , & V_10 ) ;
F_14 ( 0 ) ;
F_15 ( 0 , V_11 ,
F_5 ( V_11 ) ) ;
}
static void T_1 F_16 ( void )
{
F_17 () ;
}
