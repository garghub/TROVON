static void
F_1 ( T_1 * V_1 )
{
int V_2 , V_3 ;
T_1 V_4 ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
V_4 = V_2 ;
for ( V_3 = 8 ; V_3 > 0 ; V_3 -- ) {
if ( V_4 & 1 )
V_4 = ( V_4 >> 1 ) ^ V_6 ;
else
V_4 >>= 1 ;
}
V_1 [ V_2 ] = V_4 ;
}
V_7 ++ ;
}
void
F_2 ( T_2 * V_8 ,
T_1 V_9 ,
T_1 V_10 ,
T_1 * V_11 )
{
T_1 * V_12 = NULL ;
T_1 V_13 , V_14 , V_4 ;
if ( ! V_7 ) {
#ifdef F_3
V_12 = & V_1 ;
F_1 ( V_12 ) ;
#else
V_12 = F_4 ( V_5 * sizeof( T_1 ) ,
V_15 ) ;
if ( ! V_12 ) {
* V_11 = 0 ;
return;
}
F_1 ( V_12 ) ;
#endif
}
V_4 = V_10 ^ 0xFFFFFFFFL ;
while ( V_9 -- != 0 ) {
V_13 = ( V_4 >> 8 ) & 0x00FFFFFFL ;
V_14 = V_12 [ ( ( int ) V_4 ^ * V_8 ++ ) & 0xff ] ;
V_4 = V_13 ^ V_14 ;
}
V_4 ^= 0xFFFFFFFFL ;
* V_11 = V_4 ;
#ifndef F_3
V_7 = 0 ;
F_5 ( V_12 ) ;
#endif
}
