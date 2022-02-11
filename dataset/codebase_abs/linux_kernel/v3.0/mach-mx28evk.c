static void T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * V_2 ;
V_2 = F_2 ( L_1 , NULL ) ;
if ( ! F_3 ( V_2 ) )
F_4 ( V_2 ) ;
V_1 = F_5 ( V_3 , L_2 ) ;
if ( V_1 ) {
F_6 ( L_3 , L_4 , V_1 ) ;
return;
}
V_1 = F_7 ( V_3 , 0 ) ;
if ( V_1 ) {
F_6 ( L_5 , L_4 , V_1 ) ;
return;
}
V_1 = F_5 ( V_4 , L_6 ) ;
if ( V_1 ) {
F_6 ( L_3 , L_7 , V_1 ) ;
return;
}
F_7 ( V_4 , 0 ) ;
if ( V_1 ) {
F_6 ( L_5 , L_7 , V_1 ) ;
return;
}
F_8 ( 1 ) ;
F_9 ( V_4 , 1 ) ;
}
static int T_1 F_10 ( void )
{
int V_5 ;
T_2 V_6 ;
const T_2 * V_7 = F_11 () ;
if ( ! V_7 )
goto error;
for ( V_5 = 0 ; V_5 < 2 ; V_5 ++ ) {
V_6 = V_7 [ V_5 * 4 ] ;
V_8 [ V_5 ] . V_9 [ 0 ] = 0x00 ;
V_8 [ V_5 ] . V_9 [ 1 ] = 0x04 ;
V_8 [ V_5 ] . V_9 [ 2 ] = 0x9f ;
V_8 [ V_5 ] . V_9 [ 3 ] = ( V_6 >> 16 ) & 0xff ;
V_8 [ V_5 ] . V_9 [ 4 ] = ( V_6 >> 8 ) & 0xff ;
V_8 [ V_5 ] . V_9 [ 5 ] = ( V_6 >> 0 ) & 0xff ;
}
return 0 ;
error:
F_6 ( L_8 , V_10 ) ;
return - V_11 ;
}
static void F_12 ( void )
{
if ( V_12 || V_13 )
F_9 ( V_14 , 1 ) ;
else
F_9 ( V_14 , 0 ) ;
}
static void F_13 ( int V_15 )
{
V_12 = V_15 ;
F_12 () ;
}
static void F_14 ( int V_15 )
{
V_13 = V_15 ;
F_12 () ;
}
static void T_1 F_15 ( void )
{
int V_1 ;
F_16 ( V_16 , F_17 ( V_16 ) ) ;
F_18 () ;
F_19 () ;
F_20 () ;
if ( F_10 () )
F_21 ( L_9 , V_10 ) ;
F_1 () ;
F_22 ( 0 , & V_8 [ 0 ] ) ;
F_22 ( 1 , & V_8 [ 1 ] ) ;
V_1 = F_23 ( V_14 , V_17 ,
L_10 ) ;
if ( V_1 ) {
F_6 ( L_11 , V_1 ) ;
} else {
F_24 ( 0 , & V_18 [ 0 ] ) ;
F_24 ( 1 , & V_18 [ 1 ] ) ;
}
V_1 = F_23 ( V_19 , V_17 , L_12 ) ;
if ( V_1 )
F_21 ( L_13 , V_1 ) ;
else
F_9 ( V_19 , 1 ) ;
V_1 = F_23 ( V_20 , V_17 , L_14 ) ;
if ( V_1 )
F_21 ( L_15 , V_1 ) ;
else
F_9 ( V_20 , 1 ) ;
F_25 ( & V_21 ) ;
V_1 = F_23 ( V_22 , V_23 ,
L_16 ) ;
if ( V_1 )
F_21 ( L_17 , V_1 ) ;
F_26 ( 0 , & V_24 [ 0 ] ) ;
V_1 = F_23 ( V_25 , V_23 ,
L_18 ) ;
if ( V_1 )
F_21 ( L_19 , V_1 ) ;
F_26 ( 1 , & V_24 [ 1 ] ) ;
}
static void T_1 F_27 ( void )
{
F_28 () ;
}
