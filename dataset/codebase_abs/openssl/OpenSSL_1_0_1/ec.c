int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
T_1 * V_4 = NULL ;
const T_2 * V_5 ;
int V_6 , V_7 = 0 ;
const T_3 * V_8 = NULL ;
T_4 * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 , V_13 = 0 , V_14 = 0 ;
int V_15 = 0 , V_16 = 0 , V_17 = 0 ;
char * V_18 , * V_19 , * V_20 , * V_21 ;
char * V_22 = NULL , * V_23 = NULL ;
char * V_24 = NULL , * V_25 = NULL ;
T_5 V_26 = V_27 ;
int V_28 = 0 ;
int V_29 = V_30 ;
int V_31 = 0 ;
F_1 () ;
if ( V_32 == NULL )
if ( ( V_32 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_32 , V_33 , V_34 | V_35 ) ;
if ( ! F_5 ( V_32 , NULL ) )
goto V_36;
V_21 = NULL ;
V_18 = NULL ;
V_19 = NULL ;
V_11 = V_37 ;
V_12 = V_37 ;
V_20 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_11 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_12 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_38;
++ V_2 ;
V_28 = 1 ;
if ( strcmp ( * V_2 , L_11 ) == 0 )
V_26 = V_39 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_26 = V_27 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_26 = V_40 ;
else
goto V_38;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_38;
++ V_2 ;
V_31 = 1 ;
if ( strcmp ( * V_2 , L_15 ) == 0 )
V_29 = V_30 ;
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_29 = 0 ;
else
goto V_38;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_17 = 1 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_16 = 1 ;
else if ( ( V_8 = F_7 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_8 ( V_32 , L_20 , * V_2 ) ;
V_7 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_7 )
{
V_38:
F_8 ( V_32 , L_21 , V_20 ) ;
F_8 ( V_32 , L_22 ) ;
F_8 ( V_32 , L_23
L_24 ) ;
F_8 ( V_32 , L_25
L_24 ) ;
F_8 ( V_32 , L_26 ) ;
F_8 ( V_32 , L_27
L_28 ) ;
F_8 ( V_32 , L_29 ) ;
F_8 ( V_32 , L_30
L_28 ) ;
F_8 ( V_32 , L_31
L_32 ) ;
F_8 ( V_32 , L_33
L_34
L_35
L_36 ) ;
F_8 ( V_32 , L_37 ) ;
F_8 ( V_32 , L_38 ) ;
F_8 ( V_32 , L_39
L_40 ) ;
F_8 ( V_32 , L_41
L_42 ) ;
F_8 ( V_32 , L_43
L_44 ) ;
F_8 ( V_32 , L_45
L_46 ) ;
F_8 ( V_32 , L_47
L_48 ) ;
F_8 ( V_32 , L_49
L_50 ) ;
F_8 ( V_32 , L_51
L_52 ) ;
F_8 ( V_32 , L_43
L_53 ) ;
F_8 ( V_32 , L_47
L_54 ) ;
goto V_36;
}
F_9 () ;
#ifndef F_10
F_11 ( V_32 , V_21 , 0 ) ;
#endif
if( ! F_12 ( V_32 , V_22 , V_23 , & V_24 , & V_25 ) )
{
F_8 ( V_32 , L_55 ) ;
goto V_36;
}
V_9 = F_2 ( F_3 () ) ;
V_10 = F_2 ( F_3 () ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) )
{
F_13 ( V_32 ) ;
goto V_36;
}
if ( V_18 == NULL )
F_4 ( V_9 , V_41 , V_34 ) ;
else
{
if ( F_14 ( V_9 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
goto V_36;
}
}
F_8 ( V_32 , L_56 ) ;
if ( V_11 == V_42 )
{
if ( V_15 )
V_4 = F_15 ( V_9 , NULL ) ;
else
V_4 = F_16 ( V_9 , NULL ) ;
}
else if ( V_11 == V_37 )
{
if ( V_15 )
V_4 = F_17 ( V_9 , NULL , NULL ,
NULL ) ;
else
V_4 = F_18 ( V_9 , NULL , NULL ,
V_24 ) ;
}
else
{
F_8 ( V_32 , L_57 ) ;
goto V_36;
}
if ( V_4 == NULL )
{
F_8 ( V_32 , L_58 ) ;
F_13 ( V_32 ) ;
goto V_36;
}
if ( V_19 == NULL )
{
F_4 ( V_10 , stdout , V_34 ) ;
#ifdef F_19
{
T_4 * V_43 = F_2 ( F_20 () ) ;
V_10 = F_21 ( V_43 , V_10 ) ;
}
#endif
}
else
{
if ( F_22 ( V_10 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_36;
}
}
V_5 = F_23 ( V_4 ) ;
if ( V_28 )
F_24 ( V_4 , V_26 ) ;
if ( V_31 )
F_25 ( V_4 , V_29 ) ;
if ( V_13 )
if ( ! F_26 ( V_10 , V_4 , 0 ) )
{
perror ( V_19 ) ;
F_13 ( V_32 ) ;
goto V_36;
}
if ( V_14 )
{
V_3 = 0 ;
goto V_36;
}
F_8 ( V_32 , L_59 ) ;
if ( V_12 == V_42 )
{
if ( V_17 )
V_6 = F_27 ( V_10 , V_5 ) ;
else if ( V_15 || V_16 )
V_6 = F_28 ( V_10 , V_4 ) ;
else
V_6 = F_29 ( V_10 , V_4 ) ;
}
else if ( V_12 == V_37 )
{
if ( V_17 )
V_6 = F_30 ( V_10 , V_5 ) ;
else if ( V_15 || V_16 )
V_6 = F_31 ( V_10 , V_4 ) ;
else
V_6 = F_32 ( V_10 , V_4 , V_8 ,
NULL , 0 , NULL , V_25 ) ;
}
else
{
F_8 ( V_32 , L_60
L_61 ) ;
goto V_36;
}
if ( ! V_6 )
{
F_8 ( V_32 , L_62 ) ;
F_13 ( V_32 ) ;
}
else
V_3 = 0 ;
V_36:
if ( V_9 )
F_33 ( V_9 ) ;
if ( V_10 )
F_34 ( V_10 ) ;
if ( V_4 )
F_35 ( V_4 ) ;
if ( V_24 )
F_36 ( V_24 ) ;
if ( V_25 )
F_36 ( V_25 ) ;
F_37 () ;
F_38 ( V_3 ) ;
}
