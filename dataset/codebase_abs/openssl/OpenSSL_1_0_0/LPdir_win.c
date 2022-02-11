const char * F_1 ( T_1 * * V_1 , const char * V_2 )
{
if ( V_1 == NULL || V_2 == NULL )
{
V_3 = V_4 ;
return 0 ;
}
V_3 = 0 ;
if ( * V_1 == NULL )
{
* V_1 = ( T_1 * ) malloc ( sizeof( T_1 ) ) ;
if ( * V_1 == NULL )
{
V_3 = V_5 ;
return 0 ;
}
memset ( * V_1 , '\0' , sizeof( T_1 ) ) ;
if ( sizeof( V_6 ) != sizeof( char ) )
{
V_6 * V_7 = NULL ;
T_2 V_8 = 0 , V_9 = strlen ( V_2 ) + 1 ;
V_7 = ( V_6 * ) malloc ( V_9 * sizeof( V_6 ) ) ;
if ( V_7 == NULL )
{
free ( * V_1 ) ;
* V_1 = NULL ;
V_3 = V_5 ;
return 0 ;
}
#ifdef F_2
if ( ! F_3 ( V_10 , 0 , V_2 , V_9 , ( V_11 * ) V_7 , V_9 ) )
#endif
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
V_7 [ V_8 ] = ( V_6 ) V_2 [ V_8 ] ;
( * V_1 ) -> V_12 = F_4 ( V_7 , & ( * V_1 ) -> V_1 ) ;
free ( V_7 ) ;
}
else
( * V_1 ) -> V_12 = F_4 ( ( V_6 * ) V_2 , & ( * V_1 ) -> V_1 ) ;
if ( ( * V_1 ) -> V_12 == V_13 )
{
free ( * V_1 ) ;
* V_1 = NULL ;
V_3 = V_4 ;
return 0 ;
}
}
else
{
if ( F_5 ( ( * V_1 ) -> V_12 , & ( * V_1 ) -> V_1 ) == FALSE )
{
return 0 ;
}
}
if ( sizeof( V_6 ) != sizeof( char ) )
{
V_6 * V_7 = ( * V_1 ) -> V_1 . V_14 ;
T_2 V_8 , V_9 = 0 ;
while ( V_7 [ V_9 ] && V_9 < ( sizeof( ( * V_1 ) -> V_15 ) - 1 ) ) V_9 ++ ;
V_9 ++ ;
#ifdef F_2
if ( ! F_6 ( V_10 , 0 , ( V_11 * ) V_7 , V_9 , ( * V_1 ) -> V_15 ,
sizeof( ( * V_1 ) -> V_15 ) , NULL , 0 ) )
#endif
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
( * V_1 ) -> V_15 [ V_8 ] = ( char ) V_7 [ V_8 ] ;
}
else
strncpy ( ( * V_1 ) -> V_15 , ( const char * ) ( * V_1 ) -> V_1 . V_14 ,
sizeof( ( * V_1 ) -> V_15 ) - 1 ) ;
( * V_1 ) -> V_15 [ sizeof( ( * V_1 ) -> V_15 ) - 1 ] = '\0' ;
return ( * V_1 ) -> V_15 ;
}
int F_7 ( T_1 * * V_1 )
{
if ( V_1 != NULL && * V_1 != NULL )
{
F_8 ( ( * V_1 ) -> V_12 ) ;
free ( * V_1 ) ;
* V_1 = NULL ;
return 1 ;
}
V_3 = V_4 ;
return 0 ;
}
