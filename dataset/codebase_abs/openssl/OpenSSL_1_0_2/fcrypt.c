char * F_1 ( const char * V_1 , const char * V_2 )
{
static char V_3 [ 14 ] ;
#ifndef F_2
return ( F_3 ( V_1 , V_2 , V_3 ) ) ;
#else
char V_4 [ 2 + 1 ] ;
char V_5 [ 32 + 1 ] ;
char * V_6 ;
if ( ( V_4 [ 0 ] = V_2 [ 0 ] ) != '\0' )
V_4 [ 1 ] = V_2 [ 1 ] ;
strncpy ( V_5 , V_1 , sizeof( V_5 ) ) ;
V_4 [ sizeof( V_4 ) - 1 ] = V_5 [ sizeof( V_5 ) - 1 ] = '\0' ;
F_4 ( V_4 , V_4 , sizeof V_4 ) ;
F_4 ( V_5 , V_5 , sizeof V_5 ) ;
V_6 = F_3 ( V_5 , V_4 , V_3 ) ;
F_5 ( V_6 , V_6 , strlen ( V_6 ) ) ;
return V_6 ;
#endif
}
char * F_3 ( const char * V_1 , const char * V_2 , char * V_6 )
{
unsigned int V_7 , V_8 , V_9 , V_10 ;
T_1 V_11 , V_12 ;
T_1 V_13 [ 2 ] , V_14 ;
T_2 V_15 ;
T_3 V_16 ;
unsigned char V_17 [ 9 ] ;
unsigned char * V_18 = V_17 ;
unsigned char V_19 , V_20 ;
#ifndef F_2
V_9 = V_6 [ 0 ] = ( ( V_2 [ 0 ] == '\0' ) ? 'A' : V_2 [ 0 ] ) ;
V_11 = V_21 [ V_9 ] << 2 ;
V_9 = V_6 [ 1 ] = ( ( V_2 [ 1 ] == '\0' ) ? 'A' : V_2 [ 1 ] ) ;
V_12 = V_21 [ V_9 ] << 6 ;
#else
V_9 = V_6 [ 0 ] = ( ( V_2 [ 0 ] == '\0' ) ? V_22 [ 'A' ] : V_2 [ 0 ] ) ;
V_11 = V_21 [ V_9 ] << 2 ;
V_9 = V_6 [ 1 ] = ( ( V_2 [ 1 ] == '\0' ) ? V_22 [ 'A' ] : V_2 [ 1 ] ) ;
V_12 = V_21 [ V_9 ] << 6 ;
#endif
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
V_19 = * ( V_1 ++ ) ;
if ( ! V_19 )
break;
V_15 [ V_7 ] = ( V_19 << 1 ) ;
}
for (; V_7 < 8 ; V_7 ++ )
V_15 [ V_7 ] = 0 ;
F_6 ( & V_15 , & V_16 ) ;
F_7 ( & ( V_13 [ 0 ] ) , & V_16 , V_11 , V_12 ) ;
V_14 = V_13 [ 0 ] ;
F_8 ( V_14 , V_18 ) ;
V_14 = V_13 [ 1 ] ;
F_8 ( V_14 , V_18 ) ;
V_10 = 0 ;
V_20 = 0x80 ;
V_17 [ 8 ] = 0 ;
for ( V_7 = 2 ; V_7 < 13 ; V_7 ++ ) {
V_19 = 0 ;
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
V_19 <<= 1 ;
if ( V_17 [ V_10 ] & V_20 )
V_19 |= 1 ;
V_20 >>= 1 ;
if ( ! V_20 ) {
V_10 ++ ;
V_20 = 0x80 ;
}
}
V_6 [ V_7 ] = V_23 [ V_19 ] ;
}
V_6 [ 13 ] = '\0' ;
return ( V_6 ) ;
}
