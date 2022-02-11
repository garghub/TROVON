int MAIN ( int V_1 , char * * V_2 )
{
char * * args , * V_3 = NULL , * V_4 = NULL ;
T_1 * V_5 = NULL , * V_6 = NULL ;
int V_7 = 0 ;
int V_8 = - 1 ;
const T_2 * V_9 = NULL ;
int V_10 = V_11 ;
int V_12 , V_13 ;
int V_14 = V_15 ;
int V_16 = 0 ;
T_3 * V_17 ;
T_4 * V_18 ;
T_5 * V_19 ;
char V_20 [ 50 ] ;
int V_21 = 0 ;
if ( V_22 == NULL ) V_22 = F_1 ( V_23 , V_24 ) ;
V_12 = V_25 ;
V_13 = V_25 ;
F_2 () ;
F_3 () ;
args = V_2 + 1 ;
while ( ! V_21 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_1 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_9 = F_4 ( * args ) ;
if( ! V_9 ) {
F_5 ( V_22 ,
L_2 , * args ) ;
V_21 = 1 ;
}
} else V_21 = 1 ;
} else if ( ! strcmp ( * args , L_3 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_12 = F_6 ( * args ) ;
} else V_21 = 1 ;
} else if ( ! strcmp ( * args , L_4 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_13 = F_6 ( * args ) ;
} else V_21 = 1 ;
} else if ( ! strcmp ( * args , L_5 ) ) V_7 = 1 ;
else if ( ! strcmp ( * args , L_6 ) ) V_10 = 1 ;
else if ( ! strcmp ( * args , L_7 ) ) V_16 = 1 ;
else if ( ! strcmp ( * args , L_8 ) ) V_14 = V_26 ;
else if ( ! strcmp ( * args , L_9 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_3 = * args ;
} else V_21 = 1 ;
} else if ( ! strcmp ( * args , L_10 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_4 = * args ;
} else V_21 = 1 ;
} else V_21 = 1 ;
args ++ ;
}
if ( V_21 ) {
F_5 ( V_22 , L_11 ) ;
F_5 ( V_22 , L_12 ) ;
F_5 ( V_22 , L_13 ) ;
F_5 ( V_22 , L_14 ) ;
F_5 ( V_22 , L_15 ) ;
F_5 ( V_22 , L_16 ) ;
F_5 ( V_22 , L_17 ) ;
F_5 ( V_22 , L_18 ) ;
F_5 ( V_22 , L_19 ) ;
F_5 ( V_22 , L_20 ) ;
F_5 ( V_22 , L_21 ) ;
return ( 1 ) ;
}
if ( ( V_8 == - 1 ) && ! V_9 ) V_8 = V_27 ;
if ( V_3 ) {
if ( ! ( V_5 = F_7 ( V_3 , L_22 ) ) ) {
F_5 ( V_22 ,
L_23 , V_3 ) ;
return ( 1 ) ;
}
} else V_5 = F_1 ( V_28 , V_24 ) ;
if ( V_4 ) {
if ( ! ( V_6 = F_7 ( V_4 , L_24 ) ) ) {
F_5 ( V_22 ,
L_25 , V_4 ) ;
return ( 1 ) ;
}
} else V_6 = F_1 ( stdout , V_24 ) ;
if ( V_7 ) {
if ( ! ( V_19 = F_8 ( V_5 , NULL , NULL , NULL ) ) ) {
F_5 ( V_22 , L_26 , V_4 ) ;
F_9 ( V_22 ) ;
return ( 1 ) ;
}
F_10 ( V_5 ) ;
if ( ! ( V_18 = F_11 ( V_19 ) ) ) {
F_5 ( V_22 , L_27 , V_4 ) ;
F_9 ( V_22 ) ;
return ( 1 ) ;
}
F_12 ( V_18 , V_14 ) ;
if( V_16 ) {
if( V_13 == V_25 )
F_13 ( V_6 , V_18 ) ;
else if( V_13 == V_29 )
F_14 ( V_6 , V_18 ) ;
else {
F_5 ( V_22 , L_28 ) ;
return ( 1 ) ;
}
} else {
F_15 ( V_20 , 50 , L_29 , 1 ) ;
if ( ! ( V_17 = F_16 ( V_8 , V_9 ,
V_20 , strlen ( V_20 ) ,
NULL , 0 , V_10 , V_18 ) ) ) {
F_5 ( V_22 , L_30 ,
V_4 ) ;
F_9 ( V_22 ) ;
return ( 1 ) ;
}
if( V_13 == V_25 )
F_17 ( V_6 , V_17 ) ;
else if( V_13 == V_29 )
F_18 ( V_6 , V_17 ) ;
else {
F_5 ( V_22 , L_28 ) ;
return ( 1 ) ;
}
F_19 ( V_17 ) ;
}
F_20 ( V_18 ) ;
F_21 ( V_19 ) ;
F_10 ( V_6 ) ;
return ( 0 ) ;
}
if( V_16 ) {
if( V_12 == V_25 )
V_18 = F_22 ( V_5 , NULL , NULL , NULL ) ;
else if( V_12 == V_29 )
V_18 = F_23 ( V_5 , NULL ) ;
else {
F_5 ( V_22 , L_28 ) ;
return ( 1 ) ;
}
} else {
if( V_12 == V_25 )
V_17 = F_24 ( V_5 , NULL , NULL , NULL ) ;
else if( V_12 == V_29 )
V_17 = F_25 ( V_5 , NULL ) ;
else {
F_5 ( V_22 , L_28 ) ;
return ( 1 ) ;
}
if ( ! V_17 ) {
F_5 ( V_22 , L_26 , V_4 ) ;
F_9 ( V_22 ) ;
return ( 1 ) ;
}
F_15 ( V_20 , 50 , L_31 , 0 ) ;
V_18 = F_26 ( V_17 , V_20 , strlen ( V_20 ) ) ;
F_19 ( V_17 ) ;
}
if ( ! V_18 ) {
F_5 ( V_22 , L_32 , V_4 ) ;
F_9 ( V_22 ) ;
return ( 1 ) ;
}
if ( ! ( V_19 = F_27 ( V_18 ) ) ) {
F_5 ( V_22 , L_27 , V_4 ) ;
F_9 ( V_22 ) ;
return ( 1 ) ;
}
if ( V_18 -> V_30 ) {
F_5 ( V_22 , L_33 ) ;
switch ( V_18 -> V_30 ) {
case V_26 :
F_5 ( V_22 , L_34 ) ;
break;
default:
F_5 ( V_22 , L_35 ) ;
break;
}
}
F_20 ( V_18 ) ;
F_28 ( V_6 , V_19 , NULL , NULL , 0 , NULL , NULL ) ;
F_21 ( V_19 ) ;
F_10 ( V_6 ) ;
F_10 ( V_5 ) ;
return ( 0 ) ;
}
