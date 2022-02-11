T_1 F_1 ( T_1 V_1 , T_2 V_2 , T_2 V_3 ) {
int V_4 ;
T_3 V_5 = ( V_2 << 8 | V_3 ) << 6 ;
T_3 V_6 = 0x6F << 15 ;
for ( V_4 = 15 ;
V_4 >= 0 ;
-- V_4 )
{
if ( V_5 & ( 0x40 << V_4 ) )
{
V_5 ^= V_6 ;
}
V_6 >>= 1 ;
}
return ( T_1 ) ( V_5 ^ V_1 ) ;
}
T_1 F_2 ( const T_2 * V_7 , int V_8 )
{
T_1 V_9 ;
int V_10 ;
V_9 = 0 ;
V_10 = 0 ;
if ( V_8 == 0 )
{
return 0 ;
}
do
{
V_9 = ( V_9 << 8 ) | V_7 [ V_10 ] ;
V_9 = V_11 [ V_9 ] ;
V_10 ++ ;
}
while ( V_10 < V_8 );
return V_9 ;
}
