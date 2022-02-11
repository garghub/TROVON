int MAIN ( int V_1 , char * * V_2 )
{
#ifndef F_1
T_1 * V_3 = NULL ;
#endif
T_2 * V_4 = NULL ;
int V_5 = 1 ;
char * V_6 = NULL ;
char * V_7 = NULL , * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL ;
T_3 * V_11 = NULL , * V_12 = NULL ;
const T_4 * V_13 = NULL ;
#ifndef F_1
char * V_14 = NULL ;
#endif
F_2 () ;
if ( V_15 == NULL )
if ( ( V_15 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_15 , V_16 , V_17 | V_18 ) ;
if ( ! F_6 ( V_15 , NULL ) )
goto V_19;
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_20;
V_6 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_20;
V_9 = * ( ++ V_2 ) ;
}
#ifndef F_1
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_20;
V_14 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_20;
V_7 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
goto V_20;
#ifndef F_7
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_13 = F_8 () ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_13 = F_9 () ;
#endif
#ifndef F_10
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_13 = F_11 () ;
#endif
#ifndef F_12
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_13 = F_13 () ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_13 = F_14 () ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_13 = F_15 () ;
#endif
else if ( * * V_2 != '-' && V_8 == NULL )
{
V_8 = * V_2 ;
}
else
goto V_20;
V_2 ++ ;
V_1 -- ;
}
if ( V_8 == NULL )
{
V_20:
F_16 ( V_15 , L_12 ) ;
F_16 ( V_15 , L_13 ) ;
#ifndef F_7
F_16 ( V_15 , L_14 ) ;
F_16 ( V_15 , L_15 ) ;
#endif
#ifndef F_10
F_16 ( V_15 , L_16 ) ;
#endif
#ifndef F_12
F_16 ( V_15 , L_17 ) ;
F_16 ( V_15 , L_18 ) ;
#endif
#ifndef F_1
F_16 ( V_15 , L_19 ) ;
#endif
F_16 ( V_15 , L_20 , V_21 , V_21 ) ;
F_16 ( V_15 , L_21 ) ;
F_16 ( V_15 , L_22 ) ;
F_16 ( V_15 , L_23 ) ;
F_16 ( V_15 , L_24 ) ;
goto V_19;
}
#ifndef F_1
V_3 = F_17 ( V_15 , V_14 , 0 ) ;
#endif
if( ! F_18 ( V_15 , NULL , V_9 , NULL , & V_10 ) ) {
F_16 ( V_15 , L_25 ) ;
goto V_19;
}
V_12 = F_3 ( F_4 () ) ;
if ( ! ( F_19 ( V_12 , V_8 ) ) )
{
perror ( V_8 ) ;
goto V_19;
}
if ( ( V_4 = F_20 ( V_12 , NULL , NULL , NULL ) ) == NULL )
{
F_16 ( V_15 , L_26 ) ;
goto V_19;
}
F_21 ( V_12 ) ;
V_12 = NULL ;
V_11 = F_3 ( F_4 () ) ;
if ( V_11 == NULL ) goto V_19;
if ( V_6 == NULL )
{
F_5 ( V_11 , stdout , V_17 ) ;
#ifdef F_22
{
T_3 * V_22 = F_3 ( F_23 () ) ;
V_11 = F_24 ( V_22 , V_11 ) ;
}
#endif
}
else
{
if ( F_25 ( V_11 , V_6 ) <= 0 )
{
perror ( V_6 ) ;
goto V_19;
}
}
if ( ! F_26 ( NULL , V_15 , 1 ) && V_7 == NULL )
{
F_16 ( V_15 , L_27 ) ;
}
if ( V_7 != NULL )
F_16 ( V_15 , L_28 ,
F_27 ( V_7 ) ) ;
F_16 ( V_15 , L_29 ,
F_28 ( V_4 -> V_23 ) ) ;
if ( ! F_29 ( V_4 ) ) goto V_19;
F_30 ( NULL , V_15 ) ;
if ( ! F_31 ( V_11 , V_4 , V_13 , NULL , 0 , NULL , V_10 ) )
goto V_19;
V_5 = 0 ;
V_19:
if ( V_5 != 0 )
F_32 ( V_15 ) ;
if ( V_12 != NULL ) F_21 ( V_12 ) ;
if ( V_11 != NULL ) F_33 ( V_11 ) ;
if ( V_4 != NULL ) F_34 ( V_4 ) ;
if( V_10 ) F_35 ( V_10 ) ;
F_36 () ;
F_37 ( V_5 ) ;
}
