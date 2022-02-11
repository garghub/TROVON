static void F_1 ( void )
{
unsigned V_1 , V_2 ;
T_1 V_3 = 1 ;
V_4 [ 0 ] [ 0 ] = 0 ;
for ( V_1 = 1 << ( V_5 - 1 ) ; V_1 ; V_1 >>= 1 ) {
V_3 = ( V_3 >> 1 ) ^ ( ( V_3 & 1 ) ? V_6 : 0 ) ;
for ( V_2 = 0 ; V_2 < V_7 ; V_2 += 2 * V_1 )
V_4 [ 0 ] [ V_1 + V_2 ] = V_3 ^ V_4 [ 0 ] [ V_2 ] ;
}
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
V_3 = V_4 [ 0 ] [ V_1 ] ;
for ( V_2 = 1 ; V_2 < 4 ; V_2 ++ ) {
V_3 = V_4 [ 0 ] [ V_3 & 0xff ] ^ ( V_3 >> 8 ) ;
V_4 [ V_2 ] [ V_1 ] = V_3 ;
}
}
}
static void F_2 ( void )
{
unsigned V_1 , V_2 ;
T_1 V_3 = 0x80000000 ;
V_8 [ 0 ] [ 0 ] = 0 ;
for ( V_1 = 1 ; V_1 < V_9 ; V_1 <<= 1 ) {
V_3 = ( V_3 << 1 ) ^ ( ( V_3 & 0x80000000 ) ? V_10 : 0 ) ;
for ( V_2 = 0 ; V_2 < V_1 ; V_2 ++ )
V_8 [ 0 ] [ V_1 + V_2 ] = V_3 ^ V_8 [ 0 ] [ V_2 ] ;
}
for ( V_1 = 0 ; V_1 < V_9 ; V_1 ++ ) {
V_3 = V_8 [ 0 ] [ V_1 ] ;
for ( V_2 = 1 ; V_2 < 4 ; V_2 ++ ) {
V_3 = V_8 [ 0 ] [ ( V_3 >> 24 ) & 0xff ] ^ ( V_3 << 8 ) ;
V_8 [ V_2 ] [ V_1 ] = V_3 ;
}
}
}
static void F_3 ( T_1 V_11 [ 4 ] [ 256 ] , int V_12 , char * V_13 )
{
int V_1 , V_2 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
printf ( L_1 ) ;
for ( V_1 = 0 ; V_1 < V_12 - 1 ; V_1 ++ ) {
if ( V_1 % V_14 == 0 )
printf ( L_2 ) ;
printf ( L_3 , V_13 , V_11 [ V_2 ] [ V_1 ] ) ;
}
printf ( L_4 , V_13 , V_11 [ V_2 ] [ V_12 - 1 ] ) ;
}
}
int main ( int V_15 , char * * V_16 )
{
printf ( L_5 ) ;
if ( V_5 > 1 ) {
F_1 () ;
printf ( L_6 ) ;
F_3 ( V_4 , V_7 , L_7 ) ;
printf ( L_8 ) ;
}
if ( V_17 > 1 ) {
F_2 () ;
printf ( L_9 ) ;
F_3 ( V_8 , V_9 , L_10 ) ;
printf ( L_8 ) ;
}
return 0 ;
}
