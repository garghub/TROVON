int MAIN ( int V_1 , char * * V_2 )
{
char * * args , * V_3 = NULL , * V_4 = NULL ;
char * V_5 = NULL , * V_6 = NULL ;
T_1 * V_7 = NULL , * V_8 = NULL ;
int V_9 = 0 ;
int V_10 = - 1 ;
const T_2 * V_11 = NULL ;
int V_12 = V_13 ;
int V_14 , V_15 ;
int V_16 = V_17 ;
int V_18 = 0 ;
T_3 * V_19 ;
T_4 * V_20 ;
T_5 * V_21 ;
char V_22 [ 50 ] , * V_23 = NULL , * V_24 = NULL , * V_25 = NULL ;
int V_26 = 0 ;
if ( V_27 == NULL ) V_27 = F_1 ( V_28 , V_29 ) ;
V_14 = V_30 ;
V_15 = V_30 ;
F_2 () ;
F_3 () ;
args = V_2 + 1 ;
while ( ! V_26 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_1 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_11 = F_4 ( * args ) ;
if( ! V_11 ) {
F_5 ( V_27 ,
L_2 , * args ) ;
V_26 = 1 ;
}
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_3 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_10 = F_6 ( * args ) ;
if( V_10 == V_31 ) {
F_5 ( V_27 ,
L_4 , * args ) ;
V_26 = 1 ;
}
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_5 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_14 = F_7 ( * args ) ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_6 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_15 = F_7 ( * args ) ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_7 ) ) V_9 = 1 ;
else if ( ! strcmp ( * args , L_8 ) ) V_12 = 1 ;
else if ( ! strcmp ( * args , L_9 ) ) V_18 = 1 ;
else if ( ! strcmp ( * args , L_10 ) ) V_16 = V_32 ;
else if ( ! strcmp ( * args , L_11 ) ) V_16 = V_33 ;
else if ( ! strcmp ( * args , L_12 ) ) V_16 = V_34 ;
else if ( ! strcmp ( * args , L_13 ) )
{
if ( ! args [ 1 ] ) goto V_35;
V_5 = * ( ++ args ) ;
}
else if ( ! strcmp ( * args , L_14 ) )
{
if ( ! args [ 1 ] ) goto V_35;
V_6 = * ( ++ args ) ;
}
else if ( ! strcmp ( * args , L_15 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_3 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_16 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_4 = * args ;
} else V_26 = 1 ;
} else V_26 = 1 ;
args ++ ;
}
if ( V_26 ) {
V_35:
F_5 ( V_27 , L_17 ) ;
F_5 ( V_27 , L_18 ) ;
F_5 ( V_27 , L_19 ) ;
F_5 ( V_27 , L_20 ) ;
F_5 ( V_27 , L_21 ) ;
F_5 ( V_27 , L_22 ) ;
F_5 ( V_27 , L_23 ) ;
F_5 ( V_27 , L_24 ) ;
F_5 ( V_27 , L_25 ) ;
F_5 ( V_27 , L_26 ) ;
F_5 ( V_27 , L_27 ) ;
F_5 ( V_27 , L_28 ) ;
F_5 ( V_27 , L_29 ) ;
F_5 ( V_27 , L_30 ) ;
F_5 ( V_27 , L_31 ) ;
F_5 ( V_27 , L_32 ) ;
return ( 1 ) ;
}
if( ! F_8 ( V_27 , V_5 , V_6 , & V_23 , & V_24 ) ) {
F_5 ( V_27 , L_33 ) ;
return ( 1 ) ;
}
if ( ( V_10 == - 1 ) && ! V_11 ) V_10 = V_36 ;
if ( V_3 ) {
if ( ! ( V_7 = F_9 ( V_3 , L_34 ) ) ) {
F_5 ( V_27 ,
L_35 , V_3 ) ;
return ( 1 ) ;
}
} else V_7 = F_1 ( V_37 , V_29 ) ;
if ( V_4 ) {
if ( ! ( V_8 = F_9 ( V_4 , L_36 ) ) ) {
F_5 ( V_27 ,
L_37 , V_4 ) ;
return ( 1 ) ;
}
} else {
V_8 = F_1 ( stdout , V_29 ) ;
#ifdef F_10
{
T_1 * V_38 = F_11 ( F_12 () ) ;
V_8 = F_13 ( V_38 , V_8 ) ;
}
#endif
}
if ( V_9 ) {
if( V_14 == V_30 )
V_21 = F_14 ( V_7 , NULL , NULL , V_23 ) ;
else if( V_14 == V_39 )
V_21 = F_15 ( V_7 , NULL ) ;
else {
F_5 ( V_27 , L_38 ) ;
return ( 1 ) ;
}
if ( ! V_21 ) {
F_5 ( V_27 , L_39 , V_4 ) ;
F_16 ( V_27 ) ;
return ( 1 ) ;
}
F_17 ( V_7 ) ;
if ( ! ( V_20 = F_18 ( V_21 , V_16 ) ) ) {
F_5 ( V_27 , L_40 , V_4 ) ;
F_16 ( V_27 ) ;
return ( 1 ) ;
}
if( V_18 ) {
if( V_15 == V_30 )
F_19 ( V_8 , V_20 ) ;
else if( V_15 == V_39 )
F_20 ( V_8 , V_20 ) ;
else {
F_5 ( V_27 , L_38 ) ;
return ( 1 ) ;
}
} else {
if( V_24 ) V_25 = V_24 ;
else {
V_25 = V_22 ;
F_21 ( V_22 , 50 , L_41 , 1 ) ;
}
F_22 ( NULL , V_27 , 0 ) ;
if ( ! ( V_19 = F_23 ( V_10 , V_11 ,
V_25 , strlen ( V_25 ) ,
NULL , 0 , V_12 , V_20 ) ) ) {
F_5 ( V_27 , L_42 ,
V_4 ) ;
F_16 ( V_27 ) ;
return ( 1 ) ;
}
F_24 ( NULL , V_27 ) ;
if( V_15 == V_30 )
F_25 ( V_8 , V_19 ) ;
else if( V_15 == V_39 )
F_26 ( V_8 , V_19 ) ;
else {
F_5 ( V_27 , L_38 ) ;
return ( 1 ) ;
}
F_27 ( V_19 ) ;
}
F_28 ( V_20 ) ;
F_29 ( V_21 ) ;
F_30 ( V_8 ) ;
if( V_23 ) F_31 ( V_23 ) ;
if( V_24 ) F_31 ( V_24 ) ;
return ( 0 ) ;
}
if( V_18 ) {
if( V_14 == V_30 )
V_20 = F_32 ( V_7 , NULL , NULL , NULL ) ;
else if( V_14 == V_39 )
V_20 = F_33 ( V_7 , NULL ) ;
else {
F_5 ( V_27 , L_38 ) ;
return ( 1 ) ;
}
} else {
if( V_14 == V_30 )
V_19 = F_34 ( V_7 , NULL , NULL , NULL ) ;
else if( V_14 == V_39 )
V_19 = F_35 ( V_7 , NULL ) ;
else {
F_5 ( V_27 , L_38 ) ;
return ( 1 ) ;
}
if ( ! V_19 ) {
F_5 ( V_27 , L_39 , V_4 ) ;
F_16 ( V_27 ) ;
return ( 1 ) ;
}
if( V_23 ) V_25 = V_23 ;
else {
V_25 = V_22 ;
F_21 ( V_22 , 50 , L_43 , 0 ) ;
}
V_20 = F_36 ( V_19 , V_25 , strlen ( V_25 ) ) ;
F_27 ( V_19 ) ;
}
if ( ! V_20 ) {
F_5 ( V_27 , L_44 , V_4 ) ;
F_16 ( V_27 ) ;
return ( 1 ) ;
}
if ( ! ( V_21 = F_37 ( V_20 ) ) ) {
F_5 ( V_27 , L_40 , V_4 ) ;
F_16 ( V_27 ) ;
return ( 1 ) ;
}
if ( V_20 -> V_40 ) {
F_5 ( V_27 , L_45 ) ;
switch ( V_20 -> V_40 ) {
case V_32 :
F_5 ( V_27 , L_46 ) ;
break;
case V_34 :
F_5 ( V_27 , L_47 ) ;
break;
case V_33 :
F_5 ( V_27 , L_48 ) ;
break;
default:
F_5 ( V_27 , L_49 ) ;
break;
}
}
F_28 ( V_20 ) ;
if( V_15 == V_30 )
F_38 ( V_8 , V_21 , NULL , NULL , 0 , NULL , V_24 ) ;
else if( V_15 == V_39 )
F_39 ( V_8 , V_21 ) ;
else {
F_5 ( V_27 , L_38 ) ;
return ( 1 ) ;
}
F_29 ( V_21 ) ;
F_30 ( V_8 ) ;
F_17 ( V_7 ) ;
if( V_23 ) F_31 ( V_23 ) ;
if( V_24 ) F_31 ( V_24 ) ;
return ( 0 ) ;
}
