const char * F_1 ( T_1 * * V_1 , const char * V_2 )
{
if ( V_1 == NULL || V_2 == NULL ) {
V_3 = V_4 ;
return 0 ;
}
V_3 = 0 ;
if ( * V_1 == NULL ) {
const char * V_5 = V_2 ;
char * V_6 = NULL ;
T_2 V_7 = strlen ( V_2 ) ;
if ( V_7 == 0 ) {
V_3 = V_8 ;
return 0 ;
}
* V_1 = ( T_1 * ) malloc ( sizeof( T_1 ) ) ;
if ( * V_1 == NULL ) {
V_3 = V_9 ;
return 0 ;
}
memset ( * V_1 , '\0' , sizeof( T_1 ) ) ;
if ( V_2 [ V_7 - 1 ] != '*' ) {
V_6 = ( char * ) malloc ( V_7 + 3 ) ;
if ( V_6 == NULL ) {
free ( * V_1 ) ;
* V_1 = NULL ;
V_3 = V_9 ;
return 0 ;
}
if ( V_2 [ V_7 - 1 ] != '/' && V_2 [ V_7 - 1 ] != '\\' )
V_5 = strcat ( strcpy ( V_6 , V_2 ) , L_1 ) ;
else
V_5 = strcat ( strcpy ( V_6 , V_2 ) , L_2 ) ;
}
if ( sizeof( V_10 ) != sizeof( char ) ) {
V_10 * V_11 = NULL ;
T_2 V_12 = 0 , V_13 = strlen ( V_5 ) + 1 ;
V_11 = ( V_10 * ) calloc ( V_13 , sizeof( V_10 ) ) ;
if ( V_11 == NULL ) {
if ( V_6 != NULL ) {
free ( V_6 ) ;
}
free ( * V_1 ) ;
* V_1 = NULL ;
V_3 = V_9 ;
return 0 ;
}
#ifdef F_2
if ( ! F_3
( V_14 , 0 , V_5 , V_13 , ( V_15 * ) V_11 , V_13 ) )
#endif
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
V_11 [ V_12 ] = ( V_10 ) V_5 [ V_12 ] ;
( * V_1 ) -> V_16 = F_4 ( V_11 , & ( * V_1 ) -> V_1 ) ;
free ( V_11 ) ;
} else {
( * V_1 ) -> V_16 = F_4 ( ( V_10 * ) V_5 , & ( * V_1 ) -> V_1 ) ;
}
if ( V_6 != NULL ) {
free ( V_6 ) ;
}
if ( ( * V_1 ) -> V_16 == V_17 ) {
free ( * V_1 ) ;
* V_1 = NULL ;
V_3 = V_4 ;
return 0 ;
}
} else {
if ( F_5 ( ( * V_1 ) -> V_16 , & ( * V_1 ) -> V_1 ) == FALSE ) {
return 0 ;
}
}
if ( sizeof( V_10 ) != sizeof( char ) ) {
V_10 * V_11 = ( * V_1 ) -> V_1 . V_18 ;
T_2 V_12 , V_13 = 0 ;
while ( V_11 [ V_13 ] && V_13 < ( sizeof( ( * V_1 ) -> V_19 ) - 1 ) )
V_13 ++ ;
V_13 ++ ;
#ifdef F_2
if ( ! F_6
( V_14 , 0 , ( V_15 * ) V_11 , V_13 , ( * V_1 ) -> V_19 ,
sizeof( ( * V_1 ) -> V_19 ) , NULL , 0 ) )
#endif
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
( * V_1 ) -> V_19 [ V_12 ] = ( char ) V_11 [ V_12 ] ;
} else
strncpy ( ( * V_1 ) -> V_19 , ( const char * ) ( * V_1 ) -> V_1 . V_18 ,
sizeof( ( * V_1 ) -> V_19 ) - 1 ) ;
( * V_1 ) -> V_19 [ sizeof( ( * V_1 ) -> V_19 ) - 1 ] = '\0' ;
return ( * V_1 ) -> V_19 ;
}
int F_7 ( T_1 * * V_1 )
{
if ( V_1 != NULL && * V_1 != NULL ) {
F_8 ( ( * V_1 ) -> V_16 ) ;
free ( * V_1 ) ;
* V_1 = NULL ;
return 1 ;
}
V_3 = V_4 ;
return 0 ;
}
