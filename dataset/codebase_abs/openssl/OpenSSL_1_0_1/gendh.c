int MAIN ( int V_1 , char * * V_2 )
{
T_1 V_3 ;
T_2 * V_4 = NULL ;
int V_5 = 1 , V_6 = V_7 ;
int V_8 = 2 ;
char * V_9 = NULL ;
char * V_10 = NULL ;
#ifndef F_1
char * V_11 = NULL ;
#endif
T_3 * V_12 = NULL ;
F_2 () ;
F_3 ( & V_3 , V_13 , V_14 ) ;
if ( V_14 == NULL )
if ( ( V_14 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_14 , V_15 , V_16 | V_17 ) ;
if ( ! F_7 ( V_14 , NULL ) )
goto V_18;
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_19;
V_9 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
V_8 = 2 ;
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_8 = 5 ;
#ifndef F_1
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_19;
V_11 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_19;
V_10 = * ( ++ V_2 ) ;
}
else
break;
V_2 ++ ;
V_1 -- ;
}
if ( ( V_1 >= 1 ) && ( ( sscanf ( * V_2 , L_6 , & V_6 ) == 0 ) || ( V_6 < 0 ) ) )
{
V_19:
F_8 ( V_14 , L_7 ) ;
F_8 ( V_14 , L_8 ) ;
F_8 ( V_14 , L_9 ) ;
F_8 ( V_14 , L_10 ) ;
#ifndef F_1
F_8 ( V_14 , L_11 ) ;
#endif
F_8 ( V_14 , L_12 , V_20 , V_20 ) ;
F_8 ( V_14 , L_13 ) ;
F_8 ( V_14 , L_14 ) ;
goto V_18;
}
#ifndef F_1
F_9 ( V_14 , V_11 , 0 ) ;
#endif
V_12 = F_4 ( F_5 () ) ;
if ( V_12 == NULL )
{
F_10 ( V_14 ) ;
goto V_18;
}
if ( V_9 == NULL )
{
F_6 ( V_12 , stdout , V_16 ) ;
#ifdef F_11
{
T_3 * V_21 = F_4 ( F_12 () ) ;
V_12 = F_13 ( V_21 , V_12 ) ;
}
#endif
}
else
{
if ( F_14 ( V_12 , V_9 ) <= 0 )
{
perror ( V_9 ) ;
goto V_18;
}
}
if ( ! F_15 ( NULL , V_14 , 1 ) && V_10 == NULL )
{
F_8 ( V_14 , L_15 ) ;
}
if ( V_10 != NULL )
F_8 ( V_14 , L_16 ,
F_16 ( V_10 ) ) ;
F_8 ( V_14 , L_17 , V_6 , V_8 ) ;
F_8 ( V_14 , L_18 ) ;
if( ( ( V_4 = F_17 () ) == NULL ) || ! F_18 ( V_4 , V_6 , V_8 , & V_3 ) )
goto V_18;
F_19 ( NULL , V_14 ) ;
if ( ! F_20 ( V_12 , V_4 ) )
goto V_18;
V_5 = 0 ;
V_18:
if ( V_5 != 0 )
F_10 ( V_14 ) ;
if ( V_12 != NULL ) F_21 ( V_12 ) ;
if ( V_4 != NULL ) F_22 ( V_4 ) ;
F_23 () ;
F_24 ( V_5 ) ;
}
static int T_4 V_13 ( int V_22 , int V_23 , T_1 * V_3 )
{
char V_24 = '*' ;
if ( V_22 == 0 ) V_24 = '.' ;
if ( V_22 == 1 ) V_24 = '+' ;
if ( V_22 == 2 ) V_24 = '*' ;
if ( V_22 == 3 ) V_24 = '\n' ;
F_25 ( V_3 -> V_25 , & V_24 , 1 ) ;
( void ) F_26 ( V_3 -> V_25 ) ;
#ifdef F_27
V_22 = V_23 ;
#endif
return 1 ;
}
