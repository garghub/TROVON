static void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
V_1 = F_2 ( L_1 , NULL ) ;
if ( ! F_3 ( V_1 ) )
F_4 ( V_1 ) ;
F_5 ( V_2 , 0 ) ;
F_6 ( 1 ) ;
F_5 ( V_2 , 1 ) ;
}
static int T_1 F_7 ( void )
{
int V_3 ;
T_2 V_4 ;
const T_2 * V_5 = F_8 () ;
if ( ! V_5 )
return - V_6 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_4 = V_5 [ V_3 ] ;
V_7 [ V_3 ] . V_8 [ 0 ] = 0x00 ;
V_7 [ V_3 ] . V_8 [ 1 ] = 0x04 ;
V_7 [ V_3 ] . V_8 [ 2 ] = 0x9f ;
V_7 [ V_3 ] . V_8 [ 3 ] = ( V_4 >> 16 ) & 0xff ;
V_7 [ V_3 ] . V_8 [ 4 ] = ( V_4 >> 8 ) & 0xff ;
V_7 [ V_3 ] . V_8 [ 5 ] = ( V_4 >> 0 ) & 0xff ;
}
return 0 ;
}
static void F_9 ( void )
{
if ( V_9 || V_10 )
F_5 ( V_11 , 1 ) ;
else
F_5 ( V_11 , 0 ) ;
}
static void F_10 ( int V_12 )
{
V_9 = V_12 ;
F_9 () ;
}
static void F_11 ( int V_12 )
{
V_10 = V_12 ;
F_9 () ;
}
static void T_1 F_12 ( void )
{
F_13 ( & V_13 ) ;
}
static void T_1 F_12 ( void ) {}
static void T_1 F_14 ( void )
{
int V_14 ;
F_15 () ;
F_16 ( V_15 , F_17 ( V_15 ) ) ;
F_18 () ;
F_19 () ;
F_20 () ;
if ( F_7 () )
F_21 ( L_2 , V_16 ) ;
V_14 = F_22 ( V_17 , F_17 ( V_17 ) ) ;
if ( V_14 )
F_23 ( L_3 , V_14 ) ;
F_1 () ;
F_24 ( 0 , & V_7 [ 0 ] ) ;
F_24 ( 1 , & V_7 [ 1 ] ) ;
F_25 ( 0 , & V_18 [ 0 ] ) ;
F_25 ( 1 , & V_18 [ 1 ] ) ;
F_26 ( & V_19 ) ;
F_27 ( V_20 ) ;
F_28 ( 0 , & V_21 [ 0 ] ) ;
F_28 ( 1 , & V_21 [ 1 ] ) ;
F_29 ( 0 ) ;
F_30 ( 0 , V_22 ,
F_17 ( V_22 ) ) ;
F_12 () ;
F_31 ( L_4 , 0 , NULL , 0 ,
NULL , 0 ) ;
F_32 ( 0 , & V_23 [ 0 ] ) ;
F_32 ( 1 , & V_23 [ 1 ] ) ;
F_33 () ;
F_34 ( 0 , & V_24 ) ;
}
static void T_1 F_35 ( void )
{
F_36 () ;
}
