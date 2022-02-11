static T_1 *
F_1 ( T_1 * V_1 )
{
T_1 * V_2 , * V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_1 V_6 [ 3 ] ;
#ifdef F_2
if ( strncmp ( L_1 , V_1 , 9 ) == 0 ) {
V_1 += 7 ;
} else if ( strncmp ( L_2 , V_1 , 8 ) == 0 ) {
V_1 += 8 ;
}
#else
if ( strncmp ( L_3 , V_1 , 5 ) == 0 ) {
V_1 += 5 ;
for(; V_1 [ 1 ] == '/' ; ++ V_1 ) ;
}
#endif
V_2 = V_1 ;
V_3 = V_1 ;
while ( * V_2 ) {
if ( * V_2 == '%' ) {
V_2 ++ ;
if ( * V_2 == '%' ) {
* V_3 = * V_2 ;
V_2 ++ ;
V_3 ++ ;
} else {
V_6 [ 0 ] = V_2 [ 0 ] ;
V_6 [ 1 ] = V_2 [ 1 ] ;
V_6 [ 2 ] = '\0' ;
V_4 = sscanf ( V_6 , L_4 , & V_5 ) ;
if ( V_4 == 1 ) {
V_2 += 2 ;
* V_3 = ( T_1 ) V_5 ;
V_3 ++ ;
} else {
V_2 ++ ;
}
}
#ifdef F_2
} else if ( * V_2 == '/' ) {
* V_3 = '\\' ;
V_2 ++ ;
V_3 ++ ;
#endif
} else {
* V_3 = * V_2 ;
V_2 ++ ;
V_3 ++ ;
}
}
* V_3 = '\0' ;
return V_1 ;
}
void
F_3 ( T_1 * V_7 )
{
int V_8 ;
T_1 * V_1 ;
int V_9 ;
int V_10 ;
char * * V_11 ;
char * V_12 ;
if ( V_7 == NULL ) return;
V_1 = V_7 ;
for( V_9 = 0 ; ( V_1 = strstr ( V_1 , L_5 ) ) != NULL ; ) {
V_1 += 2 ;
V_9 ++ ;
}
if ( V_9 == 0 ) {
F_4 ( V_7 ) ;
return;
}
V_11 = ( char * * ) F_5 ( sizeof( char * ) * V_9 ) ;
V_1 = V_7 ;
V_11 [ 0 ] = V_1 ;
for( V_10 = 1 ; ( V_1 = strstr ( V_1 , L_5 ) ) != NULL && V_10 < V_9 ; ) {
V_1 += 2 ;
V_11 [ V_10 ] = V_1 ;
V_10 ++ ;
}
V_1 = V_7 ;
F_6 ( V_1 , L_5 , '\0' ) ;
for( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
V_11 [ V_10 ] = F_1 ( V_11 [ V_10 ] ) ;
}
if ( V_9 == 1 ) {
if ( F_7 ( & V_13 , V_11 [ 0 ] , V_14 , FALSE , & V_8 ) == V_15 ) {
F_8 ( & V_13 , FALSE ) ;
F_9 ( V_11 [ 0 ] ) ;
} else {
}
} else {
V_12 = NULL ;
if ( F_10 ( & V_12 , V_9 , V_11 ,
V_16 , FALSE ) == V_15 ) {
F_11 ( & V_13 ) ;
if ( F_7 ( & V_13 , V_12 , V_14 , TRUE , & V_8 ) == V_15 ) {
F_4 ( V_12 ) ;
F_8 ( & V_13 , FALSE ) ;
} else {
F_4 ( V_12 ) ;
}
} else {
F_4 ( V_12 ) ;
}
}
F_4 ( V_11 ) ;
F_4 ( V_7 ) ;
}
static void
F_12 ( T_4 * T_5 V_17 , T_6 * T_7 V_17 , T_2 T_8 V_17 , T_2 T_9 V_17 ,
T_10 * V_18 , T_3 V_19 , T_3 T_11 V_17 , T_12 T_13 V_17 )
{
T_1 * V_7 ;
const T_14 * V_20 ;
T_2 V_21 ;
if ( V_19 == V_22 ) {
#ifdef F_13
if( ( V_23 . V_24 != V_25 ) ) {
F_14 ( V_26 ,
V_27 ,
L_6
L_7 ,
F_15 () , F_16 () ) ;
return;
}
#endif
if( V_13 . V_24 == V_28 ) {
F_14 ( V_26 ,
V_27 ,
L_6
L_8 ,
F_15 () , F_16 () ) ;
return;
}
V_21 = F_17 ( V_18 ) ;
V_20 = F_18 ( V_18 ) ;
V_7 = ( T_1 * ) F_5 ( V_21 + 1 ) ;
memcpy ( V_7 , V_20 , V_21 ) ;
V_7 [ V_21 ] = '\0' ;
if ( F_19 ( & V_13 , FALSE , L_9 ) )
F_3 ( V_7 ) ;
}
}
T_15
F_20 ( T_16 * T_17 V_17 , T_1 * V_29 , T_12 T_18 V_17 )
{
T_10 V_18 ;
T_1 * V_30 ;
T_19 V_31 = strlen ( V_29 ) ;
V_30 = ( T_1 * ) F_5 ( V_31 + 3 ) ;
memcpy ( V_30 , V_29 , V_31 ) ;
V_30 [ V_31 ] = '\r' ;
V_30 [ V_31 + 1 ] = '\n' ;
V_30 [ V_31 + 2 ] = '\0' ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_21 ( & V_18 , F_22 ( L_10 ) , 8 , ( T_14 * ) V_30 , ( T_2 ) ( V_31 + 2 ) ) ;
F_12 ( NULL , NULL , 0 , 0 , & V_18 , V_22 , 0 , 0 ) ;
return TRUE ;
}
void
F_23 ( T_4 * V_32 )
{
static T_20 V_33 [] = {
{ L_10 , 0 , V_22 }
} ;
F_24 (
V_32 , V_34 , V_33 ,
sizeof( V_33 ) / sizeof( T_20 ) ,
( V_35 ) ( V_36 | V_37 ) ) ;
F_25 ( V_32 , L_11 , F_26 ( F_12 ) , NULL ) ;
#ifdef F_27
F_25 ( F_28 ( V_38 , NULL ) , L_12 , F_26 ( F_20 ) , NULL ) ;
#endif
}
