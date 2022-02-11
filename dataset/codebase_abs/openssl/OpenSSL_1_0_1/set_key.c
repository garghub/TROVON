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
#ifdef F_7
{
F_8 ( V_9 ) ;
F_9 ( V_1 , V_7 ) ;
}
void F_9 ( T_2 * V_1 , T_3 * V_7 )
#endif
{
static const int V_10 [ 16 ] = { 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 } ;
register T_4 V_11 , V_12 , V_13 , V_14 , V_15 ;
register const unsigned char * V_16 ;
register T_4 * V_17 ;
register int V_2 ;
#ifdef F_10
memcpy ( V_7 -> V_1 , V_1 , sizeof V_7 -> V_1 ) ;
V_7 -> V_18 = NULL ;
#endif
V_17 = & V_7 -> V_19 -> V_20 [ 0 ] ;
V_16 = & ( * V_1 ) [ 0 ] ;
F_11 ( V_16 , V_11 ) ;
F_11 ( V_16 , V_12 ) ;
F_12 ( V_12 , V_11 , V_13 , 4 , 0x0f0f0f0fL ) ;
F_13 ( V_11 , V_13 , - 2 , 0xcccc0000L ) ;
F_13 ( V_12 , V_13 , - 2 , 0xcccc0000L ) ;
F_12 ( V_12 , V_11 , V_13 , 1 , 0x55555555L ) ;
F_12 ( V_11 , V_12 , V_13 , 8 , 0x00ff00ffL ) ;
F_12 ( V_12 , V_11 , V_13 , 1 , 0x55555555L ) ;
V_12 = ( ( ( V_12 & 0x000000ffL ) << 16L ) | ( V_12 & 0x0000ff00L ) |
( ( V_12 & 0x00ff0000L ) >> 16L ) | ( ( V_11 & 0xf0000000L ) >> 4L ) ) ;
V_11 &= 0x0fffffffL ;
for ( V_2 = 0 ; V_2 < V_21 ; V_2 ++ )
{
if ( V_10 [ V_2 ] )
{ V_11 = ( ( V_11 >> 2L ) | ( V_11 << 26L ) ) ; V_12 = ( ( V_12 >> 2L ) | ( V_12 << 26L ) ) ; }
else
{ V_11 = ( ( V_11 >> 1L ) | ( V_11 << 27L ) ) ; V_12 = ( ( V_12 >> 1L ) | ( V_12 << 27L ) ) ; }
V_11 &= 0x0fffffffL ;
V_12 &= 0x0fffffffL ;
V_14 = V_22 [ 0 ] [ ( V_11 ) & 0x3f ] |
V_22 [ 1 ] [ ( ( V_11 >> 6L ) & 0x03 ) | ( ( V_11 >> 7L ) & 0x3c ) ] |
V_22 [ 2 ] [ ( ( V_11 >> 13L ) & 0x0f ) | ( ( V_11 >> 14L ) & 0x30 ) ] |
V_22 [ 3 ] [ ( ( V_11 >> 20L ) & 0x01 ) | ( ( V_11 >> 21L ) & 0x06 ) |
( ( V_11 >> 22L ) & 0x38 ) ] ;
V_13 = V_22 [ 4 ] [ ( V_12 ) & 0x3f ] |
V_22 [ 5 ] [ ( ( V_12 >> 7L ) & 0x03 ) | ( ( V_12 >> 8L ) & 0x3c ) ] |
V_22 [ 6 ] [ ( V_12 >> 15L ) & 0x3f ] |
V_22 [ 7 ] [ ( ( V_12 >> 21L ) & 0x0f ) | ( ( V_12 >> 22L ) & 0x30 ) ] ;
V_15 = ( ( V_13 << 16L ) | ( V_14 & 0x0000ffffL ) ) & 0xffffffffL ;
* ( V_17 ++ ) = F_14 ( V_15 , 30 ) & 0xffffffffL ;
V_15 = ( ( V_14 >> 16L ) | ( V_13 & 0xffff0000L ) ) ;
* ( V_17 ++ ) = F_14 ( V_15 , 26 ) & 0xffffffffL ;
}
}
int F_15 ( T_2 * V_1 , T_3 * V_7 )
{
return ( F_4 ( V_1 , V_7 ) ) ;
}
