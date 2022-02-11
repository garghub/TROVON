void F_1 ( const char * V_1 , T_1 * V_2 )
{
T_2 V_3 ;
int V_4 , V_5 ;
memset ( V_2 , 0 , 8 ) ;
V_5 = strlen ( V_1 ) ;
#ifdef F_2
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
( * V_2 ) [ V_4 % 8 ] ^= ( V_1 [ V_4 ] << 1 ) ;
#else
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
register unsigned char V_6 = V_1 [ V_4 ] ;
if ( ( V_4 % 16 ) < 8 )
( * V_2 ) [ V_4 % 8 ] ^= ( V_6 << 1 ) ;
else {
V_6 = ( ( V_6 << 4 ) & 0xf0 ) | ( ( V_6 >> 4 ) & 0x0f ) ;
V_6 = ( ( V_6 << 2 ) & 0xcc ) | ( ( V_6 >> 2 ) & 0x33 ) ;
V_6 = ( ( V_6 << 1 ) & 0xaa ) | ( ( V_6 >> 1 ) & 0x55 ) ;
( * V_2 ) [ 7 - ( V_4 % 8 ) ] ^= V_6 ;
}
}
#endif
F_3 ( V_2 ) ;
F_4 ( V_2 , & V_3 ) ;
F_5 ( ( const unsigned char * ) V_1 , V_2 , V_5 , & V_3 , V_2 ) ;
F_6 ( & V_3 , sizeof( V_3 ) ) ;
F_3 ( V_2 ) ;
}
void F_7 ( const char * V_1 , T_1 * V_7 , T_1 * V_8 )
{
T_2 V_3 ;
int V_4 , V_5 ;
memset ( V_7 , 0 , 8 ) ;
memset ( V_8 , 0 , 8 ) ;
V_5 = strlen ( V_1 ) ;
#ifdef F_2
if ( V_5 <= 8 ) {
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
( * V_8 ) [ V_4 ] = ( * V_7 ) [ V_4 ] = ( V_1 [ V_4 ] << 1 ) ;
}
} else {
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( ( V_4 / 8 ) & 1 )
( * V_8 ) [ V_4 % 8 ] ^= ( V_1 [ V_4 ] << 1 ) ;
else
( * V_7 ) [ V_4 % 8 ] ^= ( V_1 [ V_4 ] << 1 ) ;
}
}
#else
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
register unsigned char V_6 = V_1 [ V_4 ] ;
if ( ( V_4 % 32 ) < 16 ) {
if ( ( V_4 % 16 ) < 8 )
( * V_7 ) [ V_4 % 8 ] ^= ( V_6 << 1 ) ;
else
( * V_8 ) [ V_4 % 8 ] ^= ( V_6 << 1 ) ;
} else {
V_6 = ( ( V_6 << 4 ) & 0xf0 ) | ( ( V_6 >> 4 ) & 0x0f ) ;
V_6 = ( ( V_6 << 2 ) & 0xcc ) | ( ( V_6 >> 2 ) & 0x33 ) ;
V_6 = ( ( V_6 << 1 ) & 0xaa ) | ( ( V_6 >> 1 ) & 0x55 ) ;
if ( ( V_4 % 16 ) < 8 )
( * V_7 ) [ 7 - ( V_4 % 8 ) ] ^= V_6 ;
else
( * V_8 ) [ 7 - ( V_4 % 8 ) ] ^= V_6 ;
}
}
if ( V_5 <= 8 )
memcpy ( V_8 , V_7 , 8 ) ;
#endif
F_3 ( V_7 ) ;
F_3 ( V_8 ) ;
F_4 ( V_7 , & V_3 ) ;
F_5 ( ( const unsigned char * ) V_1 , V_7 , V_5 , & V_3 , V_7 ) ;
F_4 ( V_8 , & V_3 ) ;
F_5 ( ( const unsigned char * ) V_1 , V_8 , V_5 , & V_3 , V_8 ) ;
F_6 ( & V_3 , sizeof( V_3 ) ) ;
F_3 ( V_7 ) ;
F_3 ( V_8 ) ;
}
