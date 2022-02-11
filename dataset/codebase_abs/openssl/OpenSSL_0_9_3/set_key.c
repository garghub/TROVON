void F_1 ( T_1 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
( * V_1 ) [ V_2 ] = V_4 [ ( * V_1 ) [ V_2 ] ] ;
}
static int F_2 ( T_2 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
{
if ( ( * V_1 ) [ V_2 ] != V_4 [ ( * V_1 ) [ V_2 ] ] )
return ( 0 ) ;
}
return ( 1 ) ;
}
int F_3 ( T_2 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ )
if ( memcmp ( V_6 [ V_2 ] , V_1 , sizeof( T_1 ) ) == 0 ) return ( 1 ) ;
return ( 0 ) ;
}
int F_4 ( T_2 * V_1 , T_3 V_7 )
{
static int V_8 [ 16 ] = { 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 } ;
register T_4 V_9 , V_10 , V_11 , V_12 , V_13 ;
register const unsigned char * V_14 ;
register T_4 * V_15 ;
register int V_2 ;
if ( V_16 )
{
if ( ! F_2 ( V_1 ) )
return ( - 1 ) ;
if ( F_3 ( V_1 ) )
return ( - 2 ) ;
}
V_15 = ( T_4 * ) V_7 ;
V_14 = & ( * V_1 ) [ 0 ] ;
F_5 ( V_14 , V_9 ) ;
F_5 ( V_14 , V_10 ) ;
F_6 ( V_10 , V_9 , V_11 , 4 , 0x0f0f0f0fL ) ;
F_7 ( V_9 , V_11 , - 2 , 0xcccc0000L ) ;
F_7 ( V_10 , V_11 , - 2 , 0xcccc0000L ) ;
F_6 ( V_10 , V_9 , V_11 , 1 , 0x55555555L ) ;
F_6 ( V_9 , V_10 , V_11 , 8 , 0x00ff00ffL ) ;
F_6 ( V_10 , V_9 , V_11 , 1 , 0x55555555L ) ;
V_10 = ( ( ( V_10 & 0x000000ffL ) << 16L ) | ( V_10 & 0x0000ff00L ) |
( ( V_10 & 0x00ff0000L ) >> 16L ) | ( ( V_9 & 0xf0000000L ) >> 4L ) ) ;
V_9 &= 0x0fffffffL ;
for ( V_2 = 0 ; V_2 < V_17 ; V_2 ++ )
{
if ( V_8 [ V_2 ] )
{ V_9 = ( ( V_9 >> 2L ) | ( V_9 << 26L ) ) ; V_10 = ( ( V_10 >> 2L ) | ( V_10 << 26L ) ) ; }
else
{ V_9 = ( ( V_9 >> 1L ) | ( V_9 << 27L ) ) ; V_10 = ( ( V_10 >> 1L ) | ( V_10 << 27L ) ) ; }
V_9 &= 0x0fffffffL ;
V_10 &= 0x0fffffffL ;
V_12 = V_18 [ 0 ] [ ( V_9 ) & 0x3f ] |
V_18 [ 1 ] [ ( ( V_9 >> 6 ) & 0x03 ) | ( ( V_9 >> 7L ) & 0x3c ) ] |
V_18 [ 2 ] [ ( ( V_9 >> 13 ) & 0x0f ) | ( ( V_9 >> 14L ) & 0x30 ) ] |
V_18 [ 3 ] [ ( ( V_9 >> 20 ) & 0x01 ) | ( ( V_9 >> 21L ) & 0x06 ) |
( ( V_9 >> 22L ) & 0x38 ) ] ;
V_11 = V_18 [ 4 ] [ ( V_10 ) & 0x3f ] |
V_18 [ 5 ] [ ( ( V_10 >> 7L ) & 0x03 ) | ( ( V_10 >> 8L ) & 0x3c ) ] |
V_18 [ 6 ] [ ( V_10 >> 15L ) & 0x3f ] |
V_18 [ 7 ] [ ( ( V_10 >> 21L ) & 0x0f ) | ( ( V_10 >> 22L ) & 0x30 ) ] ;
V_13 = ( ( V_11 << 16L ) | ( V_12 & 0x0000ffffL ) ) & 0xffffffffL ;
* ( V_15 ++ ) = F_8 ( V_13 , 30 ) & 0xffffffffL ;
V_13 = ( ( V_12 >> 16L ) | ( V_11 & 0xffff0000L ) ) ;
* ( V_15 ++ ) = F_8 ( V_13 , 26 ) & 0xffffffffL ;
}
return ( 0 ) ;
}
int F_9 ( T_2 * V_1 , T_3 V_7 )
{
return ( F_4 ( V_1 , V_7 ) ) ;
}
