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
static void
F_3 ( int V_7 , char * * V_8 )
{
char * V_9 ;
T_4 V_10 ;
int V_11 ;
V_9 = NULL ;
V_10 = F_4 ( & V_9 , V_7 , V_8 ,
V_12 , FALSE ) ;
if ( V_10 != V_13 ) {
F_5 ( V_9 ) ;
return;
}
F_6 ( & V_14 ) ;
if ( F_7 ( & V_14 , V_9 , TRUE , & V_11 ) != V_13 ) {
F_5 ( V_9 ) ;
return;
}
F_5 ( V_9 ) ;
switch ( F_8 ( & V_14 , FALSE ) ) {
case V_15 :
case V_16 :
break;
case V_17 :
return;
}
}
void
F_9 ( T_1 * V_18 )
{
int V_11 ;
T_1 * V_1 ;
int V_19 ;
T_5 * V_20 ;
int V_21 ;
char * * V_8 ;
V_1 = V_18 ;
for( V_19 = 0 ; ( V_1 = strstr ( V_1 , L_5 ) ) != NULL ; ) {
V_1 += 2 ;
V_19 ++ ;
}
V_8 = F_10 ( sizeof( char * ) * V_19 ) ;
V_1 = V_18 ;
V_8 [ 0 ] = V_1 ;
for( V_21 = 1 ; ( V_1 = strstr ( V_1 , L_5 ) ) != NULL && V_21 < V_19 ; ) {
V_1 += 2 ;
V_8 [ V_21 ] = V_1 ;
V_21 ++ ;
}
V_1 = V_18 ;
F_11 ( V_1 , L_5 , '\0' ) ;
for( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
V_8 [ V_21 ] = F_1 ( V_8 [ V_21 ] ) ;
}
switch( V_19 ) {
case ( 0 ) :
break;
case ( 1 ) :
if ( F_7 ( & V_14 , V_8 [ 0 ] , FALSE , & V_11 ) == V_13 ) {
F_8 ( & V_14 , FALSE ) ;
F_12 ( V_8 [ 0 ] ) ;
} else {
}
break;
default:
V_20 = F_13 ( 200 ) ;
F_14 ( V_20 ,
L_6 ,
F_15 () , F_16 () ) ;
for( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
F_17 ( V_20 , V_8 [ V_21 ] ) ;
F_17 ( V_20 , L_7 ) ;
}
F_17 ( V_20 , L_8 ) ;
F_18 ( V_22 ,
V_23 , L_9 ,
V_20 -> V_24 ) ;
F_19 ( V_20 , TRUE ) ;
F_3 ( V_19 , V_8 ) ;
}
F_5 ( V_8 ) ;
F_5 ( V_18 ) ;
}
static void
F_20 ( T_6 * T_7 V_25 , T_8 * T_9 V_25 , T_2 T_10 V_25 , T_2 T_11 V_25 ,
T_12 * V_26 , T_3 V_27 , T_3 T_13 V_25 , T_14 T_15 V_25 )
{
T_1 * V_18 ;
const T_16 * V_28 ;
T_2 V_29 ;
if ( V_27 == V_30 ) {
#ifdef F_21
if( ( V_31 . V_32 != V_33 ) ) {
F_18 ( V_22 ,
V_23 ,
L_10
L_11 ,
F_15 () , F_16 () ) ;
return;
}
#endif
if( V_14 . V_32 == V_34 ) {
F_18 ( V_22 ,
V_23 ,
L_10
L_12 ,
F_15 () , F_16 () ) ;
return;
}
V_29 = F_22 ( V_26 ) ;
V_28 = F_23 ( V_26 ) ;
V_18 = F_10 ( V_29 + 1 ) ;
memcpy ( V_18 , V_28 , V_29 ) ;
V_18 [ V_29 ] = '\0' ;
if ( F_24 ( & V_14 , FALSE , L_13 ) )
F_9 ( V_18 ) ;
}
}
T_17
F_25 ( T_18 * T_19 V_25 , T_1 * V_35 , T_14 T_20 V_25 )
{
T_12 V_26 ;
T_1 * V_36 ;
int V_37 = strlen ( V_35 ) + 3 ;
V_36 = F_10 ( V_37 + 3 ) ;
memcpy ( V_36 , V_35 , V_37 ) ;
V_36 [ V_37 ] = '\r' ;
V_36 [ V_37 + 1 ] = '\n' ;
V_36 [ V_37 + 2 ] = '\0' ;
F_26 ( & V_26 , V_36 , V_37 ) ;
F_20 ( NULL , NULL , 0 , 0 , & V_26 , V_30 , 0 , 0 ) ;
F_5 ( V_36 ) ;
return TRUE ;
}
void
F_27 ( T_6 * V_38 )
{
static T_21 V_39 [] = {
{ L_14 , 0 , V_30 }
} ;
F_28 (
V_38 , V_40 , V_39 ,
sizeof( V_39 ) / sizeof( T_21 ) ,
( V_41 ) ( V_42 | V_43 ) ) ;
F_29 ( V_38 , L_15 , F_30 ( F_20 ) , NULL ) ;
#ifdef F_31
F_29 ( F_32 ( V_44 , NULL ) , L_16 , F_30 ( F_25 ) , NULL ) ;
#endif
}
