T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_2 , unsigned char * * V_3 )
{
return ( F_6 ( ( V_4 * ) V_2 , V_3 ,
V_5 , V_6 ) ) ;
}
T_1 * F_7 ( T_1 * * V_2 , unsigned char * * V_3 ,
long V_7 )
{
T_1 * V_8 = NULL ;
V_8 = ( T_1 * ) F_8 ( ( V_4 * * ) V_2 ,
V_3 , V_7 , V_5 , V_6 ) ;
if ( V_8 == NULL )
{
F_9 ( V_9 , V_10 ) ;
return ( NULL ) ;
}
return ( V_8 ) ;
}
int F_10 ( const unsigned char * V_11 , int V_12 , unsigned long * V_13 )
{
const unsigned char * V_14 ;
unsigned long V_15 ;
int V_8 ;
if( V_12 <= 0 ) return 0 ;
V_14 = V_11 ;
if( ( * V_14 & 0x80 ) == 0 ) {
V_15 = * V_14 ++ & 0x7f ;
V_8 = 1 ;
} else if( ( * V_14 & 0xe0 ) == 0xc0 ) {
if( V_12 < 2 ) return - 1 ;
if( ( V_14 [ 1 ] & 0xc0 ) != 0x80 ) return - 3 ;
V_15 = ( * V_14 ++ & 0x1f ) << 6 ;
V_15 |= * V_14 ++ & 0x3f ;
if( V_15 < 0x80 ) return - 4 ;
V_8 = 2 ;
} else if( ( * V_14 & 0xf0 ) == 0xe0 ) {
if( V_12 < 3 ) return - 1 ;
if( ( ( V_14 [ 1 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 2 ] & 0xc0 ) != 0x80 ) ) return - 3 ;
V_15 = ( * V_14 ++ & 0xf ) << 12 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 6 ;
V_15 |= * V_14 ++ & 0x3f ;
if( V_15 < 0x800 ) return - 4 ;
V_8 = 3 ;
} else if( ( * V_14 & 0xf8 ) == 0xf0 ) {
if( V_12 < 4 ) return - 1 ;
if( ( ( V_14 [ 1 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 2 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 3 ] & 0xc0 ) != 0x80 ) ) return - 3 ;
V_15 = ( * V_14 ++ & 0x7 ) << 18 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 12 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 6 ;
V_15 |= * V_14 ++ & 0x3f ;
if( V_15 < 0x10000 ) return - 4 ;
V_8 = 4 ;
} else if( ( * V_14 & 0xfc ) == 0xf8 ) {
if( V_12 < 5 ) return - 1 ;
if( ( ( V_14 [ 1 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 2 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 3 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 4 ] & 0xc0 ) != 0x80 ) ) return - 3 ;
V_15 = ( * V_14 ++ & 0x3 ) << 24 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 18 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 12 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 6 ;
V_15 |= * V_14 ++ & 0x3f ;
if( V_15 < 0x200000 ) return - 4 ;
V_8 = 5 ;
} else if( ( * V_14 & 0xfe ) == 0xfc ) {
if( V_12 < 6 ) return - 1 ;
if( ( ( V_14 [ 1 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 2 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 3 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 4 ] & 0xc0 ) != 0x80 )
|| ( ( V_14 [ 5 ] & 0xc0 ) != 0x80 ) ) return - 3 ;
V_15 = ( * V_14 ++ & 0x1 ) << 30 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 24 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 18 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 12 ;
V_15 |= ( * V_14 ++ & 0x3f ) << 6 ;
V_15 |= * V_14 ++ & 0x3f ;
if( V_15 < 0x4000000 ) return - 4 ;
V_8 = 6 ;
} else return - 2 ;
* V_13 = V_15 ;
return V_8 ;
}
int F_11 ( unsigned char * V_11 , int V_12 , unsigned long V_15 )
{
if( ! V_11 ) V_12 = 6 ;
else if( V_12 <= 0 ) return - 1 ;
if( V_15 < 0x80 ) {
if( V_11 ) * V_11 = ( unsigned char ) V_15 ;
return 1 ;
}
if( V_15 < 0x800 ) {
if( V_12 < 2 ) return - 1 ;
if( V_11 ) {
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 6 ) & 0x1f ) | 0xc0 ) ;
* V_11 = ( unsigned char ) ( ( V_15 & 0x3f ) | 0x80 ) ;
}
return 2 ;
}
if( V_15 < 0x10000 ) {
if( V_12 < 3 ) return - 1 ;
if( V_11 ) {
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 12 ) & 0xf ) | 0xe0 ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 6 ) & 0x3f ) | 0x80 ) ;
* V_11 = ( unsigned char ) ( ( V_15 & 0x3f ) | 0x80 ) ;
}
return 3 ;
}
if( V_15 < 0x200000 ) {
if( V_12 < 4 ) return - 1 ;
if( V_11 ) {
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 18 ) & 0x7 ) | 0xf0 ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 12 ) & 0x3f ) | 0x80 ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 6 ) & 0x3f ) | 0x80 ) ;
* V_11 = ( unsigned char ) ( ( V_15 & 0x3f ) | 0x80 ) ;
}
return 4 ;
}
if( V_15 < 0x4000000 ) {
if( V_12 < 5 ) return - 1 ;
if( V_11 ) {
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 24 ) & 0x3 ) | 0xf8 ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 18 ) & 0x3f ) | 0x80 ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 12 ) & 0x3f ) | 0x80 ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 6 ) & 0x3f ) | 0x80 ) ;
* V_11 = ( unsigned char ) ( ( V_15 & 0x3f ) | 0x80 ) ;
}
return 5 ;
}
if( V_12 < 6 ) return - 1 ;
if( V_11 ) {
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 30 ) & 0x1 ) | 0xfc ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 24 ) & 0x3f ) | 0x80 ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 18 ) & 0x3f ) | 0x80 ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 12 ) & 0x3f ) | 0x80 ) ;
* V_11 ++ = ( unsigned char ) ( ( ( V_15 >> 6 ) & 0x3f ) | 0x80 ) ;
* V_11 = ( unsigned char ) ( ( V_15 & 0x3f ) | 0x80 ) ;
}
return 6 ;
}
