static unsigned int T_1 F_1 ( T_2 T_3 * V_1 )
{
T_2 V_2 ;
unsigned int V_3 ;
unsigned int V_4 ;
unsigned int V_5 ;
unsigned int V_6 ;
unsigned int V_7 ;
unsigned int V_8 = 0 ;
unsigned int V_9 = 0 ;
unsigned int V_10 = 0 ;
unsigned int V_11 = 0 ;
V_2 = F_2 ( V_1 ) ;
V_3 = ( ( V_2 & ( 1 << 10 ) ) >> 10 ) ;
V_4 = ( ( V_2 & ( 1 << 8 ) ) >> 8 ) ;
V_5 = ( ( V_2 & ( 3 << 5 ) ) >> 5 ) ;
V_6 = ( ( V_2 & ( 7 << 2 ) ) >> 2 ) ;
V_7 = ( ( V_2 & ( 1 << 0 ) ) >> 0 ) ;
if ( V_3 ) {
V_8 = 2 << V_4 ;
V_9 = 2048 << V_5 ;
V_10 = 256 << V_6 ;
V_11 = 8 >> V_7 ;
}
return V_9 * V_10 * V_11 * V_8 ;
}
unsigned int T_1 F_3 ( void )
{
unsigned int V_12 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_14 -> V_15 ) ; V_13 ++ )
V_12 += F_1 ( & V_14 -> V_15 [ V_13 ] ) ;
return V_12 ;
}
