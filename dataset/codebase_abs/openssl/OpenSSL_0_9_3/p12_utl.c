unsigned char * F_1 ( const char * V_1 , unsigned char * * V_2 , int * V_3 )
{
int V_4 , V_5 ;
unsigned char * V_6 ;
V_4 = strlen ( V_1 ) * 2 + 2 ;
if ( ! ( V_6 = Malloc ( V_4 ) ) ) return NULL ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 += 2 ) {
V_6 [ V_5 ] = 0 ;
V_6 [ V_5 + 1 ] = V_1 [ V_5 >> 1 ] ;
}
if ( V_3 ) * V_3 = V_4 ;
if ( V_2 ) * V_2 = V_6 ;
return V_6 ;
}
char * F_2 ( unsigned char * V_2 , int V_3 )
{
int V_7 , V_5 ;
char * V_8 ;
V_7 = V_3 / 2 ;
if ( V_2 [ V_3 - 1 ] ) V_7 ++ ;
V_2 ++ ;
if ( ! ( V_8 = Malloc ( V_7 ) ) ) return NULL ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 += 2 ) V_8 [ V_5 >> 1 ] = V_2 [ V_5 ] ;
V_8 [ V_7 - 1 ] = 0 ;
return V_8 ;
}
int F_3 ( T_1 * V_9 , T_2 * V_10 )
{
return F_4 ( ( int ( * ) () ) V_11 , V_9 , ( unsigned char * ) V_10 ) ;
}
int F_5 ( T_3 * V_12 , T_2 * V_10 )
{
return F_6 ( ( int ( * ) () ) V_11 , V_12 , ( unsigned char * ) V_10 ) ;
}
T_2 * F_7 ( T_1 * V_9 , T_2 * * V_10 )
{
return ( T_2 * ) F_8 ( ( char * (*)() ) V_13 ,
( char * (*)() ) V_14 , V_9 , ( unsigned char * * ) V_10 ) ;
}
T_2 * F_9 ( T_3 * V_12 , T_2 * * V_10 )
{
return ( T_2 * ) F_10 ( ( char * (*)() ) V_13 ,
( char * (*)() ) V_14 , V_12 , ( unsigned char * * ) ( V_10 ) ) ;
}
