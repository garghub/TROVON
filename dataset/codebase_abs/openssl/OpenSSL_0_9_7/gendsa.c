int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
int V_5 = 1 ;
char * V_6 = NULL ;
char * V_7 = NULL , * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL ;
T_3 * V_11 = NULL , * V_12 = NULL ;
const T_4 * V_13 = NULL ;
char * V_14 = NULL ;
F_1 () ;
if ( V_15 == NULL )
if ( ( V_15 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_15 , V_16 , V_17 | V_18 ) ;
if ( ! F_5 ( V_15 , NULL ) )
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
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_20;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_20;
V_7 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
goto V_20;
#ifndef F_6
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_13 = F_7 () ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_13 = F_8 () ;
#endif
#ifndef F_9
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_13 = F_10 () ;
#endif
#ifndef F_11
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_13 = F_12 () ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_13 = F_13 () ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_13 = F_14 () ;
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
F_15 ( V_15 , L_12 ) ;
F_15 ( V_15 , L_13 ) ;
#ifndef F_6
F_15 ( V_15 , L_14 ) ;
F_15 ( V_15 , L_15 ) ;
#endif
#ifndef F_9
F_15 ( V_15 , L_16 ) ;
#endif
#ifndef F_11
F_15 ( V_15 , L_17 ) ;
F_15 ( V_15 , L_18 ) ;
#endif
F_15 ( V_15 , L_19 ) ;
F_15 ( V_15 , L_20 , V_21 , V_21 ) ;
F_15 ( V_15 , L_21 ) ;
F_15 ( V_15 , L_22 ) ;
F_15 ( V_15 , L_23 ) ;
F_15 ( V_15 , L_24 ) ;
goto V_19;
}
V_3 = F_16 ( V_15 , V_14 , 0 ) ;
if( ! F_17 ( V_15 , NULL , V_9 , NULL , & V_10 ) ) {
F_15 ( V_15 , L_25 ) ;
goto V_19;
}
V_12 = F_2 ( F_3 () ) ;
if ( ! ( F_18 ( V_12 , V_8 ) ) )
{
perror ( V_8 ) ;
goto V_19;
}
if ( ( V_4 = F_19 ( V_12 , NULL , NULL , NULL ) ) == NULL )
{
F_15 ( V_15 , L_26 ) ;
goto V_19;
}
F_20 ( V_12 ) ;
V_12 = NULL ;
V_11 = F_2 ( F_3 () ) ;
if ( V_11 == NULL ) goto V_19;
if ( V_6 == NULL )
{
F_4 ( V_11 , stdout , V_17 ) ;
#ifdef F_21
{
T_3 * V_22 = F_2 ( F_22 () ) ;
V_11 = F_23 ( V_22 , V_11 ) ;
}
#endif
}
else
{
if ( F_24 ( V_11 , V_6 ) <= 0 )
{
perror ( V_6 ) ;
goto V_19;
}
}
if ( ! F_25 ( NULL , V_15 , 1 ) && V_7 == NULL )
{
F_15 ( V_15 , L_27 ) ;
}
if ( V_7 != NULL )
F_15 ( V_15 , L_28 ,
F_26 ( V_7 ) ) ;
F_15 ( V_15 , L_29 ,
F_27 ( V_4 -> V_23 ) ) ;
if ( ! F_28 ( V_4 ) ) goto V_19;
F_29 ( NULL , V_15 ) ;
if ( ! F_30 ( V_11 , V_4 , V_13 , NULL , 0 , NULL , V_10 ) )
goto V_19;
V_5 = 0 ;
V_19:
if ( V_5 != 0 )
F_31 ( V_15 ) ;
if ( V_12 != NULL ) F_20 ( V_12 ) ;
if ( V_11 != NULL ) F_32 ( V_11 ) ;
if ( V_4 != NULL ) F_33 ( V_4 ) ;
if( V_10 ) F_34 ( V_10 ) ;
F_35 () ;
F_36 ( V_5 ) ;
}
