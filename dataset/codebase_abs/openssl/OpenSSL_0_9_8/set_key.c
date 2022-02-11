void F_1 ( T_1 * V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
( * V_1 ) [ V_2 ] = V_4 [ ( * V_1 ) [ V_2 ] ] ;
}
int F_2 ( T_2 * V_1 )
{
unsigned int V_2 ;
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
int F_4 ( T_2 * V_1 , T_3 * V_7 )
{
if ( V_8 )
{
return F_5 ( V_1 , V_7 ) ;
}
else
{
F_6 ( V_1 , V_7 ) ;
return 0 ;
}
}
int F_5 ( T_2 * V_1 , T_3 * V_7 )
{
if ( ! F_2 ( V_1 ) )
return ( - 1 ) ;
if ( F_3 ( V_1 ) )
return ( - 2 ) ;
F_6 ( V_1 , V_7 ) ;
return 0 ;
}
void F_6 ( T_2 * V_1 , T_3 * V_7 )
{
static int V_9 [ 16 ] = { 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 } ;
register T_4 V_10 , V_11 , V_12 , V_13 , V_14 ;
register const unsigned char * V_15 ;
register T_4 * V_16 ;
register int V_2 ;
#ifdef F_7
memcpy ( V_7 -> V_1 , V_1 , sizeof V_7 -> V_1 ) ;
V_7 -> V_17 = NULL ;
#endif
V_16 = & V_7 -> V_18 -> V_19 [ 0 ] ;
V_15 = & ( * V_1 ) [ 0 ] ;
F_8 ( V_15 , V_10 ) ;
F_8 ( V_15 , V_11 ) ;
F_9 ( V_11 , V_10 , V_12 , 4 , 0x0f0f0f0fL ) ;
F_10 ( V_10 , V_12 , - 2 , 0xcccc0000L ) ;
F_10 ( V_11 , V_12 , - 2 , 0xcccc0000L ) ;
F_9 ( V_11 , V_10 , V_12 , 1 , 0x55555555L ) ;
F_9 ( V_10 , V_11 , V_12 , 8 , 0x00ff00ffL ) ;
F_9 ( V_11 , V_10 , V_12 , 1 , 0x55555555L ) ;
V_11 = ( ( ( V_11 & 0x000000ffL ) << 16L ) | ( V_11 & 0x0000ff00L ) |
( ( V_11 & 0x00ff0000L ) >> 16L ) | ( ( V_10 & 0xf0000000L ) >> 4L ) ) ;
V_10 &= 0x0fffffffL ;
for ( V_2 = 0 ; V_2 < V_20 ; V_2 ++ )
{
if ( V_9 [ V_2 ] )
{ V_10 = ( ( V_10 >> 2L ) | ( V_10 << 26L ) ) ; V_11 = ( ( V_11 >> 2L ) | ( V_11 << 26L ) ) ; }
else
{ V_10 = ( ( V_10 >> 1L ) | ( V_10 << 27L ) ) ; V_11 = ( ( V_11 >> 1L ) | ( V_11 << 27L ) ) ; }
V_10 &= 0x0fffffffL ;
V_11 &= 0x0fffffffL ;
V_13 = V_21 [ 0 ] [ ( V_10 ) & 0x3f ] |
V_21 [ 1 ] [ ( ( V_10 >> 6L ) & 0x03 ) | ( ( V_10 >> 7L ) & 0x3c ) ] |
V_21 [ 2 ] [ ( ( V_10 >> 13L ) & 0x0f ) | ( ( V_10 >> 14L ) & 0x30 ) ] |
V_21 [ 3 ] [ ( ( V_10 >> 20L ) & 0x01 ) | ( ( V_10 >> 21L ) & 0x06 ) |
( ( V_10 >> 22L ) & 0x38 ) ] ;
V_12 = V_21 [ 4 ] [ ( V_11 ) & 0x3f ] |
V_21 [ 5 ] [ ( ( V_11 >> 7L ) & 0x03 ) | ( ( V_11 >> 8L ) & 0x3c ) ] |
V_21 [ 6 ] [ ( V_11 >> 15L ) & 0x3f ] |
V_21 [ 7 ] [ ( ( V_11 >> 21L ) & 0x0f ) | ( ( V_11 >> 22L ) & 0x30 ) ] ;
V_14 = ( ( V_12 << 16L ) | ( V_13 & 0x0000ffffL ) ) & 0xffffffffL ;
* ( V_16 ++ ) = F_11 ( V_14 , 30 ) & 0xffffffffL ;
V_14 = ( ( V_13 >> 16L ) | ( V_12 & 0xffff0000L ) ) ;
* ( V_16 ++ ) = F_11 ( V_14 , 26 ) & 0xffffffffL ;
}
}
int F_12 ( T_2 * V_1 , T_3 * V_7 )
{
return ( F_4 ( V_1 , V_7 ) ) ;
}
