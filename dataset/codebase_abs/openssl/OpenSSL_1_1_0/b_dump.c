int F_1 ( int (* F_2) ( const void * V_1 , T_1 V_2 , void * V_3 ) ,
void * V_3 , const char * V_4 , int V_2 )
{
return F_3 ( F_2 , V_3 , V_4 , V_2 , 0 ) ;
}
int F_3 ( int (* F_2) ( const void * V_1 , T_1 V_2 , void * V_3 ) ,
void * V_3 , const char * V_4 , int V_2 , int V_5 )
{
int V_6 = 0 ;
char V_7 [ 288 + 1 ] , V_8 [ 20 ] , V_9 [ 128 + 1 ] ;
int V_10 , V_11 , V_12 , V_13 ;
unsigned char V_14 ;
int V_15 ;
V_13 = 0 ;
#ifdef F_4
for (; ( V_2 > 0 ) && ( ( V_4 [ V_2 - 1 ] == ' ' ) || ( V_4 [ V_2 - 1 ] == '\0' ) ) ; V_2 -- )
V_13 ++ ;
#endif
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 ) {
if ( V_5 > 128 )
V_5 = 128 ;
memset ( V_9 , ' ' , V_5 ) ;
}
V_9 [ V_5 ] = '\0' ;
V_15 = F_5 ( V_5 ) ;
V_12 = ( V_2 / V_15 ) ;
if ( ( V_12 * V_15 ) < V_2 )
V_12 ++ ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
F_6 ( V_7 , V_9 , sizeof V_7 ) ;
F_7 ( V_8 , sizeof V_8 , L_1 , V_10 * V_15 ) ;
F_8 ( V_7 , V_8 , sizeof V_7 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
if ( ( ( V_10 * V_15 ) + V_11 ) >= V_2 ) {
F_8 ( V_7 , L_2 , sizeof V_7 ) ;
} else {
V_14 = ( ( unsigned char ) * ( V_4 + V_10 * V_15 + V_11 ) ) & 0xff ;
F_7 ( V_8 , sizeof V_8 , L_3 , V_14 ,
V_11 == 7 ? '-' : ' ' ) ;
F_8 ( V_7 , V_8 , sizeof V_7 ) ;
}
}
F_8 ( V_7 , L_4 , sizeof V_7 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
if ( ( ( V_10 * V_15 ) + V_11 ) >= V_2 )
break;
V_14 = ( ( unsigned char ) * ( V_4 + V_10 * V_15 + V_11 ) ) & 0xff ;
#ifndef F_9
F_7 ( V_8 , sizeof V_8 , L_5 ,
( ( V_14 >= ' ' ) && ( V_14 <= '~' ) ) ? V_14 : '.' ) ;
#else
F_7 ( V_8 , sizeof V_8 , L_5 ,
( ( V_14 >= V_16 [ ' ' ] ) && ( V_14 <= V_16 [ '~' ] ) )
? V_17 [ V_14 ]
: '.' ) ;
#endif
F_8 ( V_7 , V_8 , sizeof V_7 ) ;
}
F_8 ( V_7 , L_6 , sizeof V_7 ) ;
V_6 += F_2 ( ( void * ) V_7 , strlen ( V_7 ) , V_3 ) ;
}
#ifdef F_4
if ( V_13 > 0 ) {
F_7 ( V_7 , sizeof V_7 , L_7 , V_9 ,
V_2 + V_13 ) ;
V_6 += F_2 ( ( void * ) V_7 , strlen ( V_7 ) , V_3 ) ;
}
#endif
return ( V_6 ) ;
}
static int F_10 ( const void * V_1 , T_1 V_2 , void * V_18 )
{
return F_11 ( V_1 , V_2 , 1 , V_18 ) ;
}
int F_12 ( T_2 * V_18 , const char * V_4 , int V_2 )
{
return F_1 ( F_10 , V_18 , V_4 , V_2 ) ;
}
int F_13 ( T_2 * V_18 , const char * V_4 , int V_2 , int V_5 )
{
return F_3 ( F_10 , V_18 , V_4 , V_2 , V_5 ) ;
}
static int F_14 ( const void * V_1 , T_1 V_2 , void * V_19 )
{
return F_15 ( ( V_20 * ) V_19 , ( const char * ) V_1 , V_2 ) ;
}
int F_16 ( V_20 * V_19 , const char * V_4 , int V_2 )
{
return F_1 ( F_14 , V_19 , V_4 , V_2 ) ;
}
int F_17 ( V_20 * V_19 , const char * V_4 , int V_2 , int V_5 )
{
return F_3 ( F_14 , V_19 , V_4 , V_2 , V_5 ) ;
}
int F_18 ( V_20 * V_21 , int V_5 , int V_22 , unsigned char * V_1 ,
int V_23 )
{
int V_10 , V_11 = 0 ;
if ( V_23 < 1 )
return 1 ;
for ( V_10 = 0 ; V_10 < V_23 - 1 ; V_10 ++ ) {
if ( V_10 && ! V_11 )
F_19 ( V_21 , L_8 , V_5 , L_9 ) ;
F_19 ( V_21 , L_10 , V_1 [ V_10 ] ) ;
V_11 = ( V_11 + 1 ) % V_22 ;
if ( ! V_11 )
F_19 ( V_21 , L_6 ) ;
}
if ( V_10 && ! V_11 )
F_19 ( V_21 , L_8 , V_5 , L_9 ) ;
F_19 ( V_21 , L_11 , V_1 [ V_23 - 1 ] ) ;
return 1 ;
}
