int F_1 ( const unsigned char * V_1 , int V_2 , unsigned long * V_3 )
{
const unsigned char * V_4 ;
unsigned long V_5 ;
int V_6 ;
if ( V_2 <= 0 )
return 0 ;
V_4 = V_1 ;
if ( ( * V_4 & 0x80 ) == 0 ) {
V_5 = * V_4 ++ & 0x7f ;
V_6 = 1 ;
} else if ( ( * V_4 & 0xe0 ) == 0xc0 ) {
if ( V_2 < 2 )
return - 1 ;
if ( ( V_4 [ 1 ] & 0xc0 ) != 0x80 )
return - 3 ;
V_5 = ( * V_4 ++ & 0x1f ) << 6 ;
V_5 |= * V_4 ++ & 0x3f ;
if ( V_5 < 0x80 )
return - 4 ;
V_6 = 2 ;
} else if ( ( * V_4 & 0xf0 ) == 0xe0 ) {
if ( V_2 < 3 )
return - 1 ;
if ( ( ( V_4 [ 1 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 2 ] & 0xc0 ) != 0x80 ) )
return - 3 ;
V_5 = ( * V_4 ++ & 0xf ) << 12 ;
V_5 |= ( * V_4 ++ & 0x3f ) << 6 ;
V_5 |= * V_4 ++ & 0x3f ;
if ( V_5 < 0x800 )
return - 4 ;
V_6 = 3 ;
} else if ( ( * V_4 & 0xf8 ) == 0xf0 ) {
if ( V_2 < 4 )
return - 1 ;
if ( ( ( V_4 [ 1 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 2 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 3 ] & 0xc0 ) != 0x80 ) )
return - 3 ;
V_5 = ( ( unsigned long ) ( * V_4 ++ & 0x7 ) ) << 18 ;
V_5 |= ( * V_4 ++ & 0x3f ) << 12 ;
V_5 |= ( * V_4 ++ & 0x3f ) << 6 ;
V_5 |= * V_4 ++ & 0x3f ;
if ( V_5 < 0x10000 )
return - 4 ;
V_6 = 4 ;
} else if ( ( * V_4 & 0xfc ) == 0xf8 ) {
if ( V_2 < 5 )
return - 1 ;
if ( ( ( V_4 [ 1 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 2 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 3 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 4 ] & 0xc0 ) != 0x80 ) )
return - 3 ;
V_5 = ( ( unsigned long ) ( * V_4 ++ & 0x3 ) ) << 24 ;
V_5 |= ( ( unsigned long ) ( * V_4 ++ & 0x3f ) ) << 18 ;
V_5 |= ( ( unsigned long ) ( * V_4 ++ & 0x3f ) ) << 12 ;
V_5 |= ( * V_4 ++ & 0x3f ) << 6 ;
V_5 |= * V_4 ++ & 0x3f ;
if ( V_5 < 0x200000 )
return - 4 ;
V_6 = 5 ;
} else if ( ( * V_4 & 0xfe ) == 0xfc ) {
if ( V_2 < 6 )
return - 1 ;
if ( ( ( V_4 [ 1 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 2 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 3 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 4 ] & 0xc0 ) != 0x80 )
|| ( ( V_4 [ 5 ] & 0xc0 ) != 0x80 ) )
return - 3 ;
V_5 = ( ( unsigned long ) ( * V_4 ++ & 0x1 ) ) << 30 ;
V_5 |= ( ( unsigned long ) ( * V_4 ++ & 0x3f ) ) << 24 ;
V_5 |= ( ( unsigned long ) ( * V_4 ++ & 0x3f ) ) << 18 ;
V_5 |= ( ( unsigned long ) ( * V_4 ++ & 0x3f ) ) << 12 ;
V_5 |= ( * V_4 ++ & 0x3f ) << 6 ;
V_5 |= * V_4 ++ & 0x3f ;
if ( V_5 < 0x4000000 )
return - 4 ;
V_6 = 6 ;
} else
return - 2 ;
* V_3 = V_5 ;
return V_6 ;
}
int F_2 ( unsigned char * V_1 , int V_2 , unsigned long V_5 )
{
if ( ! V_1 )
V_2 = 6 ;
else if ( V_2 <= 0 )
return - 1 ;
if ( V_5 < 0x80 ) {
if ( V_1 )
* V_1 = ( unsigned char ) V_5 ;
return 1 ;
}
if ( V_5 < 0x800 ) {
if ( V_2 < 2 )
return - 1 ;
if ( V_1 ) {
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 6 ) & 0x1f ) | 0xc0 ) ;
* V_1 = ( unsigned char ) ( ( V_5 & 0x3f ) | 0x80 ) ;
}
return 2 ;
}
if ( V_5 < 0x10000 ) {
if ( V_2 < 3 )
return - 1 ;
if ( V_1 ) {
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 12 ) & 0xf ) | 0xe0 ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 6 ) & 0x3f ) | 0x80 ) ;
* V_1 = ( unsigned char ) ( ( V_5 & 0x3f ) | 0x80 ) ;
}
return 3 ;
}
if ( V_5 < 0x200000 ) {
if ( V_2 < 4 )
return - 1 ;
if ( V_1 ) {
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 18 ) & 0x7 ) | 0xf0 ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 12 ) & 0x3f ) | 0x80 ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 6 ) & 0x3f ) | 0x80 ) ;
* V_1 = ( unsigned char ) ( ( V_5 & 0x3f ) | 0x80 ) ;
}
return 4 ;
}
if ( V_5 < 0x4000000 ) {
if ( V_2 < 5 )
return - 1 ;
if ( V_1 ) {
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 24 ) & 0x3 ) | 0xf8 ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 18 ) & 0x3f ) | 0x80 ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 12 ) & 0x3f ) | 0x80 ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 6 ) & 0x3f ) | 0x80 ) ;
* V_1 = ( unsigned char ) ( ( V_5 & 0x3f ) | 0x80 ) ;
}
return 5 ;
}
if ( V_2 < 6 )
return - 1 ;
if ( V_1 ) {
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 30 ) & 0x1 ) | 0xfc ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 24 ) & 0x3f ) | 0x80 ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 18 ) & 0x3f ) | 0x80 ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 12 ) & 0x3f ) | 0x80 ) ;
* V_1 ++ = ( unsigned char ) ( ( ( V_5 >> 6 ) & 0x3f ) | 0x80 ) ;
* V_1 = ( unsigned char ) ( ( V_5 & 0x3f ) | 0x80 ) ;
}
return 6 ;
}
