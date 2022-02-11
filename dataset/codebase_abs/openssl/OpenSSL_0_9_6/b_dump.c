int F_1 ( T_1 * V_1 , const char * V_2 , int V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , 0 ) ;
}
int F_2 ( T_1 * V_1 , const char * V_2 , int V_3 , int V_4 )
{
int V_5 = 0 ;
char V_6 [ 288 + 1 ] , V_7 [ 20 ] , V_8 [ 128 + 1 ] ;
int V_9 , V_10 , V_11 , V_12 ;
unsigned char V_13 ;
int V_14 ;
V_12 = 0 ;
#ifdef F_3
for(; ( V_3 > 0 ) && ( ( V_2 [ V_3 - 1 ] == ' ' ) || ( V_2 [ V_3 - 1 ] == '\0' ) ) ; V_3 -- )
V_12 ++ ;
#endif
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_4 )
{
if ( V_4 > 128 ) V_4 = 128 ;
memset ( V_8 , ' ' , V_4 ) ;
}
V_8 [ V_4 ] = '\0' ;
V_14 = F_4 ( V_4 ) ;
V_11 = ( V_3 / V_14 ) ;
if ( ( V_11 * V_14 ) < V_3 )
V_11 ++ ;
for( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
{
V_6 [ 0 ] = '\0' ;
strcpy ( V_6 , V_8 ) ;
sprintf ( V_7 , L_1 , V_9 * V_14 ) ;
strcat ( V_6 , V_7 ) ;
for( V_10 = 0 ; V_10 < V_14 ; V_10 ++ )
{
if ( ( ( V_9 * V_14 ) + V_10 ) >= V_3 )
{
strcat ( V_6 , L_2 ) ;
}
else
{
V_13 = ( ( unsigned char ) * ( V_2 + V_9 * V_14 + V_10 ) ) & 0xff ;
sprintf ( V_7 , L_3 , V_13 , V_10 == 7 ? '-' : ' ' ) ;
strcat ( V_6 , V_7 ) ;
}
}
strcat ( V_6 , L_4 ) ;
for( V_10 = 0 ; V_10 < V_14 ; V_10 ++ )
{
if ( ( ( V_9 * V_14 ) + V_10 ) >= V_3 )
break;
V_13 = ( ( unsigned char ) * ( V_2 + V_9 * V_14 + V_10 ) ) & 0xff ;
#ifndef F_5
sprintf ( V_7 , L_5 , ( ( V_13 >= ' ' ) && ( V_13 <= '~' ) ) ? V_13 : '.' ) ;
#else
sprintf ( V_7 , L_5 , ( ( V_13 >= V_15 [ ' ' ] ) && ( V_13 <= V_15 [ '~' ] ) )
? V_16 [ V_13 ]
: '.' ) ;
#endif
strcat ( V_6 , V_7 ) ;
}
strcat ( V_6 , L_6 ) ;
V_5 += F_6 ( V_1 , ( char * ) V_6 , strlen ( V_6 ) ) ;
}
#ifdef F_3
if ( V_12 > 0 )
{
sprintf ( V_6 , L_7 , V_8 , V_3 + V_12 ) ;
V_5 += F_6 ( V_1 , ( char * ) V_6 , strlen ( V_6 ) ) ;
}
#endif
return ( V_5 ) ;
}
