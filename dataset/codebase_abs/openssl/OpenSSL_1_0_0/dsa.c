int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
T_2 * V_5 = NULL ;
int V_6 , V_7 = 0 ;
const T_3 * V_8 = NULL ;
T_4 * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 , V_13 = 0 , V_14 = 0 ;
int V_15 = 0 , V_16 = 0 ;
char * V_17 , * V_18 , * V_19 ;
#ifndef F_1
char * V_20 ;
#endif
char * V_21 = NULL , * V_22 = NULL ;
char * V_23 = NULL , * V_24 = NULL ;
int V_25 = 0 ;
int V_26 = 2 ;
F_2 () ;
if ( V_27 == NULL )
if ( ( V_27 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_27 , V_28 , V_29 | V_30 ) ;
if ( ! F_6 ( V_27 , NULL ) )
goto V_31;
#ifndef F_1
V_20 = NULL ;
#endif
V_17 = NULL ;
V_18 = NULL ;
V_11 = V_32 ;
V_12 = V_32 ;
V_19 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_11 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_12 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_22 = * ( ++ V_2 ) ;
}
#ifndef F_1
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_20 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_26 = 2 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_26 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_26 = 0 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( * V_2 , L_14 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_15 ) == 0 )
V_16 = 1 ;
else if ( ( V_8 = F_8 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_9 ( V_27 , L_16 , * V_2 ) ;
V_7 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_7 )
{
V_33:
F_9 ( V_27 , L_17 , V_19 ) ;
F_9 ( V_27 , L_18 ) ;
F_9 ( V_27 , L_19 ) ;
F_9 ( V_27 , L_20 ) ;
F_9 ( V_27 , L_21 ) ;
F_9 ( V_27 , L_22 ) ;
F_9 ( V_27 , L_23 ) ;
F_9 ( V_27 , L_24 ) ;
#ifndef F_1
F_9 ( V_27 , L_25 ) ;
#endif
F_9 ( V_27 , L_26 ) ;
F_9 ( V_27 , L_27 ) ;
#ifndef F_10
F_9 ( V_27 , L_28 ) ;
#endif
#ifndef F_11
F_9 ( V_27 , L_29 ) ;
F_9 ( V_27 , L_30 ) ;
#endif
#ifndef F_12
F_9 ( V_27 , L_31 ) ;
F_9 ( V_27 , L_32 ) ;
#endif
#ifndef F_13
F_9 ( V_27 , L_33 ) ;
#endif
F_9 ( V_27 , L_34 ) ;
F_9 ( V_27 , L_35 ) ;
F_9 ( V_27 , L_36 ) ;
goto V_31;
}
F_14 () ;
#ifndef F_1
V_3 = F_15 ( V_27 , V_20 , 0 ) ;
#endif
if( ! F_16 ( V_27 , V_21 , V_22 , & V_23 , & V_24 ) ) {
F_9 ( V_27 , L_37 ) ;
goto V_31;
}
V_9 = F_3 ( F_4 () ) ;
V_10 = F_3 ( F_4 () ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) )
{
F_17 ( V_27 ) ;
goto V_31;
}
if ( V_17 == NULL )
F_5 ( V_9 , V_34 , V_29 ) ;
else
{
if ( F_18 ( V_9 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_31;
}
}
F_9 ( V_27 , L_38 ) ;
{
T_5 * V_35 ;
if ( V_15 )
V_35 = F_19 ( V_27 , V_17 , V_11 , 1 ,
V_23 , V_3 , L_39 ) ;
else
V_35 = F_20 ( V_27 , V_17 , V_11 , 1 ,
V_23 , V_3 , L_40 ) ;
if ( V_35 )
{
V_5 = F_21 ( V_35 ) ;
F_22 ( V_35 ) ;
}
}
if ( V_5 == NULL )
{
F_9 ( V_27 , L_41 ) ;
F_17 ( V_27 ) ;
goto V_31;
}
if ( V_18 == NULL )
{
F_5 ( V_10 , stdout , V_29 ) ;
#ifdef F_23
{
T_4 * V_36 = F_3 ( F_24 () ) ;
V_10 = F_25 ( V_36 , V_10 ) ;
}
#endif
}
else
{
if ( F_26 ( V_10 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
goto V_31;
}
}
if ( V_13 )
if ( ! F_27 ( V_10 , V_5 , 0 ) )
{
perror ( V_18 ) ;
F_17 ( V_27 ) ;
goto V_31;
}
if ( V_25 )
{
fprintf ( stdout , L_42 ) ;
F_28 ( V_10 , V_5 -> V_37 ) ;
fprintf ( stdout , L_43 ) ;
}
if ( V_14 ) goto V_31;
F_9 ( V_27 , L_44 ) ;
if ( V_12 == V_38 ) {
if( V_15 || V_16 ) V_6 = F_29 ( V_10 , V_5 ) ;
else V_6 = F_30 ( V_10 , V_5 ) ;
} else if ( V_12 == V_32 ) {
if( V_15 || V_16 )
V_6 = F_31 ( V_10 , V_5 ) ;
else V_6 = F_32 ( V_10 , V_5 , V_8 ,
NULL , 0 , NULL , V_24 ) ;
#ifndef F_33
} else if ( V_12 == V_39 || V_12 == V_40 ) {
T_5 * V_41 ;
V_41 = F_34 () ;
F_35 ( V_41 , V_5 ) ;
if ( V_12 == V_40 )
V_6 = F_36 ( V_10 , V_41 , V_26 , 0 , V_24 ) ;
else if ( V_15 || V_16 )
V_6 = F_37 ( V_10 , V_41 ) ;
else
V_6 = F_38 ( V_10 , V_41 ) ;
F_22 ( V_41 ) ;
#endif
} else {
F_9 ( V_27 , L_45 ) ;
goto V_31;
}
if ( V_6 <= 0 )
{
F_9 ( V_27 , L_46 ) ;
F_17 ( V_27 ) ;
}
else
V_4 = 0 ;
V_31:
if( V_9 != NULL ) F_39 ( V_9 ) ;
if( V_10 != NULL ) F_40 ( V_10 ) ;
if( V_5 != NULL ) F_41 ( V_5 ) ;
if( V_23 ) F_42 ( V_23 ) ;
if( V_24 ) F_42 ( V_24 ) ;
F_43 () ;
F_44 ( V_4 ) ;
}
