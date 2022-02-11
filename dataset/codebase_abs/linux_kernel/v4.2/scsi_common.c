const char * F_1 ( unsigned type )
{
if ( type == 0x1e )
return L_1 ;
if ( type == 0x1f )
return L_2 ;
if ( type >= F_2 ( V_1 ) )
return L_3 ;
return V_1 [ type ] ;
}
T_1 F_3 ( struct V_2 * V_3 )
{
int V_4 ;
T_1 V_5 ;
V_5 = 0 ;
for ( V_4 = 0 ; V_4 < sizeof( V_5 ) ; V_4 += 2 )
V_5 = V_5 | ( ( ( T_1 ) V_3 -> V_2 [ V_4 ] << ( ( V_4 + 1 ) * 8 ) ) |
( ( T_1 ) V_3 -> V_2 [ V_4 + 1 ] << ( V_4 * 8 ) ) ) ;
return V_5 ;
}
void F_4 ( T_1 V_5 , struct V_2 * V_3 )
{
int V_4 ;
memset ( V_3 -> V_2 , 0 , sizeof( V_3 -> V_2 ) ) ;
for ( V_4 = 0 ; V_4 < sizeof( V_5 ) ; V_4 += 2 ) {
V_3 -> V_2 [ V_4 ] = ( V_5 >> 8 ) & 0xFF ;
V_3 -> V_2 [ V_4 + 1 ] = V_5 & 0xFF ;
V_5 = V_5 >> 16 ;
}
}
bool F_5 ( const T_2 * V_6 , int V_7 ,
struct V_8 * V_9 )
{
if ( ! V_6 || ! V_7 )
return false ;
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 -> V_10 = ( V_6 [ 0 ] & 0x7f ) ;
if ( ! F_6 ( V_9 ) )
return false ;
if ( V_9 -> V_10 >= 0x72 ) {
if ( V_7 > 1 )
V_9 -> V_11 = ( V_6 [ 1 ] & 0xf ) ;
if ( V_7 > 2 )
V_9 -> V_12 = V_6 [ 2 ] ;
if ( V_7 > 3 )
V_9 -> V_13 = V_6 [ 3 ] ;
if ( V_7 > 7 )
V_9 -> V_14 = V_6 [ 7 ] ;
} else {
if ( V_7 > 2 )
V_9 -> V_11 = ( V_6 [ 2 ] & 0xf ) ;
if ( V_7 > 7 ) {
V_7 = ( V_7 < ( V_6 [ 7 ] + 8 ) ) ?
V_7 : ( V_6 [ 7 ] + 8 ) ;
if ( V_7 > 12 )
V_9 -> V_12 = V_6 [ 12 ] ;
if ( V_7 > 13 )
V_9 -> V_13 = V_6 [ 13 ] ;
}
}
return true ;
}
