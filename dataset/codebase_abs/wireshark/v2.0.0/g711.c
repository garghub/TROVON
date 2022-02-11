static int
F_1 (
int V_1 ,
short * V_2 ,
int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( V_1 <= * V_2 ++ )
return ( V_4 ) ;
}
return ( V_3 ) ;
}
unsigned char
F_2 (
int V_5 )
{
int V_6 ;
int V_7 ;
unsigned char V_8 ;
if ( V_5 >= 0 ) {
V_6 = 0xD5 ;
} else {
V_6 = 0x55 ;
V_5 = - V_5 - 8 ;
}
V_7 = F_1 ( V_5 , V_9 , 8 ) ;
if ( V_7 >= 8 )
return ( 0x7F ^ V_6 ) ;
else {
V_8 = V_7 << V_10 ;
if ( V_7 < 2 )
V_8 |= ( V_5 >> 4 ) & V_11 ;
else
V_8 |= ( V_5 >> ( V_7 + 3 ) ) & V_11 ;
return ( V_8 ^ V_6 ) ;
}
}
int
F_3 (
unsigned char V_12 )
{
int V_13 ;
int V_7 ;
V_12 ^= 0x55 ;
V_13 = ( V_12 & V_11 ) << 4 ;
V_7 = ( ( unsigned ) V_12 & V_14 ) >> V_10 ;
switch ( V_7 ) {
case 0 :
V_13 += 8 ;
break;
case 1 :
V_13 += 0x108 ;
break;
default:
V_13 += 0x108 ;
V_13 <<= V_7 - 1 ;
}
return ( ( V_12 & V_15 ) ? V_13 : - V_13 ) ;
}
unsigned char
F_4 (
int V_5 )
{
int V_6 ;
int V_7 ;
unsigned char V_16 ;
if ( V_5 < 0 ) {
V_5 = V_17 - V_5 ;
V_6 = 0x7F ;
} else {
V_5 += V_17 ;
V_6 = 0xFF ;
}
V_7 = F_1 ( V_5 , V_9 , 8 ) ;
if ( V_7 >= 8 )
return ( 0x7F ^ V_6 ) ;
else {
V_16 = ( V_7 << 4 ) | ( ( V_5 >> ( V_7 + 3 ) ) & 0xF ) ;
return ( V_16 ^ V_6 ) ;
}
}
int
F_5 (
unsigned char V_18 )
{
int V_13 ;
V_18 = ~ V_18 ;
V_13 = ( ( V_18 & V_11 ) << 3 ) + V_17 ;
V_13 <<= ( ( unsigned ) V_18 & V_14 ) >> V_10 ;
return ( ( V_18 & V_15 ) ? ( V_17 - V_13 ) : ( V_13 - V_17 ) ) ;
}
