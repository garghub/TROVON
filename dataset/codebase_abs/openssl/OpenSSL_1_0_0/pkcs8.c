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
T_4 * V_20 = NULL ;
T_5 * V_21 = NULL ;
T_6 * V_22 = NULL ;
char V_23 [ 50 ] , * V_24 = NULL , * V_25 = NULL , * V_26 = NULL ;
int V_27 = 0 ;
int V_28 = 1 ;
#ifndef F_1
char * V_29 = NULL ;
#endif
if ( V_30 == NULL ) V_30 = F_2 ( V_31 , V_32 ) ;
if ( ! F_3 ( V_30 , NULL ) )
goto V_33;
V_15 = V_34 ;
V_16 = V_34 ;
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
F_7 ( V_30 ,
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
if ( V_11 == V_35 )
{
F_7 ( V_30 ,
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
V_17 = V_36 ;
else if ( ! strcmp ( * args , L_11 ) )
V_17 = V_37 ;
else if ( ! strcmp ( * args , L_12 ) )
V_17 = V_38 ;
else if ( ! strcmp ( * args , L_13 ) )
{
if ( ! args [ 1 ] ) goto V_39;
V_6 = * ( ++ args ) ;
}
else if ( ! strcmp ( * args , L_14 ) )
{
if ( ! args [ 1 ] ) goto V_39;
V_7 = * ( ++ args ) ;
}
#ifndef F_1
else if ( strcmp ( * args , L_15 ) == 0 )
{
if ( ! args [ 1 ] ) goto V_39;
V_29 = * ( ++ args ) ;
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
V_39:
F_7 ( V_30 , L_18 ) ;
F_7 ( V_30 , L_19 ) ;
F_7 ( V_30 , L_20 ) ;
F_7 ( V_30 , L_21 ) ;
F_7 ( V_30 , L_22 ) ;
F_7 ( V_30 , L_23 ) ;
F_7 ( V_30 , L_24 ) ;
F_7 ( V_30 , L_25 ) ;
F_7 ( V_30 , L_26 ) ;
F_7 ( V_30 , L_27 ) ;
F_7 ( V_30 , L_28 ) ;
F_7 ( V_30 , L_29 ) ;
F_7 ( V_30 , L_30 ) ;
F_7 ( V_30 , L_31 ) ;
F_7 ( V_30 , L_32 ) ;
F_7 ( V_30 , L_33 ) ;
#ifndef F_1
F_7 ( V_30 , L_34 ) ;
#endif
goto V_33;
}
#ifndef F_1
V_3 = F_10 ( V_30 , V_29 , 0 ) ;
#endif
if ( ! F_11 ( V_30 , V_6 , V_7 , & V_24 , & V_25 ) )
{
F_7 ( V_30 , L_35 ) ;
goto V_33;
}
if ( ( V_11 == - 1 ) && ! V_12 )
V_11 = V_40 ;
if ( V_4 )
{
if ( ! ( V_8 = F_12 ( V_4 , L_36 ) ) )
{
F_7 ( V_30 ,
L_37 , V_4 ) ;
goto V_33;
}
}
else
V_8 = F_2 ( V_41 , V_32 ) ;
if ( V_5 )
{
if ( ! ( V_9 = F_12 ( V_5 , L_38 ) ) )
{
F_7 ( V_30 ,
L_39 , V_5 ) ;
goto V_33;
}
}
else
{
V_9 = F_2 ( stdout , V_32 ) ;
#ifdef F_13
{
T_2 * V_42 = F_14 ( F_15 () ) ;
V_9 = F_16 ( V_42 , V_9 ) ;
}
#endif
}
if ( V_10 )
{
V_22 = F_17 ( V_30 , V_4 , V_15 , 1 ,
V_24 , V_3 , L_40 ) ;
if ( ! V_22 )
goto V_33;
if ( ! ( V_21 = F_18 ( V_22 , V_17 ) ) )
{
F_7 ( V_30 , L_41 ) ;
F_19 ( V_30 ) ;
goto V_33;
}
if ( V_19 )
{
if ( V_16 == V_34 )
F_20 ( V_9 , V_21 ) ;
else if ( V_16 == V_43 )
F_21 ( V_9 , V_21 ) ;
else
{
F_7 ( V_30 , L_42 ) ;
goto V_33;
}
}
else
{
if ( V_25 )
V_26 = V_25 ;
else
{
V_26 = V_23 ;
if ( F_22 ( V_23 , sizeof V_23 , L_43 , 1 ) )
goto V_33;
}
F_23 ( NULL , V_30 , 0 ) ;
if ( ! ( V_20 = F_24 ( V_11 , V_12 ,
V_26 , strlen ( V_26 ) ,
NULL , 0 , V_13 , V_21 ) ) )
{
F_7 ( V_30 , L_44 ) ;
F_19 ( V_30 ) ;
goto V_33;
}
F_25 ( NULL , V_30 ) ;
if ( V_16 == V_34 )
F_26 ( V_9 , V_20 ) ;
else if ( V_16 == V_43 )
F_27 ( V_9 , V_20 ) ;
else
{
F_7 ( V_30 , L_42 ) ;
goto V_33;
}
}
V_28 = 0 ;
goto V_33;
}
if ( V_19 )
{
if ( V_15 == V_34 )
V_21 = F_28 ( V_8 , NULL , NULL , NULL ) ;
else if ( V_15 == V_43 )
V_21 = F_29 ( V_8 , NULL ) ;
else
{
F_7 ( V_30 , L_42 ) ;
goto V_33;
}
}
else
{
if ( V_15 == V_34 )
V_20 = F_30 ( V_8 , NULL , NULL , NULL ) ;
else if ( V_15 == V_43 )
V_20 = F_31 ( V_8 , NULL ) ;
else
{
F_7 ( V_30 , L_42 ) ;
goto V_33;
}
if ( ! V_20 )
{
F_7 ( V_30 , L_45 ) ;
F_19 ( V_30 ) ;
goto V_33;
}
if ( V_24 )
V_26 = V_24 ;
else
{
V_26 = V_23 ;
F_22 ( V_23 , sizeof V_23 , L_46 , 0 ) ;
}
V_21 = F_32 ( V_20 , V_26 , strlen ( V_26 ) ) ;
}
if ( ! V_21 )
{
F_7 ( V_30 , L_47 ) ;
F_19 ( V_30 ) ;
goto V_33;
}
if ( ! ( V_22 = F_33 ( V_21 ) ) )
{
F_7 ( V_30 , L_41 ) ;
F_19 ( V_30 ) ;
goto V_33;
}
if ( V_21 -> V_44 )
{
F_7 ( V_30 , L_48 ) ;
switch ( V_21 -> V_44 )
{
case V_36 :
F_7 ( V_30 , L_49 ) ;
break;
case V_38 :
F_7 ( V_30 , L_50 ) ;
break;
case V_37 :
F_7 ( V_30 , L_51 ) ;
break;
case V_45 :
F_7 ( V_30 , L_52 ) ;
break;
default:
F_7 ( V_30 , L_53 ) ;
break;
}
}
if ( V_16 == V_34 )
F_34 ( V_9 , V_22 , NULL , NULL , 0 , NULL , V_25 ) ;
else if ( V_16 == V_43 )
F_35 ( V_9 , V_22 ) ;
else
{
F_7 ( V_30 , L_42 ) ;
goto V_33;
}
V_28 = 0 ;
V_33:
F_36 ( V_20 ) ;
F_37 ( V_21 ) ;
F_38 ( V_22 ) ;
F_39 ( V_9 ) ;
F_40 ( V_8 ) ;
if ( V_24 )
F_41 ( V_24 ) ;
if ( V_25 )
F_41 ( V_25 ) ;
return V_28 ;
}
