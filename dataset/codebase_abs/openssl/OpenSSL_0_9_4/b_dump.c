int F_1 ( T_1 * V_1 , const char * V_2 , int V_3 )
{
int V_4 = 0 ;
char V_5 [ 160 + 1 ] , V_6 [ 20 ] ;
int V_7 , V_8 , V_9 , V_10 ;
unsigned char V_11 ;
V_10 = 0 ;
#ifdef F_2
for(; ( V_3 > 0 ) && ( ( V_2 [ V_3 - 1 ] == ' ' ) || ( V_2 [ V_3 - 1 ] == '\0' ) ) ; V_3 -- )
V_10 ++ ;
#endif
V_9 = ( V_3 / V_12 ) ;
if ( ( V_9 * V_12 ) < V_3 )
V_9 ++ ;
for( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_5 [ 0 ] = '\0' ;
sprintf ( V_6 , L_1 , V_7 * V_12 ) ;
strcpy ( V_5 , V_6 ) ;
for( V_8 = 0 ; V_8 < V_12 ; V_8 ++ ) {
if ( ( ( V_7 * V_12 ) + V_8 ) >= V_3 ) {
strcat ( V_5 , L_2 ) ;
} else {
V_11 = ( ( unsigned char ) * ( ( char * ) ( V_2 ) + V_7 * V_12 + V_8 ) ) & 0xff ;
sprintf ( V_6 , L_3 , V_11 , V_8 == 7 ? '-' : ' ' ) ;
strcat ( V_5 , V_6 ) ;
}
}
strcat ( V_5 , L_4 ) ;
for( V_8 = 0 ; V_8 < V_12 ; V_8 ++ ) {
if ( ( ( V_7 * V_12 ) + V_8 ) >= V_3 )
break;
V_11 = ( ( unsigned char ) * ( ( char * ) ( V_2 ) + V_7 * V_12 + V_8 ) ) & 0xff ;
#ifndef F_3
sprintf ( V_6 , L_5 , ( ( V_11 >= ' ' ) && ( V_11 <= '~' ) ) ? V_11 : '.' ) ;
#else
sprintf ( V_6 , L_5 , ( ( V_11 >= V_13 [ ' ' ] ) && ( V_11 <= V_13 [ '~' ] ) )
? V_14 [ V_11 ]
: '.' ) ;
#endif
strcat ( V_5 , V_6 ) ;
}
strcat ( V_5 , L_6 ) ;
V_4 += F_4 ( V_1 , ( char * ) V_5 , strlen ( V_5 ) ) ;
}
#ifdef F_2
if ( V_10 > 0 ) {
sprintf ( V_5 , L_7 , V_3 + V_10 ) ;
V_4 += F_4 ( V_1 , ( char * ) V_5 , strlen ( V_5 ) ) ;
}
#endif
return ( V_4 ) ;
}
