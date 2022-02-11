static void F_1 ( void )
{
volatile unsigned long T_1 * V_1 ;
unsigned long V_2 ;
int V_3 , V_4 ;
V_1 = F_2 ( V_5 , V_6 ) ;
if( ! V_1 ) {
for( V_3 = 0 ; V_3 < V_7 ; V_3 ++ )
V_8 [ V_3 ] . V_9 = V_10 [ V_3 ] . V_11 ;
return;
}
for( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
for( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_2 = V_1 [ F_3 ( V_4 ) ] ;
if( ( V_2 & V_13 ) == V_10 [ V_3 ] . V_14 )
{
V_1 [ F_3 ( V_4 ) ] = V_10 [ V_3 ] . V_15 ;
break;
}
}
if( V_4 == V_12 )
{
F_4 ( V_16 L_1 ,
V_8 [ V_3 ] . V_17 ) ;
F_4 ( V_16 L_2 ,
V_10 [ V_3 ] . V_11 ) ;
V_8 [ V_3 ] . V_9 = V_10 [ V_3 ] . V_11 ;
}
}
F_5 ( V_1 ) ;
}
static int T_2 F_6 ( void )
{
int V_3 , V_18 = 0 ;
#ifdef F_7
F_1 () ;
#endif
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
F_4 ( V_16 L_3 ,
( unsigned long long ) V_8 [ V_3 ] . V_19 ,
( unsigned long long ) V_8 [ V_3 ] . V_9 ) ;
V_8 [ V_3 ] . V_20 = F_2 ( V_8 [ V_3 ] . V_9 , V_8 [ V_3 ] . V_19 ) ;
if ( ! V_8 [ V_3 ] . V_20 ) {
F_4 ( L_4 ) ;
return - V_21 ;
}
F_8 ( & V_8 [ V_3 ] ) ;
V_22 [ V_3 ] = F_9 ( L_5 , & V_8 [ V_3 ] ) ;
if( ! V_22 [ V_3 ] )
V_22 [ V_3 ] = F_9 ( L_6 , & V_8 [ V_3 ] ) ;
if( ! V_22 [ V_3 ] )
V_22 [ V_3 ] = F_9 ( L_7 , & V_8 [ V_3 ] ) ;
if ( V_22 [ V_3 ] ) {
V_22 [ V_3 ] -> V_23 = V_24 ;
++ V_18 ;
}
else {
F_5 ( V_8 [ V_3 ] . V_20 ) ;
}
}
if( V_18 >= 2 ) {
V_25 = F_10 ( V_22 , 2 , L_8 ) ;
if( V_25 )
F_11 ( V_25 , NULL , 0 ) ;
}
if( V_18 == 3 )
F_11 ( V_22 [ 2 ] , NULL , 0 ) ;
return ( V_18 ? 0 : - V_26 ) ;
}
static void T_3 F_12 ( void )
{
int V_3 ;
if ( V_25 ) {
F_13 ( V_25 ) ;
F_14 ( V_25 ) ;
}
if ( V_22 [ 2 ] )
F_13 ( V_22 [ 2 ] ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( V_22 [ V_3 ] )
F_15 ( V_22 [ V_3 ] ) ;
if ( V_8 [ V_3 ] . V_20 ) {
F_5 ( V_8 [ V_3 ] . V_20 ) ;
V_8 [ V_3 ] . V_20 = NULL ;
}
}
}
