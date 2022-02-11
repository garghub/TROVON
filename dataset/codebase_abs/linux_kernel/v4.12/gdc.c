void F_1 (
const T_1 V_1 ,
const int V_2 [ 4 ] [ V_3 ] )
{
unsigned int V_4 , V_5 = V_6 ;
assert ( V_1 < V_7 ) ;
assert ( V_8 <= ( 4 * sizeof( V_9 ) ) ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_9 V_10 = V_2 [ 0 ] [ V_4 ] & V_11 ;
V_9 V_12 = V_2 [ 1 ] [ V_4 ] & V_11 ;
V_9 V_13 = V_2 [ 2 ] [ V_4 ] & V_11 ;
V_9 V_14 = V_2 [ 3 ] [ V_4 ] & V_11 ;
V_9 V_15 = V_10 |
( V_12 << V_8 ) ;
V_9 V_16 = V_13 |
( V_14 << V_8 ) ;
F_2 ( V_1 , V_5 ++ , V_15 ) ;
F_2 ( V_1 , V_5 ++ , V_16 ) ;
}
return;
}
void F_3 ( const int V_17 [ 4 ] [ V_3 ] ,
int V_18 [ 4 ] [ V_3 ] )
{
unsigned int V_4 ;
int * V_19 = ( int * ) V_18 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_19 [ 0 ] = V_17 [ 0 ] [ V_4 ] ;
V_19 [ 1 ] = V_17 [ 1 ] [ V_4 ] ;
V_19 [ 2 ] = V_17 [ 2 ] [ V_4 ] ;
V_19 [ 3 ] = V_17 [ 3 ] [ V_4 ] ;
V_19 += 4 ;
}
}
int F_4 (
const T_1 V_1 )
{
assert ( V_1 < V_7 ) ;
( void ) V_1 ;
return ( int ) ( 1UL << V_20 ) ;
}
T_2 void F_2 (
const T_1 V_1 ,
const unsigned int V_21 ,
const V_9 V_22 )
{
F_5 ( V_23 [ V_1 ] + V_21 * sizeof( V_9 ) , V_22 ) ;
return;
}
T_2 V_9 F_6 (
const T_1 V_1 ,
const unsigned int V_21 )
{
return F_7 ( V_23 [ V_1 ] + V_21 * sizeof( V_9 ) ) ;
}
