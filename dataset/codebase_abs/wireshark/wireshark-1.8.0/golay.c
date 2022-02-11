static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = 0 ;
T_1 V_3 ;
for( V_3 = 0 ; V_3 < 12 ; V_3 ++ )
if( V_1 & 1 << V_3 )
V_2 ++ ;
return V_2 ;
}
static T_1 F_2 ( T_1 V_2 )
{
T_1 V_4 = 0 ;
T_1 V_3 ;
for( V_3 = 0 ; V_3 < 12 ; V_3 ++ ) {
if( V_2 & 1 << V_3 )
V_4 ^= V_5 [ V_3 ] ;
}
return V_4 ;
}
T_2 F_3 ( T_1 V_2 )
{
return ( ( T_2 ) V_2 ) | ( ( T_2 ) F_2 ( V_2 ) ) << 12 ;
}
static T_1 F_4 ( T_1 V_2 )
{
T_1 V_4 = 0 ;
T_1 V_3 ;
for( V_3 = 0 ; V_3 < 12 ; V_3 ++ ) {
if( V_2 & 1 << ( V_3 ) )
V_4 ^= V_6 [ V_3 ] ;
}
return V_4 ;
}
T_3 F_5 ( T_2 V_7 )
{
T_1 V_8 , V_9 ;
T_1 V_10 ;
T_1 V_2 , V_3 ;
T_1 V_11 = 0 ;
V_9 = ( T_1 ) ( V_7 >> 12 ) ;
V_8 = ( T_1 ) V_7 & 0xfff ;
V_10 = V_9 ^ ( F_2 ( V_8 ) ) ;
V_2 = F_1 ( V_10 ) ;
if( V_2 <= 3 ) {
return ( ( T_3 ) V_10 ) << 12 ;
}
for( V_3 = 0 ; V_3 < 12 ; V_3 ++ ) {
T_1 error = 1 << V_3 ;
T_1 V_12 = V_5 [ V_3 ] ;
if( F_1 ( V_10 ^ V_12 ) <= 2 ) {
return ( T_3 ) ( ( ( ( T_2 ) ( V_10 ^ V_12 ) ) << 12 ) | ( T_2 ) error ) ;
}
}
V_11 = F_4 ( V_10 ) ;
V_2 = F_1 ( V_11 ) ;
if( V_2 <= 3 ) {
return ( T_3 ) V_11 ;
}
for( V_3 = 0 ; V_3 < 12 ; V_3 ++ ) {
T_1 error = 1 << V_3 ;
T_1 V_12 = V_6 [ V_3 ] ;
if( F_1 ( V_11 ^ V_12 ) <= 2 ) {
T_2 V_13 = ( ( T_2 ) ( V_11 ^ V_12 ) ) | ( ( T_2 ) error ) << 12 ;
return ( T_3 ) V_13 ;
}
}
return - 1 ;
}
T_4 F_6 ( T_2 V_2 )
{
T_1 V_14 = ( T_1 ) V_2 & 0xfff ;
T_3 V_15 = F_5 ( V_2 ) ;
T_1 V_16 ;
if( V_15 == - 1 )
return - 1 ;
V_16 = ( T_1 ) V_15 & 0xfff ;
return ( T_4 ) ( V_14 ^ V_16 ) ;
}
