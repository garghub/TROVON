const char * F_1 ( T_1 * * V_1 , const char * V_2 )
{
struct V_3 * V_4 = NULL ;
if ( V_1 == NULL || V_2 == NULL )
{
V_5 = V_6 ;
return 0 ;
}
V_5 = 0 ;
if ( * V_1 == NULL )
{
* V_1 = ( T_1 * ) malloc ( sizeof( T_1 ) ) ;
if ( * V_1 == NULL )
{
V_5 = V_7 ;
return 0 ;
}
memset ( * V_1 , '\0' , sizeof( T_1 ) ) ;
if ( sizeof( V_8 ) != sizeof( char ) )
{
V_8 * V_9 = NULL ;
T_2 V_10 = 0 , V_11 = strlen ( V_2 ) + 1 ;
V_9 = ( V_8 * ) malloc ( V_11 * sizeof( V_8 ) ) ;
if ( V_9 == NULL )
{
free ( * V_1 ) ;
* V_1 = NULL ;
V_5 = V_7 ;
return 0 ;
}
#ifdef F_2
if ( ! F_3 ( V_12 , 0 , V_2 , V_11 , ( V_13 * ) V_9 , V_11 ) )
#endif
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
V_9 [ V_10 ] = ( V_8 ) V_2 [ V_10 ] ;
( * V_1 ) -> V_14 = F_4 ( V_9 , & ( * V_1 ) -> V_1 ) ;
free ( V_9 ) ;
}
else
( * V_1 ) -> V_14 = F_4 ( ( V_8 * ) V_2 , & ( * V_1 ) -> V_1 ) ;
if ( ( * V_1 ) -> V_14 == V_15 )
{
free ( * V_1 ) ;
* V_1 = NULL ;
V_5 = V_6 ;
return 0 ;
}
}
else
{
if ( F_5 ( ( * V_1 ) -> V_14 , & ( * V_1 ) -> V_1 ) == FALSE )
{
return 0 ;
}
}
if ( sizeof( V_8 ) != sizeof( char ) )
{
V_8 * V_9 = ( * V_1 ) -> V_1 . V_16 ;
T_2 V_10 , V_11 = 0 ;
while ( V_9 [ V_11 ] && V_11 < ( sizeof( ( * V_1 ) -> V_17 ) - 1 ) ) V_11 ++ ;
V_11 ++ ;
#ifdef F_2
if ( ! F_6 ( V_12 , 0 , ( V_13 * ) V_9 , V_11 , ( * V_1 ) -> V_17 ,
sizeof( ( * V_1 ) -> V_17 ) , NULL , 0 ) )
#endif
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
( * V_1 ) -> V_17 [ V_10 ] = ( char ) V_9 [ V_10 ] ;
}
else
strncpy ( ( * V_1 ) -> V_17 , ( const char * ) ( * V_1 ) -> V_1 . V_16 ,
sizeof( ( * V_1 ) -> V_17 ) - 1 ) ;
( * V_1 ) -> V_17 [ sizeof( ( * V_1 ) -> V_17 ) - 1 ] = '\0' ;
return ( * V_1 ) -> V_17 ;
}
int F_7 ( T_1 * * V_1 )
{
if ( V_1 != NULL && * V_1 != NULL )
{
F_8 ( ( * V_1 ) -> V_14 ) ;
free ( * V_1 ) ;
* V_1 = NULL ;
return 1 ;
}
V_5 = V_6 ;
return 0 ;
}
