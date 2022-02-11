int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
char * V_5 = NULL ;
char * V_6 = NULL , * V_7 = NULL ;
char * V_8 = NULL , * V_9 = NULL ;
T_2 * V_10 = NULL , * V_11 = NULL ;
T_3 * V_12 = NULL ;
F_1 () ;
if ( V_13 == NULL )
if ( ( V_13 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_13 , V_14 , V_15 | V_16 ) ;
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_17;
V_5 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_17;
V_8 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_17;
V_6 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
goto V_17;
#ifndef F_5
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_12 = F_6 () ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_12 = F_7 () ;
#endif
#ifndef F_8
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_12 = F_9 () ;
#endif
else if ( * * V_2 != '-' && V_7 == NULL )
{
V_7 = * V_2 ;
}
else
goto V_17;
V_2 ++ ;
V_1 -- ;
}
if ( V_7 == NULL )
{
V_17:
F_10 ( V_13 , L_8 ) ;
F_10 ( V_13 , L_9 ) ;
#ifndef F_5
F_10 ( V_13 , L_10 ) ;
F_10 ( V_13 , L_11 ) ;
#endif
#ifndef F_8
F_10 ( V_13 , L_12 ) ;
#endif
F_10 ( V_13 , L_13 , V_18 , V_18 ) ;
F_10 ( V_13 , L_14 ) ;
F_10 ( V_13 , L_15 ) ;
F_10 ( V_13 , L_16 ) ;
F_10 ( V_13 , L_17 ) ;
goto V_19;
}
if( ! F_11 ( V_13 , NULL , V_8 , NULL , & V_9 ) ) {
F_10 ( V_13 , L_18 ) ;
goto V_19;
}
V_11 = F_2 ( F_3 () ) ;
if ( ! ( F_12 ( V_11 , V_7 ) ) )
{
perror ( V_7 ) ;
goto V_19;
}
if ( ( V_3 = F_13 ( V_11 , NULL , NULL , NULL ) ) == NULL )
{
F_10 ( V_13 , L_19 ) ;
goto V_19;
}
F_14 ( V_11 ) ;
V_11 = NULL ;
V_10 = F_2 ( F_3 () ) ;
if ( V_10 == NULL ) goto V_19;
if ( V_5 == NULL )
{
F_4 ( V_10 , stdout , V_15 ) ;
#ifdef F_15
{
T_2 * V_20 = F_2 ( F_16 () ) ;
V_10 = F_17 ( V_20 , V_10 ) ;
}
#endif
}
else
{
if ( F_18 ( V_10 , V_5 ) <= 0 )
{
perror ( V_5 ) ;
goto V_19;
}
}
if ( ! F_19 ( NULL , V_13 , 1 ) && V_6 == NULL )
{
F_10 ( V_13 , L_20 ) ;
}
if ( V_6 != NULL )
F_10 ( V_13 , L_21 ,
F_20 ( V_6 ) ) ;
F_10 ( V_13 , L_22 ,
F_21 ( V_3 -> V_21 ) ) ;
if ( ! F_22 ( V_3 ) ) goto V_19;
F_23 ( NULL , V_13 ) ;
if ( ! F_24 ( V_10 , V_3 , V_12 , NULL , 0 , NULL , V_9 ) )
goto V_19;
V_4 = 0 ;
V_19:
if ( V_4 != 0 )
F_25 ( V_13 ) ;
if ( V_11 != NULL ) F_14 ( V_11 ) ;
if ( V_10 != NULL ) F_26 ( V_10 ) ;
if ( V_3 != NULL ) F_27 ( V_3 ) ;
if( V_9 ) F_28 ( V_9 ) ;
EXIT ( V_4 ) ;
}
