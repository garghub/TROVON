static int F_1 ( const T_1 V_1 ,
unsigned char * V_2 , int V_3 )
{
const unsigned char * V_4 ;
unsigned char V_5 = V_1 & 0xFF ;
unsigned char V_6 = ( V_1 >> 8 ) & 0xFF ;
unsigned char V_7 , V_8 ;
if ( V_3 <= 0 )
return - V_9 ;
if ( V_1 == 0x20ac ) {
V_2 [ 0 ] = 0x80 ;
return 1 ;
}
if ( V_6 == 0 ) {
V_7 = V_10 [ V_5 * 2 ] ;
V_8 = V_10 [ V_5 * 2 + 1 ] ;
if ( V_7 == 0x00 && V_8 == 0x00 ) {
if ( V_5 < 0x80 ) {
V_2 [ 0 ] = V_5 ;
return 1 ;
}
return - V_11 ;
} else {
if ( V_3 <= 1 )
return - V_9 ;
V_2 [ 0 ] = V_7 ;
V_2 [ 1 ] = V_8 ;
return 2 ;
}
}
V_4 = V_12 [ V_6 ] ;
if ( V_4 ) {
if ( V_3 <= 1 )
return - V_9 ;
V_2 [ 0 ] = V_4 [ V_5 * 2 ] ;
V_2 [ 1 ] = V_4 [ V_5 * 2 + 1 ] ;
if ( V_2 [ 0 ] == 0x00 && V_2 [ 1 ] == 0x00 )
return - V_11 ;
return 2 ;
}
else
return - V_11 ;
}
static int F_2 ( const unsigned char * V_13 , int V_3 ,
T_1 * V_1 )
{
unsigned char V_6 , V_5 ;
const T_1 * V_14 ;
int V_15 ;
if ( V_3 <= 0 )
return - V_9 ;
if ( V_3 == 1 ) {
if ( V_13 [ 0 ] == 0x80 ) {
* V_1 = 0x20ac ;
} else {
* V_1 = V_13 [ 0 ] ;
}
return 1 ;
}
V_6 = V_13 [ 0 ] ;
V_5 = V_13 [ 1 ] ;
V_14 = V_16 [ V_6 ] ;
if ( V_14 && V_5 ) {
* V_1 = V_14 [ V_5 ] ;
if ( * V_1 == 0x0000 )
return - V_11 ;
V_15 = 2 ;
} else{
if ( V_6 == 0x80 ) {
* V_1 = 0x20ac ;
} else {
* V_1 = V_6 ;
}
V_15 = 1 ;
}
return V_15 ;
}
static int T_2 F_3 ( void )
{
return F_4 ( & V_17 ) ;
}
static void T_3 F_5 ( void )
{
F_6 ( & V_17 ) ;
}
