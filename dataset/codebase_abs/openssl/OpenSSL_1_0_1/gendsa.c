int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
char * V_5 = NULL ;
char * V_6 = NULL , * V_7 = NULL ;
char * V_8 = NULL , * V_9 = NULL ;
T_2 * V_10 = NULL , * V_11 = NULL ;
const T_3 * V_12 = NULL ;
#ifndef F_1
char * V_13 = NULL ;
#endif
F_2 () ;
if ( V_14 == NULL )
if ( ( V_14 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_14 , V_15 , V_16 | V_17 ) ;
if ( ! F_6 ( V_14 , NULL ) )
goto V_18;
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_19;
V_5 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_19;
V_8 = * ( ++ V_2 ) ;
}
#ifndef F_1
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_19;
V_13 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_19;
V_6 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
goto V_19;
#ifndef F_7
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_12 = F_8 () ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_12 = F_9 () ;
#endif
#ifndef F_10
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_12 = F_11 () ;
#endif
#ifndef F_12
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_12 = F_13 () ;
#endif
#ifndef F_14
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_12 = F_15 () ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_12 = F_16 () ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_12 = F_17 () ;
#endif
#ifndef F_18
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_12 = F_19 () ;
else if ( strcmp ( * V_2 , L_14 ) == 0 )
V_12 = F_20 () ;
else if ( strcmp ( * V_2 , L_15 ) == 0 )
V_12 = F_21 () ;
#endif
else if ( * * V_2 != '-' && V_7 == NULL )
{
V_7 = * V_2 ;
}
else
goto V_19;
V_2 ++ ;
V_1 -- ;
}
if ( V_7 == NULL )
{
V_19:
F_22 ( V_14 , L_16 ) ;
F_22 ( V_14 , L_17 ) ;
#ifndef F_7
F_22 ( V_14 , L_18 ) ;
F_22 ( V_14 , L_19 ) ;
#endif
#ifndef F_10
F_22 ( V_14 , L_20 ) ;
#endif
#ifndef F_12
F_22 ( V_14 , L_21 ) ;
F_22 ( V_14 , L_22 ) ;
#endif
#ifndef F_14
F_22 ( V_14 , L_23 ) ;
F_22 ( V_14 , L_24 ) ;
#endif
#ifndef F_18
F_22 ( V_14 , L_25 ) ;
F_22 ( V_14 , L_26 ) ;
#endif
#ifndef F_1
F_22 ( V_14 , L_27 ) ;
#endif
F_22 ( V_14 , L_28 , V_20 , V_20 ) ;
F_22 ( V_14 , L_29 ) ;
F_22 ( V_14 , L_30 ) ;
F_22 ( V_14 , L_31 ) ;
F_22 ( V_14 , L_32 ) ;
goto V_18;
}
#ifndef F_1
F_23 ( V_14 , V_13 , 0 ) ;
#endif
if( ! F_24 ( V_14 , NULL , V_8 , NULL , & V_9 ) ) {
F_22 ( V_14 , L_33 ) ;
goto V_18;
}
V_11 = F_3 ( F_4 () ) ;
if ( ! ( F_25 ( V_11 , V_7 ) ) )
{
perror ( V_7 ) ;
goto V_18;
}
if ( ( V_3 = F_26 ( V_11 , NULL , NULL , NULL ) ) == NULL )
{
F_22 ( V_14 , L_34 ) ;
goto V_18;
}
F_27 ( V_11 ) ;
V_11 = NULL ;
V_10 = F_3 ( F_4 () ) ;
if ( V_10 == NULL ) goto V_18;
if ( V_5 == NULL )
{
F_5 ( V_10 , stdout , V_16 ) ;
#ifdef F_28
{
T_2 * V_21 = F_3 ( F_29 () ) ;
V_10 = F_30 ( V_21 , V_10 ) ;
}
#endif
}
else
{
if ( F_31 ( V_10 , V_5 ) <= 0 )
{
perror ( V_5 ) ;
goto V_18;
}
}
if ( ! F_32 ( NULL , V_14 , 1 ) && V_6 == NULL )
{
F_22 ( V_14 , L_35 ) ;
}
if ( V_6 != NULL )
F_22 ( V_14 , L_36 ,
F_33 ( V_6 ) ) ;
F_22 ( V_14 , L_37 ,
F_34 ( V_3 -> V_22 ) ) ;
if ( ! F_35 ( V_3 ) ) goto V_18;
F_36 ( NULL , V_14 ) ;
if ( ! F_37 ( V_10 , V_3 , V_12 , NULL , 0 , NULL , V_9 ) )
goto V_18;
V_4 = 0 ;
V_18:
if ( V_4 != 0 )
F_38 ( V_14 ) ;
if ( V_11 != NULL ) F_27 ( V_11 ) ;
if ( V_10 != NULL ) F_39 ( V_10 ) ;
if ( V_3 != NULL ) F_40 ( V_3 ) ;
if( V_9 ) F_41 ( V_9 ) ;
F_42 () ;
F_43 ( V_4 ) ;
}
