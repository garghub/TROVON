int MAIN ( int V_1 , char * * V_2 )
{
#ifndef F_1
T_1 * V_3 = NULL ;
#endif
int V_4 = 1 ;
T_2 * V_5 = NULL ;
const T_3 * V_6 ;
int V_7 , V_8 = 0 ;
const T_4 * V_9 = NULL ;
T_5 * V_10 = NULL , * V_11 = NULL ;
int V_12 , V_13 , V_14 = 0 , V_15 = 0 ;
int V_16 = 0 , V_17 = 0 , V_18 = 0 ;
char * V_19 , * V_20 , * V_21 , * V_22 ;
char * V_23 = NULL , * V_24 = NULL ;
char * V_25 = NULL , * V_26 = NULL ;
T_6 V_27 = V_28 ;
int V_29 = 0 ;
int V_30 = V_31 ;
int V_32 = 0 ;
F_2 () ;
if ( V_33 == NULL )
if ( ( V_33 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_33 , V_34 , V_35 | V_36 ) ;
if ( ! F_6 ( V_33 , NULL ) )
goto V_37;
V_22 = NULL ;
V_19 = NULL ;
V_20 = NULL ;
V_12 = V_38 ;
V_13 = V_38 ;
V_21 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_12 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_13 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_20 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_24 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_39;
++ V_2 ;
V_29 = 1 ;
if ( strcmp ( * V_2 , L_11 ) == 0 )
V_27 = V_40 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_27 = V_28 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_27 = V_41 ;
else
goto V_39;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_39;
++ V_2 ;
V_32 = 1 ;
if ( strcmp ( * V_2 , L_15 ) == 0 )
V_30 = V_31 ;
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_30 = 0 ;
else
goto V_39;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_18 = 1 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_17 = 1 ;
else if ( ( V_9 = F_8 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_9 ( V_33 , L_20 , * V_2 ) ;
V_8 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_8 )
{
V_39:
F_9 ( V_33 , L_21 , V_21 ) ;
F_9 ( V_33 , L_22 ) ;
F_9 ( V_33 , L_23
L_24 ) ;
F_9 ( V_33 , L_25
L_24 ) ;
F_9 ( V_33 , L_26 ) ;
F_9 ( V_33 , L_27
L_28 ) ;
F_9 ( V_33 , L_29 ) ;
F_9 ( V_33 , L_30
L_28 ) ;
F_9 ( V_33 , L_31
L_32 ) ;
F_9 ( V_33 , L_33
L_34
L_35
L_36 ) ;
F_9 ( V_33 , L_37 ) ;
F_9 ( V_33 , L_38 ) ;
F_9 ( V_33 , L_39
L_40 ) ;
F_9 ( V_33 , L_41
L_42 ) ;
F_9 ( V_33 , L_43
L_44 ) ;
F_9 ( V_33 , L_45
L_46 ) ;
F_9 ( V_33 , L_47
L_48 ) ;
F_9 ( V_33 , L_49
L_50 ) ;
F_9 ( V_33 , L_51
L_52 ) ;
F_9 ( V_33 , L_43
L_53 ) ;
F_9 ( V_33 , L_47
L_54 ) ;
goto V_37;
}
F_10 () ;
#ifndef F_1
V_3 = F_11 ( V_33 , V_22 , 0 ) ;
#endif
if( ! F_12 ( V_33 , V_23 , V_24 , & V_25 , & V_26 ) )
{
F_9 ( V_33 , L_55 ) ;
goto V_37;
}
V_10 = F_3 ( F_4 () ) ;
V_11 = F_3 ( F_4 () ) ;
if ( ( V_10 == NULL ) || ( V_11 == NULL ) )
{
F_13 ( V_33 ) ;
goto V_37;
}
if ( V_19 == NULL )
F_5 ( V_10 , V_42 , V_35 ) ;
else
{
if ( F_14 ( V_10 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_37;
}
}
F_9 ( V_33 , L_56 ) ;
if ( V_12 == V_43 )
{
if ( V_16 )
V_5 = F_15 ( V_10 , NULL ) ;
else
V_5 = F_16 ( V_10 , NULL ) ;
}
else if ( V_12 == V_38 )
{
if ( V_16 )
V_5 = F_17 ( V_10 , NULL , NULL ,
NULL ) ;
else
V_5 = F_18 ( V_10 , NULL , NULL ,
V_25 ) ;
}
else
{
F_9 ( V_33 , L_57 ) ;
goto V_37;
}
if ( V_5 == NULL )
{
F_9 ( V_33 , L_58 ) ;
F_13 ( V_33 ) ;
goto V_37;
}
if ( V_20 == NULL )
{
F_5 ( V_11 , stdout , V_35 ) ;
#ifdef F_19
{
T_5 * V_44 = F_3 ( F_20 () ) ;
V_11 = F_21 ( V_44 , V_11 ) ;
}
#endif
}
else
{
if ( F_22 ( V_11 , V_20 ) <= 0 )
{
perror ( V_20 ) ;
goto V_37;
}
}
V_6 = F_23 ( V_5 ) ;
if ( V_29 )
F_24 ( V_5 , V_27 ) ;
if ( V_32 )
F_25 ( V_5 , V_30 ) ;
if ( V_14 )
if ( ! F_26 ( V_11 , V_5 , 0 ) )
{
perror ( V_20 ) ;
F_13 ( V_33 ) ;
goto V_37;
}
if ( V_15 )
{
V_4 = 0 ;
goto V_37;
}
F_9 ( V_33 , L_59 ) ;
if ( V_13 == V_43 )
{
if ( V_18 )
V_7 = F_27 ( V_11 , V_6 ) ;
else if ( V_16 || V_17 )
V_7 = F_28 ( V_11 , V_5 ) ;
else
V_7 = F_29 ( V_11 , V_5 ) ;
}
else if ( V_13 == V_38 )
{
if ( V_18 )
V_7 = F_30 ( V_11 , V_6 ) ;
else if ( V_16 || V_17 )
V_7 = F_31 ( V_11 , V_5 ) ;
else
V_7 = F_32 ( V_11 , V_5 , V_9 ,
NULL , 0 , NULL , V_26 ) ;
}
else
{
F_9 ( V_33 , L_60
L_61 ) ;
goto V_37;
}
if ( ! V_7 )
{
F_9 ( V_33 , L_62 ) ;
F_13 ( V_33 ) ;
}
else
V_4 = 0 ;
V_37:
if ( V_10 )
F_33 ( V_10 ) ;
if ( V_11 )
F_34 ( V_11 ) ;
if ( V_5 )
F_35 ( V_5 ) ;
if ( V_25 )
F_36 ( V_25 ) ;
if ( V_26 )
F_36 ( V_26 ) ;
F_37 () ;
F_38 ( V_4 ) ;
}
