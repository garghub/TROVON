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
if ( F_10 ( V_16 , & V_12 , V_9 , V_11 ,
V_17 , FALSE ) == V_15 ) {
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
F_12 ( T_4 * T_5 V_18 , T_6 * T_7 V_18 , T_2 T_8 V_18 , T_2 T_9 V_18 ,
T_10 * V_19 , T_3 V_20 , T_3 T_11 V_18 , T_12 T_13 V_18 )
{
T_1 * V_7 ;
const T_14 * V_21 ;
T_2 V_22 ;
if ( V_20 == V_23 ) {
#ifdef F_13
if( ( V_24 . V_25 != V_26 ) ) {
F_14 ( V_27 ,
V_28 ,
L_6
L_7 ,
F_15 () , F_16 () ) ;
return;
}
#endif
if( V_13 . V_25 == V_29 ) {
F_14 ( V_27 ,
V_28 ,
L_6
L_8 ,
F_15 () , F_16 () ) ;
return;
}
V_22 = F_17 ( V_19 ) ;
V_21 = F_18 ( V_19 ) ;
V_7 = ( T_1 * ) F_5 ( V_22 + 1 ) ;
memcpy ( V_7 , V_21 , V_22 ) ;
V_7 [ V_22 ] = '\0' ;
if ( F_19 ( & V_13 , FALSE , L_9 ) )
F_3 ( V_7 ) ;
}
}
T_15
F_20 ( T_16 * T_17 V_18 , T_1 * V_30 , T_12 T_18 V_18 )
{
T_10 V_19 ;
T_1 * V_31 ;
T_19 V_32 = strlen ( V_30 ) ;
V_31 = ( T_1 * ) F_5 ( V_32 + 3 ) ;
memcpy ( V_31 , V_30 , V_32 ) ;
V_31 [ V_32 ] = '\r' ;
V_31 [ V_32 + 1 ] = '\n' ;
V_31 [ V_32 + 2 ] = '\0' ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
F_21 ( & V_19 , F_22 ( L_10 ) , 8 , ( T_14 * ) V_31 , ( T_2 ) ( V_32 + 2 ) ) ;
F_12 ( NULL , NULL , 0 , 0 , & V_19 , V_23 , 0 , 0 ) ;
return TRUE ;
}
void
F_23 ( T_4 * V_33 )
{
static T_20 V_34 [] = {
{ L_10 , 0 , V_23 }
} ;
F_24 (
V_33 , V_35 , V_34 ,
sizeof( V_34 ) / sizeof( T_20 ) ,
( V_36 ) ( V_37 | V_38 ) ) ;
F_25 ( V_33 , L_11 , F_26 ( F_12 ) , NULL ) ;
#ifdef F_27
F_25 ( F_28 ( V_39 , NULL ) , L_12 , F_26 ( F_20 ) , NULL ) ;
#endif
}
