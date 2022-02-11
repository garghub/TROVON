const char * F_1 ( T_1 * * V_1 , const char * V_2 )
{
if ( V_1 == NULL || V_2 == NULL ) {
V_3 = V_4 ;
return 0 ;
}
V_3 = 0 ;
if ( * V_1 == NULL ) {
T_2 V_5 = strlen ( V_2 ) ;
if ( V_5 == 0 || V_5 > V_6 - 3 ) {
V_3 = V_7 ;
return 0 ;
}
* V_1 = malloc ( sizeof( * * V_1 ) ) ;
if ( * V_1 == NULL ) {
V_3 = V_8 ;
return 0 ;
}
memset ( * V_1 , 0 , sizeof( * * V_1 ) ) ;
if ( sizeof( V_9 ) != sizeof( char ) ) {
V_9 * V_10 = NULL ;
T_2 V_11 = 0 , V_12 = V_5 + 1 ;
#ifdef F_2
int V_13 = 0 ;
T_3 V_14 ;
do {
# ifdef F_3
if ( ( V_13 = F_4 ( ( V_14 = F_3 ) , 0 ,
V_2 , V_12 ,
NULL , 0 ) ) > 0 ||
F_5 () != V_15 )
break;
# endif
V_13 = F_4 ( ( V_14 = V_16 ) , 0 ,
V_2 , V_12 ,
NULL , 0 ) ;
} while ( 0 );
if ( V_13 > 0 ) {
V_10 = F_6 ( ( V_13 + 2 ) * sizeof( V_9 ) ) ;
if ( ! F_4 ( V_14 , 0 , V_2 , V_12 ,
( V_17 * ) V_10 , V_13 ) ) {
free ( * V_1 ) ;
* V_1 = NULL ;
V_3 = V_4 ;
return 0 ;
}
} else
#endif
{
V_13 = V_12 ;
V_10 = F_6 ( ( V_13 + 2 ) * sizeof( V_9 ) ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_10 [ V_11 ] = ( V_9 ) V_2 [ V_11 ] ;
}
V_13 -- ;
if ( V_10 [ V_13 - 1 ] != F_7 ( '*' ) ) {
if ( V_10 [ V_13 - 1 ] != F_7 ( '/' ) && V_10 [ V_13 - 1 ] != F_7 ( '\\' ) )
F_8 ( V_10 + V_13 , F_7 ( L_1 ) ) ;
else
F_8 ( V_10 + V_13 , F_7 ( L_2 ) ) ;
}
( * V_1 ) -> V_18 = F_9 ( V_10 , & ( * V_1 ) -> V_1 ) ;
} else {
if ( V_2 [ V_5 - 1 ] != '*' ) {
char * V_19 = F_6 ( V_5 + 3 ) ;
strcpy ( V_19 , V_2 ) ;
if ( V_19 [ V_5 - 1 ] != '/' && V_19 [ V_5 - 1 ] != '\\' )
strcpy ( V_19 + V_5 , L_1 ) ;
else
strcpy ( V_19 + V_5 , L_2 ) ;
V_2 = V_19 ;
}
( * V_1 ) -> V_18 = F_9 ( ( V_9 * ) V_2 , & ( * V_1 ) -> V_1 ) ;
}
if ( ( * V_1 ) -> V_18 == V_20 ) {
free ( * V_1 ) ;
* V_1 = NULL ;
V_3 = V_4 ;
return 0 ;
}
} else {
if ( F_10 ( ( * V_1 ) -> V_18 , & ( * V_1 ) -> V_1 ) == FALSE ) {
return 0 ;
}
}
if ( sizeof( V_9 ) != sizeof( char ) ) {
V_9 * V_10 = ( * V_1 ) -> V_1 . V_21 ;
T_2 V_11 , V_12 = 0 ;
while ( V_10 [ V_12 ] && V_12 < ( sizeof( ( * V_1 ) -> V_22 ) - 1 ) )
V_12 ++ ;
V_12 ++ ;
#ifdef F_2
if ( ! F_11 ( V_23 , 0 , ( V_17 * ) V_10 , V_12 ,
( * V_1 ) -> V_22 ,
sizeof( ( * V_1 ) -> V_22 ) , NULL , 0 ) )
#endif
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
( * V_1 ) -> V_22 [ V_11 ] = ( char ) V_10 [ V_11 ] ;
} else
strncpy ( ( * V_1 ) -> V_22 , ( const char * ) ( * V_1 ) -> V_1 . V_21 ,
sizeof( ( * V_1 ) -> V_22 ) - 1 ) ;
( * V_1 ) -> V_22 [ sizeof( ( * V_1 ) -> V_22 ) - 1 ] = '\0' ;
return ( * V_1 ) -> V_22 ;
}
int F_12 ( T_1 * * V_1 )
{
if ( V_1 != NULL && * V_1 != NULL ) {
F_13 ( ( * V_1 ) -> V_18 ) ;
free ( * V_1 ) ;
* V_1 = NULL ;
return 1 ;
}
V_3 = V_4 ;
return 0 ;
}
