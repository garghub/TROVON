static char * F_1 ( T_1 V_1 , T_1 V_2 )
{
char * V_3 ;
char * V_4 ;
T_1 V_5 ;
F_2 ( V_6 ) ;
if ( V_1 == V_7 ) {
V_5 = 1 + ( V_8 * V_2 ) + 2 + 1 ;
} else {
V_5 =
V_1 + ( V_8 * V_2 ) + 2 + 1 ;
}
V_4 = F_3 ( V_5 ) ;
if ( ! V_4 ) {
F_4 ( ( V_9 ,
L_1 , V_5 ) ) ;
F_5 ( NULL ) ;
}
V_3 = V_4 ;
if ( V_1 == V_7 ) {
* V_3 ++ = V_10 ;
} else {
while ( V_1 -- ) {
* V_3 ++ = V_11 ;
}
}
if ( V_2 > 2 ) {
* V_3 ++ = V_12 ;
* V_3 ++ = ( char ) V_2 ;
} else if ( 2 == V_2 ) {
* V_3 ++ = V_13 ;
}
* V_3 = 0 ;
F_5 ( V_4 ) ;
}
static T_2 F_6 ( T_3 * * V_14 , char * V_4 )
{
char * V_15 = ( void * ) * V_14 ;
T_2 V_16 = V_17 ;
T_1 V_18 ;
char V_19 [ 5 ] ;
F_2 ( V_20 ) ;
V_19 [ 0 ] = * V_15 ;
if ( '0' <= V_19 [ 0 ] && V_19 [ 0 ] <= '9' ) {
F_4 ( ( V_9 , L_2 , V_19 [ 0 ] ) ) ;
F_7 ( V_21 ) ;
}
F_8 ( ( V_22 , L_3 ) ) ;
for ( V_18 = 0 ;
( V_18 < V_8 )
&& ( F_9 ( * V_15 , 0 ) ) ; V_18 ++ ) {
V_19 [ V_18 ] = * V_15 ++ ;
F_8 ( ( V_22 , L_4 , V_19 [ V_18 ] ) ) ;
}
if ( V_18 == 4 ) {
V_19 [ 4 ] = '\0' ;
if ( V_4 ) {
strcat ( V_4 , V_19 ) ;
F_8 ( ( V_23 ,
L_5 , V_4 ) ) ;
} else {
F_8 ( ( V_23 ,
L_6 , V_19 ) ) ;
}
} else if ( V_18 == 0 ) {
F_8 ( ( V_24 ,
L_7 ,
V_19 [ 0 ] ) ) ;
V_16 = V_21 ;
} else {
V_16 = V_25 ;
F_4 ( ( V_9 ,
L_8 ,
* V_15 , V_15 ) ) ;
}
* V_14 = F_10 ( T_3 , V_15 ) ;
F_7 ( V_16 ) ;
}
T_2
F_11 ( T_4 V_26 ,
T_3 * V_14 ,
char * * V_27 , T_1 * V_28 )
{
T_2 V_16 = V_17 ;
T_3 * V_15 = V_14 ;
char * V_4 = NULL ;
T_1 V_29 ;
T_1 V_1 = 0 ;
T_3 V_30 = FALSE ;
F_12 ( V_31 , V_15 ) ;
if ( V_32 == V_26 ||
V_33 == V_26 ||
V_34 == V_26 ) {
V_4 = F_1 ( 0 , 1 ) ;
if ( ! V_4 ) {
V_16 = V_35 ;
} else {
V_16 =
F_6 ( & V_15 , V_4 ) ;
}
} else {
switch ( * V_15 ) {
case V_10 :
F_8 ( ( V_22 ,
L_9 ,
V_15 ) ) ;
V_15 ++ ;
V_1 = V_7 ;
V_30 = TRUE ;
break;
case V_11 :
do {
F_8 ( ( V_22 ,
L_10 ,
V_15 ) ) ;
V_15 ++ ;
V_1 ++ ;
} while ( * V_15 == V_11 );
V_30 = TRUE ;
break;
default:
break;
}
switch ( * V_15 ) {
case V_13 :
F_8 ( ( V_22 ,
L_11 ,
V_15 ) ) ;
V_15 ++ ;
V_4 =
F_1 ( V_1 , 2 ) ;
if ( ! V_4 ) {
V_16 = V_35 ;
break;
}
V_30 = TRUE ;
V_16 =
F_6 ( & V_15 , V_4 ) ;
if ( F_13 ( V_16 ) ) {
V_16 =
F_6 ( & V_15 ,
V_4 ) ;
}
break;
case V_12 :
F_8 ( ( V_22 ,
L_12 ,
V_15 ) ) ;
V_15 ++ ;
V_29 = * V_15 ;
V_4 =
F_1 ( V_1 ,
V_29 ) ;
if ( ! V_4 ) {
V_16 = V_35 ;
break;
}
V_15 ++ ;
V_30 = TRUE ;
while ( V_29 &&
( V_16 =
F_6 ( & V_15 ,
V_4 ) ) == V_17 ) {
V_29 -- ;
}
break;
case 0 :
if ( V_1 == V_7 ) {
F_8 ( ( V_36 ,
L_13 ) ) ;
}
V_15 ++ ;
V_4 =
F_1 ( V_1 , 0 ) ;
if ( ! V_4 ) {
V_16 = V_35 ;
break;
}
break;
default:
V_4 =
F_1 ( V_1 , 1 ) ;
if ( ! V_4 ) {
V_16 = V_35 ;
break;
}
V_16 =
F_6 ( & V_15 , V_4 ) ;
break;
}
}
if ( V_21 == V_16 && V_30 ) {
F_4 ( ( V_9 , L_14 , V_4 ) ) ;
V_16 = V_25 ;
}
if ( F_14 ( V_16 ) ) {
if ( V_4 ) {
F_15 ( V_4 ) ;
}
F_7 ( V_16 ) ;
}
* V_27 = V_4 ;
* V_28 = ( T_1 ) ( V_15 - V_14 ) ;
F_7 ( V_16 ) ;
}
