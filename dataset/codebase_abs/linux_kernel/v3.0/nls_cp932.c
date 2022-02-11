static int F_1 ( const T_1 V_1 ,
unsigned char * V_2 , int V_3 )
{
const unsigned char * V_4 ;
unsigned char V_5 = V_1 & 0xFF ;
unsigned char V_6 = ( V_1 >> 8 ) & 0xFF ;
if ( V_3 <= 0 )
return - V_7 ;
if ( V_6 == 0xFF && 0x61 <= V_5 && V_5 <= 0x9F ) {
V_2 [ 0 ] = V_5 + 0x40 ;
return 1 ;
}
V_4 = V_8 [ V_6 ] ;
if ( V_4 ) {
if ( V_3 < 2 )
return - V_7 ;
V_2 [ 0 ] = V_4 [ V_5 * 2 ] ;
V_2 [ 1 ] = V_4 [ V_5 * 2 + 1 ] ;
if ( V_2 [ 0 ] == 0x00 && V_2 [ 1 ] == 0x00 )
return - V_9 ;
return 2 ;
} else if ( V_6 == 0 ) {
if ( V_5 <= 0x7F ) {
V_2 [ 0 ] = V_5 ;
return 1 ;
} else if ( 0xA0 <= V_5 ) {
V_2 [ 0 ] = V_10 [ V_5 - 0xA0 ] [ 0 ] ;
V_2 [ 1 ] = V_10 [ V_5 - 0xA0 ] [ 1 ] ;
if ( V_2 [ 0 ] && V_2 [ 1 ] )
return 2 ;
}
return - V_9 ;
}
else
return - V_9 ;
}
static int F_2 ( const unsigned char * V_11 , int V_3 ,
T_1 * V_1 )
{
unsigned char V_6 , V_5 ;
const T_1 * V_12 ;
if ( V_3 <= 0 )
return - V_7 ;
if ( V_11 [ 0 ] <= 0x7F ) {
* V_1 = V_11 [ 0 ] ;
return 1 ;
}
if ( 0xA1 <= V_11 [ 0 ] && V_11 [ 0 ] <= 0xDF ) {
* V_1 = 0xFF00 | ( V_11 [ 0 ] - 0x40 ) ;
return 1 ;
}
if ( V_3 < 2 )
return - V_7 ;
V_6 = V_11 [ 0 ] ;
V_5 = V_11 [ 1 ] ;
V_12 = V_13 [ V_6 ] ;
if ( V_12 && V_5 ) {
* V_1 = V_12 [ V_5 ] ;
if ( * V_1 == 0x0000 )
return - V_9 ;
return 2 ;
}
else
return - V_9 ;
}
static int T_2 F_3 ( void )
{
return F_4 ( & V_14 ) ;
}
static void T_3 F_5 ( void )
{
F_6 ( & V_14 ) ;
}
