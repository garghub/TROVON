int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * * args , * V_4 = NULL , * V_5 = NULL ;
char * V_6 = NULL , * V_7 = NULL ;
T_2 * V_8 = NULL , * V_9 = NULL ;
int V_10 = 0 ;
int V_11 = - 1 ;
const T_3 * V_12 = NULL ;
int V_13 = V_14 ;
int V_15 , V_16 ;
int V_17 = V_18 ;
int V_19 = 0 ;
T_4 * V_20 ;
T_5 * V_21 ;
T_6 * V_22 = NULL ;
char V_23 [ 50 ] , * V_24 = NULL , * V_25 = NULL , * V_26 = NULL ;
int V_27 = 0 ;
#ifndef F_1
char * V_28 = NULL ;
#endif
if ( V_29 == NULL ) V_29 = F_2 ( V_30 , V_31 ) ;
if ( ! F_3 ( V_29 , NULL ) )
goto V_32;
V_15 = V_33 ;
V_16 = V_33 ;
F_4 () ;
F_5 () ;
args = V_2 + 1 ;
while ( ! V_27 && * args && * args [ 0 ] == '-' )
{
if ( ! strcmp ( * args , L_1 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_12 = F_6 ( * args ) ;
if ( ! V_12 )
{
F_7 ( V_29 ,
L_2 , * args ) ;
V_27 = 1 ;
}
}
else
V_27 = 1 ;
}
else if ( ! strcmp ( * args , L_3 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_11 = F_8 ( * args ) ;
if ( V_11 == V_34 )
{
F_7 ( V_29 ,
L_4 , * args ) ;
V_27 = 1 ;
}
}
else
V_27 = 1 ;
}
else if ( ! strcmp ( * args , L_5 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_15 = F_9 ( * args ) ;
}
else V_27 = 1 ;
}
else if ( ! strcmp ( * args , L_6 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_16 = F_9 ( * args ) ;
}
else V_27 = 1 ;
}
else if ( ! strcmp ( * args , L_7 ) )
V_10 = 1 ;
else if ( ! strcmp ( * args , L_8 ) )
V_13 = 1 ;
else if ( ! strcmp ( * args , L_9 ) )
V_19 = 1 ;
else if ( ! strcmp ( * args , L_10 ) )
V_17 = V_35 ;
else if ( ! strcmp ( * args , L_11 ) )
V_17 = V_36 ;
else if ( ! strcmp ( * args , L_12 ) )
V_17 = V_37 ;
else if ( ! strcmp ( * args , L_13 ) )
{
if ( ! args [ 1 ] ) goto V_38;
V_6 = * ( ++ args ) ;
}
else if ( ! strcmp ( * args , L_14 ) )
{
if ( ! args [ 1 ] ) goto V_38;
V_7 = * ( ++ args ) ;
}
#ifndef F_1
else if ( strcmp ( * args , L_15 ) == 0 )
{
if ( ! args [ 1 ] ) goto V_38;
V_28 = * ( ++ args ) ;
}
#endif
else if ( ! strcmp ( * args , L_16 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_4 = * args ;
}
else V_27 = 1 ;
}
else if ( ! strcmp ( * args , L_17 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_5 = * args ;
}
else V_27 = 1 ;
}
else V_27 = 1 ;
args ++ ;
}
if ( V_27 )
{
V_38:
F_7 ( V_29 , L_18 ) ;
F_7 ( V_29 , L_19 ) ;
F_7 ( V_29 , L_20 ) ;
F_7 ( V_29 , L_21 ) ;
F_7 ( V_29 , L_22 ) ;
F_7 ( V_29 , L_23 ) ;
F_7 ( V_29 , L_24 ) ;
F_7 ( V_29 , L_25 ) ;
F_7 ( V_29 , L_26 ) ;
F_7 ( V_29 , L_27 ) ;
F_7 ( V_29 , L_28 ) ;
F_7 ( V_29 , L_29 ) ;
F_7 ( V_29 , L_30 ) ;
F_7 ( V_29 , L_31 ) ;
F_7 ( V_29 , L_32 ) ;
F_7 ( V_29 , L_33 ) ;
#ifndef F_1
F_7 ( V_29 , L_34 ) ;
#endif
return 1 ;
}
#ifndef F_1
V_3 = F_10 ( V_29 , V_28 , 0 ) ;
#endif
if ( ! F_11 ( V_29 , V_6 , V_7 , & V_24 , & V_25 ) )
{
F_7 ( V_29 , L_35 ) ;
return 1 ;
}
if ( ( V_11 == - 1 ) && ! V_12 )
V_11 = V_39 ;
if ( V_4 )
{
if ( ! ( V_8 = F_12 ( V_4 , L_36 ) ) )
{
F_7 ( V_29 ,
L_37 , V_4 ) ;
return ( 1 ) ;
}
}
else
V_8 = F_2 ( V_40 , V_31 ) ;
if ( V_5 )
{
if ( ! ( V_9 = F_12 ( V_5 , L_38 ) ) )
{
F_7 ( V_29 ,
L_39 , V_5 ) ;
return ( 1 ) ;
}
}
else
{
V_9 = F_2 ( stdout , V_31 ) ;
#ifdef F_13
{
T_2 * V_41 = F_14 ( F_15 () ) ;
V_9 = F_16 ( V_41 , V_9 ) ;
}
#endif
}
if ( V_10 )
{
F_17 ( V_8 ) ;
V_22 = F_18 ( V_29 , V_4 , V_15 , 1 ,
V_24 , V_3 , L_40 ) ;
if ( ! V_22 )
{
F_19 ( V_9 ) ;
return 1 ;
}
if ( ! ( V_21 = F_20 ( V_22 , V_17 ) ) )
{
F_7 ( V_29 , L_41 ) ;
F_21 ( V_29 ) ;
F_22 ( V_22 ) ;
F_19 ( V_9 ) ;
return 1 ;
}
if ( V_19 )
{
if ( V_16 == V_33 )
F_23 ( V_9 , V_21 ) ;
else if ( V_16 == V_42 )
F_24 ( V_9 , V_21 ) ;
else
{
F_7 ( V_29 , L_42 ) ;
F_25 ( V_21 ) ;
F_22 ( V_22 ) ;
F_19 ( V_9 ) ;
return ( 1 ) ;
}
}
else
{
if ( V_25 )
V_26 = V_25 ;
else
{
V_26 = V_23 ;
if ( F_26 ( V_23 , sizeof V_23 , L_43 , 1 ) )
{
F_25 ( V_21 ) ;
F_22 ( V_22 ) ;
F_19 ( V_9 ) ;
return ( 1 ) ;
}
}
F_27 ( NULL , V_29 , 0 ) ;
if ( ! ( V_20 = F_28 ( V_11 , V_12 ,
V_26 , strlen ( V_26 ) ,
NULL , 0 , V_13 , V_21 ) ) )
{
F_7 ( V_29 , L_44 ) ;
F_21 ( V_29 ) ;
F_25 ( V_21 ) ;
F_22 ( V_22 ) ;
F_19 ( V_9 ) ;
return ( 1 ) ;
}
F_29 ( NULL , V_29 ) ;
if ( V_16 == V_33 )
F_30 ( V_9 , V_20 ) ;
else if ( V_16 == V_42 )
F_31 ( V_9 , V_20 ) ;
else
{
F_7 ( V_29 , L_42 ) ;
F_25 ( V_21 ) ;
F_22 ( V_22 ) ;
F_19 ( V_9 ) ;
return ( 1 ) ;
}
F_32 ( V_20 ) ;
}
F_25 ( V_21 ) ;
F_22 ( V_22 ) ;
F_19 ( V_9 ) ;
if ( V_24 )
F_33 ( V_24 ) ;
if ( V_25 )
F_33 ( V_25 ) ;
return ( 0 ) ;
}
if ( V_19 )
{
if ( V_15 == V_33 )
V_21 = F_34 ( V_8 , NULL , NULL , NULL ) ;
else if ( V_15 == V_42 )
V_21 = F_35 ( V_8 , NULL ) ;
else
{
F_7 ( V_29 , L_42 ) ;
return ( 1 ) ;
}
}
else
{
if ( V_15 == V_33 )
V_20 = F_36 ( V_8 , NULL , NULL , NULL ) ;
else if ( V_15 == V_42 )
V_20 = F_37 ( V_8 , NULL ) ;
else
{
F_7 ( V_29 , L_42 ) ;
return ( 1 ) ;
}
if ( ! V_20 )
{
F_7 ( V_29 , L_45 ) ;
F_21 ( V_29 ) ;
return ( 1 ) ;
}
if ( V_24 )
V_26 = V_24 ;
else
{
V_26 = V_23 ;
F_26 ( V_23 , sizeof V_23 , L_46 , 0 ) ;
}
V_21 = F_38 ( V_20 , V_26 , strlen ( V_26 ) ) ;
F_32 ( V_20 ) ;
}
if ( ! V_21 )
{
F_7 ( V_29 , L_47 ) ;
F_21 ( V_29 ) ;
return ( 1 ) ;
}
if ( ! ( V_22 = F_39 ( V_21 ) ) )
{
F_7 ( V_29 , L_41 ) ;
F_21 ( V_29 ) ;
return ( 1 ) ;
}
if ( V_21 -> V_43 )
{
F_7 ( V_29 , L_48 ) ;
switch ( V_21 -> V_43 )
{
case V_35 :
F_7 ( V_29 , L_49 ) ;
break;
case V_37 :
F_7 ( V_29 , L_50 ) ;
break;
case V_36 :
F_7 ( V_29 , L_51 ) ;
break;
default:
F_7 ( V_29 , L_52 ) ;
break;
}
}
F_25 ( V_21 ) ;
if ( V_16 == V_33 )
F_40 ( V_9 , V_22 , NULL , NULL , 0 , NULL , V_25 ) ;
else if ( V_16 == V_42 )
F_41 ( V_9 , V_22 ) ;
else
{
F_7 ( V_29 , L_42 ) ;
return ( 1 ) ;
}
V_32:
F_22 ( V_22 ) ;
F_19 ( V_9 ) ;
F_17 ( V_8 ) ;
if ( V_24 )
F_33 ( V_24 ) ;
if ( V_25 )
F_33 ( V_25 ) ;
return ( 0 ) ;
}
